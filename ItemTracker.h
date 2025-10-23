#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <map>
#include <string>

class ItemTracker {
public:
    // load items from a text file (one word per token)
    bool LoadFromFile(const std::string& filename);

    // write backup file like "word count" per line
    bool WriteBackup(const std::string& filename) const;

    // get count for one word (0 if not found)
    int GetCount(const std::string& word) const;

    // print all "word count" lines
    void PrintAll() const;

    // print histogram "word *****"
    void PrintHistogram() const;

private:
    std::map<std::string, int> freq; // word -> count
};

#endif