//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_CARS 1000
#define MAX_TIME 100
#define MAX_SPEED 60 // in km/h

// Define struct for car
typedef struct Car
{
    int speed;
    int position;
} Car;

// Function to initialize a car
void init_car(Car *car)
{
    car->speed = rand() % MAX_SPEED + 1;
    car->position = 0;
}

// Function to update position of a car
void update_car_position(Car *car, int time_interval)
{
    car->position += time_interval * car->speed / 3600; // distance = speed * time
}

// Function to check if two cars collide
int check_collision(Car *car1, Car *car2, int time_interval)
{
    int distance_between_cars = car2->position - car1->position;
    int distance_covered_by_car1 = time_interval * car1->speed / 3600;
    int distance_covered_by_car2 = time_interval * car2->speed / 3600;

    if (distance_between_cars < distance_covered_by_car1 + distance_covered_by_car2)
    {
        return 1; // collision detected
    }

    return 0; // no collision
}

int main()
{
    srand(time(NULL)); // seed random number generator

    Car cars[MAX_CARS]; // initialize array for cars

    for (int i = 0; i < MAX_CARS; i++)
    {
        init_car(&cars[i]); // initialize each car in the array
    }

    for (int t = 0; t < MAX_TIME; t++)
    {
        for (int i = 0; i < MAX_CARS; i++)
        {
            update_car_position(&cars[i], 1); // update position of each car
        }

        for (int i = 0; i < MAX_CARS - 1; i++)
        {
            for (int j = i + 1; j < MAX_CARS; j++)
            {
                if (check_collision(&cars[i], &cars[j], 1)) // check for collision between two cars
                {
                    printf("Collision detected at time %d between car %d and car %d\n", t, i, j);
                    return 0; // end program if collision detected
                }
            }
        }
    }

    printf("No collision detected\n"); // print message if no collision detected
    return 0;
}