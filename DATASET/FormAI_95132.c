//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 20
#define COLS 20
#define BRICK_ROWS 3
#define BRICK_COLS 5

// function prototypes
void init_board(char board[ROWS][COLS]);
void init_bricks(bool bricks[BRICK_ROWS][BRICK_COLS]);
void draw_board(char board[ROWS][COLS]);
void draw_bricks(bool bricks[BRICK_ROWS][BRICK_COLS]);
void handle_input(char *input, int *paddle_pos);
bool update_game(char board[ROWS][COLS], bool bricks[BRICK_ROWS][BRICK_COLS], int *paddle_pos, int *ball_row, int *ball_col, int *dir_row, int *dir_col);
bool check_collision(int ball_row, int ball_col, int dir_row, int dir_col, int paddle_pos, bool bricks[BRICK_ROWS][BRICK_COLS]);
bool check_brick_collision(int ball_row, int ball_col, bool bricks[BRICK_ROWS][BRICK_COLS]);
void end_game();
void print_score(int score);

int main() {
    char board[ROWS][COLS];
    bool bricks[BRICK_ROWS][BRICK_COLS];
    int paddle_pos = COLS / 2 - 2;
    int ball_row = ROWS - 2;
    int ball_col = COLS / 2;
    int dir_row = -1;
    int dir_col = 1;
    int score = 0;

    init_board(board);
    init_bricks(bricks);

    while (true) {
        draw_board(board);
        draw_bricks(bricks);
        printf("Score: %d\n", score);
        char input[10];
        handle_input(input, &paddle_pos);
        if (!update_game(board, bricks, &paddle_pos, &ball_row, &ball_col, &dir_row, &dir_col)) {
            end_game();
            break;
        }
        if (check_brick_collision(ball_row, ball_col, bricks)) {
            dir_row = -dir_row;
            score++;
        }
        if (check_collision(ball_row, ball_col, dir_row, dir_col, paddle_pos, bricks)) {
            dir_row = -dir_row;
        }
    }
    print_score(score);
    return 0;
}

// Initialize the game board
void init_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS - 1 || j == 0 || j == COLS - 1) {
                board[i][j] = '#';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Initialize the bricks
void init_bricks(bool bricks[BRICK_ROWS][BRICK_COLS]) {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            bricks[i][j] = true;
        }
    }
}

// Draw the game board
void draw_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Draw the bricks
void draw_bricks(bool bricks[BRICK_ROWS][BRICK_COLS]) {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            if (bricks[i][j]) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Handle user input
void handle_input(char *input, int *paddle_pos) {
    fgets(input, 10, stdin);
    if (strcmp(input, "a\n") == 0) {
        *paddle_pos = (*paddle_pos - 1 < 1) ? 1 : *paddle_pos - 1;
    } else if (strcmp(input, "d\n") == 0) {
        *paddle_pos = (*paddle_pos + 1 > COLS - 3) ? COLS - 3 : *paddle_pos + 1;
    }
}

// Update the game state
bool update_game(char board[ROWS][COLS], bool bricks[BRICK_ROWS][BRICK_COLS], int *paddle_pos, int *ball_row, int *ball_col, int *dir_row, int *dir_col) {
    // Update ball position
    board[*ball_row][*ball_col] = ' ';
    *ball_row += *dir_row;
    *ball_col += *dir_col;
    board[*ball_row][*ball_col] = 'O';

    // Check if ball hit the wall
    if (*ball_row == ROWS - 2) {
        return false;
    }

    // Update paddle position
    for (int i = 0; i < 3; i++) {
        board[ROWS - 2][*paddle_pos + i] = ' ';
    }
    for (int i = 0; i < 3; i++) {
        board[ROWS - 2][*paddle_pos + i] = '=';
    }

    return true;
}

// Check if ball hit the wall or paddle
bool check_collision(int ball_row, int ball_col, int dir_row, int dir_col, int paddle_pos, bool bricks[BRICK_ROWS][BRICK_COLS]) {
    if (ball_row == ROWS - 2 && ball_col >= paddle_pos && ball_col <= paddle_pos + 2) {
        return true;
    }
    if (ball_row == 1 && dir_row == -1) {
        return true;
    }
    if (ball_col == 1 && dir_col == -1) {
        return true;
    }
    if (ball_col == COLS - 2 && dir_col == 1) {
        return true;
    }
    return false;
}

// Check if ball hit a brick
bool check_brick_collision(int ball_row, int ball_col, bool bricks[BRICK_ROWS][BRICK_COLS]) {
    int brick_row = ball_row - 2;
    int brick_col = ball_col - 1;
    if (bricks[brick_row][brick_col]) {
        bricks[brick_row][brick_col] = false;
        return true;
    }
    return false;
}

// End the game
void end_game() {
    system("clear");
    printf("Game over!\n");
}

// Print the score
void print_score(int score) {
    printf("Your score was %d\n", score);
}