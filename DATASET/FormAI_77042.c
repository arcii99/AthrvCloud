//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game board dimensions
#define BOARD_WIDTH 30
#define BOARD_HEIGHT 30

// Spaceship dimensions
#define SHIP_WIDTH 5
#define SHIP_HEIGHT 3

// Alien dimensions
#define ALIEN_WIDTH 3
#define ALIEN_HEIGHT 2

// Projectile dimensions
#define PROJECTILE_WIDTH 1
#define PROJECTILE_HEIGHT 1

// Game board
char board[BOARD_HEIGHT][BOARD_WIDTH];

// Spaceship position
int ship_x = BOARD_WIDTH / 2 - SHIP_WIDTH / 2;
int ship_y = BOARD_HEIGHT - SHIP_HEIGHT - 1;

// Alien position
int alien_x = BOARD_WIDTH / 2 - ALIEN_WIDTH / 2;
int alien_y = 1;

// Projectile flag
int projectile_active = 0;

// Projectile position
int projectile_x;
int projectile_y;

// Initialize the game board
void init_board() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
}

// Draw the game board
void draw_board() {
    system("clear"); // This line is system-specific, may need to be changed
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Draw the spaceship
void draw_ship() {
    for (int i = 0; i < SHIP_HEIGHT; i++) {
        for (int j = 0; j < SHIP_WIDTH; j++) {
            board[ship_y+i][ship_x+j] = '#';
        }
    }
}

// Draw the alien
void draw_alien() {
    for (int i = 0; i < ALIEN_HEIGHT; i++) {
        for (int j = 0; j < ALIEN_WIDTH; j++) {
            board[alien_y+i][alien_x+j] = '@';
        }
    }
}

// Move the spaceship left
void move_ship_left() {
    if (ship_x > 0) {
        ship_x--;
    }
}

// Move the spaceship right
void move_ship_right() {
    if (ship_x < BOARD_WIDTH - SHIP_WIDTH) {
        ship_x++;
    }
}

// Fire the projectile
void fire_projectile() {
    if (!projectile_active) { // Only one projectile at a time
        projectile_active = 1;
        projectile_x = ship_x + SHIP_WIDTH / 2;
        projectile_y = ship_y - PROJECTILE_HEIGHT;
    }
}

// Update the projectile
void update_projectile() {
    if (projectile_active) {
        projectile_y--;
        if (projectile_y < 0) {
            projectile_active = 0;
        }
        else if (alien_x <= projectile_x && projectile_x < alien_x + ALIEN_WIDTH && alien_y <= projectile_y && projectile_y < alien_y + ALIEN_HEIGHT) {
            projectile_active = 0;
            alien_x = rand() % (BOARD_WIDTH - ALIEN_WIDTH); // Respawn the alien
            alien_y = 1;
        }
    }
}

// Draw the projectile
void draw_projectile() {
    if (projectile_active) {
        board[projectile_y][projectile_x] = '|';
    }
}

int main() {
    srand(time(NULL)); // Initialize random number generator
    init_board(); // Initialize the game board

    while (1) { // Main game loop
        draw_board(); // Draw the game board
        draw_ship(); // Draw the spaceship
        draw_alien(); // Draw the alien
        draw_projectile(); // Draw the projectile

        // Handle user input
        switch (getchar()) {
            case 'a':
                move_ship_left();
                break;
            case 'd':
                move_ship_right();
                break;
            case ' ':
                fire_projectile();
                break;
        }

        update_projectile(); // Move and update the projectile

        // Move the alien
        if (rand() % 2 == 0) {
            if (alien_x > 0) {
                alien_x--;
            }
        }
        else {
            if (alien_x < BOARD_WIDTH - ALIEN_WIDTH){
                alien_x++;
            }
        }
        alien_y++;

        // Check for collision with the spaceship
        if (alien_x <= ship_x + SHIP_WIDTH - 1 && ship_x <= alien_x + ALIEN_WIDTH - 1 && alien_y <= ship_y + SHIP_HEIGHT - 1 && ship_y <= alien_y + ALIEN_HEIGHT - 1) {
            printf("Game over!\n");
            exit(0);
        }

        usleep(100000); // Sleep for 100 ms
    }

    return 0;
}