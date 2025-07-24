//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_BAGS_PER_FLIGHT 100
#define MAX_FLIGHTS 10
#define MAX_BAGS 1000

int flight[MAX_FLIGHTS][MAX_BAGS_PER_FLIGHT];             // Array of flights and bags
int bags_processed[MAX_BAGS];                             // Array of processed bags
int num_bags_processed = 0;                                // Total number of processed bags
int num_flights_ready = 0;                                 // Total number of flights ready
int time_spent[MAX_BAGS];                                  // Total time spent processing the bags
int num_bags = 0;                                          // Total number of bags
int max_time = 0;                                          // Maximum time spent processing a bag
int total_time = 0;                                        // Total time spent processing bags
int last_flight = 0;                                       // ID of the last processed flight
int last_bag = 0;                                          // ID of the last processed bag
int bags_needed[MAX_FLIGHTS];                              // Number of bags needed per flight

void generate_flight(int id, int num_bags) {               // Generates a random flight with random number of bags
    int i;
    for (i = 0; i < num_bags; i++) {
        flight[id][i] = rand() % 100 + 1;
    }
    bags_needed[id] = num_bags;
    printf("Flight %d arrived with %d bags.\n", id, num_bags);
}

int check_ready_flight(int id) {                           // Checks if a flight is ready to depart
    int i, num_processed_bags = 0;
    for (i = 0; i < bags_needed[id]; i++) {
        if (flight[id][i] != 0 && bags_processed[flight[id][i]-1] == 1) {
            num_processed_bags++;
        }
    }
    if (num_processed_bags == bags_needed[id]) {
        return 1;
    }
    return 0;
}

void process_bags() {                                      // Processes bags until flights are ready to depart
    int i, j, time;
    while (num_flights_ready < MAX_FLIGHTS) {              // Stops when all flights are ready
        for (i = 0; i < MAX_FLIGHTS; i++) {                // Loops through all flights
            if (check_ready_flight(i) == 1) {              // Checks if the flight is ready
                printf("Flight %d ready to depart.\n", i); 
                num_flights_ready++;
            }
            for (j = 0; j < bags_needed[i]; j++) {         // Loops through all bags of the flight
                if (flight[i][j] != 0 && bags_processed[flight[i][j]-1] == 0) {     // Checks if the bag is not yet processed
                    time = rand() % 10 + 1;
                    total_time += time;
                    time_spent[flight[i][j]-1] += time;
                    if (time_spent[flight[i][j]-1] > max_time) {
                        max_time = time_spent[flight[i][j]-1];
                    }
                    bags_processed[flight[i][j]-1] = 1;
                    printf("Processed bag %d of Flight %d, Time: %d.\n", flight[i][j], i, time);
                    last_flight = i;
                    last_bag = flight[i][j];
                    num_bags_processed++;
                }
            }
        }
        usleep(100);                                      // Simulates delay of processing bags in time units
    }
    printf("All flights ready to depart!\n");
}

void print_statistics() {                                  // Prints simulation statistics
    printf("Simulation Statistics:\n");
    printf("Total Bags Processed: %d\n", num_bags_processed);
    printf("Total Time Spent: %d\n", total_time);
    printf("Average Time Spent per Bag: %.2f\n", (float)total_time/num_bags_processed);
    printf("Maximum Time Spent on a Bag: %d\n", max_time);
    printf("Last Processed Bag: %d of Flight %d\n", last_bag, last_flight);
}

int main() {                                               // Main method
    srand((unsigned) time(NULL));                          // Initializes random seed
    int i, num_bags_flight;
    for (i = 0; i < MAX_FLIGHTS; i++) {                     // Loops through all flights
        num_bags_flight = rand() % MAX_BAGS_PER_FLIGHT + 1; // Generates a random number of bags
        generate_flight(i, num_bags_flight);                // Generates the flight
        num_bags += num_bags_flight;                        // Updates the total number of bags
    }
    process_bags();                                         // Starts processing bags
    print_statistics();                                     // Prints simulation statistics
    return 0;
}