//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <termios.h>

#define ROWS 20
#define COLS 50
#define BALL_SPEED 100000
#define PADDLE_SPEED 50000

char screen[ROWS][COLS];
int paddlePos = COLS/2, score = 0;

typedef struct {
    int row, col, dir;
    bool dead;
}Ball;

Ball ball = {ROWS-2, COLS/2, -1, false};

pthread_mutex_t displayMutex = PTHREAD_MUTEX_INITIALIZER;

void addBorders(){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if (i == ROWS-1 || i == 0)
                screen[i][j] = '-';
            else if (j == 0 || j == COLS-1)
                screen[i][j] = '|';
            else
                screen[i][j] = ' ';
        }
    }
}

void displayScreen(){
    pthread_mutex_lock(&displayMutex);
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
    pthread_mutex_unlock(&displayMutex);
}

void clearScreen(){
    system("clear");
}

void movePaddle(char dir){
    if (dir == 'l' && paddlePos > 1)
        paddlePos--;
    else if (dir == 'r' && paddlePos < COLS-2)
        paddlePos++;
}

void moveBall(){
    if (ball.dir == -1 && ball.row > 1 && ball.col > 1){
        if (screen[ball.row-1][ball.col-1] == ' '){
            screen[ball.row][ball.col] = ' ';
            ball.row--;
            ball.col--;
            screen[ball.row][ball.col] = 'O';
        }
        else if (screen[ball.row-1][ball.col-1] == '|'){
            screen[ball.row][ball.col] = ' ';
            ball.row--;
            ball.col--;
            ball.dir = -ball.dir;
            score++;
            screen[ball.row][ball.col] = 'O';
        }
        else if (screen[ball.row-1][ball.col-1] == '-'){
            ball.dead = true;
            printf("Game over!\n");
        }
        else{
            screen[ball.row][ball.col] = ' ';
            ball.row--;
            ball.col--;
            screen[ball.row][ball.col] = 'O';
        }
    }
    else if (ball.dir == 1 && ball.row < ROWS-2 && ball.col > 1){
        if (screen[ball.row+1][ball.col-1] == ' '){
            screen[ball.row][ball.col] = ' ';
            ball.row++;
            ball.col--;
            screen[ball.row][ball.col] = 'O';
        }
        else if (screen[ball.row+1][ball.col-1] == '|'){
            screen[ball.row][ball.col] = ' ';
            ball.row++;
            ball.col--;
            ball.dir = -ball.dir;
            score++;
            screen[ball.row][ball.col] = 'O';
        }
        else if (screen[ball.row+1][ball.col-1] == '-'){
            ball.dead = true;
            printf("Game over!\n");
        }
        else{
            screen[ball.row][ball.col] = ' ';
            ball.row++;
            ball.col--;
            screen[ball.row][ball.col] = 'O';
        }
    }

    if (ball.dir == -COLS+2 && ball.row > 1 && ball.col == 1){
        if (screen[ball.row-1][ball.col+1] == ' '){
            screen[ball.row][ball.col] = ' ';
            ball.row--;
            ball.col++;
            screen[ball.row][ball.col] = 'O';
        }
        else if (screen[ball.row-1][ball.col+1] == '|'){
            screen[ball.row][ball.col] = ' ';
            ball.row--;
            ball.col++;
            ball.dir = -ball.dir;
            score++;
            screen[ball.row][ball.col] = 'O';
        }
        else if (screen[ball.row-1][ball.col+1] == '-'){
            ball.dead = true;
            printf("Game over!\n");
        }
        else{
            screen[ball.row][ball.col] = ' ';
            ball.row--;
            ball.col++;
            screen[ball.row][ball.col] = 'O';
        }
    }
    else if (ball.dir == COLS-2 && ball.row < ROWS-2 && ball.col == COLS-2){
        if (screen[ball.row+1][ball.col+1] == ' '){
            screen[ball.row][ball.col] = ' ';
            ball.row++;
            ball.col++;
            screen[ball.row][ball.col] = 'O';
        }
        else if (screen[ball.row+1][ball.col+1] == '|'){
            screen[ball.row][ball.col] = ' ';
            ball.row++;
            ball.col++;
            ball.dir = -ball.dir;
            score++;
            screen[ball.row][ball.col] = 'O';
        }
        else if (screen[ball.row+1][ball.col+1] == '-'){
            ball.dead = true;
            printf("Game over!\n");
        }
        else{
            screen[ball.row][ball.col] = ' ';
            ball.row++;
            ball.col++;
            screen[ball.row][ball.col] = 'O';
        }
    }

    if (ball.dir == -COLS+2 && ball.row == 1 && ball.col == 1){
        ball.dir = COLS-2;
        screen[ball.row][ball.col] = ' ';
        ball.row++;
        ball.col++;
        screen[ball.row][ball.col] = 'O';
    }
    else if (ball.dir == COLS-2 && ball.row == ROWS-2 && ball.col == COLS-2){
        ball.dir = -COLS+2;
        screen[ball.row][ball.col] = ' ';
        ball.row--;
        ball.col--;
        screen[ball.row][ball.col] = 'O';
    }

    usleep(BALL_SPEED);
}

void* ballThread(){
    while (!ball.dead){
        moveBall();
        displayScreen();
    }

    pthread_exit(NULL);
}

void* paddleThread(){
    struct termios old, new;
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &new);

    char dir = 'n';
    while (!ball.dead){
        dir = getchar();
        movePaddle(dir);
    }

    tcsetattr(0, TCSANOW, &old);
    pthread_exit(NULL);
}

int main(){
    addBorders();
    screen[ball.row][ball.col] = 'O';
    screen[ROWS-1][paddlePos] = '_';

    pthread_t ballId, paddleId;

    pthread_create(&ballId, NULL, ballThread, NULL);
    pthread_create(&paddleId, NULL, paddleThread, NULL);

    pthread_join(ballId, NULL);
    pthread_join(paddleId, NULL);

    return 0;
}