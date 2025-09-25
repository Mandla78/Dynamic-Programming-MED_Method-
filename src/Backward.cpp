#include "Backward.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Trace back the path from bottom-right to top-left
void Backward::tracePath(const Forward& sol) {
    int i = sol.word2.size();
    int j = sol.word1.size();

    vector<vector<string>> path(sol.dp.size(), vector<string>(sol.dp[0].size(), "_"));

    // Backtracking the MED path
    while (i > 0 || j > 0) {
        path[i][j] = to_string(sol.dp[i][j]);

        if (i > 0 && j > 0 && sol.word1[j - 1] == sol.word2[i - 1])
            i--, j--; // match → move diagonally
        else if (i > 0 && j > 0 && sol.dp[i][j] == sol.dp[i - 1][j - 1] + 2)
            i--, j--; // replacement → diagonal
        else if (i > 0 && sol.dp[i][j] == sol.dp[i - 1][j] + 1)
            i--; // insertion → move up
        else if (j > 0 && sol.dp[i][j] == sol.dp[i][j - 1] + 1)
            j--; // deletion → move left
    }

    path[0][0] = to_string(sol.dp[0][0]); //Mark starting cell (0,0)

    // Determine cell width for alignment
    int width = 0;
    for (char c : sol.word1) width = max(width, 1);
    for (char c : sol.word2) width = max(width, 1);
    for (auto &row : path)
        for (auto &s : row) width = max(width, (int)s.length());
    width += 2;

    // Print backward DP path table
    cout << "\nDP TABLE SHOWING ONLY MINIMAL EDIT DISTANCE PATH(Backward Stage):\n\n";
    cout << setw(width) << "_";
    for (char c : sol.word1) cout << setw(width) << c;
    cout << "\n";

    for (size_t r = 0; r < path.size(); r++) {
        if (r == 0) cout << setw(width) << "_";
        else cout << setw(width) << sol.word2[r - 1];

        for (size_t c = 0; c < path[0].size(); c++)
            cout << setw(width) << path[r][c];
        cout << "\n";
    }
}

