//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROAD_LENGTH 100
#define MAX_SPEED 5
#define CAR_DENSITY 0.4
#define STEP_TIME 1

typedef struct Car
{
    int position;
    int speed;
    int ahead_distance;
}Car;

void initializeCars(int road[], int n, Car cars[]);
void displayRoad(int road[], int n);
void displayCars(Car cars[], int n);
void updateCarSpeeds(int road[], int n, Car cars[]);
void updateCarPositions(int road[], int n, Car cars[]);

int main()
{
    int road[ROAD_LENGTH];
    Car cars[ROAD_LENGTH];
    initializeCars(road, ROAD_LENGTH, cars);
    
    while(1)
    {
        system("cls"); // clears screen
        displayRoad(road, ROAD_LENGTH);
        displayCars(cars, ROAD_LENGTH);
        updateCarSpeeds(road, ROAD_LENGTH, cars);
        updateCarPositions(road, ROAD_LENGTH, cars);
        getchar();
    }
    
    return 0;
}

void initializeCars(int road[], int n, Car cars[])
{
    srand(time(NULL)); // seeding random number generator
    for(int i=0; i<n; i++)
    {
        road[i] = 0; // empty cell
        if((double)rand() / RAND_MAX < CAR_DENSITY) // check if cell has a car
        {
            cars[i].position = i;
            cars[i].speed = rand() % (MAX_SPEED+1); // random speed
            cars[i].ahead_distance = 0;
        }
    }
}

void displayRoad(int road[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("-");
    }
    printf("\n");
}

void displayCars(Car cars[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(cars[i].speed > 0)
        {
            for(int j=0; j<cars[i].position-cars[i].ahead_distance; j++)
            {
                printf(" ");
            }
            printf("o");
        }
    }
    printf("\n");
}

void updateCarSpeeds(int road[], int n, Car cars[])
{
    for(int i=0; i<n; i++)
    {
        if(cars[i].speed > 0)
        {
            int ahead_car = -1;
            int distance = ROAD_LENGTH; // assume no cars ahead
            for(int j=i+1; j<n; j++)
            {
                if(cars[j].speed > 0)
                {
                    if(cars[j].position - cars[i].position < distance)
                    {
                        ahead_car = j;
                        distance = cars[j].position - cars[i].position;
                    }
                    break;
                }
            }
            if(ahead_car == -1 || distance >= cars[i].speed + (cars[i].speed*(cars[i].speed+1))/2) // check if there's enough distance to increase speed
            {
                cars[i].speed++;
            }
            else
            {
                cars[i].speed = distance - cars[i].ahead_distance - 1;
            }
        }
    }
}

void updateCarPositions(int road[], int n, Car cars[])
{
    for(int i=0; i<n; i++)
    {
        if(cars[i].speed > 0)
        {
            int new_position = (cars[i].position + cars[i].speed) % ROAD_LENGTH;
            if(new_position > cars[i].position)
            {
                int distance = new_position - cars[i].position;
                int can_move = 1;
                for(int j=1; j<=distance; j++)
                {
                    if(road[(cars[i].position+j)%ROAD_LENGTH] != 0)
                    {
                        can_move = 0;
                        break;
                    }
                }
                if(can_move)
                {
                    road[cars[i].position] = 0;
                    cars[i].position = new_position;
                    cars[i].ahead_distance = 0;
                    road[cars[i].position] = 1;
                }
                else
                {
                    cars[i].ahead_distance++;
                }
            }
            else
            {
                int distance = (ROAD_LENGTH - cars[i].position) + new_position;
                int can_move = 1;
                for(int j=1; j<=distance; j++)
                {
                    if(road[(cars[i].position+j)%ROAD_LENGTH] != 0)
                    {
                        can_move = 0;
                        break;
                    }
                }
                if(can_move)
                {
                    road[cars[i].position] = 0;
                    cars[i].position = new_position;
                    cars[i].ahead_distance = 0;
                    road[cars[i].position] = 1;
                }
                else
                {
                    cars[i].ahead_distance++;
                }
            }
        }
    }
}