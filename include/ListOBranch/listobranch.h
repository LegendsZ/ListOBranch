#ifndef LISTOBRANCH_H
#define LISTOBRANCH_H

#define VERSION "1.0.0"

// includes here
#include <string>

#ifdef _WIN32
  #ifdef LISTOBRANCH_EXPORTS
    #define LISTOBRANCH_API __declspec(dllexport)
  #else
    #define LISTOBRANCH_API __declspec(dllimport)
  #endif
#else
  #define LISTOBRANCH_API
#endif

namespace listobranch {

  class LISTOBRANCH_API Core {
  public:
    std::string getVersion() const;
  };

}

#endif