#ifndef LISTOBRANCH_H
#define LISTOBRANCH_H

// includes here

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
    void start();
  };

}

#endif