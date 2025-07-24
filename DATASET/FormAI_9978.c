//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 10 // Length of the road (number of cells)
#define CAR_DENSITY 0.4 // Density of cars on the road (in percentage)
#define MAX_SPEED 5 // Maximum speed allowed on the road
#define BRAKING_PROBABILITY 0.5 // Probability of a car randomly slowing down
#define SIMULATION_TIME 100 // Total number of time steps in the simulation
#define TIME_STEP_DELAY 500 // Delay (in ms) between each time step

void print_road(int road[])
{
    for (int i = 0; i < ROAD_LENGTH; i++)
    {
        if (road[i] == -1)
        {
            printf("_ ");
        }
        else
        {
            printf("%d ", road[i]);
        }
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    int road[ROAD_LENGTH]; // Initialize the road
    for (int i = 0; i < ROAD_LENGTH; i++)
    {
        road[i] = -1; // Empty cell
    }

    // Add initial cars to the road
    int num_cars = ROAD_LENGTH * CAR_DENSITY;
    int car_speeds[num_cars];
    for (int i = 0; i < num_cars; i++)
    {
        road[i] = i;
        car_speeds[i] = rand() % MAX_SPEED + 1;
    }

    // Run the simulation for SIMULATION_TIME time steps
    for (int t = 0; t < SIMULATION_TIME; t++)
    {
        // Update the speed and position of each car
        for (int i = 0; i < num_cars; i++)
        {
            // Calculate the distance to the next car
            int next_car_pos = -1;
            for (int j = i + 1; j < ROAD_LENGTH; j++)
            {
                if (road[j] != -1)
                {
                    next_car_pos = j;
                    break;
                }
            }
            int distance = next_car_pos - i - 1;

            // Accelerate until maximum speed is reached
            if (car_speeds[i] < MAX_SPEED && distance > car_speeds[i])
            {
                car_speeds[i]++;
            }

            // Randomly slow down
            if (car_speeds[i] > 0 && ((double)rand() / RAND_MAX) < BRAKING_PROBABILITY)
            {
                car_speeds[i]--;
            }

            // Move the car forward
            if (i + car_speeds[i] < ROAD_LENGTH)
            {
                road[i + car_speeds[i]] = road[i];
                road[i] = -1;
            }
            else
            {
                road[i] = -1;
            }
        }

        // Print the current state of the road
        printf("Time step %d:\n", t);
        print_road(road);

        // Delay before the next time step
        usleep(TIME_STEP_DELAY * 1000);
    }

    return 0;
}