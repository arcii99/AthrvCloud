//FormAI DATASET v1.0 Category: Physics simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Declaring relevant constants
#define GRAVITY 9.81f
#define TIME_STEP 0.1f

//Declaring a structure for the ball
typedef struct {
    float posX;
    float posY;
    float velocity;
} Ball;

//Declaring function prototypes
void printBallInfo(Ball ball);
void animateBall(Ball *ballPtr);

int main(void) {
    //Initializing a ball with initial position and velocity
    Ball ball = {0.0f, 0.0f, 15.0f};
    
    //Printing initial ball information
    printBallInfo(ball);
    
    //Animating the ball for 10 seconds
    for(int i = 0; i < 100; i++) {
        animateBall(&ball);
        printBallInfo(ball);
    }

    return 0;
}

//Function to print ball information
void printBallInfo(Ball ball) {
    printf("Ball position: (%f, %f)\n", ball.posX, ball.posY);
    printf("Ball velocity: %f\n", ball.velocity);
    printf("----------------------------\n");
}

//Function to animate the ball
void animateBall(Ball *ballPtr) {
    float time = 0.0f;
    float acceleration = -GRAVITY;
    float velocity = ballPtr->velocity;
    float posX = ballPtr->posX;
    float posY = ballPtr->posY;
    bool isDescending = true;

    while(time < TIME_STEP) {
        //Calculating the net force on the ball
        float netForce = acceleration;
        
        //Calculating the new velocity of the ball
        velocity += netForce * TIME_STEP;
        
        //Checking if the ball has reached its peak
        if(velocity < 0 && isDescending) {
            isDescending = false;
        }
        
        //Updating the position of the ball
        if(isDescending) {
            posY += velocity * TIME_STEP + 0.5f * acceleration * TIME_STEP * TIME_STEP;
        } else {
            posY += velocity * TIME_STEP - 0.5f * acceleration * TIME_STEP * TIME_STEP;
        }
        
        //Updating the time
        time += TIME_STEP;
    }

    //Updating the ball position and velocity
    ballPtr->posX = posX;
    ballPtr->posY = posY;
    ballPtr->velocity = velocity;
}