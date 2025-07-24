//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100 // maximum speed limit on the road
#define NUM_CARS 50 // number of cars on the road
#define TIME_STEP 1 // time step in seconds

struct car {
    int position; // position of the car on the road
    int speed; // speed of the car in km/h
};

void update_car_position(struct car *c);
void print_road(struct car cars[], int size, int time);
void simulate_traffic_flow(struct car cars[], int size, int time);

int main() {
    srand(time(NULL)); // seed the random number generator
    
    struct car cars[NUM_CARS]; // initialize the cars on the road
    for (int i = 0; i < NUM_CARS; i++) {
        cars[i].position = i * 10; // set initial position of the car
        cars[i].speed = rand() % MAX_SPEED; // set initial speed of the car
    }
    
    simulate_traffic_flow(cars, NUM_CARS, 0); // start simulation
    
    return 0;
}

// update the position of a given car based on its speed
void update_car_position(struct car *c) {
    c->position += c->speed * (TIME_STEP / 3600);
}

// print the current state of the road
void print_road(struct car cars[], int size, int time) {
    printf("Time Step: %ds\n", time);
    for (int i = 0; i < size; i++) {
        printf("Car %d: Position = %dm, Speed = %dkm/h\n", i, cars[i].position, cars[i].speed);
    }
    printf("\n");
}

// simulate the traffic flow on the road
void simulate_traffic_flow(struct car cars[], int size, int time) {
    while (time < 3600) { // simulate for 1 hour
        print_road(cars, size, time);
        for (int i = 0; i < size; i++) {
            // update the position of each car based on its speed
            update_car_position(&cars[i]);
            
            // adjust the speed of the car based on the distance to the next car
            if (i < size - 1) {
                int distance = cars[i + 1].position - cars[i].position;
                if (distance < 10) {
                    cars[i].speed--;
                } else if (distance > 20) {
                    cars[i].speed++;
                }
            }
            
            // limit the speed of the car to the maximum speed limit on the road
            if (cars[i].speed > MAX_SPEED) {
                cars[i].speed = MAX_SPEED;
            }
        }
        
        time += TIME_STEP; // advance the simulation time
    }
}