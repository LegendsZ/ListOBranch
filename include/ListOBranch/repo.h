#ifndef REPO_H
#define REPO_H

// includes here
#include "branch.h"
#include <vector>

namespace ListOBranch {
  namespace Repo {
    struct RepoData{
      std::string name;
      std::vector<Branch::BranchData> branches;
    };

    bool addBranchToRepository(Repo::RepoData* repo, const Branch::BranchData* branch);
    bool addBranchToRepository(Repo::RepoData* repo, const std::string* branchName);

    bool removeBranchFromRepository(Repo::RepoData* repo, const Branch::BranchData* branch);
    bool removeBranchFromRepository(Repo::RepoData* repo, const std::string* branchName);
  }
}

#endif