//FormAI DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BID 1000

int main() {
    int item_number, num_bids, bid, current_bid;
    char bidder_name[30], highest_bidder[30];

    srand(time(0)); // seed the random number generator

    // generate a random item number
    item_number = rand() % 1000 + 1;

    // prompt user for number of bids
    printf("Enter number of bids: ");
    scanf("%d", &num_bids);

    // initialize current_bid to a random value
    current_bid = rand() % MAX_BID;

    // loop through each bid
    for (int i = 0; i < num_bids; i++) {
        printf("Enter bidder name: ");
        scanf("%s", bidder_name);

        printf("Enter bid amount: ");
        scanf("%d", &bid);

        // check if bid is higher than current_bid
        if (bid > current_bid) {
            printf("Current highest bidder is %s with a bid of %d\n", bidder_name, bid);
            current_bid = bid;
            strcpy(highest_bidder, bidder_name);
        } else {
            printf("Bid rejected. Current highest bid is %d by %s\n", current_bid, highest_bidder);
        }
    }

    // print out final results
    printf("\n\nFinal Results:\n");
    printf("Item Number: %d\n", item_number);
    printf("Highest Bidder: %s\n", highest_bidder);
    printf("Highest Bid: %d\n", current_bid);

    return 0;
}