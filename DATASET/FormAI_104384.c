//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

void printMap(char map[ROWS][COLS]);
void findPath(char map[ROWS][COLS], int row, int col);

int main() {
    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', '#', '#', '#', '#', '#'}
    };

    printf("Original map:\n");
    printMap(map);

    findPath(map, 1, 1);

    printf("\nSolved map:\n");
    printMap(map);

    return 0;
}

void printMap(char map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void findPath(char map[ROWS][COLS], int row, int col) {
    if (map[row][col] == 'G') {
        return;
    } else if (map[row][col] == '#' || map[row][col] == '.') {
        return;
    } else {
        map[row][col] = '.';

        if (row > 0) {
            findPath(map, row - 1, col);
        }

        if (col > 0) {
            findPath(map, row, col - 1);
        }

        if (row < ROWS - 1) {
            findPath(map, row + 1, col);
        }

        if (col < COLS - 1) {
            findPath(map, row, col + 1);
        }
    }
}