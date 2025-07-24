//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the bingo card
#define CARD_SIZE 5

// Define the number of balls in the game
#define BALL_COUNT 75

// Define the number of balls drawn per game
#define DRAW_COUNT 24

int main() {

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Declare the bingo card
    int card[CARD_SIZE][CARD_SIZE];

    // Declare the balls to be drawn
    int balls[DRAW_COUNT];

    // Initialize the card to all zeros
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            card[i][j] = 0;
        }
    }

    // Generate random numbers to fill the card
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {

            // Generate a random number
            int num = rand() % BALL_COUNT + 1;

            // Check that the number is not already on the card
            int duplicate = 0;
            for (int k = 0; k < j; k++) {
                if (num == card[i][k]) {
                    duplicate = 1;
                    break;
                }
            }

            // If the number is a duplicate, continue generating random numbers until a unique one is found
            while (duplicate) {
                num = rand() % BALL_COUNT + 1;
                duplicate = 0;
                for (int k = 0; k < j; k++) {
                    if (num == card[i][k]) {
                        duplicate = 1;
                        break;
                    }
                }
            }

            // Assign the unique number to the card
            card[i][j] = num;
        }
    }

    // Print out the card
    printf("BINGO CARD:\n");
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }

    // Draw balls until someone wins
    int winner = 0;
    for (int i = 0; i < DRAW_COUNT; i++) {

        // Draw a random ball
        int ball = rand() % BALL_COUNT + 1;

        // Check if the ball has already been drawn
        int duplicate = 0;
        for (int j = 0; j < i; j++) {
            if (ball == balls[j]) {
                duplicate = 1;
                break;
            }
        }

        // If the ball has already been drawn, continue drawing until a unique ball is found
        while (duplicate) {
            ball = rand() % BALL_COUNT + 1;
            duplicate = 0;
            for (int j = 0; j < i; j++) {
                if (ball == balls[j]) {
                    duplicate = 1;
                    break;
                }
            }
        }

        // Add the unique ball to the list of drawn balls
        balls[i] = ball;

        // Check if any rows, columns, or diagonals of the card have been completed
        for (int j = 0; j < CARD_SIZE; j++) {

            // Check rows
            int row_complete = 1;
            for (int k = 0; k < CARD_SIZE; k++) {
                if (card[j][k] != 0 && card[j][k] != ball) {
                    row_complete = 0;
                    break;
                }
            }
            if (row_complete) {
                printf("BINGO! Row %d\n", j + 1);
                winner = 1;
            }

            // Check columns
            int col_complete = 1;
            for (int k = 0; k < CARD_SIZE; k++) {
                if (card[k][j] != 0 && card[k][j] != ball) {
                    col_complete = 0;
                    break;
                }
            }
            if (col_complete) {
                printf("BINGO! Column %d\n", j + 1);
                winner = 1;
            }
        }

        // Check diagonal from top left to bottom right
        int diag1_complete = 1;
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card[j][j] != 0 && card[j][j] != ball) {
                diag1_complete = 0;
                break;
            }
        }
        if (diag1_complete) {
            printf("BINGO! Diagonal from top left to bottom right.\n");
            winner = 1;
        }

        // Check diagonal from top right to bottom left
        int diag2_complete = 1;
        for (int j = CARD_SIZE - 1; j >= 0; j--) {
            if (card[CARD_SIZE - j - 1][j] != 0 && card[CARD_SIZE - j - 1][j] != ball) {
                diag2_complete = 0;
                break;
            }
        }
        if (diag2_complete) {
            printf("BINGO! Diagonal from top right to bottom left.\n");
            winner = 1;
        }

        // If someone wins, break out of the loop
        if (winner) {
            break;
        }
    }

    // If nobody wins, print a message saying so
    if (!winner) {
        printf("No winner this game.\n");
    }

    return 0;
}