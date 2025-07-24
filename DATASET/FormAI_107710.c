//FormAI DATASET v1.0 Category: Digital Auction System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bid = 0;
    int winning_bid = 0;
    
    srand(time(NULL));  // Seed the random number generator
    
    printf("Welcome to the Digital Auction System!\n\n");
    printf("Item for Auction: Antique Gold Watch\n");
    printf("Starting bid: $10000\n\n");
    
    // Start the bidding process
    while (1) {
        printf("Enter your bid (in USD): ");
        scanf("%d", &bid);
        
        if (bid <= winning_bid) {
            printf("Your bid must be higher than the current winning bid ($%d)\n\n", winning_bid);
        } else if (bid < 10000) {
            printf("Your bid is too low. The minimum bid is $10000\n\n");
        } else {
            // Generate a random bidder number between 1 and 100
            int bidder_num = rand() % 100 + 1;
            
            // Display the winning bidder and bid amount
            printf("Congratulations, bidder %d! You are the current winning bidder with a bid of $%d\n\n", bidder_num, bid);
            
            // Update the winning_bid variable
            winning_bid = bid;
        }
    }
    
    return 0;
}