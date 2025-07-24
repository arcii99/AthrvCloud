//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_BULLETS 5
#define INVADERS_ROWS 3
#define INVADERS_COLS 6
#define INVADERS_START_ROW 2
#define INVADERS_START_COL 2
#define PLAYER_START_ROW 23
#define PLAYER_START_COL 38
#define BULLET_EXPLOSION_RADIUS 2
#define INVADER_SCORE 10
#define PLAYER_SCORE -50

char screen[HEIGHT][WIDTH];
bool bullets[MAX_BULLETS]; // true if bullet is active
int bullet_positions[MAX_BULLETS]; // array of x positions of bullets
int invader_positions[INVADERS_ROWS][INVADERS_COLS]; // matrix of invader positions
int player_position; // x position of player
int score; // current game score
bool gameover; // true if game is over (either player wins or loses)

// initializes the game board
void initialize() {
    // clear screen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
    // initialize bullets
    for (int i = 0; i < MAX_BULLETS; i++) {
        bullets[i] = false;
        bullet_positions[i] = -1;
    }
    // initialize invader positions
    for (int i = 0; i < INVADERS_ROWS; i++) {
        for (int j = 0; j < INVADERS_COLS; j++) {
            invader_positions[i][j] = INVADERS_START_COL + j * 5;
        }
    }
    // initialize player position and score
    player_position = PLAYER_START_COL;
    score = 0;
    gameover = false;
}

// updates screen with current game state
void updateScreen() {
    // clear screen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
    // draw bullets
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i]) {
            screen[HEIGHT - 2][bullet_positions[i]] = '|';
        }
    }
    // draw invader positions
    for (int i = 0; i < INVADERS_ROWS; i++) {
        for (int j = 0; j < INVADERS_COLS; j++) {
            if (invader_positions[i][j] >= 0 && invader_positions[i][j] < WIDTH) {
                screen[INVADERS_START_ROW + i][invader_positions[i][j]] = 'O';
            }
        }
    }
    // draw player position
    if (player_position >= 0 && player_position < WIDTH) {
        screen[PLAYER_START_ROW][player_position] = 'V';
    }
    // draw score
    printf("Score: %d\n", score);
    // draw screen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

// updates the position of all bullets on screen
void updateBullets() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i]) {
            bullet_positions[i]++;
            if (bullet_positions[i] >= HEIGHT - 2) { // bullet hits bottom screen
                bullets[i] = false;
                bullet_positions[i] = -1;
            }
        }
    }
}

// updates the position of all invaders on screen
void updateInvaders() {
    // move invaders horizontally
    bool move_down = false;
    for (int i = 0; i < INVADERS_ROWS; i++) {
        for (int j = 0; j < INVADERS_COLS; j++) {
            if (invader_positions[i][j] >= 0 && invader_positions[i][j] < WIDTH) {
                invader_positions[i][j] += 2; // move by 2 steps
                if (invader_positions[i][j] >= WIDTH) { // invaders move down if reached right edge
                    move_down = true;
                }
            }
        }
    }
    // move invaders down if necessary
    if (move_down) {
        for (int i = 0; i < INVADERS_ROWS; i++) {
            for (int j = 0; j < INVADERS_COLS; j++) {
                if (invader_positions[i][j] >= 0 && invader_positions[i][j] < WIDTH) {
                    invader_positions[i][j] += INVADERS_COLS * 2; // move down by 2 * number of columns
                }
            }
        }
    }
}

// updates player position based on user input
void updatePlayer() {
    char input = getchar();
    if (input == 'a' && player_position > 0) { // move left
        player_position--;
    } else if (input == 'd' && player_position < WIDTH - 1) { // move right
        player_position++;
    } else if (input == 's') { // shoot bullet
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i]) { // find available bullet slot
                bullets[i] = true;
                bullet_positions[i] = player_position;
                break;
            }
        }
    }
}

// checks if bullet hits any invader, and removes both if so
void handleBulletInvaderCollision() {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (bullets[i]) {
            for (int j = 0; j < INVADERS_ROWS; j++) {
                for (int k = 0; k < INVADERS_COLS; k++) {
                    int invader_x = invader_positions[j][k];
                    int invader_y = INVADERS_START_ROW + j;
                    int bullet_x = bullet_positions[i];
                    int bullet_y = HEIGHT - 2;
                    if (invader_x >= 0 && invader_x < WIDTH && invader_y >= 0 && invader_y < HEIGHT &&
                        bullet_x >= invader_x - BULLET_EXPLOSION_RADIUS && bullet_x <= invader_x + BULLET_EXPLOSION_RADIUS &&
                        bullet_y >= invader_y - BULLET_EXPLOSION_RADIUS && bullet_y <= invader_y + BULLET_EXPLOSION_RADIUS) {
                        bullets[i] = false;
                        bullet_positions[i] = -1;
                        invader_positions[j][k] = -1;
                        score += INVADER_SCORE;
                    }
                }
            }
        }
    }
}

// checks if any invader reaches the player's position, and ends the game if so
void handleInvaderPlayerCollision() {
    for (int i = 0; i < INVADERS_ROWS; i++) {
        for (int j = 0; j < INVADERS_COLS; j++) {
            int invader_x = invader_positions[i][j];
            int invader_y = INVADERS_START_ROW + i;
            if (invader_x >= 0 && invader_x < WIDTH &&
                invader_y >= PLAYER_START_ROW - BULLET_EXPLOSION_RADIUS && invader_y <= PLAYER_START_ROW + BULLET_EXPLOSION_RADIUS &&
                !gameover) {
                gameover = true;
                printf("You lose!\n");
                score += PLAYER_SCORE;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    initialize();
    while (!gameover) {
        updateScreen();
        updateBullets();
        updateInvaders();
        updatePlayer();
        handleBulletInvaderCollision();
        handleInvaderPlayerCollision();
        usleep(50000); // sleep for 50ms to control game speed
    }
    printf("Final score: %d\n", score);
    return 0;
}