//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 15

void print_maze(char maze[HEIGHT][WIDTH]){
    int i, j;
    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void create_border(char maze[HEIGHT][WIDTH]){
    int i, j;
    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            if(i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1){
                maze[i][j] = '#';
            }
            else{
                maze[i][j] = ' ';
            }
        }
    }
}

void carve_maze(char maze[HEIGHT][WIDTH], int x, int y){
    maze[y][x] = '.';
    int dx, dy, idx, idy, temp;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i = 0; i < 4; i++){
        idx = rand() % 4;
        dy = dirs[idx][0];
        dx = dirs[idx][1];
        temp = maze[y + dy][x + dx];
        idy = y + 2 * dy;
        idx = x + 2 * dx;
        if(temp == ' ' && idy > 0 && idy < HEIGHT - 1 && idx > 0 && idx < WIDTH - 1){
            maze[idy][idx] = '.';
            carve_maze(maze, x + dx, y + dy);
        }
    }
}

int main(){
    srand(time(NULL));
    char maze[HEIGHT][WIDTH]; 
    create_border(maze);
    carve_maze(maze, 1, 1);
    print_maze(maze);
    return 0;
}