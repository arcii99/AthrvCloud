//FormAI DATASET v1.0 Category: Physics simulation ; Style: dynamic
#include<stdio.h>
#include<math.h>

#define PI 3.14159265359

int main(){
    double v0, theta, x, y, t;
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &v0);
    printf("Enter the launch angle (degrees): ");
    scanf("%lf", &theta);
    theta = theta * PI / 180.0;
    printf("Enter the initial x-coordinate (m): ");
    scanf("%lf", &x);
    printf("Enter the initial y-coordinate (m): ");
    scanf("%lf", &y);

    double vx = v0 * cos(theta);
    double vy = v0 * sin(theta);

    double ax = 0, ay = -9.8; // acceleration due to gravity

    t = 0;
    while(y >= 0){
        x = x + vx*t + 0.5*ax*t*t;
        y = y + vy*t + 0.5*ay*t*t;
        printf("Time: %lf seconds | X-Coordinate: %lf meters | Y-Coordinate: %lf meters\n", t, x, y);
        t += 0.1; // increment time by 0.1 seconds
    }

    printf("Total time of flight: %lf seconds\n", t);
    return 0;
}