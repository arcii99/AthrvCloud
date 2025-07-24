//FormAI DATASET v1.0 Category: Digital Auction System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for starting and ending bid values
#define MAX_BID 1000
#define MIN_BID 10

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Generate random item number
    int item_number = rand() % 1000 + 1;
    
    // Initialize starting bid and current bid
    int starting_bid = rand() % (MAX_BID - MIN_BID + 1) + MIN_BID;
    int current_bid = starting_bid;
    
    // Print out item number and starting bid
    printf("Item number: %d\nStarting bid: $%d\n", item_number, starting_bid);
    
    // User input to bid on the item
    printf("Enter your bid: $");
    scanf("%d", &current_bid);
    
    // Loop until bid is invalid or user stops bidding
    while (current_bid > 0 && current_bid > starting_bid) {
        // Generate random counter bid from other bidders
        int counter_bid = rand() % (MAX_BID - current_bid + 1) + current_bid;
        printf("Current bid is $%d, counter bid is $%d.\n", current_bid, counter_bid);
        
        // User input to place a higher bid or stop bidding
        printf("Enter your bid (or 0 to stop): $");
        scanf("%d", &current_bid);
    }
    
    // Print out final bid amount and whether user won or lost
    if (current_bid >= starting_bid) {
        printf("Congratulations, you won the auction for $%d!\n", current_bid);
    } else {
        printf("Sorry, you were outbid. The final bid was $%d.\n", starting_bid);
    }
    
    return 0;
}