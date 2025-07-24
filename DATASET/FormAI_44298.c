//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

typedef struct{
    int floor;
    bool is_moving;
    bool is_door_open;
} elevator;

int main() {
    srand(time(NULL));

    elevator elevators[MAX_ELEVATORS];
    for(int i = 0; i < MAX_ELEVATORS; i++){
        elevators[i].floor = 0;
        elevators[i].is_moving = false;
        elevators[i].is_door_open = true;
    }

    int people_waiting[MAX_FLOORS] = {0};

    int time_elapsed = 0;
    
    printf("Welcome to the Elevator Simulation!\n\n");

    while(true){
        // update each elevator
        for(int i = 0; i < MAX_ELEVATORS; i++){
            // if the elevator is moving, update its floor
            if(elevators[i].is_moving){
                if(elevators[i].floor == 0){
                    printf("Elevator %d has arrived at the ground floor!\n", i+1);
                }
                elevators[i].floor += elevators[i].is_moving ? (rand() % 2 ? 1 : -1) : 0;
                printf("Elevator %d is currently at floor %d\n", i+1, elevators[i].floor);
            }
            // if the elevator has reached its destination floor, open the doors
            if(elevators[i].floor == people_waiting[elevators[i].floor] && !elevators[i].is_door_open){
                printf("Elevator %d has arrived at floor %d\n", i+1, elevators[i].floor);
                elevators[i].is_moving = false;
                elevators[i].is_door_open = true;
            }
        }

        // check if anyone is waiting on a floor
        for(int i = 0; i < MAX_FLOORS; i++){
            if(people_waiting[i] > 0){
                printf("There %s currently %d person%s waiting on floor %d\n", people_waiting[i] == 1 ? "is" : "are", people_waiting[i], people_waiting[i] == 1 ? "" : "s", i);
            }
        }

        // check if any elevators are empty and can pick up more people
        for(int i = 0; i < MAX_ELEVATORS; i++){
            if(elevators[i].is_door_open && people_waiting[elevators[i].floor] > 0){
                printf("Elevator %d is picking up %d person%s from floor %d\n", i+1, people_waiting[elevators[i].floor], people_waiting[elevators[i].floor] == 1 ? "" : "s", elevators[i].floor);
                elevators[i].is_door_open = false;
                elevators[i].is_moving = true;
                people_waiting[elevators[i].floor] = 0;
            }
        }

        // add more people to a random floor
        if(rand() % 5 == 0){
            int floor = rand() % MAX_FLOORS;
            int num_people = rand() % 6 + 1;
            people_waiting[floor] += num_people;
            printf("%d person%s just arrived on floor %d\n", num_people, num_people == 1 ? "" : "s", floor);
        }

        // check if anyone is stuck
        if(time_elapsed > 0 && time_elapsed % 10 == 0){
            int num_stuck = 0;
            for(int i = 0; i < MAX_ELEVATORS; i++){
                if(elevators[i].is_moving){
                    printf("Elevator %d seems to be stuck between floors %d and %d!\n", i+1, elevators[i].floor, elevators[i].floor + (rand() % 2 ? 1 : -1));
                    num_stuck++;
                }
            }
            if(num_stuck == MAX_ELEVATORS){
                printf("All elevators are stuck! Simulation over.\n");
                break;
            }
        }

        time_elapsed++;

        printf("\n");
    }

    return 0;
}