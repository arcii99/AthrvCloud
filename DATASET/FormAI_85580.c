//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
/*A C program to calculate the factorial of a given number*/

#include <stdio.h>

int main() {
    int num, i;
    long long fact = 1;

    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // error if the input number is negative
    if (num < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else {
        for (i = 1; i <= num; ++i) {
            fact *= i;
        }
        printf("Factorial of %d = %lld", num, fact);
    }

    return 0;
}