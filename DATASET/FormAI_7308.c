//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));   // to generate a random seed
    int count = 1;    // to count the number of turns
    int table[10];    // array to store the table values
    for (int i = 0; i < 10; i++) {
        table[i] = rand() % 10 + 1;   // setting the values randomly
    }
    printf("Welcome to the Happy Table Game!\n");
    printf("The table is set with the following values:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
    int choice = -1;    // variable to store player's choice
    int score = 0;      // variable to store player's score
    while (count <= 5) {   // game runs for 5 turns
        printf("\nTurn %d: Choose a value from the table to add to your score: ", count);
        scanf("%d", &choice);
        if (choice < 1 || choice > 10) {   // validating player's input
            printf("Invalid choice! Choose a value from 1 to 10.\n");
            continue;   // continue with the loop again
        }
        for (int i = 0; i < 10; i++) {
            if (table[i] == choice) {
                score += choice;   // adding the choice to the score
                break;             // exit the loop after finding the value
            }
        }
        printf("Your score: %d\n", score);
        count++;    // incrementing the turn count
    }
    if (score >= 25) {
        printf("\nCongratulations! You won the Happy Table Game with a score of %d! :)\n", score);
    } else {
        printf("\nSorry, You lost! Try again to win! :(\n");
    }
    return 0;
}