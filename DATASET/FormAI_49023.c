//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CAPACITY 50 // Maximum capacity of the conveyor belt
#define MAX_WEIGHT 100 // Maximum weight of a luggage
#define MAX_LUGGAGE 20 // Maximum number of luggage in a batch
#define MAX_BATCHES 5 // Maximum number of batches in a round
#define WAIT_TIME 1 // Wait time between handling each luggage in seconds

enum FlightStatus { ARRIVAL, DEPARTURE }; // Enum for flight status
enum LuggageStatus { LOADING, UNLOADING }; // Enum for luggage status

struct Luggage {
    int weight;
    enum FlightStatus flight_status;
    enum LuggageStatus luggage_status;
};

void conveyor_belt(struct Luggage *luggages, int count) { // Function to simulate conveyor belt
    printf("Conveyor Belt: ");
    for(int i = 0; i < count; i++) {
        if(luggages[i].luggage_status == LOADING) {
            printf("[ %d kg %s luggage (loading) ] ", luggages[i].weight, luggages[i].flight_status == ARRIVAL ? "arrival" : "departure");
        }
        else {
            printf("[ %d kg %s luggage (unloading) ] ", luggages[i].weight, luggages[i].flight_status == ARRIVAL ? "arrival" : "departure");
        }
    }
    printf("\n");
}

void load_luggage(struct Luggage *luggages, int count) { // Function to simulate loading of luggage
    for(int i = 0; i < count; i++) {
        luggages[i].luggage_status = LOADING;
        conveyor_belt(luggages, count);
        printf("Loading %d kg %s luggage\n", luggages[i].weight, luggages[i].flight_status == ARRIVAL ? "arrival" : "departure");
        sleep(WAIT_TIME);
    }
}

void unload_luggage(struct Luggage *luggages, int count) { // Function to simulate unloading of luggage
    for(int i = count-1; i >= 0; i--) {
        luggages[i].luggage_status = UNLOADING;
        conveyor_belt(luggages, count);
        printf("Unloading %d kg %s luggage\n", luggages[i].weight, luggages[i].flight_status == ARRIVAL ? "arrival" : "departure");
        sleep(WAIT_TIME);
    }
}

int main() {
    struct Luggage batches[MAX_BATCHES][MAX_LUGGAGE];
    int count = 0;
    srand(time(0)); // Seed for generating random numbers

    for(int i = 0; i < MAX_BATCHES; i++) { // Generating random batches of luggage
        for(int j = 0; j < MAX_LUGGAGE; j++) {
            batches[i][j].weight = rand() % MAX_WEIGHT + 1;
            batches[i][j].flight_status = (rand() % 2 == 0) ? ARRIVAL : DEPARTURE;
        }
    }

    for(int i = 0; i < MAX_BATCHES; i++) { // Processing each batch of luggage
        count = 0;
        for(int j = 0; j < MAX_LUGGAGE; j++) {
            if(batches[i][j].flight_status == ARRIVAL) {
                if(count + 1 <= MAX_CAPACITY) { // Loading arrival luggage
                    batches[i][j].luggage_status = LOADING;
                    conveyor_belt(batches[i], count + 1);
                    printf("Loading %d kg arrival luggage\n", batches[i][j].weight);
                    sleep(WAIT_TIME);
                    count++;
                }
                else { // Conveyor belt is full, unload first before loading
                    unload_luggage(batches[i], count);
                    batches[i][j].luggage_status = LOADING;
                    conveyor_belt(batches[i], count + 1);
                    printf("Loading %d kg arrival luggage\n", batches[i][j].weight);
                    sleep(WAIT_TIME);
                    count++;
                }
            }
        }

        if(count == MAX_CAPACITY) { // Conveyor belt is full, unload before processing departure luggage
            unload_luggage(batches[i], count);
            count = 0;
        }

        for(int j = 0; j < MAX_LUGGAGE; j++) {
            if(batches[i][j].flight_status == DEPARTURE) {
                if(count + 1 <= MAX_CAPACITY) { // Loading departure luggage
                    batches[i][j].luggage_status = LOADING;
                    conveyor_belt(batches[i], count + 1);
                    printf("Loading %d kg departure luggage\n", batches[i][j].weight);
                    sleep(WAIT_TIME);
                    count++;
                }
                else { // Conveyor belt is full, unload first before loading
                    unload_luggage(batches[i], count);
                    batches[i][j].luggage_status = LOADING;
                    conveyor_belt(batches[i], count + 1);
                    printf("Loading %d kg departure luggage\n", batches[i][j].weight);
                    sleep(WAIT_TIME);
                    count++;
                }
            }
        }

        unload_luggage(batches[i], count); // Unloading remaining luggage before processing next batch
    }

    return 0;
}