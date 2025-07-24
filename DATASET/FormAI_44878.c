//FormAI DATASET v1.0 Category: Physics simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void updatePosition(double *x, double *y, double *vx, double *vy, double *t, double dt) {
    *x += *vx * dt;
    *y += *vy * dt;
    *t += dt;
    *vx -= 9.8 * dt;
}

int main() {
    double x = 0.0;    // initial X position
    double y = 0.0;    // initial Y position
    double vx = 50.0;  // initial X velocity
    double vy = 0.0;   // initial Y velocity
    double t = 0.0;    // initial time
    double dt = 0.01;  // time step
    int total_simulated_time = 10;  // total time to simulate
    int num_steps = total_simulated_time / dt;  // number of steps to simulate
    int i;

    srand(time(NULL));

    // create output file for plotting
    FILE *fp;
    fp = fopen("trajectory.dat", "w");
    fprintf(fp, "# x\t y\n");

    for (i = 0; i <= num_steps; i++) {
        updatePosition(&x, &y, &vx, &vy, &t, dt);

        // if the object hits the ground
        if (y < 0.0) {
            fprintf(fp, "%lf\t%lf\n", x, 0.0);
            break;
        }

        fprintf(fp, "%lf\t%lf\n", x, y);

        // add some randomness to the velocity
        vx += ((double)rand() / RAND_MAX) * 2 - 1;
        vy += ((double)rand() / RAND_MAX) * 2 - 1;
    }

    fclose(fp);

    return 0;
}