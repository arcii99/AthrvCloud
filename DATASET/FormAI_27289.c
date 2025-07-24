//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 60
#define HEIGHT 30
#define PADDLE_LENGTH 3
#define BALL_SIZE 1

#define AI_SPEED_MS 200

void clear_screen();
void draw_paddle(int x, int y);
void draw_ball(int x, int y);
void update_score(int score);
bool is_collision(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);
void move_paddle(int *y, bool up);
void move_ball(int *x, int *y, int *vx, int *vy, int *score, int *ai_y);
void ai_move(int ball_x, int ball_y, int *ai_y);

int main()
{
    srand(time(NULL));

    int paddle_y = HEIGHT / 2 - PADDLE_LENGTH / 2;
    int ball_x = WIDTH / 2, ball_y = HEIGHT / 2;
    int ball_vx = -1, ball_vy = rand() % 3 - 1;
    int score = 0;
    int ai_y = HEIGHT / 2 - PADDLE_LENGTH / 2;

    clear_screen();

    while (true)
    {
        move_ball(&ball_x, &ball_y, &ball_vx, &ball_vy, &score, &ai_y);
        ai_move(ball_x, ball_y, &ai_y);

        clear_screen();
        draw_paddle(0, paddle_y);
        draw_paddle(WIDTH - 1, ai_y);
        draw_ball(ball_x, ball_y);
        update_score(score);

        usleep(5000);
    }

    return 0;
}

void clear_screen()
{
    system("clear");
}

void draw_paddle(int x, int y)
{
    for (int i = 0; i < PADDLE_LENGTH; i++)
    {
        printf("\033[%d;%dH|\n", y + i, x + (x == 0 ? 0 : 1));
    }
}

void draw_ball(int x, int y)
{
    printf("\033[%d;%dHo\n", y, x);
}

void update_score(int score)
{
    printf("\033[1;1HScore: %d\n", score);
}

bool is_collision(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    return (bx1 <= ax2 && bx2 >= ax1 && by1 <= ay2 && by2 >= ay1);
}

void move_paddle(int *y, bool up)
{
    if (up)
    {
        if (*y > 0)
        {
            *y -= 1;
        }
    }
    else
    {
        if (*y < HEIGHT - PADDLE_LENGTH)
        {
            *y += 1;
        }
    }
}

void move_ball(int *x, int *y, int *vx, int *vy, int *score, int *ai_y)
{
    int old_x = *x, old_y = *y;
    *x += *vx;
    *y += *vy;

    if (*y <= 0 || *y >= HEIGHT - BALL_SIZE)
    {
        *vy = -*vy;
    }

    if (is_collision(0, *ai_y, 1, *ai_y + PADDLE_LENGTH - 1, *x, *y, *x, *y + BALL_SIZE - 1))
    {
        *vx = -*vx;
    }

    if (is_collision(WIDTH - 1, *y, WIDTH, *y + BALL_SIZE - 1, *x, *y, *x, *y + BALL_SIZE - 1))
    {
        *vx = -*vx;
        *score += 1;
        *y = rand() % (HEIGHT - BALL_SIZE);
        *vx = -1;
        *vy = rand() % 3 - 1;
    }

    if (*x < 0 || *x >= WIDTH)
    {
        // Game over
        printf("\033[%d;%dHLost!\n", HEIGHT / 2, WIDTH / 2 - 4);
        exit(0);
    }
}

void ai_move(int ball_x, int ball_y, int *ai_y)
{
    if (ball_y < *ai_y + PADDLE_LENGTH / 2)
    {
        move_paddle(ai_y, true);
    }
    else if (ball_y > *ai_y + PADDLE_LENGTH / 2)
    {
        move_paddle(ai_y, false);
    }

    usleep(AI_SPEED_MS * 1000);
}