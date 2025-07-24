//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some constants
#define MAX_BAGGAGE 100
#define MAX_FLIGHTS 10
#define MAX_SEATS 5

// Define the struct for baggage
typedef struct {
    int weight;
    char type[20];
} Baggage;

// Define the struct for flights
typedef struct {
    char destination[20];
    int seats[MAX_SEATS];
    Baggage baggage[MAX_BAGGAGE];
    int num_passengers;
    int num_checked_bags;
} Flight;

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Create an array of flights
    Flight flights[MAX_FLIGHTS];
    
    // Initialize the flights
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        // Generate a random destination within the US
        char destinations[][20] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix", "Philadelphia", "San Antonio", "San Diego", "Dallas", "San Jose"};
        int dest_index = rand() % 10;
        strcpy(flights[i].destination, destinations[dest_index]);
        
        // Generate random number of passengers and checked bags
        flights[i].num_passengers = rand() % MAX_SEATS + 1;
        flights[i].num_checked_bags = rand() % MAX_BAGGAGE + 1;
        
        // Initialize seats and baggage
        for (int j = 0; j < MAX_SEATS; j++) {
            flights[i].seats[j] = 0;
        }
        for (int j = 0; j < MAX_BAGGAGE; j++) {
            flights[i].baggage[j].weight = 0;
            strcpy(flights[i].baggage[j].type, "");
        }
    }
    
    // Simulate baggage handling process for each flight
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight to %s\n", flights[i].destination);
        printf("Total number of checked bags: %d\n", flights[i].num_checked_bags);
        
        // Generate random baggage for each passenger
        for (int j = 0; j < flights[i].num_passengers; j++) {
            int num_bags = rand() % 2 + 1;
            for (int k = 0; k < num_bags; k++) {
                int weight = rand() % 50 + 1;
                char types[][20] = {"suitcase", "backpack", "duffle bag", "golf bag", "computer bag"};
                int type_index = rand() % 5;
                strcpy(flights[i].baggage[k].type, types[type_index]);
                flights[i].baggage[k].weight = weight;
            }
        }
        
        // Load baggage onto the plane
        int num_loaded_bags = 0;
        for (int j = 0; j < flights[i].num_checked_bags; j++) {
            if (num_loaded_bags == MAX_BAGGAGE) {
                printf("Cannot load any more bags for flight to %s\n", flights[i].destination);
                break;
            }
            int weight = rand() % 50 + 1;
            char types[][20] = {"suitcase", "backpack", "duffle bag", "golf bag", "computer bag"};
            int type_index = rand() % 5;
            strcpy(flights[i].baggage[num_loaded_bags].type, types[type_index]);
            flights[i].baggage[num_loaded_bags].weight = weight;
            num_loaded_bags++;
        }
        printf("Number of loaded bags: %d\n", num_loaded_bags);
        
        // Unload baggage from the plane
        int num_unloaded_bags = 0;
        for (int j = 0; j < num_loaded_bags; j++) {
            if (num_unloaded_bags == flights[i].num_checked_bags) {
                printf("All bags have been unloaded for flight to %s\n", flights[i].destination);
                break;
            }
            if (strcmp(flights[i].baggage[j].type, "") != 0) {
                printf("Unloading baggage with type %s and weight %d for flight to %s\n", flights[i].baggage[j].type, flights[i].baggage[j].weight, flights[i].destination);
                flights[i].baggage[j].weight = 0;
                strcpy(flights[i].baggage[j].type, "");
                num_unloaded_bags++;
            }
        }
        printf("Number of unloaded bags: %d\n", num_unloaded_bags);
    }
    
    return 0;
}