#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <limits>

void ItemTracker::loadDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string item;
    itemFrequencies.clear(); // Clear the map to avoid retaining old data

    while (std::getline(file, item)) {
        if (!item.empty()) {
            itemFrequencies[item]++; // Increment the count for each item
        }
    }
}

int ItemTracker::getItemFrequency(const std::string& item) const {
    auto it = itemFrequencies.find(item);
    if (it != itemFrequencies.end()) {
        return it->second;
    }
    return 0; // Return 0 if the item is not found
}

void ItemTracker::printAllFrequencies() const {
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void ItemTracker::printHistogram() const {
    for (const auto& pair : itemFrequencies) {
        std::cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*"; // Print asterisks corresponding to the frequency
        }
        std::cout << std::endl;
    }
}
