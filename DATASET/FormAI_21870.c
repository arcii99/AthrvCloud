//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20
#define WALL '#'
#define PADDLE '='
#define BALL 'o'
#define BRICK '@'

int score = 0;
char grid[HEIGHT][WIDTH];

struct Paddle {
    int x;
    int y;
} paddle;

struct Ball {
    int x;
    int y;
    int dx;
    int dy;
} ball;

void clear_screen() {
    system("clear");
}

void init_paddle() {
    paddle.x = WIDTH / 2 - 3;
    paddle.y = HEIGHT - 1;
}

void draw_paddle() {
    for(int i = paddle.x; i < paddle.x + 6; i++) {
        grid[paddle.y][i] = PADDLE;
    }
}

void move_paddle(int dir) {
    if(dir == -1 && paddle.x > 0) {
        paddle.x--;
    } else if(dir == 1 && paddle.x < WIDTH - 6) {
        paddle.x++;
    }
}

void init_ball() {
    ball.x = WIDTH / 2;
    ball.y = HEIGHT - 2;
    ball.dx = (rand() % 2 == 0 ? 1 : -1);
    ball.dy = -1;
}

void draw_ball() {
    grid[ball.y][ball.x] = BALL;
}

bool move_ball() {
    bool bounce = false;

    ball.x += ball.dx;
    ball.y += ball.dy;

    if(ball.x == 0 || ball.x == WIDTH - 1) {
        ball.dx *= -1;
        bounce = true;
    }

    if(ball.y == 0) {
        ball.dy *= -1;
        bounce = true;
    }

    if(ball.y == HEIGHT - 1) {
        return false;
    }

    if(ball.y == paddle.y - 1 && ball.x >= paddle.x && ball.x <= paddle.x + 5) {
        ball.dy *= -1;
        bounce = true;
    }

    if(grid[ball.y][ball.x] == BRICK) {
        score++;
        grid[ball.y][ball.x] = ' ';
        ball.dy *= -1;
        bounce = true;
    }

    return bounce;
}

void init_bricks() {
    srand(time(NULL));
    for(int i = 1; i < HEIGHT / 2; i++) {
        for(int j = 1; j < WIDTH - 1; j++) {
            if(rand() % 5 == 0) {
                grid[i][j] = BRICK;
            }
        }
    }
}

void draw_grid() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            putchar(grid[i][j] ? grid[i][j] : ' ');
        }
        putchar('\n'); 
    }
}

int main() {
    clear_screen();
    init_paddle();
    init_ball();
    init_bricks();

    while(true) {
        clear_screen();
        draw_paddle();
        draw_ball();
        draw_grid();

        if(move_ball() == false) {
            printf("Game Over\nScore: %d\n", score);
            break;
        }

        usleep(50000);
    }

    return 0;
}