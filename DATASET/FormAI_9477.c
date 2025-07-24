//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define PADDLE_LENGTH 5
#define BALL_SYMBOL 'o'
#define PADDLE_SYMBOL '='
#define BLOCK_SYMBOL '-'
#define WALL_SYMBOL '|'
#define EMPTY_SYMBOL ' '

int main() {
    srand(time(NULL)); // initialize random seed
    int paddle_position = 4;
    int ball_position_x = 10;
    int ball_position_y = 5;
    int ball_velocity_x = 1;
    int ball_velocity_y = 1;
    int score = 0;
    char board[20][50];
    int i, j;

    // set up the board with walls, paddle, and blocks
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 50; j++) {
            if (i == 0 || i == 19) {
                board[i][j] = WALL_SYMBOL;
            } else if (j >= paddle_position && j < paddle_position + PADDLE_LENGTH) {
                board[i][j] = PADDLE_SYMBOL;
            } else if (i < 5 && j % 5 == 0) {
                board[i][j] = BLOCK_SYMBOL;
            } else {
                board[i][j] = EMPTY_SYMBOL;
            }
        }
    }

    // main game loop
    while (1) {
        system("clear"); // clear the screen
        // move the ball
        ball_position_x += ball_velocity_x;
        ball_position_y += ball_velocity_y;

        // check for collision with walls and paddle
        if (ball_position_x == 49 || ball_position_x == 0) {
            ball_velocity_x = -ball_velocity_x;
        } else if (ball_position_y == 18 && ball_position_x >= paddle_position && ball_position_x < paddle_position + PADDLE_LENGTH) {
            ball_velocity_y = -ball_velocity_y;
            score++;
        } else if (ball_position_y == 19) {
            printf("Game over! Final score: %d\n", score);
            return 0;
        }

        // check for collision with blocks
        if (board[ball_position_y][ball_position_x] == BLOCK_SYMBOL) {
            board[ball_position_y][ball_position_x] = EMPTY_SYMBOL;
            ball_velocity_y = -ball_velocity_y;
            score += 10;
        }

        // update the paddle position
        int key = getchar();
        if (key == 'a' && paddle_position > 0) {
            paddle_position--;
        } else if (key == 'd' && paddle_position < 45) {
            paddle_position++;
        }

        // update the board
        for (i = 0; i < 20; i++) {
            for (j = 0; j < 50; j++) {
                if (i == ball_position_y && j == ball_position_x) {
                    board[i][j] = BALL_SYMBOL;
                } else if (i == 19 && j >= paddle_position && j < paddle_position + PADDLE_LENGTH) {
                    board[i][j] = PADDLE_SYMBOL;
                } else {
                    printf("%c", board[i][j]);
                }
            }
            printf("\n");
        }

        usleep(30000); // delay to slow down the game
    }
}