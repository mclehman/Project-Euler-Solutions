/* Project Euler Problem 9:

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product a * b * c.
*/

#include <stdio.h>

// Returns the product of a Pythagorean triplet also satisfying a + b + c = targetSum
int tripletProduct (int targetSum) {
    int a = 0;
    int b = 0;
    int c = 0;

    /*  Generate candidate triplets with Eulid's Formula which states:
        Given integers m,n such that m > n, the integers (m^2 - n^2),
        (2*m*n), and (m^2 + n^2) form a Pythagorean triple. */
    for (int m = 1; m < targetSum; m++) {
        for (int n = 1; n < m; n++) {
            a = m*m - n*n;
            b = 2 * m * n;
            c = m*m + n*n;

            if (a + b + c == targetSum) {
                return a * b * c;
            }

        }
    }

    // return 0 if no triple satisfies the property
    return 0;
}

// Prints the product of the special Pythagorean triplet with a + b + c = 1000
int main() {
    // Specified in the problem
    int targetSum = 1000;

    printf("The product of this special Pythagorean triplet is %d\n",
           tripletProduct(targetSum));
    return 0;
}
