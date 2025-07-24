//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<fcntl.h>

#define WIDTH 70
#define HEIGHT 20

#define PADDLE_SIZE 4
#define BALL_SPEED 25000

struct termios initial_settings, new_settings;

char getkey()
{
    char key;
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0,TCSANOW,&new_settings);
    key = getchar();
    tcsetattr(0,TCSANOW,&initial_settings);
    return key;
}

void draw_board(char board[][WIDTH])
{
    int x,y;
    for(y = 0; y < HEIGHT; ++y) {
        for(x = 0; x < WIDTH; ++x)
            putchar(board[y][x]);
        putchar('\n');
    }
}

void paddle_ai(int *paddle_pos, int ball_pos_y)
{
    int paddle_center = *paddle_pos + PADDLE_SIZE / 2;
    if(ball_pos_y < paddle_center - 1)
        --*paddle_pos;
    else if(ball_pos_y > paddle_center + 1)
        ++*paddle_pos;
}

int main()
{
    char board[HEIGHT][WIDTH];
    int x,y;
    for(y = 0; y < HEIGHT; ++y)
        for(x = 0; x < WIDTH; ++x)
            board[y][x] = ' ';
    for(x = 0; x < WIDTH; ++x)
        board[0][x] = board[HEIGHT - 1][x] = '-';
    for(y = 1; y < HEIGHT - 1; ++y)
        board[y][0] = board[y][WIDTH - 1] = '|';
    int ball_pos_x = WIDTH / 2, ball_pos_y = HEIGHT / 2;
    int ball_vel_x = -1, ball_vel_y = -1;
    int paddle_pos_left = HEIGHT / 2 - PADDLE_SIZE / 2;
    int paddle_pos_right = HEIGHT / 2 - PADDLE_SIZE / 2;
    int left_player_score = 0, right_player_score = 0;
    while(1) {
        draw_board(board);
        usleep(BALL_SPEED);
        ball_pos_x += ball_vel_x;
        ball_pos_y += ball_vel_y;
        if(ball_pos_x == 1) {
            if(ball_pos_y >= paddle_pos_left &&
                ball_pos_y < paddle_pos_left + PADDLE_SIZE) {
                ball_vel_x = -ball_vel_x;
                int diff = ball_pos_y - (paddle_pos_left + PADDLE_SIZE / 2);
                ball_vel_y = diff / 2;
            }
            else {
                ++right_player_score;
                ball_pos_x = WIDTH / 2;
                ball_pos_y = HEIGHT / 2;
                ball_vel_y = ball_vel_y > 0 ? -1 : 1;
                ball_vel_x = -ball_vel_x;
            }
        }
        else if(ball_pos_x == WIDTH - 2) {
            if(ball_pos_y >= paddle_pos_right &&
                ball_pos_y < paddle_pos_right + PADDLE_SIZE) {
                ball_vel_x = -ball_vel_x;
                int diff = ball_pos_y - (paddle_pos_right + PADDLE_SIZE / 2);
                ball_vel_y = diff / 2;
            }
            else {
                ++left_player_score;
                ball_pos_x = WIDTH / 2;
                ball_pos_y = HEIGHT / 2;
                ball_vel_y = ball_vel_y > 0 ? -1 : 1;
                ball_vel_x = -ball_vel_x;
            }
        }
        if(ball_pos_y == 0 || ball_pos_y == HEIGHT - 1)
            ball_vel_y = -ball_vel_y;
        board[ball_pos_y][ball_pos_x] = '*';
        if(left_player_score >= 5 || right_player_score >= 5)
            break;
        char key;
        if(ball_vel_x < 0) {
            if(ball_pos_y < paddle_pos_left + PADDLE_SIZE / 2)
                --paddle_pos_left;
            else
                ++paddle_pos_left;
        }
        else {
            paddle_ai(&paddle_pos_right,ball_pos_y);
        }
        key = getkey();
        if(key == 'w' && paddle_pos_left > 1)
            --paddle_pos_left;
        if(key == 's' && paddle_pos_left < HEIGHT - PADDLE_SIZE - 1)
            ++paddle_pos_left;
        for(y = 0; y < HEIGHT; ++y)
            board[y][2] = board[y][WIDTH - 3] = ' ';
        for(y = paddle_pos_left; y < paddle_pos_left + PADDLE_SIZE; ++y)
            board[y][2] = '|';
        for(y = paddle_pos_right; y < paddle_pos_right + PADDLE_SIZE; ++y)
            board[y][WIDTH - 3] = '|';
    }
    draw_board(board);
    if(left_player_score > right_player_score)
        printf("Player 1 wins!\n");
    else
        printf("Player 2 wins!\n");
    return 0;
}