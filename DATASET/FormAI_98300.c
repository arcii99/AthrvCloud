//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define ROWS 20
#define COLS 60
#define PADDLE_HEIGHT 4

#define UP 'w'
#define DOWN 's'
#define BALL_SPEED 200000

struct AI {
    int y; // y-coordinate of the AI's paddle
    int direction; // direction to move the paddle
};

struct Paddle {
    int x; // x-coordinate of the paddle
    int y; // y-coordinate of the paddle
};

struct Ball {
    int x; // x-coordinate of the ball
    int y; // y-coordinate of the ball
    int dx; // direction of the ball along the x-axis
    int dy; // direction of the ball along the y-axis
};

void print_board(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void init_board(char board[][COLS], struct Paddle *player, struct AI *ai, struct Ball *ball)
{
    // Initialize the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j == 0 || j == COLS - 1) {
                board[i][j] = '|';
            }
            else {
                board[i][j] = ' ';
            }
        }
    }

    // Initialize the player's paddle
    player->x = 2;
    player->y = ROWS / 2 - PADDLE_HEIGHT / 2;
    for (int i = player->y; i < player->y + PADDLE_HEIGHT; i++) {
        board[i][player->x] = '|';
        board[i][player->x + 1] = '|';
    }

    // Initialize the AI's paddle
    ai->y = ROWS / 2 - PADDLE_HEIGHT / 2;
    ai->direction = 0;
    for (int i = ai->y; i < ai->y + PADDLE_HEIGHT; i++) {
        board[i][COLS - 2] = '|';
        board[i][COLS - 3] = '|';
    }

    // Initialize the ball
    ball->x = COLS / 2;
    ball->y = ROWS / 2;
    int sign = rand() % 2 ? -1 : 1;
    ball->dx = sign;
    ball->dy = sign;
    board[ball->y][ball->x] = 'o';
}

void move_player(char board[][COLS], struct Paddle *player, char input)
{
    if (input == UP && player->y >= 1) {
        // Clear the paddle's previous position
        for (int i = player->y; i < player->y + PADDLE_HEIGHT; i++) {
            board[i][player->x] = ' ';
            board[i][player->x + 1] = ' ';
        }
        // Move the paddle up
        player->y--;
        // Draw the paddle in its new position
        for (int i = player->y; i < player->y + PADDLE_HEIGHT; i++) {
            board[i][player->x] = '|';
            board[i][player->x + 1] = '|';
        }
    }
    else if (input == DOWN && player->y + PADDLE_HEIGHT <= ROWS - 2) {
        // Clear the paddle's previous position
        for (int i = player->y; i < player->y + PADDLE_HEIGHT; i++) {
            board[i][player->x] = ' ';
            board[i][player->x + 1] = ' ';
        }
        // Move the paddle down
        player->y++;
        // Draw the paddle in its new position
        for (int i = player->y; i < player->y + PADDLE_HEIGHT; i++) {
            board[i][player->x] = '|';
            board[i][player->x + 1] = '|';
        }
    }
}

void move_ball(char board[][COLS], struct Ball *ball, struct Paddle *player, struct AI *ai)
{
    // Clear the ball's previous position
    board[ball->y][ball->x] = ' ';

    // Move the ball
    ball->x += ball->dx;
    ball->y += ball->dy;

    // Check for collision with walls
    if (ball->y == 0 || ball->y == ROWS - 1) {
        ball->dy = -ball->dy;
    }
    if (ball->x == 0) {
        printf("Game Over: You lose!\n");
        exit(0);
    }
    if (ball->x == COLS - 1) {
        printf("Game Over: You win!\n");
        exit(0);
    }

    // Check for collision with player's paddle
    if (ball->x == player->x + 2 && ball->y >= player->y && ball->y < player->y + PADDLE_HEIGHT) {
        ball->dx = -ball->dx;
    }
    // Check for collision with AI's paddle
    if (ball->x == COLS - 3 && ball->y >= ai->y && ball->y < ai->y + PADDLE_HEIGHT) {
        ball->dx = -ball->dx;
    }

    // Draw the ball in its new position
    board[ball->y][ball->x] = 'o';
}

void move_ai(char board[][COLS], struct AI *ai, struct Ball *ball)
{
    // Clear the paddle's previous position
    for (int i = ai->y; i < ai->y + PADDLE_HEIGHT; i++) {
        board[i][COLS - 2] = ' ';
        board[i][COLS - 3] = ' ';
    }

    // Update the AI's direction
    if (ball->y < ai->y + PADDLE_HEIGHT / 2) {
        ai->direction = -1;
    }
    else if (ball->y > ai->y + PADDLE_HEIGHT / 2) {
        ai->direction = 1;
    }
    else {
        ai->direction = 0;
    }

    // Move the paddle
    ai->y += ai->direction;

    // Draw the paddle in its new position
    for (int i = ai->y; i < ai->y + PADDLE_HEIGHT; i++) {
        board[i][COLS - 2] = '|';
        board[i][COLS - 3] = '|';
    }
}

int main()
{
    srand(time(NULL));

    char board[ROWS][COLS];
    struct Paddle player;
    struct AI ai;
    struct Ball ball;
    init_board(board, &player, &ai, &ball);

    // Set terminal attributes for non-blocking I/O
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    // Main game loop
    while (true) {
        print_board(board);
        usleep(BALL_SPEED);
        // Read user input (non-blocking)
        char input;
        read(STDIN_FILENO, &input, 1);
        if (input == UP || input == DOWN) {
            move_player(board, &player, input);
        }
        move_ball(board, &ball, &player, &ai);
        move_ai(board, &ai, &ball);
        // Check for collision with AI's paddle
        if (ball.x == COLS - 3 && (ball.y < ai.y || ball.y >= ai.y + PADDLE_HEIGHT)) {
            printf("Game Over: You lose!\n");
            break;
        }
    }

    // Reset terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, ~O_NONBLOCK);

    return 0;
}