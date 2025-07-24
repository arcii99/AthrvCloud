//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);

int main()
{
    int maze[ROWS][COLS];
    srand(time(NULL));

    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[ROWS][COLS]){
    int i, j, k;

    // fill maze with walls
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            maze[i][j] = 1;
        }
    }

    // make random path
    int curRow = 1;
    int curCol = 1;
    maze[curRow][curCol] = 0;
    while(curRow != ROWS - 2 || curCol != COLS - 2){
        // get random direction
        int direction = rand() % 4;

        if(direction == 0 && curRow > 1 && maze[curRow - 2][curCol] == 1){
            maze[curRow - 1][curCol] = 0;
            maze[curRow - 2][curCol] = 0;
            curRow -= 2;
        } else if(direction == 1 && curCol < COLS - 2 && maze[curRow][curCol + 2] == 1){
            maze[curRow][curCol + 1] = 0;
            maze[curRow][curCol + 2] = 0;
            curCol += 2;
        } else if(direction == 2 && curRow < ROWS - 2 && maze[curRow + 2][curCol] == 1){
            maze[curRow + 1][curCol] = 0;
            maze[curRow + 2][curCol] = 0;
            curRow += 2;
        } else if(direction == 3 && curCol > 1 && maze[curRow][curCol - 2] == 1){
            maze[curRow][curCol - 1] = 0;
            maze[curRow][curCol - 2] = 0;
            curCol -= 2;
        }
    }
}

void printMaze(int maze[ROWS][COLS]){
    int i, j;
    printf(" ");

    // print top border
    for(i = 0; i < COLS; i++){
        printf("_ ");
    }

    printf("\n");

    // print middle rows
    for(i = 0; i < ROWS; i++){
        printf("|");

        for(j = 0; j < COLS; j++){
            if(maze[i][j] == 1){
                printf("X");
            } else {
                printf(" ");
            }

            printf("|");
        }

        printf("\n");
    }

    // print bottom border
    for(i = 0; i < COLS; i++){
        printf("_ ");
    }

    printf("\n");
}