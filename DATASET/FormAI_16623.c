//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 25
#define HEIGHT 10
#define GHOST 'G'
#define PLAYER '@'
#define WALL '#'
#define FLOOR ' '
#define DOOR '|'

char room[HEIGHT][WIDTH];
int playerX = 1, playerY = 1;
int score = 0;

void initRoom() {
    srand(time(NULL));

    // Generate room walls
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                room[i][j] = WALL;
            } else {
                room[i][j] = FLOOR;
            }
        }
    }

    // Add doors
    room[HEIGHT/2][0] = DOOR;
    room[HEIGHT/2][WIDTH-1] = DOOR;

    // Add ghosts
    for (int i = 0; i < 3; i++) {
        int x = rand() % (WIDTH-2) + 1;
        int y = rand() % (HEIGHT-2) + 1;
        if (room[y][x] != GHOST && room[y][x] != PLAYER) {
            room[y][x] = GHOST;
        } else {
            i--;
        }
    }

    // Add player
    room[playerY][playerX] = PLAYER;
}

void printRoom() {
    system("clear");

    // Print room
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", room[i][j]);
        }
        printf("\n");
    }

    // Print score
    printf("Score: %d\n", score);
}

void movePlayer(char direction) {
    int newX, newY;

    switch (direction) {
        case 'w': // Up
            newY = playerY - 1;
            newX = playerX;
            break;
        case 'a': // Left
            newY = playerY;
            newX = playerX - 1;
            break;
        case 's': // Down
            newY = playerY + 1;
            newX = playerX;
            break;
        case 'd': // Right
            newY = playerY;
            newX = playerX + 1;
            break;
    }

    // Move player
    if (room[newY][newX] == FLOOR || room[newY][newX] == DOOR) {
        room[playerY][playerX] = FLOOR;
        playerY = newY;
        playerX = newX;
        room[playerY][playerX] = PLAYER;
    }

    // Increment score if player collects ghost
    if (room[playerY][playerX] == GHOST) {
        score++;
        room[playerY][playerX] = FLOOR;
    }
}

int main() {
    initRoom();
    printRoom();

    char input;
    while (1) {
        input = getchar();

        movePlayer(input);

        printRoom();

        // End game if player reaches a door
        if (room[playerY][playerX] == DOOR) {
            printf("Congratulations! You escaped with a score of %d.\n", score);
            return 0;
        }
    }

    return 0;
}