//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct {
    int x;
    int y;
} Cell;

typedef struct {
    int visited;
    int north;
    int south;
    int east;
    int west;
} GridItem;

void generateMaze(GridItem maze[WIDTH][HEIGHT], Cell current) {
    maze[current.x][current.y].visited = 1;
    int unvisitedCount = 0;
    Cell unvisitedNeighbours[4];
    
    if (current.x > 0 && !maze[current.x - 1][current.y].visited) {
        unvisitedNeighbours[unvisitedCount++] = (Cell) { current.x - 1, current.y };
    }
    
    if (current.x < WIDTH - 1 && !maze[current.x + 1][current.y].visited) {
        unvisitedNeighbours[unvisitedCount++] = (Cell) { current.x + 1, current.y };
    }
    
    if (current.y > 0 && !maze[current.x][current.y - 1].visited) {
        unvisitedNeighbours[unvisitedCount++] = (Cell) { current.x, current.y - 1 };
    }
    
    if (current.y < HEIGHT - 1 && !maze[current.x][current.y + 1].visited) {
        unvisitedNeighbours[unvisitedCount++] = (Cell) { current.x, current.y + 1 };
    }
    
    while (unvisitedCount > 0) {
        int selectedNeighbourIndex = rand() % unvisitedCount;
        Cell selectedNeighbour = unvisitedNeighbours[selectedNeighbourIndex];
        
        if (selectedNeighbour.x < current.x) {
            maze[current.x][current.y].north = 0;
            maze[selectedNeighbour.x][selectedNeighbour.y].south = 0;
        }
        
        if (selectedNeighbour.x > current.x) {
            maze[current.x][current.y].south = 0;
            maze[selectedNeighbour.x][selectedNeighbour.y].north = 0;
        }
        
        if (selectedNeighbour.y < current.y) {
            maze[current.x][current.y].west = 0;
            maze[selectedNeighbour.x][selectedNeighbour.y].east = 0;
        }
        
        if (selectedNeighbour.y > current.y) {
            maze[current.x][current.y].east = 0;
            maze[selectedNeighbour.x][selectedNeighbour.y].west = 0;
        }
        
        generateMaze(maze, selectedNeighbour);
        
        unvisitedCount = 0;
        if (current.x > 0 && !maze[current.x - 1][current.y].visited) {
            unvisitedNeighbours[unvisitedCount++] = (Cell) { current.x - 1, current.y };
        }
        
        if (current.x < WIDTH - 1 && !maze[current.x + 1][current.y].visited) {
            unvisitedNeighbours[unvisitedCount++] = (Cell) { current.x + 1, current.y };
        }
        
        if (current.y > 0 && !maze[current.x][current.y - 1].visited) {
            unvisitedNeighbours[unvisitedCount++] = (Cell) { current.x, current.y - 1 };
        }
        
        if (current.y < HEIGHT - 1 && !maze[current.x][current.y + 1].visited) {
            unvisitedNeighbours[unvisitedCount++] = (Cell) { current.x, current.y + 1 };
        }
    }
}

void printMaze(GridItem maze[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("+");
            printf(maze[x][y].north ? "---" : "   ");
        }
        printf("+\n");
        
        for (int x = 0; x < WIDTH; x++) {
            printf(maze[x][y].west ? "|" : " ");
            printf("   ");
            printf(maze[x][y].east ? "|" : " ");
        }
        printf("\n");
    }
    
    for (int x = 0; x < WIDTH; x++) {
        printf("+");
        printf(maze[x][HEIGHT - 1].south ? "---" : "   ");
    }
    printf("+\n");
}

int main() {
    srand(time(NULL));
    GridItem maze[WIDTH][HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            maze[x][y] = (GridItem) { 0, 1, 1, 1, 1 };
        }
    }
    
    generateMaze(maze, (Cell) { rand() % WIDTH, rand() % HEIGHT });
    printMaze(maze);
    return 0;
}