//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: ultraprecise
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FIELD_WIDTH 50
#define FIELD_HEIGHT 20
#define PADDLE_SIZE 3
#define BALL_SIZE 1

/* Definition of our playing field. */
char field[FIELD_HEIGHT][FIELD_WIDTH];

/* Position of the ball. */
int ball_x = FIELD_WIDTH / 2;
int ball_y = FIELD_HEIGHT / 2;

/* Direction of the ball. */
int ball_xdir = -1;
int ball_ydir = -1;

/* Position of the left paddle. */
int paddle1_y = FIELD_HEIGHT / 2 - PADDLE_SIZE / 2;

/* Position of the right paddle. */
int paddle2_y = FIELD_HEIGHT / 2 - PADDLE_SIZE / 2;

/* Definition of our AI player function. */
void ai_player() {
    if (ball_y > paddle2_y + PADDLE_SIZE / 2) {
        paddle2_y++;
    }
    else if (ball_y < paddle2_y + PADDLE_SIZE / 2) {
        paddle2_y--;
    }
}

/* Definition of our collision detection function. */
void collision_detection() {
    /* Bounce back if the ball hits the top or bottom wall. */
    if (ball_y == 0 || ball_y == FIELD_HEIGHT - BALL_SIZE) {
        ball_ydir = -ball_ydir;
    }

    /* Bounce back if the ball hits the left paddle. */
    if (ball_x == 2 && ball_y >= paddle1_y && ball_y < paddle1_y + PADDLE_SIZE) {
        ball_xdir = -ball_xdir;
    }

    /* Bounce back if the ball hits the right paddle. */
    if (ball_x == FIELD_WIDTH - 3 && ball_y >= paddle2_y && ball_y < paddle2_y + PADDLE_SIZE) {
        ball_xdir = -ball_xdir;
    }

    /* Reset the ball to the center if it goes out of bounds. */
    if (ball_x == 0 || ball_x == FIELD_WIDTH - 1) {
        ball_x = FIELD_WIDTH / 2;
        ball_y = FIELD_HEIGHT / 2;
        ball_xdir = -ball_xdir;

        /* Randomize the ball direction after reset. */
        srand(time(NULL));
        int random_number = rand() % 2;
        if (random_number == 0) {
            ball_ydir = -1;
        }
        else {
            ball_ydir = 1;
        }
    }
}

/* Definition of our update function. */
void update() {
    ball_x += ball_xdir;
    ball_y += ball_ydir;
    collision_detection();
    ai_player();
}

/* Definition of our render function. */
void render() {
    /* Clear screen. */
    system("clear");

    /* Render playing field. */
    for (int y = 0; y < FIELD_HEIGHT; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
            if (x == 0 || x == FIELD_WIDTH - 1) {
                printf("|");
            }
            else if (x == ball_x && y == ball_y) {
                printf("O");
            }
            else if (x == 2 && y >= paddle1_y && y < paddle1_y + PADDLE_SIZE) {
                printf("|");
            }
            else if (x == FIELD_WIDTH - 3 && y >= paddle2_y && y < paddle2_y + PADDLE_SIZE) {
                printf("|");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* Definition of our main function. */
int main() {
    /* Set up keyboard input. */
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios new_termios = orig_termios;
    new_termios.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    /* Clear the playing field. */
    memset(field, ' ', sizeof(field));

    /* Set up initial ball direction. */
    srand(time(NULL));
    int random_number = rand() % 2;
    if (random_number == 0) {
        ball_ydir = -1;
    }
    else {
        ball_ydir = 1;
    }

    /* Game loop. */
    while (1) {
        /* Update and render the game. */
        update();
        render();
        fflush(stdout);

        /* Sleep for 30 milliseconds. */
        usleep(30000);
    }

    /* End keyboard input setup. */
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    return 0;
}