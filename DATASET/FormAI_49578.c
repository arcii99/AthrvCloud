//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: multi-threaded
#include <stdio.h>    // for standard I/O
#include <stdlib.h>   // for malloc and free
#include <string.h>   // for string functions
#include <pthread.h>  // for threading
#include <stdbool.h>  // for boolean variables

#define WIDTH  20           // width of the game screen
#define HEIGHT 10           // height of the game screen
#define PADDLE_WIDTH  1     // width of the paddles
#define PADDLE_HEIGHT 4     // height of the paddles
#define BALL_SIZE     1     // size of the ball
#define SLEEP_TIME    30000 // usleep value for refreshing the screen

char screen[HEIGHT + 1][WIDTH + 1];    // game screen
int ball_x = WIDTH / 2;               // x-coordinate of the ball
int ball_y = HEIGHT / 2;              // y-coordinate of the ball
int ball_dx = 1;                      // x-direction of the ball
int ball_dy = 1;                      // y-direction of the ball
int player1_y = (HEIGHT - PADDLE_HEIGHT) / 2;  // y-coordinate of player 1's paddle
int player2_y = (HEIGHT - PADDLE_HEIGHT) / 2;  // y-coordinate of player 2's paddle

// update the screen
void update_screen() {
    // clear the screen
    memset(screen, ' ', sizeof(screen));

    // draw the paddles
    for (int y = 0; y < PADDLE_HEIGHT; y++) {
        screen[player1_y + y][0] = '|';
        screen[player2_y + y][WIDTH - 1] = '|';
    }

    // draw the ball
    screen[ball_y][ball_x] = '*';

    // print the screen
    for (int y = 0; y < HEIGHT; y++) {
        screen[y][WIDTH] = '\n';
        printf("%s", screen[y]);
    }
}

// move the ball
void move_ball() {
    ball_x += ball_dx;
    ball_y += ball_dy;

    // check if the ball hit the top or bottom of the screen
    if (ball_y == 0 || ball_y == HEIGHT - 1) {
        ball_dy = -ball_dy;
    }

    // check if the ball hit the left or right paddle
    if (ball_x == PADDLE_WIDTH + 1 && ball_y >= player1_y && ball_y < player1_y + PADDLE_HEIGHT) {
        ball_dx = -ball_dx;
    } else if (ball_x == WIDTH - PADDLE_WIDTH - BALL_SIZE - 1 &&
               ball_y >= player2_y && ball_y < player2_y + PADDLE_HEIGHT) {
        ball_dx = -ball_dx;
    }

    // check if the ball went off screen
    if (ball_x == 0 || ball_x == WIDTH - BALL_SIZE - 1) {
        ball_x = WIDTH / 2;
        ball_y = HEIGHT / 2;
        ball_dx = -ball_dx;
    }
}

// move the opponent paddle
void move_opponent() {
    // move the paddle towards the ball
    if (ball_y < player2_y + PADDLE_HEIGHT / 2) {
        player2_y--;
    } else if (ball_y > player2_y + PADDLE_HEIGHT / 2) {
        player2_y++;
    }
}

int main() {
    // initialize the game screen
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            screen[y][x] = ' ';
        }
    }
    screen[HEIGHT][0] = '\0';

    // create a thread for moving the opponent paddle
    pthread_t thread;
    int rc = pthread_create(&thread, NULL, (void*)move_opponent, NULL);
    if (rc) {
        printf("Error: pthread_create failed with code %d\n", rc);
        return 1;
    }

    // main game loop
    while (true) {
        // move the ball
        move_ball();

        // update the screen
        update_screen();

        // wait a bit before refreshing the screen
        usleep(SLEEP_TIME);
    }

    // should never get here
    return 0;
}