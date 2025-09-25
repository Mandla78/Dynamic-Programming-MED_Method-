#include "Forward.h"
#include <iomanip>
#include <algorithm>

using namespace std;

// Compute the DP table and return the minimum edit distance
int Forward::computeDP(const string& w1, const string& w2) {
    word1 = w1;
    word2 = w2;
    dp = vector<vector<int>>(word2.size() + 1, vector<int>(word1.size() + 1)); // DP matrix

    // Base cases-transforming empty string
    for (int i = 0; i <= word2.size(); ++i) dp[i][0] = i;
    for (int j = 0; j <= word1.size(); ++j) dp[0][j] = j;

    // Fill DP table
    for (int i = 1; i <= word2.size(); ++i) {
        for (int j = 1; j <= word1.size(); ++j) {
            if (word1[j - 1] == word2[i - 1])
                dp[i][j] = dp[i - 1][j - 1]; // no cost if charecters match
            else
                dp[i][j] = min(
                    dp[i - 1][j - 1] + 2, // Replacement cost = 2
                    min(
                        dp[i - 1][j] + 1, // Insertion cost = 1
                        dp[i][j - 1] + 1  // Deletion cost = 1
                        )
                );
        }
    }

    return dp[word2.size()][word1.size()]; // Minimum Edit Distance(MED)-(buttom-right cell)
}

// Determine max cell width for proper alignment
int Forward::getMaxCellWidth() const {
    int maxVal = 0;
    for (auto &row : dp)
        for (int val : row)
            if (val > maxVal) maxVal = val;

    int width = 1;
    while (maxVal) { maxVal /= 10; width++; }
    width += 2;
    return width;
}

// Print full DP table
void Forward::printDP() const {
    int width = getMaxCellWidth();
    cout << "\nDP Table using MED(Forward Stage)\n\n";
    cout << setw(width) << "_";
    for (char c : word1) cout << setw(width) << c;
    cout << "\n";

    for (int i = 0; i <= word2.size(); ++i) {
        if (i == 0) cout << setw(width) << "_";
        else cout << setw(width) << word2[i - 1];

        for (int j = 0; j <= word1.size(); ++j)
            cout << setw(width) << dp[i][j];
        cout << "\n";
    }
}
