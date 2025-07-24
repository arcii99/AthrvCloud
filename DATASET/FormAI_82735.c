//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define WIDTH 50
#define HEIGHT 20

// structures for ball and paddle
struct Ball {
    int x, y, dx, dy;
};

struct Paddle {
    int x, y;
};

// function to displays the game board
void displayBoard(char board[HEIGHT][WIDTH]) {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// function to initialize the game board
void initBoard(char board[HEIGHT][WIDTH], struct Ball ball, struct Paddle paddle) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1) {
                board[i][j] = '#';
            } else if (i == ball.y && j == ball.x) {
                board[i][j] = 'O';
            } else if (i == paddle.y && j >= paddle.x-2 && j <= paddle.x+2) {
                board[i][j] = '|';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// function to move the ball on the board
void moveBall(char board[HEIGHT][WIDTH], struct Ball *ball, struct Paddle paddle) {
    ball->x += ball->dx;
    ball->y += ball->dy;
    if (ball->x <= 1 || ball->x >= WIDTH-2) {
        ball->dx = -ball->dx;
    }
    if (ball->y <= 1 || ball->y >= HEIGHT-2) {
        ball->dy = -ball->dy;
    }
    if (ball->y == paddle.y-1 && ball->x >= paddle.x-2 && ball->x <= paddle.x+2) {
        ball->dy = -ball->dy;
    }
    if (ball->y >= HEIGHT-2) {
        board[ball->y][ball->x] = ' ';
        initBoard(board, *ball, paddle);
        ball->x = WIDTH/2;
        ball->y = HEIGHT/2;
        ball->dx = 1;
        ball->dy = -1;
    }
}

// function to move the paddle on the board
void movePaddle(char board[HEIGHT][WIDTH], struct Paddle *paddle, char key) {
    switch(key) {
        case 'a':
            if (paddle->x > 3) {
                paddle->x -= 3;
            }
            break;
        case 'd':
            if (paddle->x < WIDTH-5) {
                paddle->x += 3;
            }
            break;
        default:
            break;
    }
    initBoard(board, (struct Ball){0}, *paddle);
}

// function to check if player lost the game
int checkGameOver(char board[HEIGHT][WIDTH], struct Ball *ball) {
    if (ball->y >= HEIGHT-2) {
        return 1;
    }
    return 0;
}

// main function
int main() {
    // initialize variables
    char board[HEIGHT][WIDTH];
    struct Ball ball = {WIDTH/2, HEIGHT/2, 1, -1};
    struct Paddle paddle = {WIDTH/2, HEIGHT-2};
    char key;

    // initialize game board
    initBoard(board, ball, paddle);

    // display initial game board
    displayBoard(board);

    // set terminal to be non-blocking
    struct termios old, new;
    tcgetattr(0, &old);
    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new);

    // game loop
    while (1) {
        // check if player lost the game
        if (checkGameOver(board, &ball)) {
            printf("You lose!\n");
            break;
        }

        // wait for user input or sleep for 30 milliseconds
        if (read(0, &key, 1) > 0) {
            movePaddle(board, &paddle, key);
        } else {
            usleep(30000);
            moveBall(board, &ball, paddle);
        }

        // display updated game board
        displayBoard(board);
    }

    // reset terminal to normal mode
    tcsetattr(0, TCSANOW, &old);
    return 0;
}