//FormAI DATASET v1.0 Category: Pong Game with AI Opponent ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 60
#define HEIGHT 20
#define PADDLE_SIZE 4
#define BALL_SPEED 100000

int getch(void);
void gotoxy(int x,int y);

int main() {
    int i, j, k;
    int paddle1y, paddle2y, ballx, bally, ballxdir, ballydir, score1, score2;
    char screen[WIDTH][HEIGHT];
    char c;

    // Initialize game variables and screen
    srand(time(NULL));
    paddle1y = HEIGHT / 2 - PADDLE_SIZE / 2;
    paddle2y = HEIGHT / 2 - PADDLE_SIZE / 2;
    ballx = WIDTH / 2;
    bally = HEIGHT / 2;
    ballxdir = ballydir = 1;
    score1 = score2 = 0;
    for (i = 0; i < WIDTH; ++i) {
        for (j = 0; j < HEIGHT; ++j) {
            if (i == 0 || i == WIDTH - 1) screen[i][j] = '|';
            else if (j == 0 || j == HEIGHT - 1) screen[i][j] = '-';
            else screen[i][j] = ' ';
        }
    }

    // Draw starting screen
    for (i = 0; i < HEIGHT; ++i) screen[0][i] = screen[WIDTH - 1][i] = '|';
    for (i = 0; i < WIDTH; ++i) screen[i][0] = screen[i][HEIGHT - 1] = '-';
    gotoxy(0, 0);
    for (j = 0; j < HEIGHT; ++j) {
        for (i = 0; i < WIDTH; ++i) {
            putchar(screen[i][j]);
        }
        putchar('\n');
    }
    gotoxy(0, HEIGHT + 1);

    // Game loop
    while (1) {
        // Move ball
        ballx += ballxdir;
        bally += ballydir;

        // Bounce ball off walls
        if (ballx <= 0 || ballx >= WIDTH - 1) {
            ballxdir *= -1;
        }
        if (bally <= 0 || bally >= HEIGHT - 1) {
            ballydir *= -1;
        }

        // Check for paddle collisions
        if (ballx == 1 && bally >= paddle1y && bally <= paddle1y + PADDLE_SIZE) {
            ballxdir *= -1;
        }
        if (ballx == WIDTH - 2 && bally >= paddle2y && bally <= paddle2y + PADDLE_SIZE) {
            ballxdir *= -1;
        }

        // Clear screen
        for (i = 1; i < WIDTH - 1; ++i) {
            for (j = 1; j < HEIGHT - 1; ++j) {
                screen[i][j] = ' ';
            }
        }

        // Draw paddles and ball
        for (i = 0; i < PADDLE_SIZE; ++i) {
            screen[1][paddle1y + i] = '|';
            screen[WIDTH - 2][paddle2y + i] = '|';
        }
        screen[ballx][bally] = 'O';

        // Move AI paddle
        if (ballx >= WIDTH / 2) {
            if ((bally > paddle2y + PADDLE_SIZE / 2) && (paddle2y + PADDLE_SIZE < HEIGHT)) {
                paddle2y++;
            } else if ((bally < paddle2y + PADDLE_SIZE / 2) && paddle2y > 0) {
                paddle2y--;
            }
        }

        // Check for scoring
        if (ballx == 0) {
            score2++;
            ballx = WIDTH / 2;
            bally = HEIGHT / 2;
            ballxdir *= -1;
        }
        if (ballx == WIDTH - 1) {
            score1++;
            ballx = WIDTH / 2;
            bally = HEIGHT / 2;
            ballxdir *= -1;
        }

        // Display score
        gotoxy(WIDTH / 2 - 6, HEIGHT + 1);
        printf("Player 1: %d | Player 2: %d", score1, score2);

        // Draw screen
        gotoxy(0, 0);
        for (j = 0; j < HEIGHT; ++j) {
            for (i = 0; i < WIDTH; ++i) {
                putchar(screen[i][j]);
            }
            putchar('\n');
        }
        gotoxy(0, HEIGHT + 1);

        // Delay
        usleep(BALL_SPEED);
    }
    return 0;
}

// Read a single character from the terminal without echoing it
int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

// Move cursor to position (x, y)
void gotoxy(int x,int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}