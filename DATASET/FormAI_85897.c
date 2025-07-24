//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define FLOOR_COUNT 10 // number of floors in the building
#define ELEVATOR_CAPACITY 10 // maximum capacity of the elevator
#define MAX_PEOPLE_COUNT 20 // maximum number of people in the building

// structure to represent a person in the building
struct person {
    int id; // unique identifier of the person
    int current_floor; // floor on which the person is currently present
    int destination_floor; // floor to which the person wants to go
};

// structure to represent the elevator
struct elevator {
    int current_floor; // floor on which the elevator is currently present
    int current_direction; // direction in which the elevator is moving (1: up, -1: down, 0: stationary)
    int current_capacity; // number of people currently in the elevator
    struct person* people_in_elevator[ELEVATOR_CAPACITY]; // array of pointers to people in the elevator
};

int main() {
    // create an elevator object and initialize its state
    struct elevator lift;
    lift.current_floor = 1;
    lift.current_direction = 0;
    lift.current_capacity = 0;
    
    // create an array to hold all the people in the building
    struct person people[MAX_PEOPLE_COUNT];
    
    // generate some random people with random starting and destination floors
    for(int i=0; i<MAX_PEOPLE_COUNT; ++i) {
        people[i].id = i+1;
        people[i].current_floor = (rand() % FLOOR_COUNT) + 1;
        people[i].destination_floor = (rand() % FLOOR_COUNT) + 1;
        
        // make sure the starting and destination floors are different
        while(people[i].destination_floor == people[i].current_floor) {
            people[i].destination_floor = (rand() % FLOOR_COUNT) + 1;
        }
    }
    
    // run the elevator simulation loop for 1000 seconds
    for(int t=0; t<1000; ++t) {
        
        // check if there are any people waiting on the current floor
        int people_waiting_on_current_floor = 0;
        for(int i=0; i<MAX_PEOPLE_COUNT; ++i) {
            if(people[i].current_floor == lift.current_floor) {
                ++people_waiting_on_current_floor;
            }
        }
        
        // if there are people waiting, check if the elevator has capacity to pick them up
        if(people_waiting_on_current_floor > 0 && lift.current_capacity < ELEVATOR_CAPACITY) {
            
            // add the waiting people to the elevator
            int people_added_to_elevator = 0;
            for(int i=0; i<MAX_PEOPLE_COUNT; ++i) {
                if(people[i].current_floor == lift.current_floor && lift.current_capacity < ELEVATOR_CAPACITY) {
                    lift.people_in_elevator[lift.current_capacity] = &people[i];
                    ++lift.current_capacity;
                    ++people_added_to_elevator;
                }
            }
            
            printf("Time: %d seconds. Elevator has arrived at floor %d. %d people have boarded the elevator. %d people are still waiting on the floor.\n",
                   t, lift.current_floor, people_added_to_elevator, people_waiting_on_current_floor - people_added_to_elevator);
        }
        else if(lift.current_capacity > 0) { // there are people in the elevator, check if anyone wants to get off at the current floor
            
            // remove the people who want to get off at the current floor from the elevator
            int people_removed_from_elevator = 0;
            for(int i=0; i<lift.current_capacity; ++i) {
                if(lift.people_in_elevator[i]->destination_floor == lift.current_floor) {
                    printf("Time: %d seconds. Person %d has exited the elevator at floor %d.\n", t, lift.people_in_elevator[i]->id, lift.current_floor);
                    lift.people_in_elevator[i] = NULL;
                    ++people_removed_from_elevator;
                }
            }
            
            // shift the remaining people in the elevator
            int j=0;
            for(int i=0; i<lift.current_capacity; ++i) {
                if(lift.people_in_elevator[i] != NULL) {
                    lift.people_in_elevator[j] = lift.people_in_elevator[i];
                    ++j;
                }
            }
            while(j < ELEVATOR_CAPACITY) {
                lift.people_in_elevator[j] = NULL;
                ++j;
            }
            
            lift.current_capacity -= people_removed_from_elevator;
            printf("Time: %d seconds. Elevator has arrived at floor %d. %d people have exited the elevator. %d people are still in the elevator.\n",
                   t, lift.current_floor, people_removed_from_elevator, lift.current_capacity);
        }
        else { // elevator is empty and no one is waiting, move the elevator to a random floor
            
            int destination_floor = (rand() % FLOOR_COUNT) + 1;
            while(destination_floor == lift.current_floor) {
                destination_floor = (rand() % FLOOR_COUNT) + 1;
            }
            
            if(destination_floor > lift.current_floor) {
                lift.current_direction = 1;
                printf("Time: %d seconds. Elevator is moving up from floor %d to floor %d.\n",
                       t, lift.current_floor, destination_floor);
            }
            else {
                lift.current_direction = -1;
                printf("Time: %d seconds. Elevator is moving down from floor %d to floor %d.\n",
                       t, lift.current_floor, destination_floor);
            }
            
            // update the elevator's current floor
            lift.current_floor = destination_floor;
            usleep(500000); // sleep for half a second to simulate elevator travel time
        }
    }
    
    return 0;
}