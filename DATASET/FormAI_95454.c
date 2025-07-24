//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BOARD_ROWS 10
#define BOARD_COLS 10
#define ENEMY_COUNT 10
#define BULLET_SPEED 200000
#define ENEMY_SPEED 500000

// Global variables
char board[BOARD_ROWS][BOARD_COLS];
int player_pos = BOARD_COLS / 2; // Initially at the center
int bullet_row = -1, bullet_col = -1; // Bullet not fired yet
int enemy_pos[ENEMY_COUNT][2]; // Coordinates of the enemies
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for locking shared resources

// Function to print the game board
void print_board() {
    system("clear"); // Clear the console before printing the updated board
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to update the game board
void update_board() {
    // Update player position
    board[BOARD_ROWS - 1][player_pos] = 'P';

    // Update bullet position
    if (bullet_row >= 0 && bullet_row < BOARD_ROWS) {
        board[bullet_row][bullet_col] = ' ';
        bullet_row--;
        if (bullet_row >= 0) {
            board[bullet_row][bullet_col] = '*';
        }
    }

    // Update enemy positions
    for (int i = 0; i < ENEMY_COUNT; i++) {
        board[enemy_pos[i][0]][enemy_pos[i][1]] = ' ';
        enemy_pos[i][0]++;
        if (enemy_pos[i][0] < BOARD_ROWS) {
            board[enemy_pos[i][0]][enemy_pos[i][1]] = 'E';
        } else {
            // Enemy reached the bottom, respawn at random position
            enemy_pos[i][0] = 0;
            enemy_pos[i][1] = rand() % BOARD_COLS;
        }
    }
}

// Thread function for bullet movement
void* bullet_thread_func(void* arg) {
    while (1) {
        usleep(BULLET_SPEED);
        pthread_mutex_lock(&mutex);
        if (bullet_row >= 0) {
            if (board[bullet_row][bullet_col] == '*') {
                // Bullet hit an enemy
                board[bullet_row][bullet_col] = ' ';
                bullet_row = bullet_col = -1;
            } else {
                // Move the bullet up
                update_board();
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Thread function for enemy movement
void* enemy_thread_func(void* arg) {
    while (1) {
        usleep(ENEMY_SPEED);
        pthread_mutex_lock(&mutex);
        update_board();
        // Check if any enemy reached the player's position
        for (int i = 0; i < ENEMY_COUNT; i++) {
            if (enemy_pos[i][0] == BOARD_ROWS - 1 && enemy_pos[i][1] == player_pos) {
                printf("Game over!\n");
                exit(0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    // Initialize the game board
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            board[i][j] = '-';
        }
    }

    // Initialize player position
    board[BOARD_ROWS - 1][player_pos] = 'P';

    // Initialize enemy positions
    srand(time(NULL));
    for (int i = 0; i < ENEMY_COUNT; i++) {
        enemy_pos[i][0] = rand() % BOARD_ROWS / 2; // Random row position above the player
        enemy_pos[i][1] = rand() % BOARD_COLS;
        board[enemy_pos[i][0]][enemy_pos[i][1]] = 'E';
    }

    // Create threads for bullet and enemy movement
    pthread_t bullet_thread, enemy_thread;
    pthread_create(&bullet_thread, NULL, bullet_thread_func, NULL);
    pthread_create(&enemy_thread, NULL, enemy_thread_func, NULL);

    // Main game loop
    while (1) {
        print_board();

        // Input handling
        char c = getchar();
        if (c == 'q') {
            // Quit the game
            printf("Quitting...\n");
            exit(0);
        } else if (c == 'a') {
            // Move player left
            if (player_pos > 0) {
                player_pos--;
                update_board();
            }
        } else if (c == 'd') {
            // Move player right
            if (player_pos < BOARD_COLS - 1) {
                player_pos++;
                update_board();
            }
        } else if (c == ' ') {
            // Shoot bullet
            if (bullet_row == -1) {
                bullet_row = BOARD_ROWS - 2;
                bullet_col = player_pos;
                board[bullet_row][bullet_col] = '*';
            }
        }
    }

    return 0;
}