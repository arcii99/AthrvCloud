//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MOVE_COUNT 20

void printTitle();
void printMap(char grid[MAP_SIZE][MAP_SIZE], int playerX, int playerY);
void genMap(char grid[MAP_SIZE][MAP_SIZE]);
void movePlayer(char grid[MAP_SIZE][MAP_SIZE], int* playerX, int* playerY);
void playGame(char grid[MAP_SIZE][MAP_SIZE], int playerX, int playerY);

int main() {
    char grid[MAP_SIZE][MAP_SIZE];
    int playerX, playerY;
    srand(time(0));

    genMap(grid);
    movePlayer(grid, &playerX, &playerY);
    playGame(grid, playerX, playerY);

    return 0;
}

void printTitle() {
    system("clear");
    printf("\n\n\n\n");
    printf("  _____                          _____         _       \n");
    printf(" / ____|                        / ____|       | |      \n");
    printf("| (___   _   _  ___  ___ ___  | |  __  __ _ | | ___  \n");
    printf(" \\___ \\ | | | |/ __|/ __/ _ \\ | | |_ |/ _` || |/ __| \n");
    printf(" ____) || |_| |\\__ \\| (_|  __/ | |__| | (_| || |\\__ \\ \n");
    printf("|_____/  \\__,_||___/ \\___\\___|  \\_____|\\__,_||_||___/ \n");
    printf("\n\n\n");
}

void printMap(char grid[MAP_SIZE][MAP_SIZE], int playerX, int playerY) {
    system("clear");

    printf("\n");
    printf("CyberPunk Terminal Adventure\n\n");

    for (int i = 0; i < MAP_SIZE; i++) {
        printf("[");
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("O");
            } else if (grid[i][j] == 'E') {
                printf("E");
            } else {
                printf(" ");
            }
            printf("]");
        }
        printf("\n");
    }
}

void genMap(char grid[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (rand() % 3 == 0) {
                grid[i][j] = 'E';
            } else {
                grid[i][j] = ' ';
            }
        }
    }
}

void movePlayer(char grid[MAP_SIZE][MAP_SIZE], int* playerX, int* playerY) {
    *playerX = MAP_SIZE/2;
    *playerY = MAP_SIZE/2;

    printTitle();
    printf("You have been hired to retrieve a valuable data chip from a secure facility.\n");
    printf("However, you are not alone. Enemy agents are guarding the area.\n");
    printf("Use the arrow keys to move, and avoid the enemies!\n");
    printf("\nPress any key to begin...");
    getchar();
}

void playGame(char grid[MAP_SIZE][MAP_SIZE], int playerX, int playerY) {
    int moves = MOVE_COUNT;

    while (moves > 0) {
        printMap(grid, playerX, playerY);
        printf("\nMoves Left: %d\n", moves);

        char move = getchar();
        if (move == 'w' && playerX > 0) {
            playerX--;
        } else if (move == 's' && playerX < MAP_SIZE - 1) {
            playerX++;
        } else if (move == 'a' && playerY > 0) {
            playerY--;
        } else if (move == 'd' && playerY < MAP_SIZE - 1) {
            playerY++;
        }

        if (grid[playerX][playerY] == 'E') {
            printf("\nYou ran into an enemy agent! You have been captured.\n");
            printf("Game Over.\n");
            return;
        }

        moves--;
    }

    printf("\nYou have successfully retrieved the data chip and made it back to base.\n");
    printf("Congratulations!\n");
}