//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

// Function to check if the game is over
int game_over(char game_board[HEIGHT][WIDTH]) {
    for (int i = 0; i < WIDTH; i++) {
        if (game_board[HEIGHT - 2][i] == '#') {
            return 1;
        }
    }
    return 0;
}

int main() {
    char game_board[HEIGHT][WIDTH];

    // Initialize game board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                game_board[i][j] = '#';
            } else {
                game_board[i][j] = ' ';
            }
        }
    }

    // Initialize ball and paddle positions
    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT - 3;
    int paddle_x = WIDTH / 2 - 4;

    // Game loop
    while (!game_over(game_board)) {
        // Clear screen and print game board
        system("clear");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c", game_board[i][j]);
            }
            printf("\n");
        }

        // Move ball
        ball_y--;

        // Check if ball hit wall or paddle
        if (game_board[ball_y][ball_x] == '#') {
            game_board[ball_y][ball_x] = ' ';
            ball_y += 2;
        } else if (ball_y == HEIGHT - 3 && ball_x >= paddle_x && ball_x <= paddle_x + 7) {
            ball_y += 2;
        }

        // Move paddle
        int direction = rand() % 3 - 1;
        if (paddle_x + direction >= 1 && paddle_x + direction + 7 <= WIDTH - 1) {
            paddle_x += direction;
        }

        // Update game board
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == ball_y && j == ball_x) {
                    game_board[i][j] = 'O';
                } else if (i == HEIGHT - 2 && j >= paddle_x && j <= paddle_x + 7) {
                    game_board[i][j] = '=';
                } else if (i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                    game_board[i][j] = '#';
                } else {
                    game_board[i][j] = ' ';
                }
            }
        }

        // Sleep
        struct timespec ts;
        ts.tv_sec = 0;
        ts.tv_nsec = 100000000;
        nanosleep(&ts, NULL);
    }

    // Game over
    printf("Game over!\n");

    return 0;
}