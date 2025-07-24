//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LANE_LENGTH 10
#define MAX_LANE_SPEED_LIMIT 50
#define MAX_CAR_SPEED 60
#define MIN_CAR_SPEED 20
#define MAX_CARS 5
#define MAX_SIMULATION_TIME 60 // seconds
#define TICK_LENGTH 1 // seconds

// a struct to hold information about a car in the simulation
typedef struct Car
{
    int position; // current position on the lane
    int speed; // current speed of the car
} Car;

// a struct to hold information about a lane in the simulation
typedef struct Lane
{
    Car cars[MAX_CARS]; // array of cars on the lane
    int speed_limit; // the maximum speed allowed on the lane
    int length; // the length of the lane
    int num_cars; // the number of cars currently on the lane
} Lane;

// a function to initialize a lane with random values
void init_lane(Lane *lane)
{
    lane->length = rand() % MAX_LANE_LENGTH + 1;
    lane->speed_limit = rand() % MAX_LANE_SPEED_LIMIT + 1;
    lane->num_cars = rand() % MAX_CARS;
    for (int i = 0; i < lane->num_cars; i++)
    {
        lane->cars[i].position = rand() % lane->length;
        lane->cars[i].speed = rand() % (MAX_CAR_SPEED - MIN_CAR_SPEED) + MIN_CAR_SPEED;
    }
}

// a function to update the positions of all cars on a lane
void update_cars(Lane *lane)
{
    // update positions of all cars
    for (int i = 0; i < lane->num_cars; i++)
    {
        Car *car = &lane->cars[i];
        car->position += car->speed;
    }
    // remove cars that have gone past the end of the lane
    for (int i = 0; i < lane->num_cars; i++)
    {
        Car *car = &lane->cars[i];
        if (car->position >= lane->length)
        {
            lane->num_cars--;
            for (int j = i; j < lane->num_cars; j++)
            {
                lane->cars[j] = lane->cars[j+1];
            }
            i--; // recheck current position since array shifted left
        }
    }
}

// a function to move a car forward or backward in the lane depending on traffic conditions
void move_car(Lane *lane, Car *car)
{
    // check if there is a car in front of this one
    int next_position = car->position + car->speed;
    for (int i = 0; i < lane->num_cars; i++)
    {
        Car *next_car = &lane->cars[i];
        if (next_car->position > car->position && next_car->position <= next_position)
        {
            car->speed = next_car->speed;
            car->position = next_car->position - 1;
            return;
        }
    }
    // no car in front, check if current speed exceeds speed limit
    if (car->speed > lane->speed_limit)
    {
        car->speed = lane->speed_limit;
    }
    car->position = next_position < lane->length ? next_position : lane->length;
}

// a function to simulate one tick of the traffic flow on a lane
void simulate_traffic(Lane *lane)
{
    // randomly add a new car to the lane
    if ((float)rand() / RAND_MAX < 0.25 && lane->num_cars < MAX_CARS)
    {
        Car new_car = {0, rand() % (MAX_CAR_SPEED - MIN_CAR_SPEED) + MIN_CAR_SPEED};
        int i;
        for (i = 0; i < lane->num_cars; i++)
        {
            if (lane->cars[i].position >= new_car.position)
            {
                break;
            }
        }
        for (int j = lane->num_cars; j > i; j--)
        {
            lane->cars[j] = lane->cars[j-1];
        }
        lane->cars[i] = new_car;
        lane->num_cars++;
    }
    // update positions of all cars on the lane
    update_cars(lane);
    // move each car forward or backward as needed
    for (int i = 0; i < lane->num_cars; i++)
    {
        move_car(lane, &lane->cars[i]);
    }
}

int main()
{
    srand(time(NULL)); // seed the random number generator

    // create a lane
    Lane lane;
    init_lane(&lane);

    // simulate the traffic flow on the lane
    for (int t = 0; t < MAX_SIMULATION_TIME; t += TICK_LENGTH)
    {
        printf("Tick %d: ", t);
        // print the positions of all cars on the lane
        for (int i = 0; i < lane.length; i++)
        {
            char c = '-';
            for (int j = 0; j < lane.num_cars; j++)
            {
                if (lane.cars[j].position == i)
                {
                    c = 'X';
                    break;
                }
            }
            printf("%c", c);
        }
        printf("\n");
        // simulate one tick of traffic flow
        simulate_traffic(&lane);
    }

    return 0;
}