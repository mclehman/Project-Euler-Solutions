/* Project Euler Problem 3:

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Hardcode target number rather than deal with I/O
#define  TARGET 600851475143
// Assume maximum of 100 prime factors
#define  MAXFACTORS 100

// Determines if the requested number is prime
bool isPrime(long n) {
    // Check for 2 explicitly, as it is the only even prime
    if (n == 2) {
        return true;
    } else if (n % 2 == 0){// Check for divisiblity by two
        return false;
    } else {
        // Check for divisibility by odd numbers, all even numbers already dealt with
        for (long div = 3; div <= (int)ceil(sqrt(n)); div += 2) {
            // Return false if n is divisible by any number up to its square root
            if (n % div == 0) {
                return false;
            }
        }
    }

    return true;
}

// Returns a pointer to an array of the requested numbers prime factors
long * primeFactorsOf(long n) {
    // Zero out entire array
    static long factors[MAXFACTORS] = {0};
    int index = 0;
    // Loop through integers > 1 up to the square root of the number
    for (long div = 2; div <= (int)ceil(sqrt(n)); div++) {
        // check for divisibility and do not check primehood if unnecessary
        if ((n % div == 0) && isPrime(div)) {
            // Add prime factors to array and increment index
            factors[index] = div;
            index++;
        }
    }

    return factors;
}

// Returns the largest prime factor of requested number
long largestPrimeFactor(long n) {
    // Obtains pointer to array of prime factors
    long *factors = primeFactorsOf(n);

    long largest = factors[0];
    int index = 0;
    // Loop through array and update largest as needed
    while(index < MAXFACTORS) {
        if (*(factors + index) > largest) {
            largest = *(factors + index);
        }
        index++;
    }

    return largest;
}

// Prints out the largest prime factor of TARGET
int main() {
    printf("The largest prime factor of %ld is %ld.\n", TARGET, largestPrimeFactor(TARGET));
    return 0;
}
