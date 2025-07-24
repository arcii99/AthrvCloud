//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 10 // number of threads to use
#define NUM_PLANETS 3 // number of planets to simulate

typedef struct {
    double mass;
    double x;
    double y;
    double velocity_x;
    double velocity_y;
    double acceleration_x;
    double acceleration_y;
} Planet;

Planet planets[NUM_PLANETS]; // array of planets to simulate

double G = 6.67430E-11; // gravitational constant

void calculate_forces() {
    int i, j;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].acceleration_x = 0;
        planets[i].acceleration_y = 0;
        for (j = 0; j < NUM_PLANETS; j++) {
            if (j != i) {
                double distance = sqrt(pow(planets[i].x - planets[j].x, 2) +
                                       pow(planets[i].y - planets[j].y, 2));
                double force = G * planets[i].mass * planets[j].mass / pow(distance, 2);
                double angle = atan2(planets[j].y - planets[i].y, planets[j].x - planets[i].x);
                planets[i].acceleration_x += force * cos(angle) / planets[i].mass;
                planets[i].acceleration_y += force * sin(angle) / planets[i].mass;
            }
        }
    }
}

void update_velocities(double time_step) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].velocity_x += planets[i].acceleration_x * time_step;
        planets[i].velocity_y += planets[i].acceleration_y * time_step;
    }
}

void update_positions(double time_step) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].velocity_x * time_step;
        planets[i].y += planets[i].velocity_y * time_step;
    }
}

void *simulate(void *threadid) {
    long tid;
    tid = (long) threadid;
    double time_step = 0.01;
    while (1) {
        // calculate forces
        calculate_forces();
        // update velocities
        update_velocities(time_step);
        // update positions
        update_positions(time_step);
        // sleep for a bit
        usleep(10000);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int rc;
    long t;
    pthread_t threads[NUM_THREADS];
    
    // initialize planets
    planets[0].mass = 5.97E24;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].velocity_x = 0;
    planets[0].velocity_y = 0;
    planets[1].mass = 6.39E23;
    planets[1].x = 384400000;
    planets[1].y = 0;
    planets[1].velocity_x = 0;
    planets[1].velocity_y = 1022;
    planets[2].mass = 7.34E22;
    planets[2].x = -384400000;
    planets[2].y = 0;
    planets[2].velocity_x = 0;
    planets[2].velocity_y = -1022;
    
    // create threads
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, simulate, (void *) t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    // join threads
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    return 0;
}