//FormAI DATASET v1.0 Category: Physics simulation ; Style: Donald Knuth
/* Donald Knuth style C physics simulation example program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define N 100 // number of time steps
#define DT 1 // time step
#define M 5.97e24 // mass of Earth
#define R 6.37e6 // radius of Earth
#define V 1000 // initial velocity
#define THETA M_PI/4 // initial angle
#define X0 0 // initial x position
#define Y0 R // initial y position

int main(void) {
    
    double x[N], y[N], vx[N], vy[N], ax[N], ay[N];
    int i;
    
    // set initial conditions
    x[0] = X0;
    y[0] = Y0;
    vx[0] = V*cos(THETA);
    vy[0] = V*sin(THETA);
    ax[0] = 0;
    ay[0] = -G*M/R/R;
    
    // simulate motion
    for (i=1; i<N; i++) {
        
        // calculate acceleration
        ax[i] = -G*M*x[i-1]/pow(x[i-1]*x[i-1]+y[i-1]*y[i-1], 1.5);
        ay[i] = -G*M*y[i-1]/pow(x[i-1]*x[i-1]+y[i-1]*y[i-1], 1.5);
        
        // update velocity
        vx[i] = vx[i-1] + ax[i]*DT;
        vy[i] = vy[i-1] + ay[i]*DT;
        
        // update position
        x[i] = x[i-1] + vx[i]*DT;
        y[i] = y[i-1] + vy[i]*DT;
        
        // check for collision with Earth
        if (sqrt(x[i]*x[i]+y[i]*y[i]) < R) {
            printf("Collision with Earth!\n");
            break;
        }
    }
    
    // output results
    for (i=0; i<N; i++) {
        printf("t = %d: x = %f, y = %f, vx = %f, vy = %f\n", i, x[i], y[i], vx[i], vy[i]);
    }
    
    return 0;
}