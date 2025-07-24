//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to generate random number between 1 and 6 */
int roll_dice() {
    int random_num = rand() % 6 + 1;
    return random_num;
}

/* function to display the dice in a retro-style */
void display_dice(int num) {
    switch(num) {
        case 1: printf("+-------+\n|       |\n|   *   |\n|       |\n+-------+\n"); break;
        case 2: printf("+-------+\n| *     |\n|       |\n|     * |\n+-------+\n"); break;
        case 3: printf("+-------+\n| *     |\n|   *   |\n|     * |\n+-------+\n"); break;
        case 4: printf("+-------+\n| *   * |\n|       |\n| *   * |\n+-------+\n"); break;
        case 5: printf("+-------+\n| *   * |\n|   *   |\n| *   * |\n+-------+\n"); break;
        case 6: printf("+-------+\n| *   * |\n| *   * |\n| *   * |\n+-------+\n"); break;
        default: printf("Error: Invalid number!\n"); break;
    }
}

int main() {
    srand(time(NULL)); // initialize random seed

    int num_dice, num_rolls;
    printf("Retro Dice Roller!\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    printf("How many times do you want to roll each dice? ");
    scanf("%d", &num_rolls);

    printf("\nRolling %d dice %d times...\n\n", num_dice, num_rolls);

    for(int i = 0; i < num_dice; i++) {
        int sum = 0;
        for(int j = 0; j < num_rolls; j++) {
            int roll = roll_dice();
            display_dice(roll);
            sum += roll;
        }
        printf("Sum of dice %d: %d\n\n", i+1, sum);
    }

    return 0;
}