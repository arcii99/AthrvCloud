//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define HEIGHT      20
#define WIDTH       30
#define PADDLE_SIZE  3
#define BALL_X       15
#define BALL_Y       10
#define USER_PADDLE_X       1
#define AI_PADDLE_X       28

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main(void)
{
    char screen[HEIGHT][WIDTH + 1];
    int i, j, temp;
    int ball_x = BALL_X;
    int ball_y = BALL_Y;
    int dx = 1;
    int dy = 1;
    int user_paddle_y = HEIGHT / 2 - PADDLE_SIZE / 2;
    int ai_paddle_y = HEIGHT / 2 - PADDLE_SIZE / 2;
    int score = 0;

    for(i = 0; i < HEIGHT; i++)
    {
        for(j = 0; j < WIDTH; j++)
        {
            screen[i][j] = ' ';
        }

        screen[i][j] = '\0';
    }

    while(1)
    {
        if(kbhit())
        {
            switch(getchar())
            {
                case 'w':
                    if(user_paddle_y > 1)
                    {
                        user_paddle_y--;
                    }

                    break;

                case 's':
                    if(user_paddle_y < HEIGHT - PADDLE_SIZE - 1)
                    {
                        user_paddle_y++;
                    }

                    break;

                case 'q':
                    return 0;

                default:
                    break;
            }
        }

        ball_x += dx;
        ball_y += dy;

        if(ball_y < 0 || ball_y >= HEIGHT)
        {
            dy = -dy;
        }

        if(ball_x == USER_PADDLE_X + 1 && ball_y >= user_paddle_y && ball_y < user_paddle_y + PADDLE_SIZE)
        {
            dx = -dx;
            score++;
        }

        if(ball_x == AI_PADDLE_X - 1 && ball_y >= ai_paddle_y && ball_y < ai_paddle_y + PADDLE_SIZE)
        {
            dx = -dx;
        }

        if(ball_x < 0)
        {
            printf("You lose! Score: %d\n", score);
            return 0;
        }

        if(ball_x >= WIDTH)
        {
            printf("You win! Score: %d\n", score);
            return 0;
        }

        if(ball_x == AI_PADDLE_X)
        {
            if(ball_y < ai_paddle_y + PADDLE_SIZE / 2)
            {
                ai_paddle_y--;
            }
            else if(ball_y > ai_paddle_y + PADDLE_SIZE / 2)
            {
                ai_paddle_y++;
            }
        }

        for(i = 0; i < HEIGHT; i++)
        {
            for(j = 0; j < WIDTH; j++)
            {
                screen[i][j] = ' ';
            }

            screen[i][j] = '\0';
        }

        for(i = 0; i < PADDLE_SIZE; i++)
        {
            screen[user_paddle_y + i][USER_PADDLE_X] = '|';
            screen[ai_paddle_y + i][AI_PADDLE_X] = '|';
        }

        screen[ball_y][ball_x] = 'O';

        for(i = 0; i < HEIGHT; i++)
        {
            printf("%s\n", screen[i]);
        }

        printf("Score: %d\n", score);

        usleep(1000000 / 60);
        printf("\033[2J");
        printf("\033[%d;%dH", 0, 0);
    }

    return 0;
}