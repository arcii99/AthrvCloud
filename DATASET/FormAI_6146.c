//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define MAX_CAPACITY 10

int curr_floor = 0;
int dir = 1;
int curr_capacity = 0;
int in_elevator[NUM_FLOORS] = {0};
int waiting[NUM_FLOORS] = {0};

void move_elevator() {
    curr_floor += dir;
    printf("Elevator is now on floor %d\n", curr_floor);
    if (curr_floor == 0 || curr_floor == NUM_FLOORS - 1) {
        dir *= -1;
    }
}

int check_capacity() {
    if (curr_capacity == MAX_CAPACITY) {
        return 0;
    }
    return 1;
}

int check_waiting() {
    int i;
    for (i = 0; i < NUM_FLOORS; i++) {
        if (waiting[i]) {
            return 1;
        }
    }
    return 0;
}

void load_elevator() {
    int i;
    for (i = 0; i < NUM_FLOORS; i++) {
        if (waiting[i] && in_elevator[i] == 0 && check_capacity()) {
            in_elevator[i] = 1;
            waiting[i] = 0;
            curr_capacity += 1;
            printf("Passenger picked up on floor %d\n", i);
        }
    }
}

void unload_elevator() {
    if (in_elevator[curr_floor]) {
        in_elevator[curr_floor] = 0;
        curr_capacity -= 1;
        printf("Passenger dropped off on floor %d\n", curr_floor);
    }
}

int main() {
    srand(time(NULL));
    int i;
    int num_passengers = rand() % MAX_CAPACITY;
    while (num_passengers == 0) {
        num_passengers = rand() % MAX_CAPACITY;
    }
    printf("%d passengers are waiting on the ground floor.\n", num_passengers);
    waiting[0] = num_passengers;
    while (check_waiting()) {
        load_elevator();
        unload_elevator();
        move_elevator();
    }
    printf("All passengers have been dropped off.\n");
    return 0;
}