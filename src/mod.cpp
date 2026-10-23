#include <mods/api.h>
#include <mods/svc/actor.h>
#include <string>
#include <algorithm>

// --- Your helper functions and command mapping go here ---
std::string ToLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

std::string ResolveActorName(const std::string& inputCmd) {
    std::string cmd = ToLower(inputCmd);
    if (cmd == "bokoblin" || cmd == "boko") return "MON_a";
    if (cmd == "darknut") return "MAD_a";
    if (cmd == "keese") return "MAN_a";
    if (cmd == "midna") return "Midna";
    if (cmd == "zant") return "Zant";
    return "MON_a";
}

// --- REQUIRED MOD EXPORTS ---
extern "C" {
    // This exact signature and export is what Dusklight looks for on startup
    __declspec(dllexport) bool DUSKLIGHT_MOD_INIT() {
        // Place any one-time hook registration or setup code here
        return true;
    }
}
