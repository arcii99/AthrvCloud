//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: random
#include <stdio.h>
#include <math.h>

const double G = 6.67430e-11;   // Gravitational constant

// Structure for representing planets
struct Planet {
    char name[20];
    double mass;    // Mass in kg
    double x;       // X-coordinate in m
    double y;       // Y-coordinate in m
    double z;       // Z-coordinate in m
    double vx;      // Velocity in x-direction in m/s
    double vy;      // Velocity in y-direction in m/s
    double vz;      // Velocity in z-direction in m/s
};

// Function to calculate distance between two planets
double distance(struct Planet p1, struct Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to calculate acceleration of a planet due to other planets
void calculateAcceleration(struct Planet planets[], int n, int i, double *ax, double *ay, double *az) {
    double ax_sum = 0;
    double ay_sum = 0;
    double az_sum = 0;
    for (int j = 0; j < n; j++) {
        if (i != j) {
            double d = distance(planets[i], planets[j]);
            double f = G * planets[i].mass * planets[j].mass / (d*d);
            double cos_theta = (planets[j].x - planets[i].x) / d;
            double sin_theta = (planets[j].y - planets[i].y) / d;
            double cos_phi = cos(atan((planets[j].z - planets[i].z) / d));
            double sin_phi = sin(atan((planets[j].z - planets[i].z) / d));
            ax_sum += f * cos_theta * cos_phi / planets[i].mass;
            ay_sum += f * sin_theta * cos_phi / planets[i].mass;
            az_sum += f * sin_phi / planets[i].mass;
        }
    }
    *ax = ax_sum;
    *ay = ay_sum;
    *az = az_sum;
}

int main() {
    struct Planet planets[] = {
        {"Earth", 5.972e24, 0, 0, 0, 0, 0, 0},
        {"Mars", 6.39e23, 2.279e11, 0, 0, 0, 24130, 0},
        {"Jupiter", 1.898e27, 0, 7.785e11, 0, 13070, 0, 0}
    };
    int n = sizeof(planets) / sizeof(struct Planet);
    double t = 0;
    double dt = 86400;  // One day in seconds
    while (1) {
        printf("Time: %lf\n", t);
        // Calculate accelerations for each planet
        for (int i = 0; i < n; i++) {
            double ax, ay, az;
            calculateAcceleration(planets, n, i, &ax, &ay, &az);
            planets[i].vx += ax * dt;
            planets[i].vy += ay * dt;
            planets[i].vz += az * dt;
        }
        // Update positions for each planet
        for (int i = 0; i < n; i++) {
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
            planets[i].z += planets[i].vz * dt;
            printf("%s: (%lf, %lf, %lf)\n", planets[i].name, planets[i].x / 1000, planets[i].y / 1000, planets[i].z / 1000);
        }
        t += dt;
    }
}