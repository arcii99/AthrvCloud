//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up the game board
    int board[5][5] = {0};
    int selected[25] = {0};
    int current = 0;

    // Set up random number generator
    srand(time(NULL));

    // Fill the game board with random numbers
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            // Make sure the center square is free
            if(i == 2 && j == 2) {
                continue;
            }
            int num;
            do {
                num = rand() % 15 + (15 * j) + 1;
            } while(numExists(selected, current, num));
            board[i][j] = num;
            selected[current++] = num;
        }
    }

    // Set the center square as free
    board[2][2] = -1;

    // Display the game board
    printf("Welcome to Bingo!\n\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }

    // Play the game
    int numbersCalled[75] = {0};
    int numCalled = 0;
    int gameOver = 0;
    while(!gameOver) {
        int num;
        do {
            num = rand() % 75 + 1;
        } while(numExists(numbersCalled, numCalled, num));
        printf("The next number is: %d\n", num);
        numbersCalled[numCalled++] = num;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(board[i][j] == num) {
                    board[i][j] = -1;
                }
            }
        }
        gameOver = checkGameOver(board);
    }

    // Display the winner
    printf("\nBingo! Congratulations on your win!\n");

    return 0;
}

// Helper function to check if a number already exists in an array
int numExists(int arr[], int size, int num) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

// Helper function to check if the game is over
int checkGameOver(int board[][5]) {
    // Check rows
    for(int i = 0; i < 5; i++) {
        if(board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1 && board[i][4] == -1) {
            return 1;
        }
    }
    // Check columns
    for(int j = 0; j < 5; j++) {
        if(board[0][j] == -1 && board[1][j] == -1 && board[2][j] == -1 && board[3][j] == -1 && board[4][j] == -1) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
        return 1;
    }
    if(board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
        return 1;
    }
    // Game is not over
    return 0;
}