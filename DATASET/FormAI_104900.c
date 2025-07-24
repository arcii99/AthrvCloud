//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define FLOORS 10
#define ELEVATORS 3

typedef struct {
    int floor;
    int num_passengers;
} Elevator;

typedef struct {
    int to_floor;
    int num_passengers;
} PassengerRequest;

typedef struct {
    PassengerRequest requests[FLOORS];
    int total_passengers_served;
    int total_passenger_wait_time;
    int max_passenger_wait_time;
    int num_passenger_requests;
} PassengerRequests;

typedef struct {
    Elevator elevators[ELEVATORS];
    PassengerRequests requests;
} ElevatorSystem;

int get_random_floor() {
    return rand() % FLOORS + 1;
}

void initialize_elevator_system(ElevatorSystem *sys) {
    for (int i = 0; i < ELEVATORS; i++) {
        sys->elevators[i].floor = 1;
        sys->elevators[i].num_passengers = 0;
    }

    for (int i = 0; i < FLOORS; i++) {
        sys->requests.requests[i].to_floor = 0;
        sys->requests.requests[i].num_passengers = 0;
    }

    sys->requests.total_passengers_served = 0;
    sys->requests.total_passenger_wait_time = 0;
    sys->requests.max_passenger_wait_time = 0;
    sys->requests.num_passenger_requests = 0;
}

void add_passenger_request(ElevatorSystem *sys, int from_floor, int to_floor) {
    sys->requests.num_passenger_requests++;
    sys->requests.requests[from_floor-1].to_floor = to_floor;
    sys->requests.requests[from_floor-1].num_passengers++;
}

void move_elevator(Elevator *elevator, int dest_floor) {
    if (elevator->floor < dest_floor) {
        printf("Moving elevator from floor %d to floor %d\n", elevator->floor, dest_floor);
        while (elevator->floor < dest_floor) {
            elevator->floor++;
        }
    } else if (elevator->floor > dest_floor) {
        printf("Moving elevator from floor %d to floor %d\n", elevator->floor, dest_floor);
        while (elevator->floor > dest_floor) {
            elevator->floor--;
        }
    }
}

void handle_request(ElevatorSystem *sys, int elevator_index, int floor) {
    int dest_floor = sys->requests.requests[floor-1].to_floor;

    if (dest_floor == 0) {
        return;
    }

    sys->requests.requests[floor-1].num_passengers--;
    sys->requests.num_passenger_requests--;
    sys->requests.total_passengers_served++;
    int passenger_wait_time = elevator_index * 5;
    sys->requests.total_passenger_wait_time += passenger_wait_time;
    if (passenger_wait_time > sys->requests.max_passenger_wait_time) {
        sys->requests.max_passenger_wait_time = passenger_wait_time;
    }

    printf("Elevator %d picked up %d passengers from floor %d\n", elevator_index+1, 5, floor);
    sys->elevators[elevator_index].num_passengers = 5;
    move_elevator(&sys->elevators[elevator_index], dest_floor);
    sys->elevators[elevator_index].num_passengers = 0;
    printf("Elevator %d delivered passengers to floor %d\n", elevator_index+1, dest_floor);
}

void handle_requests(ElevatorSystem *sys) {
    int elevators_idle = 0;
    for (int i = 0; i < ELEVATORS; i++) {
        if (sys->elevators[i].num_passengers == 0) {
            elevators_idle++;
        }
    }

    for (int i = 0; i < FLOORS; i++) {
        if (sys->requests.requests[i].to_floor != 0) {
            if (sys->requests.requests[i].num_passengers >= 5) {
                for (int j = 0; j < ELEVATORS; j++) {
                    if (sys->elevators[j].num_passengers == 0) {
                        printf("Elevator %d is picking up passengers from floor %d\n", j+1, i+1);
                        sys->elevators[j].num_passengers = 5;
                        move_elevator(&sys->elevators[j], i+1);
                        handle_request(sys, j, i+1);
                        elevators_idle--;
                        break;
                    }
                }
            } else {
                if (elevators_idle > 0) {
                    for (int j = 0; j < ELEVATORS; j++) {
                        if (sys->elevators[j].num_passengers == 0) {
                            printf("Elevator %d is picking up passengers from floor %d\n", j+1, i+1);
                            sys->elevators[j].num_passengers = sys->requests.requests[i].num_passengers;
                            move_elevator(&sys->elevators[j], i+1);
                            handle_request(sys, j, i+1);
                            elevators_idle--;
                            break;
                        }
                    }
                } else {
                    int best_elevator = -1;
                    int min_travel_time = FLOORS * 2;
                    for (int j = 0; j < ELEVATORS; j++) {
                        if (sys->elevators[j].num_passengers > 0) {
                            int travel_time = abs(sys->elevators[j].floor - i-1);
                            if (travel_time < min_travel_time) {
                                min_travel_time = travel_time;
                                best_elevator = j;
                            }
                        }
                    }

                    if (best_elevator != -1) {
                        handle_request(sys, best_elevator, i+1);
                    }
                }
            }
        }
    }
}

void print_elevator_system(ElevatorSystem *sys) {
    printf("============================\n");
    printf("Elevator System Status\n");
    printf("============================\n");
    printf("Passenger Requests:\n");
    for (int i = 0; i < FLOORS; i++) {
        printf("Floor %d: %d passengers going to floor %d\n", i+1, sys->requests.requests[i].num_passengers, sys->requests.requests[i].to_floor);
    }

    printf("\nElevators:\n");
    for (int i = 0; i < ELEVATORS; i++) {
        printf("Elevator %d: Floor %d, %d passengers\n", i+1, sys->elevators[i].floor, sys->elevators[i].num_passengers);
    }

    printf("\nPassenger Stats:\n");
    printf("Total Passengers Served: %d\n", sys->requests.total_passengers_served);
    printf("Total Passenger Wait Time: %d seconds\n", sys->requests.total_passenger_wait_time);
    printf("Max Passenger Wait Time: %d seconds\n", sys->requests.max_passenger_wait_time);
    printf("============================\n");
}

int main() {
    srand(123456789); // Seed the random number generator
    ElevatorSystem sys;

    initialize_elevator_system(&sys);

    // Add some passenger requests
    add_passenger_request(&sys, 1, 4);
    add_passenger_request(&sys, 1, 6);
    add_passenger_request(&sys, 3, 7);
    add_passenger_request(&sys, 5, 9);
    add_passenger_request(&sys, 2, 10);

    // Run the simulation for 50 time steps
    for (int t = 0; t < 50; t++) {
        printf("Time step %d\n", t+1);
        handle_requests(&sys);
        print_elevator_system(&sys);
    }

    return 0;
}