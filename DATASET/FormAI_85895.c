//FormAI DATASET v1.0 Category: Checkers Game ; Style: decentralized
#include <stdio.h>

#define SIZE 8

//constants for player's pieces
#define PLAYER_ONE 'B'
#define PLAYER_TWO 'W'

//constants for board spaces
#define EMPTY '.'
#define OCCUPIED 'O'

//function prototypes
void initializeBoard(char board[][SIZE]);
void printBoard(char board[][SIZE]);
int checkLegalMove(char board[][SIZE], int row, int col, int newRow, int newCol, char playerPiece);
int isJump(int oldRow, int oldCol, int newRow, int newCol);
int checkJump(char board[][SIZE], int row, int col, int newRow, int newCol, char playerPiece);
int checkAroundPiece(char board[][SIZE], int row, int col);
int checkIfCanJump(char board[][SIZE], char playerPiece);
int movePiece(char board[][SIZE], int row, int col, int newRow, int newCol, char playerPiece);
int getPlayerInput(char *player, int *row, int *col, int *newRow, int *newCol);
int gameLoop(char board[][SIZE], char playerOne, char playerTwo);

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    printBoard(board);
    gameLoop(board, PLAYER_ONE, PLAYER_TWO);
    return 0;
}

void initializeBoard(char board[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3)
                    board[i][j] = PLAYER_ONE;
                else if (i > 4)
                    board[i][j] = PLAYER_TWO;
                else
                    board[i][j] = EMPTY;
            } else {
                board[i][j] = OCCUPIED;
            }
        }
    }
}

void printBoard(char board[][SIZE]) {
    int i, j;
    printf("   ");
    for (i = 0; i < SIZE; i++)
        printf("%d ", i);
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d  ", i);
        for (j = 0; j < SIZE; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

int checkLegalMove(char board[][SIZE], int row, int col, int newRow, int newCol, char playerPiece) {
    if (board[newRow][newCol] != EMPTY)
        return 0;
    if (playerPiece == PLAYER_ONE && newRow > row)
        return 0;
    if (playerPiece == PLAYER_TWO && newRow < row)
        return 0;
    if (isJump(row, col, newRow, newCol))
        return checkJump(board, row, col, newRow, newCol, playerPiece);
    else {
        if ((newRow == row - 1 || newRow == row + 1) && (newCol == col - 1 || newCol == col + 1))
            return 1;
        else
            return 0;
    }
}

int isJump(int oldRow, int oldCol, int newRow, int newCol) {
    if (oldRow - newRow == 2 || oldRow - newRow == -2)
        return 1;
    else
        return 0;
}

int checkJump(char board[][SIZE], int row, int col, int newRow, int newCol, char playerPiece) {
    int midRow, midCol;
    if (newRow > row) midRow = row + 1;
    else midRow = row - 1;
    if (newCol > col) midCol = col + 1;
    else midCol = col - 1;
    if (board[midRow][midCol] == OCCUPIED && board[midRow][midCol] != playerPiece)
        return 1;
    else
        return 0;
}

int checkAroundPiece(char board[][SIZE], int row, int col) {
    if (board[row][col] == PLAYER_ONE || board[row][col] == PLAYER_TWO) {
        if (checkIfCanJump(board, board[row][col]))
            return 2;
        else
            return 1;
    } else
        return 0;
}

int checkIfCanJump(char board[][SIZE], char playerPiece) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == playerPiece) {
                if ((i >= 2 && j >= 2) && (checkLegalMove(board, i, j, i - 2, j - 2, playerPiece)))
                    return 1;
                if ((i >= 2 && j <= SIZE - 3) && (checkLegalMove(board, i, j, i - 2, j + 2, playerPiece)))
                    return 1;
                if ((i <= SIZE - 3 && j >= 2) && (checkLegalMove(board, i, j, i + 2, j - 2, playerPiece)))
                    return 1;
                if ((i <= SIZE - 3 && j <= SIZE - 3) && (checkLegalMove(board, i, j, i + 2, j + 2, playerPiece)))
                    return 1;
            }
        }
    }
    return 0;
}

int movePiece(char board[][SIZE], int row, int col, int newRow, int newCol, char playerPiece) {
    if (checkLegalMove(board, row, col, newRow, newCol, playerPiece)) {
        if (isJump(row, col, newRow, newCol)) {
            int midRow, midCol;
            if (newRow > row) midRow = row + 1;
            else midRow = row - 1;
            if (newCol > col) midCol = col + 1;
            else midCol = col - 1;
            board[midRow][midCol] = EMPTY;
        }
        board[newRow][newCol] = playerPiece;
        board[row][col] = EMPTY;
        return 1;
    } else
        return 0;
}

int getPlayerInput(char *player, int *row, int *col, int *newRow, int *newCol) {
    int validInput = 0;
    while (!validInput) {
        printf("%s's turn: ", player);
        scanf("%d %d %d %d", row, col, newRow, newCol);
        if (*row >= 0 && *row <= 7 && *col >= 0 && *col <= 7
            && *newRow >= 0 && *newRow <= 7 && *newCol >= 0 && *newCol <= 7)
            validInput = 1;
        else
            printf("Invalid move. Please try again.\n");
    }
    return 1;
}

int gameLoop(char board[][SIZE], char playerOne, char playerTwo) {
    int gameOver = 0;
    int turnCounter = 0;
    char currentPlayer, otherPlayer;
    int row, col, newRow, newCol;
    while (!gameOver) {
        printBoard(board);
        if (turnCounter % 2 == 0) {
            currentPlayer = playerOne;
            otherPlayer = playerTwo;         
        } else {
            currentPlayer = playerTwo;
            otherPlayer = playerOne;
        }
        if (!checkIfCanJump(board, currentPlayer)) {
            getPlayerInput(&currentPlayer, &row, &col, &newRow, &newCol);
            while (!movePiece(board, row, col, newRow, newCol, currentPlayer)) {
                printf("Invalid move. Please try again.\n");
                getPlayerInput(&currentPlayer, &row, &col, &newRow, &newCol);
            }
        } else {
            printf("%s, you must jump!\n", currentPlayer);
            do {
                getPlayerInput(&currentPlayer, &row, &col, &newRow, &newCol);
            } while(checkJump(board, row, col, newRow, newCol, currentPlayer) == 0);
            movePiece(board, row, col, newRow, newCol, currentPlayer);
            while (checkIfCanJump(board, currentPlayer)) {
                do {
                    getPlayerInput(&currentPlayer, &row, &col, &newRow, &newCol);
                } while(checkJump(board, row, col, newRow, newCol, currentPlayer) == 0);
                movePiece(board, row, col, newRow, newCol, currentPlayer);
            }
        }
        if (checkAroundPiece(board, newRow, newCol) == 2) {
            printf("You must continue to jump with this piece.\n");
            turnCounter--;
        }
        if (checkIfCanJump(board, currentPlayer) == 0 && checkIfCanJump(board, otherPlayer) == 0)
            gameOver = 1;
        turnCounter++;
    }
    printBoard(board);
    printf("Game over!\n");
    return 1;
}