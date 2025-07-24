//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

#define COLS 80
#define ROWS 24

typedef struct {
    int x, y;
    int dx, dy;
} ball;

typedef struct {
    int x, y;
} paddle;

ball gameBall = {COLS / 2, ROWS / 2, 1, 1};
paddle gamePaddle = {COLS / 2, ROWS - 2};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *inputThread(void *vargp) {
    int input, fd;
    struct termios oldattr, newattr;

    fd = fileno(stdin);
    tcgetattr(fd, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(fd, TCSANOW, &newattr);

    while (1) {
        input = getchar();
        pthread_mutex_lock(&mutex);

        if (input == 'a') {
            gamePaddle.x--;
        } else if (input == 'd') {
            gamePaddle.x++;
        }

        pthread_mutex_unlock(&mutex);
    }

    tcsetattr(fd, TCSANOW, &oldattr);
    return NULL;
}

void *outputThread(void *vargp) {
    char screen[ROWS][COLS + 1];
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            screen[i][j] = ' ';
        }

        screen[i][COLS] = '\0';
    }

    while (1) {
        pthread_mutex_lock(&mutex);

        if (gameBall.x + gameBall.dx <= 0 || gameBall.x + gameBall.dx >= COLS - 1) {
            gameBall.dx *= -1;
        }

        if (gameBall.y + gameBall.dy < 0 || (gameBall.y + gameBall.dy == gamePaddle.y &&
                gameBall.x + gameBall.dx >= gamePaddle.x &&
                gameBall.x + gameBall.dx <= gamePaddle.x + 5)) {
            gameBall.dy *= -1;
        } else if (gameBall.y + gameBall.dy == ROWS - 1) {
            printf("Game Over!\n");
            exit(0);
        }

        gameBall.x += gameBall.dx;
        gameBall.y += gameBall.dy;

        memcpy(screen, "-----------------------------------------------------------", COLS);

        screen[gameBall.y][gameBall.x] = 'O';

        screen[gamePaddle.y][gamePaddle.x] = '|';
        screen[gamePaddle.y][gamePaddle.x + 1] = '|';
        screen[gamePaddle.y][gamePaddle.x + 2] = '|';
        screen[gamePaddle.y][gamePaddle.x + 3] = '|';
        screen[gamePaddle.y][gamePaddle.x + 4] = '|';

        screen[gamePaddle.y + 1][gamePaddle.x] = '|';
        screen[gamePaddle.y + 1][gamePaddle.x + 1] = '|';
        screen[gamePaddle.y + 1][gamePaddle.x + 2] = '|';
        screen[gamePaddle.y + 1][gamePaddle.x + 3] = '|';
        screen[gamePaddle.y + 1][gamePaddle.x + 4] = '|';

        printf("\033[0;0H");  // move cursor to (0, 0)
        fflush(stdout);

        for (i = 0; i < ROWS; i++) {
            printf("%s\n", screen[i]);
            fflush(stdout);
        }

        pthread_mutex_unlock(&mutex);

        usleep(100000);
    }

    return NULL;
}

int main() {
    pthread_t input_tid, output_tid;

    pthread_create(&input_tid, NULL, inputThread, NULL);
    pthread_create(&output_tid, NULL, outputThread, NULL);

    pthread_join(input_tid, NULL);
    pthread_join(output_tid, NULL);

    return 0;
}