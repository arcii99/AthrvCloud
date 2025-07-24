//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>

#define clearScreen() printf("\033[H\033[J")
#define ROWS 20
#define COLS 45

int bricks[ROWS][COLS];
int paddlePos;
int ballPos[2];
int ballDir[2];
int score;
int lives = 3;

void initializeGame();
void displayGame();
void movePaddle(int);
void moveBall();
void updateScore(int);
void gameOver();
int kbhit();
void setTerminal();
void resetTerminal();
void sigintHandler(int);

int main()
{
    setTerminal();
    initializeGame();
    displayGame();

    signal(SIGINT, sigintHandler);
    while (1)
    {
        if (kbhit())
            movePaddle(getchar());
        moveBall();
        displayGame();
        usleep(100000);
    }
    resetTerminal();
    return 0;
}

void initializeGame()
{
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            bricks[i][j] = rand() % 2;

    paddlePos = COLS / 2 - 4;
    ballPos[0] = ROWS - 2;
    ballPos[1] = paddlePos + 3;
    ballDir[0] = -1;
    ballDir[1] = 1;
    score = 0;
}

void displayGame()
{
    clearScreen();
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == ROWS - 1 && j >= paddlePos && j < paddlePos + 8)
                printf("~");
            else if (i == ballPos[0] && j == ballPos[1])
                printf("o");
            else if (bricks[i][j])
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("Score: %d\tLives: %d\n", score, lives);
}

void movePaddle(int key)
{
    switch (key)
    {
    case 'a':
        if (paddlePos > 0)
            paddlePos--;
        break;
    case 'd':
        if (paddlePos < COLS - 8)
            paddlePos++;
        break;
    default:
        break;
    }
}

void moveBall()
{
    ballPos[0] += ballDir[0];
    ballPos[1] += ballDir[1];

    if (ballPos[0] == ROWS - 1)
    {
        if (ballPos[1] >= paddlePos && ballPos[1] <= paddlePos + 7)
        {
            ballDir[0] *= -1;
            ballDir[1] = rand() % 2 - 1;
        }
        else
        {
            lives--;
            if (lives == 0)
                gameOver();
            else
            {
                ballPos[0] = ROWS - 2;
                ballPos[1] = paddlePos + 3;
                ballDir[0] = -1;
                ballDir[1] = 1;
                usleep(100000);
            }
        }
    }

    if (ballPos[1] == 0 || ballPos[1] == COLS - 1)
        ballDir[1] *= -1;

    if (ballPos[0] >= 0 && ballPos[0] < ROWS && ballPos[1] >= 0 && ballPos[1] < COLS && bricks[ballPos[0]][ballPos[1]])
    {
        bricks[ballPos[0]][ballPos[1]] = 0;
        score += 10;
        ballDir[0] *= -1;
    }

    if (score == ROWS * COLS * 10)
        gameOver();
}

void updateScore(int points)
{
    score += points;
}

void gameOver()
{
    clearScreen();
    printf("Romeo and Juliet died for love.\n");
    exit(0);
}

int kbhit()
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

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void setTerminal()
{
    struct termios term;

    tcgetattr(0, &term);

    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);

    printf("\033[?25l");
    fflush(stdout);
}

void resetTerminal()
{
    printf("\033[?25h");
    fflush(stdout);
    system("stty cooked");
}

void sigintHandler(int sig_num)
{
    resetTerminal();
    exit(0);
}