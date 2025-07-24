//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_HEIGHT 25
#define BOARD_WIDTH 80
#define PLAYER_HEIGHT 5
#define PLAYER_WIDTH 1
#define BALL_HEIGHT 1
#define BALL_WIDTH 1

// Function to print the game board
void print_board(char board[][BOARD_WIDTH]) {
    system("clear"); // clear the console screen
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize variables
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    bool game_over = false;
    int player1_pos = BOARD_HEIGHT / 2 - (PLAYER_HEIGHT / 2);
    int player2_pos = player1_pos;
    int ball_pos_x = BOARD_WIDTH / 2 - (BALL_WIDTH / 2);
    int ball_pos_y = BOARD_HEIGHT / 2 - (BALL_HEIGHT / 2);
    int ball_dir_x = (rand() % 2 == 0) ? 1 : -1;
    int ball_dir_y = (rand() % 2 == 0) ? 1 : -1;
    // Fill the board with spaces and add the players and ball
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
            if (i >= player1_pos && i < player1_pos + PLAYER_HEIGHT && j == 0) {
                board[i][j] = '|'; // player 1
            }
            if (i >= player2_pos && i < player2_pos + PLAYER_HEIGHT && j == BOARD_WIDTH - 1) {
                board[i][j] = '|'; // player 2
            }
            if (i == ball_pos_y && j == ball_pos_x) {
                board[i][j] = 'O'; // ball
            }
        }
    }
    // Game loop
    while (!game_over) {
        print_board(board);
        // Move the ball
        ball_pos_x += ball_dir_x;
        ball_pos_y += ball_dir_y;
        // Check if the ball hit a wall or a player
        if (ball_pos_x == 0 || ball_pos_x == BOARD_WIDTH - 1) {
            game_over = true;
            printf("GAME OVER!\n");
        } else {
            if (ball_pos_y == 0 || ball_pos_y == BOARD_HEIGHT - 1) {
                ball_dir_y = -ball_dir_y; // hit a wall
            } else {
                // check if the ball hit a player
                if (ball_pos_x == 1 && ball_pos_y >= player1_pos && ball_pos_y < player1_pos + PLAYER_HEIGHT) {
                    ball_dir_x = -ball_dir_x;
                }
                if (ball_pos_x == BOARD_WIDTH - 2 && ball_pos_y >= player2_pos && ball_pos_y < player2_pos + PLAYER_HEIGHT) {
                    ball_dir_x = -ball_dir_x;
                }
            }
        }
        // Move the opponent player
        if (rand() % 2 == 0) {
            if (ball_pos_y < player2_pos + (PLAYER_HEIGHT / 2)) {
                player2_pos--;
            } else if (ball_pos_y > player2_pos + (PLAYER_HEIGHT / 2)) {
                player2_pos++;
            }
        }
        // Update the board
        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                board[i][j] = ' ';
                if (i >= player1_pos && i < player1_pos + PLAYER_HEIGHT && j == 0) {
                    board[i][j] = '|'; // player 1
                }
                if (i >= player2_pos && i < player2_pos + PLAYER_HEIGHT && j == BOARD_WIDTH - 1) {
                    board[i][j] = '|'; // player 2
                }
                if (i == ball_pos_y && j == ball_pos_x) {
                    board[i][j] = 'O'; // ball
                }
            }
        }
        // Add a delay to slow down the game
        struct timespec ts = {0, 100000000};
        nanosleep(&ts, NULL);
    }
    return 0;
}