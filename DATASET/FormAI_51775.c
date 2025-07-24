//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

/* Defining the max distance for the vehicle */
#define MAX_DISTANCE 100

/* Defining the max speed for the vehicle */
#define MAX_SPEED 20

/* Defining the simulation time for the vehicle */
#define SIMULATION_TIME 10

/* Defining the structure for the remote control vehicle */
typedef struct
{
    float distance; /* Distance traveled by the vehicle */
    float speed; /* Speed of the vehicle */
}rc_vehicle_t;

/* Function to simulate the remote control vehicle */
void simulate_vehicle(rc_vehicle_t *vehicle)
{
    /* Initializing the variables for the simulation */
    float time = 0.0;
    float acceleration = 2.0;

    /* Loop for simulating the vehicle */
    while(time < SIMULATION_TIME)
    {
        /* Calculate the new speed of the vehicle */
        vehicle->speed += acceleration;

        /* Limiting the speed of the vehicle */
        if(vehicle->speed > MAX_SPEED)
        {
            vehicle->speed = MAX_SPEED;
        }

        /* Calculate the new distance traveled by the vehicle */
        vehicle->distance += vehicle->speed;

        /* Limiting the distance traveled by the vehicle */
        if(vehicle->distance > MAX_DISTANCE)
        {
            vehicle->distance = MAX_DISTANCE;
        }

        /* Printing the status of the vehicle */
        printf("Time: %.2f seconds, Speed: %.2f m/s, Distance Traveled: %.2f meters\n", time, vehicle->speed, vehicle->distance);

        /* Updating the time for the simulation */
        time += 1.0;
    }
}

/* Main function */
int main()
{
    /* Creating a remote control vehicle object */
    rc_vehicle_t vehicle = {0.0, 0.0};

    /* Simulating the remote control vehicle */
    simulate_vehicle(&vehicle);

    /* Exiting the program */
    return 0;
}