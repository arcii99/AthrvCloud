//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 30
#define WALL '#'
#define PATH ' '
#define GOAL '*'

char maze[ROWS][COLS];

// Returns true if the coordinates (x, y) are valid
bool isValid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] != WALL);
}

// Returns true if the coordinates (x, y) are the goal
bool isGoal(int x, int y) {
    return maze[x][y] == GOAL;
}

// Generates the maze using a recursive backtracking algorithm
void generateMaze(int x, int y) {
    int directions[4] = {1, 2, 3, 4}; // Up, down, left, right
    bool visited[4] = {false, false, false, false};
    int count = 4;
    
    while (count > 0) {
        int randIndex = rand() % count; // Choose a random direction
        int direction = directions[randIndex];
        directions[randIndex] = directions[count - 1];
        count--;
        
        int nextX, nextY;
        
        if (direction == 1) { // Up
            nextX = x - 2;
            nextY = y;
            
            if (isValid(nextX, nextY)) {
                maze[x - 1][y] = PATH;
                maze[nextX][nextY] = PATH;
                generateMaze(nextX, nextY);
            }
        } else if (direction == 2) { // Down
            nextX = x + 2;
            nextY = y;
            
            if (isValid(nextX, nextY)) {
                maze[x + 1][y] = PATH;
                maze[nextX][nextY] = PATH;
                generateMaze(nextX, nextY);
            }
        } else if (direction == 3) { // Left
            nextX = x;
            nextY = y - 2;
            
            if (isValid(nextX, nextY)) {
                maze[x][y - 1] = PATH;
                maze[nextX][nextY] = PATH;
                generateMaze(nextX, nextY);
            }
        } else { // Right
            nextX = x;
            nextY = y + 2;
            
            if (isValid(nextX, nextY)) {
                maze[x][y + 1] = PATH;
                maze[nextX][nextY] = PATH;
                generateMaze(nextX, nextY);
            }
        }
    }
}

// Finds the shortest path from (startX, startY) to the goal
void findPath(int startX, int startY) {
    int queue[ROWS * COLS][2];
    int front = 0, rear = 0;
    bool visited[ROWS][COLS] = {false};
    
    queue[rear][0] = startX;
    queue[rear][1] = startY;
    rear++;
    visited[startX][startY] = true;

    while (front < rear) {
        int currX = queue[front][0];
        int currY = queue[front][1];
        front++;

        if (isGoal(currX, currY)) {
            break;
        }

        if (isValid(currX - 1, currY) && !visited[currX - 1][currY]) { // Up
            queue[rear][0] = currX - 1;
            queue[rear][1] = currY;
            rear++;
            visited[currX - 1][currY] = true;
        }

        if (isValid(currX + 1, currY) && !visited[currX + 1][currY]) { // Down
            queue[rear][0] = currX + 1;
            queue[rear][1] = currY;
            rear++;
            visited[currX + 1][currY] = true;
        }

        if (isValid(currX, currY - 1) && !visited[currX][currY - 1]) { // Left
            queue[rear][0] = currX;
            queue[rear][1] = currY - 1;
            rear++;
            visited[currX][currY - 1] = true;
        }

        if (isValid(currX, currY + 1) && !visited[currX][currY + 1]) { // Right
            queue[rear][0] = currX;
            queue[rear][1] = currY + 1;
            rear++;
            visited[currX][currY + 1] = true;
        }
    }

    // Mark the path from the goal to the start
    int currX = queue[front][0];
    int currY = queue[front][1];
    maze[currX][currY] = GOAL;

    while (currX != startX || currY != startY) {
        if (isValid(currX - 1, currY) && visited[currX - 1][currY]) { // Up
            currX--;
        } else if (isValid(currX + 1, currY) && visited[currX + 1][currY]) { // Down
            currX++;
        } else if (isValid(currX, currY - 1) && visited[currX][currY - 1]) { // Left
            currY--;
        } else { // Right
            currY++;
        }

        maze[currX][currY] = PATH;
    }
}

int main() {
    srand(time(NULL));
    
    // Initialize the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i % 2 == 0 || j % 2 == 0) {
                maze[i][j] = WALL;
            } else {
                maze[i][j] = PATH;
            }
        }
    }
    
    // Generate the maze starting from the top-left corner
    generateMaze(1, 1);

    // Find the shortest path from the bottom-right corner to the top-left corner
    findPath(ROWS - 2, COLS - 2);

    // Print the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        
        printf("\n");
    }
    
    return 0;
}