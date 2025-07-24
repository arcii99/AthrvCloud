//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

void generateMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);

int main(void) {
    int maze[ROWS][COLS];
    srand(time(NULL));
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

void generateMaze(int maze[ROWS][COLS]) {
    // Initialize maze with all walls
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // Generate random starting point
    int x = rand() % (COLS-2) + 1;
    int y = rand() % (ROWS-2) + 1;

    maze[x][y] = 0; // Set starting point to empty

    while(1) {
        int direction = rand() % 4; // 0=up, 1=right, 2=down, 3=left

        if(direction == 0 && y > 1 && maze[x][y-2] == 1) { // up
            maze[x][y-1] = 0;
            maze[x][y-2] = 0;
            y -= 2;
        } else if(direction == 1 && x < COLS-2 && maze[x+2][y] == 1) { // right
            maze[x+1][y] = 0;
            maze[x+2][y] = 0;
            x += 2;
        } else if(direction == 2 && y < ROWS-2 && maze[x][y+2] == 1) { // down
            maze[x][y+1] = 0;
            maze[x][y+2] = 0;
            y += 2;
        } else if(direction == 3 && x > 1 && maze[x-2][y] == 1) { // left
            maze[x-1][y] = 0;
            maze[x-2][y] = 0;
            x -= 2;
        }

        int done = 1;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(maze[i][j] == 1) {
                    done = 0;
                    break;
                }
            }
        }

        if(done) {
            break;
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    printf("  ");
    for(int i = 0; i < COLS; i++) {
        printf("_");
    }
    printf("\n");

    for(int i = 0; i < ROWS; i++) {
        printf(" |");
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 1) {
                printf("X");
            } else if(i == 0 && j == 1) {
                printf(" ");
            } else if(i == ROWS-1 && j == COLS-2) {
                printf(" ");
            } else {
                printf(" ");
            }
        }
        printf("| \n");
    }

    printf("  ");
    for(int i = 0; i < COLS; i++) {
        printf("-");
    }
    printf("\n");
    printf("Thy passage through this maze is done, my dear Juliet!\n");
}