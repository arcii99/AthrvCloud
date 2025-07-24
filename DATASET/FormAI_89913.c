//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ELEVATOR 3
#define MAX_FLOOR 10

typedef struct {
    int floor;
    int status; // 0=idle, 1=up, 2=down
    int direction; // 1=up, -1=down
    int request[MAX_FLOOR];
    int current_index;
} Elevator;

typedef struct {
    int floor;
    int destination_floor;
} Request;

Elevator elevators[MAX_ELEVATOR];

void init_elevators();
int get_elevator();
int elevator_move(Elevator* elevator);
int handle_request(Request request);

int main()
{
    init_elevators();
    
    while(1) {
        Request request;
        printf("\nEnter the floor: ");
        scanf("%d", &request.floor);
        printf("Enter the destination floor: ");
        scanf("%d", &request.destination_floor);
        handle_request(request);
    }
    return 0;
}


// Function to initialize elevators
void init_elevators()
{
    int i,j;
    for(i=0;i<MAX_ELEVATOR;i++) {
        elevators[i].floor = 0; // ground floor
        elevators[i].status = 0; // idle
        elevators[i].direction = 1; // up
        elevators[i].current_index = 0;
        
        for(j=0;j<MAX_FLOOR;j++) {
            elevators[i].request[j] = 0;
        }
    }
}


// Function to get the elevator to handle the request
int get_elevator(Request request)
{
    int i,j;
    int minsteps = MAX_FLOOR + 1;
    int minindex = -1;
    int steps;
    
    for(i=0;i<MAX_ELEVATOR;i++) {
        if(elevators[i].status == 0) {
            return i;
        }
    }
    
    for(i=0;i<MAX_ELEVATOR;i++) {
        steps = abs(request.floor - elevators[i].floor);
        if(steps < minsteps && elevators[i].direction == request.destination_floor - request.floor) {
            minsteps = steps;
            minindex = i;
        }
    }
    
    for(i=0;i<MAX_ELEVATOR;i++) {
        steps = abs(request.floor - elevators[i].floor);
        if(steps < minsteps && elevators[i].status == 0) {
            minsteps = steps;
            minindex = i;
        }
    }
    
    return minindex;
}


// Function to handle request and assign to elevator
int handle_request(Request request)
{
    int i,elevator_id;
    elevator_id = get_elevator(request);
    elevators[elevator_id].request[request.floor] = 1;

    if(elevators[elevator_id].status == 0) {
        elevators[elevator_id].direction = 1;
        if(request.floor < elevators[elevator_id].floor) {
            elevators[elevator_id].direction = -1;
        }
    }

    if(elevator_move(&elevators[elevator_id]) == 0) {
        elevators[elevator_id].status = 0; // idle
    }
}


// Function to move the elevator
int elevator_move(Elevator* elevator)
{
    int i,j;
    int temp[MAX_FLOOR];
    int total_requests = 0;
    
    for(i=0;i<MAX_FLOOR;i++) {
        temp[i] = elevator->request[i];
    }
    
    for(i=0;i<MAX_FLOOR;i++) {
        if(temp[i] == 1) {
            total_requests++;
        }
    }
    
    if(total_requests == 0) {
        return 0;
    }
    
    if(elevator->status == 0) {
        elevator->status = elevator->direction;
    }
    
    elevator->floor += elevator->direction;
    
    printf("\nElevator %d is moving in direction %d and is at floor %d", (int)elevator-(int)elevators+1, elevator->direction, elevator->floor);
    
    if(elevator->floor == 0) {
        elevator->direction = 1; // can only go up
    } else if(elevator->floor == MAX_FLOOR-1) {
        elevator->direction = -1; // can only go down
    }
    
    if(elevator->request[elevator->floor] == 1) {
        printf("\nElevator %d is stopping at floor %d to drop off a passenger", (int)elevator-(int)elevators+1, elevator->floor);
        elevator->request[elevator->floor] = 0;
        
        for(i=elevator->current_index+1;i<MAX_FLOOR;i++) {
            if(elevator->request[i] == 1) {
                if(i > elevator->floor) {
                    elevator->direction = 1;
                } else {
                    elevator->direction = -1;
                }
                elevator->current_index = i;
                break;
            }
        }
    }
    
    for(i=0;i<MAX_ELEVATOR;i++) {
        for(j=0;j<MAX_FLOOR;j++) {
            if(elevators[i].request[j] == 1) {
                return 1; // continue to handle requests
            }
        }
    }
    
    return 0; // no more requests
}