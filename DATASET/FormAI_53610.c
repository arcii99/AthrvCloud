//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100 // Maximum bags that can be in system
#define MAX_QUEUE_SIZE 10 // Maximum number of bags that can be waiting

struct Baggage {
    int id;
    int weight;
    int destination;
};

// Global variables
int current_weight = 0;
int current_queue_size = 0;
int current_waiting_time = 0;
struct Baggage baggage_queue[MAX_QUEUE_SIZE];
int current_bags_count = 0;

// Function that simulates the baggage handling
void handle_bags() {
    while (1) {
        if (current_queue_size == 0) { // If there are no bags waiting
            printf("Waiting for bags...\n");
            sleep(2);
            continue;
        }
        
        // If there are bags waiting
        struct Baggage current_bag = baggage_queue[0];
        current_queue_size--;
        current_bags_count--;
        current_weight -= current_bag.weight;
        
        printf("Bag with ID %d weighing %d kgs headed to destination %d has been processed.\n", 
            current_bag.id, current_bag.weight, current_bag.destination);
        
        current_waiting_time += 2; // Increase waiting time
        
        // Wait for some time before processing next bag
        int sleep_time = (rand() % 5) + 1;
        printf("Waiting for %d seconds before processing next bag...\n", sleep_time);
        sleep(sleep_time);
    }
}

// Function that adds a bag to the queue
void add_to_queue(struct Baggage bag) {
    if (current_queue_size == MAX_QUEUE_SIZE) { // If queue is full
        printf("Queue is full. Please wait...\n");
        return;
    }
    
    if (current_weight + bag.weight > 1000) { // If baggage weight exceeds limit
        printf("Weight limit exceeded. Bag with ID %d cannot be added. Please remove some weight from the queue.\n", bag.id);
        return;
    }
    
    printf("Bag with ID %d weighing %d kgs headed to destination %d has been added to the queue.\n", 
        bag.id, bag.weight, bag.destination);
    
    current_queue_size++;
    current_weight += bag.weight;
    
    // Add bag to queue
    baggage_queue[current_queue_size-1] = bag;
}

int main() {
    srand(time(0)); // Seed for random number generator
    
    // Create a few sample bags
    struct Baggage bag1 = { .id = 1, .weight = 20, .destination = 2 };
    struct Baggage bag2 = { .id = 2, .weight = 15, .destination = 1 };
    struct Baggage bag3 = { .id = 3, .weight = 30, .destination = 3 };
    struct Baggage bag4 = { .id = 4, .weight = 18, .destination = 2 };
    struct Baggage bag5 = { .id = 5, .weight = 23, .destination = 1 };
    
    // Add bags to queue
    add_to_queue(bag1);
    add_to_queue(bag2);
    add_to_queue(bag3);
    add_to_queue(bag4);
    add_to_queue(bag5);
    
    // Start handling bags asynchronously
    handle_bags();
    
    return 0;
}