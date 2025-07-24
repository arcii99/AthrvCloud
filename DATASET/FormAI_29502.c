//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define BOARD_WIDTH 50
#define BOARD_HEIGHT 20

int score = 0;
int game_over = 0;

struct termios orig_termios, new_termios;

char board[BOARD_HEIGHT][BOARD_WIDTH];

// Initialize the board with empty spaces
void init_board() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the board to the console
void print_board() {
    printf("\033[H\033[J"); // Clear the console

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    printf("Score: %d\n", score);
}

// Set terminal to raw mode
void enable_raw_mode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_termios);
}

// Restore terminal settings
void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

// Move the player left
void move_left(int *player_pos) {
    if (*player_pos > 0) {
        *player_pos -= 1;
    }
}

// Move the player right
void move_right(int *player_pos) {
    if (*player_pos < BOARD_WIDTH - 1) {
        *player_pos += 1;
    }
}

// Update the board to move the player and the enemies
void update_board(int *player_pos, int *alien_pos) {
    // Move player
    board[BOARD_HEIGHT - 1][*player_pos] = 'X';
    board[BOARD_HEIGHT - 1][*player_pos + 1] = ' ';

    // Move alien
    board[*alien_pos][0] = ' ';
    board[*alien_pos + 1][0] = ' ';
    *alien_pos = rand() % (BOARD_HEIGHT - 3) + 1;
    board[*alien_pos][0] = 'O';
    board[*alien_pos + 1][0] = 'O';

    // Check for collision
    if (board[BOARD_HEIGHT - 2][*player_pos] == 'O' || board[BOARD_HEIGHT - 2][*player_pos + 1] == 'O') {
        game_over = 1;
    }

    // Update score
    score++;
}

int main() {
    // Set up random seed
    srand(time(NULL));

    // Set up initial variables
    int player_pos = BOARD_WIDTH / 2;
    int alien_pos = rand() % (BOARD_HEIGHT - 3) + 1;

    // Initialize board and put player and alien in initial positions
    init_board();
    board[BOARD_HEIGHT - 1][player_pos] = 'X';
    board[BOARD_HEIGHT - 1][player_pos + 1] = ' ';
    board[alien_pos][0] = 'O';
    board[alien_pos + 1][0] = 'O';

    // Set up terminal to raw mode
    enable_raw_mode();

    // Game loop
    while (!game_over) {
        // Update board
        update_board(&player_pos, &alien_pos);

        // Print board
        print_board();

        // Wait for 100 milliseconds
        usleep(100000);

        // Move player based on input
        char ch = ' ';
        if (read(STDIN_FILENO, &ch, 1) == 1) {
            if (ch == 'a') {
                move_left(&player_pos);
            } else if (ch == 'd') {
                move_right(&player_pos);
            }
        }
    }

    // Restore terminal settings
    disable_raw_mode();

    // Print game over message
    printf("Game over. Final score: %d\n", score);

    return 0;
}