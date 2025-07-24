//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define ROWS 20
#define COLS 40
#define ENEMY_ROWS 5
#define ENEMY_COLS 15
#define PLAYER_SIZE 3
#define ENEMY_SIZE 3
#define BULLET_SIZE 1

// Turns off buffer and input echo for input streaming
void off_buffered_input() {
    struct termios settings;
    tcgetattr(STDIN_FILENO, &settings);
    settings.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    // Set up game board
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == (ROWS-1)) { // Set up player
                if (j >= (COLS/2 - PLAYER_SIZE/2) && j <= (COLS/2 + PLAYER_SIZE/2)) {
                    board[i][j] = 'P';
                } else {
                    board[i][j] = '-';
                }
            } else if (i < ENEMY_ROWS && j < ENEMY_COLS) { // Set up enemies
                board[i][j] = 'E';
            } else { // Set up board
                board[i][j] = '-';
            }
        }
    }

    // Set up player and bullet positions
    int player_pos = COLS/2;
    int bullet_row = -1;
    int bullet_col = -1;

    // Set up enemy positions
    int enemy_pos_row = 0;
    int enemy_pos_col = 0;

    // Initialize score and gameover variables
    int score = 0;
    int gameover = 0;

    off_buffered_input(); // Turn off buffered and echo input

    // Print initial board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    while (!gameover) {
        int c = getchar();

        if (c == 'a' && player_pos > 0) { // Move player left
            board[ROWS-1][player_pos] = '-';
            player_pos--;
            board[ROWS-1][player_pos] = 'P';
        } else if (c == 'd' && player_pos < (COLS-1)) { // Move player right
            board[ROWS-1][player_pos] = '-';
            player_pos++;
            board[ROWS-1][player_pos] = 'P';
        } else if (c == ' ' && bullet_row == -1) { // Make player fire bullet
            bullet_row = ROWS-2;
            bullet_col = player_pos;
            board[bullet_row][bullet_col] = '|';
        }

        // Move bullet up
        if (bullet_row != -1) {
            board[bullet_row][bullet_col] = '-';
            bullet_row--;
            if (bullet_row >= 0) {
                board[bullet_row][bullet_col] = '|';
            } else {
                bullet_row = -1;
            }
        }

        // Move enemies down
        if (enemy_pos_row < (ROWS-1)) {
            board[enemy_pos_row][enemy_pos_col] = '-';
            enemy_pos_row++;
            if (enemy_pos_row < ENEMY_ROWS) {
                board[enemy_pos_row][enemy_pos_col] = 'E';
            } else {
                enemy_pos_row = 0;
                enemy_pos_col = rand() % (COLS-ENEMY_SIZE);
            }
        }

        // Detect bullet and enemy collision
        if (bullet_row != -1 && enemy_pos_row == bullet_row && enemy_pos_col <= bullet_col && bullet_col <= (enemy_pos_col+ENEMY_SIZE-1)) {
            score++;
            bullet_row = -1;
            board[enemy_pos_row][enemy_pos_col] = '-';
            if (score == ENEMY_ROWS*(COLS-ENEMY_SIZE+1)) { // Check for win
                printf("Congratulations! You won!\n");
                gameover = 1;
            }
        }

        // Detect enemy and player collision
        if (enemy_pos_row == (ROWS-1) && enemy_pos_col <= player_pos && player_pos <= (enemy_pos_col+ENEMY_SIZE-1)) {
            printf("Game over! You died!\n");
            gameover = 1;
        }

        // Clear screen and print board
        system("clear");
        printf("Score: %d\n", score);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
        usleep(100000); // Sleep for 100ms to slow down game
    }

    return 0;
}