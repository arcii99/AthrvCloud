//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int maze[WIDTH][HEIGHT];

void print_maze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", maze[x][y] ? '#' : '.');
        }
        printf("\n");
    }
}

void generate_maze() {
    srand(time(NULL));
    // set walls around the border
    for (int i = 0; i < WIDTH; i++) {
        maze[i][0] = 1;
        maze[i][HEIGHT-1] = 1;
    }
    for (int i = 0; i < HEIGHT; i++) {
        maze[0][i] = 1;
        maze[WIDTH-1][i] = 1;
    }
    // randomly generate the maze
    int x = 2;
    int y = WIDTH-2;
    while (x < HEIGHT-2) {
        maze[x][y] = 1;
        int choices[4] = {1,2,3,4};
        for (int i = 0; i < 4; i++) {
            int r = rand() % 4;
            int temp = choices[i];
            choices[i] = choices[r];
            choices[r] = temp;
        }
        if (choices[0] == 1 && maze[x-2][y] == 0) {
            maze[x-1][y] = 1;
            x -= 2;
        } else if (choices[0] == 2 && maze[x][y-2] == 0) {
            maze[x][y-1] = 1;
            y -= 2;
        } else if (choices[0] == 3 && maze[x+2][y] == 0) {
            maze[x+1][y] = 1;
            x += 2;
        } else if (choices[0] == 4 && maze[x][y+2] == 0) {
            maze[x][y+1] = 1;
            y += 2;
        } else if (choices[1] == 1 && maze[x-2][y] == 0) {
            maze[x-1][y] = 1;
            x -= 2;
        } else if (choices[1] == 2 && maze[x][y-2] == 0) {
            maze[x][y-1] = 1;
            y -= 2;
        } else if (choices[1] == 3 && maze[x+2][y] == 0) {
            maze[x+1][y] = 1;
            x += 2;
        } else if (choices[1] == 4 && maze[x][y+2] == 0) {
            maze[x][y+1] = 1;
            y += 2;
        } else if (choices[2] == 1 && maze[x-2][y] == 0) {
            maze[x-1][y] = 1;
            x -= 2;
        } else if (choices[2] == 2 && maze[x][y-2] == 0) {
            maze[x][y-1] = 1;
            y -= 2;
        } else if (choices[2] == 3 && maze[x+2][y] == 0) {
            maze[x+1][y] = 1;
            x += 2;
        } else if (choices[2] == 4 && maze[x][y+2] == 0) {
            maze[x][y+1] = 1;
            y += 2;
        } else if (choices[3] == 1 && maze[x-2][y] == 0) {
            maze[x-1][y] = 1;
            x -= 2;
        } else if (choices[3] == 2 && maze[x][y-2] == 0) {
            maze[x][y-1] = 1;
            y -= 2;
        } else if (choices[3] == 3 && maze[x+2][y] == 0) {
            maze[x+1][y] = 1;
            x += 2;
        } else if (choices[3] == 4 && maze[x][y+2] == 0) {
            maze[x][y+1] = 1;
            y += 2;
        }
    }
    maze[2][1] = 0;
    maze[WIDTH-3][HEIGHT-2] = 0;
    print_maze();
}

int main() {
    generate_maze();
    return 0;
}