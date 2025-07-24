//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROAD_CAPACITY 20
#define TRAFFIC_DENSITY 0.7
#define MAX_WAITING_TIME 3

int main()
{
    srand(time(NULL));

    int road[ROAD_CAPACITY];
    int cars_on_road = 0;
    int car_count = 0;
    int time = 0;

    printf("Traffic Flow Simulation Program\n\n");

    while(1)
    {
        time++;
        printf("\nTime: %d\n", time);

        // Add new cars to the road
        if(((float)rand() / RAND_MAX) < TRAFFIC_DENSITY)
        {
            if(cars_on_road == ROAD_CAPACITY)
            {
                printf("Traffic jam! No space for new car.\n");
            }
            else
            {
                road[cars_on_road++] = ++car_count;
                printf("Car %d added to the road.\n", car_count);
            }
        }

        // Move cars forward
        for(int i = 0; i < cars_on_road; i++)
        {
            road[i]--;

            if(road[i] == 0)
            {
                printf("Car %d has reached the end of the road.\n", i+1);
            }
            else if(i > 0 && road[i-1] > 0 && (float)rand() / RAND_MAX < 0.5)
            {
                printf("Car %d is waiting for car %d to move.\n", i+1, i);
                if(road[i] < MAX_WAITING_TIME)
                {
                    road[i]++;
                }
            }
            else
            {
                road[i]++;
            }
        }

        // Remove cars that have reached the end of the road
        int index = 0;
        while(index < cars_on_road)
        {
            if(road[index] == 0)
            {
                printf("Car %d has left the road.\n", index+1);
                cars_on_road--;
                for(int j = index; j < cars_on_road; j++)
                {
                    road[j] = road[j+1];
                }
            }
            else
            {
                index++;
            }
        }

        if(cars_on_road == 0)
        {
            printf("\nNo more cars on the road. Simulation over!\n");
            break;
        }
    }

    return 0;
}