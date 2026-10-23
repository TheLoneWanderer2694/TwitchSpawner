#include <mods/api.h>
#include <mods/svc/actor.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <thread>
#include <chrono>

namespace {
    // Convert string to lowercase for case-insensitive chat command matching
    std::string ToLower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    // Map Twitch chat commands to Twilight Princess actor profiles
    std::string ResolveActorName(const std::string& inputCmd) {
        std::string cmd = ToLower(inputCmd);

        // --- ENEMIES ---
        if (cmd == "bokoblin" || cmd == "boko")       return "MON_a";      
        if (cmd == "redbokoblin")                      return "MON_a2";     
        if (cmd == "bulblin")                         return "MBN_a";      
        if (cmd == "keese")                           return "MAN_a";      
        if (cmd == "firekeese")                       return "MAN_b";      
        if (cmd == "icekeese")                        return "MAN_c";      
        if (cmd == "stalfos")                         return "MCN_a";      
        if (cmd == "darknut")                         return "MAD_a";      
        if (cmd == "lizalfos")                        return "MAS_a";      
        if (cmd == "dinafos")                         return "MAT_a";      
        if (cmd == "chu" || cmd == "chuchu")          return "WON_a";      
        if (cmd == "poe")                             return "WGN_a";      
        if (cmd == "skulltula")                       return "Wspcial_l";  

        // --- ITEMS & EQUIPMENT ---
        if (cmd == "mastersword" || cmd == "ms")       return "MstrSword";  
        if (cmd == "heart" || cmd == "recoveryheart" || 
            cmd == "greenrupee" || cmd == "rupee" || 
            cmd == "bluerupee" || cmd == "redrupee")   return "d_a_item";   

        // --- NPCS & ENVIRONMENT ---
        if (cmd == "midna")                           return "Midna";      
        if (cmd == "zelda")                           return "Zelda";      
        if (cmd == "zant")                            return "Zant";       
        if (cmd == "maro")                            return "Maro";       
        if (cmd == "pot" || cmd == "jar")             return "K_tubo02";   

        return "MON_a"; 
    }

    // Background thread to watch command.txt written by Python
    void CommandWatcherThread() {
        std::string lastCommand = "";
        
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));

            std::ifstream inFile("command.txt");
            if (!inFile.is_open()) continue;

            std::string currentCommand;
            std::getline(inFile, currentCommand);
            inFile.close();

            // Clean up whitespace/newlines
            currentCommand.erase(currentCommand.find_last_not_of(" \n\r\t") + 1);

            if (!currentCommand.empty() && currentCommand != lastCommand) {
                lastCommand = currentCommand;
                std::string actorName = ResolveActorName(currentCommand);

                // Execute the Dusklight actor spawn service call
                // Note: Spawning requires the game engine context; ensure parameters match your SDK version
                Dusklight::Svc::Actor::Spawn(actorName.c_str());

                // Clear the command file so it doesn't re-trigger
                std::ofstream outFile("command.txt", std::ios::trunc);
                outFile.close();
            }
        }
    }
}

// Initialization hook called when Dusklight loads the mod
bool ModInit() {
    // Launch background thread to listen for Python chat commands
    std::thread(CommandWatcherThread).detach();
    return true;
}

// Automatically generates the required mod export symbols for the loader
DEFINE_MOD();
