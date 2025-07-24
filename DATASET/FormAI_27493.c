//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMaze(int mazeSize) {
    int maze[mazeSize][mazeSize], i, j;
    // Initialize maze with walls
    for(i = 0; i < mazeSize; i++) {
        for(j = 0; j < mazeSize; j++) {
            maze[i][j] = 1;
        }
    }

    srand(time(NULL)); // Seed random numbers with current time
    int currentX = rand() % mazeSize;
    int currentY = rand() % mazeSize;
    maze[currentX][currentY] = 0; // Carve the starting cell
    int visitedCount = 1; // Track number of visited cells

    while(visitedCount < mazeSize * mazeSize) {
        int nextX, nextY;
        int validMoves[4][2] = { // List of all possible moves
            {currentX - 1, currentY},
            {currentX + 1, currentY},
            {currentX, currentY - 1},
            {currentX, currentY + 1}
        };
        int numValidMoves = 4;

        // Remove moves that are out of bounds or already visited
        for(i = 0; i < 4; i++) {
            int x = validMoves[i][0];
            int y = validMoves[i][1];
            if(x < 0 || x >= mazeSize || y < 0 || y >= mazeSize || maze[x][y] == 0) {
                validMoves[i][0] = -1;
                validMoves[i][1] = -1;
                numValidMoves--;
            }
        }
        
        if(numValidMoves > 0) { // If there are valid moves
            int randomIndex = rand() % numValidMoves;
            nextX = validMoves[randomIndex][0];
            nextY = validMoves[randomIndex][1];
            maze[nextX][nextY] = 0; // Carve the new cell
            currentX = nextX;
            currentY = nextY;
            visitedCount++;
        } else { // If there are no valid moves, backtrack
            for(i = 0; i < 4; i++) {
                int x = validMoves[i][0];
                int y = validMoves[i][1];
                if(x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && maze[x][y] == 0) {
                    currentX = x;
                    currentY = y;
                    break;
                }
            }
        }
    }

    // Print the maze
    for(i = 0; i < mazeSize; i++) {
        for(j = 0; j < mazeSize; j++) {
            if(maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    int mazeSize;
    printf("Enter maze size: ");
    scanf("%d", &mazeSize);
    generateMaze(mazeSize);
    return 0;
}