//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 40
#define PLAYER_CHAR 'X'
#define ALIEN_CHAR '+'
#define MISSILE_CHAR '|'
#define ALIEN_BLOCK_SIZE 10
#define ALIEN_BLOCK_ROWS 4
#define ALIEN_BLOCK_COLS 7
#define ALIEN_BLOCK_TOP 5

// Initialize the game board
void init_board(char board[][SCREEN_WIDTH]) {
    int i, j;

    // Fill the board with spaces
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }

    // Spawn the player
    board[SCREEN_HEIGHT - 1][SCREEN_WIDTH / 2] = PLAYER_CHAR;

    // Spawn the alien block
    for (i = 0; i < ALIEN_BLOCK_ROWS; i++) {
        for (j = 0; j < ALIEN_BLOCK_COLS; j++) {
            board[ALIEN_BLOCK_TOP + i][j * ALIEN_BLOCK_SIZE] = ALIEN_CHAR;
        }
    }
}

// Draw the game board
void draw_board(char board[][SCREEN_WIDTH]) {
    int i, j;

    // Clear the screen
    system("clear");

    // Draw the board
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            putchar(board[i][j]);
        }
        putchar('\n');
    }
}

// Move the player left
void move_left(char board[][SCREEN_WIDTH]) {
    int i, j;

    // Find the player's position
    for (i = SCREEN_HEIGHT - 1; i >= 0; i--) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == PLAYER_CHAR) {
                // Remove the player from their current position
                board[i][j] = ' ';

                // Move the player left if possible
                if (j > 0) {
                    board[i][j - 1] = PLAYER_CHAR;
                }

                return;
            }
        }
    }
}

// Move the player right
void move_right(char board[][SCREEN_WIDTH]) {
    int i, j;

    // Find the player's position
    for (i = SCREEN_HEIGHT - 1; i >= 0; i--) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == PLAYER_CHAR) {
                // Remove the player from their current position
                board[i][j] = ' ';

                // Move the player right if possible
                if (j < SCREEN_WIDTH - 1) {
                    board[i][j + 1] = PLAYER_CHAR;
                }

                return;
            }
        }
    }
}

// Spawn a missile at the player's position
void fire_missile(char board[][SCREEN_WIDTH]) {
    int i, j;

    // Find the player's position
    for (i = SCREEN_HEIGHT - 1; i >= 0; i--) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == PLAYER_CHAR) {
                // Spawn a missile above the player
                board[i - 1][j] = MISSILE_CHAR;
                return;
            }
        }
    }
}

// Move a missile up the board
void update_missile(char board[][SCREEN_WIDTH], int row, int col) {
    // Remove the missile from its current position
    board[row][col] = ' ';

    // Move the missile up if possible
    if (row > 0) {
        board[row - 1][col] = MISSILE_CHAR;
    }
}

// Move all missiles up the board
void update_missiles(char board[][SCREEN_WIDTH]) {
    int i, j;

    // Find all missiles on the board
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == MISSILE_CHAR) {
                // Update the missile's position
                update_missile(board, i, j);
            }
        }
    }
}

// Spawn a missile at a random alien position
void alien_fire_missile(char board[][SCREEN_WIDTH]) {
    int i, j;

    // Find all aliens on the board
    for (i = ALIEN_BLOCK_TOP; i < ALIEN_BLOCK_TOP + ALIEN_BLOCK_ROWS; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == ALIEN_CHAR) {
                // Spawn a missile below the alien
                board[i + 1][j] = MISSILE_CHAR;
                return;
            }
        }
    }
}

// Move an alien missile down the board
void update_alien_missile(char board[][SCREEN_WIDTH], int row, int col) {
    // Remove the missile from its current position
    board[row][col] = ' ';

    // Move the missile down if possible
    if (row < SCREEN_HEIGHT - 1) {
        board[row + 1][col] = MISSILE_CHAR;
    }
}

// Move all alien missiles down the board
void update_alien_missiles(char board[][SCREEN_WIDTH]) {
    int i, j;

    // Find all alien missiles on the board
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == MISSILE_CHAR && board[i - 1][j] == ALIEN_CHAR) {
                // Update the alien missile's position
                update_alien_missile(board, i, j);
            }
        }
    }
}

// Move all aliens left or right
void update_aliens(char board[][SCREEN_WIDTH], int dir) {
    int i, j;

    // Find the leftmost and rightmost alien columns
    int leftmost = SCREEN_WIDTH, rightmost = 0;
    for (i = ALIEN_BLOCK_TOP; i < ALIEN_BLOCK_TOP + ALIEN_BLOCK_ROWS; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == ALIEN_CHAR && j < leftmost) {
                leftmost = j;
            }
            if (board[i][j] == ALIEN_CHAR && j > rightmost) {
                rightmost = j;
            }
        }
    }

    // Move all aliens left or right
    for (i = ALIEN_BLOCK_TOP; i < ALIEN_BLOCK_TOP + ALIEN_BLOCK_ROWS; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == ALIEN_CHAR) {
                // Remove the alien from its current position
                board[i][j] = ' ';

                // Move the alien left or right if possible
                if (dir == -1 && j > 0) {
                    board[i][j - 1] = ALIEN_CHAR;
                } else if (dir == 1 && j < SCREEN_WIDTH - 1) {
                    board[i][j + 1] = ALIEN_CHAR;
                }
            }
        }
    }

    // Reverse direction if the aliens hit a wall
    if (dir == -1 && leftmost == 0) {
        dir = 1;
    } else if (dir == 1 && rightmost == SCREEN_WIDTH - 1) {
        dir = -1;
    }
}

// Check for collisions between missiles and aliens
void check_collisions(char board[][SCREEN_WIDTH]) {
    int i, j;

    // Find all missiles on the board
    for (i = 0; i < SCREEN_HEIGHT; i++) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == MISSILE_CHAR) {
                // Check for collisions with aliens
                if (board[i - 1][j] == ALIEN_CHAR) {
                    // Remove the missile and the alien from the board
                    board[i][j] = ' ';
                    board[i - 1][j] = ' ';

                    // Update the score
                    printf("Alien destroyed! Score: %d\n", rand() % 100);
                }
            }
        }
    }

    // Check for collisions with the player
    for (i = SCREEN_HEIGHT - 2; i >= 0; i--) {
        for (j = 0; j < SCREEN_WIDTH; j++) {
            if (board[i][j] == PLAYER_CHAR) {
                if (board[i + 1][j] == ALIEN_CHAR || board[i + 1][j] == MISSILE_CHAR) {
                    // Game over!
                    printf("Game over! Score: %d\n", rand() % 100);
                    exit(0);
                }
            }
        }
    }
}

int main(void) {
    char board[SCREEN_HEIGHT][SCREEN_WIDTH];
    int player_dir = 0;
    int alien_dir = 1;
    int turn_count = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game board
    init_board(board);

    // Main game loop
    while (1) {
        // Draw the game board
        draw_board(board);

        // Get player input
        switch (getchar()) {
            case 'a':
                player_dir = -1;
                break;
            case 'd':
                player_dir = 1;
                break;
            case ' ':
                fire_missile(board);
                break;
        }

        // Move the player
        if (player_dir != 0) {
            move_left(board);
            move_right(board);
            player_dir = 0;
        }

        // Update the alien block
        turn_count++;
        if (turn_count % 10 == 0) {
            update_aliens(board, alien_dir);
            alien_dir *= -1;
        }

        // Update the missiles
        update_missiles(board);
        update_alien_missiles(board);

        // Check for collisions
        check_collisions(board);
    }

    return 0;
}