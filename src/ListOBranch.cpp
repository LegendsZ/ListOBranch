#include "listobranch/listobranch.h"

namespace ListOBranch {
    bool initialized = false;
    std::vector<ListOBranch::Repo::RepoData*> repositories;

    std::string getVersion() {
        return VERSION;
    }
    
    bool initialize(std::string* saveDataFile) {
        if (saveDataFile == nullptr || saveDataFile->empty()) {
            LOG_DEBUG("Invalid save data file provided for initialization.\n");
            return false;
        }
        if (!initialized) {
            LOG_DEBUG("initializing ListOBranch...\n");
            // init here
            loadData(saveDataFile);
            initialized = true;
            LOG_DEBUG("Initialized ListOBranch!\n");
            return true;
        }
        LOG_DEBUG("Already initialized ListOBranch!\n");
        return false;
    }

    bool initialize() {
        if (!initialized) {
            LOG_DEBUG("initializing ListOBranch...\n");
            // init here
            initialized = true;
            LOG_DEBUG("Initialized ListOBranch!\n");
            return true;
        }
        LOG_DEBUG("Already initialized ListOBranch!\n");
        return false;
    }

    bool safeExit(std::string* saveDataFile) {
        if (saveDataFile == nullptr || saveDataFile->empty()) {
            LOG_DEBUG("Invalid save data file provided for safe exit.\n");
            return false;
        }
        if (initialized) {
            LOG_DEBUG("Exiting ListOBranch safely...\n");
            // cleanup here
            saveData(saveDataFile);
            initialized = false;
            LOG_DEBUG("ListOBranch exited safely.\n");
        } else {
            LOG_DEBUG("ListOBranch was not initialized. No need to exit safely.\n");
            return false;
        }
        return true;
    }

    bool safeExit() {
        if (initialized) {
            LOG_DEBUG("Exiting ListOBranch safely...\n");
            // cleanup here
            initialized = false;
            LOG_DEBUG("ListOBranch exited safely.\n");
        } else {
            LOG_DEBUG("ListOBranch was not initialized. No need to exit safely.\n");
            return false;
        }
        return true;
    }

    bool saveData(const std::string* filename) {
        if (filename == nullptr || filename->empty()) {
            LOG_DEBUG("Invalid filename provided for saving data.\n");
            return false;
        }
        LOG_DEBUG("Saving data to " + *filename + "...\n");
        // Dummy implementation
        LOG_DEBUG("Data saved to " + *filename + "\n");
        return true;
    }

    bool loadData(const std::string* filename) {
        LOG_DEBUG("Loading data from " + *filename + "...\n");
        // Dummy implementation
        LOG_DEBUG("Data loaded from " + *filename + "\n");
        return true;
    }

    std::vector<Repo::RepoData*> getRepositories() {
        return repositories;
    }

    bool addRepository(Repo::RepoData* repo) {
        repositories.push_back(repo);
        return true;
    }

    bool addRepository(const std::string* name) {
        Repo::RepoData* repo = new Repo::RepoData();
        repo->name = *name;
        repositories.push_back(repo);
        return true;
    }

    bool removeRepository(const Repo::RepoData* repo) {
        LOG_DEBUG("Finding repository: " + repo->name + "\n");
        auto it = std::remove_if(repositories.begin(), repositories.end(),
                                 [repo](Repo::RepoData* r) { return r->name == repo->name; });
        if (it != repositories.end()) {
            repositories.erase(it, repositories.end());
            LOG_DEBUG("Repository removed: " + repo->name + "\n");
            return true;
        }
        LOG_DEBUG("Repository not found: " + repo->name + "\n");
        return false;
    }

    bool removeRepository(std::string* name) {
        LOG_DEBUG("Finding repository: " + *name + "\n");
        auto it = std::remove_if(repositories.begin(), repositories.end(),
                                 [*name](Repo::RepoData* r) { return r->name == *name; });
        if (it != repositories.end()) {
            repositories.erase(it, repositories.end());
            LOG_DEBUG("Repository removed: " + *name + "\n");
            return true;
        }
        LOG_DEBUG("Repository not found: " + *name + "\n");
        return false;
    }
    
