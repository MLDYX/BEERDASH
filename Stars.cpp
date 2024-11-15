#include "Stars.h"
#include <SDL.h>
#include <fstream>
#include <iostream>
#include <Windows.h>

Stars::Stars() : starCount(2.0) {
    loadProgress();
}

void Stars::collectStar1() {
    if (starCount == 2.0) {
        starCount = 3.0;
    }

    saveProgress();
}

void Stars::collectStar2() {
    if (starCount == 3.0) {
        starCount = 4.0;
    }

    saveProgress();
}

void Stars::collectStar3() {
    if (starCount == 4.0) {
        starCount = 5.0;

    }
    saveProgress();
}

void Stars::saveProgress() const {
    std::ofstream outFile(progressFile);
    if (outFile.is_open()) {
        std::string encryptedData = encrypt(std::to_string(starCount), cipherShift);
        outFile << encryptedData;
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for saving progress.\n";
    }
}

void Stars::loadProgress() {
    std::ifstream inFile(progressFile);
    if (inFile.is_open()) {
        std::string encryptedData;
        std::getline(inFile, encryptedData);
        if (!encryptedData.empty()) {
            std::string decryptedData = decrypt(encryptedData, cipherShift);
            starCount = std::stof(decryptedData);
        }
        inFile.close();
    }
    else {
        std::cerr << "Unable to open file for loading progress. Starting with default value.\n";
    }
}

float Stars::getStarCount() const {
    return starCount;
}

std::string Stars::encrypt(const std::string& data, int shift) const {
    std::string result = data;
    for (char& c : result) {
        c += shift;
    }
    return result;
}

std::string Stars::decrypt(const std::string& data, int shift) const {
    std::string result = data;
    for (char& c : result) {
        c -= shift;
    }
    return result;
}
