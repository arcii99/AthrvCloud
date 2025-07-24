//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_ELEVATORS 3
#define NUM_OF_FLOORS 10

int elevators[NUM_OF_ELEVATORS] = {0}; // initializing all elevators to the ground floor (0)
int floors[NUM_OF_FLOORS] = {0}; // initializing all floors to 0 (meaning no one is waiting)

// function declarations
void displayElevators();
void displayFloors();
int isFull(int elevator);
void moveElevator(int elevator, int floor);
int isAvailable(int floor);
void addPersonToFloor(int floor);

int main(){
    int i, j, selected_elevator, selected_floor;
    
    // simulation loop
    for(i=0; i<50; i++){
        printf("Time step: %d\n", i+1);
        displayElevators();
        displayFloors();

        // check if anyone is waiting on a floor
        for(j=0; j<NUM_OF_FLOORS; j++){
            if(floors[j] > 0){ // someone is waiting
                // check if an elevator is available
                if(isAvailable(j)){
                    // select the available elevator and set its target floor 
                    for(int k=0; k<NUM_OF_ELEVATORS; k++){
                        if(elevators[k] == j){
                            break; // elevator is already on the floor, so no need to set the target floor again
                        }
                        if(elevators[k] == 0){ // elevator is available
                            selected_elevator = k;
                            elevators[k] = j;
                            printf("\nElevator %d is moving to Floor %d\n\n", k+1, j+1);

                            // move the elevator to the floor
                            while(elevators[k] != j){
                                if(elevators[k] < j){
                                    moveElevator(k, elevators[k]+1);
                                }
                                else{
                                    moveElevator(k, elevators[k]-1);
                                }
                            }
                            // elevator has arrived at the floor
                            printf("Elevator %d has arrived at Floor %d\n\n", k+1, j+1); 

                            // remove person from the floor and add them to the elevator
                            elevators[k] = -floors[j];
                            floors[j] = 0;

                            break; // found an available elevator and set its target floor, so break out of loop
                        }
                    }
                }
                else{
                    addPersonToFloor(j);
                }
            }
        }

        // move each occupied elevator by 1 floor if possible
        for(j=0; j<NUM_OF_ELEVATORS; j++){
            if(elevators[j] != 0){
                if(elevators[j] < NUM_OF_FLOORS && elevators[j] > 0){
                    moveElevator(j, elevators[j]+1);
                }
                else{
                    moveElevator(j, elevators[j]-1);
                }
            }
        }
    }

    return 0;
}

// function definitions
void displayElevators(){
    printf("Elevators: [ ");
    for(int i=0; i<NUM_OF_ELEVATORS; i++){
        printf("%d ", elevators[i]);
    }
    printf("]\n");
}

void displayFloors(){
    printf("Floors: [ ");
    for(int i=0; i<NUM_OF_FLOORS; i++){
        printf("%d ", floors[i]);
    }
    printf("]\n");
}

int isFull(int elevator){
    int count = 0;
    for(int i=0; i<NUM_OF_ELEVATORS; i++){
        if(elevators[i] == elevator+1 || elevators[i] == -elevator-1){ // check if someone is going to or from this floor
            count++;
        }
    }
    return count >= 5 ? 1 : 0;
}

void moveElevator(int elevator, int floor){
    if(floor >= 0 && floor < NUM_OF_FLOORS){
        if(elevators[elevator] < floor){
            printf("Elevator %d is going up to Floor %d\n", elevator+1, floor+1); 
        }
        else{
            printf("Elevator %d is going down to Floor %d\n", elevator+1, floor+1);
        }
        elevators[elevator] = floor;
    }
}

int isAvailable(int floor){
    for(int i=0; i<NUM_OF_ELEVATORS; i++){
        if(elevators[i] == floor || elevators[i] == 0){ // check if elevator is already on the floor or available 
            if(!isFull(i)){
                return 1;
            }
        }
    }
    return 0;
}

void addPersonToFloor(int floor){
    for(int i=1; i<=5; i++){
        if(floors[floor+i] == 0 && floor+i < NUM_OF_FLOORS){
            floors[floor+i] = i;
            printf("Person %d has arrived on Floor %d and is waiting\n", i, floor+i+1);
            break;
        }
        if(floors[floor-i] == 0 && floor-i >= 0){
            floors[floor-i] = i;
            printf("Person %d has arrived on Floor %d and is waiting\n", i, floor-i+1);
            break;
        }
    }
}