//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: immersive
#include <stdio.h>
#include <math.h>

#define G 6.67e-11

typedef struct {
    double x, y;
    double vx, vy;
    double m;
} Planet;

int main() {
    Planet planets[3] = {
        {0, 0, 0, 0, 1.0e6},
        {-100.0, 0, 0, 400.0, 1.0e3},
        {0, 200.0, -300.0, 0, 1.0e2}
    };

    double dt = 0.01;
    double tmax = 100.0;

    for (double t = 0; t < tmax; t += dt) {
        for (int i = 0; i < 3; i++) {
            double ax = 0, ay = 0;
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double r = hypot(dx, dy);
                double f = G * planets[i].m * planets[j].m / (r * r);
                ax += f * dx / r / planets[i].m;
                ay += f * dy / r / planets[i].m;
            }

            planets[i].vx += ax * dt;
            planets[i].vy += ay * dt;
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
        }

        printf("%lf, %lf, %lf\n", t, planets[0].x, planets[0].y);
    }

    return 0;
}