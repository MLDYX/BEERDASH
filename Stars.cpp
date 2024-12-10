#include "Stars.h"
#include <SDL.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <Windows.h>


Stars::Stars() : star1(0), star2(0), star3(0), starCount(0), latoStarCount(2.0f), jesienStarCount(2.0f), zimaStarCount(2.0f) {
    loadProgress();
}

void Stars::collectStar1(const std::string& map) {
    if (collectedStars[map].insert(1).second) {
        star1++;
        starCount++;
        starCounts[map]++;
        if (map == "lato") latoStarCount++;
        else if (map == "jesien") jesienStarCount++;
        else if (map == "zima") zimaStarCount++;
    }
    saveProgress();
}

void Stars::collectStar2(const std::string& map) {
    if (collectedStars[map].insert(2).second) {
        star2++;
        starCount++;
        starCounts[map]++;
        if (map == "lato") latoStarCount++;
        else if (map == "jesien") jesienStarCount++;
        else if (map == "zima") zimaStarCount++;
    }
    saveProgress();
}

void Stars::collectStar3(const std::string& map) {
    if (collectedStars[map].insert(3).second) {
        star3++;
        starCount++;
        starCounts[map]++;
        if (map == "lato") latoStarCount++;
        else if (map == "jesien") jesienStarCount++;
        else if (map == "zima") zimaStarCount++;
    }
    saveProgress();
}

float Stars::getLatoStarCount() const {
    return latoStarCount;
}

float Stars::getJesienStarCount() const {
    return jesienStarCount;
}

float Stars::getZimaStarCount() const {
    return zimaStarCount;
}

void Stars::saveProgress() const {
    std::ofstream file(progressFile);
    if (file.is_open()) {
        for (const auto& mapStars : collectedStars) {
            file << mapStars.first << ":";
            for (const auto& star : mapStars.second) {
                file << star << ",";
            }
            file << "\n";
        }
        file << "latoStarCount:" << latoStarCount << "\n";
        file << "jesienStarCount:" << jesienStarCount << "\n";
        file << "zimaStarCount:" << zimaStarCount << "\n";
        file.close();
    }
}

void Stars::loadProgress() {
    std::ifstream file(progressFile);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::string key;
            if (std::getline(ss, key, ':')) {
                if (key == "latoStarCount") {
                    ss >> latoStarCount;
                }
                else if (key == "jesienStarCount") {
                    ss >> jesienStarCount;
                }
                else if (key == "zimaStarCount") {
                    ss >> zimaStarCount;
                }
                else {
                    std::string stars;
                    if (std::getline(ss, stars)) {
                        std::istringstream starsStream(stars);
                        std::string star;
                        while (std::getline(starsStream, star, ',')) {
                            if (!star.empty()) {
                                collectedStars[key].insert(std::stoi(star));
                                starCount++;
                            }
                        }
                    }
                }
            }
        }
        file.close();
    }
}

float Stars::getStarCount() const {
    return starCount;
}

bool Stars::isStarCollected(const std::string& map, int star) const {
    return collectedStars.at(map).find(star) != collectedStars.at(map).end();
}
