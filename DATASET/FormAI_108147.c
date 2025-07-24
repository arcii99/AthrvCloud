//FormAI DATASET v1.0 Category: Checkers Game ; Style: shape shifting
#include <stdio.h>

// Constants
#define BOARD_SIZE 8

// Function Prototypes
void printBoard(char board[][BOARD_SIZE]);
int isValidMove(char board[][BOARD_SIZE], int startX, int startY, int endX, int endY, char player);
void makeMove(char board[][BOARD_SIZE], int startX, int startY, int endX, int endY);
void getAllMoves(char board[][BOARD_SIZE], int startX, int startY, int validMoves[][2], int* numMoves, char player);
int isGameOver(char board[][BOARD_SIZE]);

// Main function
int main() {
    // Initialize the board
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'O','-','O','-','-','-','@','-'},
        {'-','-','-','-','-','O','-','-'},
        {'O','-','-','-','-','-','-','-'},
        {'-','-','-','O','-','-','-','-'},
        {'-','-','-','-','-','-','-','-'},
        {'X','-','-','-','-','-','-','-'},
        {'-','-','X','-','X','-','-','-'},
        {'-','X','-','X','-','X','-','X'}
    };
    
    int turn = 0; // 0 = O, 1 = X
    int winner = -1;
    
    while (winner == -1) {
        // Print the board
        printBoard(board);
        
        // Determine the current player
        char player;
        if (turn == 0) {
            player = '@';
        } else {
            player = 'X';
        }
        
        // Get the player's move
        int startX, startY, endX, endY;
        printf("Player %c, enter your move (startX startY endX endY): ", player);
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);
        
        // Check if the move is valid
        if (isValidMove(board, startX, startY, endX, endY, player)) {
            // Make the move
            makeMove(board, startX, startY, endX, endY);
            
            // Check if the game is over
            if (isGameOver(board)) {
                winner = turn;
            } else {
                // Switch turns
                turn = 1 - turn;
            }
        } else {
            // Invalid move, ask for input again
            printf("Invalid move, please try again.\n");
        }
    }
    
    // Print the final board
    printBoard(board);
    
    // Print the winner
    if (winner == 0) {
        printf("Player @ has won!\n");
    } else {
        printf("Player X has won!\n");
    }
    
    return 0;
}

// Print the board
void printBoard(char board[][BOARD_SIZE]) {
    printf("\n   A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i+1);
    }
    printf("   A B C D E F G H\n\n");
}

// Check if a move is valid for a player
int isValidMove(char board[][BOARD_SIZE], int startX, int startY, int endX, int endY, char player) {
    // Check if start position is valid
    if (board[startY][startX] != player) {
        return 0;
    }
    
    // Check if end position is within the board
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0;
    }
    
    // Check if end position is empty
    if (board[endY][endX] != '-') {
        return 0;
    }
    
    // Check if the move is valid for the piece being moved
    if (player == '@') {
        // Regular moves
        if (endY == startY+1 && (endX == startX-1 || endX == startX+1)) {
            return 1;
        }
        // Capturing moves
        if (endY == startY+2 && (endX == startX-2 || endX == startX+2) && board[startY+1][(startX+endX)/2] == 'X') {
            return 1;
        }
    } else {
        // Regular moves
        if (endY == startY-1 && (endX == startX-1 || endX == startX+1)) {
            return 1;
        }
        // Capturing moves
        if (endY == startY-2 && (endX == startX-2 || endX == startX+2) && board[startY-1][(startX+endX)/2] == '@') {
            return 1;
        }
    }
    
    // Move is not valid
    return 0;
}

// Make a move
void makeMove(char board[][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    // Move the piece
    board[endY][endX] = board[startY][startX];
    board[startY][startX] = '-';
    
    // Check if the piece needs to be captured
    if (startX-endX == 2 || startX-endX == -2) {
        board[(startY+endY)/2][(startX+endX)/2] = '-';
    }
}

// Get all possible moves for a piece
void getAllMoves(char board[][BOARD_SIZE], int startX, int startY, int validMoves[][2], int* numMoves, char player) {
    *numMoves = 0;
    if (player == '@') {
        // Check regular moves
        if (startY+1 < BOARD_SIZE) {
            if (startX-1 >= 0 && board[startY+1][startX-1] == '-') {
                validMoves[*numMoves][0] = startX-1;
                validMoves[*numMoves][1] = startY+1;
                (*numMoves)++;
            }
            if (startX+1 < BOARD_SIZE && board[startY+1][startX+1] == '-') {
                validMoves[*numMoves][0] = startX+1;
                validMoves[*numMoves][1] = startY+1;
                (*numMoves)++;
            }
        }
        // Check capturing moves
        if (startY+2 < BOARD_SIZE) {
            if (startX-2 >= 0 && board[startY+1][startX-1] == 'X' && board[startY+2][startX-2] == '-') {
                validMoves[*numMoves][0] = startX-2;
                validMoves[*numMoves][1] = startY+2;
                (*numMoves)++;
            }
            if (startX+2 < BOARD_SIZE && board[startY+1][startX+1] == 'X' && board[startY+2][startX+2] == '-') {
                validMoves[*numMoves][0] = startX+2;
                validMoves[*numMoves][1] = startY+2;
                (*numMoves)++;
            }
        }
    } else {
        // Check regular moves
        if (startY-1 >= 0) {
            if (startX-1 >= 0 && board[startY-1][startX-1] == '-') {
                validMoves[*numMoves][0] = startX-1;
                validMoves[*numMoves][1] = startY-1;
                (*numMoves)++;
            }
            if (startX+1 < BOARD_SIZE && board[startY-1][startX+1] == '-') {
                validMoves[*numMoves][0] = startX+1;
                validMoves[*numMoves][1] = startY-1;
                (*numMoves)++;
            }
        }
        // Check capturing moves
        if (startY-2 >= 0) {
            if (startX-2 >= 0 && board[startY-1][startX-1] == '@' && board[startY-2][startX-2] == '-') {
                validMoves[*numMoves][0] = startX-2;
                validMoves[*numMoves][1] = startY-2;
                (*numMoves)++;
            }
            if (startX+2 < BOARD_SIZE && board[startY-1][startX+1] == '@' && board[startY-2][startX+2] == '-') {
                validMoves[*numMoves][0] = startX+2;
                validMoves[*numMoves][1] = startY-2;
                (*numMoves)++;
            }
        }
    }
}

// Check if the game is over
int isGameOver(char board[][BOARD_SIZE]) {
    int hasO = 0, hasX = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '@') {
                hasO = 1;
            } else if (board[i][j] == 'X') {
                hasX = 1;
            }
        }
    }
    return !(hasO && hasX);
}