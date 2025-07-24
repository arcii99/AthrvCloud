//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int roll_dice() {
    int num = (rand() % 6) + 1;
    return num;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int player1_score = 0;
    int player2_score = 0;
    int target_score = 50;

    printf("Welcome to the Dice Table Game!\n\n");
    printf("The target score is %d. Let's begin!\n", target_score);

    while (player1_score < target_score && player2_score < target_score) {
        // Player 1's turn
        printf("\nPlayer 1's turn:\n");
        int roll1 = roll_dice();
        int roll2 = roll_dice();
        printf("You rolled %d and %d\n", roll1, roll2);
        int sum = roll1 + roll2;
        printf("Sum: %d\n", sum);

        // Check for possible point-scoring combinations
        if (sum == 7 || sum == 11) {
            player1_score += 10;
            printf("You scored 10 points!\n");
        } 
        else if (roll1 == roll2) {
            player1_score += 5;
            printf("You rolled doubles and scored 5 points!\n");
        } 
        else {
            printf("Sorry, no points scored this turn.\n");
        }
        printf("Player 1's score: %d\n", player1_score);

        // Player 2's turn
        printf("\nPlayer 2's turn:\n");
        roll1 = roll_dice();
        roll2 = roll_dice();
        printf("You rolled %d and %d\n", roll1, roll2);
        sum = roll1 + roll2;
        printf("Sum: %d\n", sum);

        // Check for possible point-scoring combinations
        if (sum == 7 || sum == 11) {
            player2_score += 10;
            printf("You scored 10 points!\n");
        } 
        else if (roll1 == roll2) {
            player2_score += 5;
            printf("You rolled doubles and scored 5 points!\n");
        } 
        else {
            printf("Sorry, no points scored this turn.\n");
        }
        printf("Player 2's score: %d\n", player2_score);
    }

    if (player1_score >= target_score) {
        printf("\nCongratulations Player 1, you win!\n");
    }
    else {
        printf("\nCongratulations Player 2, you win!\n");
    }

    return 0;
}