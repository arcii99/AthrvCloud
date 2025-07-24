//FormAI DATASET v1.0 Category: Educational ; Style: inquisitive
#include <stdio.h>

/* Inquisitive C program to calculate the factorial of a number */

int main() {
    int num;
    printf("Welcome to the factorial calculator! Please enter a positive integer:\n");
    scanf("%d", &num);
    
    /* Check if the number is valid */
    if (num < 0) {
        printf("Hmm, that's not a positive integer. Let's try again.\n");
        main();
    }
    else {
        int factorial = 1;
        int i;
        
        /* Calculate the factorial */
        for (i = 1; i <= num; i++) {
            factorial *= i;
        }
        
        /* Display the result */
        printf("The factorial of %d is %d.\n", num, factorial);
        
        /* Ask if the user wants to calculate another factorial */
        printf("Would you like to calculate another factorial? (Y/N)\n");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'Y' || answer == 'y') {
            printf("Okay, let's go!\n");
            main();
        }
        else {
            printf("Alright, see you later!\n");
            return 0;
        }
    }
    return 0;
}