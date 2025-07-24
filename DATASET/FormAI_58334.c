//FormAI DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int numItems, numBidders, minBid, maxBid;
    
    printf("Welcome to the Medieval Digital Auction System!\n\n");
    
    // Get number of items to auction
    printf("How many items would you like to auction?\n");
    scanf("%d", &numItems);
    
    // Get number of bidders
    printf("How many bidders will be participating in the auction?\n");
    scanf("%d", &numBidders);
    
    // Specify minimum and maximum bid values
    printf("What is the minimum bid value for each item?\n");
    scanf("%d", &minBid);
    
    printf("What is the maximum bid value for each item?\n");
    scanf("%d", &maxBid);
    
    printf("Let the auction begin!\n\n");
    
    for (int i = 1; i <= numItems; i++) {
        printf("Item %d up for auction!\n", i);
        int highestBid = 0, bidderID = 0;
        
        for (int j = 1; j <= numBidders; j++) {
            int currentBid = (rand() % (maxBid - minBid + 1)) + minBid;
            printf("Bidder %d has placed a bid of %d.\n", j, currentBid);
            
            if (currentBid > highestBid) {
                highestBid = currentBid;
                bidderID = j;
            }
        }
        
        printf("\nThe winner is Bidder %d with a bid of %d!\n\n", bidderID, highestBid);
    }
    
    printf("Thanks for using the Medieval Digital Auction System!\n");
    
    return 0;
}