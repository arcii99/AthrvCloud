//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define WIDTH 80
#define HEIGHT 24
#define PADDLE_LENGTH 7
#define BALL_SIZE 2

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

static struct termios orig_termios;

void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void clearScreen()
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void drawPaddle(int x, int y)
{
    for (int i = y - PADDLE_LENGTH / 2; i <= y + PADDLE_LENGTH / 2; i++)
    {
        printf("\033[%d;%dH", i, x);
        printf("|");
    }
}

void drawBall(int x, int y)
{
    printf("\033[%d;%dH", y, x);
    printf("O");
}

void drawBrick(int x, int y)
{
    printf("\033[%d;%dH", y, x);
    printf("=");
}

void initBricks(int bricks[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i > 0 && i < HEIGHT / 3 && j > 0 && j < WIDTH - 1 && ((j % 4) == 1))
            {
                bricks[i][j] = 1;
            }
            else
            {
                bricks[i][j] = 0;
            }
        }
    }
}

void drawBricks(int bricks[HEIGHT][WIDTH])
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (bricks[i][j])
            {
                drawBrick(j, i);
            }
        }
    }
}

int paddleHitsBall(int paddleX, int paddleY, int ballX, int ballY, int lastBallX)
{
    int paddleTop = paddleY - PADDLE_LENGTH / 2;
    int paddleBottom = paddleY + PADDLE_LENGTH / 2;

    if (lastBallX < paddleX && ballX >= paddleX)
    {
        int distance = ballY - (paddleY - PADDLE_LENGTH / 2);
        int quadrant = distance / ((PADDLE_LENGTH - 1) / 3);
        if (quadrant == 0)
        {
            return -2;
        }
        else if (quadrant == 1)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int ballHitsWall(int ballX, int ballY, int *dx, int *dy, int bricks[HEIGHT][WIDTH])
{
    if (ballX <= 1 || ballX >= WIDTH - BALL_SIZE)
    {
        *dx = -(*dx);
    }

    if (ballY <= 0)
    {
        *dy = -(*dy);
    }

    if (ballY >= HEIGHT - BALL_SIZE)
    {
        return -1;
    }

    int brickX = ballX + (*dx);
    int brickY = ballY + (*dy);

    if (bricks[brickY][brickX])
    {
        bricks[brickY][brickX] = 0;
        *dy = -(*dy);
        return 1;
    }

    return 0;
}

int main()
{
    srand(time(NULL));
    enableRawMode();

    int paddleX = WIDTH / 2;
    int paddleY = HEIGHT - PADDLE_LENGTH / 2;
    int ballX = WIDTH / 2;
    int ballY = HEIGHT / 2;
    int dx = 1;
    int dy = 1;

    int bricks[HEIGHT][WIDTH];
    initBricks(bricks);

    int score = 0;
    int lives = 3;

    clearScreen();

    while (1)
    {
        // Move paddle
        int c = 0;
        if (read(STDIN_FILENO, &c, sizeof(c)) == -1)
            break;

        switch (c)
        {
        case 'a':
            paddleX = MAX(paddleX - 2, BALL_SIZE + 1);
            break;
        case 'd':
            paddleX = MIN(paddleX + 2, WIDTH - BALL_SIZE - 1);
            break;
        case 'q':
            goto GAMEOVER;
        }

        // Clear screen
        clearScreen();

        // Draw paddle
        drawPaddle(paddleX, paddleY);

        // Draw bricks
        drawBricks(bricks);

        // Check if ball hits wall or bricks
        int result = ballHitsWall(ballX, ballY, &dx, &dy, bricks);
        if (result == -1)
        {
            lives--;
            ballX = WIDTH / 2;
            ballY = HEIGHT / 2;
            dx = (rand() % 2 == 0) ? 1 : -1;
            dy = 1;
            if (lives == 0)
            {
                goto GAMEOVER;
            }
        }
        else if (result == 1)
        {
            score += 10;
        }

        // Check if ball hits paddle
        int paddleResult = paddleHitsBall(paddleX, paddleY, ballX, ballY, ballX - dx);
        if (paddleResult != 0)
        {
            dx = -dx;
            if (paddleResult == -2)
            {
                dy = -1;
            }
            else if (paddleResult == -1)
            {
                dy = 0;
            }
            else
            {
                dy = 1;
            }

            score++;
        }

        // Move ball
        ballX += dx;
        ballY += dy;

        // Draw ball
        drawBall(ballX - BALL_SIZE / 2, ballY - BALL_SIZE / 2);

        // Draw score
        printf("\033[%d;%dH", HEIGHT + 1, 0);
        printf("Score: %d", score);

        // Draw lives
        printf("\033[%d;%dH", HEIGHT + 1, WIDTH - 10);
        printf("Lives: %d", lives);

        fflush(stdout);
        usleep(50000); // 50 ms
    }

GAMEOVER:
    clearScreen();
    printf("\033[%d;%dH", HEIGHT / 2, WIDTH / 2 - 4);
    printf("GAME OVER");
    disableRawMode();
    return 0;
}