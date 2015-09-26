#include <stdio.h>
#include <math.h>

// Define boolean type for clarity
typedef int bool;
#define true 1
#define false 0

// Returns the number of digits in the decimal representation of an integer
int digitLength(int n) {
    // One digit assumed until proven otherwise
    int result = 1;
    while(n > 9) {
        // Divides n by 10 until a single digit number is reached, incrementing result each time
        n = n / 10;
        result++;
    }

    return result;
}

// Returns true (1) if the decimal representation of the integer is a palindrome
bool isPalindrome(int n) {
    int numDigits = digitLength(n);
    int iDigit;       // Most signficant digit
    int iMirrorDigit; // Least significant digit

    for (int i = numDigits; i > (numDigits / 2) - 1; i--) {
        // iDigit is set to the i-th digit of n
        iDigit = (n % (int)pow(10, i)) / pow(10, i - 1);
        // Its complement is set to the i-th digit from the left
        iMirrorDigit = (n % (int)pow(10, numDigits - i + 1)) / pow(10, numDigits - i);

        if (iDigit != iMirrorDigit) {
            return false;
        }
    }
    return true;
}

// Returns the largest product of n-digit integers that is a palindrome
int largestPalindromeProduct(int n) {
    int minInt  = (int)(pow(10, n - 1)); // 10^(n - 1) is the smallest n-digit integer
    int maxInt  = (int)(pow(10, n)) - 1; // 10^(n) - 1 is the largest  n-digit integer
    int current;
    int largest = 0; // return 0 if no palindrome product exists

    // Loop through every possible combination of n-digit integers, updating the largest as needed
    for (int i = maxInt; i >= minInt; i--) {
        for (int j = maxInt; j >= minInt; j--) {
            current = i * j;
            if((current > largest) && isPalindrome(current)) {
                largest = current;
            }
        }
    }

    return largest;
}

int main() {
    int n = 3; // Dimension requested by Project Euler question. Generalized for kicks

    printf("The largest palindrome product of %d-digit integers is: %d\n", n, largestPalindromeProduct(n));
    return 0;
}
