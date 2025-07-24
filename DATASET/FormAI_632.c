//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FLOORS 10 //total number of floors
#define MAX_PEOPLE 20 //maximum number of people in the elevator at once

//struct to represent a floor
typedef struct floor {
    int number; //floor number
    int queue[FLOORS]; //queue of people waiting
    int queue_length; //length of queue
} Floor;

//struct to represent a person waiting on a floor
typedef struct person {
    int floor; //floor number they are waiting on
    int destination; //floor number they want to go to
} Person;

//struct to represent an elevator
typedef struct elevator {
    int current_floor; //current floor the elevator is on
    bool moving_up; //true if elevator is moving up, false if moving down
    int occupancy; //number of people currently in the elevator
    int destinations[MAX_PEOPLE]; //list of floor numbers that people in the elevator want to go to
    bool pickup_requests[FLOORS]; //list of floors where people want to get on
} Elevator;

//function prototypes
void print_floor(Floor f);
void print_elevator(Elevator e);
Person create_person(int current_floor);
void request_pickup(Elevator* e, int floor);
void request_destination(Elevator* e, int destination);
void move_elevator(Elevator* e);
void print_status(Floor* floors, Elevator* e);

int main() {
    //initialize floors
    Floor floors[FLOORS];
    for (int i = 0; i < FLOORS; i++) {
        floors[i].number = i+1;
        floors[i].queue_length = 0;
        for (int j = 0; j < FLOORS; j++) {
            floors[i].queue[j] = 0;
        }
    }

    //initialize elevator
    Elevator elevator;
    elevator.current_floor = 1;
    elevator.moving_up = true;
    elevator.occupancy = 0;
    for (int i = 0; i < MAX_PEOPLE; i++) {
        elevator.destinations[i] = -1;
    }
    for (int i = 0; i < FLOORS; i++) {
        elevator.pickup_requests[i] = false;
    }

    //run simulation
    for (int i = 0; i < 20; i++) {
        //randomly generate new people waiting on floors
        for (int j = 0; j < FLOORS; j++) {
            int r = rand() % 10;
            if (r < 4 && floors[j].queue_length < MAX_PEOPLE) { //25% chance of new person
                Person p = create_person(j+1);
                floors[j].queue[floors[j].queue_length] = p.destination;
                floors[j].queue_length++;
            }
        }

        //check for pickup requests and add people to elevator
        for (int j = 0; j < FLOORS; j++) {
            if (elevator.pickup_requests[j] && elevator.occupancy < MAX_PEOPLE) {
                elevator.pickup_requests[j] = false;
                for (int k = 0; k < floors[j].queue_length && elevator.occupancy < MAX_PEOPLE; k++) {
                    if (floors[j].queue[k] > elevator.current_floor && elevator.moving_up) {
                        request_destination(&elevator, floors[j].queue[k]);
                        floors[j].queue[k] = 0;
                        floors[j].queue_length--;
                        elevator.occupancy++;
                    } else if (floors[j].queue[k] < elevator.current_floor && !elevator.moving_up) {
                        request_destination(&elevator, floors[j].queue[k]);
                        floors[j].queue[k] = 0;
                        floors[j].queue_length--;
                        elevator.occupancy++;
                    }
                }
            }
        }

        //check for destination requests and remove people from elevator
        for (int j = 0; j < MAX_PEOPLE; ) {
            if (elevator.destinations[j] == elevator.current_floor) {
                for (int k = j; k+1 < MAX_PEOPLE; k++) {
                    elevator.destinations[k] = elevator.destinations[k+1];
                }
                elevator.destinations[MAX_PEOPLE-1] = -1;
                elevator.occupancy--;
            } else {
                j++;
            }
        }

        //move the elevator
        move_elevator(&elevator);

        //print current status
        print_status(floors, &elevator);
    }

    return 0;
}

//function to print out information about a floor
void print_floor(Floor f) {
    printf("Floor %d: ", f.number);
    if (f.queue_length == 0) {
        printf("No one waiting\n");
    } else {
        printf("Waiting: ");
        for (int i = 0; i < f.queue_length; i++) {
            printf("%d ", f.queue[i]);
        }
        printf("\n");
    }
}

//function to print out information about the elevator
void print_elevator(Elevator e) {
    printf("Elevator (floor %d, %d occupants): ", e.current_floor, e.occupancy);
    if (e.occupancy == 0) {
        printf("Empty\n");
    } else {
        printf("Destinations: ");
        for (int i = 0; i < MAX_PEOPLE; i++) {
            if (e.destinations[i] != -1) {
                printf("%d ", e.destinations[i]);
            } else {
                break;
            }
        }
        printf("\n");
    }
}

//function to create a new person waiting on a floor
Person create_person(int current_floor) {
    Person p;
    p.floor = current_floor;
    do {
        p.destination = rand() % FLOORS + 1;
    } while (p.destination == p.floor);
    return p;
}

//function to add a pickup request for the elevator
void request_pickup(Elevator* e, int floor) {
    e->pickup_requests[floor-1] = true;
}

//function to add a destination request for the elevator
void request_destination(Elevator* e, int destination) {
    for (int i = 0; i < MAX_PEOPLE; i++) {
        if (e->destinations[i] == -1) {
            e->destinations[i] = destination;
            break;
        }
    }
}

//function to move the elevator
void move_elevator(Elevator* e) {
    if (e->moving_up) {
        e->current_floor++;
        if (e->current_floor == FLOORS) {
            e->moving_up = false;
        }
    } else {
        e->current_floor--;
        if (e->current_floor == 1) {
            e->moving_up = true;
        }
    }
}

//function to print out the status of all floors and the elevator
void print_status(Floor* floors, Elevator* e) {
    for (int i = 0; i < FLOORS; i++) {
        print_floor(floors[i]);
    }
    print_elevator(*e);
    printf("\n");
}