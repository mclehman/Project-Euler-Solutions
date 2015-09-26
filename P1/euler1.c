/* Project Euler Problem 1:

If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>

// Returns the sum the multiples of factor1 and factor2 below limit
int sumMultiplesBelow (int limit, int factor1, int factor2) {
    int result = 0;

    for (int i = 0; i < limit; i++) {
        if (i % factor1 == 0 || i % factor2 == 0) {
            result += i;
        }
    }

    return result;
}

// Prints the sum of multiples of factor1 and factor2 below limit.
int main() {
    int limit = 1000;
    int factor1 = 3;
    int factor2 = 5;

    printf("The sum of multiples of %d and %d below %d is %d\n",
           factor1, factor2, limit, sumMultiplesBelow(limit, factor1, factor2));

    return 0;
}
