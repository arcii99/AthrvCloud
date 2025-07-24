//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265359
#define G 6.67430e-11
#define AU 149.6e9

struct Body {
    double x, y, z; //position
    double vx, vy, vz; //velocity
    double ax, ay, az; //acceleration
    double mass; //mass
};

void update_acceleration(struct Body *objs, int n) {
    double r, rx, ry, rz, a;

    for (int i = 0; i < n; i++) {
        objs[i].ax = objs[i].ay = objs[i].az = 0;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            rx = objs[j].x - objs[i].x;
            ry = objs[j].y - objs[i].y;
            rz = objs[j].z - objs[i].z;

            r = sqrt(rx*rx + ry*ry + rz*rz);
            a = G*objs[j].mass/pow(r, 3);

            objs[i].ax += a*rx;
            objs[i].ay += a*ry;
            objs[i].az += a*rz;
        }
    }
}

void update_velocity(struct Body *objs, int n, double dt) {
    for (int i = 0; i < n; i++) {
        objs[i].vx += objs[i].ax*dt;
        objs[i].vy += objs[i].ay*dt;
        objs[i].vz += objs[i].az*dt;
    }
}

void update_position(struct Body *objs, int n, double dt) {
    for (int i = 0; i < n; i++) {
        objs[i].x += objs[i].vx*dt;
        objs[i].y += objs[i].vy*dt;
        objs[i].z += objs[i].vz*dt;
    }
}

void initialize(struct Body *objs, int n) {
    srand(time(NULL));

    objs[0].x = objs[0].y = objs[0].z = objs[0].vx = objs[0].vy = objs[0].vz = objs[0].ax = objs[0].ay = objs[0].az = 0.0;
    objs[0].mass = 1.989e30;

    for (int i = 1; i < n; i++) {
        objs[i].x = ((double) rand() / RAND_MAX) * AU;
        objs[i].y = ((double) rand() / RAND_MAX) * AU;
        objs[i].z = ((double) rand() / RAND_MAX) * AU;

        objs[i].vx = ((double) rand() / RAND_MAX) * 1000.0;
        objs[i].vy = ((double) rand() / RAND_MAX) * 1000.0;
        objs[i].vz = ((double) rand() / RAND_MAX) * 1000.0;

        objs[i].ax = objs[i].ay = objs[i].az = 0.0;
        objs[i].mass = ((double) rand() / RAND_MAX) * 5.0e23;
    }
}

void print_body(struct Body obj) {
    printf("Position: (%.3e, %.3e, %.3e)\n", obj.x, obj.y, obj.z);
    printf("Velocity: (%.3e, %.3e, %.3e)\n", obj.vx, obj.vy, obj.vz);
    printf("Acceleration: (%.3e, %.3e, %.3e)\n", obj.ax, obj.ay, obj.az);
    printf("Mass: %.3e\n\n", obj.mass);
}

void print_bodies(struct Body *objs, int n) {
    for (int i = 0; i < n; i++) {
        printf("Body %d:\n", i);
        print_body(objs[i]);
    }
}

int main() {
    int n = 8;
    double dt = 86400.0;

    struct Body objs[8];

    initialize(objs, n);
    print_bodies(objs, n);

    for (int i = 0; i < 36500; i++) {
        update_acceleration(objs, n);
        update_velocity(objs, n, dt);
        update_position(objs, n, dt);
    }

    print_bodies(objs, n);

    return 0;
}