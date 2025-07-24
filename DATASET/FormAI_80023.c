//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int num_flights = 0;
    int num_luggage = 0;
    int conveyor_belt[100] = {0}; // initialize to empty

    // seed random number generator
    srand(time(NULL));

    // generate random number of flights and luggage
    num_flights = rand() % 10 + 1; // range: 1-10
    num_luggage = rand() % 100 + 1; // range: 1-100

    // print number of flights and luggage
    printf("Number of flights: %d\n", num_flights);
    printf("Number of luggage: %d\n", num_luggage);

    // randomly fill conveyor belt with luggage
    for (int i = 0; i < num_luggage; i++) {
        int index = rand() % 100; // range: 0-99
        if (conveyor_belt[index] == 0) {
            conveyor_belt[index] = i+1; // assign luggage number
        } else {
            i--; // try again at a different index
        }
    }

    // print conveyor belt status
    printf("\nConveyor belt status:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", conveyor_belt[i]);
    }
    printf("\n\n");

    // simulate baggage handling process
    int current_flight = 1; // initialize to first flight
    int current_index = 0; // initialize to beginning of conveyor belt
    while (current_flight <= num_flights) {
        printf("Loading flight #%d...\n", current_flight);
        // loop through conveyor belt until luggage for current flight is found
        while (conveyor_belt[current_index] != current_flight) {
            printf("Luggage %d not for this flight.\n", conveyor_belt[current_index]);
            current_index++; // move to next luggage on conveyor belt
            if (current_index == 100) { // start at the beginning if end is reached
                current_index = 0;
            }
        }
        printf("Loading luggage %d...\n", conveyor_belt[current_index]);
        conveyor_belt[current_index] = 0; // remove luggage from conveyor belt
        current_flight++; // move to next flight

        // check if conveyor belt is empty
        int is_empty = 1; // set to true
        for (int i = 0; i < 100; i++) {
            if (conveyor_belt[i] != 0) {
                is_empty = 0; // set to false if any luggage exists on conveyor belt
                break;
            }
        }
        if (is_empty) {
            printf("Conveyor belt is empty.\n");
            break; // exit simulation if conveyor belt is empty
        }

        // randomly add new luggage to conveyor belt
        int num_new_luggage = rand() % 5 + 1; // range: 1-5
        printf("Adding %d new luggage...\n", num_new_luggage);
        for (int i = 0; i < num_new_luggage; i++) {
            int index = rand() % 100; // range: 0-99
            if (conveyor_belt[index] == 0) {
                conveyor_belt[index] = num_luggage+1; // assign new luggage number
                num_luggage++;
            } else {
                i--; // try again at a different index
            }
        }
        printf("\nConveyor belt status:\n");
        for (int i = 0; i < 100; i++) {
            printf("%d ", conveyor_belt[i]);
        }
        printf("\n\n");
    }

    // print end of program message
    printf("Baggage handling simulation complete.\n");

    return 0;
}