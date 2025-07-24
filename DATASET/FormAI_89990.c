//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// A structure to represent a cell in the maze
typedef struct {
    int x;
    int y;
    int visited;
    int walls[4];
} Cell;

// An array to represent the maze
Cell maze[ROWS][COLS];

// Function to initialize the maze
void initializeMaze() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            maze[i][j].x = i;
            maze[i][j].y = j;
            maze[i][j].visited = 0;
            maze[i][j].walls[0] = 1;
            maze[i][j].walls[1] = 1;
            maze[i][j].walls[2] = 1;
            maze[i][j].walls[3] = 1;
        }
    }
}

// Function to check if a cell is within the maze
int isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= ROWS || y >= COLS)
        return 0;
    return 1;
}

// Function to get the neighboring cells
Cell* getNeighbors(Cell* c) {
    Cell* neighbors[4];
    int count = 0;
    if(isValid(c->x-1, c->y) && !maze[c->x-1][c->y].visited) {
        neighbors[count++] = &maze[c->x-1][c->y];
    }
    if(isValid(c->x, c->y-1) && !maze[c->x][c->y-1].visited) {
        neighbors[count++] = &maze[c->x][c->y-1];
    }
    if(isValid(c->x+1, c->y) && !maze[c->x+1][c->y].visited) {
        neighbors[count++] = &maze[c->x+1][c->y];
    }
    if(isValid(c->x, c->y+1) && !maze[c->x][c->y+1].visited) {
        neighbors[count++] = &maze[c->x][c->y+1];
    }
    if(count == 0)
        return NULL;
    return neighbors[rand() % count];
}

// Function to remove the walls between two cells
void removeWalls(Cell* c1, Cell* c2) {
    if(c1->x == c2->x) {
        if(c1->y < c2->y) {
            c1->walls[3] = 0;
            c2->walls[1] = 0;
        } else {
            c1->walls[1] = 0;
            c2->walls[3] = 0;
        }
    } else {
        if(c1->x < c2->x) {
            c1->walls[2] = 0;
            c2->walls[0] = 0;
        } else {
            c1->walls[0] = 0;
            c2->walls[2] = 0;
        }
    }
}

// Function to generate the maze using DFS algorithm
void generateMaze() {
    Cell* current = &maze[0][0];
    current->visited = 1;
    Cell* next;
    int visitedCells = 1;
    while(visitedCells < ROWS*COLS) {
        next = getNeighbors(current);
        if(next != NULL) {
            removeWalls(current, next);
            next->visited = 1;
            visitedCells++;
            current = next;
        } else {
            current = current - 1;
        }
    }
}

// Function to print the maze
void printMaze() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("+");
            if(maze[i][j].walls[0])
                printf("---");
            else
                printf("   ");
        }
        printf("+\n");
        for(j = 0; j < COLS; j++) {
            if(maze[i][j].walls[3])
                printf("|");
            else
                printf(" ");
            printf("   ");
        }
        if(maze[i][j-1].walls[1])
            printf("|");
        else
            printf(" ");
        printf("\n");
    }
    for(j = 0; j < COLS; j++) {
        printf("+---");
    }
    printf("+\n");
}

// Function to generate the maze asynchronously
void generateMazeAsync() {
    initializeMaze();
    srand(time(NULL));
    generateMaze();
    printMaze();
}

int main() {
    generateMazeAsync();
    return 0;
}