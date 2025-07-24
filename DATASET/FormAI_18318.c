//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <termios.h>
#define ROWS 24
#define COLS 60

struct ball {
    int row;
    int col;
    int row_inc;
    int col_inc;
};

bool bricks[ROWS][COLS] = {false};
pthread_mutex_t lock;
int score = 0;
bool game_over = false;

void print_board() {
    system("clear");
    printf("Score: %d\n\n", score);
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(bricks[i][j]) {
                printf("X");
            } else if(i == ROWS-1) {
                printf("_");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void* ball_thread(void* arg) {
    struct ball* ball_ptr = (struct ball*) arg;
    while(!game_over) {
        usleep(100000);
        pthread_mutex_lock(&lock);
        bricks[ball_ptr->row][ball_ptr->col] = false;
        ball_ptr->row += ball_ptr->row_inc;
        ball_ptr->col += ball_ptr->col_inc;
        if(ball_ptr->row >= ROWS-1 || ball_ptr->row <= 0) {
            ball_ptr->row_inc *= -1;
            score++;
        }
        if(ball_ptr->col >= COLS-1 || ball_ptr->col <= 0) {
            ball_ptr->col_inc *= -1;
            score++;
        }
        if(bricks[ball_ptr->row][ball_ptr->col]) {
            ball_ptr->row_inc *= -1;
            ball_ptr->col_inc *= -1;
            score += 5;
        }
        bricks[ball_ptr->row][ball_ptr->col] = true;
        print_board();
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* paddle_thread(void* arg) {
    int* col_ptr = (int*) arg;
    while(!game_over) {
        struct termios tp, save;
        tcgetattr(STDIN_FILENO, &tp);
        save = tp;
        tp.c_cc[VMIN] = 1;
        tp.c_lflag &= ~ICANON;
        tp.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &tp);

        char ch=getchar();
        if(ch == 'a' && *col_ptr > 0) {
            pthread_mutex_lock(&lock);
            *col_ptr -= 1;
            pthread_mutex_unlock(&lock);
        } else if(ch == 'd' && *col_ptr < COLS-8) {
            pthread_mutex_lock(&lock);
            *col_ptr += 1;
            pthread_mutex_unlock(&lock);
        } else if(ch == 'q') {
            game_over = true;
            break;
        }

        tcsetattr(STDIN_FILENO, TCSANOW, &save);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&lock, NULL);

    struct ball ball = {
        .row = ROWS/2,
        .col = COLS/2,
        .row_inc = -1,
        .col_inc = 1
    };
    bricks[ROWS/2][COLS/2] = true;
    pthread_t ball_t, paddle_t;

    int paddle_col = 0;
    pthread_create(&ball_t, NULL, ball_thread, &ball);
    pthread_create(&paddle_t, NULL, paddle_thread, &paddle_col);

    pthread_join(ball_t, NULL);
    pthread_join(paddle_t, NULL);

    print_board();
    printf("Game Over! Final Score: %d\n", score);

    pthread_mutex_destroy(&lock);

    return 0;
}