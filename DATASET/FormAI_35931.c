//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20

void generate_maze(int maze[ROW][COL]);
void print_maze(int maze[ROW][COL]);

int main() {
    int maze[ROW][COL] = {0}; // initialize maze with all zeros
    srand(time(NULL)); // seed random number generator with current time
    generate_maze(maze); // generate the maze
    print_maze(maze); // print the maze
    return 0;
}

void generate_maze(int maze[ROW][COL]) {
    int i, j, x, y;
    int px[4] = {0, 0, -1, 1}; // possible x directions
    int py[4] = {-1, 1, 0, 0}; // possible y directions
    int visited[ROW][COL] = {0}; // flag to mark visited cells
    int stackx[ROW * COL], stacky[ROW * COL]; // stack to store visited cells
    int top = 0;

    x = rand() % ROW; // pick a random starting point
    y = rand() % COL;
    visited[x][y] = 1; // mark it as visited
    stackx[top] = x; // push it onto the stack
    stacky[top] = y;

    while(top >= 0) { // while there are still unvisited cells
        int flag = 0;
        x = stackx[top]; // pop the top of the stack
        y = stacky[top];
        top--;

        for(i = 0; i < 4; i++) { // for each possible direction
            int newx = x + px[i];
            int newy = y + py[i];
            // check if the new cell is both inside the maze and unvisited
            if(newx >= 0 && newx < ROW && newy >= 0 && newy < COL && !visited[newx][newy]) {
                maze[x][y] |= 1 << i; // create a path from the current cell to the new cell
                visited[newx][newy] = 1; // mark the new cell as visited
                top++; // push the new cell onto the stack
                stackx[top] = newx;
                stacky[top] = newy;
                flag = 1; // set flag to indicate a new cell was visited
                break;
            }
        }

        if(!flag) { // if there were no unvisited cells
            top--; // go back one cell in the stack
        }
    }
}

void print_maze(int maze[ROW][COL]) {
    int i, j;
    printf("+"); // first row
    for(j = 0; j < COL; j++)
        printf("-+");
    printf("\n");

    for(i = 0; i < ROW; i++) {
        printf("|"); // left column
        for(j = 0; j < COL; j++) {
            if(maze[i][j] & 1) // if there is a path to the left
                printf(" ");
            else
                printf("|");

            if(maze[i][j] & 2) // if there is a path above
                printf(" ");
            else
                printf("-");

            if(i == ROW - 1 && j == COL - 1) // if this is the exit
                printf("\033[32;1mX\033[0m");
            else
                printf(" ");
        }
        printf("|\n"); // right column
    }

    printf("+"); // last row
    for(j = 0; j < COL; j++)
        printf("-+");
    printf("\n");
}