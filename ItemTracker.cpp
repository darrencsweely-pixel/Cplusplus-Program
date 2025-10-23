#include "ItemTracker.h"

#include <iostream>
#include <fstream>

// read words and count them
bool ItemTracker::LoadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        return false;
    }
    std::string word;
    while (in >> word) {
        ++freq[word];
    }
    return true;
}

// write "word count" to a file
bool ItemTracker::WriteBackup(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) {
        return false;
    }
    for (const auto& kv : freq) {
        out << kv.first << " " << kv.second << '\n';
    }
    return true;
}

// return count for a single word
int ItemTracker::GetCount(const std::string& word) const {
    auto it = freq.find(word);
    if (it == freq.end()) return 0;
    return it->second;
}

// print all "word count"
void ItemTracker::PrintAll() const {
    for (const auto& kv : freq) {
        std::cout << kv.first << " " << kv.second << '\n';
    }
}

// print "word *****" with stars = count
void ItemTracker::PrintHistogram() const {
    for (const auto& kv : freq) {
        std::cout << kv.first << " ";
        for (int i = 0; i < kv.second; ++i) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}