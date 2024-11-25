#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>

class Stars {
public:
    Stars();
    void collectStar1(const std::string& map);
    void collectStar2(const std::string& map);
    void collectStar3(const std::string& map);
    void saveProgress() const;
    void loadProgress();
    float getStarCount() const;
    bool isStarCollected(const std::string& map, int star) const;

    int star1;
    int star2;
    int star3;

    float getLatoStarCount() const;
    float getJesienStarCount() const;
    float getZimaStarCount() const;

private:
    float starCount;
    std::unordered_map<std::string, std::unordered_set<int>> collectedStars; // Map to track collected stars for each map
    std::unordered_map<std::string, int> starCounts;
    std::string encrypt(const std::string& data, int shift) const;
    std::string decrypt(const std::string& data, int shift) const;
    const std::string progressFile = "progress.txt";
    const int cipherShift = 420;

    int latoStarCount;
    int jesienStarCount;
    int zimaStarCount;
};
