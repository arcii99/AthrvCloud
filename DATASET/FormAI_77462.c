//FormAI DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int num_bidders;
    printf("Welcome to the Digital Auction System of the Future!\n");
    printf("Please enter the number of bidders: ");
    scanf("%d", &num_bidders);
    int bids[num_bidders];
    int highest_bid = 0;
    int highest_bidder_index = 0;
    printf("The auction has started!\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("Bidder %d, please enter your bid: ", i+1);
        scanf("%d", &bids[i]);
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
            highest_bidder_index = i;
        }
    }
    printf("\nThe bidding has ended!\n");
    printf("The winning bid is %d, by bidder %d.\n", highest_bid, highest_bidder_index+1);
    printf("Congratulations to the winner! Payment will be processed shortly.");
    return 0;
}