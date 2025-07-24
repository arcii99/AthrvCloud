//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include<stdio.h>

int main()
{
    int floors, current_floor = 1, destination_floor, choice;
    scanf("%d", &floors); //taking input for number of floors in the building
  
    printf("Elevator is at floor number %d\n", current_floor);

    do{
        printf("Enter the destination floor\n");
        scanf("%d", &destination_floor); //taking input for destination floor
        if(destination_floor > floors){
            printf("Invalid floor number\n");
            continue; //if destination floor is greater than the number of floors in the building, skip this iteration of the loop and continue with the next iteration
        }
        if(destination_floor == current_floor){
            printf("Elevator is already at floor number %d\n", current_floor);
            continue; //if destination floor is same as current floor, skip this iteration of the loop and continue with the next iteration
        }
        if(destination_floor < current_floor){
            printf("Elevator is currently going down from floor number %d to floor number %d\n", current_floor, destination_floor);
            while(current_floor != destination_floor){
                current_floor--;
                printf("Elevator is now at floor number %d\n", current_floor);
            }
            printf("Elevator has reached the destination floor number %d\n", current_floor);
            continue; //if destination floor is below the current floor, skip the next two conditions and continue with the next iteration
        }
        if(destination_floor > current_floor){
            printf("Elevator is currently going up from floor number %d to floor number %d\n", current_floor, destination_floor);
            while(current_floor != destination_floor){
                current_floor++;
                printf("Elevator is now at floor number %d\n", current_floor);
            }
            printf("Elevator has reached the destination floor number %d\n", current_floor);
        }
        printf("Do you want to continue(1: Yes / 0: No)? ");
        scanf("%d", &choice); //taking input for continuing or stopping the simulation
    }while(choice != 0);

    printf("Simulation ended\n");
    return 0;
}