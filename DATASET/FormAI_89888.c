//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

/* This program calculates the factorial of a number and checks if it is even or odd.
   It also prompts the user to enter a new number or exit the program. */

int main() {
    int n, fact = 1;
    char choice;

    do {
        printf("Enter a number: ");
        scanf("%d", &n);

        if (n < 0) {
            printf("Factorial of negative numbers is not defined.\n");
        } else {
            for (int i = 1; i <= n; i++) {
                fact *= i;
            }
            printf("The factorial of %d is %d. ", n, fact);

            if (fact % 2 == 0) {
                printf("It is even.\n");
            } else {
                printf("It is odd.\n");
            }
        }

        printf("Enter 'y' to enter a new number or any other key to exit: ");
        scanf(" %c", &choice);
        fact = 1; // reset the factorial value for the next input
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the program!\n");
    return 0;
}