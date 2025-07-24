//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];
bool visited[ROWS][COLS];

// Asynchronous recursive function to generate a maze
void generate_maze(int row, int col) {
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int shuffle_dir[4] = {0, 1, 2, 3};

    // Shuffle directions
    srand(time(NULL));
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = shuffle_dir[i];
        shuffle_dir[i] = shuffle_dir[j];
        shuffle_dir[j] = temp;
    }

    visited[row][col] = true;
    maze[row][col] = 0;

    for (int i = 0; i < 4; i++) {
        int r = row + directions[shuffle_dir[i]][0];
        int c = col + directions[shuffle_dir[i]][1];

        if (r >= 0 && r < ROWS && c >= 0 && c < COLS && !visited[r][c]) {
            maze[(row + r)/2][(col + c)/2] = 0;
            generate_maze(r, c);
        }
    }
}

int main() {
    // Generate maze
    generate_maze(0, 0);

    // Print maze
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%d ", maze[row][col]);
        }
        printf("\n");
    }

    return 0;
}