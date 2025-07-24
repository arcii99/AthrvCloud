//FormAI DATASET v1.0 Category: Physics simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265

struct projectile {
    double x;   // horizontal position
    double y;   // vertical position
    double v;   // velocity
    double angle;   // angle of launch
    double t;   // time
};

int main() {
    struct projectile p;
    printf("Enter the initial horizontal X position (m):\n");
    scanf("%lf", &p.x);
    printf("Enter the initial vertical Y position (m):\n");
    scanf("%lf", &p.y);
    printf("Enter the initial velocity (m/s):\n");
    scanf("%lf", &p.v);
    printf("Enter the angle of launch (deg):\n");
    scanf("%lf", &p.angle);
    printf("Enter the time interval between calculations (s):\n");
    scanf("%lf", &p.t);

    double vx = p.v * cos(p.angle * PI/180);
    double vy = p.v * sin(p.angle * PI/180);

    printf("\nResults:\n");

    while (p.y >= 0) {
        printf("Time: %.2lf s, Position: (%.2lf, %.2lf) m\n", p.t, p.x, p.y);
        p.x += vx * p.t;
        p.y += vy * p.t - 0.5 * 9.81 * pow(p.t, 2);
        vy -= 9.81 * p.t;
        p.t += p.t;
    }
    printf("\nProjectile has landed!\n");

    return 0;
}