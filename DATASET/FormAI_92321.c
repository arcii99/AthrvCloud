//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 24
#define COLS 80

void print_bar(char symbol);
void print_board(int board[][COLS], int score);
void move_paddle(int board[][COLS], int *paddle_pos, char dir);
int move_ball(int board[][COLS], int *ball_pos, int *ball_dir, int *paddle_pos, int score);
void initialize_board(int board[][COLS], int *ball_pos, int *ball_dir, int *paddle_pos);

int main(void) {
    srand(time(NULL));
    int board[ROWS][COLS];
    int ball_pos[2], ball_dir[2], paddle_pos = COLS/2 - 5, score = 0;

    initialize_board(board, ball_pos, ball_dir, &paddle_pos);
    print_bar('=');
    printf("\nWelcome to Breakout game!\n");
    print_board(board, score);
    print_bar('-');

    char input;
    while (input != 'q') {
        printf("Enter a direction (a - left, d - right, q - quit): ");
        scanf(" %c", &input);
        if (input == 'a' || input == 'd') {
            move_paddle(board, &paddle_pos, input);
        }
        int result = move_ball(board, ball_pos, ball_dir, &paddle_pos, score);
        if (result == 1) {
            score++;
            printf("\nYou destroyed a block! Score: %d\n", score);
        } else if (result == -1) {
            break;
        }
        print_board(board, score);
    }
    printf("\nGame over. Your score was %d.\n", score);

    return 0;
}

void print_bar(char symbol) {
    for (int i = 0; i < COLS; i++) {
        printf("%c", symbol);
    }
    printf("\n");
}

void print_board(int board[][COLS], int score) {
    printf("Score: %d\n", score);
    print_bar('-');
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] > 0) {
                printf("X");
            } else if (board[i][j] < 0) {
                printf("O");
            } else if (i == ROWS - 1 && j >= board[i][0] && j <= board[i][1]) {
                printf("_");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void move_paddle(int board[][COLS], int *paddle_pos, char dir) {
    if (dir == 'a' && (*paddle_pos) > 1) {
        board[ROWS-1][(*paddle_pos)] = 0;
        (*paddle_pos)--;
    } else if (dir == 'd' && (*paddle_pos) < (COLS-1)) {
        board[ROWS-1][(*paddle_pos)] = 0;
        (*paddle_pos)++;
    }
    board[ROWS-1][(*paddle_pos)] = 2;
}

int move_ball(int board[][COLS], int *ball_pos, int *ball_dir, int *paddle_pos, int score) {
    int x = ball_pos[0];
    int y = ball_pos[1];
    int x_dir = ball_dir[0];
    int y_dir = ball_dir[1];
    if (x == ROWS-2) {
        if (y >= (*paddle_pos) && y < (*paddle_pos)+10) {
            x_dir = -1;
            y_dir = ((rand() % 3) - 1) * 2;
        } else {
            return -1;
        }
    } else if (board[x+x_dir][y+y_dir] == 1) {
        board[x+x_dir][y+y_dir] = 0;
        x_dir *= -1;
        y_dir *= -1;
        score++;
        return 1;
    } else if (board[x+x_dir][y+y_dir] != 0) {
        x_dir *= -1;
        y_dir *= -1;
    }
    board[x][y] = 0;
    ball_pos[0] = x+x_dir;
    ball_pos[1] = y+y_dir;
    ball_dir[0] = x_dir;
    ball_dir[1] = y_dir;
    board[x+x_dir][y+y_dir] = -1;
    return 0;
}

void initialize_board(int board[][COLS], int *ball_pos, int *ball_dir, int *paddle_pos) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || j == 0 || i == ROWS-1 || j == COLS-1) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
    ball_pos[0] = ROWS-2;
    ball_pos[1] = COLS/2;
    ball_dir[0] = -1;
    ball_dir[1] = ((rand() % 3) - 1) * 2;
    for (int i = (*paddle_pos); i < (*paddle_pos)+10; i++) {
        board[ROWS-1][i] = 2;
    }
}