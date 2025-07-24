//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void elevator(int currFloor, int destFloor){
    
    printf("Elevator at floor %d\n", currFloor);
    
    //base case
    if(currFloor == destFloor){
        printf("Elevator has reached destination floor %d\n", destFloor);
        return;
    }
    
    //recursive case
    if(currFloor < destFloor){
        elevator(currFloor + 1, destFloor);
    } else {
        elevator(currFloor - 1, destFloor);
    }
}

int main(){
    int currFloor, destFloor;
    
    printf("Enter current floor: ");
    scanf("%d", &currFloor);
    printf("Enter destination floor: ");
    scanf("%d", &destFloor);
    
    elevator(currFloor, destFloor);
    
    return 0;
}