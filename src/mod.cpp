#include "mods/service.hpp"
#include "mods/svc/hook.hpp"
#include "mods/svc/log.hpp"
#include <mods/api.h>
#include <mods/svc/actor.h>
#include <string>
#include <algorithm>

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
    if (cmd == "poo" || cmd == "poe")             return "WGN_a";      // Imp Poe
    if (cmd == "skulltula")                       return "Wspcial_l";  // Skulltula

    // --- ITEMS & DROPS ---
    if (cmd == "heart")                           return "d_a_item";   // Recovery Heart
    if (cmd == "rupee")                           return "d_a_item";   // Green Rupee
    if (cmd == "redrupee")                        return "d_a_item";   // Red Rupee
    if (cmd == "purplerupee")                     return "d_a_item";   // Purple Rupee
    if (cmd == "bomb")                            return "d_a_item";   // Normal Bomb
    if (cmd == "waterbomb")                       return "d_a_item";   // Water Bomb
    if (cmd == "arrow" || cmd == "arrows")        return "d_a_item";   // Arrow Bundle
    if (cmd == "smallkey")                        return "Lv5_KEY";    // Small Key

    // --- NPCS & SPECIAL ---
    if (cmd == "midna")                           return "Midna";      // Midna
    if (cmd == "zelda")                           return "Zelda";      // Zelda
    if (cmd == "zant")                            return "Zant";       // Zant
    if (cmd == "maro")                            return "Maro";       // Maro
    if (cmd == "yelia" || cmd == "ilia")          return "Yelia";      // Ilia
    if (cmd == "pot" || cmd == "jar")             return "K_tubo02";   // Breakable Pot

    // Default fallback if command isn't recognized
    return "MON_a"; 
}

void HandleChatCommand(const std::string& command) {
    std::string actorName = ResolveActorName(command);

    // Call Dusklight's actor service to spawn the entity at Link's current position
    // Dusklight::Svc::Actor::Spawn(actorName.c_str());
}

bool DUSKLIGHT_MOD_INIT() {
    return true;
}
