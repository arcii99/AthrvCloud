//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_FLOORS 10
#define ELEVATOR_CAPACITY 10

int floors[NUM_FLOORS][ELEVATOR_CAPACITY];
int occupied[NUM_FLOORS];
int elevator_floor = 0;
int elevator_direction = 1; // going up when 1, down when -1
int num_passengers = 0;
int max_passengers = ELEVATOR_CAPACITY;
int remaining_stops = 0;

int random_floor() {
    return rand() % NUM_FLOORS;
}

void insert_passenger(int to_floor) {
    for (int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if (floors[elevator_floor][i] == -1) {
            floors[elevator_floor][i] = to_floor;
            num_passengers++;
            occupied[to_floor]++;
            break;
        }
    }
}

void remove_passenger(int i) {
    int to_floor = floors[elevator_floor][i];
    floors[elevator_floor][i] = -1;
    num_passengers--;
    occupied[to_floor]--;
    if (occupied[to_floor] == 0) {
        remaining_stops--;
    }
}

void print_elevator() {
    printf("Elevator at floor %d going %s with %d passengers: ", 
           elevator_floor, elevator_direction == 1 ? "up" : "down", num_passengers);
    for (int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if (floors[elevator_floor][i] != -1) {
            printf("%d ", floors[elevator_floor][i]);
        }
    }
    printf("\n");
}

void print_floors() {
    printf("Floors: ");
    for (int i = NUM_FLOORS - 1; i >= 0; i--) {
        printf("%d |", i);
        for (int j = 0; j < ELEVATOR_CAPACITY; j++) {
            if (floors[i][j] != -1) {
                printf(" %d", floors[i][j]);
            } else {
                printf(" -");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void elevator_up() {
    if (num_passengers == 0) {
        elevator_direction = 1;
        return;
    }
    elevator_floor++;
    for (int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if (floors[elevator_floor][i] != -1) {
            remove_passenger(i);
            i--;
        }
    }
}

void elevator_down() {
    if (num_passengers == 0) {
        elevator_direction = -1;
        return;
    }
    elevator_floor--;
    for (int i = 0; i < ELEVATOR_CAPACITY; i++) {
        if (floors[elevator_floor][i] != -1) {
            remove_passenger(i);
            i--;
        }
    }
}

void elevator_idle() {
    int from_floor = random_floor();
    int to_floor = random_floor();
    while (from_floor == to_floor) {
        to_floor = random_floor();
    }
    insert_passenger(to_floor);
    if (elevator_floor > from_floor) {
        elevator_direction = -1;
    } else if (elevator_floor < from_floor) {
        elevator_direction = 1;
    } else {
        if (elevator_direction == 1 && to_floor < from_floor) {
            elevator_direction = -1;
        } else if (elevator_direction == -1 && to_floor > from_floor) {
            elevator_direction = 1;
        }
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ELEVATOR_CAPACITY; j++) {
            floors[i][j] = -1;
        }
    }
    int steps = 0;
    while (steps < 100) {
        steps++;
        print_elevator();
        print_floors();
        if (num_passengers == 0 && remaining_stops == 0) {
            elevator_idle();
        } else {
            if (elevator_direction == 1) {
                elevator_up();
            } else {
                elevator_down();
            }
        }
        printf("------------------------------------\n");
    }
    return 0;
}