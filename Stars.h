#pragma once
#include <string>

class Stars {
public:
    Stars();
    void collectStar1();
    void collectStar2();
    void collectStar3();
    void saveProgress() const;
    void loadProgress();
    float getStarCount() const;
    int star1;
    int star2;
    int star3;

private:
    float starCount;
    std::string encrypt(const std::string& data, int shift) const;
    std::string decrypt(const std::string& data, int shift) const;
    const std::string progressFile = "progress.txt";
    const int cipherShift = 420;
};