//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 22
#define COLS 60
#define BRICK_ROWS 4
#define BRICK_COLS 13

struct brick {
    int row, col, hits;
    char symbol;
};

static struct brick bricks[BRICK_ROWS][BRICK_COLS];
static int ball_row, ball_col, paddle_col, score, level;
static int bricks_left, direction_row, direction_col;

void setup_bricks() {
    int i, j, ind;
    char symbols[] = {'@', '#', '$', '%'};
    for (i = 0; i < BRICK_ROWS; i++) {
        for (j = 0; j < BRICK_COLS; j++) {
            ind = rand() % 4;
            bricks[i][j].row = 1 + i;
            bricks[i][j].col = 1 + 4 * j;
            bricks[i][j].hits = ind + 1;
            bricks[i][j].symbol = symbols[ind];
        }
    }
}

void print_game_board() {
    int i, j;
    system("clear");
    printf("+");
    for (i = 0; i < COLS; i++) {
        printf("-");
    }
    printf("+\n");
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            if (i == ball_row && j == ball_col) {
                printf("o");
            } else if (i == ROWS - 1 && j >= paddle_col - 2 && j <= paddle_col + 2) {
                printf("=");
            } else {
                int flag = 0, k;
                for (k = 0; k < BRICK_ROWS; k++) {
                    int l;
                    for (l = 0; l < BRICK_COLS; l++) {
                        if (bricks[k][l].row == i && bricks[k][l].col == j && bricks[k][l].hits > 0) {
                            flag = 1;
                            printf("%c", bricks[k][l].symbol);
                            break;
                        }
                    }
                    if (flag == 1) {
                        break;
                    }
                }
                if (flag == 0) {
                    printf(" ");
                }
            }
        }
        printf("|\n");
    }
    printf("+");
    for (i = 0; i < COLS; i++) {
        printf("-");
    }
    printf("+\nScore: %d    Level: %d    Bricks left: %d", score, level, bricks_left);
}

int get_input() {
    char c = getchar();
    while (getchar() != '\n');
    if (c == 'a' || c == 'A') {
        return -1;
    } else if (c == 'd' || c == 'D') {
        return 1;
    } else {
        return 0;
    }
}

void move_ball() {
    int new_row = ball_row + direction_row;
    int new_col = ball_col + direction_col;
    if (new_row == ROWS - 1 && new_col >= paddle_col - 2 && new_col <= paddle_col + 2) {
        direction_row = -1;
        int delta_col = new_col - paddle_col;
        if (delta_col == 0) {
            direction_col = 0;
        } else if (delta_col < 0) {
            direction_col = -1;
        } else {
            direction_col = 1;
        }
    } else if (new_row == ROWS) {
        print_game_board();
        printf("\n\nGame Over!\n");
        exit(0);
    } else if (new_row < 0) {
        direction_row = 1;
    } else if (new_col == COLS || new_col == 0) {
        direction_col = -direction_col;
    } else {
        int i, j;
        for (i = 0; i < BRICK_ROWS; i++) {
            for (j = 0; j < BRICK_COLS; j++) {
                if (bricks[i][j].row == new_row && bricks[i][j].col == new_col && bricks[i][j].hits > 0) {
                    score += bricks[i][j].hits;
                    bricks_left--;
                    bricks[i][j].hits--;
                    if (direction_row * direction_col == 1) {
                        direction_row = -direction_row;
                    } else if (direction_row * direction_col == -1) {
                        direction_col = -direction_col;
                    }
                    if (bricks_left == 0) {
                        print_game_board();
                        printf("\n\nCongratulations! You have won the game!\n");
                        exit(0);
                    }
                    return;
                }
            }
        }
        ball_row = new_row;
        ball_col = new_col;
    }
}

int main() {
    srand(time(NULL));
    int i, j, ind, move;
    ball_row = ROWS - 2;
    ball_col = COLS / 2;
    paddle_col = COLS / 2;
    score = 0;
    level = 1;
    bricks_left = BRICK_ROWS * BRICK_COLS;
    direction_row = -1;
    direction_col = 1;
    setup_bricks();
    while (1) {
        print_game_board();
        move = get_input();
        if (move != 0) {
            paddle_col += move;
            if (paddle_col < 3) {
                paddle_col = 3;
            } else if (paddle_col > COLS - 3) {
                paddle_col = COLS - 3;
            }
        }
        move_ball();
        if (score >= level * 100) {
            level++;
            ball_row = ROWS - 2;
            ball_col = COLS / 2;
            paddle_col = COLS / 2;
            direction_row = -1;
            direction_col = 1;
            setup_bricks();
        }
    }
    return 0;
}