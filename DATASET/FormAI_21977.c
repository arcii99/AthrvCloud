//FormAI DATASET v1.0 Category: Physics simulation ; Style: calm
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define GRAVITY 9.81

int main() {
    double v, angle; // initial velocity and angle in degrees
    printf("Enter the initial velocity and angle (in degrees): ");
    scanf("%lf %lf", &v, &angle);
    
    double vx = v * cos(angle * PI / 180); // x component of velocity
    double vy = v * sin(angle * PI / 180); // y component of velocity
    
    // calculate the time of flight and maximum height
    double t_max = vy / GRAVITY;
    double h_max = pow(vy, 2) / (2 * GRAVITY);
    
    // calculate the range
    double range = vx * t_max;
    
    // output the results
    printf("Maximum height: %lf meters\n", h_max);
    printf("Range: %lf meters\n", range);
    
    return 0;
}