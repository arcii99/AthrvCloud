//FormAI DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i, roll;
    char choice;

    printf("=== WELCOME TO THE PUZZLING DICE ROLLER ===\n\n");
    
    do {

        printf("How many dice should I roll? (1-5): ");
        scanf(" %d", &roll);

        if (roll < 1 || roll > 5) {
            printf("I'm sorry, that is an invalid number of dice.\n");
        }
        else {
            printf("\nRolling the dice %d times...\n\n", roll);

            srand(time(NULL));

            for (i = 1; i <= roll; i++) {
                printf("Die %d: %d\n", i, rand() % 6 + 1);
            }

            printf("\nWould you like to roll again? (y/n): ");
            scanf(" %c", &choice);

            if (choice == 'n') {
                printf("\nThank you for using the puzzling dice roller!");
            }
        }

    } while (choice != 'n');

    return 0;
}