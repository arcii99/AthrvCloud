//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

int grid[ROW][COL];

void generate_maze(int row, int col)
{
    int stack_row[ROW*COL];
    int stack_col[ROW*COL];
    int visited[ROW][COL];
    int stack_top = -1;
    int i, j, x, y, rand_dir, visited_count = 1;

    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            grid[i][j] = 1;
            visited[i][j] = 0;
        }
    }

    srand(time(NULL));
    x = rand() % row;
    y = rand() % col;
    visited[x][y] = 1;

    while(visited_count < ROW*COL) {
        rand_dir = rand() % 4;
        switch(rand_dir) {
            case 0:
                if(x-1 >= 0 && visited[x-1][y] == 0) {
                    grid[x-1][y] = 0;
                    visited[x-1][y] = 1;
                    stack_top++;
                    stack_row[stack_top] = x-1;
                    stack_col[stack_top] = y;
                    visited_count++;
                    x--;
                }
                break;

            case 1:
                if(y+1 < col && visited[x][y+1] == 0) {
                    grid[x][y+1] = 0;
                    visited[x][y+1] = 1;
                    stack_top++;
                    stack_row[stack_top] = x;
                    stack_col[stack_top] = y+1;
                    visited_count++;
                    y++;
                }
                break;

            case 2:
                if(x+1 < row && visited[x+1][y] == 0) {
                    grid[x+1][y] = 0;
                    visited[x+1][y] = 1;
                    stack_top++;
                    stack_row[stack_top] = x+1;
                    stack_col[stack_top] = y;
                    visited_count++;
                    x++;
                }
                break;

            case 3:
                if(y-1 >= 0 && visited[x][y-1] == 0) {
                    grid[x][y-1] = 0;
                    visited[x][y-1] = 1;
                    stack_top++;
                    stack_row[stack_top] = x;
                    stack_col[stack_top] = y-1;
                    visited_count++;
                    y--;
                }
                break;

            default:
                break;
        }

        if(stack_top == -1) {
            x = rand() % row;
            y = rand() % col;
            visited[x][y] = 1;
            stack_top++;
            stack_row[stack_top] = x;
            stack_col[stack_top] = y;
        }
    }
}

void print_maze(int row, int col)
{
    int i, j;

    printf("\n");
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            if(grid[i][j] == 1) {
                printf("# ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    generate_maze(ROW, COL);
    print_maze(ROW, COL);

    return 0;
}