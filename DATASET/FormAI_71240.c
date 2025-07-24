//FormAI DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>
// A program to find the factorial of a number

int main() {
    int num, i;
    long long fact = 1;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Error: Factorial of negative number does not exist.");
    }
    else {
        for(i = 1; i <= num; ++i) {
            fact *= i;
        }
        printf("Factorial of %d = %lld", num, fact);
    }

    return 0;
}