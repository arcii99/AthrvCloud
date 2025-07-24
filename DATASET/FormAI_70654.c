//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 3

int main() {
    int elevators[ELEVATORS] = {1, 1, 1}; // starting position: all elevators at ground floor
    int request_floor, request_elevator, elevator_floor, elevator_distance, i, j;
    int requests[FLOORS] = {0}; // initialize all requests to 0
    int min_distance = FLOORS - 1; // max distance between floors is FLOORS - 1

    srand(time(NULL)); // seed random number generator

    while(1) {
        printf("===================\n");
        printf("Current Elevator Positions:\n");
        for(i = 0; i < ELEVATORS; i++) {
            printf("Elevator %d: Floor %d\n", i+1, elevators[i]);
        }

        printf("===================\n");
        printf("Current Requests:\n");
        for(i = 0; i < FLOORS; i++) {
            if(requests[i] == 1) {
                printf("Floor %d: Requested\n", i+1);
            }
        }

        // randomly generate new requests
        if(rand() % 2 == 0) {
            request_floor = rand() % FLOORS; // random floor between 0 and FLOORS-1
            requests[request_floor] = 1;
            printf("===================\n");
            printf("New Request: Floor %d\n", request_floor+1);
        }

        // check if any elevators are already on the requested floor
        for(i = 0; i < ELEVATORS; i++) {
            if(elevators[i] == request_floor+1) {
                request_elevator = i;
                printf("===================\n");
                printf("Elevator %d is on Floor %d and can handle request to Floor %d\n", i+1, elevators[i], request_floor+1);
                break;
            }
        }

        // if none of the elevators are on the requested floor, find which elevator is closest to the requested floor
        if(i == ELEVATORS) {
            for(i = 0; i < ELEVATORS; i++) {
                elevator_floor = elevators[i];
                elevator_distance = abs(request_floor - elevator_floor);
                if(elevator_distance < min_distance) {
                    min_distance = elevator_distance;
                    request_elevator = i;
                }
            }
            printf("===================\n");
            printf("Elevator %d is closest to Floor %d with a distance of %d floors\n", request_elevator+1, request_floor+1, min_distance);
            min_distance = FLOORS - 1;
        }

        // move the elevator to the requested floor
        while(elevators[request_elevator] != request_floor+1) {
            if(elevators[request_elevator] < request_floor+1) {
                elevators[request_elevator]++;
            }
            else {
                elevators[request_elevator]--;
            }
        }

        printf("===================\n");
        printf("Elevator %d has arrived at Floor %d\n", request_elevator+1, elevators[request_elevator]);

        // clear the request from the request array
        requests[request_floor] = 0;

        // wait for a random amount of time before starting again
        int wait_time = rand() % 6; // random wait time between 0 and 5 seconds
        printf("===================\n");
        printf("Waiting %d seconds before next simulation step...\n", wait_time);
        sleep(wait_time);
    }

    return 0;
}