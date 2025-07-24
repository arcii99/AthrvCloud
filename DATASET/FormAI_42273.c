//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bricks[5][10]; // 5 rows and 10 columns of bricks

// function to initialize the bricks
void initializeBricks() {
    int i, j;
    for(i=0;i<5;i++) {
        for(j=0;j<10;j++) {
            bricks[i][j] = 1; // 1 represents the brick is not broken
        }
    }
}

int main() {
    int ballX = 5, ballY = 5; // initial position of the ball
    int ballDirectionX = 1, ballDirectionY = 1; // initial direction of the ball
    int paddleX = 0; // initial position of the paddle
    int score = 0; // initial score

    initializeBricks(); // initialize the bricks

    srand(time(NULL)); // seed the random number generator

    while(1) { // infinite loop until game is over
        // clear the screen
        system("clear");

        // print the game board
        int i, j;
        for(i=0;i<5;i++) {
            for(j=0;j<10;j++) {
                if(bricks[i][j] == 1) { // if brick is not broken
                    printf("* ");
                } else { // if brick is broken
                    printf("  ");
                }
            }
            printf("\n");
        }

        // print the paddle
        for(i=0;i<15;i++) {
            printf("-");
        }
        printf("\n");

        // print the ball
        for(i=0;i<ballX;i++) {
            printf(" ");
        }
        printf("O\n");

        // move the ball
        ballX += ballDirectionX;
        ballY += ballDirectionY;

        // bounce the ball off the walls
        if(ballX==0 || ballX==9) {
            ballDirectionX *= -1;
        }
        if(ballY==0) {
            ballDirectionY *= -1;
        }

        // check if ball hits a brick
        if(ballY==4) { // rows = 5 - 1 (0-indexed)
            if(bricks[ballX][ballY] == 1) { // if brick is not broken
                bricks[ballX][ballY] = 0; // set brick as broken
                score += 10; // increase score
                ballDirectionY *= -1; // bounce the ball off the brick
            }
        }

        // check if ball hits the paddle
        if(ballY==14) { // rows = 15 - 1 (0-indexed)
            if(ballX>=paddleX && ballX<=paddleX+4) {
                ballDirectionY *= -1;
            } else { // game over
                printf("Game Over!\n");
                printf("Score: %d\n", score);
                return 0; // exit program
            }
        }

        // move the paddle
        if(rand()%5 == 0) { // move randomly
            paddleX += rand()%3 - 1;
        }

        // limit the paddle's movement
        if(paddleX < 0) {
            paddleX = 0;
        }
        if(paddleX > 5) {
            paddleX = 5;
        }
    }

    return 0;
}