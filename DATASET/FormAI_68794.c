//FormAI DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This is a brave style C program that simulates a dice roller.
 *
 * The program generates a random number between 1 and 6 and displays
 * the corresponding face of a die. The program repeatedly prompts the user
 * if they want to roll the dice again until they choose to quit.
 *
 * Minimum 50 lines.
 */

int main() {
    int roll;
    char input;

    srand(time(NULL));

    printf("Welcome to the Brave Dice Roller Program!\n\n");

    do {
        printf("Press enter to roll the dice...");
        getchar();

        roll = rand() % 6 + 1;

        switch (roll) {
            case 1:
                printf(" _______\n");
                printf("|       |\n");
                printf("|   •   |\n");
                printf("|_______|\n");
                break;
            case 2:
                printf(" _______\n");
                printf("|       |\n");
                printf("| •   • |\n");
                printf("|_______|\n");
                break;
            case 3:
                printf(" _______\n");
                printf("|   •   |\n");
                printf("|   •   |\n");
                printf("|___•___|\n");
                break;
            case 4:
                printf(" _______\n");
                printf("| •   • |\n");
                printf("|       |\n");
                printf("|_•___•_|\n");
                break;
            case 5:
                printf(" _______\n");
                printf("| •   • |\n");
                printf("|   •   |\n");
                printf("|_•___•_|\n");
                break;
            case 6:
                printf(" _______\n");
                printf("| •   • |\n");
                printf("| •   • |\n");
                printf("|_•___•_|\n");
                break;
        }

        printf("\nDo you want to roll again? (y/n): ");
        input = getchar();

        while (getchar() != '\n'); // clear input buffer

    } while (input == 'y');

    printf("\nThanks for rolling with us!\n");

    return 0;
}