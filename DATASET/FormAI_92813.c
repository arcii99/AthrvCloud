//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: calm
#include<stdio.h>
#include<stdlib.h>

int main(){
    int current_floor=1, target_floor, elevator_status=0;
    //elevator_status=0 for idle, 1 for moving up and 2 for moving down
    
    //display the current floor
    printf("You are currently on floor %d.\n", current_floor);
    
    //ask user for target floor
    printf("Enter the floor you want to go to: ");
    scanf("%d", &target_floor);
    
    //check if target floor is greater or lesser than current floor
    if(target_floor>current_floor){
        printf("\nThe elevator is moving up.");
        elevator_status=1;
    }
    else if(target_floor<current_floor){
        printf("\nThe elevator is moving down.");
        elevator_status=2;
    }
    else if(target_floor==current_floor){
        printf("\nYou are already on floor %d.", current_floor);
        return 0;
    }
    
    //simulate elevator movement
    while(current_floor!=target_floor){
        if(elevator_status==1){
            current_floor++;
        }
        else if(elevator_status==2){
            current_floor--;
        }
        printf("\nElevator is on floor %d.", current_floor);
    }
    
    //reached target floor
    printf("\nYou have reached floor %d.", current_floor);
    return 0;
}