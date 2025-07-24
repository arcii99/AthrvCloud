//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: invasive
#include<stdio.h>
#include<math.h>

#define G 6.67e-11

struct planet {
    char name[50];
    float mass;
    float radius;
    float x,y,z;
    float vx,vy,vz;
};

void simulate(struct planet *p, int num_planets, float time_step, int iterations) {
    int i, j, k;
    float dx, dy, dz, dist, force, accel, accel_x, accel_y, accel_z;
    for (k = 0; k < iterations; k++) {
        for (i = 0; i < num_planets; i++) {
            accel_x = accel_y = accel_z = 0;
            for (j = 0; j < num_planets; j++) {
                if (i == j)
                    continue;
                dx = p[j].x - p[i].x;
                dy = p[j].y - p[i].y;
                dz = p[j].z - p[i].z;
                dist = sqrt(dx*dx + dy*dy + dz*dz);
                force = G * p[i].mass * p[j].mass / (dist * dist);
                accel = force / p[i].mass;
                accel_x += accel * dx / dist;
                accel_y += accel * dy / dist;
                accel_z += accel * dz / dist;
            }
            p[i].vx += accel_x * time_step;
            p[i].vy += accel_y * time_step;
            p[i].vz += accel_z * time_step;
            p[i].x += p[i].vx * time_step;
            p[i].y += p[i].vy * time_step;
            p[i].z += p[i].vz * time_step;
        }
    }
}

int main() {
    struct planet planets[] = {
        {
            "Earth",
            5.97e24,
            6371e3,
            0, 0, 0,
            0, 0, 0
        },
        {
            "Moon",
            7.34e22,
            1737e3,
            384400e3, 0, 0,
            0, 1000, 0
        },
        {
            "Mars",
            6.39e23,
            3390e3,
            227940000e3, 0, 0,
            0, -250, 0
        }
    };
    int i;
    int num_planets = sizeof(planets)/sizeof(struct planet);
    float time_step = 3600;
    int iterations = 24 * 365;
    simulate(planets, num_planets, time_step, iterations);
    for (i = 0; i < num_planets; i++) {
        printf("%s: %f %f %f\n", planets[i].name,
               planets[i].x/1000, planets[i].y/1000, planets[i].z/1000);
    }
    return 0;
}