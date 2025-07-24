//FormAI DATASET v1.0 Category: Memory Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

// Initialize the board with random numbers
void initialize(int board[][SIZE], int numbers[])
{
    int i, j, k = 0;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = numbers[k];
            k++;
        }
    }
}

// Display the board to the user
void display_board(int board[][SIZE], int revealed[][SIZE])
{
    int i, j;

    printf("\n    ");

    for (i = 0; i < SIZE; i++) {
        printf("%d   ", i+1);
    }

    printf("\n  ");

    for (i = 0; i < SIZE; i++) {
        printf("----");
    }

    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d | ", i+1);

        for (j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d | ", board[i][j]);
            }
            else {
                printf("  | ");
            }
        }

        printf("\n  ");

        for (j = 0; j < SIZE; j++) {
            printf("----");
        }

        printf("\n");
    }
}

// Get the user's guess and update the revealed board
void guess(int board[][SIZE], int revealed[][SIZE])
{
    int row_guess, col_guess;
    int row_index, col_index;

    printf("\n");
    printf("Enter your guess (row column): ");
    scanf("%d %d", &row_guess, &col_guess);

    row_index = row_guess - 1;
    col_index = col_guess - 1;

    if (row_index < 0 || row_index >= SIZE || col_index < 0 || col_index >= SIZE) {
        printf("Invalid guess. Try again.\n");
        guess(board, revealed);
    }
    else if (revealed[row_index][col_index]) {
        printf("That square has already been revealed. Try again.\n");
        guess(board, revealed);
    }
    else {
        revealed[row_index][col_index] = 1;
    }
}

// Check if the game is over
int game_over(int revealed[][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (revealed[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int numbers[SIZE*SIZE/2];
    int board[SIZE][SIZE];
    int revealed[SIZE][SIZE] = {0};
    int i, j;

    // Initialize random number generator
    srand(time(NULL));

    // Initialize array of numbers to be used in the game
    for (i = 0; i < SIZE*SIZE/2; i++) {
        numbers[i] = i+1;
    }

    // Shuffle the numbers
    for (i = 0; i < SIZE*SIZE/2; i++) {
        int temp = numbers[i];
        int rand_index = rand() % (SIZE*SIZE/2);
        numbers[i] = numbers[rand_index];
        numbers[rand_index] = temp;
    }

    // Initialize the board with the shuffled numbers
    initialize(board, numbers);

    // Main game loop
    while (!game_over(revealed)) {
        display_board(board, revealed);
        guess(board, revealed);
    }

    // Display the final board
    display_board(board, revealed);
    printf("Congratulations, you win!\n");

    return 0;
}