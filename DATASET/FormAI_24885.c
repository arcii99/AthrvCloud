//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define WALL '*'
#define PATH ' '

char maze[N][N];

void generate_maze();
void print_maze();

int main() {
    srand(time(NULL));

    generate_maze();
    print_maze();

    return 0;
}

void generate_maze() {
    // Fill entire maze with walls
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maze[i][j] = WALL;
        }
    }

    // Set starting and ending point
    int start_i = rand() % N;
    int start_j = 0;
    maze[start_i][start_j] = PATH;

    int end_i = rand() % N;
    int end_j = N - 1;
    maze[end_i][end_j] = PATH;

    // Generate random paths
    int i = start_i;
    int j = start_j;
    while (i != end_i || j != end_j) {
        int direction = rand() % 4;
        switch (direction) {
            case 0:  // Move up
                if (i > 0 && maze[i-1][j] == WALL) {
                    i--;
                    maze[i][j] = PATH;
                }
                break;
            case 1:  // Move right
                if (j < N - 1 && maze[i][j+1] == WALL) {
                    j++;
                    maze[i][j] = PATH;
                }
                break;
            case 2:  // Move down
                if (i < N - 1 && maze[i+1][j] == WALL) {
                    i++;
                    maze[i][j] = PATH;
                }
                break;
            case 3:  // Move left
                if (j > 0 && maze[i][j-1] == WALL) {
                    j--;
                    maze[i][j] = PATH;
                }
                break;
        }
    }
}

void print_maze() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}