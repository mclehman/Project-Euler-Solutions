#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

int digitLength(int n) {
    int result = 1;
    while(n > 9) {
        n = n / 10;
        result++;
    }

    return result;
}

bool isPalindrome(int n) {
    int numDigits = digitLength(n);
    int iDigit;
    int iMirrorDigit;
    for (int i = numDigits; i > (numDigits / 2) - 1; i--) {
        iDigit = (n % (int)pow(10, i)) / pow(10, i - 1);
        iMirrorDigit = (n % (int)pow(10, numDigits - i + 1)) / pow(10, numDigits - i);
        if (iDigit != iMirrorDigit) {
            return false;
        }
    }
    return true;
}

int largestPalindromeProduct(int n) {
    int minInt  = (int)(pow(10, n - 1));
    int maxInt  = (int)(pow(10, n)) - 1;
    int current;
    int largest = 0;

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
    int n = 3;

    printf("Testing 1: %d\n", isPalindrome(1));
    printf("Testing 13: %d\n", isPalindrome(13));
    printf("Testing 131: %d\n", isPalindrome(131));
    printf("Testing 133: %d\n", isPalindrome(133));
    printf("Testing 1031: %d\n", isPalindrome(1031));
    printf("Testing 1331: %d\n", isPalindrome(1331));
    printf("Testing 13011: %d\n", isPalindrome(13011));
    printf("Testing 11131: %d\n", isPalindrome(11131));
    printf("Testing 10301: %d\n", isPalindrome(10301));

    printf("The largest palindrome product of %d-digit integers is: %d\n", n, largestPalindromeProduct(n));
    return 0;
}
