//FormAI DATASET v1.0 Category: Scientific ; Style: calm
#include <stdio.h>
#include <stdlib.h>

/* This program calculates the factorial of a number */

int main() {
    int num, i;
    long long fact = 1; // using long long to accommodate larger numbers
    
    printf("Please enter a number: ");
    scanf("%d", &num);
    
    /*Error handling for negative numbers*/
    if (num < 0) {
        printf("Error: Please enter a non-negative number.\n");
        exit(0);
    }
    
    /*If the number is 0 or 1, its factorial will be 1*/
    else if (num == 0 || num == 1) {
        printf("The factorial of %d is 1.\n", num);
        exit(0);
    }
    
    /* If the number is greater than 1 */
    else {
        for (i = 2; i <= num; i++) {
            fact *= i;
        }
        printf("The factorial of %d is %lld.\n", num, fact);
    }
    
    return 0;
}