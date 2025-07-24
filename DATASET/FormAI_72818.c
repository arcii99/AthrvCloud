//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

void printMaze(char maze[][COL], int row, int col);
bool findPath(char maze[][COL], int row, int col, int endRow, int endCol, char* path, int* pathIndex);

int main() {
    char maze[ROW][COL] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#'},
        {'#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };

    int startRow = 1;
    int startCol = 1;
    int endRow = 8;
    int endCol = 8;
    char path[ROW * COL] = "";

    printMaze(maze, ROW, COL);

    if (findPath(maze, startRow, startCol, endRow, endCol, path, 0)) {
        printf("\nPath found:\n%s\n", path);
    } else {
        printf("\nPath not found.\n");
    }

    return 0;
}

void printMaze(char maze[][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

bool findPath(char maze[][COL], int row, int col, int endRow, int endCol, char* path, int* pathIndex) {
    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        return false;
    }

    if (maze[row][col] == '#') {
        return false;
    }

    if (row == endRow && col == endCol) {
        path[*pathIndex] = '\0';
        return true;
    }

    maze[row][col] = '#';

    if (findPath(maze, row, col + 1, endRow, endCol, path, pathIndex + 1)) {
        path[*pathIndex] = 'R';
        return true;
    }
  
    if (findPath(maze, row - 1, col, endRow, endCol, path, pathIndex + 1)) {
        path[*pathIndex] = 'U';
        return true;
    }

    if (findPath(maze, row, col - 1, endRow, endCol, path, pathIndex + 1)) {
        path[*pathIndex] = 'L';
        return true;
    }

    if (findPath(maze, row + 1, col, endRow, endCol, path, pathIndex + 1)) {
        path[*pathIndex] = 'D';
        return true;
    }

    return false;
}