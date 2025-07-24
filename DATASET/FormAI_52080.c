//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10

typedef struct {
    int id;
    int current_floor;
    int destination_floor;
    int passengers_count;
} Elevator;

typedef struct {
    int id;
    int current_floor;
} Passenger;

int main() {
    srand(time(NULL));
    
    int num_passengers = 100;
    Passenger passengers[num_passengers];
    
    for (int i = 0; i < num_passengers; i++) {
        passengers[i].id = i + 1;
        passengers[i].current_floor = rand() % FLOORS + 1;
    }
    
    Elevator elevator;
    elevator.id = 1;
    elevator.current_floor = 1;
    elevator.destination_floor = 1;
    elevator.passengers_count = 0;
    
    printf("Elevator #%d is on floor %d.\n", elevator.id, elevator.current_floor);
    
    while (1) {
        if (elevator.current_floor == elevator.destination_floor) {
            elevator.destination_floor = rand() % FLOORS + 1;
            printf("Elevator #%d is moving to floor %d.\n", elevator.id, elevator.destination_floor);
        }
        
        if (elevator.passengers_count > 0) {
            for (int i = 0; i < num_passengers; i++) {
                if (passengers[i].current_floor == elevator.current_floor) {
                    printf("Passenger #%d has left the elevator on floor %d.\n", passengers[i].id, elevator.current_floor);
                    elevator.passengers_count--;
                }
            }
        }
        
        if (elevator.passengers_count < 10) {
            for (int i = 0; i < num_passengers; i++) {
                if (passengers[i].current_floor == elevator.current_floor) {
                    printf("Passenger #%d has entered the elevator on floor %d.\n", passengers[i].id, elevator.current_floor);
                    elevator.passengers_count++;
                }
            }
        }
        
        elevator.current_floor += elevator.current_floor < elevator.destination_floor ? 1 : -1;
        
        if (elevator.current_floor == FLOORS) {
            printf("Elevator #%d has reached the top floor.\n", elevator.id);
            elevator.destination_floor = rand() % (FLOORS - 1) + 1;
        } else if (elevator.current_floor == 1) {
            printf("Elevator #%d has reached the ground floor.\n", elevator.id);
            elevator.destination_floor = rand() % (FLOORS - 1) + 2;
        }
    }
    
    return 0;
}