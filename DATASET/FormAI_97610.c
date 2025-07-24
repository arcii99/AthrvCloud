//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main() {
    double x[3], y[3], vx[3], vy[3], ax[3], ay[3], m[3];
    double dt, tmax, G;
    int i, j, k;
    FILE *fptr;
    
    G = 6.674e-11;
    dt = 60*60; // 1 hour
    tmax = 365*24*60*60; // simulate for 1 year
    
    // initial conditions
    x[0] = 0; y[0] = 0; vx[0] = 0; vy[0] = 0; m[0] = 5.972e24; // earth
    x[1] = 1.496e11; y[1] = 0; vx[1] = 0; vy[1] = 3.0e4; m[1] = 1.989e30; // sun
    x[2] = 0; y[2] = 384400e3; vx[2] = 1022; vy[2] = 0; m[2] = 7.342e22; // moon
    
    fptr=fopen("output.txt","w");
    
    for (i = 0; i < tmax/dt; i++) {
        // calculate acceleration
        for (j = 0; j < 3; j++) {
            ax[j] = 0;
            ay[j] = 0;
            for (k = 0; k < 3; k++) {
                if (j != k) {
                    double dx, dy, d, f;
                    dx = x[k] - x[j];
                    dy = y[k] - y[j];
                    d = sqrt(dx*dx + dy*dy);
                    f = G*m[j]*m[k]/(d*d);
                    ax[j] += f*dx/d/m[j];
                    ay[j] += f*dy/d/m[j];
                }
            }
        }
        // update velocity and position
        for (j = 0; j < 3; j++) {
            vx[j] += ax[j]*dt;
            vy[j] += ay[j]*dt;
            x[j] += vx[j]*dt;
            y[j] += vy[j]*dt;
            fprintf(fptr,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",x[0],y[0],x[1],y[1],x[2],y[2],vx[2],vy[2]);
        }
    }
    fclose(fptr);
    return 0;
}