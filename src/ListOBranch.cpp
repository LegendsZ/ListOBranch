#include "listobranch/listobranch.h"

namespace ListOBranch {
    bool initialized = false;
    std::vector<ListOBranch::Repo::RepoData*> repositories;

    std::string getVersion() {
        return VERSION;
    }

    bool initialize(std::string* saveDataFile) {
        if (saveDataFile == nullptr || saveDataFile->empty()) {
            LOG_DEBUG("Invalid save data file provided for initialization.");
            return false;
        }
        if (!initialized) {
            LOG_DEBUG("initializing ListOBranch...");
            loadData(saveDataFile);
            initialized = true;
            LOG_DEBUG("Initialized ListOBranch!");
            return true;
        }
        LOG_DEBUG("Already initialized ListOBranch!");
        return false;
    }

    bool initialize() {
        if (!initialized) {
            LOG_DEBUG("initializing ListOBranch...");
            initialized = true;
            LOG_DEBUG("Initialized ListOBranch!");
            return true;
        }
        LOG_DEBUG("Already initialized ListOBranch!");
        return false;
    }

    bool safeExit(std::string* saveDataFile) {
        if (saveDataFile == nullptr || saveDataFile->empty()) {
            LOG_DEBUG("Invalid save data file provided for safe exit.");
            return false;
        }
        if (initialized) {
            LOG_DEBUG("Exiting ListOBranch safely...");
            saveData(saveDataFile);
            initialized = false;
            LOG_DEBUG("ListOBranch exited safely.");
        } else {
            LOG_DEBUG("ListOBranch was not initialized. No need to exit safely.");
            return false;
        }
        return true;
    }

    bool safeExit() {
        if (initialized) {
            LOG_DEBUG("Exiting ListOBranch safely...");
            initialized = false;
            LOG_DEBUG("ListOBranch exited safely.");
        } else {
            LOG_DEBUG("ListOBranch was not initialized. No need to exit safely.");
            return false;
        }
        return true;
    }

    bool saveData(const std::string* filename) {
        if (filename == nullptr || filename->empty()) {
            LOG_DEBUG("Invalid filename provided for saving data.");
            return false;
        }
        LOG_DEBUG("Saving data to " << *filename << "...");
        LOG_DEBUG("Data saved to " << *filename);
        return true;
    }

    bool loadData(const std::string* filename) {
        LOG_DEBUG("Loading data from " << *filename << "...");
        LOG_DEBUG("Data loaded from " << *filename);
        return true;
    }

    std::vector<Repo::RepoData*> getRepositories() {
        return repositories;
    }

    bool addRepository(Repo::RepoData* repo) {
        repositories.push_back(repo);
        return true;
    }

    bool addRepository(const std::string* name, const std::string* remoteUrl, const std::string* localPath) {
        Repo::RepoData* repo = new Repo::RepoData();
        repo->name = *name;
        repo->remoteUrl = *remoteUrl;
        repo->localPath = *localPath;
        repositories.push_back(repo);
        return true;
    }

    bool removeRepository(const Repo::RepoData* repo) {
        LOG_DEBUG("Finding repository: " << repo->name);
        auto it = std::remove_if(repositories.begin(), repositories.end(),
                                 [repo](Repo::RepoData* r) { return r->name == repo->name; });
        if (it != repositories.end()) {
            repositories.erase(it, repositories.end());
            LOG_DEBUG("Repository removed: " << repo->name);
            return true;
        }
        LOG_DEBUG("Repository not found: " << repo->name);
        return false;
    }

    bool removeRepository(std::string* name) {
        LOG_DEBUG("Finding repository: " << *name);
        auto it = std::remove_if(repositories.begin(), repositories.end(),
                                 [name](Repo::RepoData* r) { return r->name == *name; });
        if (it != repositories.end()) {
            repositories.erase(it, repositories.end());
            LOG_DEBUG("Repository removed: " << *name);
            return true;
        }
        LOG_DEBUG("Repository not found: " << *name);
        return false;
    }

    //TODO: add removeRepository by remote url and/or local path.

