//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>

#define NUM_FLOORS 6
#define MAX_NUM_PASSENGERS 8

int current_floor = 1;
int num_passengers = 0;
int passenger_destinations[MAX_NUM_PASSENGERS];
int num_stops = 0;

void elevator_operation() {
    printf("Elevator has arrived at floor %d\n", current_floor);

    int num_boarded = 0;
    int num_destinations[NUM_FLOORS] = {0};

    for (int i = 0; i < num_passengers; i++) {
        num_destinations[passenger_destinations[i]]++;
    }

    for (int i = 0; i < num_passengers; i++) {
        if (passenger_destinations[i] == current_floor) {
            num_boarded++;
            printf("Passenger %d has arrived at their destination on floor %d\n", i+1, current_floor);
            for (int j = i; j < num_passengers-1; j++) {
                passenger_destinations[j] = passenger_destinations[j+1];
            }
            num_passengers--;
            i--;
        }
    }

    int num_waiting = 0;
    for (int i = 1; i <= NUM_FLOORS; i++) {
        if (i == current_floor) continue;
        num_waiting += num_destinations[i];
    }

    if (num_waiting == 0) {
        printf("No passengers waiting on this floor or other floors\n");
    } else {
        printf("%d passengers are waiting for the elevator\n", num_waiting);
        int dest_floor;

        while (num_passengers < MAX_NUM_PASSENGERS && num_waiting > 0) {
            for (int i = current_floor+1; i <= NUM_FLOORS; i++) {
                if (num_destinations[i] > 0) {
                    dest_floor = i;
                    break;
                }
            }

            for (int i = current_floor-1; i > 0; i--) {
                if (num_destinations[i] > 0) {
                    dest_floor = i;
                    break;
                }
            }

            printf("Elevator is going to floor %d\n", dest_floor);
            current_floor = dest_floor;

            while (num_waiting > 0 && num_passengers < MAX_NUM_PASSENGERS) {
                for (int i = 0; i < num_destinations[current_floor]; i++) {
                    passenger_destinations[num_passengers] = current_floor;
                    num_waiting--;
                    num_passengers++;
                    num_destinations[current_floor]--;
                }
            }

            num_stops++;
        }

        printf("Elevator has completed its operations with %d stops\n", num_stops);
    }
}

int main() {
    passenger_destinations[0] = 2;
    passenger_destinations[1] = 3;
    passenger_destinations[2] = 4;
    passenger_destinations[3] = 2;
    passenger_destinations[4] = 1;
    passenger_destinations[5] = 5;
    num_passengers = 6;

    elevator_operation();
    return 0;
}