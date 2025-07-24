//FormAI DATASET v1.0 Category: Chess engine ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Function to check if a position is valid on the board
int isValidPosition(int row, int col) {
    if(row>=0 && row<8 && col>=0 && col<8) {
        return 1;
    }
    return 0;
}

// Function to check if a given move is allowed for the Knight
int isKnightMoveAllowed(int row, int col, int newRow, int newCol, int visited[8][8]) {
    int rowDiff = newRow - row;
    int colDiff = newCol - col;
    if((abs(rowDiff) == 2 && abs(colDiff) == 1 ||
       abs(rowDiff) == 1 && abs(colDiff) == 2) && 
       isValidPosition(newRow, newCol) &&
       !visited[newRow][newCol]) {
        return 1;
    }
    return 0;
}

// Recursive function to find a valid path for the Knight
int findValidPath(int row, int col, int visited[8][8], int count) {
    visited[row][col] = count;
    if(count == 64) {
        return 1;
    }
    int rowMoves[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int colMoves[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for(int i=0; i<8; i++) {
        int newRow = row + rowMoves[i];
        int newCol = col + colMoves[i];
        if(isKnightMoveAllowed(row, col, newRow, newCol, visited)) {
            if(findValidPath(newRow, newCol, visited, count+1)) {
                return 1;
            }
        }
    }
    visited[row][col] = 0;
    return 0;
}

int main() {
    int visited[8][8] = {0};
    if(findValidPath(0, 0, visited, 1)) {
        printf("Successfully found a valid Knight's tour.\n");
        printf("The path taken by the Knight:\n\n");
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                printf("%2d ", visited[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Failed to find a valid Knight's tour.\n");
    }
    return 0;
}