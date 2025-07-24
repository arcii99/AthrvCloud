//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20
#define WALL '+'
#define PATH ' '

void initialize_maze(char maze[HEIGHT][WIDTH]){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            maze[i][j] = WALL;
            if(i%2 == 1 && j%2 == 1){
                maze[i][j] = PATH;
            }
        }
    }
}

int is_valid(int x, int y){
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT){
        return 0;
    }else if(x%2 == 0 || y%2 == 0){
        return 0;
    }
    return 1;
}

int can_reach(int x1, int y1, int x2, int y2, char maze[HEIGHT][WIDTH]){
    if(x1 == x2 && y1 == y2){
        return 1;
    }
    maze[y1][x1] = WALL;

    if(is_valid(x1-1, y1) && maze[y1][x1-1] == PATH && can_reach(x1-2, y1, x2, y2, maze)){
        return 1;
    }
    if(is_valid(x1+1, y1) && maze[y1][x1+1] == PATH && can_reach(x1+2, y1, x2, y2, maze)){
        return 1;
    }
    if(is_valid(x1, y1-1) && maze[y1-1][x1] == PATH && can_reach(x1, y1-2, x2, y2, maze)){
        return 1;
    }
    if(is_valid(x1, y1+1) && maze[y1+1][x1] == PATH && can_reach(x1, y1+2, x2, y2, maze)){
        return 1;
    }
    return 0;
}

void generate_maze(char maze [HEIGHT][WIDTH]){
    srand(time(NULL));
    for(int i = 1; i < HEIGHT-1; i += 2){
        for(int j = 1; j < WIDTH-1; j += 2){
            int neighbors[4] = {0,1,2,3};
            for(int k = 0; k < 4; k++){
                int next = rand()%4;
                int temp = neighbors[k];
                neighbors[k] = neighbors[next];
                neighbors[next] = temp;
            }
            for(int k = 0; k < 4; k++){
                int x = j + (neighbors[k] == 0) - (neighbors[k] == 1);
                int y = i + (neighbors[k] == 2) - (neighbors[k] == 3);

                if(is_valid(x, y) && maze[y][x] == WALL && can_reach(j, i, x, y, maze)){
                    maze[y][x] = PATH;
                    break;
                }
            }
        }
    }
    maze[1][0] = PATH;
    maze[HEIGHT-2][WIDTH-1] = PATH;
}

void print_maze(char maze[HEIGHT][WIDTH]){
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char maze[HEIGHT][WIDTH];
    initialize_maze(maze);
    generate_maze(maze);
    print_maze(maze);
    return 0;
}