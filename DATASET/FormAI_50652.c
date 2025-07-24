//FormAI DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, roll;
    char choice;

    do {
        srand(time(NULL)); // Seed the random number generator

        printf("Enter the number of dice you want to roll: ");
        scanf("%d", &n);

        printf("Rolling %d dice...\n\n", n);

        // Roll the dice n times
        for(i = 1; i <= n; i++) {
            roll = rand() % 6 + 1; // Generate a random number between 1 and 6
            printf("Die %d: %d\n", i, roll);
        }

        printf("\nRoll again? (Y/N) ");
        scanf(" %c", &choice); // Use a space before %c to ignore leading whitespace
    } while(choice == 'y' || choice == 'Y');

    return 0;
}