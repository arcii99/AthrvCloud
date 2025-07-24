//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants for game board
#define BOARD_WIDTH 20
#define BOARD_HEIGHT 20

// Constants for player ship
#define PLAYER_WIDTH 3
#define PLAYER_HEIGHT 2
#define PLAYER_START_X 9
#define PLAYER_START_Y 18

// Constants for enemy ships
#define ENEMY_ROWS 5
#define ENEMY_COLS 10
#define ENEMY_WIDTH 2
#define ENEMY_HEIGHT 2
#define ENEMY_SPACING 2

// Constants for bullets
#define PLAYER_BULLET_SPEED 1
#define ENEMY_BULLET_SPEED 1
#define BULLET_WIDTH 1
#define BULLET_HEIGHT 1

// Game board and player variables
char board[BOARD_HEIGHT][BOARD_WIDTH];
int player_x = PLAYER_START_X;
int player_y = PLAYER_START_Y;
int player_alive = 1;

// Enemy and bullet variables
int enemy_x[ENEMY_ROWS][ENEMY_COLS];
int enemy_y[ENEMY_ROWS][ENEMY_COLS];
int enemy_alive[ENEMY_ROWS][ENEMY_COLS];
int enemy_direction = 1;    // 1 = right, -1 = left
int player_bullets_x[BOARD_HEIGHT];
int player_bullets_y[BOARD_HEIGHT];
int player_bullets_alive[BOARD_HEIGHT];
int enemy_bullets_x[BOARD_HEIGHT];
int enemy_bullets_y[BOARD_HEIGHT];
int enemy_bullets_alive[BOARD_HEIGHT];
int num_player_bullets = 0;
int num_enemy_bullets = 0;
int player_score = 0;

// Function to draw game board
void draw_board() {
    int i, j;
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            if (i == player_y && j >= player_x && j < player_x + PLAYER_WIDTH) {
                board[i][j] = 'A';  // Player ship
            } else if (i < ENEMY_ROWS * ENEMY_HEIGHT && j < ENEMY_COLS * (ENEMY_WIDTH + ENEMY_SPACING)) {
                int row = i / ENEMY_HEIGHT;
                int col = j / (ENEMY_WIDTH + ENEMY_SPACING);
                if (enemy_alive[row][col]) {
                    if (i % ENEMY_HEIGHT == 0 && j % (ENEMY_WIDTH + ENEMY_SPACING) == 0) {
                        board[i][j] = '+';  // Top left corner
                    } else if (i % ENEMY_HEIGHT == 0 && j % (ENEMY_WIDTH + ENEMY_SPACING) == ENEMY_WIDTH - 1) {
                        board[i][j] = '+';  // Top right corner
                    } else if (i % ENEMY_HEIGHT == ENEMY_HEIGHT - 1 && j % (ENEMY_WIDTH + ENEMY_SPACING) == 0) {
                        board[i][j] = '+';  // Bottom left corner
                    } else if (i % ENEMY_HEIGHT == ENEMY_HEIGHT - 1 && j % (ENEMY_WIDTH + ENEMY_SPACING) == ENEMY_WIDTH - 1) {
                        board[i][j] = '+';  // Bottom right corner
                    } else if (i % ENEMY_HEIGHT == 0 || i % ENEMY_HEIGHT == ENEMY_HEIGHT - 1) {
                        board[i][j] = '-';  // Horizontal line
                    } else if (j % (ENEMY_WIDTH + ENEMY_SPACING) == 0 || j % (ENEMY_WIDTH + ENEMY_SPACING) == ENEMY_WIDTH - 1) {
                        board[i][j] = '|';  // Vertical line
                    } else {
                        board[i][j] = 'O';  // Enemy ship
                    }
                }
            } else if (num_player_bullets > 0) {
                int k;
                for (k = 0; k < num_player_bullets; k++) {
                    if (player_bullets_alive[k] && i == player_bullets_y[k] && j == player_bullets_x[k]) {
                        board[i][j] = '*';  // Player bullet
                    }
                }
            } else if (num_enemy_bullets > 0) {
                int k;
                for (k = 0; k < num_enemy_bullets; k++) {
                    if (enemy_bullets_alive[k] && i == enemy_bullets_y[k] && j == enemy_bullets_x[k]) {
                        board[i][j] = '*';  // Enemy bullet
                    }
                }
            } else {
                board[i][j] = ' ';  // Empty space
            }
        }
    }
}

// Function to move player ship
void move_player(char direction) {
    if (direction == 'L' && player_x > 0) {
        player_x--;
    } else if (direction == 'R' && player_x < BOARD_WIDTH - PLAYER_WIDTH) {
        player_x++;
    }
}

