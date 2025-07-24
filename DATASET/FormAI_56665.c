//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: careful
#include <stdio.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

typedef struct {
    int current_floor;
    int queued_floors[MAX_FLOORS];
    int num_queued_floors;
    int capacity;
    int num_people;
    int people[MAX_PEOPLE];
} Elevator;

int get_next_floor(Elevator* elevator) {
    if (elevator->num_queued_floors == 0) {
        return -1;
    }
    int next_floor = elevator->queued_floors[0];
    for (int i = 1; i < elevator->num_queued_floors; i++) {
        if (abs(elevator->current_floor - elevator->queued_floors[i]) < abs(elevator->current_floor - next_floor)) {
            next_floor = elevator->queued_floors[i];
        }
    }
    return next_floor;
}

void unload_elevator(Elevator* elevator) {
    int num_unloaded = 0;
    for (int i = 0; i < elevator->num_people; i++) {
        if (elevator->people[i] == elevator->current_floor) {
            // unload person
            elevator->people[i] = -1;
            num_unloaded++;
        }
    }
    printf("Unloaded %d people at floor %d\n", num_unloaded, elevator->current_floor);
    elevator->num_people -= num_unloaded;
}

void load_elevator(Elevator* elevator, int* people_waiting) {
    int num_loaded = 0;
    for (int i = 0; i < MAX_PEOPLE && elevator->num_people < elevator->capacity; i++) {
        if (people_waiting[elevator->current_floor * MAX_PEOPLE + i] == 1) {
            // load person
            elevator->people[elevator->num_people++] = elevator->current_floor;
            num_loaded++;
        }
    }
    printf("Loaded %d people at floor %d\n", num_loaded, elevator->current_floor);
}

void step_elevator(Elevator* elevator, int* people_waiting) {
    int next_floor = get_next_floor(elevator);
    if (next_floor == -1) {
        printf("Elevator idle at floor %d\n", elevator->current_floor);
        return;
    }
    printf("Elevator moving from floor %d to floor %d\n", elevator->current_floor, next_floor);
    elevator->current_floor = next_floor;
    unload_elevator(elevator);
    load_elevator(elevator, people_waiting);
    for (int i = 0; i < elevator->num_queued_floors; i++) {
        if (elevator->queued_floors[i] == next_floor) {
            // remove floor from queue
            for (int j = i; j < elevator->num_queued_floors - 1; j++) {
                elevator->queued_floors[j] = elevator->queued_floors[j + 1];
            }
            elevator->num_queued_floors--;
            break;
        }
    }
}

int main() {
    Elevator elevator = {0};
    elevator.capacity = 3;
    int people_waiting[MAX_FLOORS * MAX_PEOPLE] = {0};
    people_waiting[0] = 1;
    people_waiting[2 * MAX_PEOPLE] = 1;
    people_waiting[5 * MAX_PEOPLE + 1] = 1;
    elevator.queued_floors[0] = 2;
    elevator.queued_floors[1] = 5;
    elevator.num_queued_floors = 2;
    while (elevator.num_queued_floors > 0 || elevator.num_people > 0) {
        step_elevator(&elevator, people_waiting);
        printf("\n");
    }
    return 0;
}