//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOOR_NUM 20
#define ELEVATOR_CAP 10
#define CYBERPUNK_MODE 1

int floor_requests[FLOOR_NUM];

int current_floor = 0;
int elevator_dir = 1; // up = 1; down = -1;

int elevator_pos = 0;
int elevator_capacity = 0;

/* Generate random floor requests */
void generate_requests() {
    for(int i=0; i<FLOOR_NUM; i++) {
        floor_requests[i] = rand() % 2;
    }
}

/* Print floor requests */
void print_requests() {
    for(int i=0; i<FLOOR_NUM; i++) {
        printf("|%d", floor_requests[i]);
    }
    printf("|\n");
}

/* Check if there are any floor requests ahead */
int check_ahead() {
    if(elevator_dir == 1) {
        for(int i=current_floor+1; i<FLOOR_NUM; i++) {
            if(floor_requests[i])
                return 1;
        }
        return 0;
    }
    else {
        for(int i=current_floor-1; i>=0; i--) {
            if(floor_requests[i])
                return 1;
        }
        return 0;
    }
}

/* Move the elevator one floor up or down */
void move_elevator() {
    if(elevator_dir == 1) {
        elevator_pos++;
        printf("[Elevator moving up. Currently on floor %d.]\n", elevator_pos);
    }
    else {
        elevator_pos--;
        printf("[Elevator moving down. Currently on floor %d.]\n", elevator_pos);
    }
}

/* Simulate opening elevator doors */
void open_doors() {
    printf("[Elevator doors opening.]\n");
}

/* Simulate closing elevator doors */
void close_doors() {
    printf("[Elevator doors closing.]\n");
}

/* Simulate picking up passengers from the current floor */
void pick_up() {
    int passengers_added = 0;
    while(current_floor < FLOOR_NUM && elevator_capacity < ELEVATOR_CAP) {
        if(floor_requests[current_floor]) {
            floor_requests[current_floor] = 0;
            passengers_added++;
            elevator_capacity++;
        }
        current_floor += elevator_dir;
    }
    printf("[Picked up %d passengers.]\n", passengers_added);
}

/* Simulate dropping off passengers at the current floor */
void drop_off() {
    int passengers_dropped = 0;
    for(int i=0; i<ELEVATOR_CAP; i++) {
        if(rand() % 2) {
            passengers_dropped++;
            elevator_capacity--;
        }
    }
    printf("[Dropped off %d passengers.]\n", passengers_dropped);
}

int main() {
    srand(time(NULL));
    generate_requests();

    printf("Elevator requests: ");
    print_requests();

    while(check_ahead() || elevator_capacity) {
        if(floor_requests[elevator_pos]) {
            printf("[Elevator doors opening on floor %d.]\n", elevator_pos);
            drop_off();
            open_doors();
            close_doors();
        }
        else {
            move_elevator();
        }

        if(current_floor == FLOOR_NUM-1)
            elevator_dir = -1;
        else if(current_floor == 0)
            elevator_dir = 1;

        if(elevator_capacity < ELEVATOR_CAP)
            pick_up();

        if(CYBERPUNK_MODE) {
            // Simulate elevator malfunction
            if(rand() % 25 == 0) {
                printf("[Elevator malfunction!]\n");
                break;
            }
            // Simulate power outage
            if(rand() % 50 == 0) {
                printf("[Power outage!]\n");
                break;
            }
        }
    }

    printf("[Elevator simulation finished.]\n");
    return 0;
}