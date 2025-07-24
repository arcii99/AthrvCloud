//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generateRandomNumber(int limit) {
    srand(time(NULL));
    return rand() % limit;
}

// Function to print the game grid
void printGrid(int grid[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", grid[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to check if game is over
int isGameOver(int grid[], int size) {
    for (int i = 0; i < size; i++) {
        if (grid[i] == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to get user input and update the grid
void getUserInput(int grid[], int size) {
    int position;
    do {
        printf("\nEnter a position (1 to 9): ");
        scanf("%d", &position);
        if (position < 1 || position > 9) {
            printf("Invalid position. Please enter a number between 1 and 9.\n");
        } else if (grid[position - 1] != 0) {
            printf("Position already taken. Please choose a different one.\n");
        } else {
            grid[position - 1] = 1;
            break;
        }
    } while (1);
}

// Function to get computer input and update the grid
void getComputerInput(int grid[], int size) {
    int position;
    do {
        position = generateRandomNumber(size);
        if (grid[position] == 0) {
            grid[position] = 2;
            break;
        }
    } while (1);
}

// Function to check if there is a winner
int checkWinner(int grid[], int size) {
    // Check rows
    for (int i = 0; i < size; i += 3) {
        if (grid[i] == grid[i + 1] && grid[i + 1] == grid[i + 2]) {
            return grid[i];
        }
    }
    // Check columns
    for (int i = 0; i < size / 3; i++) {
        if (grid[i] == grid[i + 3] && grid[i + 3] == grid[i + 6]) {
            return grid[i];
        }
    }
    // Check diagonals
    if (grid[0] == grid[4] && grid[4] == grid[8]) {
        return grid[0];
    }
    if (grid[2] == grid[4] && grid[4] == grid[6]) {
        return grid[2];
    }
    return 0;
}

int main() {
    int grid[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int winner = 0;
    int playerTurn = 1;
    int playAgain = 1;
    
    printf("Welcome to the Terminal Based Game: Tic Tac Toe\n");

    do {
        // Reset game variables
        for (int i = 0; i < 9; i++) {
            grid[i] = 0;
        }
        winner = 0;
        playerTurn = 1;

        printf("\nLet's start the game!\n");
        printGrid(grid, 9);

        while (!isGameOver(grid, 9) && winner == 0) {
            printf("\nPlayer %d's turn.\n", playerTurn);
            if (playerTurn == 1) {
                getUserInput(grid, 9);
            } else {
                getComputerInput(grid, 9);
            }
            printGrid(grid, 9);
            winner = checkWinner(grid, 9);
            playerTurn = (playerTurn == 1) ? 2 : 1;
        }
        if (winner == 1) {
            printf("\nCongratulations! Player 1 has won the game!\n");
        } else if (winner == 2) {
            printf("\nCongratulations! Player 2 (computer) has won the game!\n");
        } else {
            printf("\nIt's a tie!\n");
        }
        printf("\nDo you want to play again? Enter 1 for Yes or 0 for No: ");
        scanf("%d", &playAgain);
    } while (playAgain == 1);

    printf("\nThank you for playing!\n");
    return 0;
}