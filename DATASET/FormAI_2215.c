//FormAI DATASET v1.0 Category: Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateMaze(char maze[][30]);
void printMaze(char maze[][30]);
void updateMaze(char maze[][30], int playerX, int playerY);
int movePlayer(char maze[][30], int* playerX, int* playerY, char direction);

int main() {
    srand(time(NULL));  // Seed for random generation
    char maze[30][30];
    generateMaze(maze);
    int playerX = 1;  // Starting position of player
    int playerY = 1;
    printf("Welcome to the Brave Maze Game!\n");
    while (1) {
        printMaze(maze);
        printf("Use 'w', 'a', 's', 'd' to move.\n");
        char input;
        scanf("%c", &input);
        getchar();  // Clears input buffer
        int moved = movePlayer(maze, &playerX, &playerY, input);
        if (moved == 0) {
            printf("Invalid move. Try again.\n");
        }
        else {
            updateMaze(maze, playerX, playerY);
            if (maze[playerY][playerX] == 'E') {
                printf("Congratulations, you have escaped the maze!\n");
                break;  // End game
            }
        }
    }
    return 0;
}

/**
 * Generates a random maze using a depth-first search algorithm.
 * 
 * @param maze: the array representing the maze
 * @return void
 */
void generateMaze(char maze[][30]) {
    // Initialize maze to all walls
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (i == 0 || i == 29 || j == 0 || j == 29) {
                maze[i][j] = '#';  // Border walls
            }
            else {
                maze[i][j] = '+';  // Interior walls
            }
        }
    }
    // Create maze using depth-first search algorithm
    int stackX[1000];  // Stack to keep track of visited nodes
    int stackY[1000];
    int stackTop = -1;
    int visited[30][30] = {0};  // Initialize all nodes as unvisited
    int currentX = 1;  // Starting position for maze generation
    int currentY = 1;
    visited[1][1] = 1;  // Mark starting node as visited
    maze[1][1] = ' ';  // Remove wall from starting node
    while (1) {
        // Add unvisited neighbors to stack
        if (currentX > 1 && !visited[currentY][currentX-2]) {
            stackTop++;
            stackX[stackTop] = currentX-2;
            stackY[stackTop] = currentY;
        }
        if (currentY > 1 && !visited[currentY-2][currentX]) {
            stackTop++;
            stackX[stackTop] = currentX;
            stackY[stackTop] = currentY-2;
        }
        if (currentX < 28 && !visited[currentY][currentX+2]) {
            stackTop++;
            stackX[stackTop] = currentX+2;
            stackY[stackTop] = currentY;
        }
        if (currentY < 28 && !visited[currentY+2][currentX]) {
            stackTop++;
            stackX[stackTop] = currentX;
            stackY[stackTop] = currentY+2;
        }
        // If there are no unvisited neighbors, backtrack to previous node
        if (stackTop == -1) {
            break;
        }
        int nextX = stackX[stackTop];
        int nextY = stackY[stackTop];
        stackTop--;
        visited[nextY][nextX] = 1;
        // Remove wall between current node and next node
        if (nextX > currentX) {
            maze[currentY][currentX+1] = ' ';
        }
        else if (nextX < currentX) {
            maze[currentY][currentX-1] = ' ';
        }
        else if (nextY > currentY) {
            maze[currentY+1][currentX] = ' ';
        }
        else if (nextY < currentY) {
            maze[currentY-1][currentX] = ' ';
        }
        // Move to next node
        currentX = nextX;
        currentY = nextY;
    }
    // Add entrance and exit to maze
    maze[1][0] = 'E';
    maze[28][29] = 'S';
}

/**
 * Prints the current state of the maze, including the player's position.
 * 
 * @param maze: the array representing the maze
 * @return void
 */
void printMaze(char maze[][30]) {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (maze[i][j] == '+' || maze[i][j] == '#') {
                printf("\033[30m\033[47m %c\033[m", maze[i][j]);  // White walls
            }
            else if (maze[i][j] == 'E') {
                printf("\033[32m\033[40m %c\033[m", maze[i][j]);  // Green exit
            }
            else if (maze[i][j] == 'S') {
                printf("\033[31m\033[40m %c\033[m", maze[i][j]);  // Red entrance
            }
            else {
                printf(" %c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * Updates the maze to show the player's current position.
 * 
 * @param maze: the array representing the maze
 * @param playerX: the current x-coordinate of the player
 * @param playerY: the current y-coordinate of the player
 * @return void
 */
void updateMaze(char maze[][30], int playerX, int playerY) {
    maze[playerY][playerX] = '@';
}

/**
 * Moves the player in the specified direction if possible.
 * 
 * @param maze: the array representing the maze
 * @param playerX: a pointer to the current x-coordinate of the player
 * @param playerY: a pointer to the current y-coordinate of the player
 * @param direction: the direction the player wants to move in
 * @return int: 0 if the move was invalid, 1 if the move was successful
 */
int movePlayer(char maze[][30], int* playerX, int* playerY, char direction) {
    int x = *playerX;
    int y = *playerY;
    switch (direction) {
        case 'w':
            y--;
            break;
        case 'a':
            x--;
            break;
        case 's':
            y++;
            break;
        case 'd':
            x++;
            break;
        default:
            return 0;  // Invalid input
    }
    if (maze[y][x] == '+' || maze[y][x] == '#') {
        return 0;  // Wall in the way
    }
    *playerX = x;
    *playerY = y;
    return 1;
}