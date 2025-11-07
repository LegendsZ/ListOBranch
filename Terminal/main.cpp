#include <iostream>
#include "listobranch/listobranch.h"

int main() {
    std::cout << "ListOBranch backend library version: " << ListOBranch::getVersion() << std::endl;
    ListOBranch::initialize();
    
    ListOBranch::safeExit();
    return 0;
}
