#include <mods/api.h>
#include <mods/svc/actor.h>
#include <string>
#include <algorithm>

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
        if (cmd == "bokoblin" || cmd == "boko")       return "MON_a";      // Standard Bokoblin
        if (cmd == "redbokoblin")                      return "MON_a2";     // Red Bokoblin
        if (cmd == "bulblin")                         return "MBN_a";      // Bulblin
        if (cmd == "keese")                           return "MAN_a";      // Keese
        if (cmd == "firekeese")                       return "MAN_b";      // Fire Keese
        if (cmd == "icekeese")                        return "MAN_c";      // Ice Keese
        if (cmd == "stalfos")                         return "MCN_a";      // Stalfos
        if (cmd == "darknut")                         return "MAD_a";      // Darknut
        if (cmd == "lizalfos")                        return "MAS_a";      // Lizalfos
        if (cmd == "dinafos")                         return "MAT_a";      // Dinolfos
        if (cmd == "chu" || cmd == "chuchu")          return "WON_a";      // Chu Chu
        if (cmd == "poe")                             return "WGN_a";      // Imp Poe
        if (cmd == "skulltula")                       return "Wspcial_l";  // Skulltula

        // --- ITEMS & DROPS ---
        if (cmd == "heart" || cmd == "rupee" || cmd == "bomb") return "d_a_item"; 
        if (cmd == "smallkey")                        return "Lv5_KEY";    // Small Key

        // --- NPCS & SPECIAL ---
        if (cmd == "midna")                           return "Midna";      // Midna
        if (cmd == "zelda")                           return "Zelda";      // Zelda
        if (cmd == "zant")                            return "Zant";       // Zant
        if (cmd == "maro")                            return "Maro";       // Maro
        if (cmd == "pot" || cmd == "jar")             return "K_tubo02";   // Breakable Pot

        return "MON_a"; 
    }
}

// Handler called when a chat command triggers an action
void HandleChatCommand(const std::string& command) {
    std::string actorName = ResolveActorName(command);
    // Dusklight::Svc::Actor::Spawn(actorName.c_str());
}

// Automatically generates all required mod entry points and export symbols
DEFINE_MOD();
