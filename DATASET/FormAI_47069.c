//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#define WIDTH 60
#define HEIGHT 25

struct termios orig_termios;

char screen[HEIGHT][WIDTH];

struct Ball {
    int x, y;
    int speedX, speedY;
};

struct Paddle {
    int x, y;
    int length;
};

void set_raw_mode(void) {
    struct termios raw = orig_termios;

    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void reset_termios(void) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

char getch(void) {
    char ch = 0;
    set_raw_mode();

    fd_set set;
    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);

    while (select(STDIN_FILENO + 1, &set, NULL, NULL, NULL) < 1);

    read(STDIN_FILENO, &ch, 1);
    reset_termios();

    return ch;
}

void initScreen() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            screen[i][j] = ' ';
        }
    }
}

void drawScreen() {
    system("clear");
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

void initBall(struct Ball *ball) {
    ball->x = ((rand()%2) == 0) ? WIDTH/2 - 1 : WIDTH/2 + 1;
    ball->y = 2 + rand()%5;
    ball->speedX = ((rand()%2) == 0) ? -1 : 1;
    ball->speedY = -1;
}

void drawBall(struct Ball *ball) {
    screen[ball->y][ball->x] = '*';
}

void eraseBall(struct Ball *ball) {
    screen[ball->y][ball->x] = ' ';
}

void moveBall(struct Ball *ball, struct Paddle *paddle) {
    eraseBall(ball);

    if (ball->x + ball->speedX == 0 || ball->x + ball->speedX == WIDTH - 1) {
        ball->speedX = -ball->speedX;
    }

    if (ball->y + ball->speedY == 0 || (ball->y + ball->speedY == paddle->y && ball->x >= paddle->x && ball->x < paddle->x + paddle->length)) {
        ball->speedY = -ball->speedY;
    }
    else if (ball->y + ball->speedY == HEIGHT - 1) {
        // ball hits the ground, game over
        ball->speedY = -ball->speedY;
        ball->y = 2 + rand()%5;
        ball->x = ((rand()%2) == 0) ? WIDTH/2 - 1 : WIDTH/2 + 1;
        drawScreen();
        printf("Game Over\n");
        exit(0);
    }

    ball->x += ball->speedX;
    ball->y += ball->speedY;
    drawBall(ball);
    drawScreen();
}

void initPaddle(struct Paddle *paddle) {
    paddle->length = 10;
    paddle->x = WIDTH/2 - paddle->length/2;
    paddle->y = HEIGHT - 3;
}

void drawPaddle(struct Paddle *paddle) {
    for (int i = paddle->x; i < paddle->x + paddle->length; ++i) {
        screen[paddle->y][i] = '=';
    }
}

void erasePaddle(struct Paddle *paddle) {
    for (int i = paddle->x; i < paddle->x + paddle->length; ++i) {
        screen[paddle->y][i] = ' ';
    }
}

bool paddleMove(struct Paddle *paddle, char dir) {
    bool valid_move = true;
    erasePaddle(paddle);

    if (tolower(dir) == 'a' && paddle->x - 1 >= 0) {
        paddle->x -= 1;
    }
    else if (tolower(dir) == 'd' && paddle->x + paddle->length + 1 < WIDTH) {
        paddle->x += 1;
    }
    else {
        valid_move = false;
    }
    drawPaddle(paddle);

    return valid_move;
}

int main() {
    struct Ball ball;
    struct Paddle paddle;
    char key;

    srand(time(0));

    initScreen();
    initBall(&ball);
    initPaddle(&paddle);
    drawBall(&ball);
    drawPaddle(&paddle);
    drawScreen();

    while (1) {
        key = getch();

        if (tolower(key) == 'q') { // quit the game
            reset_termios();
            printf("Quit the game\n");
            break;
        }
        else if (!paddleMove(&paddle, key)) {
            continue;
        }

        moveBall(&ball, &paddle);
        usleep(25000);
    }

    return 0;
}