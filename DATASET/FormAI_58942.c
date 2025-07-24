//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to display the board
void displayBoard(int board[4][4])
{
    printf("\n");
    printf("-------------------------------\n");
    for (int row = 0; row < 4; row++) {
        printf("|");
        for (int col = 0; col < 4; col++) {
            printf(" %-4d |", board[row][col]);
        }
        printf("\n");
        printf("-------------------------------\n");
    }
}

// Function to update the board with random values
void updateBoard(int board[4][4], int player)
{
    srand(time(NULL));

    // Generate random coordinates
    int row = rand() % 4;
    int col = rand() % 4;

    // Check if the cell is empty
    while (board[row][col] != 0) {
        row = rand() % 4;
        col = rand() % 4;
    }

    // Assign value 1 or 2 based on the player
    if (player == 1) {
        board[row][col] = 1;
    }
    else {
        board[row][col] = 2;
    }
}

// Function to check if there are no empty cells left on the board
bool isBoardFull(int board[4][4])
{
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (board[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the game is over
bool isGameOver(int board[4][4])
{
    // Check for horizontal lines
    for (int row = 0; row < 4; row++) {
        if (board[row][0] != 0 && board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][2] == board[row][3]) {
            return true;
        }
    }

    // Check for vertical lines
    for (int col = 0; col < 4; col++) {
        if (board[0][col] != 0 && board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[2][col] == board[3][col]) {
            return true;
        }
    }

    // Check for diagonal lines
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
        return true;
    }
    if (board[0][3] != 0 && board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
        return true;
    }

    // Check if the board is full
    if (isBoardFull(board)) {
        return true;
    }

    return false;
}

int main()
{
    // Initialize the board with all zeroes
    int board[4][4] = {{0}};

    // Display the empty board
    displayBoard(board);

    // Initialize the players
    int currentPlayer = 1;
    int otherPlayer = 2;

    // Loop until the game is over
    while (!isGameOver(board)) {
        // Update the board with a value for the current player
        updateBoard(board, currentPlayer);

        // Display the updated board
        displayBoard(board);

        // Swap the players
        int tempPlayer = currentPlayer;
        currentPlayer = otherPlayer;
        otherPlayer = tempPlayer;
    }

    // Print the result
    printf("\nGAME OVER!\n");
    if (isBoardFull(board)) {
        printf("The board is full!\n");
    }
    else {
        printf("Player %d has won the game!\n", otherPlayer);
    }

    return 0;
}