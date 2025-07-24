//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define BOARD_WIDTH 70 // Width of the game board
#define BOARD_HEIGHT 20 // Height of the game board
#define BALL_SYMBOL 'o' // Symbol used to represent the ball
#define PADDLE_SYMBOL '|' // Symbol used to represent the paddle
#define AI_SPEED 2 // Speed of the AI paddle

int kbhit(void); // Function to check if keyboard key was hit

int main() {
    int x = BOARD_WIDTH / 2; // Initial ball x-coordinate
    int y = BOARD_HEIGHT / 2; // Initial ball y-coordinate
    int ball_x_speed = 1; // Initial ball x-speed
    int ball_y_speed = 1; // Initial ball y-speed
    int ai_paddle_pos = BOARD_HEIGHT / 2; // Initial AI paddle position
    int prev_ai_paddle_pos = ai_paddle_pos; // Used to erase previous AI paddle position
    int user_score = 0; // User score
    int ai_score = 0; // AI score
    char board[BOARD_HEIGHT][BOARD_WIDTH]; // Game board

    // Initialize game board
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (j == 0 || j == BOARD_WIDTH - 1) {
                board[i][j] = '|';
            } else if (i == y && j == x) {
                board[i][j] = BALL_SYMBOL;
            } else if (i == ai_paddle_pos) {
                board[i][j] = PADDLE_SYMBOL;
            } else {
                board[i][j] = ' ';
            }
        }
    }

    // Game loop
    while (user_score < 10 && ai_score < 10) {
        // Clear screen and print game board
        system("clear");
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            printf("%s\n", board[i]);
        }

        // Move ball
        x += ball_x_speed;
        y += ball_y_speed;

        // Check if ball hit top or bottom of board
        if (y == 0 || y == BOARD_HEIGHT - 1) {
            ball_y_speed *= -1;
        }

        // Check if ball hit AI paddle
        if (x == 2 && y >= ai_paddle_pos && y <= ai_paddle_pos + 2) {
            ball_x_speed *= -1;
        }

        // Check if ball hit left or right of board
        if (x == 0) {
            ai_score++;
            // Reset ball position and speed
            x = BOARD_WIDTH / 2;
            y = BOARD_HEIGHT / 2;
            ball_x_speed = 1;
            ball_y_speed = 1;
            // Update user score
            printf("AI scored!\n");
            printf("User: %d | AI: %d\n", user_score, ai_score);
            // Wait for input before continuing game
            getchar();
        } else if (x == BOARD_WIDTH - 1) {
            user_score++;
            // Reset ball position and speed
            x = BOARD_WIDTH / 2;
            y = BOARD_HEIGHT / 2;
            ball_x_speed = -1;
            ball_y_speed = -1;
            // Update user score
            printf("You scored!\n");
            printf("User: %d | AI: %d\n", user_score, ai_score);
            // Wait for input before continuing game
            getchar();
        }

        // Update AI paddle position
        if (prev_ai_paddle_pos < y) {
            ai_paddle_pos += AI_SPEED;
        } else if (prev_ai_paddle_pos > y) {
            ai_paddle_pos -= AI_SPEED;
        }
        prev_ai_paddle_pos = ai_paddle_pos;

        // Check if AI paddle goes out of bounds
        if (ai_paddle_pos < 0) {
            ai_paddle_pos = 0;
        } else if (ai_paddle_pos > BOARD_HEIGHT - 3) {
            ai_paddle_pos = BOARD_HEIGHT - 3;
        }

        // Update game board
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                if (j == 0 || j == BOARD_WIDTH - 1) {
                    board[i][j] = '|';
                } else if (i == y && j == x) {
                    board[i][j] = BALL_SYMBOL;
                } else if (i >= ai_paddle_pos && i <= ai_paddle_pos + 2 && j == 2) {
                    board[i][j] = PADDLE_SYMBOL;
                } else {
                    board[i][j] = ' ';
                }
            }
        }

        // Wait for 100000 microseconds (0.1 seconds)
        usleep(100000);

        // Check if user hits keyboard key and move paddle accordingly
        if (kbhit()) {
            char c = getchar();
            if (c == 'w' && prev_ai_paddle_pos != 0) {
                ai_paddle_pos -= AI_SPEED;
            } else if (c == 's' && prev_ai_paddle_pos != BOARD_HEIGHT - 3) {
                ai_paddle_pos += AI_SPEED;
            }
            prev_ai_paddle_pos = ai_paddle_pos;
        }
    }

    // Print final scores
    printf("Game over!\n");
    printf("Final score: User: %d | AI: %d\n", user_score, ai_score);

    return 0;
}

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}