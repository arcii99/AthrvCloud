//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: grateful
#include<stdio.h>

/* Defining the structure for elevator */
typedef struct elev {
    int current_floor, destination_floor, direction;
}Elevator;

/* Defining the structure for person */
typedef struct per {
    int current_floor, destination_floor;
}Person;

/* Function to move the Elevator */
void move_elevator(Elevator *elevator, Person *person) {
    if(elevator->current_floor == person->current_floor && elevator->destination_floor == person->destination_floor) {
        printf("\n\nElevator Opening its doors on floor %d...\nTaking person to floor %d...\n", elevator->current_floor, elevator->destination_floor);
    }
    else if(elevator->current_floor == person->current_floor && elevator->destination_floor < person->destination_floor) {
        printf("\n\nElevator Opening its doors on floor %d...\nTaking person to floor %d...\n", elevator->current_floor, elevator->destination_floor);
    }
    else if(elevator->current_floor == person->current_floor && elevator->destination_floor > person->destination_floor) {
        printf("\n\nElevator Opening its doors on floor %d...\nTaking person to floor %d...\n", elevator->current_floor, elevator->destination_floor);
    }
    else {
        printf("\n\nElevator Moving from floor %d to floor %d...\n", elevator->current_floor, person->current_floor);
        elevator->current_floor = person->current_floor;
        printf("\n\nElevator Opening its doors on floor %d...\nTaking person to floor %d...\n", elevator->current_floor, elevator->destination_floor);
    }
}

int main() {
    Elevator elevator = {1, 5, 1};
    Person person1 = {2, 4};
    Person person2 = {5, 1};
    
    /* Moving the elevator to pick up the first person */
    move_elevator(&elevator, &person1);
    
    /* Changing the direction of elevator as per the second person */
    elevator.direction = -1;
    
    /* Moving the elevator to pick up the second person */
    move_elevator(&elevator, &person2);

    return 0;
}