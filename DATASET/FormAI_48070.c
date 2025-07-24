//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of bags
#define MAX_BAGS 100

// Define the maximum travel time for bags
#define MAX_TRAVEL_TIME 10

// Define the maximum number of conveyor belts
#define MAX_CONVEYOR_BELTS 10

// Define the maximum travel time for conveyor belts
#define MAX_CONVEYOR_BELT_TRAVEL_TIME 5

// Define the maximum timeout for unloading a baggage from the plane
#define MAX_TIMEOUT 3

// The Baggage struct to hold information about a piece of baggage
typedef struct Baggage {
    int id; // the ID of the baggage
    int arrival_time; // the time the baggage arrived at the airport
    int conveyor_belt_id; // the ID of the conveyor belt the baggage is on
    int travel_time; // the time it takes for the baggage to travel from the conveyor belt to the plane
    int unloading_timeout; // the time the plane can wait for the baggage to be unloaded
} Baggage;

// The ConveyorBelt struct to hold information about a conveyor belt
typedef struct ConveyorBelt {
    int id; // the ID of the conveyor belt
    int travel_time; // the time it takes for a bag to travel from the conveyor belt to the plane
    int is_available; // a flag to indicate whether the conveyor belt is available
} ConveyorBelt;

// The Plane struct to hold information about a plane
typedef struct Plane {
    int id; // the ID of the plane
    int unloading_timeout; // the time the plane can wait for the baggage to be unloaded
} Plane;

// Declare global variables
Baggage baggage_list[MAX_BAGS];
int num_bags = 0;
ConveyorBelt conveyor_belt_list[MAX_CONVEYOR_BELTS];
int num_conveyor_belts = 0;
Plane plane;

// Function to generate a random number between min and max, inclusive
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to initialize the baggage_list
void init_baggage_list() {
    int i;
    for (i = 0; i < MAX_BAGS; i++) {
        baggage_list[i].id = i; // set the ID of the baggage
        baggage_list[i].arrival_time = -1; // set the arrival time to -1 to indicate that it hasn't arrived yet
        baggage_list[i].conveyor_belt_id = -1; // set the conveyor belt ID to -1 to indicate that it's not on a conveyor belt yet
        baggage_list[i].travel_time = -1; // set the travel time to -1 to indicate that it hasn't started traveling yet
        baggage_list[i].unloading_timeout = -1; // set the unloading timeout to -1 to indicate that it hasn't been unloaded yet
    }
    num_bags = MAX_BAGS; // set the number of bags to the maximum
}

// Function to initialize the conveyor_belt_list
void init_conveyor_belt_list() {
    int i;
    for (i = 0; i < MAX_CONVEYOR_BELTS; i++) {
        conveyor_belt_list[i].id = i; // set the ID of the conveyor belt
        conveyor_belt_list[i].travel_time = get_random_number(1, MAX_CONVEYOR_BELT_TRAVEL_TIME); // set the travel time of the conveyor belt
        conveyor_belt_list[i].is_available = 1; // set the availability of the conveyor belt to true
    }
    num_conveyor_belts = MAX_CONVEYOR_BELTS; // set the number of conveyor belts to the maximum
}

// Function to initialize the plane
void init_plane() {
    plane.id = 1; // set the ID of the plane
    plane.unloading_timeout = get_random_number(1, MAX_TIMEOUT); // set the unloading timeout of the plane
}

// Function to add a new baggage to the airport
void add_new_baggage(int arrival_time) {
    int i;
    for (i = 0; i < num_bags; i++) {
        if (baggage_list[i].arrival_time == -1) { // find the first empty slot in the baggage list
            baggage_list[i].arrival_time = arrival_time; // set the arrival time of the new baggage
            baggage_list[i].travel_time = get_random_number(1, MAX_TRAVEL_TIME); // set the travel time of the new baggage
            baggage_list[i].unloading_timeout = get_random_number(1, MAX_TIMEOUT); // set the unloading timeout of the new baggage based on the plane
            break;
        }
    }
}

int main() {
    srand(time(NULL)); // set the seed for the random number generator
    init_baggage_list(); // initialize the baggage list
    init_conveyor_belt_list(); // initialize the conveyor belt list
    init_plane(); // initialize the plane
    printf("Welcome to the surreal airport baggage handling simulation!\n\n");

    // Main simulation loop
    int current_time = 0; // initialize the current time
    while (current_time < 100) { // while the simulation is still running
        printf("Time: %d\n", current_time);

        // Add new baggage to the airport
        if (get_random_number(0, 1)) { // if a new baggage arrives
            add_new_baggage(current_time); // add it to the airport
            printf("New baggage has arrived at the airport!\n");
        }

        // Check if any baggage is on a conveyor belt
        int i;
        for (i = 0; i < num_bags; i++) {
            if (baggage_list[i].travel_time > 0) { // if the baggage is traveling
                baggage_list[i].travel_time--; // decrement the travel time
                if (baggage_list[i].travel_time == 0) { // if the baggage has reached the plane
                    printf("Baggage %d has reached the plane!\n", baggage_list[i].id);
                }
            } else if (baggage_list[i].conveyor_belt_id != -1) { // if the baggage is on a conveyor belt
                ConveyorBelt cb = conveyor_belt_list[baggage_list[i].conveyor_belt_id]; // get the conveyor belt
                if (cb.is_available) { // if the conveyor belt is available
                    cb.is_available = 0; // set the conveyor belt to not available
                    baggage_list[i].travel_time = cb.travel_time; // set the travel time of the baggage
                    printf("Baggage %d is on conveyor belt %d and will take %d minutes to reach the plane!\n", baggage_list[i].id, cb.id, cb.travel_time);
                }
            }
        }

        // Check if the plane has unloaded any baggage
        for (i = 0; i < num_bags; i++) {
            if (baggage_list[i].unloading_timeout > 0) { // if the baggage is being unloaded
                baggage_list[i].unloading_timeout--; // decrement the unloading timeout
                if (baggage_list[i].unloading_timeout == 0) { // if the baggage has not been unloaded in time
                    printf("Baggage %d was not unloaded from the plane in time!\n", baggage_list[i].id);
                }
            }
        }

        // Check if any conveyor belts are available
        for (i = 0; i < num_conveyor_belts; i++) {
            if (!conveyor_belt_list[i].is_available) { // if the conveyor belt is not available
                conveyor_belt_list[i].travel_time--; // decrement the travel time of the baggage on the conveyor belt
                if (conveyor_belt_list[i].travel_time == 0) { // if the baggage on the conveyor belt has reached the end
                    conveyor_belt_list[i].is_available = 1; // set the conveyor belt to available
                    printf("Baggage on conveyor belt %d has reached the end!\n", conveyor_belt_list[i].id);
                }
            }
        }

        // Increment the current time
        current_time++;
        printf("\n");
    }

    return 0;
}