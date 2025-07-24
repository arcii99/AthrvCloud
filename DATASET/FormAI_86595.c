//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

const int ROW = 50;
const int COL = 20;

void print_screen(char screen[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void init_screen(char screen[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            screen[i][j] = ' ';
        }
    }
}

void draw_paddle(char screen[][COL], int paddle_pos) {
    for (int i = ROW - 2; i < ROW; i++) {
        for (int j = paddle_pos - 2; j < paddle_pos + 2; j++) {
            if (j >= 0 && j < COL) {
                screen[i][j] = '_';
            }
        }
    }
}

void draw_ball(char screen[][COL], int ball_pos_x, int ball_pos_y) {
    screen[ball_pos_x][ball_pos_y] = '*';
}

void move_ball(int *ball_pos_x, int *ball_pos_y, int *ball_dir_x, int *ball_dir_y) {
    if (*ball_pos_x + *ball_dir_x < 0) {
        *ball_dir_x = 1;
    } else if (*ball_pos_x + *ball_dir_x >= ROW) {
        *ball_dir_x = -1;
    } else {
        *ball_pos_x += *ball_dir_x;
    }

    if (*ball_pos_y + *ball_dir_y < 0) {
        *ball_dir_y = 1;
    } else if (*ball_pos_y + *ball_dir_y >= COL) {
        *ball_dir_y = -1;
    } else {
        *ball_pos_y += *ball_dir_y;
    }
}

bool check_hit_paddle(int ball_pos_x, int ball_pos_y, int paddle_pos) {
    if (ball_pos_x == ROW - 2 && ball_pos_y >= paddle_pos - 2 && ball_pos_y <= paddle_pos + 2) {
        return true;
    } else {
        return false;
    }
}

bool check_game_over(int ball_pos_x) {
    if (ball_pos_x == ROW - 1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char screen[ROW][COL];
    init_screen(screen);
    int paddle_pos = COL / 2;
    int ball_pos_x = ROW / 2;
    int ball_pos_y = COL / 2;
    int ball_dir_x = 1;
    int ball_dir_y = 1;

    while (true) {
        system("clear");
        draw_paddle(screen, paddle_pos);
        draw_ball(screen, ball_pos_x, ball_pos_y);
        print_screen(screen);
        move_ball(&ball_pos_x, &ball_pos_y, &ball_dir_x, &ball_dir_y);
        
        if (check_hit_paddle(ball_pos_x, ball_pos_y, paddle_pos)) {
            ball_dir_x = -1;
        }

        if (check_game_over(ball_pos_x)) {
            printf("Game Over!\n");
            break;
        }

        char input = getchar();
        if (input == 'a' && paddle_pos > 2) {
            paddle_pos--;
        } else if (input == 'd' && paddle_pos < COL - 3) {
            paddle_pos++;
        }
    }

    return 0;
}