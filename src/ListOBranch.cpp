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
        if (!initialized) {
            std::cout << "initializing ListOBranch...\n";
            // init here
            if (!saveDataFile.empty()) {
                loadData(saveDataFile);
            }
            initialized = true;
            std::cout << "Initialized ListOBranch!\n";
            return true;
        }
        std::cout << "Already initialized ListOBranch!\n";
        return false;
    }

    bool saveData(const std::string& filename) {
        std::cout << "Saving data to " << filename << "...\n";
        // Dummy implementation
        std::cout << "Data saved to " << filename << std::endl;
        return true;
    }

    bool loadData(const std::string& filename) {
        std::cout << "Loading data from " << filename << "...\n";
        // Dummy implementation
        std::cout << "Data loaded from " << filename << std::endl;
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
        std::cout << "Removing repository: " << repo.name << "\n";
        auto it = std::remove_if(repositories.begin(), repositories.end(),
                                 [&repo](const Repo::RepoData& r) { return r.name == repo.name; });
        if (it != repositories.end()) {
            repositories.erase(it, repositories.end());
            std::cout << "Repository removed: " << repo.name << "\n";
            return true;
        }
        std::cout << "Repository not found: " << repo.name << "\n";
        return false;
    }
}
