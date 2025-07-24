//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROADS 10
#define MAX_CARS 20

int roads[MAX_ROADS][2]; // array for storing road lengths
int cars[MAX_CARS][3]; // array for storing car positions and speeds

//function for initializing roads and cars
void initialize(int num_roads, int num_cars) {
    srand(time(NULL)); // initialize random seed
    //initialize roads with random lengths between 1 and 10
    for(int i=0; i<num_roads; i++) {
        roads[i][0] = i+1;
        roads[i][1] = rand()%10 + 1;
    }
    //initialize cars with random positions and speeds
    for(int i=0; i<num_cars; i++) {
        cars[i][0] = rand()%num_roads; //random road
        cars[i][1] = rand()%(roads[cars[i][0]][1] + 1); //random position on road
        cars[i][2] = rand()%5 + 1; // random speed between 1 and 5
    }
}

//function for displaying the current state of the traffic flow
void display(int num_roads, int num_cars) {
    printf("---------------------------------------------\n");
    //display road lengths
    printf("Roads:\n");
    for(int i=0; i<num_roads; i++) {
        printf("Road %d\tLength: %d\n", roads[i][0], roads[i][1]);
    }
    //display car positions and speeds
    printf("\nCars:\n");
    for(int i=0; i<num_cars; i++) {
        printf("Car %d\tRoad: %d\tPosition: %d\tSpeed: %d\n", i, cars[i][0], cars[i][1], cars[i][2]);
    }
    printf("---------------------------------------------\n");
}

//function for simulating the movement of cars
void simulate(int num_roads, int num_cars) {
    //for each car, calculate its new position and speed
    for(int i=0; i<num_cars; i++) {
        int new_pos = cars[i][1] + cars[i][2]; //calculate new position
        //if the car reaches the end of the road, wrap around to the beginning
        if(new_pos > roads[cars[i][0]][1]) {
            cars[i][1] = new_pos - roads[cars[i][0]][1];
        }
        //otherwise, update the position normally
        else {
            cars[i][1] = new_pos;
        }
    }
}

int main() {
    int num_roads = 5;
    int num_cars = 10;
    initialize(num_roads, num_cars);
    display(num_roads, num_cars);
    printf("Simulating traffic flow...\n");
    for(int i=0; i<10; i++) {
        simulate(num_roads, num_cars);
        display(num_roads, num_cars);
    }
    return 0;
}