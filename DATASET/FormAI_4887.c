//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5
#define MAX_WEIGHT 500

struct passenger {
    int destination_floor;
    int weight;
};

struct floor {
    int num_passengers;
    struct passenger passengers[MAX_PASSENGERS];
};

struct elevator {
    int current_floor;
    int direction; // 1 for up, -1 for down, 0 for stationary
    int num_passengers;
    int max_passengers;
    struct passenger passengers[MAX_PASSENGERS];
};

void initialize_floors(struct floor floors[MAX_FLOORS]) {
    for (int i = 0; i < MAX_FLOORS; i++) {
        floors[i].num_passengers = 0;
    }
}

void initialize_elevator(struct elevator *elevator) {
    elevator->current_floor = 0;
    elevator->direction = 1;
    elevator->num_passengers = 0;
    elevator->max_passengers = MAX_PASSENGERS;
}

void add_passenger_to_floor(struct floor *floor, struct passenger passenger) {
    if (floor->num_passengers < MAX_PASSENGERS) {
        floor->passengers[floor->num_passengers] = passenger;
        floor->num_passengers++;
    }
}

void add_passenger_to_elevator(struct elevator *elevator, struct passenger passenger) {
    if (elevator->num_passengers < elevator->max_passengers) {
        elevator->passengers[elevator->num_passengers] = passenger;
        elevator->num_passengers++;
    }
}

void remove_passenger_from_floor(struct floor *floor, int index) {
    for (int i = index; i < floor->num_passengers - 1; i++) {
        floor->passengers[i] = floor->passengers[i+1];
    }
    floor->num_passengers--;
}

void remove_passenger_from_elevator(struct elevator *elevator, int index) {
    for (int i = index; i < elevator->num_passengers - 1; i++) {
        elevator->passengers[i] = elevator->passengers[i+1];
    }
    elevator->num_passengers--;
}

int calculate_total_weight(struct elevator elevator) {
    int total_weight = 0;
    for (int i = 0; i < elevator.num_passengers; i++) {
        total_weight += elevator.passengers[i].weight;
    }
    return total_weight;
}

int select_floor_to_visit(struct elevator elevator, struct floor floors[MAX_FLOORS]) {
    for (int i = 0; i < MAX_FLOORS; i++) {
        if (floors[i].num_passengers > 0 && elevator.direction == 1 && i > elevator.current_floor) {
            return i;
        } else if (floors[i].num_passengers > 0 && elevator.direction == -1 && i < elevator.current_floor) {
            return i;
        }
    }
    return -1;
}

void move_elevator(struct elevator *elevator, struct floor floors[MAX_FLOORS]) {
    int destination_floor = select_floor_to_visit(*elevator, floors);
    if (destination_floor == -1) {
        elevator->direction = 0;
    } else {
        if (destination_floor > elevator->current_floor) {
            elevator->direction = 1;
            printf("Elevator moving from floor %d to floor %d (going up)\n", elevator->current_floor, destination_floor);
        } else if (destination_floor < elevator->current_floor) {
            elevator->direction = -1;
            printf("Elevator moving from floor %d to floor %d (going down)\n", elevator->current_floor, destination_floor);
        } else {
            printf("Elevator on floor %d\n", destination_floor);
        }

        while (elevator->current_floor != destination_floor) {
            elevator->current_floor += elevator->direction;
            printf("Elevator on floor %d\n", elevator->current_floor);

            // If elevator is on a floor with passengers, let passengers in
            if (elevator->current_floor == destination_floor) {
                int num_passengers_to_add = floors[destination_floor].num_passengers;
                for (int i = 0; i < num_passengers_to_add; i++) {
                    if (calculate_total_weight(*elevator) + floors[destination_floor].passengers[i].weight <= MAX_WEIGHT) {
                        add_passenger_to_elevator(elevator, floors[destination_floor].passengers[i]);
                        printf("Passenger with weight %d added to elevator\n", floors[destination_floor].passengers[i].weight);
                        remove_passenger_from_floor(&floors[destination_floor], i);
                        num_passengers_to_add--;
                    } else {
                        printf("Elevator is at capacity and cannot add any more passengers\n");
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    struct floor floors[MAX_FLOORS];
    struct elevator elevator;
    int num_iterations = 10;

    srand(time(NULL));

    initialize_floors(floors);
    initialize_elevator(&elevator);

    // Add random passengers to random floors
    for (int i = 0; i < 20; i++) {
        struct passenger passenger;
        passenger.destination_floor = rand() % MAX_FLOORS;
        passenger.weight = rand() % 80 + 50;
        add_passenger_to_floor(&floors[rand() % MAX_FLOORS], passenger);
    }

    // Move elevator for a certain number of iterations
    for (int i = 0; i < num_iterations; i++) {
        move_elevator(&elevator, floors);
    }

    return 0;
}