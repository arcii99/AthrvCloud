//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 20

// Function to print the maze
void printMaze(int maze[][MAZE_SIZE]) {
    for(int i=0; i<MAZE_SIZE; i++) {
        for(int j=0; j<MAZE_SIZE; j++) {
            if(maze[i][j] == 0) {
                printf("█"); // Wall
            } else if(maze[i][j] == 1) {
                printf(" "); // Path
            } else if(maze[i][j] == 2) {
                printf("S"); // Start
            } else if(maze[i][j] == 3) {
                printf("E"); // End
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize random seed
    srand(time(0));

    // Generate maze matrix
    int maze[MAZE_SIZE][MAZE_SIZE];
    for(int i=0; i<MAZE_SIZE; i++) {
        for(int j=0; j<MAZE_SIZE; j++) {
            if(i==0 || i==MAZE_SIZE-1 || j==0 || j==MAZE_SIZE-1) {
                maze[i][j] = 0; // Set walls at the edges
            } else {
                maze[i][j] = 1; // Set paths everywhere else
            }
        }
    }

    // Randomly place start and end points
    int startX = rand() % (MAZE_SIZE-2) + 1;
    int startY = rand() % (MAZE_SIZE-2) + 1;
    int endX, endY;
    do {
        endX = rand() % (MAZE_SIZE-2) + 1;
        endY = rand() % (MAZE_SIZE-2) + 1;
    } while(endX == startX && endY == startY);

    maze[startY][startX] = 2;
    maze[endY][endX] = 3;

    // Procedurally generate maze
    int dirX[4] = {1, -1, 0, 0};
    int dirY[4] = {0, 0, 1, -1};
    int posX = startX, posY = startY;
    int visited[MAZE_SIZE][MAZE_SIZE] = {0};
    visited[posY][posX] = 1;
    int stackX[MAZE_SIZE*MAZE_SIZE], stackY[MAZE_SIZE*MAZE_SIZE], top=0;
    do {
        int possibleMoves[4] = {0, 0, 0, 0};
        int numPossibleMoves = 0;
        for(int i=0; i<4; i++) {
            int newX = posX + dirX[i];
            int newY = posY + dirY[i];
            if(maze[newY][newX] == 1 && visited[newY][newX] == 0) {
                possibleMoves[numPossibleMoves] = i;
                numPossibleMoves++;
            }
        }
        if(numPossibleMoves == 0) {
            top--;
            posX = stackX[top];
            posY = stackY[top];
        } else {
            int randIndex = possibleMoves[rand() % numPossibleMoves];
            stackX[top] = posX;
            stackY[top] = posY;
            top++;
            posX += dirX[randIndex];
            posY += dirY[randIndex];
            visited[posY][posX] = 1;
            maze[posY][posX] = 0;
        }
    } while(top > 0);

    // Print maze
    printMaze(maze);

    return 0;
}