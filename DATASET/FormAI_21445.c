//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 60
#define HEIGHT 20

#define AI_SPEED 20000

#define UP 'w'
#define DOWN 's'

// Function to set terminal input
void set_input_mode(void)
{
    struct termios tty_attr;

    // Get terminal attributes
    tcgetattr(STDIN_FILENO, &tty_attr);

    // Clear echo flag
    tty_attr.c_lflag &= ~(ECHO);

    // Set new attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &tty_attr);
}

// Function to get terminal input (non-blocking)
int get_input(void)
{
    int c = -1;

    // Set terminal to non-blocking mode
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    // Get input
    c = getchar();

    // Set terminal to blocking mode
    fcntl(STDIN_FILENO, F_SETFL, ~O_NONBLOCK);

    return c;
}

// Struct to represent ball
typedef struct Ball
{
    int x, y;
    int vx, vy;
} Ball;

// Struct to represent paddle
typedef struct Paddle
{
    int x, y;
    int size;
    char up_key, down_key;
} Paddle;

// Initialize ball
void init_ball(Ball *ball)
{
    ball->x = WIDTH / 2;
    ball->y = HEIGHT / 2;
    ball->vx = 1;
    ball->vy = 1;
}

// Initialize paddle
void init_paddle(Paddle *paddle, int x, int y, int size, char up_key, char down_key)
{
    paddle->x = x;
    paddle->y = y;
    paddle->size = size;
    paddle->up_key = up_key;
    paddle->down_key = down_key;
}

// Draw ball
void draw_ball(Ball ball)
{
    printf("\e[%d;%dH@", ball.y, ball.x);
    fflush(stdout);
}

// Draw paddle
void draw_paddle(Paddle paddle)
{
    int i;

    for (i = 0; i < paddle.size; i++)
    {
        printf("\e[%d;%dH#", paddle.y + i, paddle.x);
        fflush(stdout);
    }
}

// Erase ball
void erase_ball(Ball ball)
{
    printf("\e[%d;%dH ", ball.y, ball.x);
    fflush(stdout);
}

// Erase paddle
void erase_paddle(Paddle paddle)
{
    int i;

    for (i = 0; i < paddle.size; i++)
    {
        printf("\e[%d;%dH ", paddle.y + i, paddle.x);
        fflush(stdout);
    }
}

// Move ball
void move_ball(Ball *ball, Paddle player, Paddle ai)
{
    // Erase ball
    erase_ball(*ball);

    // Check for paddle collisions
    if (ball->x == player.x + 1 && ball->y >= player.y && ball->y <= player.y + player.size - 1)
    {
        ball->vx = -ball->vx;
    }
    else if (ball->x == ai.x - 1 && ball->y >= ai.y && ball->y <= ai.y + ai.size - 1)
    {
        ball->vx = -ball->vx;
    }

    // Check for wall collisions
    if (ball->y == 0)
    {
        ball->vy = -ball->vy;
    }
    else if (ball->y == HEIGHT - 1)
    {
        ball->vy = -ball->vy;
    }

    // Move ball
    ball->x += ball->vx;
    ball->y += ball->vy;

    // Draw ball
    draw_ball(*ball);
}

// Move paddle
void move_paddle(Paddle *paddle, char input)
{
    // Erase paddle
    erase_paddle(*paddle);

    // Move paddle depending on input
    if (input == paddle->up_key)
    {
        if (paddle->y > 0)
        {
            paddle->y--;
        }
    }
    else if (input == paddle->down_key)
    {
        if (paddle->y + paddle->size - 1 < HEIGHT - 1)
        {
            paddle->y++;
        }
    }

    // Draw paddle
    draw_paddle(*paddle);
}

// AI function
void ai_move(Ball ball, Paddle *ai)
{
    // Only move if ball is moving towards AI
    if (ball.vx < 0)
    {
        // Erase paddle
        erase_paddle(*ai);

        // Move paddle towards ball
        if (ball.y < ai->y + ai->size / 2)
        {
            ai->y--;
        }
        else if (ball.y > ai->y + ai->size / 2)
        {
            ai->y++;
        }

        // Draw paddle
        draw_paddle(*ai);
    }
}

// Check if game is over
int is_game_over(Ball ball)
{
    if (ball.x < 0 || ball.x > WIDTH - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    char input = 0;
    int game_over = 0;
    int ai_timer = 0;

    // Set terminal input mode
    set_input_mode();

    // Initialize ball and paddles
    Ball ball;
    init_ball(&ball);

    Paddle player;
    init_paddle(&player, 1, HEIGHT / 2 - 2, 5, UP, DOWN);

    Paddle ai;
    init_paddle(&ai, WIDTH - 2, HEIGHT / 2 - 2, 5, ' ', ' ');

    // Main game loop
    while (!game_over)
    {
        // Move ball
        move_ball(&ball, player, ai);

        // Get input
        input = get_input();

        // Move player paddle
        move_paddle(&player, input);

        // Move AI paddle
        ai_timer++;

        if (ai_timer >= AI_SPEED)
        {
            ai_move(ball, &ai);
            ai_timer = 0;
        }

        // Check if game is over
        game_over = is_game_over(ball);

        // Slow down loop
        usleep(10000);
    }

    // Game over message
    printf("\e[%d;%dHGame Over!", HEIGHT / 2, WIDTH / 2 - 5);
    fflush(stdout);

    // Reset terminal input mode
    tcsetattr(STDIN_FILENO, TCSANOW, &(struct termios){0});

    return 0;
}