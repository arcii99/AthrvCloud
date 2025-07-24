//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

int maze[ROW][COL] = {0};
int startRow = 0, startCol = 0;
int endRow = ROW - 1, endCol = COL - 1;

void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf("██");
            } else if (maze[i][j] == 1) {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int validMove(int row, int col) {
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 0) {
        int count = 0;
        if (row > 0 && maze[row - 1][col] == 1) {
            count++;
        }
        if (row < ROW - 1 && maze[row + 1][col] == 1) {
            count++;
        }
        if (col > 0 && maze[row][col - 1] == 1) {
            count++;
        }
        if (col < COL - 1 && maze[row][col + 1] == 1) {
            count++;
        }
        return count == 1;
    }
    return 0;
}

void generateMaze() {
    int curRow, curCol;
    maze[startRow][startCol] = 1;
    curRow = startRow;
    curCol = startCol;
    while (1) {
        int prevRow = curRow, prevCol = curCol;
        if (curRow > 0 && validMove(curRow - 1, curCol)) {
            curRow--;
        } else if (curRow < ROW - 1 && validMove(curRow + 1, curCol)) {
            curRow++;
        } else if (curCol > 0 && validMove(curRow, curCol - 1)) {
            curCol--;
        } else if (curCol < COL - 1 && validMove(curRow, curCol + 1)) {
            curCol++;
        } else {
            int found = 0;
            for (int i = 0; i < ROW; i++) {
                if (found) {
                    break;
                }
                for (int j = 0; j < COL; j++) {
                    if (validMove(i, j)) {
                        curRow = i;
                        curCol = j;
                        found = 1;
                        break;
                    }
                }
            }
            if (!found) {
                break;
            }
        }
        maze[curRow][curCol] = 1;
    }
    maze[endRow][endCol] = 1;
}

int main() {
    srand(time(0));
    generateMaze();
    printMaze();
    return 0;
}