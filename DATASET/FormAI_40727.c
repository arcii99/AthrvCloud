//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80    // screen width in characters
#define HEIGHT 24   // screen height in characters

char screen[HEIGHT][WIDTH];  // 2D array to represent the screen

// struct to represent a player or enemy ship
typedef struct {
    int x, y;       // current position of the ship
    int dx, dy;     // current velocity of the ship
    char symbol;    // symbol to represent the ship on the screen
} Ship;

// function to clear the screen
void clearScreen() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            screen[y][x] = ' ';
        }
    }
}

// function to draw the screen
void drawScreen() {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            putchar(screen[y][x]);
        }
        putchar('\n');
    }
}

// function to update the position of a ship
void updateShip(Ship *ship) {
    // update position based on velocity
    ship->x += ship->dx;
    ship->y += ship->dy;
    // check for collision with screen edges
    if (ship->x < 0 || ship->x >= WIDTH) {
        ship->dx *= -1;
    }
    if (ship->y < 0 || ship->y >= HEIGHT) {
        ship->dy *= -1;
    }
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    // initialize the player ship
    Ship player = {WIDTH/2, HEIGHT/2, 0, 0, '>'};
    // initialize the enemy ships
    Ship enemies[10];
    int i;
    for (i = 0; i < 10; i++) {
        enemies[i].x = rand() % WIDTH;
        enemies[i].y = rand() % HEIGHT;
        enemies[i].dx = rand() % 3 - 1;
        enemies[i].dy = rand() % 3 - 1;
        enemies[i].symbol = '*';
    }
    // main game loop
    while (1) {
        // clear the screen
        clearScreen();
        // update the player ship
        updateShip(&player);
        // draw the player ship
        screen[player.y][player.x] = player.symbol;
        // update the enemy ships
        for (i = 0; i < 10; i++) {
            updateShip(&enemies[i]);
            // draw the enemy ships
            screen[enemies[i].y][enemies[i].x] = enemies[i].symbol;
        }
        // draw the screen
        drawScreen();
        // sleep for a short time to control frame rate
        usleep(100000);
    }
    return 0;
}