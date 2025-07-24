//FormAI DATASET v1.0 Category: Physics simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

#define G 6.67e-11   // gravitational constant

struct point {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double ax, ay, az; // acceleration
    double mass; // mass of the body
};

struct point p1 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 5.97e24 }; // earth
struct point p2 = { 0, 384400000, 0, 1022, 0, 0, 0, 0, 0, 7.34e22 }; // moon

double dist(struct point p1, struct point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main() {
    double time = 0;
    double dt = 1; // time step

    while (1) {
        double d = dist(p1, p2);
        double f = (G * p1.mass * p2.mass) / (d*d);

        // calculate acceleration due to gravity
        p2.ax = f * (p1.x - p2.x) / (p2.mass * d);
        p2.ay = f * (p1.y - p2.y) / (p2.mass * d);
        p2.az = f * (p1.z - p2.z) / (p2.mass * d);
        p1.ax = -p2.ax;
        p1.ay = -p2.ay;
        p1.az = -p2.az;

        // update velocity using acceleration
        p1.vx += p1.ax * dt;
        p1.vy += p1.ay * dt;
        p1.vz += p1.az * dt;
        p2.vx += p2.ax * dt;
        p2.vy += p2.ay * dt;
        p2.vz += p2.az * dt;

        // update position using velocity
        p1.x += p1.vx * dt;
        p1.y += p1.vy * dt;
        p1.z += p1.vz * dt;
        p2.x += p2.vx * dt;
        p2.y += p2.vy * dt;
        p2.z += p2.vz * dt;

        // print position and time
        printf("time = %f, moon position (%.2f, %.2f, %.2f)\n",
            time, p2.x, p2.y, p2.z);
        time += dt;
    }
    return 0;
}