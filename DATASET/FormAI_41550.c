//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CARS 30     // Total number of cars on the road
#define CAR_LENGTH 5      // Length of each car, in meters
#define MIN_SPEED 20      // Minimum speed of a car, in km/h
#define MAX_SPEED 100     // Maximum speed of a car, in km/h
#define SIMULATION_TIME 60 // Length of the simulation, in seconds
#define SIMULATION_DELAY 1 // Delay between updates, in seconds

typedef struct
{
    int id;
    float position;
    float speed;
} Car;

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    Car road[TOTAL_CARS]; // Create an array to hold the cars
    
    // Initialize each car's values
    for (int i = 0; i < TOTAL_CARS; i++)
    {
        road[i].id = i + 1;
        road[i].position = (float)i * CAR_LENGTH;
        road[i].speed = (float)(rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED);
    }
    
    // Simulate the traffic flow
    for (int t = 0; t < SIMULATION_TIME; t += SIMULATION_DELAY)
    {
        printf("Time: %d s\n", t);
        
        // Update each car's position and speed
        for (int i = 0; i < TOTAL_CARS; i++)
        {
            // Calculate the distance between this car and the next car
            int next_car_index = i + 1;
            if (next_car_index >= TOTAL_CARS)
            {
                next_car_index = 0;
            }
            float distance = road[next_car_index].position - road[i].position;
            
            // Calculate the car's new speed based on the distance to the next car
            float new_speed = road[i].speed;
            if (distance < CAR_LENGTH * 2)
            {
                new_speed = distance / 2;
            }
            
            // Update the car's position and speed
            road[i].position += road[i].speed * SIMULATION_DELAY;
            road[i].speed = new_speed;
            
            // Print the car's new position and speed
            printf("Car %d position: %.2f m\n", road[i].id, road[i].position);
            printf("Car %d speed: %.2f km/h\n", road[i].id, road[i].speed);
        }
        
        // Add a delay to simulate real time
        sleep(SIMULATION_DELAY);
    }
    
    return 0;
}