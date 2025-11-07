#include "listobranch/listobranch.h"

namespace ListOBranch{
    bool initialized = false;
    std::vector<ListOBranch::Repo::RepoData> repositories;
}

namespace ListOBranch {
    std::string getVersion() {
        return VERSION;
    }
    
    bool initialize(std::string saveDataFile) {
        if (saveDataFile.empty()) {
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

    bool safeExit(std::string saveDataFile) {
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

    bool saveData(const std::string& filename) {
        LOG_DEBUG("Saving data to " + filename + "...\n");
        // Dummy implementation
        LOG_DEBUG("Data saved to " + filename + "\n");
        return true;
    }

    bool loadData(const std::string& filename) {
        LOG_DEBUG("Loading data from " + filename + "...\n");
        // Dummy implementation
        LOG_DEBUG("Data loaded from " + filename + "\n");
        return true;
    }

    std::vector<Repo::RepoData> getRepositories() {
        return repositories;
    }

    bool addRepository(const Repo::RepoData& repo) {
        repositories.push_back(repo);
        return true;
    }

    bool addRepository(const std::string& name) {
        Repo::RepoData repo;
        repo.name = name;
        repositories.push_back(repo);
        return true;
    }

    bool removeRepository(const Repo::RepoData& repo) {
        LOG_DEBUG("Removing repository: " + repo.name + "\n");
        auto it = std::remove_if(repositories.begin(), repositories.end(),
                                 [&repo](const Repo::RepoData& r) { return r.name == repo.name; });
        if (it != repositories.end()) {
            repositories.erase(it, repositories.end());
            LOG_DEBUG("Repository removed: " + repo.name + "\n");
            return true;
        }
        LOG_DEBUG("Repository not found: " + repo.name + "\n");
        return false;
    }

    bool removeRepository(const std::string& name) {
        LOG_DEBUG("Removing repository: " + name + "\n");
        auto it = std::remove_if(repositories.begin(), repositories.end(),
                                 [&name](const Repo::RepoData& r) { return r.name == name; });
        if (it != repositories.end()) {
            repositories.erase(it, repositories.end());
            LOG_DEBUG("Repository removed: " + name + "\n");
            return true;
        }
        LOG_DEBUG("Repository not found: " + name + "\n");
        return false;
    }
    
    bool addBranchToRepository(Repo::RepoData* repo, const Branch::BranchData* branch) {
        for (auto& r : repositories) {
            if (r.name == repo->name) {
                if (Repo::addBranchToRepository(&r, branch)) {
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
        for (auto& r : repositories) {
            if (r.name == repo->name) {
                if (Repo::addBranchToRepository(&r, branchName)) {
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

    bool addBranchToRepository(const std::string* repoName, const Branch::BranchData* branch) {
        for (auto& r : repositories) {
            if (r.name == *repoName) {
                if (Repo::addBranchToRepository(&r, branch)) {
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
        for (auto& r : repositories) {
            if (r.name == *repoName) {
                if (Repo::addBranchToRepository(&r, branchName)) {
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
}
