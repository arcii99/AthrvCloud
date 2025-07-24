//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include<stdio.h>
#include<math.h>
#define MAX 10

int main() {
    double x[MAX], y[MAX], z[MAX], vx[MAX], vy[MAX], vz[MAX];
    double m[MAX], r[MAX], G, dt;
    int i, j, k;
    int n = 4;
    
    // Set initial conditions
    x[0] = 0; y[0] = 0; z[0] = 0;
    vx[0] = 0; vy[0] = 0; vz[0] = 0;
    m[0] = 1;
    r[0] = 0.1;
    
    x[1] = 0.5; y[1] = 0; z[1] = 0;
    vx[1] = 0; vy[1] = 1; vz[1] = 0;
    m[1] = 0.5;
    r[1] = 0.05;
    
    x[2] = 0; y[2] = 1.0; z[2] = 0;
    vx[2] = -1; vy[2] = 0; vz[2] = 0;
    m[2] = 0.25;
    r[2] = 0.025;
    
    x[3] = 0; y[3] = 0; z[3] = 1.5;
    vx[3] = 0; vy[3] = 0; vz[3] = -1;
    m[3] = 0.1;
    r[3] = 0.01;
    
    G = 1;
    dt = 0.001;
    
    // Start simulation
    while (1) {
        // Calculate forces on each object
        double fx[n], fy[n], fz[n];
        for (i = 0; i < n; i++) {
            fx[i] = 0; fy[i] = 0; fz[i] = 0;
            for (j = 0; j < n; j++) {
                if (i == j) continue;
                double dist = sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) + (z[j] - z[i]) * (z[j] - z[i]));
                double f = G * m[i] * m[j] / (dist * dist);
                fx[i] += f * (x[j] - x[i]) / dist;
                fy[i] += f * (y[j] - y[i]) / dist;
                fz[i] += f * (z[j] - z[i]) / dist;
            }
        }
        
        // Update velocities and positions
        for (i = 0; i < n; i++) {
            vx[i] += fx[i] / m[i] * dt;
            vy[i] += fy[i] / m[i] * dt;
            vz[i] += fz[i] / m[i] * dt;
            x[i] += vx[i] * dt;
            y[i] += vy[i] * dt;
            z[i] += vz[i] * dt;
        }
        
        // Print positions
        printf("Positions:\n");
        for (i = 0; i < n; i++) {
            printf("(%lf, %lf, %lf)\n", x[i], y[i], z[i]);
        }
        printf("\n");
        
        // Check for termination
        int done = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j) continue;
                double dist = sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) + (z[j] - z[i]) * (z[j] - z[i]));
                if (dist < r[i] + r[j]) {
                    printf("Collision detected between objects %d and %d\n", i, j);
                    done = 0;
                }
            }
        }
        if (done) break;
    }
    
    return 0;
}