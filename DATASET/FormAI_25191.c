//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10		// Number of planets
#define G 6.674E-11	// Gravitational constant

struct planet {
    double mass;		// Mass of planet
    double pos[3];		// Position of planet (x, y, z)
    double vel[3];		// Velocity of planet (x, y, z)
    double acc[3];		// Acceleration of planet (x, y, z)
};

void setInitialConditions(struct planet planets[N]) {
    planets[0].mass = 3.3011E23;
    planets[0].pos[0] = 0;
    planets[0].pos[1] = 0;
    planets[0].pos[2] = 0;
    planets[0].vel[0] = 0;
    planets[0].vel[1] = 0;
    planets[0].vel[2] = 0;

    planets[1].mass = 4.8675E24;
    planets[1].pos[0] = 0;
    planets[1].pos[1] = 0;
    planets[1].pos[2] = 6.371E6 + 41.4E6;
    planets[1].vel[0] = 0;
    planets[1].vel[1] = 0;
    planets[1].vel[2] = 0;

    planets[2].mass = 5.9722E24;
    planets[2].pos[0] = 0;
    planets[2].pos[1] = 0;
    planets[2].pos[2] = 407.6e3;
    planets[2].vel[0] = 10.5e3;
    planets[2].vel[1] = 0;
    planets[2].vel[2] = 0;

    planets[3].mass = 7.342E22;
    planets[3].pos[0] = 0;
    planets[3].pos[1] = 0;
    planets[3].pos[2] = 384.4E6 + 8E6;
    planets[3].vel[0] = 0;
    planets[3].vel[1] = 1E3;
    planets[3].vel[2] = 0;

    planets[4].mass = 6.39E23;
    planets[4].pos[0] = 2.27E11;
    planets[4].pos[1] = 0;
    planets[4].pos[2] = 0;
    planets[4].vel[0] = 0;
    planets[4].vel[1] = 23.8E3;
    planets[4].vel[2] = 0;

    planets[5].mass = 1.898E27;
    planets[5].pos[0] = 7.77E11;
    planets[5].pos[1] = 0;
    planets[5].pos[2] = 0;
    planets[5].vel[0] = 0;
    planets[5].vel[1] = 13.1E3;
    planets[5].vel[2] = 0;

    planets[6].mass = 5.683E26;
    planets[6].pos[0] = 1.43E12;
    planets[6].pos[1] = 0;
    planets[6].pos[2] = 0;
    planets[6].vel[0] = 0;
    planets[6].vel[1] = 9.7E3;
    planets[6].vel[2] = 0;

    planets[7].mass = 8.681E25;
    planets[7].pos[0] = 2.87E12;
    planets[7].pos[1] = 0;
    planets[7].pos[2] = 0;
    planets[7].vel[0] = 0;
    planets[7].vel[1] = 6.8E3;
    planets[7].vel[2] = 0;

    planets[8].mass = 1.024E23;
    planets[8].pos[0] = 4.5E12;
    planets[8].pos[1] = 0;
    planets[8].pos[2] = 0;
    planets[8].vel[0] = 0;
    planets[8].vel[1] = 5.4E3;
    planets[8].vel[2] = 0;

    planets[9].mass = 1.307E22;
    planets[9].pos[0] = 9E12;
    planets[9].pos[1] = 0;
    planets[9].pos[2] = 0;
    planets[9].vel[0] = 0;
    planets[9].vel[1] = 3.7E3;
    planets[9].vel[2] = 0;
}

void calculateForces(struct planet planets[N]) {
    int i, j;
    double r, f, dx, dy, dz;

    for (i = 0; i < N; i++) {
        planets[i].acc[0] = 0;
        planets[i].acc[1] = 0;
        planets[i].acc[2] = 0;

        for (j = 0; j < N; j++) {
            if (i != j) {
                dx = planets[j].pos[0] - planets[i].pos[0];
                dy = planets[j].pos[1] - planets[i].pos[1];
                dz = planets[j].pos[2] - planets[i].pos[2];

                r = sqrt(dx*dx + dy*dy + dz*dz);
                f = G * planets[i].mass * planets[j].mass / (r*r);

                planets[i].acc[0] += f*dx / r / planets[i].mass;
                planets[i].acc[1] += f*dy / r / planets[i].mass;
                planets[i].acc[2] += f*dz / r / planets[i].mass;
            }
        }
    }
}

void updatePositions(struct planet planets[N], double dt) {
    int i;

    for (i = 0; i < N; i++) {
        planets[i].pos[0] += planets[i].vel[0] * dt + 0.5 * planets[i].acc[0] * dt*dt;
        planets[i].pos[1] += planets[i].vel[1] * dt + 0.5 * planets[i].acc[1] * dt*dt;
        planets[i].pos[2] += planets[i].vel[2] * dt + 0.5 * planets[i].acc[2] * dt*dt;
    }
}

void updateVelocities(struct planet planets[N], double dt) {
    int i;

    for (i = 0; i < N; i++) {
        planets[i].vel[0] += 0.5 * (planets[i].acc[0] + planets[i].acc[0]) * dt;
        planets[i].vel[1] += 0.5 * (planets[i].acc[1] + planets[i].acc[1]) * dt;
        planets[i].vel[2] += 0.5 * (planets[i].acc[2] + planets[i].acc[2]) * dt;
    }
}

void printPositions(struct planet planets[N]) {
    int i;

    for (i = 0; i < N; i++) {
        printf("%d %.3e %.3e %.3e\n", i, planets[i].pos[0], planets[i].pos[1], planets[i].pos[2]);
    }
}

int main()
{
    double dt = 3600;	// Time step (s)
    int steps = 10;	// Number of steps

    struct planet planets[N];

    setInitialConditions(planets);

    int i;
    for (i = 0; i < steps; i++) {
        calculateForces(planets);
        updatePositions(planets, dt);
        calculateForces(planets);
        updateVelocities(planets, dt);

        printPositions(planets);
    }

    return 0;
}