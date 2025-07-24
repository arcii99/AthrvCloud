//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Sherlock Holmes
#include<stdio.h>
#include<time.h>

int main(){
    
    int current_floor = 1;
    int dest_floor = 1;
    int elevator_speed = 5;
    
    printf("Welcome to the Elevator Simulation Program!\n\n");
    printf("You are currently on the ground floor.\n\n");
    
    while(1){
        printf("Which floor would you like to go to? (1-10)\n");
        scanf("%d", &dest_floor);
        
        if(dest_floor < 1 || dest_floor > 10){
            printf("Invalid floor selection. Please enter a number between 1 and 10.\n\n");
        }
        else{
            break;
        }
    }
    
    printf("You have selected floor %d.\n\n", dest_floor);
    printf("The elevator is moving...\n\n");
    
    int distance = dest_floor - current_floor;
    int travel_time = distance * elevator_speed;
    
    printf("Estimated travel time: %d seconds.\n\n", travel_time);
    printf("Please wait while the elevator arrives at your floor.\n\n");
    
    time_t start = time(NULL);
    while(time(NULL) - start < travel_time){
        printf(".");
    }
    printf("\n\nYou have arrived at your destination on floor %d.\n\n", dest_floor);
    printf("Thank you for using our Elevator Simulation Program!\n");
    
    return 0;
}