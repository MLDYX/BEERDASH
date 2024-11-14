#pragma once
#include <string>

class Stars {
public:
    Stars();
    void collectStar(int starCollected);
    void saveProgress() const;
    void loadProgress();
    float getStarCount() const;

private:
    float starCount;
    std::string encrypt(const std::string& data, int shift) const;
    std::string decrypt(const std::string& data, int shift) const;
    const std::string progressFile = "progress.txt";
    const int cipherShift = 420;
};