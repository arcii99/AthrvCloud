//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <termios.h>

#define MAX_PADDLE_SPEED 2
#define MAX_BALL_SPEED 2

#define PADDLE_LENGTH 5

#define BLOCK_WIDTH 5
#define BLOCK_HEIGHT 3

#define ROWS_OF_BLOCKS 8
#define COLS_OF_BLOCKS 12

#define GAME_SPEED 80000

pthread_t thread_id;
bool game_over = false;

struct termios orig_termios;

typedef struct Block
{
    int x;
    int y;
    bool active;
} Block;

typedef struct Ball
{
    int x;
    int y;
    int x_vel;
    int y_vel;
} Ball;

typedef struct Paddle
{
    int x;
    int y;
    int x_vel;
    int y_vel;
} Paddle;

typedef struct Game
{
    Block blocks[ROWS_OF_BLOCKS][COLS_OF_BLOCKS];
    Ball ball;
    Paddle paddle;
    int score;
    bool win;
} Game;

Game game;

void reset_terminal()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void disable_canonical()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(reset_terminal);

    struct termios new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_termios);
}

void* listen_for_input(void* arg)
{
    while (!game_over)
    {
        int input = getchar();

        switch (input)
        {
            case 'a':
            {
                game.paddle.x_vel = -MAX_PADDLE_SPEED;
                break;
            }
            case 'd':
            {
                game.paddle.x_vel = MAX_PADDLE_SPEED;
                break;
            }
            default:
            {
                game.paddle.x_vel = 0;
                break;
            }
        }
    }

    pthread_exit(NULL);
}

void init_game()
{
    srand(time(NULL));

    // Initialize blocks
    for (int i = 0; i < ROWS_OF_BLOCKS; i++)
    {
        for (int j = 0; j < COLS_OF_BLOCKS; j++)
        {
            game.blocks[i][j].x = j * BLOCK_WIDTH;
            game.blocks[i][j].y = i * BLOCK_HEIGHT;
            game.blocks[i][j].active = true;
        }
    }

    // Initialize ball
    game.ball.x = COLS_OF_BLOCKS * BLOCK_WIDTH / 2;
    game.ball.y = ROWS_OF_BLOCKS * BLOCK_HEIGHT + 1;
    game.ball.x_vel = rand() % (MAX_BALL_SPEED + 1) - MAX_BALL_SPEED / 2;
    game.ball.y_vel = -MAX_BALL_SPEED;

    // Initialize paddle
    game.paddle.x = (COLS_OF_BLOCKS * BLOCK_WIDTH) / 2 - PADDLE_LENGTH / 2;
    game.paddle.y = (ROWS_OF_BLOCKS + 1) * BLOCK_HEIGHT;
    game.paddle.x_vel = 0;
    game.paddle.y_vel = 0;

    // Initialize score and win condition
    game.score = 0;
    game.win = false;
}

void draw_block(int x, int y, bool active)
{
    printf("\033[%d;%dH", y + 1, x + 1);

    if (active)
    {
        printf("\033[43m  \033[0m");
    }
    else
    {
        printf("  ");
    }
}

void draw_ball(int x, int y)
{
    printf("\033[%d;%dH", y + 1, x + 1);
    printf("\033[42m  \033[0m");
}

void erase_ball(int x, int y)
{
    printf("\033[%d;%dH", y + 1, x + 1);
    printf("\033[0m  ");
}

void draw_paddle(int x, int y)
{
    for (int i = 0; i < PADDLE_LENGTH; i++)
    {
        printf("\033[%d;%dH", y + 1, x + 1 + i);
        printf("\033[41m  \033[0m");
    }
}

void erase_paddle(int x, int y)
{
    for (int i = 0; i < PADDLE_LENGTH; i++)
    {
        printf("\033[%d;%dH", y + 1, x + 1 + i);
        printf("\033[0m  ");
    }
}

