//FormAI DATASET v1.0 Category: Chess engine ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Define the chess board
int chessBoard[BOARD_SIZE][BOARD_SIZE];

// Define coordinates structure for chess board
typedef struct {
    int x;
    int y;
} Coordinates;

// Initialize the chess board with all zeros
void initializeBoard() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            chessBoard[i][j] = 0;
        }
    }
}

// Helper method to print the chess board
void printBoard() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%d ", chessBoard[i][j]);
        }
        printf("\n");
    }
}

// Method to check if the given coordinates are within the bounds of the chess board
int isWithinBounds(Coordinates coords) {
    if(coords.x >= BOARD_SIZE || coords.x < 0 || coords.y >= BOARD_SIZE || coords.y < 0) {
        return 0;
    }
    return 1;
}

// Method to check if the given position is already occupied
int isPositionOccupied(Coordinates coords) {
    if(chessBoard[coords.x][coords.y] != 0) {
        return 1;
    }
    return 0;
}

// Method to find all the possible moves for a knight from the given position
void findAllPossibleMoves(Coordinates currentPos, Coordinates possibleMoves[]) {
    int moves[8][2] = {{-2,-1}, {-2,1}, {2,-1}, {2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}};
    
    int i, newX, newY;
    for(i=0; i<8; i++) {
        newX = currentPos.x + moves[i][0];
        newY = currentPos.y + moves[i][1];
        
        Coordinates coords = {newX, newY};
        if(isWithinBounds(coords) && !isPositionOccupied(coords)) {
            possibleMoves[i] = coords;
        }
    }
}

// Method to get the number of possible moves for a knight from the given position
int getNumPossibleMoves(Coordinates currentPos) {
    int count = 0;
    
    Coordinates possibleMoves[8];
    findAllPossibleMoves(currentPos, possibleMoves);
    
    for(int i=0; i<8; i++) {
        if(possibleMoves[i].x != -1 && possibleMoves[i].y != -1) {
            count++;
        }
    }
    return count;
}

// Method to find the next move for the knight based on the Warnsdorff's rule
Coordinates getNextMove(Coordinates currentPos) {
    int minMoves = 9; // initialize to a value greater than the maximum possible moves
    Coordinates bestMove = {-1, -1};
    
    Coordinates possibleMoves[8];
    findAllPossibleMoves(currentPos, possibleMoves);
    
    for(int i=0; i<8; i++) {
        if(possibleMoves[i].x != -1 && possibleMoves[i].y != -1) {
            int numPossibleMoves = getNumPossibleMoves(possibleMoves[i]);
            if(numPossibleMoves < minMoves) {
                minMoves = numPossibleMoves;
                bestMove = possibleMoves[i];
            }
        }
    }
    return bestMove;
}

// Main method to run the chess engine
int main() {
    initializeBoard();
    
    // Start at position (0,0) and mark it as visited
    Coordinates currentPosition = {0, 0};
    chessBoard[currentPosition.x][currentPosition.y] = 1;
    
    Coordinates nextMove;
    int moveCount = 2; // We have already made one move to start from position (0,0)
    while(moveCount <= BOARD_SIZE * BOARD_SIZE) { // We can make a maximum of BOARD_SIZE * BOARD_SIZE moves
        nextMove = getNextMove(currentPosition);
        if(nextMove.x == -1 || nextMove.y == -1) {
            printf("Cannot find any more valid moves. Stopping.\n");
            break;
        }
        currentPosition = nextMove;
        chessBoard[currentPosition.x][currentPosition.y] = moveCount;
        moveCount++;
    }
    
    printBoard();
    
    return 0;
}