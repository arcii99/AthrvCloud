//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#',' ','#','#'},
    {'#',' ','#',' ','#',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#',' ','#','#'},
    {'#',' ','#',' ','#',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#','#',' ','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#','#',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

bool visited[ROW][COL];

int startRow = 1;
int startCol = 1;
int endRow = 8;
int endCol = 8;

int rowMoves[] = {0, 1,  0, -1};
int colMoves[] = {1, 0, -1,  0};

bool isValidMove(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == ' ' && !visited[row][col]);
}

bool findEnd(int row, int col) {
    if(row == endRow && col == endCol) {
        return true;
    }
    
    bool result = false;
    visited[row][col] = true;
    for(int i = 0; i < 4; i++) {
        int newRow = row + rowMoves[i];
        int newCol = col + colMoves[i];
        if(isValidMove(newRow, newCol)) {
            result = findEnd(newRow, newCol);
            if(result == true) {
                printf("(%d,%d) ", newRow, newCol);
                break;
            }
        }
    }
    return result;
}

int main() {
    printf("Maze Route Finder:\n\n");
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    if(findEnd(startRow, startCol)) {
        printf("\nPath found!\n");
    } else {
        printf("\nNo path found.\n");
    }
    return 0;
}