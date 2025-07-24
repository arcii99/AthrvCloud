//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

int grid[ROWS][COLS];

int random_number(int min_num, int max_num){
    int result = 0, low_num = 0, hi_num = 0;
    if (min_num < max_num){
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

void print_maze(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(grid[i][j] == 0){
                printf("#");
            }else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_maze(int row, int col){

    int i, j;

    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            grid[i][j] = 0;
        }
    }
    int r = random_number(0, row-1);
    grid[r][0] = 1;
    int c = 0;
    while (c < col - 1){
        int ran_direction = random_number(1, 4);
        switch (ran_direction){
            case UP:
                if(r > 0 && grid[r - 1][c] == 0){//up
                    r--;
                    grid[r][c] = 1;
                    break;
                }
            case DOWN:
                if(r < row - 1 && grid[r + 1][c] == 0){//down
                    r++;
                    grid[r][c] = 1;
                    break;
                }
            case LEFT:
                if(c > 0 && grid[r][c - 1] == 0){//left
                    c--;
                    grid[r][c] = 1;
                    break;
                }
            case RIGHT:
                if(c < col - 1 && grid[r][c + 1] == 0){//right
                    c++;
                    grid[r][c] = 1;
                    break;
                }
            default:
                break;
        }
    }
}

int main()
{
    generate_maze(ROWS, COLS);
    print_maze();
    return 0;
}