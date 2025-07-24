//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Initializing game variables
#define ROWS 20
#define COLS 40
#define MISSILE_STEP 2
#define ENEMY_COUNT 6
#define ENEMY_STEP 1
#define BOUNDARY_LEFT 1
#define BOUNDARY_RIGHT COLS - 1
#define SCORE_STEP 10

int score = 0;
int lives = 3;

char grid[ROWS][COLS];

struct Enemy {
    int x;
    int y;
    bool active;
};

struct Enemy enemies[ENEMY_COUNT];

struct Player {
    int x;
    int y;
};

struct Missile {
    int x;
    int y;
    bool active;
};

struct Player player = {ROWS - 2, COLS / 2};
struct Missile missile = {ROWS - 3, COLS / 2};

// Function to initialize and display game grid
void initializeGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS - 1 || j == 0 || j == COLS - 1) {
                grid[i][j] = '|';
            } else {
                grid[i][j] = ' ';
            }
        }
        grid[missile.x][missile.y] = '|';
    }
    for (int k = 0; k < ENEMY_COUNT; k++) {
        grid[enemies[k].x][enemies[k].y] = '*';
    }
    grid[player.x][player.y] = 'A';
}

// Function to display the game grid
void displayGrid() {
    printf("\n\nScore: %d     Lives: %d\n\n", score, lives);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player
void movePlayer() {
    char input;
    struct termios old_settings, new_settings;

    // Turn off buffering for stdio
    tcgetattr(0, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new_settings);

    // Get input from user
    input = getchar();

    // Reset buffering for stdio
    tcsetattr(0, TCSANOW, &old_settings);

    if (input == 'a') {
        if (player.y > BOUNDARY_LEFT) {
            player.y--;
            grid[player.x][player.y + 1] = ' ';
            grid[player.x][player.y] = 'A';
        }
    } else if (input == 'd') {
        if (player.y < BOUNDARY_RIGHT) {
            player.y++;
            grid[player.x][player.y - 1] = ' ';
            grid[player.x][player.y] = 'A';
        }
    } else if (input == 'q') {
        lives = 0;
    }
}

// Function to move the missile
void moveMissile() {
    if (missile.active && missile.x > 0) {
        grid[missile.x][missile.y] = ' ';
        missile.x -= MISSILE_STEP;
        grid[missile.x][missile.y] = '|';
    } else {
        missile.active = false;
        missile.x = player.x - 1;
        missile.y = player.y;
    }
}

// Function to move the enemies
void moveEnemies() {
    for (int i = 0; i < ENEMY_COUNT; i++) {
        if (enemies[i].active) {
            grid[enemies[i].x][enemies[i].y] = ' ';
            enemies[i].x += ENEMY_STEP;
            if (enemies[i].x >= ROWS - 1) {
                enemies[i].active = false;
                lives--;
            } else {
                grid[enemies[i].x][enemies[i].y] = '*';
            }
        } else if (rand() % 6 == 0) {
            enemies[i].active = true;
            enemies[i].x = 1;
            enemies[i].y = rand() % (COLS - 2) + 1;
            grid[enemies[i].x][enemies[i].y] = '*';
        }
    }
}

// Function to detect collision between missile and enemies
void detectCollision() {
    for (int i = 0; i < ENEMY_COUNT; i++) {
        if (enemies[i].active && missile.active && missile.x == enemies[i].x && missile.y == enemies[i].y) {
            score += SCORE_STEP;
            missile.active = false;
            enemies[i].active = false;
            grid[missile.x][missile.y] = ' ';
            grid[enemies[i].x][enemies[i].y] = ' ';
        }
    }
}

// Function to run the game
void runGame() {
    while (lives > 0) {
        initializeGrid();
        displayGrid();
        movePlayer();
        moveMissile();
        moveEnemies();
        detectCollision();
        usleep(50000);
        system("clear");
    }
    printf("\n\nGAME OVER\n\n");
}

// Main function to start the game
int main() {
    runGame();
    return 0;
}