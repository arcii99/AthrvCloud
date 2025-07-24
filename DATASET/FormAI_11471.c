//FormAI DATASET v1.0 Category: Physics simulation ; Style: romantic
#include <stdio.h>
#include <math.h>

#define g 9.8    // gravitational acceleration

int main() {
    float v, alpha, h;   // initial velocity, angle with horizontal, initial height of ball
    float t, x, y;       // time, position at x and y axes
    float t_max;         // time to reach maximum height of ball
    float h_max;         // maximum height of ball
    
    // user input for initial parameters
    printf("Enter initial velocity, angle (in degrees), and initial height of ball:\n");
    scanf("%f %f %f", &v, &alpha, &h);
    
    // convert angle from degrees to radians for calculations
    alpha = alpha * M_PI / 180;
    
    // calculate t_max and h_max
    t_max = (v * sin(alpha)) / g;
    h_max = h + ((v * v * sin(alpha) * sin(alpha)) / (2 * g));
    
    // simulate trajectory of ball
    for (t = 0; t <= t_max; t += 0.01) {
        x = v * cos(alpha) * t;
        y = h + (v * sin(alpha) * t) - (0.5 * g * t * t);
        printf("At time %f seconds, the position of the ball is (%f,%f).\n", t, x, y);
    }
    
    return 0;
}