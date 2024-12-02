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
    std::unordered_map<std::string, std::unordered_set<int>> collectedStars;
    std::unordered_map<std::string, int> starCounts;
    const std::string progressFile = "progress.txt";

    int latoStarCount;
    int jesienStarCount;
    int zimaStarCount;
};
