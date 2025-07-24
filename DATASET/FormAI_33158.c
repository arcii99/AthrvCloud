//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238

int main()
{
    double g = 9.81; //acceleration due to gravity (m/s^2)
    double m = 0.1; //mass of the object (kg)
    double k = 0.1; //friction coefficient
    double t = 0.0; //time (s)
    double dt = 0.001; //time step (s)
    double x = 0.0; //position (m)
    double v = 0.0; //velocity (m/s)
    double a; //acceleration (m/s^2)
    
    int iterations = 10000; //number of time steps
    
    for (int i = 0; i < iterations; i++) {
        a = -g - (k/m) * v*v * (v > 0 ? 1 : -1);
        x += v*dt + 0.5*a*dt*dt;
        v += a*dt;
        t += dt;
        
        printf("%f, %f, %f\n", t, x, v);
        
        if (x <= 0.0) {
            v = -v*sqrt(k/m*2);
            x = 0.0;
        }
    }
    
    return 0;
}