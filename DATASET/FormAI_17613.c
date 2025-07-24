//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    int current_floor;
    int destination_floor;
} Request;

void move_elevator(int current_floor, int destination_floor) {
    printf("Elevator moving from floor %d to floor %d...\n", current_floor, destination_floor);
    if (current_floor > destination_floor) {
        for (int i=current_floor; i>=destination_floor; i--) {
            printf("Floor %d\n", i);
        }
    } else {
        for (int i=current_floor; i<=destination_floor; i++) {
            printf("Floor %d\n", i);
        }
    }
    printf("Elevator has arrived at floor %d.\n", destination_floor);
}

int main() {
    srand(time(0));

    int num_floors = 10;
    int num_requests = 5;
    int current_floor = 1;
    Request requests[num_requests];

    for (int i=0; i<num_requests; i++) {
        requests[i].current_floor = (rand() % num_floors) + 1;
        requests[i].destination_floor = (rand() % num_floors) + 1;
        while (requests[i].destination_floor == requests[i].current_floor) {
            requests[i].destination_floor = (rand() % num_floors) + 1;
        }
    }

    printf("Elevator simulation starting...\n\n");

    for (int i=0; i<num_requests; i++) {
        printf("Request %d: Request for Floor %d to Floor %d\n", i+1, requests[i].current_floor, requests[i].destination_floor);
        if (requests[i].current_floor != current_floor) {
            move_elevator(current_floor, requests[i].current_floor);
            current_floor = requests[i].current_floor;
        }
        move_elevator(current_floor, requests[i].destination_floor);
        current_floor = requests[i].destination_floor;
        printf("Request %d complete!\n\n", i+1);;
    }
    printf("All requests have been completed.\nElevator simulation has ended.\n");
    return 0;
}