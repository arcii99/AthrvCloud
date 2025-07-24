//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define WIDTH 15
#define HEIGHT 15

int maze[HEIGHT][WIDTH];
int visited[HEIGHT][WIDTH];

void createMaze(int row, int col);
void printMaze();
void setWalls();

int main()
{
    srand(time(NULL));
    setWalls();
    createMaze(1, 1);
    printMaze();

    return 0;
}

void setWalls()
{
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (i == 0 || i == HEIGHT - 1 || j == 0|| j == WIDTH - 1)
                maze[i][j] = 1;
            else 
                maze[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void createMaze(int row, int col)
{
    // up, down, left, right
    int dir_array[4] = {0, 1, 2, 3};
    int tmp, i;

    visited[row][col] = 1;

    while(1)
    {
        if(visited[row-1][col] && visited[row+1][col] && visited[row][col-1] && visited[row][col+1])
            return;

        for(i=3; i>0; i--) 
        {
            int j = rand() % (i+1);
            tmp = dir_array[i];
            dir_array[i] = dir_array[j];
            dir_array[j] = tmp;
        }

        for(i=0; i<4; i++)
        {
            switch(dir_array[i])
            {
                case 0: // up
                    if(visited[row-1][col])
                        break;

                    maze[row][col] &= 0b1110;
                    maze[row-1][col] &= 0b1101;
                    createMaze(row-1, col);
                    break;

                case 1: // down
                    if(visited[row+1][col])
                        break;

                    maze[row][col] &= 0b1101;
                    maze[row+1][col] &= 0b1110;
                    createMaze(row+1, col);
                    break;

                case 2: // left
                    if(visited[row][col-1])
                        break;

                    maze[row][col] &= 0b1011;
                    maze[row][col-1] &= 0b0111;
                    createMaze(row, col-1);
                    break;

                case 3: // right
                    if(visited[row][col+1])
                        break;

                    maze[row][col] &= 0b0111;
                    maze[row][col+1] &= 0b1011;
                    createMaze(row, col+1);
                    break;
            }
        }
    }
}

void printMaze()
{
    int i, j;

    for(i=0; i<HEIGHT; i++)
    {
        for(j=0; j<WIDTH; j++)
        {
            if(maze[i][j] & 0b1000)
                printf("  ");
            else
            {
                if(maze[i][j] & 0b0100)
                    printf("║");
                else
                    printf(" ");

                if(maze[i][j] & 0b0010)
                    printf("═");
                else
                    printf(" ");

                if(i == 0 && j == 1) // start
                    printf("S");
                else if(i == HEIGHT-1 && j == WIDTH-2) // finish
                    printf("F");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}