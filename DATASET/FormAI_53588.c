//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_TERMINALS 5

// Structure to hold information about a bag
typedef struct Bag {
    int id;
    int terminal;
} Bag;

// Function to generate a bag with a random terminal
void generateBag(Bag *bag) {
    bag->id = rand() % MAX_BAGS + 1;
    bag->terminal = rand() % MAX_TERMINALS + 1;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate bags
    Bag bags[MAX_BAGS];
    for (int i = 0; i < MAX_BAGS; i++) {
        generateBag(&bags[i]);
    }

    // Initialize terminals
    int terminals[MAX_TERMINALS] = {0};

    // Process bags
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag bag = bags[i];
        int terminal = bag.terminal;

        printf("Processing bag %d for terminal %d\n", bag.id, terminal);

        // Check if terminal is available
        if (terminals[terminal - 1] == 0) {
            printf("Terminal %d available, sending bag %d\n", terminal, bag.id);
            terminals[terminal - 1] = bag.id;
        } else {
            printf("Terminal %d occupied, sending bag %d to lost and found\n", terminal, bag.id);
        }
    }

    return 0;
}