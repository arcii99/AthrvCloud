//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 1000
#define MAX_SPEED 100
#define ROAD_LENGTH 100

// Struct for Car
typedef struct car{
    int speed;
    int position;
}Car;

// Function to move car on the road
int moveCar(Car* car, int num_of_cars, int index){
    int dist = car[index].speed;

    // Check if car gets hit by another
    for(int i=0;i<num_of_cars;i++){
        if(i != index && car[i].position >= car[index].position 
           && car[i].position < car[index].position + dist){
            dist = car[i].position - car[index].position;
        }
    }

    // Calculate new position
    int position = car[index].position + dist;
    if(position >= ROAD_LENGTH){
        return 0;
    }
    car[index].position = position;
    return 1;
}

// Function to print the road
void printRoad(Car* car, int num_of_cars){
    int road[ROAD_LENGTH];
    for(int i=0;i<ROAD_LENGTH;i++){
        road[i] = -1;
    }

    // Place the cars on the road
    for(int i=0;i<num_of_cars;i++){
        if(car[i].position != -1){
            road[car[i].position] = i;
        }
    }

    // Print the road
    for(int i=0;i<ROAD_LENGTH;i++){
        if(road[i] == -1){
            printf(".");
        }
        else{
            printf("%d", road[i]);
        }
    }
    printf("\n");
}

// Main Function
int main(){
    srand(time(NULL));

    // Initialize Cars
    Car cars[MAX_CARS];
    int num_of_cars = 0;
    for(int i=0;i<MAX_CARS;i++){
        cars[i].position = -1;
    }

    // Generate Cars on the road
    while(num_of_cars < MAX_CARS && rand() % 10 > 3){
        cars[num_of_cars].speed = rand() % MAX_SPEED + 1;
        cars[num_of_cars].position = 0;
        num_of_cars++;
    }

    // Loop for Traffic Simulation
    while(num_of_cars > 0){
        printRoad(cars, num_of_cars);

        // Move each car on the road
        for(int i=0;i<num_of_cars;i++){
            if(!moveCar(cars, num_of_cars, i)){
                cars[i].position = -1;
                num_of_cars--;
            }
        }

        // Generate new cars on the road
        if(rand() % 10 > 3 && num_of_cars < MAX_CARS){
            cars[num_of_cars].speed = rand() % MAX_SPEED + 1;
            cars[num_of_cars].position = 0;
            num_of_cars++;
        }

        // Wait for some time
        for(int i=0;i<100000000;i++);
    }

    printf("Traffic Cleared!\n");
    return 0;
}