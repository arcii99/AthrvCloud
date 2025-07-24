//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 50
#define HEIGHT 20
#define PADDLE_HEIGHT 5

typedef enum {false, true} bool;

void set_terminal_mode()
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void reset_terminal_mode()
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int kbhit()
{
    int ret = 0;
    fd_set fds;
    struct timeval tv;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    if (select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) == -1) {
        ret = 0;
    } else {
        ret = FD_ISSET(STDIN_FILENO, &fds);
    }
    return ret;
}

int getch(void)
{
    int c = 0;
    struct termios org_opts, new_opts;
    int res = 0;
    res = tcgetattr(STDIN_FILENO, &org_opts);
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c = getchar();
    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    return c;
}

int ballX, ballY, paddlePlayerX, paddlePlayerY, paddleAIY, scorePlayer, scoreAI;
int vectX, vectY;

bool firstServe = true;

void printBoard()
{
    system("clear");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == ballY && j == ballX) {
                putchar('0');
            } else if (i >= paddlePlayerY && i < paddlePlayerY + PADDLE_HEIGHT &&
                       j == paddlePlayerX) {
                putchar('|');
            } else if (i >= paddleAIY && i < paddleAIY + PADDLE_HEIGHT && j == WIDTH - 1) {
                putchar('|');
            } else if (j == WIDTH - 1 || j == 0) {
                putchar('*');
            } else if (i == 0 || i == HEIGHT - 1) {
                putchar('-');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    printf("Score: Player %d - %d AI\n", scorePlayer, scoreAI);
}

void serveBall()
{
    srand(time(NULL));
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    vectX = 1 - 2 * (rand() % 2);
    vectY = 1 - 2 * (rand() % 2);
    firstServe = false;
}

void moveBall()
{
    ballX += vectX;
    ballY += vectY;

    if (ballX == 1 || ballX == WIDTH - 2) {
        vectX = -vectX;
    }

    if (ballY == 1 || ballY == HEIGHT - 2) {
        vectY = -vectY;
    }

    if (ballX <= 1) {
        if (ballY >= paddlePlayerY && ballY < paddlePlayerY + PADDLE_HEIGHT) {
            vectX = -vectX;
        } else {
            scoreAI++;
            serveBall();
        }
    } else if (ballX >= WIDTH - 2) {
        if (ballY >= paddleAIY && ballY < paddleAIY + PADDLE_HEIGHT) {
            vectX = -vectX;
        } else {
            scorePlayer++;
            serveBall();
        }
    }
}

void movePlayerPaddle(int direction)
{
    if (paddlePlayerY + direction >= 1 && paddlePlayerY + direction <= HEIGHT - PADDLE_HEIGHT - 1) {
        paddlePlayerY += direction;
    }
}

void moveAIPaddle()
{
    if (ballY < paddleAIY + PADDLE_HEIGHT / 2) {
        movePlayerPaddle(-1);
    } else if (ballY > paddleAIY + PADDLE_HEIGHT / 2) {
        movePlayerPaddle(1);
    }
}

int main()
{
    set_terminal_mode();

    paddlePlayerX = 1;
    paddlePlayerY = HEIGHT / 2 - PADDLE_HEIGHT / 2;
    paddleAIY = HEIGHT / 2 - PADDLE_HEIGHT / 2;
    serveBall();

    while (true) {

        printBoard();

        if (kbhit()) {
            int ch = getch();
            if (ch == 'w') {
                movePlayerPaddle(-1);
            }
            if (ch == 's') {
                movePlayerPaddle(1);
            }
            if (firstServe) {
                firstServe = false;
            }
        }

        if (!firstServe) {
            moveAIPaddle();
            moveBall();
        }

        usleep(50000);
    }

    reset_terminal_mode();
    return 0;
}