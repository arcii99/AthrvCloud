//FormAI DATASET v1.0 Category: Physics simulation ; Style: rigorous
/* A Physics simulation program that calculates the trajectory of a projectile
   fired at a given velocity and angle in a vacuum. */

#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8 // m/s^2
#define TIME_STEP 0.1 // s

int main() {
    double velocity, angle, radians;
    double x = 0, y = 0, t = 0;
    double x_prev = 0, y_prev = 0;
    double x_max = 0, y_max = 0;
    
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &velocity);
    
    printf("Enter firing angle (degrees): ");
    scanf("%lf", &angle);
    
    radians = angle * M_PI / 180.0;
    
    while (y >= 0) {
        x_prev = x;
        y_prev = y;
        
        x = velocity * cos(radians) * t;
        y = velocity * sin(radians) * t - 0.5 * GRAVITY * pow(t, 2);
        
        if (y > y_max) {
            y_max = y;
            x_max = x;
        }
        
        printf("t: %lf, x: %lf, y: %lf\n", t, x, y);
        
        t += TIME_STEP;
    }
    
    printf("\n\n");
    printf("Max height: %lf m\n", y_max);
    printf("Distance traveled: %lf m\n", x_max);
    
    return 0;
}