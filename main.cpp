#include <iostream>
#include <string>
#include "ItemTracker.h"

int main() {
    ItemTracker tracker;
    const std::string inputFile = "CS210_Project_Three_Input_File.txt";
    const std::string backupFile = "frequency.dat";

    // load data
    if (!tracker.LoadFromFile(inputFile)) {
        std::cout << "Error: could not open \"" << inputFile << "\".\n";
        return 1;
    }

    // write backup right away
    tracker.WriteBackup(backupFile);

    // simple menu loop
    while (true) {
        std::cout << "\n==== Corner Grocer ====\n";
        std::cout << "1. Find item frequency\n";
        std::cout << "2. Print all frequencies\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose (1-4): ";

        int choice = 0;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            std::cout << "Enter item (one word): ";
            std::string item;
            std::cin >> item;
            std::cout << item << " " << tracker.GetCount(item) << "\n";
        } else if (choice == 2) {
            tracker.PrintAll();
        } else if (choice == 3) {
            tracker.PrintHistogram();
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}
