//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

#define FLOORS 10   // Total number of floors in the building
#define ELEVATORS 3 // Total number of elevators in the building
#define MAX_PASS 10 // Maximum capacity of an elevator

typedef struct {
    int curr_floor;                 // Current floor of elevator
    int dest_floor;                 // Destination floor of elevator
    bool is_moving;                 // Flag to indicate if elevator is moving
    int passenger_count;            // Number of passengers in elevator
    int passenger_list[MAX_PASS];   // List of passengers inside elevator
    int direction;                  // 1 for up, 0 for down
} Elevator;

// Initialize all elevators to first floor
void init_elevators(Elevator elevators[]) 
{
    for(int i=0; i<ELEVATORS; i++){
        elevators[i].curr_floor = 1;
        elevators[i].dest_floor = 1;
        elevators[i].is_moving = false;
        elevators[i].passenger_count = 0;
        elevators[i].direction = 1;
    }
}

// Move elevator to destination floor and update passenger list
void move_elevator(Elevator *elevator) 
{
    if (elevator->curr_floor < elevator->dest_floor) {
        elevator->curr_floor++;
    } else {
        elevator->curr_floor--;
    }

    if (elevator->curr_floor == elevator->dest_floor) {
        elevator->is_moving = false;
        elevator->direction = -elevator->direction; // Change direction
    }

    for (int i=0; i<elevator->passenger_count; i++){
        if (elevator->passenger_list[i] == elevator->curr_floor){
            printf("Passenger %d has arrived at floor %d.\n", i+1, elevator->curr_floor);
            elevator->passenger_list[i] = -1; // Remove passenger from elevator
            elevator->passenger_count--;
        }
    }
}

// Main program
int main()
{
    int passengers[FLOORS][ELEVATORS]; // Passengers waiting on each floor
    Elevator elevators[ELEVATORS];
    init_elevators(elevators);

    // Assume passengers arrive on random floors
    for(int i=0; i<FLOORS; i++){
        for(int j=0; j<ELEVATORS; j++){
            passengers[i][j] = rand()%4; // Maximum of 3 passengers arrive on each floor
        }
    }

    // Loop for 100 seconds
    for(int t=0; t<100; t++){
        // Check each elevator
        for (int i=0; i<ELEVATORS; i++){
            // If elevator is not moving, find closest passenger
            if (!elevators[i].is_moving && elevators[i].passenger_count == 0){
                int closest_floor = -1;
                int closest_distance = FLOORS;
                for (int j=0; j<FLOORS; j++){
                    for (int k=0; k<ELEVATORS; k++){
                        if (passengers[j][k] > 0){
                            int distance = abs(elevators[i].curr_floor - j);
                            if (distance < closest_distance) {
                                closest_floor = j;
                                closest_distance = distance;
                            }
                        }
                    }
                }
                // If closest passenger found, move elevator to passenger's floor
                if (closest_floor >= 0){
                    elevators[i].dest_floor = closest_floor;
                    elevators[i].is_moving = true;
                }
            }
            // If elevator is moving, continue moving
            else if (elevators[i].is_moving){
                move_elevator(&elevators[i]);
            }
            // If elevator is not moving but has passengers, move to next floor
            else{
                if (elevators[i].direction == 1 && elevators[i].curr_floor < FLOORS){
                    elevators[i].curr_floor++;
                } else if (elevators[i].direction == -1 && elevators[i].curr_floor > 1){
                    elevators[i].curr_floor--;
                }
            }

            // If elevator is at a floor with waiting passengers, pick them up
            int curr_floor = elevators[i].curr_floor;
            for (int j=0; j<ELEVATORS; j++){
                if (passengers[curr_floor-1][j] > 0 && elevators[i].passenger_count < MAX_PASS){
                    elevators[i].passenger_list[elevators[i].passenger_count] = curr_floor;
                    elevators[i].passenger_count++;
                    passengers[curr_floor-1][j]--;
                    printf("Passenger loaded onto elevator %d at floor %d.\n", i+1, curr_floor);
                }
            }
        }

        printf("\n");
    }

    return 0;
}