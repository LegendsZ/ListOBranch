#ifndef LISTOBRANCH_H
#define LISTOBRANCH_H

#define VERSION "1.0.0"

// includes here
#include "export.h"
#include "repo.h"

#include <iostream>
#include <string>

namespace ListOBranch {
  extern bool initialized;
  extern std::vector<Repo::RepoData> repositories;

  LISTOBRANCH_API std::string getVersion();

  LISTOBRANCH_API bool initialize(std::string saveDataFile);
  LISTOBRANCH_API bool saveData(const std::string& filename);
  LISTOBRANCH_API bool loadData(const std::string& filename);

  LISTOBRANCH_API std::vector<Repo::RepoData> getRepositories();
  LISTOBRANCH_API bool addRepository(const Repo::RepoData& repo);
  LISTOBRANCH_API bool removeRepository(const Repo::RepoData& repo);
}

#endif