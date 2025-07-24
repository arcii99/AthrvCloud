//FormAI DATASET v1.0 Category: Physics simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //Setting up constants for the simulation
    const double gravity = 9.8;
    const double timeStep = 0.1;
    const double bounceFactor = 0.75;

    //Setting up variables for the ball
    double ballX = 0;
    double ballY = 50;
    double ballZ = 0;
    double ballVX = 5;
    double ballVY = 0;
    double ballVZ = 0;
    double ballAX = 0;
    double ballAY = -gravity;
    double ballAZ = 0;
    double ballRadius = 5;

    //Setting up variables for the ground
    double groundLevel = 0;

    //Setting up a loop for the simulation
    while (1)
    {
        //Updating the ball's position and velocity based on its acceleration
        ballX += ballVX * timeStep + 0.5 * ballAX * timeStep * timeStep;
        ballY += ballVY * timeStep + 0.5 * ballAY * timeStep * timeStep;
        ballZ += ballVZ * timeStep + 0.5 * ballAZ * timeStep * timeStep;
        ballVX += ballAX * timeStep;
        ballVY += ballAY * timeStep;
        ballVZ += ballAZ * timeStep;

        //Checking if the ball has hit the ground
        if (ballY - ballRadius < groundLevel)
        {
            //Bouncing the ball and reducing its velocity
            ballVY = -ballVY * bounceFactor;
            ballY = groundLevel + ballRadius;
        }

        //Printing out the ball's position
        printf("Ball position: (%lf, %lf, %lf)\n", ballX, ballY, ballZ);

        //Breaking the loop if the ball has stopped moving
        if (fabs(ballVX) < 0.01 && fabs(ballVY) < 0.01 && fabs(ballVZ) < 0.01)
        {
            break;
        }
    }

    return 0;
}