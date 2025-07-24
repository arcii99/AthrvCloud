//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>
#define G 6.67408e-11

struct planet {
    char name[20];
    double mass, radius, x, y, z, vx, vy, vz;
};

void update_positions(struct planet *p, int n, double time_step) {
    int i, j;
    double distance, force_magnitude, force_x, force_y, force_z, acceleration_x, acceleration_y, acceleration_z;
    for (i = 0; i < n; i++) {
        force_x = force_y = force_z = 0;
        for (j = 0; j < n; j++) {
            if (j == i) continue;
            distance = sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2) + pow(p[i].z - p[j].z, 2));
            force_magnitude = G * p[i].mass * p[j].mass / pow(distance, 2);
            force_x += force_magnitude * (p[j].x - p[i].x) / distance;
            force_y += force_magnitude * (p[j].y - p[i].y) / distance;
            force_z += force_magnitude * (p[j].z - p[i].z) / distance;
        }
        acceleration_x = force_x / p[i].mass;
        acceleration_y = force_y / p[i].mass;
        acceleration_z = force_z / p[i].mass;
        p[i].vx += acceleration_x * time_step;
        p[i].vy += acceleration_y * time_step;
        p[i].vz += acceleration_z * time_step;
        p[i].x += p[i].vx * time_step;
        p[i].y += p[i].vy * time_step;
        p[i].z += p[i].vz * time_step;
    }
}

int main() {
    struct planet p[3] = {
        { "Planet1", 5.97e24, 6.38e6, 0, 0, 0, 0, 0, 0 },
        { "Planet2", 6.39e23, 3.39e6, 0, 3.84e8, 0, 1022, 0, 0 },
        { "Planet3", 7.342e22, 1.74e6, 0, -3.84e8, 0, -1022, 0, 0 }
    };
    double time_step = 1000; // seconds
    int t;
    for (t = 0; t < 86400 * 365; t += time_step) {
        update_positions(p, 3, time_step);
        printf("t = %d seconds\n", t);
        printf("%-10s%-15s%-15s%-15s\n", "Planet", "x position", "y position", "z position");
        printf("%-10s%-15.2f%-15.2f%-15.2f\n", p[0].name, p[0].x, p[0].y, p[0].z);
        printf("%-10s%-15.2f%-15.2f%-15.2f\n", p[1].name, p[1].x, p[1].y, p[1].z);
        printf("%-10s%-15.2f%-15.2f%-15.2f\n", p[2].name, p[2].x, p[2].y, p[2].z);
    }
    return 0;
}