//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_BAGS 50
#define MAX_THREADS 10

typedef struct {
    int bag_id;
    int plane_id;
} baggage;

baggage airport_bags[MAX_BAGS]; // array of bags in the airport
int num_bags = 0; // number of bags in the airport

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex to ensure thread-safety
pthread_cond_t bag_ready_cond = PTHREAD_COND_INITIALIZER; // condition variable for notifying handlers

void* baggage_handler(void* arg) {
    int handler_id = *(int*)arg;
    printf("Baggage handler %d: Ready to work!\n", handler_id);
    while (1) {
        pthread_mutex_lock(&mutex);
        while (num_bags == 0) { // wait while there are no bags to handle
            printf("Baggage handler %d: No bags to handle, going to sleep...\n", handler_id);
            pthread_cond_wait(&bag_ready_cond, &mutex);
            printf("Baggage handler %d: Woken up, bags are ready to handle!\n", handler_id);
        }
        // remove and process one bag from the array
        baggage bag = airport_bags[--num_bags];
        printf("Baggage handler %d: Handling bag %d for plane %d...\n", handler_id, bag.bag_id, bag.plane_id);
        pthread_mutex_unlock(&mutex);
        // simulate handling time by sleeping for a random amount of time
        int handle_time = rand() % 5 + 1;
        printf("Baggage handler %d: Handling time for bag %d is %d seconds\n", handler_id, bag.bag_id, handle_time);
        sleep(handle_time);
    }
    return NULL;
}

void add_baggage(int plane_id) {
    if (num_bags >= MAX_BAGS) return; // airport is full of bags
    // add a new bag to the array
    baggage bag;
    bag.bag_id = num_bags + 1;
    bag.plane_id = plane_id;
    airport_bags[num_bags++] = bag;
    printf("New bag %d added for plane %d\n", bag.bag_id, plane_id);
    // signal the handlers that a new bag is ready
    pthread_cond_signal(&bag_ready_cond);
}

int main() {
    // create handler threads
    pthread_t handlers[MAX_THREADS];
    int handler_ids[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        handler_ids[i] = i + 1;
        pthread_create(&handlers[i], NULL, baggage_handler, &handler_ids[i]);
    }
    // simulate planes landing and adding bags
    for (int i = 1; i <= 5; i++) {
        printf("Plane %d landing...\n", i);
        int num_bags = rand() % 10 + 1;
        for (int j = 0; j < num_bags; j++) {
            add_baggage(i);
        }
    }
    return 0;
}