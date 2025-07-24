//FormAI DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 12
#define NO_PLAYER 0
#define PLAYER_1 1
#define PLAYER_2 2

/* function to initialize the board */
void initializeBoard(int board[][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = NO_PLAYER;
        }
    }
}

/* function to print the current state of the board */
void printBoard(int board[][BOARD_SIZE]) {
    printf("\t");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d\t", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

/* function to check if a move is valid */
bool isValidMove(int board[][BOARD_SIZE], int row, int col) {
    if(row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == NO_PLAYER) {
        return true;
    }
    return false;
}

/* function to check if the game has been won */
bool hasGameBeenWon(int board[][BOARD_SIZE], int player) {
    int count;
    // check horizontal
    for(int i = 0; i < BOARD_SIZE; i++) {
        count = 0;
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == player) {
                count++;
                if(count >= 5) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
    }
    // check vertical
    for(int i = 0; i < BOARD_SIZE; i++) {
        count = 0;
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[j][i] == player) {
                count++;
                if(count >= 5) {
                    return true;
                }
            }
            else {
                count = 0;
            }
        }
    }
    // check diagonal (top-left to bottom-right)
    for(int i = 0; i < BOARD_SIZE - 4; i++) {
        for(int j = 0; j < BOARD_SIZE - 4; j++) {
            count = 0;
            for(int k = 0; k < 5; k++) {
                if(board[i+k][j+k] == player) {
                    count++;
                    if(count >= 5) {
                        return true;
                    }
                }
                else {
                    count = 0;
                }
            }
        }
    }
    // check diagonal (top-right to bottom-left)
    for(int i = 0; i < BOARD_SIZE - 4; i++) {
        for(int j = 4; j < BOARD_SIZE; j++) {
            count = 0;
            for(int k = 0; k < 5; k++) {
                if(board[i+k][j-k] == player) {
                    count++;
                    if(count >= 5) {
                        return true;
                    }
                }
                else {
                    count = 0;
                }
            }
        }
    }
    // game not won
    return false;
}

/* function for player input */
void playerInput(int *row, int *col) {
    printf("Enter row and column: ");
    scanf("%d %d", row, col);
}

/* function to play the game */
void playGame() {
    int board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    int currentPlayer = PLAYER_1;
    int row, col;
    printBoard(board);
    while(true) {
        playerInput(&row, &col);
        if(isValidMove(board, row, col)) {
            board[row][col] = currentPlayer;
            printBoard(board);
            if(hasGameBeenWon(board, currentPlayer)) {
                printf("Player %d has won the game!\n", currentPlayer);
                break;
            }
            if(currentPlayer == PLAYER_1) {
                currentPlayer = PLAYER_2;
            }
            else {
                currentPlayer = PLAYER_1;                    
            }
        }
        else {
            printf("Invalid move!\n");
        }
    }
}

int main() {
    playGame();
    return 0;
}