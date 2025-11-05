#ifndef BRANCH_H
#define BRANCH_H

// includes here
#include "export.h"
#include <string>


namespace branch {

  class LISTOBRANCH_API Core {
  public:
    std::string getVersion() const;
  };

}

#endif