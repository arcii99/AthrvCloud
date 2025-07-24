//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

#define WIDTH 80
#define HEIGHT 20

int ballX = WIDTH / 2, ballY = HEIGHT / 2; // initial position of the ball
int paddY = HEIGHT / 2 - 2; // initial position of the paddle
int padd2Y = HEIGHT / 2 - 2; // initial position of the AI's paddle
int score = 0, score2 = 0; // keep track of score

pthread_mutex_t ball_mutex, padd_mutex, padd2_mutex; // mutex for ball and paddles

void startInput() // function to start input mode
{
    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag &= ~ICANON;
    info.c_cc[VMIN] = 1;
    info.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &info);
}

void stopInput() // function to stop input mode
{
    struct termios info;
    tcgetattr(0, &info);
    info.c_lflag |= ICANON;
    tcsetattr(0, TCSANOW, &info);
}

void clearScreen() // function to clear the screen
{
    system("clear");
}

void drawBall() // function to draw ball
{
    pthread_mutex_lock(&ball_mutex);
    printf("\033[%d;%dH@", ballY, ballX);
    pthread_mutex_unlock(&ball_mutex);
}

void eraseBall() // function to erase ball
{
    pthread_mutex_lock(&ball_mutex);
    printf("\033[%d;%dH ", ballY, ballX);
    pthread_mutex_unlock(&ball_mutex);
}

void drawPadd() // function to draw paddle
{
    pthread_mutex_lock(&padd_mutex);
    printf("\033[%d;%dH#", paddY, 1);
    pthread_mutex_unlock(&padd_mutex);
}

void erasePadd() // function to erase paddle
{
    pthread_mutex_lock(&padd_mutex);
    printf("\033[%d;%dH     ", paddY, 1);
    pthread_mutex_unlock(&padd_mutex);
}

void drawPadd2() // function to draw AI's paddle
{
    pthread_mutex_lock(&padd2_mutex);
    printf("\033[%d;%dH#", padd2Y, WIDTH - 4);
    pthread_mutex_unlock(&padd2_mutex);
}

void erasePadd2() // function to erase AI's paddle
{
    pthread_mutex_lock(&padd2_mutex);
    printf("\033[%d;%dH     ", padd2Y, WIDTH - 4);
    pthread_mutex_unlock(&padd2_mutex);
}

void *moveBall(void *arg) // thread to move the ball
{
    int xDir = 1, yDir = 1;

    while (1)
    {
        usleep(50000);

        if (ballX == WIDTH - 2 || ballX == 2)
        {
            xDir *= -1;
        }

        if (ballY == HEIGHT - 1 || ballY == 1)
        {
            yDir *= -1;
        }

        eraseBall();
        ballX += xDir;
        ballY += yDir;
        drawBall();
    }
}

void *movePadd(void *arg) // thread to move the paddle
{
    startInput();
    int c;

    while (1)
    {
        c = getchar();

        if (c == 'w' && paddY > 1)
        {
            erasePadd();
            paddY--;
            drawPadd();
        }

        if (c == 's' && paddY < HEIGHT - 4)
        {
            erasePadd();
            paddY++;
            drawPadd();
        }

        if (c == 'q')
        {
            stopInput();
            pthread_exit(NULL);
        }
    }
}

void *movePadd2(void *arg) // thread to move the AI's paddle
{
    while (1)
    {
        usleep(100000);

        if (ballY > padd2Y + 2 && padd2Y < HEIGHT - 4)
        {
            erasePadd2();
            padd2Y++;
            drawPadd2();
        }

        if (ballY < padd2Y + 2 && padd2Y > 1)
        {
            erasePadd2();
            padd2Y--;
            drawPadd2();
        }
    }
}

void *checkScore(void *arg) // thread to check for scoring
{
    while (1)
    {
        usleep(100000);

        if (ballX == 1)
        {
            pthread_mutex_lock(&ball_mutex);
            ballX = WIDTH / 2;
            ballY = HEIGHT / 2;
            pthread_mutex_unlock(&ball_mutex);
            eraseBall();
            drawBall();
            score2++;
            printf("\033[%d;%dHSCORE: %d - %d", HEIGHT + 1, 1, score, score2);
        }

        if (ballX == WIDTH - 2)
        {
            pthread_mutex_lock(&ball_mutex);
            ballX = WIDTH / 2;
            ballY = HEIGHT / 2;
            pthread_mutex_unlock(&ball_mutex);
            eraseBall();
            drawBall();
            score++;
            printf("\033[%d;%dHSCORE: %d - %d", HEIGHT + 1, 1, score, score2);
        }
    }
}

int main()
{
    clearScreen();
    printf("\033[?25l"); // hide cursor
    pthread_mutex_init(&ball_mutex, NULL);
    pthread_mutex_init(&padd_mutex, NULL);
    pthread_mutex_init(&padd2_mutex, NULL);

    pthread_t ball, padd, padd2, score;

    pthread_create(&ball, NULL, moveBall, NULL);
    pthread_create(&padd, NULL, movePadd, NULL);
    pthread_create(&padd2, NULL, movePadd2, NULL);
    pthread_create(&score, NULL, checkScore, NULL);

    pthread_join(ball, NULL);
    pthread_join(padd, NULL);
    pthread_join(padd2, NULL);
    pthread_join(score, NULL);

    pthread_mutex_destroy(&ball_mutex);
    pthread_mutex_destroy(&padd_mutex);
    pthread_mutex_destroy(&padd2_mutex);

    return 0;
}