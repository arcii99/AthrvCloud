//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
/* The Case of the Missing Luggage */

#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of bags that can be handled
#define MAX_BAGS 100

// Define the structure for each piece of luggage
struct Baggage {
    int id;
    int weight;
};

// Define the structure for each checkpoint in the airport
struct Checkpoint {
    char name[20];
    int capacity;
    int num_bags;
    struct Baggage bags[MAX_BAGS];
};

// Define the function to add a bag to a checkpoint
void add_bag(struct Checkpoint *cp, struct Baggage bag) {
    if (cp->num_bags >= cp->capacity) {
        printf("%s checkpoint is full!\n", cp->name);
    } else {
        cp->bags[cp->num_bags++] = bag;
        printf("Added bag with ID %d to %s checkpoint.\n", bag.id, cp->name);
    }
}

// Define the function to remove a bag from a checkpoint
void remove_bag(struct Checkpoint *cp, int bag_id) {
    int i;

    for (i = 0; i < cp->num_bags; i++) {
        if (cp->bags[i].id == bag_id) {
            printf("Removed bag with ID %d from %s checkpoint.\n", bag_id, cp->name);
            cp->bags[i] = cp->bags[--cp->num_bags];
            return;
        }
    }

    printf("Bag with ID %d not found at %s checkpoint.\n", bag_id, cp->name);
}

int main() {
    // Create the checkpoint structures
    struct Checkpoint check_in = {"Check-In", 10, 0};
    struct Checkpoint security = {"Security", 20, 0};
    struct Checkpoint baggage_claim = {"Baggage Claim", 50, 0};

    // Add some bags to the Check-In checkpoint
    add_bag(&check_in, (struct Baggage) {1, 20});
    add_bag(&check_in, (struct Baggage) {2, 15});
    add_bag(&check_in, (struct Baggage) {3, 10});
    add_bag(&check_in, (struct Baggage) {4, 25});

    // Move some bags from Check-In to Security
    remove_bag(&check_in, 1);
    remove_bag(&check_in, 3);
    add_bag(&security, (struct Baggage) {1, 20});
    add_bag(&security, (struct Baggage) {3, 10});

    // Move some bags from Security to Baggage Claim
    remove_bag(&security, 1);
    remove_bag(&security, 3);
    add_bag(&baggage_claim, (struct Baggage) {1, 20});
    add_bag(&baggage_claim, (struct Baggage) {3, 10});

    return 0;
}