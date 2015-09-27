/* Project Euler Problem 6:

The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first
ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first
one hundred natural numbers and the square of the sum.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Returns the sum of the squares of all numbers from 1 to upperLimit
long sumSquares(int upperLimit) {
    long result = 0;

    // Steps through number from 1 to upperLimit, and adds their square to result
    for (int num = 1; num <= upperLimit; num++) {
        result += num * num;
    }

    return result;
}

// Returns the square of the sum of all numbers from 1 to upperLimit
long squareSum(int upperLimit) {
    long result = 0;

    // Steps through number from 1 to upperLimit, and adds them to result
    for (int num = 1; num <= upperLimit; num++) {
        result += num;
    }

    // Squares and returns the sum
    return result * result;
}

// Prints the difference between sum of squares and square of sum of first x-many numbers
int main() {
    // Specified by the problem
    int upperLimit = 100;

    // Computes and stores the difference between requested values (squareSum is strictly larger)
    long result = squareSum(upperLimit) - sumSquares(upperLimit);

    printf("The difference between the sum of the squares and the square of the sum"
            "of the first %d natural numbers is: %ld\n",
            upperLimit, result);

    return 0;
}
