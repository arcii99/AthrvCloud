//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: sophisticated
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11    // gravitational constant

typedef struct {
    double x, y, z;     // position
    double vx, vy, vz;  // velocity
    double mass;        // mass
} Body;

void simulate(Body* bodies, int n, double time_step, int steps) {
    int i, j, k;
    double dx, dy, dz, distance, d2, acceleration;
    double ax, ay, az;

    for (k = 0; k < steps; k++) {
        // calculate accelerations for each body
        for (i = 0; i < n; i++) {
            ax = ay = az = 0;
            for (j = 0; j < n; j++) {
                if (i != j) {
                    // calculate distance and acceleration due to gravity
                    dx = bodies[j].x - bodies[i].x;
                    dy = bodies[j].y - bodies[i].y;
                    dz = bodies[j].z - bodies[i].z;
                    distance = sqrt(dx*dx + dy*dy + dz*dz);
                    d2 = distance*distance;
                    acceleration = G * bodies[j].mass / d2;

                    // calculate acceleration components
                    ax += acceleration * dx / distance;
                    ay += acceleration * dy / distance;
                    az += acceleration * dz / distance;
                }
            }
            // update velocity and position
            bodies[i].vx += ax * time_step;
            bodies[i].vy += ay * time_step;
            bodies[i].vz += az * time_step;
            bodies[i].x += bodies[i].vx * time_step;
            bodies[i].y += bodies[i].vy * time_step;
            bodies[i].z += bodies[i].vz * time_step;
        }
    }
}

int main(void) {
    // create solar system simulation
    Body sun    = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.989e+30};
    Body mercury = {5.791e+10, 0.0, 0.0, 0.0, 4.788e+04, 0.0, 3.285e+23};
    Body venus  = {1.082e+11, 0.0, 0.0, 0.0, 3.502e+04, 0.0, 4.867e+24};
    Body earth  = {1.496e+11, 0.0, 0.0, 0.0, 2.978e+04, 0.0, 5.972e+24};
    Body mars   = {2.279e+11, 0.0, 0.0, 0.0, 2.410e+04, 0.0, 6.390e+23};
    Body jupiter = {7.785e+11, 0.0, 0.0, 0.0, 1.307e+04, 0.0, 1.898e+27};

    Body bodies[] = {sun, mercury, venus, earth, mars, jupiter};
    int n = sizeof(bodies) / sizeof(Body);

    simulate(bodies, n, 60*60*24, 365*10);

    // print final positions and velocities
    printf("Body       x (m)            y (m)          z (m)            vx (m/s)         vy (m/s)         vz (m/s)\n");
    for (int i = 0; i < n; i++) {
        printf("%-10s %15.3f %15.3f %15.3f %15.3f %15.3f %15.3f\n",
            i==0?"Sun":i==1?"Mercury":i==2?"Venus":i==3?"Earth":i==4?"Mars":"Jupiter",
            bodies[i].x, bodies[i].y, bodies[i].z, bodies[i].vx, bodies[i].vy, bodies[i].vz);
    }

    return 0;
}