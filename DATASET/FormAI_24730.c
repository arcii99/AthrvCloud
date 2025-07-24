//FormAI DATASET v1.0 Category: Checkers Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Constants
#define BOARD_SIZE 8

// Function prototypes
void initializeBoard(char[][BOARD_SIZE]);
void printBoard(char[][BOARD_SIZE]);
int movePiece(char[][BOARD_SIZE], int, int, int, int);
int isValidMove(char[][BOARD_SIZE], int, int, int, int);
int checkForWinner(char[][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int turn = 1;
    int gameover = 0;
    int currentPlayer = 1;
    int row1, col1, row2, col2;

    // initialize board
    initializeBoard(board);

    // game loop
    while(!gameover) {
        // print board
        printf("\n\n\n");
        printBoard(board);

        // ask player for move
        printf("\n\nPlayer %d: Enter coordinates of piece to move: ", currentPlayer);
        scanf("%d%d", &row1, &col1);
        printf("\nPlayer %d: Enter coordinates of destination: ", currentPlayer);
        scanf("%d%d", &row2, &col2);

        // check if move is valid
        if(isValidMove(board, row1, col1, row2, col2)) {
            // move piece
            movePiece(board, row1, col1, row2, col2);

            // check for winner
            if(checkForWinner(board)) {
                printf("\n\nPlayer %d Wins!!\n\n", currentPlayer);
                gameover = 1;
            }

            // switch turns
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        } else {
            printf("\n\nInvalid move. Try again.\n\n");
        }
    }

    return 0;
}

// Initializes the checkers game board
void initializeBoard(char board[][BOARD_SIZE]) {
    int i, j;

    // clear board
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // initialize player 1 pieces
    for(i = 1; i < BOARD_SIZE; i += 2) {
        board[0][i] = 'o';
        board[2][i] = 'o';
    }
    for(i = 0; i < BOARD_SIZE; i += 2) {
        board[1][i] = 'o';
    }

    // initialize player 2 pieces
    for(i = 0; i < BOARD_SIZE; i += 2) {
        board[BOARD_SIZE - 1][i] = 'x';
        board[BOARD_SIZE - 3][i] = 'x';
    }
    for(i = 1; i < BOARD_SIZE; i += 2) {
        board[BOARD_SIZE - 2][i] = 'x';
    }
}

// Prints the checkers board
void printBoard(char board[][BOARD_SIZE]) {
    int i, j;

    printf("   0 1 2 3 4 5 6 7\n");
    printf("  +---------------+\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
        printf("  +---------------+\n");
    }
}

// Moves a checkers piece from one location to another
int movePiece(char board[][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    if(board[row2][col2] != ' ') {
        // attacking move, remove piece
        board[row2][col2] = ' ';
    }
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = ' ';

    return 0;
}

// Checks if a checkers move is valid
int isValidMove(char board[][BOARD_SIZE], int row1, int col1, int row2, int col2) {
    // check if destination is off the board
    if(row2 < 0 || row2 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE) {
        return 0;
    }

    // check if destination is occupied by another piece
    if(board[row2][col2] != ' ') {
        return 0;
    }

    // check if piece is moving diagonally
    if(abs(row1 - row2) != 1 || abs(col1 - col2) != 1) {
        return 0;
    }

    // check if piece is moving in the right direction
    if(board[row1][col1] == 'o' && row2 <= row1) {
        return 0;
    }
    if(board[row1][col1] == 'x' && row2 >= row1) {
        return 0;
    }

    return 1;   
}

// Checks for a checkers game winner
int checkForWinner(char board[][BOARD_SIZE]) {
    int i, j;
    int player1Pieces = 0;
    int player2Pieces = 0;

    // count pieces for each player
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 'o') {
                player1Pieces++;
            } else if(board[i][j] == 'x') {
                player2Pieces++;
            }
        }
    }

    // check for winner
    if(player1Pieces == 0) {
        return 1;
    }
    if(player2Pieces == 0) {
        return 1;
    }

    return 0;
}