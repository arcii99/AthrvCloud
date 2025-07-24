//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int north_cars = 0, south_cars = 0, east_cars = 0, west_cars = 0, traffic_light = 0, time_remaining = 0, feature;

    srand(time(NULL));

    for(int i = 0; i < 60; i++)
    {
        feature = rand() % 3;
        switch(feature)
        {
            case 0:
                north_cars++;
            break;

            case 1:
                east_cars++;
            break;

            case 2:
                south_cars++;
            break;

            case 3:
                west_cars++;
            break;
        }

        if(time_remaining == 0)
        {
            traffic_light = rand() % 2;
            if(traffic_light == 0)
            {
                time_remaining = 30;
            }
            else
            {
                time_remaining = 45;
            }
        }

        printf("Time Remaining: %d\n", time_remaining);
        printf("Number of cars waiting at North: %d\n", north_cars);
        printf("Number of cars waiting at East: %d\n", east_cars);
        printf("Number of cars waiting at South: %d\n", south_cars);
        printf("Number of cars waiting at West: %d\n", west_cars);

        time_remaining--;

        if(time_remaining == 0)
        {
            if(traffic_light == 0)
            {
                printf("North-South Road green light.\n");
                printf("East-West Road red light.\n");
                if(north_cars > 5)
                {
                    printf("5 cars allowed through at North.\n");
                    north_cars = north_cars - 5;
                }
                else
                {
                    printf("%d cars allowed through at North.\n", north_cars);
                    north_cars = 0;
                }

                if(south_cars > 5)
                {
                    printf("5 cars allowed through at South.\n");
                    south_cars = south_cars - 5;
                }
                else
                {
                    printf("%d cars allowed through at South.\n", south_cars);
                    south_cars = 0;
                }
            }
            else
            {
                printf("East-West Road green light.\n");
                printf("North-South Road red light.\n");
                if(east_cars > 5)
                {
                    printf("5 cars allowed through at East.\n");
                    east_cars = east_cars - 5;
                }
                else
                {
                    printf("%d cars allowed through at East.\n", east_cars);
                    east_cars = 0;
                }

                if(west_cars > 5)
                {
                    printf("5 cars allowed through at West.\n");
                    west_cars = west_cars - 5;
                }
                else
                {
                    printf("%d cars allowed through at West.\n", west_cars);
                    west_cars = 0;
                }
            }
        }
    }

    return 0;
}