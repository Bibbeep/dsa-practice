/*
 * https://leetcode.com/problems/palindrome-number/
 *
 * 9. Palindrome Number
 *
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 */
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

// O(n)
unsigned long power(unsigned long base, unsigned long exp) {
    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return base;
    }

    unsigned long result = base;
    for (size_t i = 0; i < exp - 1; i++) {
        result *= base;
    }

    return result;
}

// By converting to string
bool isPalindrome(int x) {
    // Negative integers cannot be a palindrome
    if (x < 0) {
        return false;
    }

    // Calculate how many digits by checking the biggest power of 10 it can be
    // divided to before resulting in 0
    long divider = 10, digit_count = 1;
    while (x / divider != 0) {
        digit_count++;
        divider *= 10;
    }

    // A single digit integer is always a palindrome
    if (digit_count == 1) {
        return true;
    }

    size_t len = digit_count + 1;
    char str[len];
    size_t idx = 0;

    // Convert the number digit by digit from the left to a string
    while (digit_count - 1 >= 0) {
        // Get the single digit integer representation of the leftmost digit
        int digit_val = x / power(10, digit_count - 1);
        // Assign the ASCII representation to the string
        str[idx] = digit_val + 48;
        // Truncate the leftmost digit for the next iteration
        x = x % power(10, digit_count - 1);

        digit_count--;
        idx++;
    }

    str[len - 1] = '\0';

    // Check whether it is a palindrome by using two-pointers method
    for (size_t i = 0; i < (len - 1) / 2; i++) {
        // printf("%zu: str[i] = %c\tstr[(len - 2) - i] = %c\n", i, str[i], str[(len - 2) - i]);
        if (str[i] != str[(len - 2) - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int x;
    scanf("%d", &x);

    int result = isPalindrome(x);

    if (result == 1) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
