#ifndef LISTOBRANCH_H
#define LISTOBRANCH_H

#define VERSION "1.0.0"

// includes here
#include "export.h"
#include <string>


namespace listobranch {

  class LISTOBRANCH_API Core {
  public:
    std::string getVersion() const;
  };

}

#endif