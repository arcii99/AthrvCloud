//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#define BOARD_WIDTH 40
#define BOARD_HEIGHT 20

#define PADDLE_WIDTH 5
#define PADDLE_HEIGHT 1

#define BALL_SPEED 1

#define BRICKS_PER_ROW 10
#define NUM_ROWS 5

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

void drawBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]) {
    int i, j;
    system("clear");
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    char board[BOARD_HEIGHT][BOARD_WIDTH];

    int paddleX = BOARD_WIDTH / 2 - PADDLE_WIDTH / 2;
    int paddleY = BOARD_HEIGHT - 2;

    int ballX = BOARD_WIDTH / 2;
    int ballY = BOARD_HEIGHT - 3;
    int ballDirX = BALL_SPEED;
    int ballDirY = -BALL_SPEED;

    int row, col;
    int numBricks = BRICKS_PER_ROW * NUM_ROWS;
    int bricks[NUM_ROWS][BRICKS_PER_ROW];

    srand(time(NULL));
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < BRICKS_PER_ROW; col++) {
            bricks[row][col] = 1;
        }
    }

    int lives = 3;
    int score = 0;

    int running = 1;
    while (running) {
        int i, j;

        // Draw board
        for (i = 0; i < BOARD_HEIGHT; i++) {
            for (j = 0; j < BOARD_WIDTH; j++) {
                if (i == 0 || i == BOARD_HEIGHT-1 || j == 0 || j == BOARD_WIDTH-1) {
                    board[i][j] = '#';
                } else {
                    board[i][j] = ' ';
                }
            }
        }

        // Draw paddle
        for (i = 0; i < PADDLE_WIDTH; i++) {
            board[paddleY][paddleX+i] = '=';
        }

        // Move ball
        ballX += ballDirX;
        ballY += ballDirY;

        // Hit left or right wall
        if (ballX <= 0 || ballX >= BOARD_WIDTH-1) {
            ballDirX = -ballDirX;
        }

        // Hit top wall
        if (ballY <= 0) {
            ballDirY = -ballDirY;
        }

        // Hit paddle
        if (ballY == paddleY-1 && (ballX >= paddleX && ballX < paddleX+PADDLE_WIDTH)) {
            ballDirY = -ballDirY;

            // Randomly deflect ball left or right
            if (rand() % 2) {
                ballDirX = -ballDirX;
            }
        }

        // Hit bottom wall
        if (ballY >= BOARD_HEIGHT-1) {
            lives--;
            if (lives > 0) {
                ballX = BOARD_WIDTH / 2;
                ballY = BOARD_HEIGHT - 3;
                ballDirX = BALL_SPEED;
                ballDirY = -BALL_SPEED;
                printf("Lives: %d\n", lives);
                getchar();
            } else {
                printf("Game Over!\n");
                printf("Score: %d\n", score);
                getchar();
                running = 0;
            }
        }

        // Check for hit brick
        if (ballY <= NUM_ROWS && bricks[ballY-1][(ballX-1)/4]) {
            bricks[ballY-1][(ballX-1)/4] = 0;
            numBricks--;
            score++;
            ballDirY = -ballDirY;
        }

        // Draw bricks
        for (row = 0; row < NUM_ROWS; row++) {
            for (col = 0; col < BRICKS_PER_ROW; col++) {
                if (bricks[row][col]) {
                    for (i = 0; i < 4; i++) {
                        board[row+1][(col*4)+i+1] = '#';
                    }
                }
            }
        }

        // Draw ball
        board[ballY][ballX] = 'O';

        // Draw stats
        sprintf(&board[0][0], "Lives: %d Score: %d", lives, score);

        // Draw board
        drawBoard(board);

        // Handle input
        char ch = getch();
        if (ch == 'a') {
            paddleX--;
            if (paddleX < 1) {
                paddleX = 1;
            }
        } else if (ch == 'd') {
            paddleX++;
            if (paddleX > BOARD_WIDTH-1-PADDLE_WIDTH) {
                paddleX = BOARD_WIDTH-1-PADDLE_WIDTH;
            }
        } else if (ch == 'q') {
            running = 0;
        }

        // Pause
        usleep(5000);
    }

    return 0;
}