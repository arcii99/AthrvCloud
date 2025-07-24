//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10 //number of vehicles in the simulation

struct Vehicle {
    int x; //x coordinate on the map
    int y; //y coordinate on the map 
    int speed; //speed of vehicle in units per second
};

void printVehicles(struct Vehicle v[N]){
    printf("Vehicle\tLocation\tSpeed\n");
    for(int i = 0; i < N; i++){
        printf("%d\t(%d, %d)\t%d\n", i+1, v[i].x, v[i].y, v[i].speed);
    }
}

void updateVehiclePositions(struct Vehicle v[N], int timeElapsed){
    for(int i = 0; i < N; i++){
        int distance = v[i].speed * timeElapsed;
        if(rand() % 2 == 0){
            v[i].x += distance;
        } else {
            v[i].x -= distance;
        }
        if(rand() % 2 == 0){
            v[i].y += distance;
        } else {
            v[i].y -= distance;
        }
    }
}

int main(){
    srand(time(NULL));
    struct Vehicle vehicles[N] = {
        {0,0,10},
        {0,2,20},
        {1,-2,5},
        {3,3,15},
        {2,-1,25},
        {0,5,8},
        {4,1,12},
        {2,4,16},
        {-1,-1,30},
        {5,-3,18}
    };
    int simulationTime = 60; //time to run the simulation in seconds
    int timeElapsed = 0;

    printf("Initial vehicle positions:\n");
    printVehicles(vehicles);

    while(timeElapsed < simulationTime){
        updateVehiclePositions(vehicles, 1);
        printf("Vehicle positions after %d seconds:\n", timeElapsed+1);
        printVehicles(vehicles);
        timeElapsed++;
    }

    return 0;
}