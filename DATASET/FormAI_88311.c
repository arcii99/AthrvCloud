//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEVATORS 3 // number of elevators
#define FLOORS 10 // number of floors in the building
#define MAX_CAPACITY 10 // max number of passengers allowed in elevator
#define TRAVEL_TIME 2 // time it takes to travel between floors
#define DOOR_OPEN_TIME 1 // time the elevator doors stay open

int elevators[NUM_ELEVATORS][3]; // 3 columns: 0 = floor, 1 = passengers, 2 = direction (1 for up, -1 for down)
int passengers[FLOORS]; // number of passengers waiting on each floor

// helper function to generate a random number between min and max inclusive
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// function to simulate a passenger being added to an elevator
// returns the number of passengers that were able to fit in the elevator
int add_passenger(int elevator, int floor) {
    int num_added = 0;
    while (elevators[elevator][1] < MAX_CAPACITY && passengers[floor] > 0) {
        elevators[elevator][1]++;
        passengers[floor]--;
        num_added++;
    }
    return num_added;
}

int main() {
    srand(time(0)); // seed the random number generator
    
    // initialize elevator and passenger data
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i][0] = 0; // all elevators start on the first floor
        elevators[i][1] = 0; // no passengers at the beginning
        elevators[i][2] = 1; // all elevators start going up
    }
    for (int i = 0; i < FLOORS; i++) {
        passengers[i] = random_int(0, 5); // each floor starts with 0-5 passengers
    }
    
    int time_elapsed = 0;
    while (time_elapsed < 100) { // simulate 100 seconds of elevator activity
        // print the current state of the elevators and waiting passengers
        printf("Time: %d\n", time_elapsed);
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            printf("Elevator %d - Floor: %d, Passengers: %d, Direction: %s\n",
                   i + 1, elevators[i][0], elevators[i][1],
                   elevators[i][2] == 1 ? "Up" : "Down");
        }
        for (int i = FLOORS - 1; i >= 0; i--) {
            printf("Passengers waiting on Floor %d: %d\n", i, passengers[i]);
        }
        printf("\n");
        
        // move each elevator one floor in the direction it's going
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            elevators[i][0] += elevators[i][2];
            // if the elevator reaches the top or bottom floor, switch directions
            if (elevators[i][0] == FLOORS - 1) {
                elevators[i][2] = -1;
            } else if (elevators[i][0] == 0) {
                elevators[i][2] = 1;
            }
        }
        
        // offload passengers from elevators that have arrived at their destination floor
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            int floor = elevators[i][0];
            int num_passengers = elevators[i][1];
            int num_removed = 0;
            for (int j = 0; j < num_passengers; j++) {
                if (random_int(0, 1) == 1) { // 50% chance each passenger gets off at their floor
                    num_removed++;
                }
            }
            elevators[i][1] -= num_removed;
            passengers[floor] += num_removed;
        }
        
        // add passengers to elevators that are stopping on their floor
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            int floor = elevators[i][0];
            int num_added = add_passenger(i, floor);
            if (num_added > 0) {
                printf("%d passengers added to Elevator %d on Floor %d\n", num_added, i + 1, floor);
            }
        }
        
        // wait for the elevator doors to stay open
        sleep(DOOR_OPEN_TIME);
        
        // increment the time elapsed
        time_elapsed += TRAVEL_TIME + DOOR_OPEN_TIME;
    }
    
    return 0;
}