//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 10

typedef struct {
    int x;
    int y;
} Position;

void print_maze(char maze[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if ((i == 0) || (i == HEIGHT - 1) || (j == 0) || (j == WIDTH - 1)) {
                maze[i][j] = '#'; // border
            }
            else {
                maze[i][j] = ' ';
            }
        }
    }
    Position cpos = { 2, 2 };
    maze[cpos.y][cpos.x] = '@';
    srand(time(NULL));
    while (1) {
        int d = rand() % 4;
        Position npos = cpos;
        switch (d) {
        case 0: npos.x++; break;
        case 1: npos.x--; break;
        case 2: npos.y++; break;
        case 3: npos.y--; break;
        }
        if (maze[npos.y][npos.x] == ' ') {
            maze[npos.y][npos.x] = '@';
            int cx = (cpos.x + npos.x) / 2;
            int cy = (cpos.y + npos.y) / 2;
            maze[cy][cx] = '#';
            cpos = npos;
        }
        int count = 0;
        for (i = 1; i < HEIGHT - 1; i++) {
            for (j = 1; j < WIDTH - 1; j++) {
                if (maze[i][j] == '@') {
                    count++;
                }
            }
        }
        if (count >= (WIDTH * HEIGHT) / 3) {
            return; // maze is complete
        }
    }
}

int main() {
    char maze[HEIGHT][WIDTH];
    generate_maze(maze);
    print_maze(maze);
    return 0;
}