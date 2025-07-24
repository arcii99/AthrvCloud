//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 30

int x, y, vx, vy, paddle, score;
char board[HEIGHT][WIDTH];

void initialize_board()
{
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            board[i][j] = ' ';

    for(int i = 0; i < WIDTH; i++) {
        board[0][i] = '-';
        board[HEIGHT - 1][i] = '-';
    }

    for(int i = 0; i < HEIGHT; i++) {
        board[i][0] = '|';
        board[i][WIDTH - 1] = '|';
    }

    x = WIDTH / 2;
    y = HEIGHT / 2;
    vx = 1;
    vy = -1;
    paddle = WIDTH / 2;
    score = 0;

    board[y][x] = 'O';
    board[HEIGHT - 2][paddle - 1] = '_';
    board[HEIGHT - 2][paddle] = '_';
    board[HEIGHT - 2][paddle + 1] = '_';
}

void draw_board()
{
    system("clear");

    printf("Score: %d\n\n", score);

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++)
            printf("%c", board[i][j]);

        printf("\n");
    }
}

void move_ball()
{
    board[y][x] = ' ';

    x += vx;
    y += vy;

    if(board[y][x] == '_') {
        vy = -vy;
        score++;
        board[y][x] = 'O';
    }
    else if(y == HEIGHT - 2) {
        if(x >= paddle - 1 && x <= paddle + 1) {
            vy = -vy;
            score++;
            board[y][x] = 'O';
        }
        else {
            printf("Game Over!\n");
            exit(0);
        }
    }
    else {
        if(x == 0 || x == WIDTH - 1)
            vx = -vx;

        if(y == 0)
            vy = -vy;

        board[y][x] = 'O';
    }
}

void move_paddle_left()
{
    board[HEIGHT - 2][paddle + 1] = ' ';
    board[HEIGHT - 2][paddle - 1] = '_';
    paddle--;
}

void move_paddle_right()
{
    board[HEIGHT - 2][paddle - 1] = ' ';
    board[HEIGHT - 2][paddle + 1] = '_';
    paddle++;
}

int main()
{
    srand((unsigned) time(NULL));

    initialize_board();

    while(1) {
        draw_board();
        move_ball();

        int input = getchar();

        if(input == 'q')
            break;

        if(input == 'a' && paddle > 2)
            move_paddle_left();

        if(input == 'd' && paddle < WIDTH - 3)
            move_paddle_right();
    }

    return 0;
}