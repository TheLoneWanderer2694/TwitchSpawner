#include <mods/api.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <thread>
#include <chrono>

namespace {
    // Convert string to lowercase for case-insensitive matching
    std::string ToLower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    // Map Twitch chat commands to actor names
    std::string ResolveActorName(const std::string& inputCmd) {
        std::string cmd = ToLower(inputCmd);

        if (cmd == "bokoblin" || cmd == "boko")       return "MON_a";      
        if (cmd == "darknut")                         return "MAD_a";      
        if (cmd == "keese")                           return "MAN_a";      
        if (cmd == "midna")                           return "Midna";      
        if (cmd == "zant")                            return "Zant";       
        if (cmd == "greenrupee" || cmd == "rupee")     return "d_a_item";   

        return "MON_a"; 
    }

    // Background thread to poll command.txt from Python
    void CommandWatcherThread() {
        std::string lastCommand = "";
        
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(250));

            std::ifstream inFile("command.txt");
            if (!inFile.is_open()) continue;

            std::string currentCommand;
            std::getline(inFile, currentCommand);
            inFile.close();

            // Clean up trailing whitespace/newlines
            currentCommand.erase(currentCommand.find_last_not_of(" \n\r\t") + 1);

            if (!currentCommand.empty() && currentCommand != lastCommand) {
                lastCommand = currentCommand;
                std::string actorName = ResolveActorName(currentCommand);

                // TODO: Insert official Dusklight actor spawn service call here
                // e.g., Game::SpawnActor(actorName.c_str());

                // Clear the command file so it doesn't loop
                std::ofstream outFile("command.txt", std::ios::trunc);
                outFile.close();
            }
        }
    }
}

// Dusklight mod entry hook
bool ModInit() {
    std::thread(CommandWatcherThread).detach();
    return true;
}

// Automatically generates required mod export symbols
DEFINE_MOD();
