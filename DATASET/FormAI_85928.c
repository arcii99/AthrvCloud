//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ROWS 25
#define COLS 25

// Structure to represent a cell in the maze
typedef struct {
    int row, col;
    int left, right, top, bottom;
    int visited;
} Cell;

// Global variables
Cell maze[ROWS][COLS];
pthread_mutex_t lock;

// Function to generate the maze using recursive backtracking algorithm
void generateMaze(int row, int col) {
    maze[row][col].visited = 1;
    int directions[4] = {0, 1, 2, 3};
    int temp, randIndex;
    for(int i=0; i<4; i++) {
        randIndex = rand() % 4;
        temp = directions[randIndex];
        directions[randIndex] = directions[i];
        directions[i] = temp;
    }
    for(int i=0; i<4; i++) {
        switch(directions[i]) {
            case 0: // Left
                if(col-1 >= 0 && !maze[row][col-1].visited) {
                    maze[row][col].left = 0;
                    maze[row][col-1].right = 0;
                    generateMaze(row, col-1);
                }
                break;
            case 1: // Right
                if(col+1 < COLS && !maze[row][col+1].visited) {
                    maze[row][col].right = 0;
                    maze[row][col+1].left = 0;
                    generateMaze(row, col+1);
                }
                break;
            case 2: // Top
                if(row-1 >= 0 && !maze[row-1][col].visited) {
                    maze[row][col].top = 0;
                    maze[row-1][col].bottom = 0;
                    generateMaze(row-1, col);
                }
                break;
            case 3: // Bottom
                if(row+1 < ROWS && !maze[row+1][col].visited) {
                    maze[row][col].bottom = 0;
                    maze[row+1][col].top = 0;
                    generateMaze(row+1, col);
                }
                break;
        }
    }
}

// Function to print the maze
void printMaze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("+");
            if(maze[i][j].top) printf("---");
            else printf("   ");
        }
        printf("+\n");
        for(int j=0; j<COLS; j++) {
            if(maze[i][j].left) printf("|   ");
            else printf("    ");
        }
        if(maze[i][COLS-1].right) printf("|\n");
        else printf(" \n");
    }
    for(int j=0; j<COLS; j++)
        printf("+-+");
    printf("\n");
}

// Thread function to generate the maze
void* threadFunction(void* arg) {
    srand(time(NULL));
    generateMaze(0, 0);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&thread, NULL, threadFunction, NULL);
    pthread_join(thread, NULL);
    printMaze();
    pthread_mutex_destroy(&lock);
    return 0;
}