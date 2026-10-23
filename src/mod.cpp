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

    // Map Twitch chat commands to Twilight Princess actor profiles and item types
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

        // --- ITEMS & EQUIPMENT ---
        if (cmd == "mastersword" || cmd == "ms")       return "MstrSword";  // Master Sword
        if (cmd == "heart" || cmd == "recoveryheart")  return "d_a_item";   // Recovery Heart
        if (cmd == "heartcontainer" || cmd == "hc")    return "d_a_item";   // Heart Container
        if (cmd == "pieceofheart" || cmd == "poh")     return "d_a_item";   // Piece of Heart
        
        // Rupees
        if (cmd == "greenrupee" || cmd == "rupee")     return "d_a_item";   // Green Rupee (1)
        if (cmd == "bluerupee")                        return "d_a_item";   // Blue Rupee (5)
        if (cmd == "yellowrupee")                      return "d_a_item";   // Yellow Rupee (10)
        if (cmd == "redrupee")                         return "d_a_item";   // Red Rupee (20)
        if (cmd == "purplerupee")                      return "d_a_item";   // Purple Rupee (50)
        if (cmd == "orangerupee")                      return "d_a_item";   // Orange Rupee (100)
        if (cmd == "silverrupee")                      return "d_a_item";   // Silver Rupee (200)

        // Consumables & Ammo
        if (cmd == "bomb" || cmd == "normalbomb")      return "d_a_item";   // Normal Bomb
        if (cmd == "waterbomb")                        return "d_a_item";   // Water Bomb
        if (cmd == "bombchu")                          return "d_a_item";   // Bombchu
        if (cmd == "arrow" || cmd == "arrows")         return "d_a_item";   // Arrows

        // Dungeon Items & Keys
        if (cmd == "smallkey" || cmd == "key")         return "Lv5_KEY";    // Small Key
        if (cmd == "bosskey" || cmd == "bigkey")       return "d_a_item";   // Boss Key
        if (cmd == "compass")                          return "d_a_item";   // Compass
        if (cmd == "dungeonmap" || cmd == "map")       return "d_a_item";   // Dungeon Map

        // Tools & Gear
        if (cmd == "lantern" || cmd == "oil")          return "d_a_item";   // Lantern / Oil
        if (cmd == "boomerang")                        return "d_a_item";   // Gale Boomerang
        if (cmd == "bow")                              return "d_a_item";   // Hero's Bow
        if (cmd == "clawshot")                         return "d_a_item";   // Clawshot
        if (cmd == "spinner")                          return "d_a_item";   // Spinner
        if (cmd == "ballandchain")                     return "d_a_item";   // Ball and Chain
        if (cmd == "dominionrod")                      return "d_a_item";   // Dominion Rod
        if (cmd == "bottle" || cmd == "potion")        return "d_a_item";   // Bottle / Potion

        // --- NPCS & ENVIRONMENT ---
        if (cmd == "midna")                           return "Midna";      // Midna
        if (cmd == "zelda")                           return "Zelda";      // Zelda
        if (cmd == "zant")                            return "Zant";       // Zant
        if (cmd == "maro")                            return "Maro";       // Maro
        if (cmd == "pot" || cmd == "jar")             return "K_tubo02";   // Breakable Pot

        return "MON_a"; 
    }
}

void HandleChatCommand(const std::string& command) {
    std::string actorName = ResolveActorName(command);
    // Dusklight::Svc::Actor::Spawn(actorName.c_str());
}

DEFINE_MOD();
