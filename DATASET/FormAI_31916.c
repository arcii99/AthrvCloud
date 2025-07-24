//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct Cell {
    bool topWall;
    bool rightWall;
    bool bottomWall;
    bool leftWall;
    bool visited;
} Cell;

typedef struct Location {
    int x;
    int y;
} Location;

Cell maze[HEIGHT * WIDTH];
Location stack[HEIGHT * WIDTH];
int top = -1;

int getIndex(int x, int y) {
    return y * WIDTH + x;
}

bool hasUnvisitedNeighbor(int x, int y) {
    if (x > 0 && !maze[getIndex(x - 1, y)].visited) return true;
    if (x < WIDTH - 1 && !maze[getIndex(x + 1, y)].visited) return true;
    if (y > 0 && !maze[getIndex(x, y - 1)].visited) return true;
    if (y < HEIGHT - 1 && !maze[getIndex(x, y + 1)].visited) return true;
    return false;
}

void push(Location l) {
    stack[++top] = l;
}

Location pop() {
    return stack[top--];
}

Location peek() {
    return stack[top];
}

void removeWall(int currentX, int currentY, int neighborX, int neighborY) {
    if (currentX < neighborX) {
        maze[getIndex(currentX, currentY)].rightWall = false;
        maze[getIndex(neighborX, neighborY)].leftWall = false;
    } else if (currentX > neighborX) {
        maze[getIndex(currentX, currentY)].leftWall = false;
        maze[getIndex(neighborX, neighborY)].rightWall = false;
    } else if (currentY < neighborY) {
        maze[getIndex(currentX, currentY)].bottomWall = false;
        maze[getIndex(neighborX, neighborY)].topWall = false;
    } else if (currentY > neighborY) {
        maze[getIndex(currentX, currentY)].topWall = false;
        maze[getIndex(neighborX, neighborY)].bottomWall = false;
    }
}

void generateMaze() {
    // initialize cells
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        maze[i].topWall = true;
        maze[i].rightWall = true;
        maze[i].bottomWall = true;
        maze[i].leftWall = true;
        maze[i].visited = false;
    }

    // initialize stack with starting cell
    Location currentLocation = {0, 0};
    maze[0].visited = true;
    push(currentLocation);

    while (top >= 0) {
        if (hasUnvisitedNeighbor(currentLocation.x, currentLocation.y)) {
            // choose a random unvisited neighbor
            int direction = rand() % 4;
            int neighborX, neighborY;
            switch (direction) {
                case 0: // left
                    neighborX = currentLocation.x - 1;
                    neighborY = currentLocation.y;
                    break;
                case 1: // up
                    neighborX = currentLocation.x;
                    neighborY = currentLocation.y - 1;
                    break;
                case 2: // right
                    neighborX = currentLocation.x + 1;
                    neighborY = currentLocation.y;
                    break;
                case 3: // down
                    neighborX = currentLocation.x;
                    neighborY = currentLocation.y + 1;
                    break;
            }
            if (!maze[getIndex(neighborX, neighborY)].visited) {
                // remove wall between current cell and chosen neighbor
                removeWall(currentLocation.x, currentLocation.y, neighborX, neighborY);

                // push current cell onto stack and mark neighbor as visited
                push(currentLocation);
                maze[getIndex(neighborX, neighborY)].visited = true;
                currentLocation = (Location) {neighborX, neighborY};
            }
        } else {
            // backtrack to previous cell
            currentLocation = pop();
        }
    }
}

void printMaze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf(maze[getIndex(x, y)].topWall ? "+---" : "+   ");
        }
        printf("+\n");
        for (int x = 0; x < WIDTH; x++) {
            printf(maze[getIndex(x, y)].leftWall ? "|   " : "    ");
        }
        printf("|\n");
    }
    for (int x = 0; x < WIDTH; x++) {
        printf("+---");
    }
    printf("+\n");
}

int main() {
    srand(time(NULL));
    generateMaze();
    printMaze();
    return 0;
}