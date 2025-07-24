//FormAI DATASET v1.0 Category: Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20
#define MAX_TRAPS 5
#define MAX_TREASURES 3
#define PLAYER_CHAR 'P'
#define TRAP_CHAR 'T'
#define TREASURE_CHAR '$'

int playerX, playerY;
int trapX[MAX_TRAPS], trapY[MAX_TRAPS];
int treasureX[MAX_TREASURES], treasureY[MAX_TREASURES];

void placePlayer();
void placeTraps();
void placeTreasures();
void drawBoard();
int movePlayer(char dir);
int checkCollision(int x, int y);

int main() {
    srand(time(NULL)); // Initializes random number generator
    
    placePlayer();
    placeTraps();
    placeTreasures();
    drawBoard();
    
    char input;
    int gameOver = 0;
    
    while (!gameOver) {
        printf("Enter a direction (WASD): ");
        scanf(" %c", &input);
        if (movePlayer(input) == 1) {
            printf("\nYou win! Congratulations!\n");
            gameOver = 1;
        }
        else if (movePlayer(input) == -1) {
            printf("\nYou lose! Better luck next time.\n");
            gameOver = 1;
        }
        else {
            drawBoard();
        }
    }
    
    return 0;
}

void placePlayer() {
    playerX = rand() % BOARD_SIZE;
    playerY = rand() % BOARD_SIZE;
}

void placeTraps() {
    for (int i = 0; i < MAX_TRAPS; i++) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (checkCollision(x, y) == 0) {
            trapX[i] = x;
            trapY[i] = y;
        }
        else {
            i--;
        }
    }
}

void placeTreasures() {
    for (int i = 0; i < MAX_TREASURES; i++) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (checkCollision(x, y) == 0) {
            treasureX[i] = x;
            treasureY[i] = y;
        }
        else {
            i--;
        }
    }
}

void drawBoard() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == playerY && j == playerX) {
                printf("%c", PLAYER_CHAR);
            }
            else {
                int isTrap = 0;
                int isTreasure = 0;
                for (int k = 0; k < MAX_TRAPS; k++) {
                    if (i == trapY[k] && j == trapX[k]) {
                        printf("%c", TRAP_CHAR);
                        isTrap = 1;
                    }
                }
                for (int k = 0; k < MAX_TREASURES; k++) {
                    if (i == treasureY[k] && j == treasureX[k]) {
                        printf("%c", TREASURE_CHAR);
                        isTreasure = 1;
                    }
                }
                if (isTrap == 0 && isTreasure == 0) {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

int movePlayer(char dir) {
    int newX = playerX;
    int newY = playerY;
    if (dir == 'W' || dir == 'w') {
        newY--;
    }
    else if (dir == 'S' || dir == 's') {
        newY++;
    }
    else if (dir == 'A' || dir == 'a') {
        newX--;
    }
    else if (dir == 'D' || dir == 'd') {
        newX++;
    }
    if (checkCollision(newX, newY) == 1) {
        return -1; // Player collided with trap
    }
    else {
        playerX = newX;
        playerY = newY;
        int treasuresFound = 0;
        for (int i = 0; i < MAX_TREASURES; i++) {
            if (playerX == treasureX[i] && playerY == treasureY[i]) {
                treasuresFound++;
                treasureX[i] = -1;
                treasureY[i] = -1;
            }
        }
        if (treasuresFound == MAX_TREASURES) {
            return 1; // Player found all treasures
        }
        return 0; // Player moved successfully
    }
}

int checkCollision(int x, int y) {
    if (x == playerX && y == playerY) {
        return 1; // Player collided with trap
    }
    for (int i = 0; i < MAX_TRAPS; i++) {
        if (x == trapX[i] && y == trapY[i]) {
            return 1; // Player collided with trap
        }
    }
    return 0; // No collision detected
}