//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the game board size
#define ROWS 10
#define COLS 20

// define the paddle size
#define PADDLE_SIZE 4

// define the starting positions of the ball and paddle
#define BALL_X_START 10
#define BALL_Y_START 5
#define PADDLE_X_START 8
#define PADDLE_Y_START 9

// define the ball speed
#define BALL_SPEED 1

// define the paddle movement speed and directions
#define PADDLE_SPEED 1
#define LEFT -1
#define RIGHT 1

// define the brick layout
#define NUM_BRICKS 50
#define BRICK_ROWS 5
#define BRICK_COLS 10
#define BRICK_WIDTH 2
#define BRICK_HEIGHT 1

// define colors for printing to console
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[1;33m"

// function declarations
void clear_screen();
void print_board(int ball_x, int ball_y, int paddle_x, int paddle_y, int bricks[][BRICK_COLS]);
int move_ball(int ball_x, int ball_y, int dx, int dy, int bricks[][BRICK_COLS]);
int move_paddle(int paddle_x, int paddle_y, int direction);
int detect_collision(int ball_x, int ball_y, int dx, int dy, int paddle_x, int paddle_y);
void initialize_bricks(int bricks[][BRICK_COLS]);

int main() {
    // seed the random number generator
    srand(time(NULL));

    // initialize game variables
    int ball_x = BALL_X_START, ball_y = BALL_Y_START;
    int paddle_x = PADDLE_X_START, paddle_y = PADDLE_Y_START;
    int bricks[BRICK_ROWS][BRICK_COLS];
    int score = 0;

    // initialize the game board
    initialize_bricks(bricks);
    clear_screen();
    print_board(ball_x, ball_y, paddle_x, paddle_y, bricks);

    // game loop
    while (1) {
        // move the ball
        int dx = rand() % (2*BALL_SPEED + 1) - BALL_SPEED;
        int dy = BALL_SPEED;
        int collision = move_ball(ball_x, ball_y, dx, dy, bricks);
        if (collision == -1) {
            // game over
            printf(COLOR_RED "GAME OVER\n" COLOR_RESET);
            break;
        } else if (collision == 1) {
            // brick destroyed
            score++;
        }

        // move the paddle
        int direction = 0;
        if (rand() % 2) {
            direction = LEFT;
        } else {
            direction = RIGHT;
        }
        paddle_x = move_paddle(paddle_x, paddle_y, direction);

        // update the game board
        clear_screen();
        print_board(ball_x, ball_y, paddle_x, paddle_y, bricks);
        printf(COLOR_YELLOW "Score: %d\n" COLOR_RESET, score);
    }

    return 0;
}

void clear_screen() {
    system("clear");
}

void print_board(int ball_x, int ball_y, int paddle_x, int paddle_y, int bricks[][BRICK_COLS]) {
    // print the game board with bricks, ball, and paddle
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bricks[i/BRICK_HEIGHT][j/BRICK_WIDTH] > 0 && i % BRICK_HEIGHT == 0 && j % BRICK_WIDTH == 0) {
                // print brick
                printf(COLOR_GREEN "|" COLOR_RESET);
            } else if (j == 0 || j == COLS-1 || i == 0) {
                // print wall
                printf(COLOR_GREEN "#" COLOR_RESET);
            } else if (i == ball_y && j == ball_x) {
                // print ball
                printf(COLOR_RED "O" COLOR_RESET);
            } else if (i == paddle_y && j >= paddle_x && j < paddle_x+PADDLE_SIZE) {
                // print paddle
                printf(COLOR_YELLOW "=" COLOR_RESET);
            } else {
                // print empty space
                printf(" ");
            }
        }
        printf("\n");
    }
}

int move_ball(int ball_x, int ball_y, int dx, int dy, int bricks[][BRICK_COLS]) {
    // move the ball and detect collisions
    int new_ball_x = ball_x + dx;
    int new_ball_y = ball_y + dy;

    // detect collision with walls
    if (new_ball_x < 1 || new_ball_x > COLS-2) {
        dx = -dx;
        new_ball_x = ball_x + dx;
    } else if (new_ball_y < 1) {
        dy = -dy;
        new_ball_y = ball_y + dy;
    } else if (new_ball_y > ROWS-1) {
        // game over
        return -1;
    }

    // detect collision with bricks
    int brick_x = new_ball_x / BRICK_WIDTH;
    int brick_y = new_ball_y / BRICK_HEIGHT;
    if (bricks[brick_y][brick_x] > 0) {
        // brick is destroyed
        bricks[brick_y][brick_x] = 0;
        return 1;
    }

    // update ball position
    ball_x = new_ball_x;
    ball_y = new_ball_y;

    return 0;
}

int move_paddle(int paddle_x, int paddle_y, int direction) {
    // move the paddle left or right
    int new_paddle_x = paddle_x + direction*PADDLE_SPEED;

    // detect paddle collision with walls
    if (new_paddle_x < 1 || new_paddle_x > COLS-PADDLE_SIZE-1) {
        direction = -direction;
        new_paddle_x = paddle_x + direction*PADDLE_SPEED;
    }

    // update paddle position
    paddle_x = new_paddle_x;

    return paddle_x;
}

int detect_collision(int ball_x, int ball_y, int dx, int dy, int paddle_x, int paddle_y) {
    // detect collision between ball and paddle
    if (ball_y + dy == paddle_y && ball_x + dx >= paddle_x && ball_x + dx < paddle_x + PADDLE_SIZE) {
        return 1;
    }

    return 0;
}

void initialize_bricks(int bricks[][BRICK_COLS]) {
    // initialize the brick layout
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            bricks[i][j] = rand() % 2;
        }
    }
}