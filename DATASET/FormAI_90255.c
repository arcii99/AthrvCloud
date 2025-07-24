//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define ROWS 25
#define COLS 80
#define PADDLE_LENGTH 5

struct paddle{
    int x;
    int y[PADDLE_LENGTH];
};
typedef struct paddle Paddle;

struct ball{
    int x;
    int y;
    int xdir;
    int ydir;
};
typedef struct ball Ball;

// function to set terminal to raw mode
void set_raw_mode(){
    struct termios new_termios;
    tcgetattr(0, &new_termios);
    new_termios.c_lflag &= ~ICANON;
    new_termios.c_cc[VTIME] = 0;
    new_termios.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_termios);
}

// function to create the paddle
Paddle initialize_paddle(){
    Paddle paddle;
    paddle.x = COLS/2 - 3;
    for(int i=0; i<PADDLE_LENGTH; i++){
        paddle.y[i] = ROWS - 2;
    }
    return paddle;
}

// function to create the ball
Ball initialize_ball(){
    Ball ball;
    ball.x = COLS/2;
    ball.y = ROWS/2;
    ball.xdir = 1;
    ball.ydir = -1;
    return ball;
}

// function to move the paddle based on user input
void move_paddle(Paddle *paddle){
    int c = getchar();
    if(c == 'a' && paddle->x > 0){
        paddle->x--;
    }
    else if(c == 'd' && paddle->x < COLS - PADDLE_LENGTH){
        paddle->x++;
    }
}

// function to move the ball
void move_ball(Ball *ball){
    ball->x += ball->xdir;
    ball->y += ball->ydir;
    if(ball->x == 0 || ball->x == COLS-1){
        ball->xdir = -ball->xdir;
    }
    if(ball->y == 0){
        ball->ydir = -ball->ydir;
    }
}

// function to check if the ball hits the paddle
bool check_hit(Paddle *paddle, int ball_x, int ball_y){
    for(int i=0; i<PADDLE_LENGTH; i++){
        if(paddle->x+i == ball_x && paddle->y[i] == ball_y){
            return true;
        }
    }
    return false;
}

// function to play the game
void play_game(){
    set_raw_mode();
    Paddle paddle = initialize_paddle();
    Ball ball = initialize_ball();
    while(true){
        system("clear");
        move_paddle(&paddle);
        move_ball(&ball);
        if(check_hit(&paddle, ball.x, ball.y)){
            ball.ydir = -ball.ydir;
        }
        if(ball.y == ROWS-1){
            printf("Game Over\n");
            return;
        }
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(i == ball.y && j == ball.x){
                    printf("O");
                }
                else if(i == ROWS - 1){
                    printf("-");
                }
                else if(i == paddle.y[0] && j == paddle.x){
                    printf("|");
                }
                else if(i == paddle.y[0]){
                    printf(" ");
                }
                else if(i == ROWS - 2 && (j >= paddle.x && j < paddle.x + PADDLE_LENGTH)){
                    printf("-");
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
        usleep(100000);
    }
}

// main function to run the game
int main(){
    play_game();
    return 0;
}