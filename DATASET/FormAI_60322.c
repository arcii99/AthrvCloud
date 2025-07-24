//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define BRICK_ROWS 5
#define BRICK_COLS 10

int main() {
    // Initialization
    int paddle = COLS / 2;
    int ball_x = paddle;
    int ball_y = ROWS - 2;
    int ball_dx = 1;
    int ball_dy = -1;
    int bricks[BRICK_ROWS][BRICK_COLS];
    int score = 0;

    // Fill bricks randomly
    srand(time(NULL));
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            bricks[i][j] = rand() % 2;
        }
    }

    // Game loop
    while (1) {
        // Clear screen
        system("clear");

        // Draw bricks
        for (int i = 0; i < BRICK_ROWS; i++) {
            for (int j = 0; j < BRICK_COLS; j++) {
                if (bricks[i][j]) {
                    printf("[x]");
                } else {
                    printf("[ ]");
                }
            }
            printf("\n");
        }

        // Draw paddle
        for (int i = 0; i < COLS; i++) {
            if (i == paddle) {
                printf("=");
            } else {
                printf(" ");
            }
        }
        printf("\n");

        // Draw ball
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == ball_y && j == ball_x) {
                    printf("o");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Move ball
        ball_x += ball_dx;
        ball_y += ball_dy;

        // Check wall collisions
        if (ball_x == 0 || ball_x == COLS - 1) {
            ball_dx = -ball_dx;
        }
        if (ball_y == 0) {
            ball_dy = -ball_dy;
        }

        // Check paddle collision
        if (ball_y == ROWS - 2 && ball_x >= paddle - 2 && ball_x <= paddle + 2) {
            ball_dy = -ball_dy;
        }

        // Check brick collision
        if (ball_y < BRICK_ROWS && bricks[ball_y][ball_x]) {
            bricks[ball_y][ball_x] = 0;
            ball_dy = -ball_dy;
            score += 10;
        }

        // Check game over
        if (ball_y == ROWS - 1) {
            printf("Game over! Score: %d\n", score);
            return 0;
        }

        // Check win
        int bricks_left = 0;
        for (int i = 0; i < BRICK_ROWS; i++) {
            for (int j = 0; j < BRICK_COLS; j++) {
                if (bricks[i][j]) {
                    bricks_left = 1;
                    break;
                }
            }
        }
        if (!bricks_left) {
            printf("You win! Score: %d\n", score);
            return 0;
        }

        // Move paddle
        char c = getchar();
        if (c == 'a') {
            paddle = (paddle > 0) ? paddle - 1 : 0;
        } else if (c == 'd') {
            paddle = (paddle < COLS - 1) ? paddle + 1 : COLS - 1;
        }
    }
}