//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 21
#define HEIGHT 21 /* maximum maze size is 21x21 */

void print_maze(int maze[HEIGHT][WIDTH], int width, int height)
{
    printf("+");
    for (int j = 0; j < width; j++) {
        printf("--");
    }
    printf("+\n");

    for (int i = 0; i < height; i++) {
        printf("|");   
        for (int j = 0; j < width; j++) {
            if (maze[i][j] & 1) {
                printf(" ");
            } else {
                printf("|");
            }
            if (maze[i][j] & 8) {
                printf(" ");
            } else {
                printf("-");
            }
        }
        printf("|\n");
    }

    printf("+");
    for (int j = 0; j < width; j++) {
        printf("--");
    }
    printf("+\n");
}

void carve_maze(int maze[HEIGHT][WIDTH], int width, int height, int x, int y)
{
    int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int r, tmp;

    for (int i = 0; i < 4; i++) {
        r = rand() % 4;
        tmp = dirs[r][0];
        dirs[r][0] = dirs[i][0];
        dirs[i][0] = tmp;

        tmp = dirs[r][1];
        dirs[r][1] = dirs[i][1];
        dirs[i][1] = tmp;
    }

    for (int i = 0; i < 4; i++) {
        int dx = dirs[i][0];
        int dy = dirs[i][1];
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < width && ny >= 0 && ny < height && !maze[ny][nx]) {
            maze[y][x] |= (1 << i);
            maze[ny][nx] |= (1 << (i + 2) % 4);
            carve_maze(maze, width, height, nx, ny);
        }
    }
}

int main()
{
    srand(time(NULL));
    int maze[HEIGHT][WIDTH] = {0};

    carve_maze(maze, WIDTH, HEIGHT, 0, 0);
    print_maze(maze, WIDTH, HEIGHT);

    return 0;
}