void draw_game()
{
    // Clear screen
    printf("\033[2J");

    // Draw blocks
    for (int i = 0; i < ROWS_OF_BLOCKS; i++)
    {
        for (int j = 0; j < COLS_OF_BLOCKS; j++)
        {
            draw_block(game.blocks[i][j].x, game.blocks[i][j].y, game.blocks[i][j].active);
        }
    }

    // Draw ball
    draw_ball(game.ball.x, game.ball.y);

    // Draw paddle
    draw_paddle(game.paddle.x, game.paddle.y);

    // Draw score
    printf("\033[%d;%dH", ROWS_OF_BLOCKS * BLOCK_HEIGHT + 3, 1);
    printf("Score: %d", game.score);

    // Draw win message
    if (game.win)
    {
        printf("\033[%d;%dH", ROWS_OF_BLOCKS * BLOCK_HEIGHT + 4, 1);
        printf("Congratulations, you won!");
    }

    fflush(stdout);
}

void update_ball()
{
    // Move ball
    game.ball.x += game.ball.x_vel;
    game.ball.y += game.ball.y_vel;

    // Check for collision with walls
    if (game.ball.x <= 0 || game.ball.x >= COLS_OF_BLOCKS * BLOCK_WIDTH - 1)
    {
        game.ball.x_vel = -game.ball.x_vel;
    }

    if (game.ball.y <= 0)
    {
        game.ball.y_vel = -game.ball.y_vel;
    }

    // Check for collision with paddle
    if (game.ball.y == game.paddle.y - 1)
    {
        if (game.ball.x >= game.paddle.x && game.ball.x <= game.paddle.x + PADDLE_LENGTH - 1)
        {
            game.ball.y_vel = -game.ball.y_vel;

            int middle_of_paddle = game.paddle.x + PADDLE_LENGTH / 2;
            int distance_from_middle = game.ball.x - middle_of_paddle;

            game.ball.x_vel = distance_from_middle / (PADDLE_LENGTH / 2) * MAX_BALL_SPEED;
        }
    }

    // Check for collision with blocks
    int c = game.ball.x / BLOCK_WIDTH;
    int r = game.ball.y / BLOCK_HEIGHT;

    if (r >= 0 && r < ROWS_OF_BLOCKS && c >= 0 && c < COLS_OF_BLOCKS && game.blocks[r][c].active)
    {
        game.blocks[r][c].active = false;

        int block_center_x = c * BLOCK_WIDTH + BLOCK_WIDTH / 2;
        int block_center_y = r * BLOCK_HEIGHT + BLOCK_HEIGHT / 2;

        int diff_x = game.ball.x - block_center_x;
        int diff_y = game.ball.y - block_center_y;

        if (abs(diff_x) > abs(diff_y))
        {
            game.ball.x_vel = -game.ball.x_vel;
        }
        else
        {
            game.ball.y_vel = -game.ball.y_vel;
        }

        game.score++;

        if (game.score == ROWS_OF_BLOCKS * COLS_OF_BLOCKS)
        {
            game.win = true;
        }
    }

    // Check for game over
    if (game.ball.y >= ROWS_OF_BLOCKS * BLOCK_HEIGHT + 1)
    {
        game_over = true;
    }
}

void update_paddle()
{
    // Move paddle
    game.paddle.x += game.paddle.x_vel;

    // Keep paddle within bounds
    if (game.paddle.x < 0)
    {
        game.paddle.x = 0;
    }
    else if (game.paddle.x + PADDLE_LENGTH > COLS_OF_BLOCKS * BLOCK_WIDTH)
    {
        game.paddle.x = COLS_OF_BLOCKS * BLOCK_WIDTH - PADDLE_LENGTH;
    }
}

void sleep_nano(int n)
{
    struct timespec tspec;
    tspec.tv_sec = 0;
    tspec.tv_nsec = n;

    nanosleep(&tspec, NULL);
}

void* game_loop(void* arg)
{
    while (!game_over)
    {
        update_ball();
        update_paddle();
        draw_game();
        sleep_nano(GAME_SPEED);
    }

    pthread_exit(NULL);
}

int main()
{
    disable_canonical();

    init_game();

    pthread_create(&thread_id, NULL, &listen_for_input, NULL);
    game_loop(NULL);

    pthread_join(thread_id, NULL);

    return 0;
}