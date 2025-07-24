//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the game board with random values
void initialize(int board[][10])
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the game board
void display(int board[][10])
{
    printf("\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to calculate the next generation of the game board
void nextGeneration(int board[][10])
{
    int nextBoard[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int count = 0;

            // Counting the live cells in the 8 surrounding neighbors
            if (i > 0 && j > 0 && board[i-1][j-1] == 1) {
                count++;
            }
            if (i > 0 && board[i-1][j] == 1) {
                count++;
            }
            if (i > 0 && j < 9 && board[i-1][j+1] == 1) {
                count++;
            }
            if (j > 0 && board[i][j-1] == 1) {
                count++;
            }
            if (j < 9 && board[i][j+1] == 1) {
                count++;
            }
            if (i < 9 && j > 0 && board[i+1][j-1] == 1) {
                count++;
            }
            if (i < 9 && board[i+1][j] == 1) {
                count++;
            }
            if (i < 9 && j < 9 && board[i+1][j+1] == 1) {
                count++;
            }

            // Applying the rules of the game
            if (board[i][j] == 1 && (count < 2 || count > 3)) {
                nextBoard[i][j] = 0;
            }
            else if (board[i][j] == 0 && count == 3) {
                nextBoard[i][j] = 1;
            }
            else {
                nextBoard[i][j] = board[i][j];
            }
        }
    }

    // Copying the next generation board to the current board
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = nextBoard[i][j];
        }
    }
}

int main()
{
    int board[10][10];

    // Initializing the game board
    initialize(board);

    // Game loop
    int generation = 1;
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        printf("Generation %d\n", generation);
        display(board);
        nextGeneration(board);
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &choice);
        generation++;
    }

    return 0;
}