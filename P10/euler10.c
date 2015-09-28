/* Project Euler Problem 9:

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// isPrime function from Problem 3
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

long primesBelow (long limit) {
    long candidate = 3; // three will be the first prime considered to rule out even numbers
    long    result = 2; // 2 is skipped and included in result from the start;

    while (candidate < limit) {
        if (isPrime(candidate)) {
            result += candidate;
        }

        candidate += 2;
    }

    return result;
}

// Prints the sum of all primes below limit
int main() {
    // Specified in the problem
    long limit = 2000000;

    printf("The sum of all primes below %ld is %ld\n",
           limit, primesBelow(limit));
    return 0;
}
