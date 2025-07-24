//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int floors = 10, max_persons = 10, max_weight = 1000, max_floor = 10;
    int elevator_weight = 0, elevator_persons = 0, current_floor = 1, direction = 1;
    int persons_waiting_here[floors];
    int persons_count = 0;

    srand(time(NULL));

    // Initialize number of persons waiting on each floor
    for(int i=0; i<floors; i++) {
        persons_waiting_here[i] = rand() % (max_persons + 1);
        persons_count += persons_waiting_here[i];
    }

    printf("Initializing elevator...\n");
    printf("Number of persons waiting on each floor:\n");
    for(int i=0; i<floors; i++) {
        printf("Floor %d: %d persons\n", i+1, persons_waiting_here[i]);
    }
    printf("Total number of persons: %d\n", persons_count);

    // Begin simulation
    printf("Simulation started...\n");
    while(1) {
        printf("\nCurrently at floor %d\n", current_floor);

        // Check if there are persons waiting on the current floor
        int persons_waiting = persons_waiting_here[current_floor-1];
        if(persons_waiting > 0) {
            // Add persons to the elevator if there is enough space and weight capacity
            int persons_added = 0;
            for(int i=0; i<persons_waiting; i++) {
                if(elevator_persons < max_persons && elevator_weight+max_weight <= max_weight) {
                    elevator_persons++;
                    elevator_weight += rand() % (max_weight + 1);
                    persons_added++;
                }
            }
            printf("%d persons entered the elevator\n", persons_added);
            persons_waiting_here[current_floor-1] -= persons_added;
            persons_count -= persons_added;
        }

        // Change direction if top or bottom floor is reached
        if(current_floor == max_floor) {
            direction = -1;
            printf("Elevator changing direction (going down)\n");
        } else if(current_floor == 1) {
            direction = 1;
            printf("Elevator changing direction (going up)\n");
        }

        // Move elevator to the next floor
        current_floor += direction;
        
        // Check if there are any persons in the elevator
        if(elevator_persons > 0) {
            printf("%d persons in the elevator, weight: %d\n", elevator_persons, elevator_weight);
        } else {
            printf("No persons in the elevator\n");
        }

        // End simulation if all persons have been transported
        if(persons_count == 0) {
            printf("\nAll persons have been transported!\n");
            break;
        }
    }

    return 0;
}