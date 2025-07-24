//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definitions for road size
#define HEIGHT 10
#define WIDTH 50

// Definitions for simulation
#define MAX_TICKS 1000
#define MAX_CARS 20
#define CAR_SPAWN_PROB 0.2 // Probability of spawning a car on a road
#define CAR_SPEED 3 // Number of cells a car moves per tick

// Function declarations
void print_road(char road[HEIGHT][WIDTH]);
void update_cars(char road[HEIGHT][WIDTH], int car_positions[], int num_cars);
void spawn_cars(char road[HEIGHT][WIDTH], int car_positions[], int *num_cars);
void move_car(char road[HEIGHT][WIDTH], int position);
void clear_cars(char road[HEIGHT][WIDTH], int car_positions[], int num_cars);
void print_simulation_results(int ticks, int cars_passed);

int main() {
    // Initialize road
    char road[HEIGHT][WIDTH];
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            if(i == 0 || i == HEIGHT-1) {
                road[i][j] = '-';
            } else {
                road[i][j] = ' ';
            }
        }
    }
    
    // Initialize cars
    int car_positions[MAX_CARS];
    int num_cars = 0;
    
    // Initialize simulation variables
    int ticks = 0;
    int cars_passed = 0;
    
    // Seed random number generator
    srand(time(0));
    
    // Simulation loop
    while(ticks < MAX_TICKS) {
        // Update cars
        update_cars(road, car_positions, num_cars);
        
        // Spawn cars with a certain probability
        spawn_cars(road, car_positions, &num_cars);
        
        // Clear cars that have passed the end of the road
        clear_cars(road, car_positions, num_cars);
        
        // Print road
        print_road(road);
        
        // Check if a car has passed the end of the road
        if(car_positions[num_cars-1] >= WIDTH-1) {
            cars_passed++;
        }
        
        // Increment ticks
        ticks++;
    }
    
    // Print simulation results
    print_simulation_results(ticks, cars_passed);
    
    return 0;
}

// Function to print the current state of the road
void print_road(char road[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", road[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to update the position of each car on the road
void update_cars(char road[HEIGHT][WIDTH], int car_positions[], int num_cars) {
    for(int i=0; i<num_cars; i++) {
        move_car(road, car_positions[i]);
    }
}

// Function to spawn cars with a certain probability
void spawn_cars(char road[HEIGHT][WIDTH], int car_positions[], int *num_cars) {
    float prob = (float)rand() / RAND_MAX;
    if(prob < CAR_SPAWN_PROB && *num_cars < MAX_CARS) {
        car_positions[*num_cars] = 1;
        road[HEIGHT/2][1] = 'C';
        (*num_cars)++;
    }
}

// Function to move a car one cell to the right
void move_car(char road[HEIGHT][WIDTH], int position) {
    if(position >= 0 && position < WIDTH-1) {
        road[HEIGHT/2][position] = ' ';
        road[HEIGHT/2][position+1] = 'C';
    }
}

// Function to clear cars that have passed the end of the road
void clear_cars(char road[HEIGHT][WIDTH], int car_positions[], int num_cars) {
    int i = 0;
    while(i < num_cars) {
        if(car_positions[i] >= WIDTH-1) {
            car_positions[i] = car_positions[num_cars-1];
            num_cars--;
        } else {
            i++;
        }
    }
}

// Function to print the results of the simulation
void print_simulation_results(int ticks, int cars_passed) {
    printf("Simulation results:\n");
    printf("Ticks: %d\n", ticks);
    printf("Cars passed: %d\n", cars_passed);
    float avg_time_per_car = (float)ticks / cars_passed;
    printf("Average time per car: %.2f ticks\n", avg_time_per_car);
}