//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Linus Torvalds
/* Linus Torvalds style Pathfinding Algorithm */
/* Filename: pathfinder.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 9
#define COL 10

int grid[ROW][COL] = {
    {1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool isUnblocked(int row, int col) {
    return grid[row][col] == 1;
}

bool isDestination(int row, int col, int destRow, int destCol) {
    return (row == destRow) && (col == destCol);
}

int heuristic(int row, int col, int destRow, int destCol) {
    return abs(row - destRow) + abs(col - destCol);
}

void printPath(int path[ROW][COL], int destRow, int destCol) {
    printf("\nThe shortest path to the destination is:\n");
    int row = destRow;
    int col = destCol;
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};
    while (!(row == 0 && col == 0)) {
         printf("(%d,%d)\n",row,col);
        int tempRow = row - dRow[path[row][col]];
        int tempCol = col - dCol[path[row][col]];
        row = tempRow;
        col = tempCol;
    }
    printf("(%d,%d)\n",row,col);
}

void findPath(int srcRow, int srcCol, int destRow, int destCol) {
    if (!isValid(srcRow,srcCol) || !isValid(destRow,destCol)) {
        printf("Invalid source or destination.");
        return;
    }
    if (!isUnblocked(srcRow,srcCol) || !isUnblocked(destRow,destCol)) {
        printf("Source or destination is blocked.");
        return;
    }
    if (isDestination(srcRow,srcCol,destRow,destCol)) {
        printf("You have already arrived");
        return;
    }

    bool closed[ROW][COL];
    int path[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            closed[i][j] = false;
            path[i][j] = -1;
        }
    }

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    int heap[ROW*COL];
    int heapSize = 0;
    int srcCost = heuristic(srcRow,srcCol,destRow,destCol);
    int srcIdx = srcRow*COL + srcCol;
    heap[heapSize++] = srcIdx;
    closed[srcRow][srcCol] = true;
    path[srcRow][srcCol] = -1;

    bool foundDest = false;
    while (heapSize > 0 && !foundDest) {
        int currIdx = heap[0];
        int currRow = currIdx/10;
        int currCol = currIdx%10;

        if (isDestination(currRow,currCol,destRow,destCol)) {
            foundDest = true;
            break;
        }

        int newCost, newPos;
        for (int i = 0; i < 4; i++) {
            int newRow = currRow + dRow[i];
            int newCol = currCol + dCol[i];
            if (isValid(newRow,newCol) && isUnblocked(newRow,newCol) && !closed[newRow][newCol]) {
                newCost = heuristic(newRow,newCol,destRow,destCol);
                newPos = newRow*10+newCol;

                heap[heapSize++] = newPos;
                int pos = heapSize-1;
                while (pos > 0 && (heuristic(heap[pos]/10,heap[pos]%10,destRow,destCol) < heuristic(heap[(pos-1)/2]/10,heap[(pos-1)/2]%10,destRow,destCol))) {
                    int temp = heap[pos];
                    heap[pos] = heap[(pos-1)/2];
                    heap[(pos-1)/2] = temp;
                    pos = (pos-1)/2;
                }

                closed[newRow][newCol] = true;
                path[newRow][newCol] = i;
            }
        }

        heap[0] = heap[--heapSize];
        int pos = 0;
        while ((pos*2+1) < heapSize) {
            int child1 = pos*2+1;
            int child2 = pos*2+2;
            int minIdx = pos;
            if (heuristic(heap[child1]/10,heap[child1]%10,destRow,destCol) < heuristic(heap[minIdx]/10,heap[minIdx]%10,destRow,destCol)) {
                minIdx = child1;
            }
            if ((child2 < heapSize) && (heuristic(heap[child2]/10,heap[child2]%10,destRow,destCol) < heuristic(heap[minIdx]/10,heap[minIdx]%10,destRow,destCol))) {
                minIdx = child2;
            }
            if (minIdx != pos) {
                int temp = heap[minIdx];
                heap[minIdx] = heap[pos];
                heap[pos] = temp;
                pos = minIdx;
            }
            else {
                break;
            }
        }
    }

    if (!foundDest) {
        printf("Cannot reach the destination.");
        return;
    }
    printPath(path, destRow, destCol);
}

int main() {
    int srcRow = 0;
    int srcCol = 0;
    int destRow = 8;
    int destCol = 9;
    findPath(srcRow,srcCol,destRow,destCol);
    return 0;
}