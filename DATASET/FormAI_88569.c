//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXLANES 4
#define SPEEDLIMIT 50
#define DISTANCEBETWEENVEHICLES 10
#define CARLENGTH 4

typedef struct Vehicle
{
    int position;   //in meters
    int speed;      //in meters per second
    int lane;       //leftmost lane is 0
    bool direction; //true for right, false for left
    bool active;    //true if vehicle is currently on the road
} Vehicle;

typedef struct Lane
{
    Vehicle *vehicles;
    int num_vehicles;
    int max_vehicles;
} Lane;

void initialize_lanes(Lane lanes[MAXLANES], int max_vehicles)
{
    for (int i = 0; i < MAXLANES; ++i)
    {
        lanes[i].vehicles = (Vehicle *)malloc(max_vehicles * sizeof(Vehicle));
        lanes[i].num_vehicles = 0;
        lanes[i].max_vehicles = max_vehicles;
    }
}

void add_vehicle(Lane *lane, int position, int speed, int lane_num, bool direction)
{
    if (lane->num_vehicles < lane->max_vehicles)
    {
        Vehicle new_vehicle = {position, speed, lane_num, direction, true};
        lane->vehicles[lane->num_vehicles++] = new_vehicle;
    }
}

void simulate_traffic(Lane lanes[MAXLANES], int length)
{
    int time_elapsed = 0;
    srand(time(NULL));
    while (time_elapsed < 3600) //simulate for 1 hour
    {
        //Update vehicles positions
        for (int i = 0; i < MAXLANES; ++i)
        {
            for (int j = 0; j < lanes[i].num_vehicles; ++j)
            {
                if (lanes[i].vehicles[j].active)
                {
                    //Calculate new position
                    int new_pos = lanes[i].vehicles[j].position + lanes[i].vehicles[j].speed;
                    if (new_pos >= length || new_pos < 0)
                    {
                        lanes[i].vehicles[j].active = false; //remove vehicle if it goes off the road
                    }
                    else
                    {
                        //Check distance with vehicles in front
                        bool collision = false;
                        for (int k = 0; k < lanes[i].num_vehicles; ++k)
                        {
                            if (j != k && lanes[i].vehicles[k].active && lanes[i].vehicles[k].position >= new_pos - DISTANCEBETWEENVEHICLES &&
                                lanes[i].vehicles[k].position < lanes[i].vehicles[j].position) //checking for cars in front
                            {
                                collision = true;
                                break;
                            }
                        }
                        if (!collision) //if no collision, update position
                        {
                            lanes[i].vehicles[j].position = new_pos;
                        }
                        else //if collision, update speed randomly
                        {
                            //reduce speed randomly to simulate traffic
                            int rand_speed = rand() % (SPEEDLIMIT - 1) + 1;
                            lanes[i].vehicles[j].speed = rand_speed;
                        }
                    }
                }
            }
        }
        //Add new vehicles to the road
        for (int i = 0; i < MAXLANES; ++i)
        {
            if (rand() % 100 < 10) //10% chance of adding a vehicle
            {
                int speed = rand() % SPEEDLIMIT + 1;
                int pos = (i % 2) == 0 ? 0 : length; //alternating sides of the road
                int lane_num = rand() % MAXLANES;
                bool direction = (i % 2) == 0 ? true : false; //alternating directions
                add_vehicle(&lanes[i], pos, speed, lane_num, direction);
            }
        }
        ++time_elapsed;
    }
}

int main()
{
    int road_length = 10000;
    int max_vehicles = road_length / (DISTANCEBETWEENVEHICLES + CARLENGTH);
    Lane lanes[MAXLANES];
    initialize_lanes(lanes, max_vehicles);
    simulate_traffic(lanes, road_length);
    //Print results
    for (int i = 0; i < MAXLANES; ++i)
    {
        printf("Lane %d:\n", i + 1);
        for (int j = 0; j < lanes[i].num_vehicles; ++j)
        {
            if (lanes[i].vehicles[j].active)
            {
                printf("\tVehicle %d: Position=%d, Speed=%dm/s, Lane=%d, Direction=%s\n", j + 1, lanes[i].vehicles[j].position, lanes[i].vehicles[j].speed, lanes[i].vehicles[j].lane + 1, lanes[i].vehicles[j].direction ? "Right" : "Left");
            }
        }
    }
    return 0;
}