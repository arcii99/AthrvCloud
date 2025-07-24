//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50     // Maximum number of cars on the road
#define MAX_SPEED 60    // Maximum speed of cars on the road
#define TIME_STEP 1     // Time step of the simulation
#define SIM_TIME 3600   // Time duration of the simulation in seconds

// Function to generate random numbers within a range
int generate_random_number(int min_val, int max_val){
    return (rand() % (max_val - min_val + 1)) + min_val;
}

// Function to simulate car movement on the road
void simulate_car_movement(int car_positions[], int car_speeds[], int num_cars){
    for(int i=0; i<num_cars; i++){
        if(car_positions[i] != -1){
            int distance_traveled = car_speeds[i] * TIME_STEP;
            int new_pos = car_positions[i] + distance_traveled;
            if(new_pos > 1000){
                car_positions[i] = -1;
                continue;
            }
            for(int j=0; j<num_cars; j++){
                if(j != i && car_positions[j] != -1 && abs(car_positions[j] - new_pos) <= 20){
                    continue;
                }
            }
            car_positions[i] = new_pos;
        }
    }
}

// Function to add new cars to the road
void add_new_cars(int car_positions[], int car_speeds[], int num_cars){
    for(int i=0; i<num_cars; i++){
        if(car_positions[i] == -1 && generate_random_number(0,1) == 1){
            car_positions[i] = 0;
            car_speeds[i] = generate_random_number(1, MAX_SPEED);
        }
    }
}

// Function to print the road with car positions
void print_road(int car_positions[], int num_cars){
    for(int i=0; i<=1000; i++){
        if(i % 100 == 0){
            printf("|");
        } else if(i % 20 == 0){
            printf("+");
        } else {
            int car_printed = 0;
            for(int j=0; j<num_cars; j++){
                if(car_positions[j] == i){
                    printf(">");
                    car_printed = 1;
                    break;
                }
            }
            if(car_printed == 0){
                printf("-");
            }
        }
    }
    printf("|\n");
}

int main(){
    // Initialize random number generator
    srand(time(NULL));
    
    // Initialize car positions and speeds
    int car_positions[MAX_CARS];
    int car_speeds[MAX_CARS];
    for(int i=0; i<MAX_CARS; i++){
        car_positions[i] = -1;
        car_speeds[i] = 0;
    }
    
    // Simulate traffic flow for specified time duration
    for(int i=0; i<SIM_TIME; i+=TIME_STEP){
        add_new_cars(car_positions, car_speeds, MAX_CARS);
        simulate_car_movement(car_positions, car_speeds, MAX_CARS);
        print_road(car_positions, MAX_CARS);
    }
    
    return 0;
}