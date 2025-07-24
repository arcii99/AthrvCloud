//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 30

int ball_x = COLS / 2, ball_y = ROWS / 2; // Initial position of the ball
int padd_x = COLS / 2 - 2, padd_y = ROWS - 1; // Initial position of the paddle
int bricks[ROWS - 2][COLS - 2] = {0}; // Array to hold the bricks

int dx = -1, dy = -1; // Initial direction of the ball

/*
Function: init_bricks
Initializes the bricks array.
*/
void init_bricks() {
    int i, j;

    for (i = 0; i < ROWS - 2; i++) {
        for (j = 0; j < COLS - 2; j++) {
            bricks[i][j] = 1;
        }
    }
}

/*
Function: draw_bricks
Draws the bricks on the screen.
*/
void draw_bricks() {
    int i, j;

    for (i = 0; i < ROWS - 2; i++) {
        for (j = 0; j < COLS - 2; j++) {
            if (bricks[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }

        printf("\n");
    }
}

/*
Function: move_ball
Moves the ball on the screen.
*/
void move_ball() {
    int ball_next_x = ball_x + dx;
    int ball_next_y = ball_y + dy;

    // Check for collision with walls
    if (ball_next_x < 0 || ball_next_x >= COLS - 2) {
        dx = -dx;
    }

    if (ball_next_y < 0 || ball_next_y >= ROWS - 1) {
        dy = -dy;
    }

    // Check for collision with paddle
    if (ball_next_y == padd_y && ball_next_x >= padd_x && ball_next_x < padd_x + 4) {
        dy = -dy;
    }

    // Check for collision with bricks
    if (ball_next_y < ROWS - 2) {
        if (bricks[ball_next_y][ball_next_x] == 1) {
            bricks[ball_next_y][ball_next_x] = 0;
            dy = -dy;
        }
    }

    // Update the position of the ball
    ball_x += dx;
    ball_y += dy;
}

/*
Function: draw_ball
Draws the ball on the screen.
*/
void draw_ball() {
    printf("\e[%d;%dH@", ball_y, ball_x);
}

/*
Function: draw_paddle
Draws the paddle on the screen.
*/
void draw_paddle() {
    printf("\e[%d;%dH####", padd_y, padd_x);
}

/*
Function: clear_screen
Clears the screen.
*/
void clear_screen() {
    printf("\e[2J\e[H");
}

int main() {
    int i, j;

    srand(time(NULL));

    init_bricks();

    while (1) {
        clear_screen();

        draw_bricks();
        draw_ball();
        draw_paddle();

        move_ball();

        usleep(100000);

        if (ball_y >= ROWS - 1) {
            printf("\e[%d;%dHGame over!", ROWS + 2, 1);
            break;
        }

        if (bricks[0][0] == 0) {
            printf("\e[%d;%dHYou win!", ROWS + 2, 1);
            break;
        }
    }

    return 0;
}