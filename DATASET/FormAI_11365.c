//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define PADDLE_HEIGHT 1
#define BALL_SIZE 1
#define DELAY_TIME 100000 // microseconds

enum bool {false, true};
enum direction {none, up, down, left, right};

struct entity {
    int x;
    int y;
    int speed;
    int width;
    int height;
    enum direction dir;
};

int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void set_terminal_mode_to_raw() {
    struct termios tty_attr;

    tcgetattr(STDIN_FILENO, &tty_attr);
    tty_attr.c_lflag &= ~(ICANON | ECHO);
    tty_attr.c_cc[VMIN] = 1;
    tty_attr.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &tty_attr);
}

void draw_board(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void clear_board(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
}

void draw_entity(struct entity *e, char board[HEIGHT][WIDTH], char symbol) {
    for (int i = e->y; i < e->y + e->height; i++) {
        for (int j = e->x; j < e->x + e->width; j++) {
            board[i][j] = symbol;
        }
    }
}

void clear_entity(struct entity *e, char board[HEIGHT][WIDTH]) {
    for (int i = e->y; i < e->y + e->height; i++) {
        for (int j = e->x; j < e->x + e->width; j++) {
            board[i][j] = ' ';
        }
    }
}

void move_entity(struct entity *e, enum direction dir) {
    switch (dir) {
        case up:
            e->dir = up;
            e->y -= e->speed;
            break;
        case down:
            e->dir = down;
            e->y += e->speed;
            break;
        case left:
            e->dir = left;
            e->x -= e->speed;
            break;
        case right:
            e->dir = right;
            e->x += e->speed;
            break;
        default:
            e->dir = none;
            break;
    }
}

void update_ball(struct entity *ball, struct entity *paddle, struct entity *bricks, int num_bricks, char board[HEIGHT][WIDTH]) {
    clear_entity(ball, board);
    
    // Update position of the ball
    switch (ball->dir) {
        case up:
            if (ball->y <= 0) {
                ball->dir = down;
            } else {
                ball->y -= 1;
            }
            break;
        case down:
            if (ball->y >= HEIGHT - BALL_SIZE) {
                ball->dir = up;
            } else {
                ball->y += 1;
            }
            break;
        case left:
            if (ball->x <= 0) {
                ball->dir = right;
            } else {
                ball->x -= 1;
            }
            break;
        case right:
            if (ball->x >= WIDTH - BALL_SIZE) {
                ball->dir = left;
            } else {
                ball->x += 1;
            }
            break;
    }
    
    // Check collision with paddle
    if (ball->y == paddle->y - BALL_SIZE + 1 && ball->x >= paddle->x && ball->x <= paddle->x + paddle->width - 1) {
        ball->dir = up;
    }
    
    // Check collision with bricks
    for (int i = 0; i < num_bricks; i++) {
        if (bricks[i].y + bricks[i].height == ball->y && ball->x >= bricks[i].x && ball->x <= bricks[i].x + bricks[i].width - 1) {
            ball->dir = down;
            clear_entity(&bricks[i], board);
            break;
        }
    }
    
    draw_entity(ball, board, '*');
}

int main() {
    char board[HEIGHT][WIDTH];
    struct entity paddle = {WIDTH/2 - 5, HEIGHT - 2, 1, 10, PADDLE_HEIGHT, none};
    struct entity ball = {WIDTH/2, HEIGHT/2, 1, BALL_SIZE, BALL_SIZE, get_random(1, 4)};
    int num_bricks = 5;
    struct entity bricks[num_bricks];
    for (int i = 0; i < num_bricks; i++) {
        bricks[i].x = i * WIDTH/5;
        bricks[i].y = 3;
        bricks[i].width = WIDTH/5 - 1;
        bricks[i].height = 2;
    }

    set_terminal_mode_to_raw();
    srand(time(NULL));

    clear_board(board);
    draw_entity(&paddle, board, '=');
    draw_entity(&ball, board, '*');
    for (int i = 0; i < num_bricks; i++) {
        draw_entity(&bricks[i], board, '#');
    }
    draw_board(board);

    while (true) {
        char input = '\0';
        if (read(STDIN_FILENO, &input, 1) == 1) {
            switch (input) {
                case 'a':
                    move_entity(&paddle, left);
                    break;
                case 'd':
                    move_entity(&paddle, right);
                    break;
                case 'q':
                    clear_board(board);
                    printf("\n");
                    return 0;
            }
        }

        update_ball(&ball, &paddle, bricks, num_bricks, board);
        draw_entity(&paddle, board, '=');
        draw_board(board);
        clear_entity(&paddle, board);

        usleep(DELAY_TIME);
    }

    return 0;
}