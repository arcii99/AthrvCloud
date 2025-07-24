//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to Linux C programming!\n");
    printf("Here's a program to compute the factorial of a number.\n");
    printf("Enter a positive integer: ");

    int num;
    
    scanf("%d", &num);

    if(num < 0) {
        printf("Error: Input must be a positive integer.\n");
        return 0;
    } else if(num == 0) {
        printf("The factorial of 0 is 1.\n");
        return 0;
    } else {
        int result = 1;
        int i;
        for(i = 1; i <= num; i++) {
            result *= i;
        }
        printf("The factorial of %d is %d.\n", num, result);
        return 0;
    }
}