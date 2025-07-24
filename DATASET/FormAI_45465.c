//FormAI DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>

int main() {
    float v0, theta, h0, dt, t;
    float g = 9.81;
    float pi = 3.14159265359;
    float x, y;

    printf("Enter initial velocity (m/s): ");
    scanf("%f", &v0);

    printf("Enter launch angle (degrees): ");
    scanf("%f", &theta);
    theta = theta * pi / 180; // convert degrees to radians

    printf("Enter initial height (m): ");
    scanf("%f", &h0);

    printf("Enter time step (s): ");
    scanf("%f", &dt);

    x = 0;
    y = h0;
    t = 0;

    while (y >= 0) {
        printf("%f, %f\n", x, y);
        x = v0 * cos(theta) * t;
        y = -0.5 * g * t * t + v0 * sin(theta) * t + h0;
        t += dt;
    }

    return 0;
}