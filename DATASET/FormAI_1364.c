//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Retro Style Dice Roller Example Program
 */

void rollDice(char s[]);
int getSum(int dice[]);
void printDice(int dice[]);

int main(void) {
    int dice1[6] = {1, 2, 3, 4, 5, 6};
    int dice2[6] = {1, 2, 3, 4, 5, 6};
    char input[40];
    srand(time(0));

    printf("Welcome to the Retro Dice Roller!\n");
    printf("Enter 'roll' to roll the dice or 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // replace newline character with null terminator

        if (strcmp(input, "exit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        else if (strcmp(input, "roll") == 0) {
            rollDice("Player 1");
            rollDice("Player 2");
        }
        else {
            printf("Invalid command, try again.\n");
        }
    }

    return 0;
}

void rollDice(char s[]) {
    int dice1[6] = {1, 2, 3, 4, 5, 6};
    int dice2[6] = {1, 2, 3, 4, 5, 6};
    int sum1, sum2;

    printf("%s rolls the dice:\n", s);

    // shuffle the dice arrays
    for (int i = 0; i < 6; i++) {
        int j = rand() % 6;
        int temp = dice1[i];
        dice1[i] = dice1[j];
        dice1[j] = temp;

        j = rand() % 6;
        temp = dice2[i];
        dice2[i] = dice2[j];
        dice2[j] = temp;
    }

    // print the dice
    printf("Dice 1: ");
    printDice(dice1);
    printf("\n");

    printf("Dice 2: ");
    printDice(dice2);
    printf("\n");

    // calculate the sum of the dice
    sum1 = getSum(dice1);
    sum2 = getSum(dice2);

    // print the sum
    printf("%s's total: %d\n", s, sum1 + sum2);
}

int getSum(int dice[]) {
    int sum = 0;

    for (int i = 0; i < 6; i++) {
        sum += dice[i];
    }

    return sum;
}

void printDice(int dice[]) {
    for (int i = 0; i < 6; i++) {
        printf("%d ", dice[i]);
    }
}