#ifndef BACKWARD_H
#define BACKWARD_H

#include "Forward.h"
#include <string>

/*
 * Backward Stage class
 * -----------------
 * - Traces the path of the minimal edit distance
 *   from bottom-right corner of DP table to top-left corner.
 * - Only prints the path cells used to achieve MED.
 */
class Backward {
public:
    // Trace and print only minimal path
    void tracePath(const Forward& fwd);
};

#endif
