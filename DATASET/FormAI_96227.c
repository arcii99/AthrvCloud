//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_FLOORS 10
#define MAX_PEOPLE 5
#define ELEVATOR_CAPACITY 10
#define TIME_DELAY 1

int elevator_position = 0; // initializes the elevator position to the ground floor
int elevator_direction = 1; // initializes the elevator direction to go up first
int elevator_occupancy = 0; // initializes the number of people in the elevator to zero
int floor_queues[TOTAL_FLOORS][2] = { 0 }; // initializes the floor queues to be empty

void add_person_to_queue(int floor, int direction) {
    int queue_index = direction == 1 ? 0 : 1;
    if (floor_queues[floor][queue_index] < MAX_PEOPLE) {
        floor_queues[floor][queue_index]++;
        printf("Person added to queue on floor %d going %s\n", floor, direction == 1 ? "up" : "down");
    } else {
        printf("Queue on floor %d going %s is already full!\n", floor, direction == 1 ? "up" : "down");
    }
}

void move_elevator() {
    elevator_position += elevator_direction;
    printf("Elevator is now on floor %d\n", elevator_position);
}

void load_elevator() {
    while (elevator_occupancy < ELEVATOR_CAPACITY && floor_queues[elevator_position][elevator_direction == 1 ? 0 : 1] > 0) {
        elevator_occupancy++;
        floor_queues[elevator_position][elevator_direction == 1 ? 0 : 1]--;
        printf("Person loaded on floor %d going %s\n", elevator_position, elevator_direction == 1 ? "up" : "down");
    }
}

void unload_elevator() {
    if (floor_queues[elevator_position][elevator_direction == 1 ? 0 : 1] == 0 && floor_queues[elevator_position][elevator_direction == 1 ? 1 : 0] == 0) {
        printf("Elevator is empty!\n");
        elevator_occupancy = 0;
    } else {
        printf("Person unloaded on floor %d\n", elevator_position);
        elevator_occupancy--;
    }
}

int main() {
    srand(time(NULL));
    while (1) {
        int random_floor = rand() % TOTAL_FLOORS; // Add someone to a random floor
        int random_direction = rand() % 2; // Randomly choose their direction

        add_person_to_queue(random_floor, random_direction);
        load_elevator();
        move_elevator();
        unload_elevator();
        printf("\n");
         
        if (elevator_position == TOTAL_FLOORS - 1) {
            elevator_direction = -1; // Change direction when elevator reaches the top floor
        } else if (elevator_position == 0) {
            elevator_direction = 1; // Change direction when elevator reaches the ground floor
        }
         
        sleep(TIME_DELAY);
    }
    return 0;
}