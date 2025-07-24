//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FLOORS 100  // Maximum number of floors. Could be changed for different buildings.
#define MAX_PEOPLE 25   // Maximum number of people that can fit in the elevator.

// Struct to represent a person waiting for the elevator.
typedef struct Person {
    int start_floor;    // Floor the person is on.
    int dest_floor;     // Floor the person wants to go to.
    bool in_elevator;   // True if the person is in the elevator.
} Person;

// Struct to represent an elevator.
typedef struct Elevator {
    int current_floor;              // Floor the elevator is currently on.
    int dest_floor;                 // Floor the elevator is heading to.
    int people_count;               // Number of people currently in the elevator.
    int people_destinations[MAX_PEOPLE]; // Array of floors each person in the elevator wants to go to.
} Elevator;

// Function to simulate the elevator.
void simulate_elevator(Person people[], int num_people, int num_floors) {
    Elevator elevator = {0};    // Create an elevator object. Starts on ground floor.
    int time = 0;               // Current time.
    bool up_direction = true;   // True if the elevator is currently heading up. False if heading down.
    int idle_time = 0;          // Time the elevator has spent idle.

    while (idle_time < 10) {    // Run the loop until the elevator has been idle for 10 time units.
        // Check if anyone is waiting on the current floor and add them to the elevator.
        for (int i = 0; i < num_people; i++) {
            if (people[i].start_floor == elevator.current_floor && elevator.people_count < MAX_PEOPLE) {
                people[i].in_elevator = true;
                elevator.people_destinations[elevator.people_count] = people[i].dest_floor;
                elevator.people_count++;
            }
        }

        // If the elevator is full or no one is waiting, change direction.
        if (elevator.people_count == MAX_PEOPLE || 
            (elevator.people_count == 0 && idle_time >= 5)) { // If no one is waiting, the elevator will wait for 5 time units before changing directions. 
            up_direction = !up_direction;
            idle_time = 0;      // Reset the idle time.
        }

        // Sort the floors the passengers want to go to in ascending order.
        for (int i = 0; i < elevator.people_count - 1; i++) {
            for (int j = i + 1; j < elevator.people_count; j++) {
                if (elevator.people_destinations[i] > elevator.people_destinations[j]) {
                    int temp = elevator.people_destinations[i];
                    elevator.people_destinations[i] = elevator.people_destinations[j];
                    elevator.people_destinations[j] = temp;
                }
            }
        }

        // Check if the elevator has reached its destination floor.
        if (elevator.current_floor == elevator.dest_floor) {
            int next_destination = 0;

            // Find the next destination floor in the elevator's current direction.
            for (int i = 0; i < elevator.people_count; i++) {
                if (up_direction && elevator.people_destinations[i] > elevator.current_floor) {
                    next_destination = elevator.people_destinations[i];
                    break;
                } else if (!up_direction && elevator.people_destinations[i] < elevator.current_floor) {
                    next_destination = elevator.people_destinations[i];
                    break;
                }
            }

            // If no destinations in current direction, change direction.
            if (next_destination == 0) {
                up_direction = !up_direction;
                idle_time = 0;  // Reset the idle time.
                continue;       // Continue to the next iteration of the loop.
            }

            // Destination found, move elevator to the next destination.
            elevator.dest_floor = next_destination;
        }

        // Move the elevator towards the destination floor.
        if (elevator.dest_floor > elevator.current_floor) {
            elevator.current_floor++;
        } else if (elevator.dest_floor < elevator.current_floor) {
            elevator.current_floor--;
        }

        // Increment the time and idle time counters.
        time++;
        idle_time++;

        // Print the current status of the elevator.
        printf("Time: %d, Floor: %d, Direction: %s, Passengers: %d\n", 
                time, elevator.current_floor, 
                up_direction ? "Up" : "Down", 
                elevator.people_count);
    }
}

int main() {
    // Example input.
    Person people[] = {
        {1, 10, false},
        {2, 3, false},
        {4, 8, false},
        {2, 5, false},
        {10, 1, false},
        {6, 1, false},
        {3, 4, false},
        {7, 2, false},
        {4, 2, false},
        {8, 9, false},
        {10, 1, false},
        {1, 5, false},
        {7, 6, false},
        {5, 1, false},
        {1, 4, false},
        {9, 3, false},
        {3, 7, false}
    };
    int num_people = sizeof(people) / sizeof(people[0]);
    int num_floors = MAX_FLOORS;

    simulate_elevator(people, num_people, num_floors);

    return 0;
}