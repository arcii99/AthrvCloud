//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 50
#define MAX_FLIGHTS 10

int main(void)
{
    // Initialize variables
    int num_bags = 0;
    int num_flights = 0;
    int bags_processed = 0;
    int bags_in_queue = 0;
    int bags_in_flight = 0;
    int total_weight = 0;
    int bags_per_flight[MAX_FLIGHTS] = {0};
    int weights_per_flight[MAX_FLIGHTS] = {0};
    
    // Get number of bags and flights from user
    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");
    printf("Please enter the number of bags to process: ");
    scanf("%d", &num_bags);
    printf("Please enter the number of flights: ");
    scanf("%d", &num_flights);
    printf("\n");
    
    // Seed random number generator
    srand(time(NULL));
    
    // Loop through bags and assign them to flights
    for (int i = 1; i <= num_bags; i++)
    {
        int weight = rand() % MAX_WEIGHT + 1;
        total_weight += weight;
        bags_in_queue++;
        
        // Decide which flight to assign bag to
        int flight = rand() % num_flights;
        bags_per_flight[flight]++;
        weights_per_flight[flight] += weight;
        
        // Simulate baggage screening process
        if (rand() % 2 == 0)
        {
            bags_processed++;
            bags_in_queue--;
            
            if (rand() % 2 == 0)
            {
                bags_in_flight++;
                
                printf("Bag %d (Flight %d) has been loaded and is in flight!\n", i, flight);
            }
            else
            {
                printf("Bag %d (Flight %d) has been processed and is waiting for loading.\n", i, flight);
            }
        }
        else
        {
            printf("Bag %d (Flight %d) contains prohibited item and will not board flight.\n", i, flight);
        }
    }
    
    // Print summary of baggage handling
    printf("\nBaggage Handling Summary\n");
    printf("=========================\n\n");
    printf("Total bags processed: %d\n", bags_processed);
    printf("Total bags in queue: %d\n", bags_in_queue);
    printf("Total bags in flight: %d\n", bags_in_flight);
    printf("Total weight of bags: %d kg\n\n", total_weight);
    printf("Bags per Flight:\n");
    for (int i = 0; i < num_flights; i++)
    {
        printf("Flight %d: %d bags (%d kg)\n", i, bags_per_flight[i], weights_per_flight[i]);
    }
    
    return 0;
}