// Function to move enemy ships
void move_enemies() {
    int i, j;
    for (i = 0; i < ENEMY_ROWS; i++) {
        for (j = 0; j < ENEMY_COLS; j++) {
            if (enemy_alive[i][j]) {
                if (enemy_x[i][j] + ENEMY_WIDTH >= BOARD_WIDTH) {
                    enemy_direction = -1;   // Change direction
                    break;
                } else if (enemy_x[i][j] <= 0) {
                    enemy_direction = 1;    // Change direction
                    break;
                }
            }
        }
    }
    for (i = 0; i < ENEMY_ROWS; i++) {
        for (j = 0; j < ENEMY_COLS; j++) {
            if (enemy_alive[i][j]) {
                enemy_x[i][j] += enemy_direction;
                enemy_y[i][j]++;
                if (enemy_y[i][j] == player_y && enemy_x[i][j] >= player_x && enemy_x[i][j] < player_x + PLAYER_WIDTH) {
                    player_alive = 0;   // Game over
                }
            }
        }
    }
}

// Function to fire player bullet
void fire_player_bullet() {
    if (num_player_bullets < BOARD_HEIGHT) {
        player_bullets_x[num_player_bullets] = player_x + PLAYER_WIDTH / 2;
        player_bullets_y[num_player_bullets] = player_y - 1;
        player_bullets_alive[num_player_bullets] = 1;
        num_player_bullets++;
    }
}

// Function to fire enemy bullet
void fire_enemy_bullet() {
    if (num_enemy_bullets < BOARD_HEIGHT) {
        int row = ENEMY_ROWS - 1;
        int col = rand() % ENEMY_COLS;
        while (!enemy_alive[row][col]) {
            row--;
        }
        enemy_bullets_x[num_enemy_bullets] = enemy_x[row][col] + ENEMY_WIDTH / 2;
        enemy_bullets_y[num_enemy_bullets] = enemy_y[row][col] + ENEMY_HEIGHT;
        enemy_bullets_alive[num_enemy_bullets] = 1;
        num_enemy_bullets++;
    }
}

// Function to move bullets
void move_bullets() {
    int i;
    for (i = 0; i < num_player_bullets; i++) {
        if (player_bullets_alive[i]) {
            player_bullets_y[i] -= PLAYER_BULLET_SPEED;
            if (player_bullets_y[i] <= 0) {
                player_bullets_alive[i] = 0;
            }
        }
    }
    for (i = 0; i < num_enemy_bullets; i++) {
        if (enemy_bullets_alive[i]) {
            enemy_bullets_y[i] += ENEMY_BULLET_SPEED;
            if (enemy_bullets_y[i] >= BOARD_HEIGHT - 1) {
                enemy_bullets_alive[i] = 0;
            }
        }
    }
}

// Function to detect collisions
void detect_collisions() {
    int i, j, k;
    for (i = 0; i < ENEMY_ROWS; i++) {
        for (j = 0; j < ENEMY_COLS; j++) {
            if (enemy_alive[i][j]) {
                for (k = 0; k < num_player_bullets; k++) {
                    if (player_bullets_alive[k] && player_bullets_x[k] >= enemy_x[i][j] && player_bullets_x[k] < enemy_x[i][j] + ENEMY_WIDTH && player_bullets_y[k] == enemy_y[i][j]) {
                        enemy_alive[i][j] = 0;
                        player_bullets_alive[k] = 0;
                        player_score++;
                    }
                }
            }
        }
    }
    for (i = 0; i < num_enemy_bullets; i++) {
        if (enemy_bullets_alive[i] && enemy_bullets_x[i] >= player_x && enemy_bullets_x[i] < player_x + PLAYER_WIDTH && enemy_bullets_y[i] == player_y) {
            player_alive = 0;   // Game over
        }
    }
}

// Function to check game over
int check_game_over() {
    int i, j;
    for (i = 0; i < ENEMY_ROWS; i++) {
        for (j = 0; j < ENEMY_COLS; j++) {
            if (enemy_alive[i][j]) {
                if (enemy_y[i][j] == BOARD_HEIGHT - 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int i, j;
    // Initialize game board
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
    // Initialize enemy ships
    for (i = 0; i < ENEMY_ROWS; i++) {
        for (j = 0; j < ENEMY_COLS; j++) {
            enemy_x[i][j] = j * (ENEMY_WIDTH + ENEMY_SPACING);
            enemy_y[i][j] = i * (ENEMY_HEIGHT + ENEMY_SPACING);
            enemy_alive[i][j] = 1;
        }
    }
    // Main game loop
    while (player_alive && !check_game_over()) {
        // Clear screen
        system("clear");
        // Draw game board
        draw_board();
        // Print game board
        for (i = 0; i < BOARD_HEIGHT; i++) {
            for (j = 0; j < BOARD_WIDTH; j++) {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
        // Wait for input
        char input = ' ';
        read(STDIN_FILENO, &input, 1);
        if (input == 'q') {
            break;
        } else if (input == 'a' || input == 'd') {
            move_player(input);
        } else if (input == ' ') {
            fire_player_bullet();
        }
        // Move enemies
        move_enemies();
        // Fire enemy bullet
        if (rand() % 50 == 0) {
            fire_enemy_bullet();
        }
        // Move bullets
        move_bullets();
        // Detect collisions
        detect_collisions();
        // Sleep for a short time
        usleep(30000);
    }
    // Game over
    system("clear");
    printf("GAME OVER\n");
    printf("Your score: %d\n", player_score);
    return 0;
}