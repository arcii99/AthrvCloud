//FormAI DATASET v1.0 Category: Game ; Style: curious
/*This program is a game where the player must navigate through a maze to find the treasure. 
The maze is randomly generated each time the game is played, and the player has a limited 
number of moves to reach the treasure.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for maze size and player starting position
#define MAZE_SIZE 10
#define PLAYER_X 0
#define PLAYER_Y 0

// Declaring functions
void generateMaze(char maze[][MAZE_SIZE]);
void printMaze(char maze[][MAZE_SIZE], int playerX, int playerY);
void movePlayer(char maze[][MAZE_SIZE], int* playerX, int* playerY, int* movesLeft);
int checkTreasure(char maze[][MAZE_SIZE], int playerX, int playerY);

// Main function
int main() {
    char maze[MAZE_SIZE][MAZE_SIZE];
    int playerX = PLAYER_X;
    int playerY = PLAYER_Y;
    int movesLeft = 20;
    generateMaze(maze);
    while (movesLeft > 0) {
        printMaze(maze, playerX, playerY);
        printf("Moves left: %d\n", movesLeft);
        movePlayer(maze, &playerX, &playerY, &movesLeft);
        if (checkTreasure(maze, playerX, playerY)) {
            printf("You found the treasure!\n");
            return 0;
        }
    }
    printf("Out of moves! Game over.\n");
    return 0;
}


// Function to randomly generate the maze
void generateMaze(char maze[][MAZE_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == 0 || j == 0 || i == MAZE_SIZE-1 || j == MAZE_SIZE-1) {
                maze[i][j] = '#';
            }
            else {
                if (rand() % 2 == 0) {
                    maze[i][j] = ' ';
                }
                else {
                    maze[i][j] = '#';
                }
            }
        }
    }
    maze[0][0] = ' ';
    maze[MAZE_SIZE-1][MAZE_SIZE-1] = 'X';
}

// Function to print the maze and player location
void printMaze(char maze[][MAZE_SIZE], int playerX, int playerY) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == playerY && j == playerX) {
                printf("O ");
            }
            else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to move the player and decrement movesLeft
void movePlayer(char maze[][MAZE_SIZE], int* playerX, int* playerY, int* movesLeft) {
    char direction;
    printf("Which direction do you want to move? (w, a, s, d): ");
    scanf(" %c", &direction);
    switch(direction) {
        case 'w':
            if (*playerY > 0 && maze[*playerY-1][*playerX] != '#') {
                *playerY -= 1;
            }
            break;
        case 'a':
            if (*playerX > 0 && maze[*playerY][*playerX-1] != '#') {
                *playerX -= 1;
            }
            break;
        case 's':
            if (*playerY < MAZE_SIZE-1 && maze[*playerY+1][*playerX] != '#') {
                *playerY += 1;
            }
            break;
        case 'd':
            if (*playerX < MAZE_SIZE-1 && maze[*playerY][*playerX+1] != '#') {
                *playerX += 1;
            }
            break;
    }
    *movesLeft -= 1;
}

// Function to check if player has reached the treasure
int checkTreasure(char maze[][MAZE_SIZE], int playerX, int playerY) {
    if (maze[playerY][playerX] == 'X') {
        return 1;
    }
    else {
        return 0;
    }
}