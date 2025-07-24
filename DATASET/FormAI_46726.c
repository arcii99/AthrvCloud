//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

// Define the board and ball variables
char board[BOARD_WIDTH][BOARD_HEIGHT];
int ball_x, ball_y;
int ball_x_speed, ball_y_speed;
int paddle_a_y, paddle_b_y;
bool playing;
bool ai_enabled;

// Initialize the board
void init_board() {
    // Set all board elements to empty spaces
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            board[i][j] = ' ';
        }
    }
    // Set the left and right borders
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        board[0][i] = '|';
        board[BOARD_WIDTH - 1][i] = '|';
    }
    // Set the top and bottom borders
    for (int i = 0; i < BOARD_WIDTH; i++) {
        board[i][0] = '-';
        board[i][BOARD_HEIGHT - 1] = '-';
    }
    // Set the paddles in their initial positions
    paddle_a_y = BOARD_HEIGHT / 2 - 1;
    paddle_b_y = BOARD_HEIGHT / 2 - 1;
    for (int i = 0; i < 2; i++) {
        board[1][paddle_a_y + i] = '|';
        board[BOARD_WIDTH - 2][paddle_b_y + i] = '|';
    }
    // Set the ball in the center of the board
    ball_x = BOARD_WIDTH / 2;
    ball_y = BOARD_HEIGHT / 2;
    board[ball_x][ball_y] = 'O';
    // Set the ball's initial speed and direction
    srand(time(0));
    ball_x_speed = rand() % 2 == 0 ? -1 : 1;
    ball_y_speed = rand() % 3 - 1;
}

// Move the ball
void move_ball() {
    // Remove the ball from its current position
    board[ball_x][ball_y] = ' ';
    // Move the ball to its new position
    ball_x += ball_x_speed;
    ball_y += ball_y_speed;
    // Bounce the ball if it hits a top or bottom border
    if (ball_y == 0 || ball_y == BOARD_HEIGHT - 1) {
        ball_y_speed *= -1;
    }
    // Check if the ball hits one of the paddles
    if (ball_x == 2 && (ball_y == paddle_a_y || ball_y == paddle_a_y + 1)) {
        ball_x_speed *= -1;
    }
    if (ball_x == BOARD_WIDTH - 3 && (ball_y == paddle_b_y || ball_y == paddle_b_y + 1)) {
        ball_x_speed *= -1;
    }
    // If the ball goes off the left or right edge of the board
    if (ball_x == 0 || ball_x == BOARD_WIDTH - 1) {
        playing = false;
    }
    // Add the ball to its new position
    board[ball_x][ball_y] = 'O';
}

// Move the player's paddle
void move_paddle(int direction) {
    // Remove the paddle from its current position
    for (int i = 0; i < 2; i++) {
        board[1][paddle_a_y + i] = ' ';
        board[BOARD_WIDTH - 2][paddle_b_y + i] = ' ';
    }
    // Move the paddle up or down
    if (direction == -1 && paddle_a_y > 1) {
        paddle_a_y--;
    }
    if (direction == 1 && paddle_a_y < BOARD_HEIGHT - 3) {
        paddle_a_y++;
    }
    // Add the paddle to its new position
    for (int i = 0; i < 2; i++) {
        board[1][paddle_a_y + i] = '|';
        board[BOARD_WIDTH - 2][paddle_b_y + i] = '|';
    }
}

// Move the AI paddle
void move_ai_paddle() {
    int target_y = ball_y - 1;
    if (paddle_b_y + 1 < target_y) {
        move_paddle(1);
    } else if (paddle_b_y > target_y) {
        move_paddle(-1);
    }
}

// Get the user's input
int get_user_input() {
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    int input = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return input;
}

// Main function
int main() {
    // Set up the board and ball
    init_board();
    // Set the game to be playing
    playing = true;
    // Enable AI by default
    ai_enabled = true;
    // Game loop
    while (playing) {
        // Move the ball
        move_ball();
        // If AI is enabled, move the AI paddle
        if (ai_enabled) {
            move_ai_paddle();
        }
        // Draw the board
        printf("\033[2J");
        printf("\033[%d;%dH", 0, 0);
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            for (int i = 0; i < BOARD_WIDTH; i++) {
                putchar(board[i][j]);
            }
            putchar('\n');
        }
        // Get the user's input
        int input = get_user_input();
        // Move the player's paddle
        if (input == 'w') {
            move_paddle(-1);
        } else if (input == 's') {
            move_paddle(1);
        }
    }
    // Game over
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
    printf("Game Over!\n");
    return 0;
}