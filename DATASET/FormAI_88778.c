//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants for simulation */
#define NUM_LANES 4
#define NUM_CARS 20
#define MAX_SPEED 60
#define SIMULATION_TIME 300

/* Function prototypes */
void initialize_cars(int car_array[][NUM_LANES]);
void print_traffic(int car_array[][NUM_LANES], int time);
void update_traffic(int car_array[][NUM_LANES]);
int choose_speed(int current_speed, int car_distance, int lane_number);
int calculate_distance(int time, int current_speed);

int main()
{
    /* Seed random number generator */
    srand(time(NULL));

    /* Create an array to represent the state of traffic */
    int traffic[NUM_CARS][NUM_LANES];

    /* Initialize the state of traffic */
    initialize_cars(traffic);

    /* Run the simulation for SIMULATION_TIME seconds */
    for (int i = 0; i < SIMULATION_TIME; i++)
    {
        /* Update the state of traffic */
        update_traffic(traffic);

        /* Display the state of traffic */
        print_traffic(traffic, i);
    }

    return 0;
}

/*
 * Initializes the state of traffic by randomly placing cars on the road.
 */
void initialize_cars(int car_array[][NUM_LANES])
{
    /* Initialize all elements of the array to -1, which represents an empty space */
    for (int i = 0; i < NUM_CARS; i++)
    {
        for (int j = 0; j < NUM_LANES; j++)
        {
            car_array[i][j] = -1;
        }
    }

    /* Randomly place cars on the road */
    for (int i = 0; i < NUM_CARS; i++)
    {
        int lane = rand() % NUM_LANES;
        int position = rand() % 1000;
        car_array[i][lane] = position;
    }
}

/*
 * Prints the state of traffic at a given time.
 */
void print_traffic(int car_array[][NUM_LANES], int time)
{
    printf("Time: %d\n", time);

    for (int i = 0; i < NUM_CARS; i++)
    {
        printf("|");

        for (int j = 0; j < NUM_LANES; j++)
        {
            if (car_array[i][j] == -1)
            {
                printf("   ");
            }
            else
            {
                printf(" %d ", car_array[i][j]);
            }

            printf("|");
        }

        printf("\n");
    }

    printf("\n");
}

/*
 * Updates the state of traffic by moving cars forward based on their current speed.
 */
void update_traffic(int car_array[][NUM_LANES])
{
    /* Iterate over each lane */
    for (int lane = 0; lane < NUM_LANES; lane++)
    {
        /* Sort the cars in the lane by distance from top to bottom */
        for (int i = 0; i < NUM_CARS - 1; i++)
        {
            for (int j = i + 1; j < NUM_CARS; j++)
            {
                if (car_array[i][lane] > car_array[j][lane])
                {
                    int temp = car_array[i][lane];
                    car_array[i][lane] = car_array[j][lane];
                    car_array[j][lane] = temp;
                }
            }
        }

        /* Move each car forward based on its current speed */
        for (int i = 0; i < NUM_CARS; i++)
        {
            /* Calculate the distance to the next car */
            int distance_to_next_car = -1;
            for (int j = i + 1; j < NUM_CARS; j++)
            {
                if (car_array[j][lane] != -1)
                {
                    distance_to_next_car = car_array[j][lane] - car_array[i][lane];
                    break;
                }
            }
            
            /* Choose a new speed for the car */
            int current_speed = rand() % MAX_SPEED;
            int new_speed = choose_speed(current_speed, distance_to_next_car, lane);

            /* Move the car forward based on its new speed */
            int position = car_array[i][lane];
            int new_position = calculate_distance(new_speed, current_speed) + position;

            /* Prevent the car from going off the edge of the road */
            if (new_position > 1000)
            {
                new_position = 1000;
            }

            /* Update the position of the car */
            car_array[i][lane] = new_position;
        }
    }
}

/*
 * Chooses a new speed for a car based on the distance to the next car and the lane number.
 */
int choose_speed(int current_speed, int car_distance, int lane_number)
{
    /* Determine the maximum speed for the lane */
    int lane_max_speed;
    if (lane_number == 0 || lane_number == NUM_LANES - 1)
    {
        lane_max_speed = MAX_SPEED / 2;
    }
    else
    {
        lane_max_speed = MAX_SPEED;
    }

    /* Calculate the ideal stopping distance */
    int stopping_distance = ((current_speed * current_speed) / (2 * MAX_SPEED)) + 10;

    /* If there is no car in front of us, accelerate up to the maximum speed for the lane */
    if (car_distance == -1)
    {
        return current_speed + (rand() % (lane_max_speed - current_speed));
    }
    /* If we are too close to the car in front of us, slow down */
    else if (car_distance <= stopping_distance)
    {
        return current_speed - ((stopping_distance - car_distance) / 2);
    }
    /* If we are not too close to the car in front of us, maintain our current speed or speed up slightly */
    else
    {
        return current_speed + (rand() % 5);
    }
}

/*
 * Calculates the distance travelled based on the current speed and the time interval.
 */
int calculate_distance(int time, int current_speed)
{
    return (current_speed * time) / 10;
}