# Dynamic Programming: Minimum Edit Distance (MED)

This project implements the **Minimum Edit Distance (MED)** algorithm using **Dynamic Programming (DP)** in C++.  
It consists of two main stages:

1. **Forward Stage (Forward)** – builds the DP table from top-left to bottom-right, computing the cost of operations.  
2. **Backward Stage (Backward)** – retraces the path from bottom-right to top-left, showing how the MED was achieved (insertions, deletions, replacements, or matches).  

---

## Project Structure
MED_Foward_&_Backward_Stage/
│
├── src/
│ ├── Forward.h # Header file for Forward class
│ ├── Forward.cpp # Implementation of Forward class
│ ├── Backward.h # Header file for Backward class
│ ├── Backward.cpp # Implementation of Backward class
│ └── main.cpp # Program entry point
├── .gitignore # Git ignore file
└── README.md # Project description and usage

---

##  How It Works

### Forward
- Creates a **2D DP table** where each cell `[i][j]` represents the minimum cost of converting the first `j` characters of `word1` to the first `i` characters of `word2`.
- Uses the recurrence relation:

 ### BackwardDP
- Starts from the **bottom-right corner** (MED value).  
- Traces backwards to **top-left**, reconstructing the sequence of operations that led to the minimal edit distance.
- Highlights only the path that contributes to MED.

---

##  How to Run

// Clone the repository
```bash
git clone https://github.com/Mandla78/Dynamic-Programming-MED_Method-.git
cd Dynamic-Programming-MED_Method-  

// Compile the code (using g++) on Windows CMD or PowerShel 
g++ src/*.cpp -o med
//Run the program
med

// Compile the code (using g++) On Unix/Linux or Mac (or Git Bash):
g++ src/*.cpp -o med
// Run the program
./med


