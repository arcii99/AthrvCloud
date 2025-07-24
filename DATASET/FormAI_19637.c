//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 6

int main()
{
    int road[10][20] = {0};
    int cars[MAX_CARS] = {0};
    int car_speeds[MAX_CARS] = {0};
    int num_cars = 0;

    srand(time(NULL));

    // randomly add cars to the road
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (rand() % 5 == 0)
            {
                cars[num_cars] = i * 20 + j;
                car_speeds[num_cars] = rand() % MAX_SPEED + 1;
                num_cars++;
            }
        }
    }

    // main simulation loop
    int ticks = 0;
    while (ticks < 100)
    {
        // update car positions
        for (int i = 0; i < num_cars; i++)
        {
            int car_pos = cars[i];
            int car_speed = car_speeds[i];

            int new_pos = car_pos + car_speed;

            if (new_pos >= 200)
            {
                new_pos -= 200;
            }

            if (road[new_pos % 10][new_pos / 10] == 0)
            {
                road[car_pos % 10][car_pos / 10] = 0;
                road[new_pos % 10][new_pos / 10] = 1;
                cars[i] = new_pos;
            }
            else
            {
                car_speeds[i] = 0;
            }
        }

        // print the road
        printf("tick %d:\n", ticks);
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (road[i][j] == 1)
                {
                    printf("X");
                }
                else
                {
                    printf("_");
                }
            }
            printf("\n");
        }

        ticks++;
    }

    return 0;
}