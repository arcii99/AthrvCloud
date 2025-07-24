//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10 /* number of rows in the maze */
#define COL 20 /* number of columns in the maze */

int maze[ROW][COL]; /* the maze itself */
int visited[ROW][COL]; /* a matrix to keep track of visited cells */

/* function to randomly generate the maze */
void generate_maze(int row, int col)
{
    int stackx[ROW*COL]; /* stack to keep track of cell positions */
    int stacky[ROW*COL];
    int top = -1;
    int i, j, x, y, count;

    /* initialize maze and visited matrix */
    for (i=0; i<row; i++) {
        for (j=0; j<col; j++) {
            maze[i][j] = 1; /* set all cells to be walls */
            visited[i][j] = 0; /* mark all cells as unvisited */
        }
    }

    /* start from a random cell */
    x = rand() % row;
    y = rand() % col;
    maze[x][y] = 0; /* set starting cell to be a passage */
    visited[x][y] = 1;
    count = 1; /* count the number of visited cells */

    /* push starting cell onto stack */
    top++;
    stackx[top] = x;
    stacky[top] = y;

    /* keep generating maze until all cells have been visited */
    while (count < row*col) {
        /* check neighboring cells for unvisited cells */
        if (x>0 && !visited[x-1][y]) {
            stackx[top+1] = x-1;
            stacky[top+1] = y;
            top++;
        }
        if (x<row-1 && !visited[x+1][y]) {
            stackx[top+1] = x+1;
            stacky[top+1] = y;
            top++;
        }
        if (y>0 && !visited[x][y-1]) {
            stackx[top+1] = x;
            stacky[top+1] = y-1;
            top++;
        }
        if (y<col-1 && !visited[x][y+1]) {
            stackx[top+1] = x;
            stacky[top+1] = y+1;
            top++;
        }

        /* if there are unvisited neighboring cells, choose one randomly */
        if (top >= 0) {
            int r = rand() % (top+1);
            x = stackx[r];
            y = stacky[r];
            visited[x][y] = 1;
            maze[x][y] = 0; /* make a passage */
            count++;
        }
        /* if there are no unvisited neighboring cells, backtrack */
        else {
            for (i=0; i<row; i++) {
                for (j=0; j<col; j++) {
                    if (visited[i][j]) {
                        /* check neighboring cells for unvisited cells */
                        if (i>0 && !visited[i-1][j]) {
                            top++;
                            stackx[top] = i-1;
                            stacky[top] = j;
                        }
                        if (i<row-1 && !visited[i+1][j]) {
                            top++;
                            stackx[top] = i+1;
                            stacky[top] = j;
                        }
                        if (j>0 && !visited[i][j-1]) {
                            top++;
                            stackx[top] = i;
                            stacky[top] = j-1;
                        }
                        if (j<col-1 && !visited[i][j+1]) {
                            top++;
                            stackx[top] = i;
                            stacky[top] = j+1;
                        }
                    }
                }
            }
        }
    }
}

/* function to print the maze */
void print_maze()
{
    int i, j;
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            if (maze[i][j] == 1) {
                /* wall */
                printf("# ");
            }
            else {
                /* passage */
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL)); /* seed random number generator */
    generate_maze(ROW, COL);
    print_maze();
    return 0;
}