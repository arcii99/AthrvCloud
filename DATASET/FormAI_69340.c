//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100 // maximum number of cars in the simulation
#define NUM_LANES 2 // number of lanes in the road
#define MAX_SPEED 5 // maximum speed that cars can travel at
#define MAX_TIME 20 // maximum amount of time the simulation will run for

typedef struct {
    int id; // unique identifier for the car
    int speed; // current speed of the car
    int position; // current position of the car on the road
    int lane; // current lane the car is in
} Car;

int num_cars = 0; // current number of cars in the simulation
Car cars[MAX_CARS]; // array to hold all the cars in the simulation

// function to randomly generate a new car and add it to the simulation
void add_car() {
    if (num_cars < MAX_CARS) {
        Car new_car;
        new_car.id = num_cars;
        new_car.speed = rand() % MAX_SPEED + 1;
        new_car.position = 0;
        new_car.lane = rand() % NUM_LANES;
        cars[num_cars] = new_car;
        num_cars++;
    }
}

// function to update the position of all the cars in the simulation
void update_cars() {
    // loop through all the cars
    for (int i = 0; i < num_cars; i++) {
        Car *car = &cars[i];
        // calculate the distance the car will travel this time step
        int distance = car->speed;
        // check for other cars in front of this car
        for (int j = 0; j < num_cars; j++) {
            if (i != j && car->lane == cars[j].lane && car->position < cars[j].position) {
                int dist_to_car_ahead = cars[j].position - car->position;
                if (dist_to_car_ahead < distance) {
                    distance = dist_to_car_ahead;
                    if (distance < cars[j].speed) {
                        car->speed = distance;
                    }
                }
            }
        }
        // update the position of the car
        car->position += distance;
        // if the car is at the end of the road, remove it from the simulation
        if (car->position >= 100) {
            num_cars--;
            cars[i] = cars[num_cars];
            i--;
        }
    }
}

// function to print the current state of the simulation
void print_state(int time) {
    printf("Time: %d\n", time);
    for (int lane = 0; lane < NUM_LANES; lane++) {
        printf("Lane %d: ", lane);
        for (int i = 0; i < num_cars; i++) {
            if (cars[i].lane == lane) {
                int num_spaces = cars[i].position - 1;
                for (int j = 0; j < num_spaces; j++) {
                    printf("-");
                }
                printf("%d", cars[i].id);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // add some initial cars to the simulation
    for (int i = 0; i < 10; i++) {
        add_car();
    }

    // run the simulation
    for (int time = 1; time <= MAX_TIME; time++) {
        // randomly add a new car to the simulation
        if (rand() % 10 == 0) {
            add_car();
        }
        // update the position of all the cars in the simulation
        update_cars();
        // print the current state of the simulation
        print_state(time);
    }

    return 0;
}