//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10    // size of the grid
#define THRESHOLD 0.6    // probability of site being open

int grid[SIZE][SIZE];   // the grid
int visited[SIZE][SIZE];   // visited array
int top = -1;   // top of stack
int stack[SIZE*SIZE];   // stack array

// function to check if a site is open or not
int is_open_site() {
    double rnd = (double)rand() / RAND_MAX;
    if(rnd < THRESHOLD) {
        return 1;
    }
    return 0;
}

// function to create the grid
void create_grid() {
    srand(time(NULL));   // seed for random number generation
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            grid[i][j] = is_open_site();
            visited[i][j] = 0;
        }
    }
    // make sure the first row is open
    for(j=0; j<SIZE; j++) {
        grid[0][j] = 1;
    }
    // make sure the last row is open
    for(j=0; j<SIZE; j++) {
        grid[SIZE-1][j] = 1;
    }
}

// function to print the grid
void print_grid() {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            if(grid[i][j] == 1) {
                printf("O ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// function to push element to stack
void push(int x, int y) {
    ++top;
    stack[top] = x*SIZE + y;
}

// function to pop element from stack
void pop(int *x, int *y) {
    *y = stack[top] % SIZE;
    *x = stack[top] / SIZE;
    --top;
}

// function to check if site is valid
int is_valid(int x, int y) {
    if(x >= 0 && y >= 0 && x < SIZE && y < SIZE && grid[x][y] == 1 && visited[x][y] == 0) {
        return 1;
    }
    return 0;
}

// function to do percolation
int do_percolation() {
    int i, j;
    for(i=0; i<SIZE; i++) {
        if(grid[0][i] == 1) {
            push(0, i);    // push the element to stack
            visited[0][i] = 1;   // mark as visited
        }
    }
    while(top != -1) {
        int x, y;
        pop(&x, &y);   // pop the top element from stack
        if(x == SIZE-1) {
            return 1;   // percolation has occurred
        }
        visited[x][y] = 1;
        // push all the neighbors to stack
        if(is_valid(x+1, y)) {
            push(x+1, y);
        }
        if(is_valid(x-1, y)) {
            push(x-1, y);
        }
        if(is_valid(x, y+1)) {
            push(x, y+1);
        }
        if(is_valid(x, y-1)) {
            push(x, y-1);
        }
    }
    return 0;   // percolation has not occurred
}

// main function
int main() {
    create_grid();   // create the grid
    printf("Initial Grid:\n");
    print_grid();   // print the grid
    int result = do_percolation();   // do the percolation
    printf("\nResult:\n");
    print_grid();   // print the grid
    if(result == 1) {
        printf("\nPercolation has occurred!\n");
    }
    else {
        printf("\nPercolation has not occurred!\n");
    }
    return 0;
}