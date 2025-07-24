//FormAI DATASET v1.0 Category: Physics simulation ; Style: complex
#include <stdio.h>
#include <math.h>

#define G 9.81  // gravitational constant

int main() {

    double v0, theta, t;  // initial velocity, angle of launch, time elapsed
    double x, y;          // position of projectile at time t

    // prompt user for inputs
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &v0);
    printf("Enter angle of launch (degrees): ");
    scanf("%lf", &theta);

    // convert angle to radians
    theta = theta * M_PI / 180.0;

    // calculate time of flight
    double tmax = 2.0*v0*sin(theta)/G;

    // update position every 0.1 seconds
    for (t = 0.0; t <= tmax; t += 0.1) {
        x = v0*cos(theta)*t;
        y = v0*sin(theta)*t - 0.5*G*t*t;
        
        // print the x and y coordinates at each time step
        printf("At time t = %.1f seconds, the projectile is at position (x,y) = (%.2f, %.2f)\n", t, x, y);
        
        // check if projectile has landed
        if (y <= 0) {
            printf("The projectile has landed at time t = %.1f seconds.\n", t);
            break;
        }
    }
    
    return 0;
}