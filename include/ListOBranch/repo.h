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

    bool addBranchToRepository(Repo::RepoData* repo, const Branch::BranchData* branch) {
      if (repo && branch) {
        repo->branches.push_back(*branch);
        return true;
      }
      return false;
    }

    bool addBranchToRepository(Repo::RepoData* repo, const std::string* branchName) {
      if (repo && branchName && !branchName->empty()) {
        Branch::BranchData branch;
        branch.name = *branchName;
        return addBranchToRepository(repo, &branch);
      }
      return false;
    }
  }
}

#endif