//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: energetic
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant
#define DT 86400 // one day in seconds
#define N 3 // number of planets

double x[N], y[N], z[N]; // planet positions
double vx[N], vy[N], vz[N]; // planet velocities
double m[N]; // planet masses

void update(int i, int j) {
    double dx = x[j] - x[i];
    double dy = y[j] - y[i];
    double dz = z[j] - z[i];
    double d = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * m[i] * m[j] / (d*d);
    double fx = f * dx / d;
    double fy = f * dy / d;
    double fz = f * dz / d;
    vx[i] += fx/m[i] * DT;
    vy[i] += fy/m[i] * DT;
    vz[i] += fz/m[i] * DT;
    vx[j] -= fx/m[j] * DT;
    vy[j] -= fy/m[j] * DT;
    vz[j] -= fz/m[j] * DT;
}

int main() {
    // planet 1
    x[0] = 0.0;
    y[0] = 0.0;
    z[0] = 0.0;
    vx[0] = 0.0;
    vy[0] = 0.0;
    vz[0] = 0.0;
    m[0] = 5.972e24; // earth
    
    // planet 2
    x[1] = 1.0e11; // earth-sun distance
    y[1] = 0.0;
    z[1] = 0.0;
    vx[1] = 0.0;
    vy[1] = 29.78e3; // earth's orbital velocity
    vz[1] = 0.0;
    m[1] = 1.989e30; // sun
    
    // planet 3
    x[2] = 1.5e11; // earth-venus distance
    y[2] = 0.0;
    z[2] = 0.0;
    vx[2] = 0.0;
    vy[2] = 35.26e3; // venus's orbital velocity
    vz[2] = 0.0;
    m[2] = 4.867e24; // venus
    
    double t = 0.0;
    while (1) {
        printf("t = %lf\n", t);
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                update(i, j);
            }
            x[i] += vx[i] * DT;
            y[i] += vy[i] * DT;
            z[i] += vz[i] * DT;
            printf("%.2lf\t%.2lf\t%.2lf\n", x[i], y[i], z[i]);
        }
        t += DT;
    }
    return 0;
}