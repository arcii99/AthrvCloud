//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAZE_ROWS 10
#define MAZE_COLS 10
#define PLAYER_START_X 1
#define PLAYER_START_Y 1
#define EXIT_X 8
#define EXIT_Y 8
#define WALL '#'
#define PATH ' '
#define PLAYER 'O'
#define EXIT 'X'

// Prototypes
void generateMaze(char maze[][MAZE_COLS]);
void printMaze(char maze[][MAZE_COLS], int playerX, int playerY);
void movePlayer(char maze[][MAZE_COLS], int *playerX, int *playerY);
int checkForExit(int playerX, int playerY);

// Main Function
int main() {
    char maze[MAZE_ROWS][MAZE_COLS];
    int playerX = PLAYER_START_X;
    int playerY = PLAYER_START_Y;
    int timeLeft = 60;
    int hasEscaped = 0;
    
    // Seed Random Number Generator
    srand(time(NULL));
    
    // Generate Maze
    generateMaze(maze);
    
    // Game Loop
    while (timeLeft > 0 && !hasEscaped) {
        // Print Maze and Player Location
        printf("Time Left: %d seconds\n", timeLeft);
        printMaze(maze, playerX, playerY);
        
        // Move Player
        movePlayer(maze, &playerX, &playerY);
        
        // Check for Exit
        hasEscaped = checkForExit(playerX, playerY);
        
        // Decrement Time
        timeLeft--;
    }
    
    // Game Over
    if (hasEscaped) {
        printf("\nCongratulations! You have escaped the maze!\n");
    } else {
        printf("\nGame over! You ran out of time.\n");
    }

    return 0;
}

// Function to generate random maze
void generateMaze(char maze[][MAZE_COLS]) {
    int i, j;
    
    // Generate Walls
    for (i = 0; i < MAZE_ROWS; i++) {
        for (j = 0; j < MAZE_COLS; j++) {
            if (i == 0 || i == MAZE_ROWS - 1 || j == 0 || j == MAZE_COLS - 1) {
                maze[i][j] = WALL;
            } else {
                maze[i][j] = rand() % 100 < 25 ? WALL : PATH;
            }
        }
    }
    
    // Set Start and Exit Positions
    maze[PLAYER_START_X][PLAYER_START_Y] = PLAYER;
    maze[EXIT_X][EXIT_Y] = EXIT;
}

// Function to print maze
void printMaze(char maze[][MAZE_COLS], int playerX, int playerY) {
    int i, j;
    
    // Print Maze
    for (i = 0; i < MAZE_ROWS; i++) {
        for (j = 0; j < MAZE_COLS; j++) {
            if (i == playerX && j == playerY) {
                printf("%c", PLAYER);
            } else {
                printf("%c", maze[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to move player
void movePlayer(char maze[][MAZE_COLS], int *playerX, int *playerY) {
    char move;
    int newX, newY;
    
    // Get Player's Move
    printf("Enter your move: ");
    scanf(" %c", &move);
    
    // Move Player
    newX = *playerX;
    newY = *playerY;
    
    switch (move) {
        case 'w': // Up
            newX--;
            break;
        case 's': // Down
            newX++;
            break;
        case 'a': // Left
            newY--;
            break;
        case 'd': // Right
            newY++;
            break;
        default: // Invalid Move
            printf("Invalid move!\n");
            return;
    }
    
    // Check if Move is Valid
    if (maze[newX][newY] == PATH || maze[newX][newY] == EXIT) {
        maze[*playerX][*playerY] = PATH;
        *playerX = newX;
        *playerY = newY;
        maze[*playerX][*playerY] = PLAYER;
    } else {
        printf("Invalid move!\n");
    }
}

// Function to check for exit
int checkForExit(int playerX, int playerY) {
    if (playerX == EXIT_X && playerY == EXIT_Y) {
        return 1;
    } else {
        return 0;
    }
}