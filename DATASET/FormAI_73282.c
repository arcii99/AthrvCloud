//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Baggage structure
struct baggage {
    int id;
    bool has_checked;
    bool is_claimed;
};

// Function to generate baggage ID
int generate_id() {
    static int count = 1;
    return count++;
}

// Function to check baggage
void check_baggage(struct baggage* b) {
    b->has_checked = true;
    printf("Baggage %d has been checked.\n", b->id);
}

// Function to claim baggage
void claim_baggage(struct baggage* b) {
    b->is_claimed = true;
    printf("Baggage %d has been claimed.\n", b->id);
}

// Main function
int main() {
    // Generate baggage
    struct baggage b1 = {generate_id(), false, false};
    struct baggage b2 = {generate_id(), false, false};
    struct baggage b3 = {generate_id(), false, false};

    // Check baggage
    check_baggage(&b1);
    check_baggage(&b2);
    check_baggage(&b3);

    // Claim baggage
    claim_baggage(&b1);
    claim_baggage(&b2);
    claim_baggage(&b3);

    return 0;
}