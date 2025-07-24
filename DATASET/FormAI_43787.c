//FormAI DATASET v1.0 Category: Checkers Game ; Style: surprised
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Function to print the current state of the board
void printBoard(char board[][BOARD_SIZE]) {
    printf("\nCurrent State of the Board:\n");

    printf(" ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c  ", board[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Function to initialize the board with pieces
void initializeBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i < 3) {
                if ((i + j) % 2 == 0) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = ' ';
                }
            } else if (i > 4) {
                if ((i + j) % 2 == 0) {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to check if the move is valid
bool isValidMove(char board[][BOARD_SIZE], int player, int sourceX, int sourceY, int destX, int destY) {
    if (destX < 0 || destX >= BOARD_SIZE || destY < 0 || destY >= BOARD_SIZE) {
        return false;
    }

    if (board[destX][destY] != ' ') {
        return false;
    }

    if (player == 1 && board[sourceX][sourceY] != 'X' && board[sourceX][sourceY] != 'K') {
        return false;
    }

    if (player == 2 && board[sourceX][sourceY] != 'O' && board[sourceX][sourceY] != 'K') {
        return false;
    }

    if (abs(sourceX - destX) == 1 && abs(sourceY - destY) == 1) {
        return true;
    }

    if (abs(sourceX - destX) == 2 && abs(sourceY - destY) == 2) {
        int jumpX = (sourceX + destX) / 2;
        int jumpY = (sourceY + destY) / 2;

        if (board[jumpX][jumpY] == ' ') {
            return false;
        }

        if (player == 1 && board[jumpX][jumpY] != 'O' && board[jumpX][jumpY] != 'K') {
            return false;
        }

        if (player == 2 && board[jumpX][jumpY] != 'X' && board[jumpX][jumpY] != 'K') {
            return false;
        }

        return true;
    }

    return false;
}

// Function to make the move
void makeMove(char board[][BOARD_SIZE], int player, int sourceX, int sourceY, int destX, int destY) {
    board[destX][destY] = board[sourceX][sourceY];
    board[sourceX][sourceY] = ' ';

    if (abs(sourceX - destX) == 2 && abs(sourceY - destY) == 2) {
        int jumpX = (sourceX + destX) / 2;
        int jumpY = (sourceY + destY) / 2;

        board[jumpX][jumpY] = ' ';
    }

    if (player == 1 && destX == BOARD_SIZE - 1) {
        board[destX][destY] = 'K';
    }

    if (player == 2 && destX == 0) {
        board[destX][destY] = 'K';
    }
}

// Function to check if a player has won
bool hasWon(char board[][BOARD_SIZE], int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (player == 1 && (board[i][j] == 'O' || board[i][j] == 'K')) {
                return false;
            }

            if (player == 2 && (board[i][j] == 'X' || board[i][j] == 'K')) {
                return false;
            }
        }
    }

    return true;
}

// Function to get the player's move
void getPlayerMove(char board[][BOARD_SIZE], int player, int* sourceX, int* sourceY, int* destX, int* destY) {
    printf("Enter Player %d's Move: ", player);

    scanf("%d %d %d %d", sourceX, sourceY, destX, destY);

    while (!isValidMove(board, player, *sourceX, *sourceY, *destX, *destY)) {
        printf("\nInvalid Move. Try Again.\n\n");
        printf("Enter Player %d's Move: ", player);

        scanf("%d %d %d %d", sourceX, sourceY, destX, destY);
    }
}

int main() {
    int player = 1;
    int sourceX = 0, sourceY = 0, destX = 0, destY = 0;
    char board[BOARD_SIZE][BOARD_SIZE];

    printf("Welcome to the Checkers Game!\n\n");

    initializeBoard(board);

    while (!hasWon(board, player)) {
        printBoard(board);

        getPlayerMove(board, player, &sourceX, &sourceY, &destX, &destY);

        makeMove(board, player, sourceX - 1, sourceY - 1, destX - 1, destY - 1);

        player = player == 1 ? 2 : 1;
    }

    printf("Congratulations Player %d, you have won the game!\n", player);

    return 0;
}