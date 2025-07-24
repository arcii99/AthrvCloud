//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_TERMINALS 3

int main(void) {

    srand(time(NULL));

    int bag_count = rand() % MAX_BAGS + 1;
    int terminal_count = rand() % MAX_TERMINALS + 1;

    printf("Starting Airport Baggage Handling Simulation...\n\n");

    printf("Number of bags: %d\n", bag_count);
    printf("Number of terminals: %d\n\n", terminal_count);

    int bags_per_terminal = bag_count / terminal_count;
    int remaining_bags = bag_count % terminal_count;

    printf("Bags per terminal: %d\n", bags_per_terminal);
    printf("Remaining bags: %d\n\n", remaining_bags);

    int current_terminal = 1;

    printf("Starting baggage transfer...\n\n");

    for (int i = 1; i <= bag_count; i++) {
        printf("Bag %d is being transferred to Terminal %d\n", i, current_terminal);

        if (i % bags_per_terminal == 0 && current_terminal < terminal_count) {
            printf("All bags have been transferred to Terminal %d\n\n", current_terminal);
            current_terminal++;
            printf("Starting transfer to Terminal %d...\n\n", current_terminal);
        }
    }

    if (remaining_bags > 0) {
        printf("Transferring remaining %d bags to Terminal %d...\n", remaining_bags, current_terminal);
    }

    printf("\nSimulated baggage handling complete!\n");

    return 0;
}