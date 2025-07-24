//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int bid;
} Bidder;

int main() {
    Bidder bidders[MAX_BIDS];
    int num_bidders = 0;
    int current_bid = 0;
    int current_bidder_index = -1;
    
    // Populate bidders array
    strcpy(bidders[0].name, "Alice");
    bidders[0].bid = 10;
    strcpy(bidders[1].name, "Bob");
    bidders[1].bid = 15;
    num_bidders = 2;
    
    // Find current highest bid and bidder
    for (int i = 0; i < num_bidders; i++) {
        if (bidders[i].bid > current_bid) {
            current_bid = bidders[i].bid;
            current_bidder_index = i;
        }
    }
    
    // Print out results
    printf("Current highest bid: %d\n", current_bid);
    printf("Current highest bidder: %s\n", bidders[current_bidder_index].name);
    
    // Add a new bidder
    strcpy(bidders[num_bidders].name, "Charlie");
    bidders[num_bidders].bid = 20;
    num_bidders++;
    
    // Find new current highest bid and bidder
    current_bid = 0;
    current_bidder_index = -1;
    for (int i = 0; i < num_bidders; i++) {
        if (bidders[i].bid > current_bid) {
            current_bid = bidders[i].bid;
            current_bidder_index = i;
        }
    }
    
    // Print out updated results
    printf("Updated highest bid: %d\n", current_bid);
    printf("Updated highest bidder: %s\n", bidders[current_bidder_index].name);
    
    return 0;
}