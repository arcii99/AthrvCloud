//FormAI DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include<stdio.h>
#include<math.h>

int main(){
    float g = 9.8; //acceleration due to gravity
    float m = 0.1; //mass of the projectile
    float k = 0.1; //drag coefficient
    float v0 = 100; //initial velocity
    float angle = 45; //launch angle

    float x = 0; //initial position in x direction
    float y = 0; //initial position in y direction

    float vx = v0 * cos(angle); //initial velocity in x direction
    float vy = v0 * sin(angle); //initial velocity in y direction

    float dt = 0.01; //time step
    float t = 0; //initial time

    while(y>=0){
        float ax = -k*vx*vx/m; //acceleration in x direction
        float ay = -g -k*vy*vy/m; //acceleration in y direction

        vx += ax*dt; //velocity in x direction
        vy += ay*dt; //velocity in y direction

        x += vx*dt; //position in x direction
        y += vy*dt; //position in y direction

        t += dt; //update time

        printf("t=%.2f x=%.2f y=%.2f vx=%.2f vy=%.2f\n", t, x, y, vx, vy);
    }
    return 0;
}