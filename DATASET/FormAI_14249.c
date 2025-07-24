//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Elevator Simulation Program */

int main() {
    /* Initialize the building */
    printf("Initializing the building...\n\n");
    int num_floors = 10; // number of floors in the building
    int current_floor = 1; // current floor for the elevator
    int target_floor = 1; // target floor for the elevator
    int num_people = 0; // number of people in the building
    int max_people = 20; // maximum capacity for the elevator
    int people_waiting[num_floors+1]; // number of people waiting on each floor
    for(int i=1; i<=num_floors; i++) {
        people_waiting[i] = rand() % 10; // randomly assign number of people waiting on each floor
        printf("Floor %d: %d people waiting\n", i, people_waiting[i]); // print out number of people waiting on each floor
        num_people += people_waiting[i]; // add the number of people waiting on each floor to total population
    }
    printf("\nTotal number of people in the building: %d\n\n", num_people);
    
    /* Start the elevator */
    printf("Starting the elevator...\n\n");
    int num_moves = 0; // count number of moves for the elevator
    while(num_people > 0) { // loop until all people have been transported
        if(target_floor == current_floor) { // if elevator has reached the target floor
            printf("Elevator has arrived at floor %d\n", current_floor);
            if(people_waiting[current_floor] > 0) { // if there are people waiting on the current floor
                int num_boarding = people_waiting[current_floor]; // determine how many people are boarding
                if(num_boarding > max_people) { // if there are more people than the elevator can hold
                    num_boarding = max_people; // board maximum number of people
                }
                printf("%d people are boarding the elevator at floor %d\n", num_boarding, current_floor);
                num_people -= num_boarding; // subtract number of people boarding from total population
                people_waiting[current_floor] -= num_boarding; // subtract number of people boarding from number of people waiting on that floor
            }
            printf("Elevator is going to floor %d\n\n", target_floor);
            num_moves++; // increment number of moves
        }
        else { // if elevator has not reached the target floor
            if(target_floor > current_floor) { // if elevator needs to go up
                printf("Elevator is going up from floor %d to floor %d\n", current_floor, current_floor+1);
                current_floor++;
                num_moves++; // increment number of moves
            }
            else { // if elevator needs to go down
                printf("Elevator is going down from floor %d to floor %d\n", current_floor, current_floor-1);
                current_floor--;
                num_moves++; // increment number of moves
            }
        }
        if(num_moves % 5 == 0) { // every 5 moves, change the target floor
            target_floor = rand() % num_floors + 1; // randomly choose target floor
        }
    }
    printf("Elevator simulation complete! Total number of moves: %d\n", num_moves);
    return 0;
}