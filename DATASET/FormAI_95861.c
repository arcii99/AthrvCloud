//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <pthread.h>

#define BOARD_WIDTH 60
#define BOARD_HEIGHT 20
#define PADDLE_SIZE 4
#define BALL_WIDTH 1
#define BALL_HEIGHT 1

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    Point velocity;
} Ball;

typedef struct {
    Point position;
    int score;
} Player;

Ball ball;
Player player;
Player ai;

char board[BOARD_HEIGHT][BOARD_WIDTH + 1];

pthread_mutex_t ball_mutex;

void setup_board() {
    // Clear board
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
        board[i][BOARD_WIDTH] = '\0';
    }

    // Draw top and bottom borders
    for (int i = 0; i < BOARD_WIDTH; i++) {
        board[0][i] = '-';
        board[BOARD_HEIGHT - 1][i] = '-';
    }

    // Draw left and right borders
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        board[i][0] = '|';
        board[i][BOARD_WIDTH - 1] = '|';
    }

    // Draw paddles
    for (int i = 0; i < PADDLE_SIZE; i++) {
        board[player.position.y + i][1] = '#';
        board[ai.position.y + i][BOARD_WIDTH - 2] = '#';
    }

    // Draw ball
    board[ball.position.y][ball.position.x] = 'O';
}

void update_board() {
    setup_board();
    printf("%s", board);
}

void update_player_position(int y) {
    if (y < 1) {
        player.position.y = 1;
    } else if (y > BOARD_HEIGHT - PADDLE_SIZE - 1) {
        player.position.y = BOARD_HEIGHT - PADDLE_SIZE - 1;
    } else {
        player.position.y = y;
    }
}

void update_ai_position(int y) {
    if (y < 1) {
        ai.position.y = 1;
    } else if (y > BOARD_HEIGHT - PADDLE_SIZE - 1) {
        ai.position.y = BOARD_HEIGHT - PADDLE_SIZE - 1;
    } else {
        ai.position.y = y;
    }
}

void update_ball_position() {
    // Lock ball mutex
    pthread_mutex_lock(&ball_mutex);

    // Update ball position
    ball.position.x += ball.velocity.x;
    ball.position.y += ball.velocity.y;

    // Check for collision with top or bottom walls
    if (ball.position.y <= 1 || ball.position.y >= BOARD_HEIGHT - 2) {
        ball.velocity.y *= -1;
    }

    // Check for collision with left or right walls
    if (ball.position.x <= 1) {
        ai.score++;
        ball.position.x = BOARD_WIDTH / 2;
        ball.position.y = BOARD_HEIGHT / 2;
        ball.velocity.x *= -1;
        ball.velocity.y = rand() % 3 - 1;
    } else if (ball.position.x >= BOARD_WIDTH - 2) {
        player.score++;
        ball.position.x = BOARD_WIDTH / 2;
        ball.position.y = BOARD_HEIGHT / 2;
        ball.velocity.x *= -1;
        ball.velocity.y = rand() % 3 - 1;
    }

    // Check for collision with paddles
    if (ball.position.x == 2) {
        for (int i = 0; i < PADDLE_SIZE; i++) {
            if (ball.position.y == player.position.y + i) {
                ball.velocity.x *= -1;
                ball.velocity.y = rand() % 3 - 1;
                break;
            }
        }
    } else if (ball.position.x == BOARD_WIDTH - 3) {
        for (int i = 0; i < PADDLE_SIZE; i++) {
            if (ball.position.y == ai.position.y + i) {
                ball.velocity.x *= -1;
                ball.velocity.y = rand() % 3 - 1;
                break;
            }
        }
    }

    // Unlock ball mutex
    pthread_mutex_unlock(&ball_mutex);
}

void* ai_thread(void* arg) {
    while (1) {
        // Lock ball mutex
        pthread_mutex_lock(&ball_mutex);

        // Move AI towards ball
        if (ball.position.y < ai.position.y + PADDLE_SIZE / 2) {
            update_ai_position(ai.position.y - 1);
        } else if (ball.position.y > ai.position.y + PADDLE_SIZE / 2) {
            update_ai_position(ai.position.y + 1);
        }

        // Unlock ball mutex
        pthread_mutex_unlock(&ball_mutex);

        usleep(10000);
    }
}

void set_input_mode() {
    struct termios tattr;

    tcgetattr(STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

void set_blocking_mode() {
    struct termios tattr;

    tcgetattr(STDIN_FILENO, &tattr);
    tattr.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

int main() {
    // Initialize player, AI and ball
    player.position.x = 1;
    player.position.y = BOARD_HEIGHT / 2 - PADDLE_SIZE / 2;
    player.score = 0;

    ai.position.x = BOARD_WIDTH - 2;
    ai.position.y = BOARD_HEIGHT / 2 - PADDLE_SIZE / 2;
    ai.score = 0;

    ball.position.x = BOARD_WIDTH / 2;
    ball.position.y = BOARD_HEIGHT / 2;
    ball.velocity.x = rand() % 2 == 0 ? -1 : 1;
    ball.velocity.y = rand() % 3 - 1;

    // Set up board and input mode
    setup_board();
    set_input_mode();

    // Create AI thread
    pthread_t ai_tid;
    pthread_create(&ai_tid, NULL, ai_thread, NULL);

    // Main game loop
    while (1) {
        // Update board
        update_board();

        // Update ball position
        update_ball_position();

        // Check for game over
        if (player.score >= 5 || ai.score >= 5) {
            printf("\nGAME OVER\n");
            printf("Player: %d\n", player.score);
            printf("AI: %d\n", ai.score);
            break;
        }

        // Read input
        char c;
        if (read(STDIN_FILENO, &c, 1) == 1) {
            // Update player position
            if (c == 'w') {
                update_player_position(player.position.y - 1);
            } else if (c == 's') {
                update_player_position(player.position.y + 1);
            }
        }

        usleep(10000);
    }

    // Clean up and exit
    pthread_cancel(ai_tid);
    pthread_join(ai_tid, NULL);
    set_blocking_mode();
    return 0;
}