//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

int maze[ROWS][COLS];
int visited[ROWS][COLS];
int start_row, start_col, end_row, end_col;

void generateMaze();
void initializeMaze();
void printMaze();
void generatePaths(int row, int col);
void generateStartAndEnd();
int isValidMove(int row, int col);

int main()
{
    srand(time(0));
    initializeMaze();
    generateMaze();
    generateStartAndEnd();
    printMaze();
    return 0;
}

void generateMaze()
{
    generatePaths(1, 1);
}

void initializeMaze()
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }
}

void printMaze()
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        printf("\n");
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
    }
    printf("\n");
}

void generatePaths(int row, int col)
{
    int directions[4] = {0,1,2,3};
    int i, temp, rand_index, rand_dir;
    
    // Mark current cell as visited
    visited[row][col] = 1;

    // Shuffle direction array
    for (i = 0; i < 4; i++) {
        rand_index = rand() % 4;
        temp = directions[i];
        directions[i] = directions[rand_index];
        directions[rand_index] = temp;
    }

    // For each direction
    for (i = 0; i < 4; i++) {
        rand_dir = directions[i];
        switch(rand_dir)
        {
            // Move up
            case 0:
                if (isValidMove(row - 2, col)) {
                    maze[row - 1][col] = PATH;
                    maze[row - 2][col] = PATH;
                    generatePaths(row - 2, col);
                }
                break;

            // Move right
            case 1:
                if (isValidMove(row, col + 2)) {
                    maze[row][col + 1] = PATH;
                    maze[row][col + 2] = PATH;
                    generatePaths(row, col + 2);
                }
                break;

            // Move down
            case 2:
                if (isValidMove(row + 2, col)) {
                    maze[row + 1][col] = PATH;
                    maze[row + 2][col] = PATH;
                    generatePaths(row + 2, col);
                }
                break;

            // Move left
            case 3:
                if (isValidMove(row, col - 2)) {
                    maze[row][col - 1] = PATH;
                    maze[row][col - 2] = PATH;
                    generatePaths(row, col - 2);
                }
                break;
        }
    }
}

void generateStartAndEnd()
{
    // generate start and end positions randomly
    start_row = rand() % ROWS;
    start_col = rand() % COLS;
    end_row = rand() % ROWS;
    end_col = rand() % COLS;

    // make sure start and end positions are not on a wall
    while (maze[start_row][start_col] == WALL || maze[end_row][end_col] == WALL ||
            (start_row == end_row && start_col == end_col)) {
        start_row = rand() % ROWS;
        start_col = rand() % COLS;
        end_row = rand() % ROWS;
        end_col = rand() % COLS;
    }

    maze[start_row][start_col] = START;
    maze[end_row][end_col] = END;
}

int isValidMove(int row, int col)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    if (visited[row][col] == 1 || maze[row][col] != WALL) {
        return 0;
    }
    return 1;
}