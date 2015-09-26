#include <stdio.h>
#include <math.h>

#define  TARGET 600851475143
#define  MAXFACTORS 100

typedef int bool;
#define true 1
#define false 0

bool isPrime(long n) {
    if (n == 2) {
        return true;
    } else if (n % 2 == 0){// Check for divisiblity by two
        return false;
    } else {
        for (long div = 3; div <= (int)ceil(sqrt(n)); div += 2) {
            if (n % div == 0) {
                return false;
            }
        }
    }
    return true;
}

long * primeFactorsOf(long n) {
    static long factors[MAXFACTORS] = {0};
    int j = 0;
    for (long i = 2; i < (int)ceil(sqrt(n)); i++) {
        //printf("Checking if %ld is a prime factor of %ld\n", i, n);
        if ((n % i == 0) && isPrime(i)) {
            factors[j] = i;
            j++;
        }
    }

    return factors;
}

long largestPrimeFactor(long n) {
    long *factors = primeFactorsOf(n);

    long largest = factors[0];
    int i = 0;
    while(i < MAXFACTORS) {
        //printf("Checking if %ld is greater than %ld\n", *(factors + i), largest);
        if (*(factors + i) > largest) {
            largest = *(factors + i);
        }
        i++;
    }

    return largest;
}

int main() {
    printf("%ld\n", largestPrimeFactor(TARGET));
    return 0;
}
