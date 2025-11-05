#ifndef REPO_H
#define REPO_H

// includes here
#include "export.h"
#include "branch.h"
#include <string>
#include <vector>

namespace ListOBranch {
  namespace Repo {
    struct RepoData{
      std::string name;
      std::vector<Branch::BranchData> branches;
    };
  }
}

#endif