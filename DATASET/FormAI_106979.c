//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define FLOORS 10
#define ELEVATORS 3

int elevator_status[ELEVATORS] = {0}; // 0 = idle, 1 = moving up, -1 = moving down
int elevator_floor[ELEVATORS] = {0}; // current floor
int elevator_queue[FLOORS][ELEVATORS] = {0}; // 0 = no request, 1 = requested

void request_elevator(int floor, int direction) {
    int closest_elevator = -1;
    int closest_dist = FLOORS+1;

    for (int i = 0; i < ELEVATORS; i++) {
        if (elevator_status[i] == 0) { // idle
            elevator_status[i] = direction;
            elevator_queue[floor][i] = 1;
            return;
        } else if (elevator_status[i] == direction) { // moving in requested direction
            int dist = abs(elevator_floor[i] - floor);
            if (dist < closest_dist) {
                closest_dist = dist;
                closest_elevator = i;
            }
        }
    }

    if (closest_elevator != -1) { // assign to closest elevator moving in requested direction
        elevator_queue[floor][closest_elevator] = 1;
        return;
    }

    for (int i = 0; i < ELEVATORS; i++) { // assign to idle elevator
        if (elevator_status[i] == 0) {
            elevator_status[i] = direction;
            elevator_queue[floor][i] = 1;
            return;
        }
    }

    printf("Unable to assign elevator.\n");
}

void update_elevators() {
    for (int i = 0; i < ELEVATORS; i++) {
        if (elevator_status[i] != 0) { // moving
            if (elevator_status[i] == 1) { // moving up
                if (elevator_floor[i] == FLOORS-1) { // reached top floor
                    elevator_status[i] = -1;
                } else {
                    elevator_floor[i]++;
                }
            } else { // moving down
                if (elevator_floor[i] == 0) { // reached bottom floor
                    elevator_status[i] = 1;
                } else {
                    elevator_floor[i]--;
                }
            }
            if (elevator_queue[elevator_floor[i]][i] == 1) { // reached requested floor
                elevator_queue[elevator_floor[i]][i] = 0;
                printf("Elevator %d arrived at floor %d.\n", i, elevator_floor[i]);
            }
        }
    }
}

void print_elevators() {
    printf("Elevator\tFloor\tStatus\tQueue\n");
    for (int i = 0; i < ELEVATORS; i++) {
        printf("%d\t\t%d\t", i, elevator_floor[i]);
        if (elevator_status[i] == 0) {
            printf("Idle\t");
        } else if (elevator_status[i] == 1) {
            printf("Up\t");
        } else {
            printf("Down\t");
        }
        for (int j = 0; j < FLOORS; j++) {
            printf("%d ", elevator_queue[j][i]);
        }
        printf("\n");
    }
}

int main() {
    request_elevator(3, 1);
    request_elevator(5, -1);
    request_elevator(7, 1);
    request_elevator(1, -1);
    while (1) {
        system("clear"); // clear console for easy viewing
        print_elevators();
        update_elevators();
        usleep(5000); // sleep for 5ms to slow down console output
    }
    return 0;
}