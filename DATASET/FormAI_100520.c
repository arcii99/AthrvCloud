//FormAI DATASET v1.0 Category: Checkers Game ; Style: realistic
#include <stdio.h>

#define SIZE 8

// Function to print the board
void printBoard(char board[][SIZE]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the board
void initializeBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0) board[i][j] = ' ';
            else if (i < 3) board[i][j] = 'b';
            else if (i > 4) board[i][j] = 'w';
            else board[i][j] = ' ';
        }
    }
}

// Function to check if the move is valid
int isValidMove(char board[][SIZE], int fromRow, int fromCol, int toRow, int toCol, char player) {
    // Checking if there is a piece at the starting position
    if (player == 'w' && board[fromRow][fromCol] != 'w' && board[fromRow][fromCol] != 'W') {
        return 0;
    } else if (player == 'b' && board[fromRow][fromCol] != 'b' && board[fromRow][fromCol] != 'B') {
        return 0;
    }

    // Checking if the destination is an empty square
    if (board[toRow][toCol] != ' ') {
        return 0;
    }

    // Checking if the move is within the board
    if (fromRow < 0 || fromRow >= SIZE || fromCol < 0 || fromCol >= SIZE || toRow < 0 || toRow >= SIZE || toCol < 0 || toCol >= SIZE) {
        return 0;
    }
    
    // Checking if the move is only forward for regular pieces
    if (player == 'w' && fromRow <= toRow) {
        return 0;
    } else if (player == 'b' && fromRow >= toRow) {
        return 0;
    }

    // Checking if it is a regular move or a capture move
    if (fromRow - toRow == 1 || fromRow - toRow == -1) {
        if (fromCol - toCol == 1 || fromCol - toCol == -1) {
            return 1; // Regular move
        }
    } else if (fromRow - toRow == 2 || fromRow - toRow == -2) {
        if (fromCol - toCol == 2 && board[fromRow-1][(fromCol+toCol)/2] == 'b') {
            return 2; // Capture move
        } else if (fromCol - toCol == -2 && board[fromRow-1][(fromCol+toCol)/2] == 'b') {
            return 2; // Capture move
        } else if (fromCol - toCol == 2 && board[fromRow+1][(fromCol+toCol)/2] == 'b') {
            return 2; // Capture move
        }  else if (fromCol - toCol == -2 && board[fromRow+1][(fromCol+toCol)/2] == 'b') {
            return 2; // Capture move
        }
    }

    return 0;
}

// Function to make a move
void makeMove(char board[][SIZE], int fromRow, int fromCol, int toRow, int toCol, char player) {
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';

    if (player == 'w') {
        if (toRow == 0) {
            board[toRow][toCol] = 'W';
        }
    } else if (player == 'b') {
        if (toRow == SIZE-1) {
            board[toRow][toCol] = 'B';
        }
    }

    // Capture move
    if (fromRow - toRow == 2 || fromRow - toRow == -2) {
        board[(fromRow+toRow)/2][(fromCol+toCol)/2] = ' ';
    }
}

// Function to check if the game is over
int isGameOver(char board[][SIZE]) {
    int countW = 0, countB = 0;

    // Checking if any of the players have no pieces left
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 'w' || board[i][j] == 'W') {
                countW++;
            } else if (board[i][j] == 'b' || board[i][j] == 'B') {
                countB++;
            }
        }
    }

    if (countW == 0) {
        return -1; // Black wins
    } else if (countB == 0) {
        return 1; // White wins
    }

    return 0; // Game not over
}

int main() {
    char board[SIZE][SIZE];
    int fromRow, fromCol, toRow, toCol, validMove, gameOver = 0;
    char player = 'w';

    initializeBoard(board);
    printBoard(board);

    while (!gameOver) {
        printf("%c's turn\n", player);
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &fromRow, &fromCol);
        printf("Enter the row and column of the destination: ");
        scanf("%d %d", &toRow, &toCol);

        validMove = isValidMove(board, fromRow, fromCol, toRow, toCol, player);

        if (validMove == 0) {
            printf("Invalid move, try again\n");
        } else if (validMove == 1) {
            makeMove(board, fromRow, fromCol, toRow, toCol, player);
            printBoard(board);
            gameOver = isGameOver(board);
            if (gameOver == -1) printf("Black wins!\n");
            else if (gameOver == 1) printf("White wins!\n");
            if (player == 'w') player = 'b';
            else if (player == 'b') player = 'w';
        } else if (validMove == 2) {
            makeMove(board, fromRow, fromCol, toRow, toCol, player);
            printBoard(board);
            gameOver = isGameOver(board);
            if (gameOver == -1) printf("Black wins!\n");
            else if (gameOver == 1) printf("White wins!\n");
            else {
                printf("Enter 'c' to continue capturing or any other key to end your turn: ");
                char cont;
                scanf(" %c", &cont);
                if (cont != 'c') {
                    if (player == 'w') player = 'b';
                    else if (player == 'b') player = 'w';
                }
            }
        }
    }

    return 0;
}