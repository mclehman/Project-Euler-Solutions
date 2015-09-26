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
    int index = 0;
    for (long div = 2; div <= (int)ceil(sqrt(n)); div++)
        if ((n % div == 0) && isPrime(div)) {
            factors[index] = div;
            index++;
        }
    }

    return factors;
}

long largestPrimeFactor(long n) {
    long *factors = primeFactorsOf(n);

    long largest = factors[0];
    int index = 0;
    while(index < MAXFACTORS) {
        if (*(factors + index) > largest) {
            largest = *(factors + index);
        }
        index++;
    }

    return largest;
}

int main() {
    printf("%ld\n", largestPrimeFactor(TARGET));
    return 0;
}
