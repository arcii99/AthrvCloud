//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

typedef struct {
    int cur_floor;
    int dest_floor;
    int direction; // -1 for down, 0 for stationary, 1 for up
} Passenger;

typedef struct {
    int cur_floor;
    int dest_floor;
    int passengers[NUM_FLOORS];
} Elevator;

Passenger spawn_passenger() {
    Passenger p;
    p.cur_floor = rand() % NUM_FLOORS;
    p.dest_floor = rand() % NUM_FLOORS;
    while (p.dest_floor == p.cur_floor) {
        p.dest_floor = rand() % NUM_FLOORS;
    }
    p.direction = (p.dest_floor > p.cur_floor) - (p.dest_floor < p.cur_floor);
    return p;
}

void print_elevator(Elevator elev) {
    printf("Current Floor: %d | Destination Floor: %d\n", elev.cur_floor, elev.dest_floor);
    printf("Passengers: ");
    for (int i = 0; i < NUM_FLOORS; i++) {
        if (elev.passengers[i] != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void print_building(Elevator elevators[NUM_ELEVATORS]) {
    printf("Elevators:\n");
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        printf("Elevator %d:\n", i);
        print_elevator(elevators[i]);
    }
}

int main() {
    srand(time(NULL));
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].cur_floor = rand() % NUM_FLOORS;
        elevators[i].dest_floor = rand() % NUM_FLOORS;
        while (elevators[i].dest_floor == elevators[i].cur_floor) {
            elevators[i].dest_floor = rand() % NUM_FLOORS;
        }
        for (int j = 0; j < NUM_FLOORS; j++) {
            elevators[i].passengers[j] = 0;
        }
        print_elevator(elevators[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) { // spawn 10 passengers
        Passenger p = spawn_passenger();
        printf("Passenger Spawned! Current Floor: %d | Destination Floor: %d | Direction: %d\n", p.cur_floor, p.dest_floor, p.direction);
        int elev_choice = -1;
        int min_dist = 100;
        for (int j = 0; j < NUM_ELEVATORS; j++) { // choose closest elevator
            int dist = abs(elevators[j].cur_floor - p.cur_floor);
            if (dist < min_dist) {
                elev_choice = j;
                min_dist = dist;
            }
        }
        printf("Passenger Choosing Elevator: %d\n", elev_choice);
        elevators[elev_choice].passengers[p.cur_floor] = 1;
        printf("Passenger Entering Elevator: %d\n", elev_choice);
        while (elevators[elev_choice].cur_floor != p.dest_floor) { // move elevator to destination floor
            if (elevators[elev_choice].cur_floor < p.dest_floor) {
                elevators[elev_choice].cur_floor++;
            } else {
                elevators[elev_choice].cur_floor--;
            }
            usleep(1000000); // simulate time passing
            printf("Elevator Moving! Current Floor: %d | Destination Floor: %d\n", elevators[elev_choice].cur_floor, elevators[elev_choice].dest_floor);
        }
        elevators[elev_choice].passengers[p.cur_floor] = 0;
        elevators[elev_choice].passengers[p.dest_floor] = 1;
        printf("Passenger Exiting Elevator: %d\n", elev_choice);
        print_building(elevators);
        printf("\n");
    }
    return 0;
}