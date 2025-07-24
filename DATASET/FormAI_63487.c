//FormAI DATASET v1.0 Category: Digital Auction System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_BID 10 // Minimum bid amount
#define MAX_BID 1000 // Maximum bid amount
#define AUCTION_TIME 10 // Auction time in seconds

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int item_id = rand() % 1000; // Generate a random item ID
    int highest_bid = 0; // Initialize the highest bid to 0
    int current_bid = 0; // Initialize the current bid to 0
    int time_left = AUCTION_TIME; // Initialize the time left for auction
    
    printf("Welcome to the Digital Auction System\n");
    printf("Item ID: %d\n", item_id);
    printf("Minimum bid amount: %d\n", MIN_BID);
    printf("Maximum bid amount: %d\n", MAX_BID);
    printf("Auction time: %d seconds\n", AUCTION_TIME);
    
    while (time_left > 0) { // Auction loop
        printf("\nTime left: %d seconds\n\n", time_left);
        
        // Generate a random bid by adding a random amount to the current bid
        current_bid = highest_bid + rand() % (MAX_BID - highest_bid + 1);
        
        // Check if the current bid is higher than the highest bid
        if (current_bid > highest_bid) {
            printf("New bid: $%d\n", current_bid);
            highest_bid = current_bid;
        } else {
            printf("No new bids.\n");
        }
        
        time_left--;
        sleep(1); // Wait for 1 second
    }
    
    printf("\nAuction closed.\n");
    printf("Item ID: %d\n", item_id);
    printf("Highest bid: $%d\n", highest_bid);
    
    return 0;
}