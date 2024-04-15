#include "ItemTracker.h"
#include <iostream>
#include <string>

int main() {
    ItemTracker tracker;
    tracker.loadDataFromFile("items.txt"); // Load data from the specified file

    int choice = 0;
    while (choice != 4) {
        std::cout << "1. Search for an item frequency\n";
        std::cout << "2. Print all item frequencies\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip to the next line
            continue;
        }

        std::string item;
        switch (choice) {
            case 1:
                std::cout << "Enter item name: ";
                std::cin >> item;
                std::cout << "Frequency: " << tracker.getItemFrequency(item) << std::endl;
                break;
            case 2:
                tracker.printAllFrequencies();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
