//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the game board size
#define BOARD_WIDTH 60
#define BOARD_HEIGHT 20

// Define the board and ball characters
#define BALL_SYMBOL 'O'
#define PADDLE_SYMBOL '|'
#define EMPTY_SYMBOL ' '

// Define the ball struct
typedef struct {
    int x;
    int y;
    int dx;
    int dy;
} Ball;

// Define the paddle struct
typedef struct {
    int x;
    int y;
} Paddle;

// Define the AI opponent struct
typedef struct {
    int x;
    int y;
} AI;

// Function to print the game board
void printBoard(char board[][BOARD_WIDTH+1], Ball ball, Paddle player, AI opponent) {
    int i;
    int j;

    // Print top border
    for (i = 0; i < BOARD_WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // Print game board
    for (i = 0; i < BOARD_HEIGHT; i++) {
        printf("#");
        for (j = 0; j < BOARD_WIDTH; j++) {
            // Print ball or paddle
            if (i == ball.y && j == ball.x) {
                printf("%c", BALL_SYMBOL);
            } else if (i == player.y && j == player.x) {
                printf("%c", PADDLE_SYMBOL);
            } else if (i == opponent.y && j == opponent.x) {
                printf("%c", PADDLE_SYMBOL);
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("#\n");
    }

    // Print bottom border
    for (i = 0; i < BOARD_WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
}

// Function to update the ball position and direction
void updateBall(Ball *ball, Paddle player, AI opponent) {
    // Update ball position
    ball->x += ball->dx;
    ball->y += ball->dy;

    // Check for collision with walls
    if (ball->x == 0 || ball->x == BOARD_WIDTH - 1) {
        ball->dx *= -1;
    }
    if (ball->y == 0 || ball->y == BOARD_HEIGHT - 1) {
        ball->dy *= -1;
    }

    // Check for collision with paddles
    if (ball->y == player.y && ball->x == player.x + 1) {
        ball->dx *= -1;
    }
    if (ball->y == opponent.y && ball->x == opponent.x - 1) {
        ball->dx *= -1;
    }
}

// Function to update the opponent paddle position
void updateOpponent(AI *opponent, Ball ball) {
    if (opponent->y > ball.y) {
        opponent->y--;
    }
    if (opponent->y < ball.y) {
        opponent->y++;
    }
}

int main() {
    // Initialize the game board
    char board[BOARD_HEIGHT][BOARD_WIDTH+1];
    int i;
    int j;
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = EMPTY_SYMBOL;
        }
        board[i][BOARD_WIDTH] = '\0';
    }

    // Initialize the ball and paddles
    Ball ball = {BOARD_WIDTH / 2, BOARD_HEIGHT / 2, -1, -1};
    Paddle player = {0, BOARD_HEIGHT / 2};
    AI opponent = {BOARD_WIDTH - 1, BOARD_HEIGHT / 2};

    // Set seed for random number generation
    srand(time(NULL));

    // Infinite game loop
    while (true) {
        // Clear the terminal
        system("clear");

        // Print the game board
        printBoard(board, ball, player, opponent);

        // Check for player input and update the player paddle position
        if (getchar() == 'w') {
            player.y--;
        } else if (getchar() == 's') {
            player.y++;
        }

        // Update the opponent AI paddle position
        updateOpponent(&opponent, ball);

        // Update the ball position and direction
        updateBall(&ball, player, opponent);

        // Pause the game for 100000 microseconds to slow down the ball movement
        usleep(100000);
    }

    return 0;
}