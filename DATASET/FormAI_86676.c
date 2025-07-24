//FormAI DATASET v1.0 Category: Scientific ; Style: curious
#include <stdio.h>

// Let's create a program that calculates the fibonacci sequence up to a certain limit

int main() {
    int limit, num1 = 0, num2 = 1, nextNum = 0;

    // Let's ask the user for the limit he wants to calculate
    printf("Enter the limit for the fibonacci sequence: ");
    scanf("%d", &limit);

    // Let's print the first two numbers of the sequence
    printf("The fibonacci sequence up to %d is:\n%d, %d, ", limit, num1, num2);

    // Let's calculate the next numbers of the sequence and print them
    while (nextNum <= limit) {
        nextNum = num1 + num2;
        num1 = num2;
        num2 = nextNum;
        if (nextNum <= limit) {
            printf("%d, ", nextNum);
        }
    }

    // Let's print the end of the sequence
    printf("\nEnd of the fibonacci sequence.");
    
    return 0;
}