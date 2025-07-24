//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000 // maximum number of bags that can be handled
#define MAX_WEIGHT 50 // maximum weight of a single bag
#define MAX_WAIT 30 // maximum time a bag can wait before it is handled
#define MAX_PROCESS_TIME 10 // maximum time taken to handle a single bag

int main() {
    srand(time(NULL)); // initialize random number generator
    
    int total_bags = rand() % MAX_BAGS + 1; // generate random number of bags
    printf("Total bags to be handled: %d\n", total_bags);
    
    int bags_processed = 0; // initialize bags processed to 0
    
    while (bags_processed < total_bags) {
        int bags_waiting = total_bags - bags_processed; // current number of bags waiting
        
        int next_bag_wait_time = rand() % MAX_WAIT + 1; // time until next bag is ready to be handled
        printf("Waiting for %d bags for %d minutes...\n", bags_waiting, next_bag_wait_time);
        sleep(next_bag_wait_time); // simulate waiting for bags
        
        int bags_ready = rand() % (bags_waiting + 1); // generate random number of bags ready to be handled
        printf("%d bags are now ready to be handled.\n", bags_ready);
        
        for (int i = 0; i < bags_ready; i++) {
            int bag_weight = rand() % MAX_WEIGHT + 1; // generate random weight for bag
            int process_time = rand() % MAX_PROCESS_TIME + 1; // generate random processing time for bag
            
            printf("Handling bag %d (weight: %d kg)...\n", bags_processed + 1, bag_weight);
            sleep(process_time); // simulate bag handling time
            
            printf("Bag %d handled in %d minutes.\n", bags_processed + 1, process_time);
            bags_processed++;
        }
        
        printf("%d bags remaining to be handled.\n", total_bags - bags_processed);
    }
    
    printf("All bags handled successfully!\n");
    
    return 0;
}