    bool addBranchToRepository(Repo::RepoData* repo, Branch::BranchData* branch) {
        LOG_DEBUG("Adding branch " + branch->name + " to repository " + repo->name + "\n");
        for (Repo::RepoData* r : repositories) {
            if (r->name == repo->name) {
                if (Repo::addBranchToRepository(r, branch)){
                    LOG_DEBUG("Added branch " + branch->name + " to repository " + repo->name + "\n");
                    return true;
                } else {
                    LOG_DEBUG("Failed to add branch " + branch->name + " to repository " + repo->name + "\n");
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " + repo->name + "\n");
        return false;
    }

    bool addBranchToRepository(Repo::RepoData* repo, const std::string* branchName) {
        LOG_DEBUG("Adding branch " + *branchName + " to repository " + repo->name + "\n");
        for (Repo::RepoData* r : repositories) {
            if (r->name == repo->name) {
                if (Repo::addBranchToRepository(r, branchName)) {
                    LOG_DEBUG("Added branch " + *branchName + " to repository " + repo->name + "\n");
                    return true;
                } else {
                    LOG_DEBUG("Failed to add branch " + *branchName + " to repository " + repo->name + "\n");
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " + repo->name + "\n");
        return false;
    }

    bool addBranchToRepository(std::string* repoName, Branch::BranchData* branch) {
        LOG_DEBUG("Adding branch " + branch->name + " to repository " + *repoName + "\n");
        for (Repo::RepoData* r : repositories) {
            if (r->name == *repoName) {
                if (Repo::addBranchToRepository(r, branch)) {
                    LOG_DEBUG("Added branch " + branch->name + " to repository " + *repoName + "\n");
                    return true;
                } else {
                    LOG_DEBUG("Failed to add branch " + branch->name + " to repository " + *repoName + "\n");
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " + *repoName + "\n");
        return false;
    }

    bool addBranchToRepository(const std::string* repoName, const std::string* branchName) {
        LOG_DEBUG("Adding branch " + *branchName + " to repository " + *repoName + "\n");
        for (Repo::RepoData* r : repositories) {
            if (r->name == *repoName) {
                if (Repo::addBranchToRepository(r, branchName)) {
                    LOG_DEBUG("Added branch " + *branchName + " to repository " + *repoName + "\n");
                    return true;
                } else {
                    LOG_DEBUG("Failed to add branch " + *branchName + " to repository " + *repoName + "\n");
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " + *repoName + "\n");
        return false;
    }

    /*
    bool removeBranchFromRepository(Repo::RepoData* repo, const Branch::BranchData* branch) {
        LOG_DEBUG("Removing branch " + branch->name + " from repository " + repo->name + "\n");
        for (const Repo::RepoData* r : repositories) {
            if (r->name == repo->name) {
                if (Repo::deleteBranchFromRepository(r, branch)) {
                    LOG_DEBUG("Removed branch " + branch->name + " from repository " + repo->name + "\n");
                    return true;
                } else {
                    LOG_DEBUG("Failed to remove branch " + branch->name + " from repository " + repo->name + "\n");
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " + repo->name + "\n");
        return false;
    }

    bool removeBranchFromRepository(Repo::RepoData* repo, const std::string* branchName) {
        LOG_DEBUG("Removing branch " + *branchName + " from repository " + repo->name + "\n");
        for (const Repo::RepoData* r : repositories) {
            if (r->name == repo->name) {
                if (Repo::deleteBranchFromRepository(r, branchName)) {
                    LOG_DEBUG("Removed branch " + *branchName + " from repository " + repo->name + "\n");
                    return true;
                } else {
                    LOG_DEBUG("Failed to remove branch " + *branchName + " from repository " + repo->name + "\n");
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " + repo->name + "\n");
        return false;
    }

    bool removeBranchFromRepository(const std::string* repoName, const Branch::BranchData* branch) {
        LOG_DEBUG("Removing branch " + branch->name + " from repository " + *repoName + "\n");
        for (const Repo::RepoData* r : repositories) {
            if (r->name == *repoName) {
                if (Repo::deleteBranchFromRepository(r, branch)) {
                    LOG_DEBUG("Removed branch " + branch->name + " from repository " + *repoName + "\n");
                    return true;
                } else {
                    LOG_DEBUG("Failed to remove branch " + branch->name + " from repository " + *repoName + "\n");
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " + *repoName + "\n");
        return false;
    }

    bool removeBranchFromRepository(const std::string* repoName, const std::string* branchName) {
        LOG_DEBUG("Removing branch " + *branchName + " from repository " + *repoName + "\n");
        for (const Repo::RepoData* r : repositories) {
            if (r->name == *repoName) {
                if (Repo::deleteBranchFromRepository(r, branchName)) {
                    LOG_DEBUG("Removed branch " + *branchName + " from repository " + *repoName + "\n");
                    return true;
                } else {
                    LOG_DEBUG("Failed to remove branch " + *branchName + " from repository " + *repoName + "\n");
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " + *repoName + "\n");
        return false;
    }*/
}
