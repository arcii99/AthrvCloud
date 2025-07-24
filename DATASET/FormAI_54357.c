//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 50
#define MAX_BELTS 5

int main()
{
    int bags_to_process = MAX_BAGS;
    int belts_available = MAX_BELTS;
    int total_weight_processed = 0;
    int delay_count = 0;
    
    srand(time(NULL)); //initialize random number generator
    
    printf("Welcome to the airport baggage handling simulation!\n");
    printf("We've got %d bags to process and %d belts available.\n", MAX_BAGS, MAX_BELTS);
    
    while (bags_to_process > 0)
    {
        int current_bag_weight = rand() % MAX_WEIGHT + 1;
        
        if (belts_available > 0)
        {
            printf("A bag weighing %d kg is now being processed on Belt %d.\n", current_bag_weight, belts_available);
            total_weight_processed += current_bag_weight;
            belts_available--;
            bags_to_process--;
        }
        else
        {
            printf("All belts are currently in use. Please wait...\n");
            delay_count++;
        }
        
        //add a slight delay between bag processing to simulate real-life scenarios
        struct timespec delay = {0, 500000000};
        nanosleep(&delay, NULL);
        
        //check if any belts have become available
        if (belts_available < MAX_BELTS)
        {
            belts_available++;
            printf("Belt %d is now available.\n", belts_available);
        }
    }
    
    printf("All bags have been processed!\n");
    printf("Total weight processed: %d kg\n", total_weight_processed);
    printf("Number of delays experienced: %d\n", delay_count);
    
    return 0;
}