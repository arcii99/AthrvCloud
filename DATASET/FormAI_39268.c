//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for traffic flow simulation
#define MAX_CARS 50
#define MAX_SPEED 5
#define MAX_DISTANCE 30
#define SIMULATION_TIME 20

// Struct for car info
typedef struct {
    int speed;
    int position;
} Car;

void simulate_traffic_flow(Car cars[], int num_cars){

    // Variables to keep track of time and distance
    int time = 0;
    int distance = MAX_DISTANCE;

    // Iterate until end of simulation time
    while(time <= SIMULATION_TIME){
        time++;
        printf("=============================\n");
        printf("Time: %d\n", time);

        // Iterate through each car and simulate movement
        for(int i=0; i<num_cars; i++){
            // Determine the distance to the car in front
            int distance_to_car_in_front = MAX_DISTANCE;
            for(int j=0; j<num_cars; j++){
                // Check that the other car is not itself
                if(j != i){
                    int distance_to_other_car = cars[j].position - cars[i].position;
                    if(distance_to_other_car < distance_to_car_in_front
                       && distance_to_other_car > 0){
                        distance_to_car_in_front = distance_to_other_car;
                    }
                }
            }
            // Determine the new speed
            int new_speed;
            if(distance_to_car_in_front <= MAX_SPEED){
                new_speed = distance_to_car_in_front - 1;
            }
            else{
                new_speed = MAX_SPEED;
            }
            cars[i].speed = new_speed;
            // Determine the new position
            int new_position = cars[i].position + new_speed;
            if(new_position >= distance){
                new_position %= distance;
            }
            cars[i].position = new_position;

            // Print out the updated car info
            printf("Car %d: Speed: %d, Position: %d\n",
                   i, cars[i].speed, cars[i].position);
        }

    }
    printf("=============================\n");
}

int main(){

    // Seed for random number generation
    srand(time(NULL));

    // Generate random number of cars between 1 and MAX_CARS
    int num_cars = rand() % (MAX_CARS - 1 + 1) + 1;

    // Initialize the cars with random speeds and positions
    Car cars[num_cars];
    for(int i=0; i<num_cars; i++){
        cars[i].speed = rand() % (MAX_SPEED - 1 + 1) + 1;
        cars[i].position = rand() % (MAX_DISTANCE - 0 + 1) + 0;
    }

    // Print out the initial car info
    printf("Initial Car Info:\n");
    for(int i=0; i<num_cars; i++){
        printf("Car %d: Speed: %d, Position: %d\n",
               i, cars[i].speed, cars[i].position);
    }

    // Simulate traffic flow
    simulate_traffic_flow(cars, num_cars);

    return 0;
}