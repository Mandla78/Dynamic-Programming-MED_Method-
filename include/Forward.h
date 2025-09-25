#ifndef FORWARD_H
#define FORWARD_H

#include <iostream>
#include <vector>
#include <string>


/*
 * Forward Stage class
 * ----------------
 * - Builds the DP (Dynamic Programming) table for Minimum Edit Distance.
 * - Stores the DP table and the input words.
 * - Provides method to print the full DP table
 */

class Forward {
public:
    std::vector<std::vector<int>> dp; // DP table
    std::string word1, word2;  // source and target string

    // Compute DP table and return minimum edit distance
    int computeDP(const std::string& w1, const std::string& w2);

    // Print full DP table
    void printDP() const;

private:

    int getMaxCellWidth() const;
};

#endif
