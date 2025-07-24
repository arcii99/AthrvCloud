//FormAI DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 6
int dice_roll() {
    return rand() % 6 + 1;
}

// Function to print dice image
void print_dice(int dice_num) {
    switch(dice_num) {
        case 1:
            printf("+-------+\n|       |\n|   *   |\n|       |\n+-------+\n");
            break;
        case 2:
            printf("+-------+\n| *     |\n|       |\n|     * |\n+-------+\n");
            break;
        case 3:
            printf("+-------+\n| *     |\n|   *   |\n|     * |\n+-------+\n");
            break;
        case 4:
            printf("+-------+\n| *   * |\n|       |\n| *   * |\n+-------+\n");
            break;
        case 5:
            printf("+-------+\n| *   * |\n|   *   |\n| *   * |\n+-------+\n");
            break;
        case 6:
            printf("+-------+\n| *   * |\n| *   * |\n| *   * |\n+-------+\n");
            break;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the dice roller! Press enter to roll the dice.\n\n");

    // Keep rolling until user chooses to exit
    while(1) {
        getchar(); // Wait till user hits enter
        int roll_result = dice_roll();
        printf("You rolled a %d!\n", roll_result);
        print_dice(roll_result);
        printf("\nPress q to quit or any other key to roll again.\n");

        char quit_choice = getchar();
        if(quit_choice == 'q' || quit_choice == 'Q') {
            break;
        }
    }

    return 0;
}