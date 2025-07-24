//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> // for sleep() function

#define MAX_FLOORS 20  // Maximum Floors in the building
#define MAX_PEOPLE 10  // Maximum People that can occupy the Elevator
#define WAIT_TIME 2  // Time for the Elevator to wait on a floor

// Elevator struct
struct elevator {
    int floor;
    int people_count;
    int people[MAX_PEOPLE];
};

// Function to move the elevator up one floor
void move_up(struct elevator *elev) {
    elev->floor++;
    printf("Elevator moving up to floor %d\n", elev->floor);
    sleep(WAIT_TIME);
}

// Function to move the elevator down one floor
void move_down(struct elevator *elev) {
    elev->floor--;
    printf("Elevator moving down to floor %d\n", elev->floor);
    sleep(WAIT_TIME);
}

int main() {
    int num_people, destination_floor;
    struct elevator elev = {1, 0, {0}};  // Initializing the Elevator
    int floors[MAX_FLOORS+1] = {0};  // Initializing the array to store people on each floor
    int i;

    // Generating a random number of people between 1 and MAX_PEOPLE for each floor
    for(i=1; i<=MAX_FLOORS; i++) {
        floors[i] = rand() % MAX_PEOPLE + 1;
    }

    // Loop to move the elevator to all floors
    for(i=1; i<=MAX_FLOORS; i++) {
        // Check if there are people on current floor
        if(floors[i] > 0) {
            printf("\nElevator on floor %d, %d people waiting\n", i, floors[i]);

            // Loop to add people to the elevator until full or no more people on floor
            while(elev.people_count < MAX_PEOPLE && floors[i] > 0) {
                elev.people[elev.people_count++] = i;
                floors[i]--;
            }

            // Take the people to their destination floors
            for(int j=0; j<elev.people_count; j++) {
                printf("Elevator going to floor %d for person %d\n", elev.people[j], j+1);

                // Move the elevator up or down to reach the person's destination floor
                while(elev.people[j] != elev.floor) {
                    if(elev.people[j] > elev.floor) {
                        move_up(&elev);
                    }
                    else {
                        move_down(&elev);
                    }
                }

                printf("Person %d has reached their destination floor %d\n", j+1, elev.floor);
            }

            // Empty the elevator
            elev.people_count = 0;
        }
        else {
            printf("\nElevator passing by floor %d\n", i);
            // Move the elevator up or down one floor without stopping
            if(i > elev.floor) {
                move_up(&elev);
            }
            else {
                move_down(&elev);
            }
        }
    }

    return 0;
}