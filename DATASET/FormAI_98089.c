//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 /* gravitational acceleration (m/s^2) */
#define PI      3.14159265358979323846 /* the value of pi */

int main(void)
{
    double x, y;     /* position of ball */
    double v, alpha; /* initial velocity (m/s) and angle (rad) */
    double t;        /* time (s) */
    double vx, vy;   /* velocity components (m/s) */

    printf("Enter the initial velocity in m/s: ");
    scanf("%lf", &v);
    printf("Enter the angle of inclination in degrees: ");
    scanf("%lf", &alpha);

    alpha = alpha * PI / 180.0; /* convert to radians */

    /* calculate initial velocity components */
    vx = v * cos(alpha);
    vy = v * sin(alpha);

    x = y = 0.0; /* initial position */

    for (t = 0.0; y >= 0.0; t += 0.1)
    {
        /* calculate new position */
        x = vx * t;
        y = vy * t - 0.5 * GRAVITY * t * t;

        /* print time and position */
        printf("t = %5.1f s   x = %5.1f m   y = %5.1f m\n", t, x, y);
    }

    return 0;
}