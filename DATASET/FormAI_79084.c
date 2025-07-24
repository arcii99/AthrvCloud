//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGHT_GREEN 0
#define LIGHT_YELLOW 1
#define LIGHT_RED 2

#define NUM_ROADS 4
#define NUM_CARS 20
#define MAX_SPEED 5

int light_state[NUM_ROADS] = {LIGHT_GREEN, LIGHT_GREEN, LIGHT_RED, LIGHT_RED};
int road_speeds[NUM_ROADS] = {MAX_SPEED, MAX_SPEED, MAX_SPEED, MAX_SPEED};
int car_positions[NUM_ROADS][NUM_CARS] = {0};
int car_speeds[NUM_ROADS][NUM_CARS] = {0};

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    
    int time_step = 0;
    while (time_step < 10) {
        for (int road = 0; road < NUM_ROADS; road++) {
            printf("Road %d: ", road);
            
            // Move each car forward based on their speed
            for (int car = 0; car < NUM_CARS; car++) {
                int position = car_positions[road][car];
                int speed = car_speeds[road][car];
                
                // Check if car needs to stop at red light or slow down for other cars
                if (position == 0 && light_state[road] != LIGHT_GREEN) {
                    speed = 0;
                    printf("CAR%d SLOWED TO STOP AT RED LIGHT. ", car);
                } else {
                    for (int other_car = 0; other_car < NUM_CARS; other_car++) {
                        if (road == NUM_ROADS - 1 && other_car == car) { // Last road doesn't have cars in front of it
                            break;
                        }
                        
                        int other_position = car_positions[road][other_car];
                        int distance = other_position - position;
                        
                        if (distance < 0) { // Other car is behind current car
                            distance = NUM_CARS - position + other_position;
                        }
                        if (distance < speed) {
                            speed = distance - 1;
                        }
                    }
                }
                
                // Update car position and speed
                position = (position + speed) % NUM_CARS;
                car_positions[road][car] = position;
                car_speeds[road][car] = speed;
                
                printf("CAR%d POS=%d SPEED=%d ", car, position, speed);
            }
            printf("\n");
            
            // Change light state at end of road
            if (car_positions[road][NUM_CARS - 1] == 0) {
                if (light_state[road] == LIGHT_GREEN) {
                    light_state[road] = LIGHT_YELLOW;
                    printf("Road %d: LIGHT CHANGED TO YELLOW. \n", road);
                } else if (light_state[road] == LIGHT_YELLOW) {
                    light_state[road] = LIGHT_RED;
                    printf("Road %d: LIGHT CHANGED TO RED. \n", road);
                } else if (light_state[road] == LIGHT_RED) {
                    if (car_speeds[road][(NUM_CARS - 1) / 2] == 0) { // Check if middle car is stopped at red light
                        light_state[road] = LIGHT_GREEN;
                        printf("Road %d: LIGHT CHANGED TO GREEN. \n", road);
                    }
                }
            }
        }
        printf("\n");
        time_step++;
    }
    
    return 0;
}