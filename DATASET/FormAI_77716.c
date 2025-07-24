//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COL 5

void printPath(int row, int col, int a[ROW][COL], int path[ROW][COL])
{
    printf("Path:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int isValidPath(int row, int col, int a[ROW][COL], int path[ROW][COL], int nextRow, int nextCol)
{
    if (nextRow >= 0 && nextRow < row && nextCol >= 0 && nextCol < col && a[nextRow][nextCol] && !path[nextRow][nextCol])
        return 1;
    return 0;
}

int findPath(int row, int col, int a[ROW][COL], int path[ROW][COL], int curRow, int curCol, int endRow, int endCol)
{
    if (curRow == endRow && curCol == endCol) {
        path[curRow][curCol] = 1;
        return 1;
    }

    if (isValidPath(row, col, a, path, curRow, curCol)) {
        path[curRow][curCol] = 1;

        if (findPath(row, col, a, path, curRow+1, curCol, endRow, endCol))
            return 1;

        if (findPath(row, col, a, path, curRow-1, curCol, endRow, endCol))
            return 1;

        if (findPath(row, col, a, path, curRow, curCol+1, endRow, endCol))
            return 1;

        if (findPath(row, col, a, path, curRow, curCol-1, endRow, endCol))
            return 1;

        path[curRow][curCol] = 0;
        return 0;
    }

    return 0;
}

void initialize(int row, int col, int a[ROW][COL])
{
    printf("Array:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            a[i][j] = rand()%2;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[ROW][COL], path[ROW][COL], startRow, startCol, endRow, endCol;
    initialize(ROW, COL, a);

    printf("Enter start position: row col\n");
    scanf("%d %d", &startRow, &startCol);

    printf("Enter end position: row col\n");
    scanf("%d %d", &endRow, &endCol);

    printf("Finding path...\n");

    if (findPath(ROW, COL, a, path, startRow, startCol, endRow, endCol))
        printPath(ROW, COL, a, path);
    else
        printf("Path not found!\n");

    return 0;
}