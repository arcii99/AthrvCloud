//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void recursive_elevator(int current_floor, int destination_floor){
    if(current_floor == destination_floor){
        printf("Elevator has reached the destination floor %d\n", current_floor);
        return;
    } else if(current_floor < destination_floor){
        printf("Elevator is going up from floor %d to floor %d\n", current_floor, current_floor+1);
        recursive_elevator(current_floor+1, destination_floor);
    } else if(current_floor > destination_floor){
        printf("Elevator is going down from floor %d to floor %d\n", current_floor, current_floor-1);
        recursive_elevator(current_floor-1, destination_floor);
    }
}

int main(){
    srand(time(0)); // seed the random number generator

    int current_floor = rand() % 10 + 1; // set current floor between 1 and 10
    int destination_floor = rand() % 10 + 1; // set destination floor between 1 and 10

    printf("Elevator is currently on floor %d\n", current_floor);
    printf("Elevator is going to floor %d\n", destination_floor);

    recursive_elevator(current_floor, destination_floor);

    return 0;
}