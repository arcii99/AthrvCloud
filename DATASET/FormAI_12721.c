//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
 
//Declaration of global Variables
int MAX_CAPACITY = 100;
int bags_at_belt = 0;
int total_bags_processed = 0;
int bags_accepted = 0;
int bags_rejected = 0;
 
pthread_mutex_t lock;

/* Function to Handle the movement of bags */
void *bagMover(void *args)
{
    while (1) {
        // Lock the processing until bags are moved
        pthread_mutex_lock(&lock);
 
        // check if capacity is full or not
        if (bags_at_belt <= MAX_CAPACITY) {
            bags_at_belt++;
            bags_accepted++;
            printf("\nBag has been added to the belt!"
                   " Total Number of Bags till now: %d\n",
                   bags_at_belt);
        }
        else {
            printf("\nCapacity is full! Bag rejected!\n");
            bags_rejected++;
        }
        total_bags_processed++;
 
        // Unlock the processing
        pthread_mutex_unlock(&lock);
        usleep(1000);
    }
}
 
int main()
{
    // Declaration of Variables
    pthread_t tid[5];
    int i;
 
    // Mutex Initialization
    pthread_mutex_init(&lock, NULL);
 
    // Spawning 5 Threads
    for (i = 0; i < 5; i++) {
        if (pthread_create(&tid[i], NULL, &bagMover, NULL) != 0) {
            printf("\nThread creation failed..!\n");
            return 1;
        }
    }
 
    // Joining 5 Threads
    for (i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }
 
    pthread_mutex_destroy(&lock);
 
    // Final Output
    printf("\n Final Report:\n");
    printf(" Total Bags Processed: %d\n", total_bags_processed);
    printf(" Total Bags Accepted: %d\n", bags_accepted);
    printf(" Total Bags Rejected: %d\n", bags_rejected);
 
    return 0;
}