//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_bags = rand() % 51 + 50;  // random number of bags between 50 and 100
    int num_terminals = rand() % 4 + 2;  // random number of terminals between 2 and 5
    int num_carousels = rand() % 3 + 1;  // random number of carousels between 1 and 3
    
    printf("Simulating an airport baggage handling system...\n");
    printf("Number of bags: %d\n", num_bags);
    printf("Number of terminals: %d\n", num_terminals);
    printf("Number of carousels: %d\n", num_carousels);
    
    int total_time = 0;
    for (int i = 1; i <= num_bags; i++) {
        int terminal_num = rand() % num_terminals + 1;
        int carousel_num = rand() % num_carousels + 1;
        int bag_time = rand() % 11 + 10;  // random bag processing time between 10 and 20 seconds
        printf("Bag %d is being processed at terminal %d and will arrive at carousel %d in %d seconds.\n", i, terminal_num, carousel_num, bag_time);
        total_time += bag_time;
    }
    
    printf("All bags processed. Total time: %d seconds.\n", total_time);
    
    return 0;
}