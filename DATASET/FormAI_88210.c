//FormAI DATASET v1.0 Category: Physics simulation ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // seed the random number generator
    int height = 500; // height of simulation
    int width = 800; // width of simulation
    int ball_x = width/2; // starting x-coordinate of ball
    int ball_y = height-50; // starting y-coordinate of ball
    int ball_vx = rand()%10 - 5; // starting x-velocity of ball
    int ball_vy = -rand()%10; // starting y-velocity of ball

    printf("Let's simulate a bouncing ball!\n");

    // simulation loop
    while(ball_y >= 0){
        ball_x += ball_vx;
        ball_y += ball_vy;
        ball_vy += 1; // simulate gravity

        // handle bouncing off sides of screen
        if(ball_x < 0 || ball_x > width){
            ball_vx = -ball_vx;
        }
        // handle bouncing off bottom of screen
        if(ball_y > height){
            ball_y = height;
            ball_vy = -ball_vy;
        }

        printf("[%d,%d]\n", ball_x, ball_y);
    }

    printf("Ball has hit the ground. Simulation is over.\n");

    return 0;
}