#include "Forward.h"
#include "Backward.h"
#include <iostream>
using namespace std;

/*
 * main.cpp
 * ---------
 * - Gets input words from user.
 * - Uses Forward Stage class to build and print DP table.
 * - Uses Backward Stage class to trace and print minimal path.
 */
int main() {
    Forward fwd;
    Backward bwd;
    string source, target;

    cout << "Enter the source word: ";
    cin >> source;
    cout << "Enter the target word: ";
    cin >> target;


    // Compute minimum edit distance using Forward Stage
    int distance = fwd.computeDP(source, target);
    fwd.printDP(); // Print full DP table

    cout << "\nMinimum Edit Distance: " << distance << endl;

    bwd.tracePath(fwd); //Trace and print only MED path


    return 0;
}
