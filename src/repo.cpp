#include "listobranch/repo.h"

namespace ListOBranch{
  namespace Repo{
    bool addBranchToRepository(Repo::RepoData* repo, Branch::BranchData* branch) {
      if (repo && branch) {
        repo->branches.push_back(branch);
        return true;
      }
      return false;
    }

    bool addBranchToRepository(Repo::RepoData* repo, const std::string* branchName, const std::string* prLink) {
      if (repo && branchName && !branchName->empty()) {
        Branch::BranchData* branch = new Branch::BranchData();
        branch->name = *branchName;
        branch->prLink = *prLink;
        return addBranchToRepository(repo, branch);
      }
      return false;
    }

    bool removeBranchFromRepository(Repo::RepoData* repo, const Branch::BranchData* branch) {
      if (repo && branch) {
        auto it = std::remove_if(repo->branches.begin(), repo->branches.end(),
                                 [&](const Branch::BranchData* b) { return b->name == branch->name; });
        if (it != repo->branches.end()) {
          repo->branches.erase(it, repo->branches.end());
          return true;
        }
      }
      return false;
    }

    //TODO: add removeBranchFromRepository by prLink.
    bool removeBranchFromRepository(Repo::RepoData* repo, const std::string* branchName) {
      if (repo && branchName && !branchName->empty()) {
        Branch::BranchData branch;
        branch.name = *branchName;
        return removeBranchFromRepository(repo, &branch);
      }
      return false;
    }
  }
}