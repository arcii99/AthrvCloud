//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 30
#define MAZE_HEIGHT 20

#define WALL_CHAR '#'
#define PATH_CHAR ' '
#define START_CHAR 'S'
#define END_CHAR 'E'

int maze[MAZE_HEIGHT][MAZE_WIDTH];
int visited[MAZE_HEIGHT][MAZE_WIDTH];

void initializeMaze() {
    // initialize all cells in maze to be walls
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze[i][j] = 1;
        }
    }
}

void printMaze() {
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("%c", WALL_CHAR);
            } else if (maze[i][j] == 2) {
                printf("%c", PATH_CHAR);
            } else if (maze[i][j] == 3) {
                printf("%c", START_CHAR);
            } else if (maze[i][j] == 4) {
                printf("%c", END_CHAR);
            }
        }
        printf("\n");
    }
}

int isVisited(int row, int col) {
    return visited[row][col] == 1;
}

int isWall(int row, int col) {
    return maze[row][col] == 1;
}

int isEdge(int row, int col) {
    return row == 0 || row == MAZE_HEIGHT - 1 || col == 0 || col == MAZE_WIDTH - 1;
}

int hasUnvisitedNeighbors(int row, int col) {
    int numUnvisited = 0;
    if (row > 0 && !isVisited(row - 1, col)) {
        numUnvisited++;
    }
    if (row < MAZE_HEIGHT - 1 && !isVisited(row + 1, col)) {
        numUnvisited++;
    }
    if (col > 0 && !isVisited(row, col - 1)) {
        numUnvisited++;
    }
    if (col < MAZE_WIDTH - 1 && !isVisited(row, col + 1)) {
        numUnvisited++;
    }
    return numUnvisited > 0;
}

int getUnvisitedNeighbor(int row, int col) {
    int neighbors[4];
    int numNeighbors = 0;
    if (row > 0 && !isVisited(row - 1, col)) {
        neighbors[numNeighbors++] = 0;
    }
    if (row < MAZE_HEIGHT - 1 && !isVisited(row + 1, col)) {
        neighbors[numNeighbors++] = 1;
    }
    if (col > 0 && !isVisited(row, col - 1)) {
        neighbors[numNeighbors++] = 2;
    }
    if (col < MAZE_WIDTH - 1 && !isVisited(row, col + 1)) {
        neighbors[numNeighbors++] = 3;
    }
    int index = neighbors[rand() % numNeighbors];
    switch (index) {
        case 0:
            return (row - 1) * MAZE_WIDTH + col;
        case 1:
            return (row + 1) * MAZE_WIDTH + col;
        case 2:
            return row * MAZE_WIDTH + col - 1;
        case 3:
            return row * MAZE_WIDTH + col + 1;
    }
    return -1;
}

void generateMaze(int currRow, int currCol) {
    visited[currRow][currCol] = 1;
    maze[currRow][currCol] = 2;
    while (hasUnvisitedNeighbors(currRow, currCol)) {
        int nextIndex = getUnvisitedNeighbor(currRow, currCol);
        int nextRow = nextIndex / MAZE_WIDTH;
        int nextCol = nextIndex % MAZE_WIDTH;
        if (nextRow < currRow) {
            maze[currRow - 1][currCol] = 2;
        } else if (nextRow > currRow) {
            maze[currRow + 1][currCol] = 2;
        } else if (nextCol < currCol) {
            maze[currRow][currCol - 1] = 2;
        } else if (nextCol > currCol) {
            maze[currRow][currCol + 1] = 2;
        }
        generateMaze(nextRow, nextCol);
    }
}

void addStartAndEnd() {
    int startRow = rand() % (MAZE_HEIGHT - 2) + 1;
    int startCol = rand() % (MAZE_WIDTH - 2) + 1;
    int endRow = rand() % (MAZE_HEIGHT - 2) + 1;
    int endCol = rand() % (MAZE_WIDTH - 2) + 1;
    maze[startRow][startCol] = 3;
    maze[endRow][endCol] = 4;
}

void generateMazeWrapper() {
    initializeMaze();
    srand(time(NULL));
    generateMaze(MAZE_HEIGHT / 2, MAZE_WIDTH / 2);
    addStartAndEnd();
    printMaze();
}

int main() {
    generateMazeWrapper();
    return 0;
}