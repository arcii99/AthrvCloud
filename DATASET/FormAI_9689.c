//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main(void)
{
    double mass, spring_constant, initial_displacement, time_step;
    double position, velocity, acceleration, time, period, omega;
    int num_periods, num_steps_per_period, i, j;

    printf("Enter mass (kg) of the object: ");
    scanf("%lf", &mass);

    printf("Enter spring constant (N/m) of the spring: ");
    scanf("%lf", &spring_constant);

    printf("Enter initial displacement (m) of the object: ");
    scanf("%lf", &initial_displacement);

    printf("Enter time step (s) for the simulation: ");
    scanf("%lf", &time_step);

    printf("Enter number of periods for the simulation: ");
    scanf("%d", &num_periods);

    printf("Enter number of steps per period for the simulation: ");
    scanf("%d", &num_steps_per_period);

    omega = sqrt(spring_constant/mass);
    period = 2*PI/omega;

    for (i = 0; i < num_periods; i++)
    {
        for (j = 0; j < num_steps_per_period; j++)
        {
            acceleration = -omega*omega*position;
            velocity += acceleration*time_step;
            position += velocity*time_step;

            time += time_step;
            printf("Time: %.2f seconds\tPosition: %.4f meters\n", time, position);
        }
    }

    return 0;
}