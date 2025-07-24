//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// dimensions for the maze
#define WIDTH 20
#define HEIGHT 20

// cell states
#define CLOSED 0
#define OPEN 1

// use bitwise operations to mark walls
#define TOP 1 << 0
#define RIGHT 1 << 1
#define BOTTOM 1 << 2
#define LEFT 1 << 3

// utility function to get a random number between min and max
int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// main function
int main() {
    // seed random number generator
    srand(time(NULL));

    int maze[HEIGHT][WIDTH];

    // initialize all cells as closed
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            maze[i][j] = CLOSED;
        }
    }

    // mark starting point as open
    maze[0][0] |= TOP;
    maze[0][0] |= LEFT;

    // mark ending point as open
    maze[HEIGHT-1][WIDTH-1] |= BOTTOM;
    maze[HEIGHT-1][WIDTH-1] |= RIGHT;

    // generate maze
    int row = 0;
    int col = 0;
    while(row != HEIGHT-1 || col != WIDTH-1) {
        // choose random neighbor to open
        int neighbors[4];
        int num_neighbors = 0;

        if(row > 0 && (maze[row-1][col] & OPEN) == CLOSED) {
            neighbors[num_neighbors++] = TOP;
        }
        if(col < WIDTH-1 && (maze[row][col+1] & OPEN) == CLOSED) {
            neighbors[num_neighbors++] = RIGHT;
        }
        if(row < HEIGHT-1 && (maze[row+1][col] & OPEN) == CLOSED) {
            neighbors[num_neighbors++] = BOTTOM;
        }
        if(col > 0 && (maze[row][col-1] & OPEN) == CLOSED) {
            neighbors[num_neighbors++] = LEFT;
        }

        if(num_neighbors > 0) {
            int random_neighbor_index = get_random(0, num_neighbors-1);
            int random_neighbor = neighbors[random_neighbor_index];

            // mark selected wall as open
            if(random_neighbor == TOP) {
                maze[row][col] |= TOP;
                maze[row-1][col] |= BOTTOM;
                row--;
            }
            else if(random_neighbor == RIGHT) {
                maze[row][col] |= RIGHT;
                maze[row][col+1] |= LEFT;
                col++;
            }
            else if(random_neighbor == BOTTOM) {
                maze[row][col] |= BOTTOM;
                maze[row+1][col] |= TOP;
                row++;
            }
            else if(random_neighbor == LEFT) {
                maze[row][col] |= LEFT;
                maze[row][col-1] |= RIGHT;
                col--;
            }
        }
        else {
            // backtrack if no neighbors are available
            if(col > 0 && (maze[row][col-1] & OPEN) == OPEN) {
                col--;
            }
            else if(row > 0 && (maze[row-1][col] & OPEN) == OPEN) {
                row--;
            }
            else if(col < WIDTH-1 && (maze[row][col+1] & OPEN) == OPEN) {
                col++;
            }
            else if(row < HEIGHT-1 && (maze[row+1][col] & OPEN) == OPEN) {
                row++;
            }
        }
    }

    // print maze
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("+");
            if((maze[i][j] & TOP) == TOP) {
                printf("-");
            }
            else {
                printf(" ");
            }
        }
        printf("+\n");

        for(int j = 0; j < WIDTH; j++) {
            if((maze[i][j] & LEFT) == LEFT) {
                printf("| ");
            }
            else {
                printf("  ");
            }

            if(i == HEIGHT-1 && j == WIDTH-1) {
                printf(" ");
            }
            else {
                printf("X");
            }
        }
        printf("\n");
    }

    return 0;
}