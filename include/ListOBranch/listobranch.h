#ifndef LISTOBRANCH_H
#define LISTOBRANCH_H

#define VERSION "1.0.0"

// includes here
#include "export.h"
#include "repo.h"

#include <string>

namespace ListOBranch {
  namespace {
    inline bool initialized = false;
    std::vector<Repo::RepoData> repositories;
  }

  LISTOBRANCH_API bool initialize();
  LISTOBRANCH_API bool saveData(const std::string& filename);
  LISTOBRANCH_API bool loadData(const std::string& filename);
  LISTOBRANCH_API std::string getVersion();
}

#endif