#include <stdio.h>
#include <math.h>

// Hardcode requested prime index
#define TARGET 10001

// Define boolean type for clarity
typedef int   bool;
#define true  1
#define false 0

// Determines if the requested number is prime
bool isPrime(long n) {
    // Checks for 2 explicitly, as it is the only even prime
    if (n == 2) {
        return true;
    } else if (n % 2 == 0){ // Checks for divisiblity by two
        return false;
    } else {
        // Checks for divisibility by odd numbers, all even numbers already dealt with
        for (long div = 3; div <= (int)ceil(sqrt(n)); div += 2) {
            // Returns false if n is divisible by any number up to its square root
            if (n % div == 0) {
                return false;
            }
        }
    }
    return true;
}

// Returns a pointer to an array of the first TARGET primes
int * firstnPrimes() {
    static int primes[TARGET];

    primes[0] = 2; // Enters the only even prime to allow incrementing by 2 below

    int possible = 3;
    int index = 1;

    // Checks odd numbers for primehood until TARGET many are found and stored in primes
    while(index < TARGET){
        if (isPrime(possible)) {
            primes[index] = possible;
            index++;
        }
    possible += 2;
    }

    return primes;
}

// Prints the TARGET-th prime, conveniently located in the (TARGET - 1)-th index of primes.
int main() {
    int *primes = firstnPrimes();
    printf("%d\n", *(primes + TARGET - 1));
    return 0;
}
