#include "listobranch/listobranch.h"

namespace ListOBranch{
    bool initialized = false;
    std::vector<ListOBranch::Repo::RepoData> repositories;
}

namespace ListOBranch {
    std::string getVersion() {
        return VERSION;
    }

    bool initialize() {
        if (!initialized) {
            LOB_DEBUG("initializing ListOBranch...\n");
            // init here
            initialized = true;
            LOB_DEBUG("Initialized ListOBranch!\n");
            return true;
        }
        LOB_DEBUG("Already initialized ListOBranch!\n");
        return false;
    }

    bool initialize(std::string saveDataFile) {
        if (saveDataFile.empty()) {
            return false;
        }
        if (!initialized) {
            LOB_DEBUG("initializing ListOBranch...\n");
            // init here
            loadData(saveDataFile);
            initialized = true;
            LOB_DEBUG("Initialized ListOBranch!\n");
            return true;
        }
        LOB_DEBUG("Already initialized ListOBranch!\n");
        return false;
    }

    bool saveData(const std::string& filename) {
        LOB_DEBUG("Saving data to " + filename + "...\n");
        // Dummy implementation
        LOB_DEBUG("Data saved to " + filename + "\n");
        return true;
    }

    bool loadData(const std::string& filename) {
        LOB_DEBUG("Loading data from " + filename + "...\n");
        // Dummy implementation
        LOB_DEBUG("Data loaded from " + filename + "\n");
        return true;
    }

    std::vector<Repo::RepoData> getRepositories() {
        return repositories;
    }

    bool addRepository(const Repo::RepoData& repo) {
        repositories.push_back(repo);
        return true;
    }

    bool removeRepository(const Repo::RepoData& repo) {
        LOB_DEBUG("Removing repository: " + repo.name + "\n");
        auto it = std::remove_if(repositories.begin(), repositories.end(),
                                 [&repo](const Repo::RepoData& r) { return r.name == repo.name; });
        if (it != repositories.end()) {
            repositories.erase(it, repositories.end());
            LOB_DEBUG("Repository removed: " + repo.name + "\n");
            return true;
        }
        LOB_DEBUG("Repository not found: " + repo.name + "\n");
        return false;
    }
}
