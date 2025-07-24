//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define WIDTH 30
#define HEIGHT 15

int ball_x, ball_y, padd_y1, padd_y2;
int ball_vx, ball_vy;

void draw_game()
{
    int i, j;
    system("clear");
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if ((i == ball_y) && (j == ball_x))
            {
                printf("o");
            }
            else if ((i == padd_y1) && (j == 0))
            {
                printf("|");
            }
            else if ((i == padd_y1) && (j == 1))
            {
                printf("|");
            }
            else if ((i == padd_y1) && (j == 2))
            {
                printf("|");
            }
            else if ((i == padd_y1) && (j == 3))
            {
                printf("|");
            }
            else if ((i == padd_y2) && (j == WIDTH - 1))
            {
                printf("|");
            }
            else if ((i == padd_y2) && (j == WIDTH - 2))
            {
                printf("|");
            }
            else if ((i == padd_y2) && (j == WIDTH - 3))
            {
                printf("|");
            }
            else if ((i == padd_y2) && (j == WIDTH - 4))
            {
                printf("|");
            }
            else if ((i == 0) || (i == HEIGHT - 1))
            {
                printf("-");
            }
            else if ((j == 0) || (j == WIDTH - 1))
            {
                printf("|");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void init_game()
{
    ball_x = WIDTH / 2;
    ball_y = HEIGHT / 2;
    padd_y1 = HEIGHT / 2 - 2;
    padd_y2 = HEIGHT / 2 - 2;
    ball_vx = 1;
    ball_vy = 1;
}

void* ai_move_padd()
{
    while (1)
    {
        if (ball_y < padd_y2)
        {
            padd_y2--;
        }
        if (ball_y > padd_y2 + 3)
        {
            padd_y2++;
        }
        usleep(10000);
    }
}

int main()
{
    pthread_t padd_thread;
    srand(time(NULL));

    init_game();
    draw_game();

    pthread_create(&padd_thread, NULL, ai_move_padd, NULL);

    while (1)
    {
        ball_x += ball_vx;
        ball_y += ball_vy;

        if ((ball_y < 1) || (ball_y >= HEIGHT - 1))
        {
            ball_vy = -ball_vy;
        }

        if (ball_x <= 0)
        {
            printf("AI wins!\n");
            return 0;
        }

        if (ball_x >= WIDTH - 1)
        {
            printf("You win!\n");
            return 0;
        }

        if ((ball_x == 1) && (ball_y >= padd_y1) && (ball_y < padd_y1 + 4))
        {
            ball_vx = -ball_vx;
        }

        if ((ball_x == WIDTH - 2) && (ball_y >= padd_y2) && (ball_y < padd_y2 + 4))
        {
            ball_vx = -ball_vx;
        }

        draw_game();
        usleep(30000);
    }

    return 0;
}