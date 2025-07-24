//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int maze[HEIGHT][WIDTH];
int visited[HEIGHT][WIDTH];

void generateMaze(int row, int col) {
    visited[row][col] = 1;
    int directions[] = {1, 2, 3, 4}; // Up, down, left, right
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        int temp = directions[randomIndex];
        directions[randomIndex] = directions[i];
        directions[i] = temp;
    }
    for (int i = 0; i < 4; i++) {
        int newRow = row, newCol = col;
        switch (directions[i]) {
            case 1: // Up
                if (row > 0 && visited[row - 1][col] == 0) {
                    maze[row - 1][col] = 1;
                    generateMaze(row - 1, col);
                }
                break;
            case 2: // Down
                if (row < HEIGHT - 1 && visited[row + 1][col] == 0) {
                    maze[row + 1][col] = 1;
                    generateMaze(row + 1, col);
                }
                break;
            case 3: // Left
                if (col > 0 && visited[row][col - 1] == 0) {
                    maze[row][col - 1] = 1;
                    generateMaze(row, col - 1);
                }
                break;
            case 4: // Right
                if (col < WIDTH - 1 && visited[row][col + 1] == 0) {
                    maze[row][col + 1] = 1;
                    generateMaze(row, col + 1);
                }
                break;
        }
    }
}

int main() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    int startRow = rand() % HEIGHT;
    int startCol = rand() % WIDTH;
    generateMaze(startRow, startCol);
    maze[startRow][startCol] = 2;
    printf(" ");
    for (int i = 0; i < WIDTH * 2 - 1; i++) printf("_");
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 0 || (i == startRow && j == startCol)) {
                printf(" |");
            } else {
                printf("_|");
            }
        }
        printf("\n");
    }
    return 0;
}