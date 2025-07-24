//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 10
#define COL_SIZE 10

void generateMaze(int maze[ROW_SIZE][COL_SIZE], int row, int col)
{
    int i, j;

    // Initialize the maze with walls
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            maze[i][j] = 1;
        }
    }

    // Generate random starting point
    srand(time(NULL));
    int startX = rand() % row;
    int startY = rand() % col;

    // Mark starting point as visited
    maze[startX][startY] = 0;

    // Generate maze using depth-first search algorithm
    int currentX = startX;
    int currentY = startY;
    int visitedCount = 1;

    while (visitedCount < row * col) {
        int possibleMoves[4][2] = {
            {currentX - 1, currentY}, // Move up
            {currentX, currentY + 1}, // Move right
            {currentX + 1, currentY}, // Move down
            {currentX, currentY - 1}  // Move left
        };

        // Shuffle the possible moves
        for (i = 0; i < 4; i++) {
            int randomIndex = rand() % 4;
            int tempX = possibleMoves[i][0];
            int tempY = possibleMoves[i][1];
            possibleMoves[i][0] = possibleMoves[randomIndex][0];
            possibleMoves[i][1] = possibleMoves[randomIndex][1];
            possibleMoves[randomIndex][0] = tempX;
            possibleMoves[randomIndex][1] = tempY;
        }

        // Try to move in each direction
        int moveSuccessful = 0;
        for (i = 0; i < 4; i++) {
            int moveX = possibleMoves[i][0];
            int moveY = possibleMoves[i][1];

            if (moveX >= 0 && moveX < row && moveY >= 0 && moveY < col && maze[moveX][moveY] != 0) {
                // Move is valid
                maze[moveX][moveY] = 0;
                currentX = moveX;
                currentY = moveY;
                visitedCount += 1;
                moveSuccessful = 1;
                break;
            }
        }

        // If no move was successful, backtrack
        if (!moveSuccessful) {
            for (i = 0; i < 4; i++) {
                int moveX = possibleMoves[i][0];
                int moveY = possibleMoves[i][1];

                if (moveX >= 0 && moveX < row && moveY >= 0 && moveY < col && maze[moveX][moveY] == 0) {
                    currentX = moveX;
                    currentY = moveY;
                    break;
                }
            }
        }
    }

    // Add entrance and exit to the maze
    maze[startX][startY] = -1;
    int exitX;
    int exitY;
    if (startX == 0) {
        exitX = rand() % row;
        exitY = col - 1;
    } else if (startX == row - 1) {
        exitX = rand() % row;
        exitY = 0;
    } else if (startY == 0) {
        exitX = row - 1;
        exitY = rand() % col;
    } else {
        exitX = 0;
        exitY = rand() % col;
    }
    maze[exitX][exitY] = -2;
}

void printMaze(int maze[ROW_SIZE][COL_SIZE], int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (maze[i][j] == 1) {
                printf("#");
            } else if (maze[i][j] == 0) {
                printf(" ");
            } else if (maze[i][j] == -1) {
                printf("S");
            } else if (maze[i][j] == -2) {
                printf("E");
            }
        }
        printf("\n");
    }
}

int main()
{
    int maze[ROW_SIZE][COL_SIZE];
    generateMaze(maze, ROW_SIZE, COL_SIZE);
    printMaze(maze, ROW_SIZE, COL_SIZE);
    return 0;
}