#include "listobranch/listobranch.h"

namespace ListOBranch {

    std::string getVersion() {
        return VERSION;
    }

    bool initialize() {
        if (!initialized) {
            // init here
            initialized = true;
            return true;
        }
        return false;
    }

}
