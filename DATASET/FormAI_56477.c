//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

#define EAST 0
#define WEST 1
#define NORTH 2
#define SOUTH 3

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define RED 0
#define YELLOW 1
#define GREEN 2

#define MAX_TIME 1000

int traffic_Light_State_EW = RED;
int traffic_Light_State_NS = GREEN;

int prev_One, prev_Two, prev_Three, prev_Four;

int current_Time;
int vehicles_Passed_EW, vehicles_Passed_NS;

int direction; // 0-East, 1-West, 2-North, 3-South

int random_number(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void east_west_cars()
{
    int west_To_east = random_number(0, 1);
    int cars = random_number(0, 10);

    if(west_To_east == 1)
    {
        printf("West to East: %d cars\n", cars);
        for(int i=0; i<cars; i++)
        {
            printf("Car %d from West is waiting to cross the intersection.\n", i+1);
            while(current_Time-prev_One<=35)
            {
                current_Time++;
            }
            printf("Car %d from West has passed the intersection.\n", i+1);
            prev_One=current_Time;
            vehicles_Passed_EW++;
        }
        printf("\n");
    }
    else
    {
        printf("East to West: %d cars\n", cars);
        for(int i=0; i<cars; i++)
        {
            printf("Car %d from East is waiting to cross the intersection.\n", i+1);
            while(current_Time-prev_Two<=35)
            {
                current_Time++;
            }
            printf("Car %d from East has passed the intersection.\n", i+1);
            prev_Two=current_Time;
            vehicles_Passed_EW++;
        }
        printf("\n");
    }
}

void north_south_cars()
{
    int south_To_north = random_number(0, 1);
    int cars = random_number(0, 10);

    if(south_To_north == 1)
    {
        printf("South to North: %d cars\n", cars);
        for(int i=0; i<cars; i++)
        {
            printf("Car %d from South is waiting to cross the intersection.\n", i+1);
            while(current_Time-prev_Three<=35)
            {
                current_Time++;
            }
            printf("Car %d from South has passed the intersection.\n", i+1);
            prev_Three=current_Time;
            vehicles_Passed_NS++;
        }
        printf("\n");
    }
    else
    {
        printf("North to South: %d cars\n", cars);
        for(int i=0; i<cars; i++)
        {
            printf("Car %d from North is waiting to cross the intersection.\n", i+1);
            while(current_Time-prev_Four<=35)
            {
                current_Time++;
            }
            printf("Car %d from North has passed the intersection.\n", i+1);
            prev_Four=current_Time;
            vehicles_Passed_NS++;
        }
        printf("\n");
    }
}

void set_traffic_light_state_EW()
{
    if(traffic_Light_State_EW == RED)
    {
        traffic_Light_State_EW = GREEN;
        printf("\nTraffic Light is green for East-West direction\n");
    }
    else if(traffic_Light_State_EW == GREEN)
    {
        traffic_Light_State_EW = YELLOW;
        printf("\nTraffic Light is yellow for East-West direction\n");
    }
    else if(traffic_Light_State_EW == YELLOW)
    {
        traffic_Light_State_EW = RED;
        printf("\nTraffic Light is red for East-West direction\n");
        vehicles_Passed_EW = 0;
    }
}

void set_traffic_light_state_NS()
{
    if(traffic_Light_State_NS == RED)
    {
        traffic_Light_State_NS = GREEN;
        printf("\nTraffic Light is green for North-South direction\n");
    }
    else if(traffic_Light_State_NS == GREEN)
    {
        traffic_Light_State_NS = YELLOW;
        printf("\nTraffic Light is yellow for North-South direction\n");
    }
    else if(traffic_Light_State_NS == YELLOW)
    {
        traffic_Light_State_NS = RED;
        printf("\nTraffic Light is red for North-South direction\n");
        vehicles_Passed_NS = 0;
    }
}

int main()
{
    srand(42);

    while(current_Time <= MAX_TIME)
    {
        printf("\n\nTime: %d sec \n", current_Time);

        if(direction == EAST || direction == WEST)
        {
            if(traffic_Light_State_EW == GREEN && vehicles_Passed_EW < 15)
            {
                if(direction == EAST)
                {
                    east_west_cars();
                }
                else if (direction == WEST)
                {
                    east_west_cars();
                }
            }
            else if(traffic_Light_State_EW == YELLOW)
            {
                printf("Traffic Light is yellow for East-West direction\n");
                direction = NORTH;
            }
            else
            {
                printf("Traffic Light is red for East-West direction\n");
                set_traffic_light_state_EW();
                direction = NORTH;
            }
        }

        if(direction == NORTH || direction == SOUTH)
        {
            if(traffic_Light_State_NS == GREEN && vehicles_Passed_NS < 15)
            {
                if(direction == NORTH)
                {
                    north_south_cars();
                }
                else if (direction == SOUTH)
                {
                    north_south_cars();
                }
            }
            else if(traffic_Light_State_NS == YELLOW)
            {
                printf("Traffic Light is yellow for North-South direction\n");
                direction = EAST;
            }
            else
            {
                printf("Traffic Light is red for North-South direction\n");
                set_traffic_light_state_NS();
                direction = EAST;
            }
        }

        current_Time++;

    }

    return 0;
}