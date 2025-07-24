//FormAI DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <math.h>

int main()
{
    int option;
    float g = 9.8; // acceleration due to gravity
    float v, u, a, s, t; // variables for velocity, initial velocity, acceleration, distance, and time
    float force, mass, acceleration; // variables for force, mass, and acceleration

    printf("\nPHYSICS SIMULATION PROGRAM\n");
    printf("--------------------------\n\n");
    printf("MENU:\n");
    printf("1. Motion Simulation\n");
    printf("2. Force Calculation\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("\nMOTION SIMULATION\n");
            printf("------------------\n");
            printf("Enter initial velocity (m/s): ");
            scanf("%f", &u);
            printf("Enter acceleration (m/s^2): ");
            scanf("%f", &a);
            printf("Enter time (s): ");
            scanf("%f", &t);

            // calculate final velocity and distance traveled
            v = u + (a * t);
            s = (u * t) + (0.5 * a * pow(t, 2));

            printf("\nFinal Velocity: %.2f m/s", v);
            printf("\nDistance Traveled: %.2f m", s);
            break;

        case 2:
            printf("\nFORCE CALCULATION\n");
            printf("------------------\n");
            printf("Enter mass (kg): ");
            scanf("%f", &mass);
            printf("Enter acceleration (m/s^2): ");
            scanf("%f", &acceleration);

            // calculate force
            force = mass * acceleration;

            printf("\nForce: %.2f N", force);
            break;

        default:
            printf("\nInvalid option selected.");
    }

    return 0;
}