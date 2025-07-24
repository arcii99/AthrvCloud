//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 10

typedef struct{
    int current_floor;
    int destination_floor;
    bool in_elevator;
    bool is_busy;
} person;

typedef struct {
    int current_floor;
    int destination_floor;
    bool is_busy;
} elevator;

int main() {
    person people[NUM_FLOORS];
    elevator elevator1;
    elevator1.current_floor = 1; //Elevator starts at the first floor
    elevator1.destination_floor = 1; //Elevator has no destination initially
    elevator1.is_busy = false;
    
    for(int i = 0; i < NUM_FLOORS; i++) {
        people[i].current_floor = i+1; //People are initially at their own floors
        people[i].in_elevator = false;
        people[i].is_busy = false;
    }
    
    int num_people_waiting = 0;
    int num_people_in_elevator = 0;
    int current_time = 0;
    
    while(current_time < 100) { //Run simulation for 100 seconds
        //Add random people to different floors
        for(int i = 0; i < NUM_FLOORS; i++) {
            if(rand()%2 == 0) {
                people[i].is_busy = true;
                people[i].destination_floor = (rand()%(NUM_FLOORS-1))+1;
                num_people_waiting++;
            }
        }
        
        //Elevator moves to destination floor
        if(elevator1.is_busy) {
            if(elevator1.current_floor > elevator1.destination_floor)
                elevator1.current_floor--;
            else if(elevator1.current_floor < elevator1.destination_floor)
                elevator1.current_floor++;
            else {
                elevator1.is_busy = false;
                num_people_in_elevator = 0;
            }
        }
        else { //Elevator is not busy, pick up people
            for(int i = 0; i < NUM_FLOORS; i++) {
                if(num_people_in_elevator < ELEVATOR_CAPACITY && people[i].is_busy && people[i].current_floor == elevator1.current_floor) {
                    people[i].in_elevator = true;
                    people[i].is_busy = false;
                    num_people_waiting--;
                    num_people_in_elevator++;
                }
            }
            //Set new destination floor
            if(num_people_in_elevator > 0) {
                int min_distance = NUM_FLOORS;
                for(int i = 0; i < NUM_FLOORS; i++) {
                    if(!people[i].in_elevator) {
                        int distance = abs(people[i].destination_floor - elevator1.current_floor);
                        if(distance < min_distance) {
                            elevator1.destination_floor = people[i].destination_floor;
                            min_distance = distance;
                        }
                    }
                }
                elevator1.is_busy = true;
            }
        }
        
        //Print current state of simulation
        printf("TIME: %d\n", current_time);
        printf("ELEVATOR AT FLOOR: %d\n", elevator1.current_floor);
        printf("DESTINATION FLOOR: %d\n", elevator1.destination_floor);
        printf("NUMBER OF PEOPLE WAITING: %d\n", num_people_waiting);
        printf("NUMBER OF PEOPLE INSIDE ELEVATOR: %d\n", num_people_in_elevator);
        printf("-----------------------------------\n");
        
        current_time++;
    }
    
    return 0;
}