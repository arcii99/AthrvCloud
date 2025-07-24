//FormAI DATASET v1.0 Category: Checkers Game ; Style: Alan Touring
#include <stdio.h>

#define BOARD_SIZE 8

// Function to print the board
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the board
void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i+j)%2 == 0) {
                board[i][j] = 'B';
            } else {
                board[i][j] = '-';
            }
        }
    }
    
    for(int i = 3; i < 5; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    
    for(int i = 5; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i+j)%2 == 0) {
                board[i][j] = 'W';
            } else {
                board[i][j] = '-';
            }
        }
    }
}

// Function to check if the move is valid
int isMoveValid(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
    // Check if the initial position is not empty
    if(board[x1][y1] == '-') {
        return 0;
    }
    
    // Check if the final position is empty
    if(board[x2][y2] != '-') {
        return 0;
    }
    
    // Check if the move is diagonal
    if((x1-x2) != (y1-y2) && (x1-x2) != -(y1-y2)) {
        return 0;
    }
    
    // Check if the move direction is correct
    if(board[x1][y1] == 'B' && x2 > x1) {
        return 0;
    }
    if(board[x1][y1] == 'W' && x2 < x1) {
        return 0;
    }
    
    // Check if it's a normal move
    if((x1-x2) == 1 || (x1-x2) == -1) {
        return 1;
    }
    
    // Check if it's a jump move
    if((x1-x2) == 2 || (x1-x2) == -2) {
        int middleX = (x1+x2)/2;
        int middleY = (y1+y2)/2;
        if(board[middleX][middleY] == '-' || board[middleX][middleY] == board[x1][y1]) {
            return 0;
        }
        return 1;
    }
    
    return 0;
}

// Function to move a piece
void movePiece(char board[BOARD_SIZE][BOARD_SIZE], int x1, int y1, int x2, int y2) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = '-';
    
    // Check if it's a jump move
    if((x1-x2) == 2 || (x1-x2) == -2) {
        int middleX = (x1+x2)/2;
        int middleY = (y1+y2)/2;
        board[middleX][middleY] = '-';
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    printBoard(board);
    
    int turn = 0; // Black goes first
    
    while(1) {
        // Print whose turn it is
        if(turn == 0) {
            printf("Black's turn.\n");
        } else {
            printf("White's turn.\n");
        }

        // Read the move
        int x1, y1, x2, y2;
        printf("Enter the move (x1 y1 x2 y2): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        // Check if the move is valid
        if(isMoveValid(board, x1, y1, x2, y2)) {
            // Move the piece
            movePiece(board, x1, y1, x2, y2);
            printBoard(board);
            
            // Check if the game is over
            int blackCount = 0;
            int whiteCount = 0;
            for(int i = 0; i < BOARD_SIZE; i++) {
                for(int j = 0; j < BOARD_SIZE; j++) {
                    if(board[i][j] == 'B' || board[i][j] == 'K') {
                        blackCount++;
                    }
                    if(board[i][j] == 'W' || board[i][j] == 'Q') {
                        whiteCount++;
                    }
                }
            }
            if(blackCount == 0) {
                printf("White wins!\n");
                break;
            }
            if(whiteCount == 0) {
                printf("Black wins!\n");
                break;
            }
            
            // Switch the turn
            turn = 1 - turn;
        } else {
            printf("Invalid move.\n");
        }
    }
    
    return 0;
}