    bool addBranchToRepository(Repo::RepoData* repo, Branch::BranchData* branch) {
        LOG_DEBUG("Adding branch " << branch->name << " to repository " << repo->name);
        for (Repo::RepoData* r : repositories) {
            if (r->name == repo->name) {
                if (Repo::addBranchToRepository(r, branch)){
                    LOG_DEBUG("Added branch " << branch->name << " to repository " << repo->name);
                    return true;
                } else {
                    LOG_DEBUG("Failed to add branch " << branch->name << " to repository " << repo->name);
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " << repo->name);
        return false;
    }

    bool addBranchToRepository(Repo::RepoData* repo, const std::string* branchName, const std::string* prLink) {
        LOG_DEBUG("Adding branch " << *branchName << " to repository " << repo->name);
        for (Repo::RepoData* r : repositories) {
            if (r->name == repo->name) {
                if (Repo::addBranchToRepository(r, branchName, prLink)) {
                    LOG_DEBUG("Added branch " << *branchName << " to repository " << repo->name);
                    return true;
                } else {
                    LOG_DEBUG("Failed to add branch " << *branchName << " to repository " << repo->name);
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " << repo->name);
        return false;
    }

    bool addBranchToRepository(std::string* repoName, Branch::BranchData* branch) {
        LOG_DEBUG("Adding branch " << branch->name << " to repository " << *repoName);
        for (Repo::RepoData* r : repositories) {
            if (r->name == *repoName) {
                if (Repo::addBranchToRepository(r, branch)) {
                    LOG_DEBUG("Added branch " << branch->name << " to repository " << *repoName);
                    return true;
                } else {
                    LOG_DEBUG("Failed to add branch " << branch->name << " to repository " << *repoName);
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " << *repoName);
        return false;
    }

    bool addBranchToRepository(const std::string* repoName, const std::string* branchName, const std::string* prLink) {
        LOG_DEBUG("Adding branch " << *branchName << " to repository " << *repoName);
        for (Repo::RepoData* r : repositories) {
            if (r->name == *repoName) {
                if (Repo::addBranchToRepository(r, branchName, prLink)) {
                    LOG_DEBUG("Added branch " << *branchName << " to repository " << *repoName);
                    return true;
                } else {
                    LOG_DEBUG("Failed to add branch " << *branchName << " to repository " << *repoName);
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " << *repoName);
        return false;
    }

     bool removeBranchFromRepository(Repo::RepoData* repo, Branch::BranchData* branch) {
        LOG_DEBUG("Removing branch " << branch->name << " from repository " << repo->name);
        for (Repo::RepoData* r : repositories) {
            if (r->name == repo->name) {
                if (Repo::removeBranchFromRepository(r, branch)) {
                    LOG_DEBUG("Removed branch " << branch->name << " from repository " << repo->name);
                    return true;
                } else {
                    LOG_DEBUG("Failed to remove branch " << branch->name << " from repository " << repo->name);
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " << repo->name);
        return false;
    }

    bool removeBranchFromRepository(Repo::RepoData* repo, const std::string* branchName) {
        LOG_DEBUG("Removing branch " << *branchName << " from repository " << repo->name);
        for (Repo::RepoData* r : repositories) {
            if (r->name == repo->name) {
                if (Repo::removeBranchFromRepository(r, branchName)) {
                    LOG_DEBUG("Removed branch " << *branchName << " from repository " << repo->name);
                    return true;
                } else {
                    LOG_DEBUG("Failed to remove branch " << *branchName << " from repository " << repo->name);
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " << repo->name);
        return false;
    }

    bool removeBranchFromRepository(std::string* repoName, Branch::BranchData* branch) {
        LOG_DEBUG("Removing branch " << branch->name << " from repository " << *repoName);
        for (Repo::RepoData* r : repositories) {
            if (r->name == *repoName) {
                if (Repo::removeBranchFromRepository(r, branch)) {
                    LOG_DEBUG("Removed branch " << branch->name << " from repository " << *repoName);
                    return true;
                } else {
                    LOG_DEBUG("Failed to remove branch " << branch->name << " from repository " << *repoName);
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " << *repoName);
        return false;
    }

    bool removeBranchFromRepository(const std::string* repoName, const std::string* branchName) {
        LOG_DEBUG("Removing branch " << *branchName << " from repository " << *repoName);
        for (Repo::RepoData* r : repositories) {
            if (r->name == *repoName) {
                if (Repo::removeBranchFromRepository(r, branchName)) {
                    LOG_DEBUG("Removed branch " << *branchName << " from repository " << *repoName);
                    return true;
                } else {
                    LOG_DEBUG("Failed to remove branch " << *branchName << " from repository " << *repoName);
                    return false;
                }
            }
        }
        LOG_DEBUG("Repository not found: " << *repoName);
        return false;
    }
}
