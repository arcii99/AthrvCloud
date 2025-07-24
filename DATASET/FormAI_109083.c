//FormAI DATASET v1.0 Category: Physics simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(){
    int i, j, time_step;
    double position[SIZE], velocity[SIZE], acceleration[SIZE];
    double force[SIZE], mass[SIZE];
    double k = 10.0, m = 1.0;
    srand(time(0));
    for(i = 0; i < SIZE; i++){
        position[i] = rand() % 10;
        velocity[i] = rand() % 10;
        force[i] = -k * position[i];
        mass[i] = m + i;
    }
    for(time_step = 0; time_step < 5; time_step++){
        for(i = 0; i < SIZE; i++){
            acceleration[i] = force[i] / mass[i];
            velocity[i] += acceleration[i];
            position[i] += velocity[i];
            force[i] = -k * position[i];
            printf("Particle %d: pos=%.2lf, vel=%.2lf, acc=%.2lf\n",
                i, position[i], velocity[i], acceleration[i]);
        }
        printf("*****************************************\n");
    }
    return 0;
}