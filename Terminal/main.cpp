#include <iostream>
#include "listobranch/listobranch.h"

int main() {
    listobranch::Core core;
    std::cout << "ListOBranch version: " << core.getVersion() << std::endl;
    return 0;
}
