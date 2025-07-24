//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM_BAGS 100

// Bag struct to hold bag information
typedef struct {
    int bag_id;
    bool is_priority;
} Bag;

// Function to generate random bag ID
int generate_bag_id() {
    return rand() % 1000 + 1;
}

// Function to create a new bag
Bag create_bag() {
    Bag new_bag;
    new_bag.bag_id = generate_bag_id();
    new_bag.is_priority = rand() % 2 == 0;
    return new_bag;
}

int main() {
    // Initialize queue for bags waiting to be checked
    Bag check_queue[MAX_NUM_BAGS];
    int num_bags_to_check = 0;

    // Initialize array for checked bags
    Bag checked_bags[MAX_NUM_BAGS];
    int num_checked_bags = 0;

    srand(time(NULL)); // Initialize random seed

    // Simulate bags being dropped off by passengers
    for (int i = 0; i < MAX_NUM_BAGS; i++) {
        Bag new_bag = create_bag();

        if (new_bag.is_priority) {
            printf("Bag with ID %d is a priority bag.\n", new_bag.bag_id);
            check_queue[num_bags_to_check++] = new_bag; // Add to front of check queue
        } else {
            printf("Bag with ID %d is a regular bag.\n", new_bag.bag_id);
            check_queue[num_bags_to_check++] = new_bag; // Add to end of check queue
        }

        printf("%d bags are waiting to be checked.\n", num_bags_to_check);
    }

    // Simulate bags being checked
    while (num_bags_to_check > 0) {
        Bag current_bag = check_queue[--num_bags_to_check]; // Remove bag from check queue
        printf("Checking bag with ID %d...\n", current_bag.bag_id);

        // Simulate bag being lost
        if (rand() % 10 == 0) {
            printf("*** Bag with ID %d was lost! ***\n", current_bag.bag_id);
        } else {
            checked_bags[num_checked_bags++] = current_bag; // Add bag to checked bags array
            printf("Bag with ID %d has been checked.\n", current_bag.bag_id);
        }
    }

    printf("%d bags were checked successfully.\n", num_checked_bags);

    return 0;
}