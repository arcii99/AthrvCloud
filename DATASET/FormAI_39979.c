//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Define the capacity and floors of the elevator
#define CAPACITY 10
#define FLOORS 10

//Define the struct for the elevator 
typedef struct{
    int current_floor;
    int capacity;
    int direction; //0 for up, 1 for down
    int stops[FLOORS];
} elevator;

//Function to initialize elevator values
void init_elevator(elevator* e){
    e->current_floor = 0;
    e->capacity = 0;
    e->direction = 0;
    for(int i=0; i<FLOORS; i++){
        e->stops[i] = 0;
    }
}

//Function to randomly generate passenger requests
void generate_requests(int requests[FLOORS]){
    srand(time(0)); //Seed the random number generator
    for(int i=0; i<FLOORS; i++){
        requests[i] = rand() % CAPACITY + 1; //Generate a random number between 1 and the elevator capacity for each floor
    }
}

//Function to print the elevator status
void print_status(elevator e){
    printf("Current floor: %d\n", e.current_floor);
    printf("Direction: %s\n", e.direction == 0 ? "up" : "down");
    printf("Capacity: %d\n", e.capacity);
    printf("Stops: ");
    for(int i=0; i<FLOORS; i++){
        if(e.stops[i]){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    elevator e;
    int requests[FLOORS];
    
    init_elevator(&e); //Initialize the elevator
    
    while(1){
        generate_requests(requests); //Generate passenger requests
        
        //Check if there are any passengers waiting on the current floor and add them to the elevator
        if(requests[e.current_floor] > 0 && e.capacity < CAPACITY){
            int num_added = requests[e.current_floor];
            e.capacity += num_added;
            requests[e.current_floor] = 0;
            printf("%d passengers added to elevator\n", num_added);
        }
        
        //Check if any passengers need to be dropped off at the current floor and remove them from the elevator
        if(e.stops[e.current_floor]){
            int num_removed = e.stops[e.current_floor];
            e.capacity -= num_removed;
            e.stops[e.current_floor] = 0;
            printf("%d passengers removed from elevator\n", num_removed);
        }
        
        //Calculate the next floor for the elevator
        int next_floor;
        if(e.direction == 0){ //Going up
            next_floor = e.current_floor + 1;
            if(next_floor == FLOORS){ //Change direction if at the top floor
                e.direction = 1;
                next_floor = FLOORS - 2;
            }
        } else { //Going down
            next_floor = e.current_floor - 1;
            if(next_floor == -1){ //Change direction if at the bottom floor
                e.direction = 0;
                next_floor = 1;
            }
        }
        
        //Check if any passengers need to be added to the elevator at the next floor and add them
        if(requests[next_floor] > 0 && e.capacity < CAPACITY){
            int num_added = requests[next_floor];
            e.capacity += num_added;
            requests[next_floor] = 0;
            printf("%d passengers added to elevator\n", num_added);
        }
        
        //Check if the elevator needs to stop at the next floor and add the stop to the list if necessary
        if(e.stops[next_floor] || requests[next_floor] > 0){
            e.stops[next_floor] = 1;
            printf("Elevator will stop at floor %d\n", next_floor);
        }
        
        //Update the elevator's current floor
        e.current_floor = next_floor;
        
        //Print the elevator status
        printf("\nElevator status:\n");
        print_status(e);
        
        //Wait for a moment before proceeding to the next iteration
        printf("Press any key to continue...\n");
        getchar();
    }
    
    return 0;
}