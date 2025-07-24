//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARS 50 //max number of cars
#define MAX_SPEED 5 //max speed of cars
#define CAR_SPACING 10 //spacing between cars
#define CAR_LENGTH 4 //length of each car
#define ROAD_LENGTH 100 //length of the road

void printRoad(char road[ROAD_LENGTH]);
void setCars(char* road, int numCars, int *carPositions, int *carSpeeds);

int main()
{
    char road[ROAD_LENGTH];
    int numCars = rand() % (MAX_CARS + 1); //generate random number of cars between 0 and MAX_CARS
    int carPositions[numCars]; //array to store car positions
    int carSpeeds[numCars]; //array to store car speeds

    //initialize random number generator
    srand(time(NULL));

    //set cars positions and speeds
    setCars(road, numCars, carPositions, carSpeeds);

    //simulate traffic
    for(int i=0; i<100; i++)
    {
        printRoad(road);

        //update positions of cars
        for(int j=0; j<numCars; j++)
        {
            carPositions[j] += carSpeeds[j];
            if(carPositions[j] >= ROAD_LENGTH)
                carPositions[j] = 0;
        }

        //update road with new car positions
        for(int j=0; j<numCars; j++)
        {
            for(int k=0; k<CAR_LENGTH; k++)
            {
                int pos = carPositions[j] + k;
                if(pos >= ROAD_LENGTH)
                    pos -= ROAD_LENGTH;
                road[pos] = 'X';
            }
        }

        //wait for a bit before updating again
        usleep(100000);
    }

    return 0;
}

void printRoad(char road[ROAD_LENGTH])
{
    for(int i=0; i<ROAD_LENGTH; i++)
        printf("%c", road[i]);
    printf("\n");
}

void setCars(char* road, int numCars, int *carPositions, int *carSpeeds)
{
    //initialize road
    for(int i=0; i<ROAD_LENGTH; i++)
        road[i] = '-';

    //set car positions and speeds
    for(int i=0; i<numCars; i++)
    {
        int pos = i * CAR_SPACING;
        carPositions[i] = pos;
        carSpeeds[i] = rand() % MAX_SPEED + 1;

        //put car on road
        for(int j=0; j<CAR_LENGTH; j++)
        {
            int roadPos = pos + j;
            if(roadPos >= ROAD_LENGTH)
                roadPos -= ROAD_LENGTH;
            road[roadPos] = 'X';
        }
    }
}