//FormAI DATASET v1.0 Category: Physics simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.67e-11

/*
 * Function to calculate the force between two objects
 * Parameters:
 *   mass1 : mass of object 1
 *   mass2 : mass of object 2
 *   dist : distance between the two objects
 * Return : force between the two objects
 */
double force_calculator(double mass1, double mass2, double dist) {
    double force = GRAV_CONST * mass1 * mass2 / pow(dist, 2);
    return force;
}

/*
 * Function to calculate acceleration of an object subject to a force
 * Parameters:
 *   mass : mass of the object
 *   force : force acting on the object
 * Return : acceleration of the object
 */
double acceleration_calculator(double mass, double force) {
    double acc = force / mass;
    return acc;
}

/*
 * Function to update the velocity of the object
 * Parameters:
 *   vel : velocity of the object
 *   acc : acceleration acting on the object
 *   time_interval : time interval for which the acceleration is applied
 */
void velocity_updater(double *vel, double acc, double time_interval) {
    *vel += acc * time_interval;
}

/*
 * Function to update the position of the object
 * Parameters:
 *   pos : position of the object
 *   vel : velocity of the object
 *   time_interval : time interval for which the velocity is applied
 */
void position_updater(double *pos, double vel, double time_interval) {
    *pos += vel * time_interval;
}

int main() {
    double mass1, mass2, dist, time_interval, force, acc1, acc2;
    double vel1 = 0.0, vel2 = 0.0, pos1 = 0.0, pos2 = 100.0;

    printf("Enter mass of object 1 : ");
    scanf("%lf", &mass1);
    printf("Enter mass of object 2 : ");
    scanf("%lf", &mass2);
    printf("Enter distance between the two objects : ");
    scanf("%lf", &dist);
    printf("Enter time interval : ");
    scanf("%lf", &time_interval);

    // Simulation loop
    while (1) {
        // Calculate force between the two objects
        force = force_calculator(mass1, mass2, dist);

        // Calculate acceleration of object 1 and object 2
        acc1 = acceleration_calculator(mass1, force);
        acc2 = acceleration_calculator(mass2, force);

        // Update velocity and position of object 1 and object 2
        velocity_updater(&vel1, acc1, time_interval);
        position_updater(&pos1, vel1, time_interval);
        velocity_updater(&vel2, acc2, time_interval);
        position_updater(&pos2, vel2, time_interval);

        // Print the positions of the two objects
        printf("Position of object 1 : %lf\n", pos1);
        printf("Position of object 2 : %lf\n", pos2);

        // Check if the objects have collided
        if (fabs(pos1 - pos2) < 1.0) {
            printf("Objects have collided!\n");
            break;
        }
    }

    return 0;
}