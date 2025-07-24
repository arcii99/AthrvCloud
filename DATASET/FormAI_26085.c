//FormAI DATASET v1.0 Category: Checkers Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8 //define board size as 8

int board[BOARD_SIZE][BOARD_SIZE]; //Creation of game board

void initializeBoard(); //initialize the game board
void printBoard(); //Display the game board
int isMoveValid(int player, int currentRow, int currentCol, int newRow, int newCol); //validate the move
void makeMove(int player, int currentRow, int currentCol, int newRow, int newCol); //move the player
int isGameOver(); //detect if the game is over

int main() {
    int currentPlayer = 1; //player1 starts the game
    int gameover = 0; //Initially game is not over
    int currentRow = -1, currentCol = -1, newRow = -1, newCol = -1; //initialize current and new positions
    initializeBoard(); //initialize the game board
    while (!gameover) { //while the game is not over
        printBoard(); //Display the game board
        printf("Player %d's turn:\n", currentPlayer);
        printf("Enter the current position of the piece you want to move (row col): ");
        scanf("%d %d", &currentRow, &currentCol); //input current row and current col
        printf("Enter the new position of the piece (row col): ");
        scanf("%d %d", &newRow, &newCol); //input current row and current col
        if (isMoveValid(currentPlayer, currentRow, currentCol, newRow, newCol)) { //if move is valid
            makeMove(currentPlayer, currentRow, currentCol, newRow, newCol); //make the move
            gameover = isGameOver(); //check if the game is over
            if (gameover) { //if game is over
                printf("Player %d wins the game\n", currentPlayer); //print the winner
                printBoard(); //Display the final game board
            } else { //if game is not over
                if (currentPlayer == 1) { //if it is player1's turn
                    currentPlayer = 2; //switch to player2
                } else { //if it is player2's turn
                    currentPlayer = 1; //switch to player1
                }
            }
        } else { //if move is invalid
            printf("Invalid move! Try again\n");
            continue; //prompt again
        }
    }
    return 0;
}

void initializeBoard() {
    int i, j;
    for (i = 0; i < BOARD_SIZE/2 - 1; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 1) {
                    board[i][j] = 1; //player1's piece
                } else {
                    board[i][j] = 0; //blank space
                }
            } else {
                if (j % 2 == 0) {
                    board[i][j] = 1; //player1's piece
                } else {
                    board[i][j] = 0; //blank space
                }
            }
        }
    }
    for (i = BOARD_SIZE/2 + 1; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 1) {
                    board[i][j] = 2; //player2's piece
                } else {
                    board[i][j] = 0; //blank space
                }
            } else {
                if (j % 2 == 0) {
                    board[i][j] = 2; //player2's piece
                } else {
                    board[i][j] = 0; //blank space
                }
            }
        }
    }
}

void printBoard() {
    int i, j;
    printf("  | 0 1 2 3 4 5 6 7 |\n"); //column numbers
    printf("--+-----------------+\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", i); //row number
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf(". "); //blank space
            } else if (board[i][j] == 1) {
                printf("X "); //player1's piece
            } else if (board[i][j] == 2) {
                printf("O "); //player2's piece
            }
        }
        printf("|\n");
    }
    printf("--+-----------------+\n");
}

int isMoveValid(int player, int currentRow, int currentCol, int newRow, int newCol) {
    if (newRow < 0 || newRow >= BOARD_SIZE || newCol < 0 || newCol >= BOARD_SIZE) { //if move is outside the board
        return 0; //invalid move
    }
    if (board[newRow][newCol] != 0) { //if the new position is already occupied
        return 0; //invalid move
    }
    if (player == 1) { //if it is player1's turn
        if (board[currentRow][currentCol] != 1) { //if the current position does not have player1's piece
            return 0; //invalid move
        }
        if (newRow > currentRow) { //if player1 moves in the wrong direction
            return 0; //invalid move
        }
        if (currentRow - newRow > 2 || abs(currentCol - newCol) > 2) { //if player1 trying to jump over multiple squares
            return 0; //invalid move
        }
        if (abs(currentRow - newRow) == 1 && abs(currentCol - newCol) == 1) { //if player1 moves to an adjacent square
            return 1; //valid move
        } else { //if player1 trying to jump over a single square
            if (board[(currentRow+newRow)/2][(currentCol+newCol)/2] != 2) { //if there is no player2's piece to jump over
                return 0; //invalid move
            } else {
                board[(currentRow+newRow)/2][(currentCol+newCol)/2] = 0; //remove jumped over piece
                return 1; //valid move
            }
        }
    } else { //if it is player2's turn
        if (board[currentRow][currentCol] != 2) { //if the current position does not have player2's piece
            return 0; //invalid move
        }
        if (newRow < currentRow) { //if player2 moves in the wrong direction
            return 0; //invalid move
        }
        if (currentRow - newRow > 2 || abs(currentCol - newCol) > 2) { //if player2 trying to jump over multiple squares
            return 0; //invalid move
        }
        if (abs(currentRow - newRow) == 1 && abs(currentCol - newCol) == 1) { //if player2 moves to an adjacent square
            return 1; //valid move
        } else { //if player2 trying to jump over a single square
            if (board[(currentRow+newRow)/2][(currentCol+newCol)/2] != 1) { //if there is no player1's piece to jump over
                return 0; //invalid move
            } else {
                board[(currentRow+newRow)/2][(currentCol+newCol)/2] = 0; //remove jumped over piece
                return 1; //valid move
            }
        }
    }
}

void makeMove(int player, int currentRow, int currentCol, int newRow, int newCol) {
    board[newRow][newCol] = board[currentRow][currentCol]; //move player's piece to the new position
    board[currentRow][currentCol] = 0; //reset the current position
}

int isGameOver() {
    int i, j, player1Pieces = 0, player2Pieces = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1) { //if player1's piece is found on the board
                player1Pieces++; //increment player1's pieces count
            }
            if (board[i][j] == 2) { //if player2's piece is found on the board
                player2Pieces++; //increment player2's pieces count
            }
        }
    }
    if (player1Pieces == 0 || player2Pieces == 0) { //if either player has no pieces on the board
        return 1; //game is over
    } else {
        return 0; //game continues
    }
}