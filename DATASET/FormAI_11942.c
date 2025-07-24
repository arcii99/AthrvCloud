//FormAI DATASET v1.0 Category: Physics simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define GRAVITY 9.81 // m/s^2
#define DELTA_T 0.001 // s
#define K 100.0 // N/m

void updatePosition(double *p, double *v, double a, double delta_t)
{
    *p += (*v * delta_t) + (0.5 * a * delta_t * delta_t);
    *v += a * delta_t;
}

double calculateForce(double p)
{
    return -1.0 * K * p;
}

int main()
{
    double position = 0.0;
    double velocity = 0.0;
    double acceleration = calculateForce(position) / GRAVITY;
    double total_mass = 2.0; // kg

    srand(time(NULL)); // initialize random seed
    
    printf("Starting physics simulation...\n\n");
    
    for (int i = 0; i < 10000; i++)
    {
        double random_force = (double) rand() / RAND_MAX * 10.0 - 5.0; // N
        acceleration = (calculateForce(position) + random_force) / total_mass / GRAVITY;
        updatePosition(&position, &velocity, acceleration, DELTA_T);
        
        printf("Time: %.3f s\n", i * DELTA_T);
        printf("Position: %.3f m\n", position);
        printf("Velocity: %.3f m/s\n", velocity);
        printf("Acceleration: %.3f m/s^2\n", acceleration);
        printf("Total force: %.3f N\n\n", calculateForce(position) + random_force);
    }
    
    printf("Physics simulation complete.\n");
    return 0;
}