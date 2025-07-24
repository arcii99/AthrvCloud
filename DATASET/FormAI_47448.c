//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define ROWS 30
#define COLS 60
#define BRICK_ROWS 8
#define BRICK_COLS 10
#define BALL_SYMBOL 'O'
#define PADDLE_SYMBOL '-'
#define BRICK_SYMBOL '#'
#define WALL_SYMBOL '|'
#define CEILING_SYMBOL '-'
#define FLOOR_SYMBOL '_'
#define MAX_LIVES 5
#define MAX_SCORE (BRICK_ROWS * BRICK_COLS)

// Structures
typedef struct {
    int x, y;
    int dx, dy;
    int lives;
    int score;
} Ball;

typedef struct {
    int x, y;
    int dx;
} Paddle;

// Prototypes
void print_board(bool board[ROWS][COLS], Ball b, Paddle p);
void initialize_board(bool board[ROWS][COLS], Ball *b, Paddle *p);
void move_ball(bool board[ROWS][COLS], Ball *b, Paddle p);
void move_paddle(Paddle *p, bool left);
bool is_brick_hit(bool board[ROWS][COLS], int row, int col, Ball b);
void reset_board(bool board[ROWS][COLS]);
void print_message(char *message);

int main() {
    bool board[ROWS][COLS];
    Ball ball;
    Paddle paddle;
    char input;
    bool left;
    int bricks_left = BRICK_ROWS * BRICK_COLS;

    srand(time(NULL));  // Seed random number generator

    // Initialize board and game elements
    initialize_board(board, &ball, &paddle);

    // Game loop
    while (ball.lives > 0 && ball.score < MAX_SCORE && bricks_left > 0) {
        // Print board and game info
        print_board(board, ball, paddle);
        printf("Lives: %d     Score: %d/%d\n", ball.lives, ball.score, MAX_SCORE);

        // Move ball and paddle
        move_ball(board, &ball, paddle);
        input = getchar();
        left = (input == 'a');
        move_paddle(&paddle, left);

        // Check if ball hits a brick
        for(int i = 0; i < BRICK_ROWS; i++) {
            for(int j = 0; j < BRICK_COLS; j++) {
                if(board[i+1][j+5] && is_brick_hit(board, i+1, j+5, ball)) {
                    board[i+1][j+5] = false;
                    ball.score++;
                    bricks_left--;
                }
            }
        }

        // Reset board if ball goes out of bounds
        if(ball.y >= ROWS) {
            ball.lives--;
            reset_board(board);
        }
    }

    // Print final game info
    if(bricks_left == 0) {
        print_message("Congratulations, you won!");
    } else {
        print_message("Game over!");
    }
    printf("Final score: %d/%d\n", ball.score, MAX_SCORE);

    return 0;
}

void print_board(bool board[ROWS][COLS], Ball b, Paddle p) {
    system("clear");  // Clear terminal window
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j]) {
                printf("%c", BRICK_SYMBOL);
            } else if(i == b.y && j == b.x) {
                printf("%c", BALL_SYMBOL);
            } else if(i == p.y && j >= p.x && j < p.x + 10) {
                printf("%c", PADDLE_SYMBOL);
            } else if(j == 0 || j == COLS-1 || i == 0) {
                printf("%c", WALL_SYMBOL);
            } else if(i == 1) {
                printf("%c", CEILING_SYMBOL);
            } else if(i == ROWS-1) {
                printf("%c", FLOOR_SYMBOL);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void initialize_board(bool board[ROWS][COLS], Ball *b, Paddle *p) {
    // Initialize board with bricks
    for(int i = 0; i < BRICK_ROWS; i++) {
        for(int j = 0; j < BRICK_COLS; j++) {
            board[i+1][j+5] = true;
        }
    }

    // Initialize ball
    b->x = COLS/2;
    b->y = ROWS/2;
    b->dx = rand() % 2 ? 1 : -1;
    b->dy = -1;
    b->lives = MAX_LIVES;
    b->score = 0;

    // Initialize paddle
    p->x = COLS/2 - 5;
    p->y = ROWS - 2;
    p->dx = 0;
}

void move_ball(bool board[ROWS][COLS], Ball *b, Paddle p) {
    // Move ball horizontally
    b->x += b->dx;

    // Check for left/right wall collision
    if(b->x == 0 || b->x == COLS-1) {
        b->dx = -b->dx;
        b->x += b->dx;
    }

    // Move ball vertically
    b->y += b->dy;

    // Check for top wall collision
    if(b->y == 1) {
        b->dy = -b->dy;
        b->y += b->dy;
    }

    // Check for paddle collision
    if(b->y == p.y-1 && b->x >= p.x && b->x < p.x + 10) {
        b->dy = -b->dy;
        b->y += b->dy;
    }
}

void move_paddle(Paddle *p, bool left) {
    p->x += left ? -1 : 1;

    // Check for left/right wall collision
    if(p->x < 0) {
        p->x = 0;
    } else if(p->x + 10 > COLS) {
        p->x = COLS - 10;
    }
}

bool is_brick_hit(bool board[ROWS][COLS], int row, int col, Ball b) {
    if(b.y == row && b.x >= col && b.x < col + 10) {
        return true;
    }
    return false;
}

void reset_board(bool board[ROWS][COLS]) {
    // Reset board with bricks
    for(int i = 0; i < BRICK_ROWS; i++) {
        for(int j = 0; j < BRICK_COLS; j++) {
            board[i+1][j+5] = true;
        }
    }
}

void print_message(char *message) {
    system("clear");  // Clear terminal window
    printf("%s\n", message);
}