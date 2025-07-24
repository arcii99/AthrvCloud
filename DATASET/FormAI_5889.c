//FormAI DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>

// recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) { // base case
        return 1;
    } else { // recursive case
        return n * factorial(n-1);
    }
}

// recursive function to print the Fibonacci sequence
void printFibonacci(int n, int curr, int next) {
    if (n == 0) { // base case
        return;
    } else { // recursive case
        printf("%d ", curr);
        printFibonacci(n-1, next, curr+next);
    }
}

// recursive function to check if a string is a palindrome
int isPalindrome(char* str, int start, int end) {
    if (start >= end) { // base case
        return 1;
    } else if (str[start] != str[end]) { // base case
        return 0;
    } else { // recursive case
        return isPalindrome(str, start+1, end-1);
    }
}

int main() {
    // example usage of the factorial function
    int num = 5;
    printf("The factorial of %d is %d\n", num, factorial(num));
    
    // example usage of the Fibonacci function
    printf("The first 10 numbers of the Fibonacci sequence are: ");
    printFibonacci(10, 0, 1);
    printf("\n");
    
    // example usage of the isPalindrome function
    char* str = "racecar";
    if (isPalindrome(str, 0, strlen(str)-1)) {
        printf("%s is a palindrome!\n", str);
    } else {
        printf("%s is not a palindrome...\n", str);
    }
    
    return 0;
}