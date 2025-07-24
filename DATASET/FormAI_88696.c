//FormAI DATASET v1.0 Category: Physics simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define FLOOR 1 //floor height

int main() {
    srand(time(NULL));
    double vel_y = 0; 
    double pos_x = 0, pos_y = FLOOR;
    double g = -9.81; //gravity
    double mass = 0.05; 
    double e = 0.8; //coefficient of restitution
    double delta_t = 0.01; 
    double friction = 0.001; //friction coefficient

    while (pos_y >= FLOOR) {
        double time = 0;
        double vel_x = (rand() % 50) / 10.0; //random initial horizontal velocity

        while (time < 10) {
            double acc_x = -friction * abs(vel_x) * vel_x;
            double acc_y = g - friction * abs(vel_y) * vel_y;
            pos_y += vel_y * delta_t + 0.5 * acc_y * delta_t * delta_t;
            pos_x += vel_x * delta_t + 0.5 * acc_x * delta_t * delta_t;
            vel_y += acc_y * delta_t;
            vel_x += acc_x * delta_t;
            time += delta_t;

            if (pos_y < FLOOR) { //handle bouncing
                pos_y = FLOOR;
                vel_y = -e * vel_y;
                vel_x = e * vel_x;
                friction += 0.002; //increase friction after each bounce
            }
            printf("Time: %.2f, PosX: %.2f, PosY: %.2f, VelX: %.2f, VelY: %.2f, Friction: %.3f\n",
                    time, pos_x, pos_y, vel_x, vel_y, friction);
        }
    }
    return 0;
}