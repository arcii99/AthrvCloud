//FormAI DATASET v1.0 Category: Physics simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TIME_STEP 0.001
#define NUM_STEPS 10000
#define SPACE_SIZE 10.0

typedef struct particle {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass; // mass
} particle;

double distance(particle *p1, particle *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void simulate(particle *particles, int num_particles) {
    double forces[num_particles][num_particles][3];
    for(int i = 0; i < num_particles; i++) {
        for(int j = 0; j < num_particles; j++) {
            forces[i][j][0] = 0.0;
            forces[i][j][1] = 0.0;
            forces[i][j][2] = 0.0;
        }
    }

    // calculate forces between particles
    for(int i = 0; i < num_particles; i++) {
        particle *p1 = &particles[i];
        for(int j = i+1; j < num_particles; j++) {
            particle *p2 = &particles[j];
            double dist = distance(p1, p2);
            double f = p1->mass * p2->mass / (dist*dist);
            double dx = p2->x - p1->x;
            double dy = p2->y - p1->y;
            double dz = p2->z - p1->z;
            forces[i][j][0] = f * dx / dist;
            forces[i][j][1] = f * dy / dist;
            forces[i][j][2] = f * dz / dist;
            forces[j][i][0] = -forces[i][j][0];
            forces[j][i][1] = -forces[i][j][1];
            forces[j][i][2] = -forces[i][j][2];
        }
    }

    // update velocities and positions
    for(int i = 0; i < num_particles; i++) {
        particle *p = &particles[i];
        double ax = 0.0;
        double ay = 0.0;
        double az = 0.0;
        for(int j = 0; j < num_particles; j++) {
            ax += forces[i][j][0] / p->mass;
            ay += forces[i][j][1] / p->mass;
            az += forces[i][j][2] / p->mass;
        }
        p->vx += ax * TIME_STEP;
        p->vy += ay * TIME_STEP;
        p->vz += az * TIME_STEP;
        p->x += p->vx * TIME_STEP;
        p->y += p->vy * TIME_STEP;
        p->z += p->vz * TIME_STEP;

        // bounce particles off walls
        if(p->x < 0.0) {
            p->x = -p->x;
            p->vx = -p->vx;
        } else if(p->x > SPACE_SIZE) {
            p->x = 2.0*SPACE_SIZE - p->x;
            p->vx = -p->vx;
        }
        if(p->y < 0.0) {
            p->y = -p->y;
            p->vy = -p->vy;
        } else if(p->y > SPACE_SIZE) {
            p->y = 2.0*SPACE_SIZE - p->y;
            p->vy = -p->vy;
        }
        if(p->z < 0.0) {
            p->z = -p->z;
            p->vz = -p->vz;
        } else if(p->z > SPACE_SIZE) {
            p->z = 2.0*SPACE_SIZE - p->z;
            p->vz = -p->vz;
        }
    }
}

int main() {
    srand(42); // seed random number generator

    int num_particles = 10;
    particle particles[num_particles];
    for(int i = 0; i < num_particles; i++) {
        particles[i].x = (double)rand()/(double)RAND_MAX * SPACE_SIZE;
        particles[i].y = (double)rand()/(double)RAND_MAX * SPACE_SIZE;
        particles[i].z = (double)rand()/(double)RAND_MAX * SPACE_SIZE;
        particles[i].vx = (double)rand()/(double)RAND_MAX * 2.0 - 1.0;
        particles[i].vy = (double)rand()/(double)RAND_MAX * 2.0 - 1.0;
        particles[i].vz = (double)rand()/(double)RAND_MAX * 2.0 - 1.0;
        particles[i].mass = (double)rand()/(double)RAND_MAX * 10.0 + 1.0;
    }

    for(int i = 0; i < NUM_STEPS; i++) {
        simulate(particles, num_particles);
    }

    for(int i = 0; i < num_particles; i++) {
        printf("Particle %d: x=%f y=%f z=%f vx=%f vy=%f vz=%f mass=%f\n", i+1,
                particles[i].x, particles[i].y, particles[i].z,
                particles[i].vx, particles[i].vy, particles[i].vz,
                particles[i].mass);
    }

    return 0;
}