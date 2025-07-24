//FormAI DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 70
#define HEIGHT 25
#define G 9.81
#define PI 3.14159265359

int main()
{
    srand(time(0));
    float startAngle = ((float)rand()/(float)(RAND_MAX)) * 90.0;
    float startSpeed = ((float)rand()/(float)(RAND_MAX)) * 50.0;
    float posY = HEIGHT;
    float posX = 0;
    float timeStep = 0.1;
    float angle = startAngle * (PI/180);
    float velX = startSpeed * cos(angle);
    float velY = startSpeed * sin(angle);

    while(posY >= 0) {
        posX += velX * timeStep;
        posY += (velY * timeStep) - (0.5 * G * pow(timeStep, 2));
        velY -= G * timeStep;
        
        int x = (int) posX;
        int y = HEIGHT - (int) posY;

        if(x > 0 && y > 0 && x < WIDTH && y < HEIGHT) {
            printf("\033[%d;%dH*", y, x);
            fflush(stdout);
            usleep(100000);
        }
    }

    return 0;
}