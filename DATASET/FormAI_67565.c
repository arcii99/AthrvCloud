//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 50 // maximum number of bags that can be handled
#define MAX_FLIGHTS 5 // maximum number of flights that can be handled
#define MAX_PASSENGERS 150 // maximum number of passengers that can be handled
#define MAX_WAITING_TIME 15 // maximum waiting time for a passenger

// Function to simulate the baggage handling process
void handle_baggage(int passenger_id, int flight_number, int baggage_id){
    printf("Passenger %d's baggage with ID %d has been loaded onto Flight %d!\n", passenger_id, baggage_id, flight_number);
}

// Function to get a random integer between two values
int get_random(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the count of passengers, flights, and baggage
    int passenger_count = get_random(100, MAX_PASSENGERS);
    int flight_count = get_random(1, MAX_FLIGHTS);
    int baggage_count = get_random(10, MAX_BAGGAGE);

    // Initialize the arrays to track the flight numbers and baggage IDs
    int flight_numbers[MAX_FLIGHTS];
    int baggage_ids[MAX_BAGGAGE];

    // Populate the arrays with unique values
    for(int i = 0; i < flight_count; i++){
        flight_numbers[i] = i + 1;
    }
    for(int i = 0; i < baggage_count; i++){
        baggage_ids[i] = i + 100;
    }

    // Shuffle the arrays to simulate the randomness of real-life scenarios
    for(int i = 0; i < flight_count; i++){
        int random_index = get_random(0, flight_count - 1);
        int temp = flight_numbers[i];
        flight_numbers[i] = flight_numbers[random_index];
        flight_numbers[random_index] = temp;
    }
    for(int i = 0; i < baggage_count; i++){
        int random_index = get_random(0, baggage_count - 1);
        int temp = baggage_ids[i];
        baggage_ids[i] = baggage_ids[random_index];
        baggage_ids[random_index] = temp;
    }

    // Simulate the baggage handling process for each passenger
    for(int i = 0; i < passenger_count; i++){
        int flight_number = flight_numbers[get_random(0, flight_count - 1)];
        int baggage_id = baggage_ids[get_random(0, baggage_count - 1)];
        int waiting_time = get_random(1, MAX_WAITING_TIME);

        printf("Passenger %d is waiting for Flight %d with baggage ID %d...\n", i+1, flight_number, baggage_id);

        // Simulate the waiting time for the passenger
        for(int j = 1; j <= waiting_time; j++){
            printf("    %d minute(s) of waiting time remaining...\n", waiting_time-j);
        }

        // Simulate the baggage handling process for the passenger
        handle_baggage(i+1, flight_number, baggage_id);
    }

    // End the program with a cheerful message
    printf("\nThank you for using our baggage handling simulator! We hope you have a great flight!\n");

    return 0;
}