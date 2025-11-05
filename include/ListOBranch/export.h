#ifndef LISTOBRANCH_EXPORT_H
#define LISTOBRANCH_EXPORT_H

#ifdef _WIN32
  #ifdef LISTOBRANCH_EXPORTS
    #define LISTOBRANCH_API __declspec(dllexport)
  #else
    #define LISTOBRANCH_API __declspec(dllimport)
  #endif
#else
  #define LISTOBRANCH_API
#endif

#endif // LISTOBRANCH_EXPORT_H
