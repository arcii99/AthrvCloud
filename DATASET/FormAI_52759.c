//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: random
#include <stdio.h>
#include <math.h>

int main()
{
    const double GRAV_CONST = 6.67408e-11;

    double mass1, mass2, dist;
    printf("Enter the mass of planet 1 (in kg): ");
    scanf("%lf", &mass1);
    printf("Enter the mass of planet 2 (in kg): ");
    scanf("%lf", &mass2);
    printf("Enter the distance between the two planets (in meters): ");
    scanf("%lf", &dist);

    double force = GRAV_CONST * mass1 * mass2 / pow(dist, 2);

    printf("The gravitational force between planet 1 and planet 2 is %lf N.\n", force);

    double time, vel1 = 0, vel2 = 0, acc1, acc2, pos1 = 40000000, pos2 = -40000000;
    printf("Enter the time step (in seconds): ");
    scanf("%lf", &time);

    while (1) {
        double dx = pos2 - pos1;
        double dy = 0;
        double theta = atan(dy / dx);
        double force_x = force * cos(theta);
        double force_y = force * sin(theta);
        acc1 = force_x / mass1;
        acc2 = force_x / mass2;
        vel1 += acc1 * time;
        vel2 -= acc2 * time;
        pos1 += vel1 * time;
        pos2 += vel2 * time;
        dist = fabs(pos2 - pos1);
        if (dist < 1000) {
            printf("The two planets have collided!\n");
            break;
        }
        printf("Pos1: %lf  Vel1: %lf  Acc1: %lf | Pos2: %lf  Vel2: %lf  Acc2: %lf\n", pos1, vel1, acc1, pos2, vel2, acc2);
    }

    return 0;
}