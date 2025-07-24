//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_ROADS 10
#define MAX_VEHICLES 100

int roads[MAX_ROADS][2];
int vehicles[MAX_VEHICLES][2];

void initialize_roads(int num_roads)
{
    int i;
    for(i = 0; i < num_roads; i++)
    {
        roads[i][0] = rand()%1000;
        roads[i][1] = rand()%1000;
    }
}

void initialize_vehicles(int num_vehicles)
{
    int i;
    for(i = 0; i < num_vehicles; i++)
    {
        vehicles[i][0] = rand()%1000;
        vehicles[i][1] = rand()%1000;
    }
}

void drive_vehicles(int num_vehicles)
{
    int i;
    for(i = 0; i < num_vehicles; i++)
    {
        int curr_pos = vehicles[i][0];
        int speed = rand()%5;
        int distance = speed;
        int j;
        for(j = 0; j < MAX_ROADS; j++)
        {
            if(curr_pos > roads[j][0] && curr_pos < roads[j][1])
            {
                int road_distance = roads[j][1] - curr_pos;
                if(road_distance < speed)
                {
                    distance = road_distance;
                }
            }
        }
        curr_pos += distance;
        vehicles[i][0] = curr_pos;
    }
}

void print_status(int num_vehicles)
{
    int i;
    for(i = 0; i < num_vehicles; i++)
    {
        int j;
        for(j = 0; j < MAX_ROADS; j++)
        {
            if(vehicles[i][0] > roads[j][0] && vehicles[i][0] < roads[j][1])
            {
                printf("Vehicle %d is on road %d at position %d\n", i+1, j+1, vehicles[i][0]-roads[j][0]);
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int num_roads = 5;
    int num_vehicles = 10;
    initialize_roads(num_roads);
    initialize_vehicles(num_vehicles);
    int i;
    for(i = 0; i < 10; i++)
    {
        printf("Iteration %d\n", i+1);
        drive_vehicles(num_vehicles);
        print_status(num_vehicles);
        printf("\n");
    }
    return 0;
}