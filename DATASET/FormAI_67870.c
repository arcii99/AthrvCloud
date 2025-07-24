//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_CARS 100
#define ROAD_LENGTH 200
#define MAX_SPEED 5

int cars[MAX_CARS];

void initialize_cars();
void print_state(int time);
void update_state();

int main()
{
    srand(time(0));
    
    initialize_cars();
    
    for(int time = 0; time < 100; time++)
    {
        print_state(time);
        update_state();
    }
    
    return 0;
}

void initialize_cars()
{
    for(int i = 0; i < MAX_CARS; i++)
    {
        cars[i] = -1;
    }
    
    int pos = 0;
    for(int i = 0; i < MAX_CARS; i++)
    {
        if(rand() % 2 == 0)
        {
            cars[i] = pos;
            pos += 10;
        }
    }
}

void print_state(int time)
{
    printf("Time: %d\n", time);
    
    for(int i = 0; i < ROAD_LENGTH; i++)
    {
        int car_found = 0;
        for(int j = 0; j < MAX_CARS; j++)
        {
            if(cars[j] == i)
            {
                printf("X");
                car_found = 1;
                break;
            }
        }
        if(car_found == 0)
        {
            printf(".");
        }
    }
    printf("\n\n");
}

void update_state()
{
    for(int i = 0; i < MAX_CARS; i++)
    {
        if(cars[i] == -1)
        {
            continue;
        }
        
        int speed = rand() % MAX_SPEED;
        int new_pos = cars[i] + speed;
        
        if(new_pos >= ROAD_LENGTH)
        {
            cars[i] = -1;
        }
        else
        {
            int collision_flag = 0;
            for(int j = 0; j < MAX_CARS; j++)
            {
                if(i == j || cars[j] == -1)
                {
                    continue;
                }
                
                if(cars[j] == new_pos || cars[j] == new_pos - 1 || cars[j] == new_pos + 1)
                {
                    collision_flag = 1;
                    break;
                }
            }
            
            if(collision_flag == 0)
            {
                cars[i] = new_pos;
            }
        }
    }
}