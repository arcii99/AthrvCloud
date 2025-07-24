//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

typedef enum {
    IDLE,
    UP,
    DOWN
} State;

typedef struct {
    int current_floor;
    State state;
    int destinations[MAX_FLOORS];
    int num_destinations;
} Elevator;

typedef struct {
    int current_floor;
    int destination;
} Person;

void print_elevator(Elevator* elevator) {
    printf("Current floor: %d\n", elevator->current_floor);
    printf("State: ");
    switch(elevator->state) {
        case IDLE:
            printf("IDLE\n");
            break;
        case UP:
            printf("UP\n");
            break;
        case DOWN:
            printf("DOWN\n");
            break;
    }
    printf("Destinations: ");
    for(int i=0; i<elevator->num_destinations; i++) {
        printf("%d ", elevator->destinations[i]);
    }
    printf("\n");
}

void print_people(Person* people, int num_people) {
    printf("People: ");
    for(int i=0; i<num_people; i++) {
        printf("(%d, %d) ", people[i].current_floor, people[i].destination);
    }
    printf("\n");
}

int main() {
    Elevator elevator = {0, IDLE, {0}, 0};
    Person people[MAX_PEOPLE] = {{0, 4}, {2, 8}, {3, 1}};
    int num_people = 3;

    // Simulation loop
    while(1) {
        // Print current state
        printf("-------\n");
        print_elevator(&elevator);
        print_people(people, num_people);

        // Check if elevator needs to change direction
        if(elevator.num_destinations == 0 || elevator.current_floor == elevator.destinations[elevator.num_destinations-1]) {
            // Elevator is idle
            elevator.state = IDLE;
        } else if(elevator.state == UP && elevator.current_floor == elevator.destinations[elevator.num_destinations-1]) {
            // Elevator has reached highest floor
            elevator.state = DOWN;
        } else if(elevator.state == DOWN && elevator.current_floor == elevator.destinations[0]) {
            // Elevator has reached lowest floor
            elevator.state = UP;
        }

        // Update elevator's current floor
        switch(elevator.state) {
            case UP:
                elevator.current_floor++;
                break;
            case DOWN:
                elevator.current_floor--;
                break;
        }

        // Check if anyone needs to get off the elevator
        int count = 0;
        for(int i=0; i<num_people; i++) {
            if(people[i].destination == elevator.current_floor) {
                printf("Person at floor %d gets off at floor %d\n", people[i].current_floor, elevator.current_floor);
                count++;
            }
        }

        // Remove people who got off from elevator's destinations
        int new_index = 0;
        for(int i=0; i<elevator.num_destinations; i++) {
            if(elevator.destinations[i] != elevator.current_floor) {
                elevator.destinations[new_index++] = elevator.destinations[i];
            }
        }
        elevator.num_destinations = new_index;

        // Check if elevator is full
        if(elevator.num_destinations == MAX_FLOORS || count == MAX_PEOPLE) {
            continue;
        }

        // Check if anyone wants to get on the elevator
        for(int i=0; i<num_people; i++) {
            if(people[i].current_floor == elevator.current_floor && elevator.num_destinations < MAX_FLOORS) {
                printf("Person at floor %d gets on elevator\n", people[i].current_floor);
                elevator.destinations[elevator.num_destinations++] = people[i].destination;
            }
        }

        // Update elevator's state if necessary
        if(elevator.num_destinations > 0) {
            if(elevator.current_floor < elevator.destinations[0]) {
                elevator.state = UP;
            } else if(elevator.current_floor > elevator.destinations[elevator.num_destinations-1]) {
                elevator.state = DOWN;
            }
        }
    }

    return 0;
}