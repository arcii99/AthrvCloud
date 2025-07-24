//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define ROWS 20
#define COLS 40

// Direction constants
#define STOP 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// Paddle constants
#define PADDLE_HEIGHT 4
#define PADDLE_WIDTH 1

// Ball constants
#define BALL_SYMBOL 'O'
#define ROW_CENTER ROWS / 2
#define COL_CENTER COLS / 2

void draw(char screen[ROWS][COLS]){
    int i, j;
    printf("\033[2J"); // clear screen
    printf("\033[%d;%dH", 0, 0); //set cursor to top left
    for (i = 0; i < ROWS; i++){
        for (j = 0; j < COLS; j++){
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void move_ball(int *ball_row, int *ball_col, int *ball_dir_row, int *ball_dir_col, char screen[ROWS][COLS]){
    // Erase ball
    screen[*ball_row][*ball_col] = ' ';

    // Move ball
    *ball_row += *ball_dir_row;
    *ball_col += *ball_dir_col;

    // Check for collision with top/bottom walls
    if (*ball_row == 0 || *ball_row == ROWS - 1){
        *ball_dir_row = -*ball_dir_row;
    }

    // Check for collision with left wall
    if (*ball_col == 0){
        *ball_dir_col = -*ball_dir_col;
    }

    // Check for collision with right wall
    if (*ball_col == COLS - 1){
        *ball_dir_col = -*ball_dir_col;
    }

    // Draw ball
    screen[*ball_row][*ball_col] = BALL_SYMBOL;
}

void move_paddle(int *paddle_row, int *paddle_col, int direction, char screen[ROWS][COLS]){
    // Erase paddle
    int i;
    for (i = 0; i < PADDLE_HEIGHT; i++){
        screen[*paddle_row + i][*paddle_col] = ' ';
    }

    // Move paddle
    switch (direction){
        case UP:
            if (*paddle_row > 0){
                (*paddle_row)--;
            }
            break;
        case DOWN:
            if (*paddle_row < ROWS - PADDLE_HEIGHT){
                (*paddle_row)++;
            }
            break;
    }

    // Draw paddle
    for (i = 0; i < PADDLE_HEIGHT; i++){
        screen[*paddle_row + i][*paddle_col] = '|';
    }
}

int get_key(){
    struct termios oldt, newt;
    int ch;

    // Change terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Get character
    ch = getchar();

    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int is_game_over(int ball_row, int ball_col, int paddle_row, int paddle_col){
    return ball_col == 0 || ball_col == COLS - 1 ||
           (ball_row == ROWS - 1 && (ball_col < paddle_col || ball_col > paddle_col + PADDLE_WIDTH));
}

int ai_opponent(int ball_row, int ball_col, int paddle_row, int paddle_col){
    if (ball_col < COLS * 0.6) {
        if (paddle_row < ball_row) {
            return DOWN;
        } else if (paddle_row > ball_row) {
            return UP;
        }
    }
    return STOP;
}

int main(){
    char screen[ROWS][COLS];
    int ball_row = ROW_CENTER, ball_col = COL_CENTER;
    int ball_dir_row = -1, ball_dir_col = -1;
    int paddle_row = ROW_CENTER - PADDLE_HEIGHT / 2, paddle_col = 1;
    int key, ai_direction, game_over = 0;

    // Initialize random number generator
    srand(time(NULL));

    // Initialize screen
    int i, j;
    for (i = 0; i < ROWS; i++){
        for (j = 0; j < COLS; j++){
            if (i == 0 || i == ROWS - 1){
                screen[i][j] = '-';
            } else if (j == 0 || j == COLS - 1){
                screen[i][j] = '|';
            } else {
                screen[i][j] = ' ';
            }
        }
    }

    // Initialize ball direction randomly
    if (rand() % 2 == 0){
        ball_dir_row = 1;
    }
    if (rand() % 2 == 0){
        ball_dir_col = 1;
    }

    while (!game_over){
        // Move ball and paddle
        move_ball(&ball_row, &ball_col, &ball_dir_row, &ball_dir_col, screen);
        ai_direction = ai_opponent(ball_row, ball_col, paddle_row, paddle_col);
        move_paddle(&paddle_row, &paddle_col, ai_direction, screen);

        // Check for game over
        game_over = is_game_over(ball_row, ball_col, paddle_row, paddle_col);

        // Draw screen
        draw(screen);

        // Wait for input or sleep for a short while
        if (game_over){
            sleep(1);
            break;
        } else {
            usleep(50000);
        }
    }

    // Print game over message
    printf("Game over!\n");

    return 0;
}