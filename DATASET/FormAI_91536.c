//FormAI DATASET v1.0 Category: Physics simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

//constants
#define GRAV_CONST 6.674e-11  //gravitational constant
#define TIME_STEP 0.01        //simulation time step
#define PARTICLE_COUNT 3      //number of particles

//structure for particles
struct particle {
    double mass;    //mass of particle
    double x, y;    //position of particle
    double vx, vy;  //velocity of particle
};

//function to calculate distance between two particles
double distance(struct particle a, struct particle b) {
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main() {
    //initialize particles
    struct particle particles[PARTICLE_COUNT] = {
        {1000, 10, 10, 0, 0},
        {500, 20, 50, 0, 0},
        {200, 30, 40, 0, 0}
    };

    //simulate particles for 1000 time steps
    for (int i = 0; i < 1000; i++) {
        //calculate forces between particles
        double forces[PARTICLE_COUNT][2] = {{0}};  //initialize all forces to zero
        for (int j = 0; j < PARTICLE_COUNT; j++) {
            for (int k = j + 1; k < PARTICLE_COUNT; k++) {
                double dist = distance(particles[j], particles[k]);
                double force_magnitude = GRAV_CONST * particles[j].mass * particles[k].mass / pow(dist, 2);
                double force_x = force_magnitude * (particles[k].x - particles[j].x) / dist;
                double force_y = force_magnitude * (particles[k].y - particles[j].y) / dist;
                forces[j][0] += force_x;
                forces[j][1] += force_y;
                forces[k][0] -= force_x;
                forces[k][1] -= force_y;
            }
        }

        //update particles
        for (int j = 0; j < PARTICLE_COUNT; j++) {
            particles[j].vx += forces[j][0] / particles[j].mass * TIME_STEP;
            particles[j].vy += forces[j][1] / particles[j].mass * TIME_STEP;
            particles[j].x += particles[j].vx * TIME_STEP;
            particles[j].y += particles[j].vy * TIME_STEP;
        }

        //print current state of particles every 10 steps
        if (i % 10 == 0) {
            printf("Time step %d:\n", i);
            for (int j = 0; j < PARTICLE_COUNT; j++) {
                printf("Particle %d: mass=%lf, position=(%lf,%lf), velocity=(%lf,%lf)\n",
                       j, particles[j].mass, particles[j].x, particles[j].y, particles[j].vx, particles[j].vy);
            }
        }
    }

    return 0;
}