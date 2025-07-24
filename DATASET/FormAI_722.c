//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 50 // Maximum speed of a car in km/h
#define MAX_DISTANCE 1000 // Maximum distance between two cars in meters
#define SIMULATION_TIME 3600 // Total simulation time in seconds
#define CAR_LENGTH 5 // Length of a car in meters
#define SAFE_DISTANCE MULTIPLIER * CAR_LENGTH // Minimum safe distance between two cars
#define MULTIPLIER 2 // Multiplier for calculating safe distance
#define EXIT_ROAD 500 // Length of exit road in meters
#define LANE_WIDTH 3 // Width of a lane in meters
#define NUM_LANES 2 // Number of lanes in the road
#define MAX_CARS_PER_LANE 10 // Maximum number of cars allowed in a lane

// Function to generate a random number within a given range
int generate_random(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    srand(time(NULL));

    // Initialize variables
    int time_step = 0; // Time step of the simulation
    int total_cars = 0; // Total number of cars in the simulation
    int cars_on_road = 0; // Number of cars currently on the road
    int cars_arrived = 0; // Number of cars that have arrived at the exit
    float total_distance_travelled = 0; // Total distance travelled by all the cars
    float average_speed = 0; // Average speed of the cars
    int cars_per_lane[NUM_LANES]; // Array to store number of cars in each lane
    float distance_between_cars[MAX_CARS_PER_LANE * NUM_LANES]; // Array to store distance between adjacent cars in each lane

    // Initialize all elements in the arrays to zero
    for (int i = 0; i < NUM_LANES; i++)
    {
        cars_per_lane[i] = 0;
        for (int j = 0; j < MAX_CARS_PER_LANE; j++)
        {
            distance_between_cars[i * MAX_CARS_PER_LANE + j] = 0;
        }
    }

    // Simulation loop
    while (time_step < SIMULATION_TIME)
    {
        // Generate new cars at the entrance of the road
        int num_new_cars = generate_random(0, MAX_CARS_PER_LANE - cars_per_lane[0]);
        for (int i = cars_per_lane[0]; i < cars_per_lane[0] + num_new_cars; i++)
        {
            distance_between_cars[i] = generate_random(0, MAX_DISTANCE);
            cars_on_road++;
        }
        cars_per_lane[0] += num_new_cars;
        total_cars += num_new_cars;

        // Update distance between adjacent cars in the left lane
        for (int i = 0; i < cars_per_lane[0] - 1; i++)
        {
            distance_between_cars[i] -= MAX_SPEED / 3.6; // Convert km/h to m/s
        }

        // Move cars in the left lane
        int i = 0; // Index of the current car
        while (i < cars_per_lane[0])
        {
            if (distance_between_cars[i] < SAFE_DISTANCE) // Check if the current car is too close to the car in front
            {
                if (i == 0 || distance_between_cars[i - 1] > SAFE_DISTANCE) // Check if the car behind is far enough
                {
                    distance_between_cars[i] = SAFE_DISTANCE; // Adjust the distance between the cars
                }
                else
                {
                    // Slow down the current car
                    int slow_down = generate_random(0, 10);
                    if (slow_down == 0)
                    {
                        distance_between_cars[i] += 1; // Increase distance to the car in front
                    }
                }
            }
            else
            {
                // Speed up the current car
                int speed_up = generate_random(0, 9);
                if (speed_up == 0)
                {
                    distance_between_cars[i] -= 1; // Decrease distance to the car in front
                }
            }

            // Move the car forward
            distance_between_cars[i] -= MAX_SPEED / 3.6; // Convert km/h to m/s

            if (distance_between_cars[i] < -CAR_LENGTH) // Check if the car has reached the exit
            {
                cars_on_road--;
                cars_arrived++;
                total_distance_travelled += EXIT_ROAD - distance_between_cars[i];
                cars_per_lane[0]--;
                for (int j = i; j < cars_per_lane[0]; j++)
                {
                    distance_between_cars[j] = distance_between_cars[j + 1];
                }
            }
            else
            {
                i++;
            }
        }

        // Update distance between adjacent cars in the right lane
        for (int i = 0; i < cars_per_lane[1] - 1; i++)
        {
            distance_between_cars[i + MAX_CARS_PER_LANE] -= MAX_SPEED / 3.6; // Convert km/h to m/s
        }

        // Move cars in the right lane
        i = MAX_CARS_PER_LANE; // Index of the current car
        while (i < MAX_CARS_PER_LANE + cars_per_lane[1])
        {
            if (distance_between_cars[i] < SAFE_DISTANCE) // Check if the current car is too close to the car in front
            {
                if (i == MAX_CARS_PER_LANE || distance_between_cars[i - 1] > SAFE_DISTANCE) // Check if the car behind is far enough
                {
                    distance_between_cars[i] = SAFE_DISTANCE; // Adjust the distance between the cars
                }
                else
                {
                    // Slow down the current car
                    int slow_down = generate_random(0, 10);
                    if (slow_down == 0)
                    {
                        distance_between_cars[i] += 1; // Increase distance to the car in front
                    }
                }
            }
            else
            {
                // Speed up the current car
                int speed_up = generate_random(0, 9);
                if (speed_up == 0)
                {
                    distance_between_cars[i] -= 1; // Decrease distance to the car in front
                }
            }

            // Move the car forward
            distance_between_cars[i] -= MAX_SPEED / 3.6; // Convert km/h to m/s

            if (distance_between_cars[i] < -CAR_LENGTH) // Check if the car has reached the exit
            {
                cars_on_road--;
                cars_arrived++;
                total_distance_travelled += EXIT_ROAD - distance_between_cars[i];
                cars_per_lane[1]--;
                for (int j = i; j < cars_per_lane[1]; j++)
                {
                    distance_between_cars[j + MAX_CARS_PER_LANE] = distance_between_cars[j + MAX_CARS_PER_LANE + 1];
                }
            }
            else
            {
                i++;
            }
        }

        // Print the status of the simulation every 60 seconds
        if (time_step % 60 == 0)
        {
            average_speed = total_distance_travelled / ((total_cars - cars_on_road) * SIMULATION_TIME / 3600.0);
            printf("===========================\n");
            printf("Time step: %d seconds\n", time_step);
            printf("Number of cars on the road: %d\n", cars_on_road);
            printf("Number of cars arrived: %d\n", cars_arrived);
            printf("Average speed of the cars: %.1f km/h\n", average_speed);
            printf("Number of cars in each lane: %d, %d\n", cars_per_lane[0], cars_per_lane[1]);
            printf("===========================\n");
        }

        time_step++;
    }

    return 0;
}