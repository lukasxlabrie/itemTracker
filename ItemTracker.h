#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

class ItemTracker {
private:
    std::map<std::string, int> itemFrequencies; // Stores item names and their frequencies

public:
    void loadDataFromFile(const std::string& filename); // Loads data from a file and counts item frequencies
    int getItemFrequency(const std::string& item) const; // Returns the frequency of a specific item
    void printAllFrequencies() const; // Prints all items with their frequencies
    void printHistogram() const; // Prints a histogram of item frequencies
};

#endif
