//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 31
#define HEIGHT 21

int maze[HEIGHT][WIDTH];

void generate_maze(int row, int col) {
    maze[row][col] = 0;
    int directions[4][2] = {{0, -2}, {0, 2}, {2, 0}, {-2, 0}};
    int num_directions = 4;
    while (num_directions > 0) {
        int r = rand() % num_directions;
        int x = row + directions[r][0];
        int y = col + directions[r][1];
        if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH && maze[x][y] == 1) {
            maze[x][y] = 0;
            maze[row + directions[r][0]/2][col + directions[r][1]/2] = 0;
            generate_maze(x, y);
        }
        directions[r][0] = directions[num_directions-1][0];
        directions[r][1] = directions[num_directions-1][1];
        num_directions--;
    }
}

int main() {
    srand(time(0));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }
    generate_maze(0, 0);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}