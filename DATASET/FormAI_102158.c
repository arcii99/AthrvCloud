//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define FLOORS 10
#define ELEVATORS 3
#define MAX_CAPACITY 10

// Define struct for elevator
typedef struct {
    int current_floor;
    int capacity;
    int destination[FLOORS];
    int num_destinations;
} Elevator;

int main() {
    srand(time(NULL)); // seed random number generator
    
    // Create array of elevators
    Elevator elevators[ELEVATORS];
    for (int i = 0; i < ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].capacity = 0;
        elevators[i].num_destinations = 0;
        for (int j = 0; j < FLOORS; j++) {
            elevators[i].destination[j] = 0;
        }
    }
    
    int passengers_waiting[FLOORS] = {0}; // initialize array of passengers waiting on each floor
    
    int num_passengers = 0;
    int total_travel_time = 0;
    
    // Begin simulation loop
    for (int time = 0; time < 1440; time++) { // 1440 minutes in a day
        // Check if any passengers are boarding
        for (int i = 0; i < FLOORS; i++) {
            if (passengers_waiting[i] > 0) {
                // Board on random elevator
                int elevator_index = rand() % ELEVATORS;
                if (elevators[elevator_index].capacity < MAX_CAPACITY) {
                    elevators[elevator_index].destination[i] = 1;
                    elevators[elevator_index].num_destinations++;
                    elevators[elevator_index].capacity++;
                    passengers_waiting[i]--;
                    num_passengers++;
                }
            }
        }
        
        // Move each elevator
        for (int i = 0; i < ELEVATORS; i++) {
            if (elevators[i].num_destinations > 0) {
                if (elevators[i].current_floor == FLOORS - 1) {
                    elevators[i].current_floor--; // go down if at top floor
                } else if (elevators[i].current_floor == 0) {
                    elevators[i].current_floor++; // go up if at ground floor
                } else {
                    // Choose random direction
                    int direction = rand() % 2;
                    if (direction == 0) {
                        elevators[i].current_floor--;
                    } else {
                        elevators[i].current_floor++;
                    }
                }
                
                // Check if elevator has arrived at destination
                if (elevators[i].destination[elevators[i].current_floor] == 1) {
                    elevators[i].destination[elevators[i].current_floor] = 0;
                    elevators[i].num_destinations--;
                    elevators[i].capacity--;
                    
                    // Calculate travel time for passengers
                    total_travel_time += (time - elevators[i].current_floor);
                }
            }
        }
        
        // Spawn new passengers
        for (int i = 0; i < FLOORS; i++) {
            if (rand() % 10 == 0) { // 1 in 10 chance to spawn new passenger
                passengers_waiting[i]++;
            }
        }
    }
    
    // Print simulation results
    printf("Simulation complete!\n");
    printf("Total passengers: %d\n", num_passengers);
    printf("Average travel time: %f minutes\n", (float)total_travel_time/num_passengers);
    
    return 0;
}