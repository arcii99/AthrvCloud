//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 41

// Generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Initialize the maze
void init_maze(char maze[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            maze[i][j] = '#';
        }
    }
}

// Print the maze
void print_maze(char maze[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Generate the maze
void generate_maze(char maze[ROW][COL], int row, int col) {
    // Initialize the random number generator
    srand(time(NULL));
    // Create entry and exit points
    int entry_col = rand_num(2, COL - 2);
    int exit_col = rand_num(2, COL - 2);
    maze[0][entry_col] = ' ';
    maze[ROW - 1][exit_col] = ' ';
    // Generate the maze
    for (int i = 1; i < ROW - 1; i += 2) {
        for (int j = 1; j < COL - 1; j += 2) {
            maze[i][j] = ' ';
            if (i == row && j == col) {
                continue;
            }
            if (i == 1 && j == entry_col) {
                continue;
            }
            if (i == ROW - 2 && j == exit_col) {
                continue;
            }
            int r = rand_num(0, 3);
            switch (r) {
            case 0:
                maze[i - 1][j] = ' ';
                break;
            case 1:
                maze[i + 1][j] = ' ';
                break;
            case 2:
                maze[i][j - 1] = ' ';
                break;
            case 3:
                maze[i][j + 1] = ' ';
                break;
            }
        }
    }
}

int main() {
    char maze[ROW][COL];
    init_maze(maze);
    int row = rand_num(1, ROW - 2);
    int col = rand_num(1, COL - 2);
    generate_maze(maze, row, col);
    print_maze(maze);
    return 0;
}