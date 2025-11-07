#ifndef LISTOBRANCH_H
#define LISTOBRANCH_H

#define VERSION "1.0.0"

// includes here
#include "repo.h"
#include <iostream>

#ifdef LOG_DEBUG_MODE
  #pragma message("LOG_DEBUG_MODE is defined!")
  #include <iostream>
  #define LOG_DEBUG(msg) std::cout << "[ListOBranch DEBUG] " << msg << std::endl
#else
  #pragma message("LOG_DEBUG_MODE is not defined!")
  #define LOG_DEBUG(msg) ((void)0)
#endif

namespace ListOBranch {
  extern bool initialized;
  extern std::vector<Repo::RepoData> repositories;

  LISTOBRANCH_API std::string getVersion();

  LISTOBRANCH_API bool initialize(std::string saveDataFile);
  LISTOBRANCH_API bool initialize();
  LISTOBRANCH_API bool safeExit(std::string saveDataFile);
  LISTOBRANCH_API bool safeExit();

  LISTOBRANCH_API bool saveData(const std::string& filename);
  LISTOBRANCH_API bool loadData(const std::string& filename);

  LISTOBRANCH_API std::vector<Repo::RepoData> getRepositories();
  LISTOBRANCH_API bool addRepository(const Repo::RepoData& repo);
  LISTOBRANCH_API bool removeRepository(const Repo::RepoData& repo);
}

#endif