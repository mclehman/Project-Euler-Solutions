#include <stdio.h>
#include <math.h>

#define TARGET 10001

typedef int   bool;
#define true  1
#define false 0

bool isPrime(long n) {
    //printf("Checking if %ld is prime\n", n);
    if (n == 2) {
        return true;
    } else if (n % 2 == 0){
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

int * firstnPrimes() {
    static int primes[TARGET];

    int i = 2;
    int j = 0;
    while(j < TARGET){
        if (isPrime(i)) {
            primes[j] = i;
            j++;
        }
    i++;
    }

    return primes;
}

int main() {
    int *primes = firstnPrimes();
    printf("%d\n", *(primes + TARGET - 1));
    return 0;
}
