//FormAI DATASET v1.0 Category: Checkers Game ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define BLACK 0
#define WHITE 1

// Struct for checking pieces coordinates
typedef struct {
    int x;
    int y;
} Coordinate;

// Struct for holding game state
typedef struct {
    int board[8][8];
    int turn;
} GameState;

// Forward declarations
void initializeBoard(GameState *gameState);
void printBoard(GameState *gameState);
int getOpponent(int currentPlayer);
int movePiece(GameState *gameState, Coordinate current, Coordinate target);

int main() {
    GameState gameState;
    initializeBoard(&gameState);
    printBoard(&gameState);
    
    Coordinate current = {2, 1};
    Coordinate target = {3, 0};
    
    if(movePiece(&gameState, current, target)) {
        printf("Move successful!\n");
        printBoard(&gameState);
    } else {
        printf("Invalid move.\n");
    }
    
    return 0;
}

// Function to initialize the game board
void initializeBoard(GameState *gameState) {
    // Empty board
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            gameState->board[i][j] = -1;
        }
    }
    
    // Black pieces
    for(int i=0; i<3; i++) {
        for(int j=0; j<8; j++) {
            if((i+j) % 2 != 0) {
                gameState->board[i][j] = BLACK;
            }
        }
    }
    
    // White pieces
    for(int i=5; i<8; i++) {
        for(int j=0; j<8; j++) {
            if((i+j) % 2 != 0) {
                gameState->board[i][j] = WHITE;
            }
        }
    }
    
    // Empty spaces
    for(int i=3; i<5; i++) {
        for(int j=0; j<8; j++) {
            if((i+j) % 2 != 0) {
                gameState->board[i][j] = -1;
            }
        }
    }
    
    // Set turn to Black
    gameState->turn = BLACK;
}

// Function to print the game board
void printBoard(GameState *gameState) {
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i=0; i<8; i++) {
        printf("%d ", i);
        for(int j=0; j<8; j++) {
            if(gameState->board[i][j] == -1) {
                printf(". ");
            } else if(gameState->board[i][j] == BLACK) {
                printf("b ");
            } else {
                printf("w ");
            }
        }
        printf("\n");
    }
    
    if(gameState->turn == BLACK) {
        printf("Black's turn.\n");
    } else {
        printf("White's turn.\n");
    }
}

// Function to get the opponent's color
int getOpponent(int currentPlayer) {
    if(currentPlayer == BLACK) {
        return WHITE;
    } else {
        return BLACK;
    }
}

// Function to move a piece on the board
int movePiece(GameState *gameState, Coordinate current, Coordinate target) {
    // Check that the current coordinate has a piece
    if(gameState->board[current.x][current.y] == -1) {
        return 0;
    }
    
    // Check that the target coordinate is empty
    if(gameState->board[target.x][target.y] != -1) {
        return 0;
    }
    
    // Check if move is valid
    int currentPlayer = gameState->board[current.x][current.y];
    int opponent = getOpponent(currentPlayer);
    
    int dx = target.x - current.x;
    int dy = target.y - current.y;
    if(currentPlayer == BLACK) {
        if(dy != 1 || (dx != -1 && dx != 1)) {
            return 0;
        }
    } else {
        if(dy != -1 || (dx != -1 && dx != 1)) {
            return 0;
        }
    }
    
    // Move the piece
    gameState->board[current.x][current.y] = -1;
    gameState->board[target.x][target.y] = currentPlayer;
    
    // Check for captures
    if(dx == -2 && dy == -2) {
        if(gameState->board[current.x-1][current.y-1] == opponent) {
            gameState->board[current.x-1][current.y-1] = -1;
        } else {
            return 0;
        }
    } else if(dx == -2 && dy == 2) {
        if(gameState->board[current.x-1][current.y+1] == opponent) {
            gameState->board[current.x-1][current.y+1] = -1;
        } else {
            return 0;
        }
    } else if(dx == 2 && dy == -2) {
        if(gameState->board[current.x+1][current.y-1] == opponent) {
            gameState->board[current.x+1][current.y-1] = -1;
        } else {
            return 0;
        }
    } else if(dx == 2 && dy == 2) {
        if(gameState->board[current.x+1][current.y+1] == opponent) {
            gameState->board[current.x+1][current.y+1] = -1;
        } else {
            return 0;
        }
    }
    
    // Switch player turn
    gameState->turn = getOpponent(currentPlayer);
    
    return 1;
}