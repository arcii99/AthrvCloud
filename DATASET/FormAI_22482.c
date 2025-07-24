//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define CAR_LENGTH 5  // car length in meters
#define CAR_SPEED 60  // car speed in km/h
#define SIM_TIME 60  // simulation time in seconds
#define ROAD_LENGTH 250  // road length in meters
#define UPDATE_INTERVAL 1  // update interval in seconds

int main()
{
    srand(time(NULL));  // seed for random number generation
    int car_position = 0;  // initial car position
    
    for(int i = 0; i < SIM_TIME; i += UPDATE_INTERVAL)
    {
        int car_speed = rand() % (CAR_SPEED + 1);  // generate random speed
        car_position += car_speed * UPDATE_INTERVAL / 3600;  // update car position
        
        // check if car has reached end of road
        if(car_position >= ROAD_LENGTH)
        {
            printf("Car reached end of road at time %d seconds.\n", i);
            break;
        }
        
        // generate traffic flow visualization
        for(int j = 0; j < ROAD_LENGTH; j++)
        {
            if(j == car_position)
            {
                printf("|O");  // represent car as O
            }
            else if(j % 10 == 0)
            {
                printf("| ");  // represent road markings
            }
            else
            {
                printf(" ");  // represent empty space
            }
        }
        printf("|\n");
        
        // wait for update interval
        for(int j = 0; j < UPDATE_INTERVAL; j++)
        {
            printf("-");  // represent passage of time
            sleep(1);
        }
        printf("\n");
    }
    return 0;
}