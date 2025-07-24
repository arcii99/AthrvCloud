//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multivariable
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

struct planet {
    char name[20];
    double mass;
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double ax, ay, az; // acceleration
};

void update_position(struct planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void update_velocity(struct planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_acceleration(struct planet *p, struct planet *planets, int n) {
    double ax = 0.0, ay = 0.0, az = 0.0;
    for (int i = 0; i < n; i++) {
        if (p == &planets[i]) continue; // don't compute self-gravity
        double dx = planets[i].x - p->x;
        double dy = planets[i].y - p->y;
        double dz = planets[i].z - p->z;
        double r = sqrt(dx*dx + dy*dy + dz*dz);
        double f = G * p->mass * planets[i].mass / (r*r*r);
        ax += f * dx;
        ay += f * dy;
        az += f * dz;
    }
    p->ax = ax / p->mass;
    p->ay = ay / p->mass;
    p->az = az / p->mass;
}

int main() {
    struct planet sun = {"Sun", 1.989e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    struct planet earth = {"Earth", 5.9742e24, 1.495e11, 0.0, 0.0, 0.0, 29783.0, 0.0, 0.0, 0.0};
    struct planet mars = {"Mars", 6.4171e23, -2.279e11, 0.0, 0.0, 0.0, 24007.0, 0.0, 0.0, 0.0};
    struct planet planets[] = {sun, earth, mars};
    int n = sizeof(planets) / sizeof(planets[0]);

    double dt = 3600.0; // time step (1 hour in seconds)
    double t = 0.0; // simulation time
    double t_end = 365.0 * 24.0 * 3600.0; // simulation end time (1 year in seconds)

    while (t < t_end) {
        // update accelerations
        for (int i = 0; i < n; i++) {
            update_acceleration(&planets[i], planets, n);
        }

        // update positions and velocities
        for (int i = 0; i < n; i++) {
            update_position(&planets[i], dt);
            update_velocity(&planets[i], dt);
        }

        printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n",
            t,
            sun.x, sun.y, sun.z,
            earth.x, earth.y, earth.z,
            mars.x, mars.y, mars.z,
            earth.vx, mars.vx);

        t += dt;
    }

    return 0;
}