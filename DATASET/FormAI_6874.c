//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 3
#define MAX_CARS 10

int main()
{
    int lanes[NUM_LANES][MAX_CARS]; // Holds current car positions
    int lengths[NUM_LANES]; // Holds lane lengths
    int speeds[MAX_CARS]; // Holds the speed of each car
    int num_cars = 0; // Number of cars on the road
    int max_pos = 0; // Most advanced car position
    int max_speed = 0; // Max speed of cars on road
    int tick = 0; // Simulation time
    int i, j;

    // Set random seed
    srand(time(NULL));

    // Initialize lanes and speeds
    for(i = 0; i < NUM_LANES; i++)
    {
        lengths[i] = rand() % 10 + 10; // Random lane length between 10 and 19
        for(j = 0; j < MAX_CARS; j++)
        {
            lanes[i][j] = -1; // Initialize all positions to empty
            speeds[j] = rand() % 4 + 1; // Random speed between 1 and 4
        }
    }

    // Main simulation loop
    while(num_cars < MAX_CARS && tick < 1000)
    {
        // Move cars
        for(i = 0; i < NUM_LANES; i++)
        {
            for(j = 0; j < lengths[i]; j++)
            {
                int car_pos = lanes[i][j];
                if(car_pos >= 0)
                {
                    int next_pos = car_pos + speeds[car_pos];
                    if(next_pos >= lengths[i])
                    {
                        // Car is at end of lane
                        lanes[i][j] = -1;
                        num_cars--;
                    }
                    else if(lanes[i][next_pos] >= 0)
                    {
                        // Car is blocked
                        speeds[car_pos] = speeds[lanes[i][next_pos]];
                    }
                    else
                    {
                        // Move car forward
                        lanes[i][next_pos] = car_pos;
                        lanes[i][car_pos] = -1;
                    }
                }
            }
        }

        // Add new car
        if(rand() % 5 == 0 && num_cars < MAX_CARS)
        {
            int lane = rand() % NUM_LANES;
            if(lanes[lane][0] == -1)
            {
                // Add new car to empty lane position
                lanes[lane][0] = num_cars;
                speeds[num_cars] = rand() % 4 + 1;
                num_cars++;
            }
        }

        // Print current state
        printf("Tick %d:\n", tick);
        for(i = 0; i < NUM_LANES; i++)
        {
            printf("Lane %d: ", i);
            for(j = 0; j < lengths[i]; j++)
            {
                if(lanes[i][j] >= 0)
                {
                    printf("%d ", lanes[i][j]);
                    if(j > max_pos)
                    {
                        max_pos = j;
                        max_speed = speeds[lanes[i][j]];
                    }
                }
                else
                {
                    printf(". ");
                }
            }
            printf("\n");
        }
        printf("\n");

        // Check for end state
        if(max_pos >= lengths[0] - 1 && max_speed == 1)
        {
            printf("Car has reached destination!\n");
            break;
        }

        // Increment simulation time
        tick++;
    }

    printf("Simulation finished.\n");

    return 0;
}