//FormAI DATASET v1.0 Category: Educational ; Style: peaceful
/* This program calculates the sum of odd numbers up to a user-specified limit, using a for loop */

#include <stdio.h>

int main() {
    int i, limit, sum = 0;
    
    printf("Enter the maximum limit: ");
    scanf("%d", &limit);
    
    printf("The odd numbers up to %d are:\n", limit);
    
    for (i = 1; i <= limit; i += 2) {
        printf("%d ", i);
        sum += i;
    }
    
    printf("\n\nThe sum of the odd numbers up to %d is %d", limit, sum);

    return 0;
}