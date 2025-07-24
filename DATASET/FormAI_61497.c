//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define COLUMN 80
#define ROW 20
#define ELEVATOR_HEIGHT 5
#define ELEVATOR_WIDTH 10

// Define a struct for the floor
struct floor {
    int floor_number;
    int people_waiting;
};

// Define a struct for the elevator
struct elevator {
    int current_floor;
    int next_floor;
    int num_people_inside;
};

int main() {
    // Initialize variables
    int i, j, k, l, p, q, r, wait_time;
    struct floor floors[ROW];
    struct elevator elevator1;

    // Set initial elevator position and number of people inside
    elevator1.current_floor = 0;
    elevator1.next_floor = 0;
    elevator1.num_people_inside = 0;

    // Set default values for each floor
    for (i = 0; i < ROW; i++) {
        floors[i].floor_number = i;
        floors[i].people_waiting = 0;
    }

    // Main loop for elevator simulation
    for (p = 0; p < 20; p++) {
        // Clear screen
        system("clear");

        // Print elevator
        for (j = 0; j < ELEVATOR_HEIGHT; j++) {
            for (k = 0; k < (COLUMN - ELEVATOR_WIDTH) / 2; k++) {
                printf(" ");
            }
            for (l = 0; l < ELEVATOR_WIDTH; l++) {
                if (j == 0 || j == ELEVATOR_HEIGHT - 1) {
                    printf("-");
                } else if (l == 0 || l == ELEVATOR_WIDTH - 1) {
                    printf("|");
                } else if (elevator1.num_people_inside > 0) {
                    printf("o");
                    elevator1.num_people_inside--;
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Print floors
        for (q = 0; q < ROW; q++) {
            printf("|");
            for (r = 0; r < COLUMN - 2; r++) {
                if (r == (COLUMN - 2) / 2) {
                    printf("%d", floors[q].floor_number);
                } else if (r == (COLUMN - 2) / 2 + 1 && floors[q].people_waiting > 0) {
                    printf("%d", floors[q].people_waiting);
                    floors[q].people_waiting--;
                } else {
                    printf(" ");
                }
            }
            printf("|\n");
        }

        // Check if elevator needs to stop
        if (elevator1.current_floor == elevator1.next_floor) {
            printf("\nElevator door opens.\n");
            elevator1.num_people_inside += floors[elevator1.current_floor].people_waiting;
            floors[elevator1.current_floor].people_waiting = 0;
            wait_time = rand() % 5 + 1;
            printf("People get on and off the elevator. Door closes in %d seconds.\n", wait_time);
            elevator1.next_floor = rand() % ROW;
            while (elevator1.next_floor == elevator1.current_floor) {
                elevator1.next_floor = rand() % ROW;
            }
            for (i = 0; i < wait_time; i++) {
                printf("%d...\n", wait_time - i);
                sleep(1);
            }
            printf("Elevator door closes.\n");
        }

        // Set elevator direction and move elevator
        if (elevator1.next_floor > elevator1.current_floor) {
            printf("\nElevator is going up.\n");
            elevator1.current_floor++;
        } else {
            printf("\nElevator is going down.\n");
            elevator1.current_floor--;
        }

        // Generate random number of people on floors
        for (i = 0; i < ROW; i++) {
            floors[i].people_waiting += rand() % 2;
        }

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}