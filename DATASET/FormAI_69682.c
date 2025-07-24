//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 20
#define MAX_PEOPLE 10

int floor_queue[MAX_PEOPLE]; // queue of people waiting on floors
int floor_queues[MAX_FLOORS][MAX_PEOPLE]; // list of people waiting on each floor
int floor_counts[MAX_FLOORS]; // number of people waiting on each floor
int elevator_queue[MAX_PEOPLE]; // queue of people waiting for elevator
int elevator_pos = 1; // starting position of elevator
int elevator_dir = 1; // direction elevator is moving in
int elevator_count = 0; // number of people in elevator

void add_person(int person) {
    if (floor_counts[person] >= MAX_PEOPLE) {
        printf("Floor %d is at maximum capacity\n", person);
        return;
    }
    floor_queues[person][floor_counts[person]] = person;
    floor_counts[person]++;
    printf("Person %d is waiting on floor %d\n", person, person);
}

void remove_person(int person) {
    for (int i = 0; i < floor_counts[person]; i++) {
        if (floor_queues[person][i] == person) {
            floor_queues[person][i] = -1;
            floor_counts[person]--;
            return;
        }
    }
    printf("Unable to find person %d on floor %d\n", person, person);
}

int get_next_floor() {
    int min_floor = 1;
    int max_floor = MAX_FLOORS;
    if (elevator_dir == -1) {
        max_floor = elevator_pos - 1;
    } else if (elevator_dir == 1) {
        min_floor = elevator_pos + 1;
    } else {
        printf("Invalid elevator direction\n");
    }
    for (int floor = min_floor; floor <= max_floor; floor++) {
        if (floor_counts[floor] > 0) {
            return floor;
        }
    }
    return elevator_pos;
}

void move_elevator() {
    int next_floor = get_next_floor();
    if (next_floor == elevator_pos) {
        return;
    }
    elevator_dir = next_floor > elevator_pos ? 1 : -1;
    printf("Elevator moving from floor %d to floor %d\n", elevator_pos, next_floor);
    elevator_pos = next_floor;
    for (int i = 0; i < floor_counts[elevator_pos]; i++) {
        int person = floor_queues[elevator_pos][i];
        if (person != -1) {
            if (elevator_count < MAX_PEOPLE) {
                elevator_queue[elevator_count] = person;
                floor_queues[elevator_pos][i] = -1;
                floor_counts[elevator_pos]--;
                elevator_count++;
                printf("Person %d is entering the elevator\n", person);
            } else {
                printf("Elevator is at maximum capacity\n");
                return;
            }
        }
    }
}

void drop_off_people() {
    int i = 0;
    while (i < elevator_count) {
        int person = elevator_queue[i];
        if (person == elevator_pos) {
            elevator_queue[i] = -1;
            elevator_count--;
            printf("Person %d is leaving the elevator on floor %d\n", person, elevator_pos);
            remove_person(person);
        } else {
            i++;
        }
    }
}

int main() {
    for (int i = 1; i <= MAX_PEOPLE; i++) {
        add_person(i % MAX_FLOORS + 1);
    }
    while (elevator_count > 0 || floor_counts[1] > 0 || floor_counts[MAX_FLOORS] > 0) {
        drop_off_people();
        move_elevator();
    }
    printf("Simulation complete\n");
    return 0;
}