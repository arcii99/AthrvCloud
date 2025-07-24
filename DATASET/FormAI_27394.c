//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAR_SPEED 60 // Maximum car speed in km/h
#define CAR_LENGTH 5 // Length of each car in metres
#define MAX_ROAD_LENGTH 100 // Maximum length of the road in metres

int main()
{
    srand(time(NULL)); // Seed the random number generator

    // Generate random road length between 50 and MAX_ROAD_LENGTH
    int road_length = rand() % (MAX_ROAD_LENGTH - 50 + 1) + 50;

    int num_cars = road_length / 10; // Number of cars based on road length
    int car_speeds[num_cars]; // Array to store speeds of each car
    int car_positions[num_cars]; // Array to store positions of each car
    int time_elapsed = 0; // Time elapsed in seconds

    // Set initial positions and speeds of cars
    for (int i = 0; i < num_cars; i++)
    {
        car_speeds[i] = rand() % (MAX_CAR_SPEED - 10 + 1) + 10;
        car_positions[i] = i * 10;
    }

    printf("Initial state of the road:\n");
    for (int i = 0; i < num_cars; i++)
    {
        printf("Car %d is at position %d with speed %d km/h\n", i+1, car_positions[i], car_speeds[i]);
    }
    printf("\n");

    while (1) // Loop indefinitely to simulate traffic flow
    {
        time_elapsed++;

        // Move each car based on its speed
        for (int i = 0; i < num_cars; i++)
        {
            car_positions[i] += (car_speeds[i] * 1000 / 3600); // Calculate distance travelled in metres

            // Collision check
            if (i > 0 && car_positions[i] < car_positions[i-1] + CAR_LENGTH)
            {
                car_positions[i] = car_positions[i-1] + CAR_LENGTH; // If collision, set position to end of previous car
            }
        }

        // Update speeds based on distance to next car
        for (int i = 0; i < num_cars; i++)
        {
            int distance_to_next_car = road_length; // Initialise to maximum distance
            if (i < num_cars - 1)
            {
                distance_to_next_car = car_positions[i+1] - car_positions[i] - CAR_LENGTH;
            }

            int max_speed = distance_to_next_car * 3600 / 1000; // Calculate maximum speed to avoid collision
            if (max_speed < car_speeds[i])
            {
                car_speeds[i]--; // Slow down if necessary
            }
            else if (max_speed > car_speeds[i])
            {
                car_speeds[i]++; // Speed up if possible
            }
        }

        // Print current state of the road every 5 seconds
        if (time_elapsed % 5 == 0)
        {
            printf("Time elapsed: %d seconds\n", time_elapsed);
            for (int i = 0; i < num_cars; i++)
            {
                printf("Car %d is at position %d with speed %d km/h\n", i+1, car_positions[i], car_speeds[i]);
            }
            printf("\n");
        }

        // Check if all cars have reached the end of the road
        if (car_positions[num_cars-1] >= road_length)
        {
            printf("All cars have reached the end of the road in %d seconds\n", time_elapsed);
            break; // Exit loop
        }
    }

    return 0;
}