/* Project Euler Problem 5:

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>
#include <stdbool.h>

int smallestCommonMultiple(int lowerBound, int upperBound) {
    int  candidate = 0;
    bool searching = true;
    bool possible;

    while (searching) {
    // Every number that satisfies the requirement must be a multiple of upperBound
    candidate += upperBound;

    // Possible until proven otherwise
    possible = true;

        // Checks divisibility in the range, upperBound not checked, due to definition of candidate
        for (int div = lowerBound; div < upperBound; div++) {
            // Cannot fill criteria if not divisible by any divisor
            if (candidate % div != 0) {
                possible = false;
            }
        }

        // If no divisor failed above, end search and return
        if (possible) {
            searching = false;
        }
    }

    return candidate;
}

// Prints the smallest multiple of all numbers between lowerBound and upperBound
int main() {
    int lowerBound =  2; // all numbers are divisible by 1, so 2 is the actual lowerBound
    int upperBound = 20; // As specified in the problem

    printf("The smallest common multiple of all numbers between %d and %d is %d\n",
           lowerBound, upperBound, smallestCommonMultiple(lowerBound, upperBound));

    return 0;
}
