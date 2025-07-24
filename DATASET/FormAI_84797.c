//FormAI DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator

    int num_bidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    int min_bid, max_bid;
    printf("Enter the minimum and maximum bids: ");
    scanf("%d %d", &min_bid, &max_bid);

    int current_bid = min_bid;
    int winning_bid = 0;
    int winning_bidder = 0;

    while (current_bid <= max_bid) {
        printf("Current bid: $%d\n", current_bid);

        for (int i = 1; i <= num_bidders; i++) {
            printf("Bidder %d, enter your bid: ", i);
            int bid;
            scanf("%d", &bid);

            if (bid > winning_bid) {
                winning_bid = bid;
                winning_bidder = i;
            } else if (bid == winning_bid) {
                // flip a coin to decide the winner
                if (rand() % 2 == 0) {
                    winning_bidder = i;
                }
            }
        }

        printf("Winning bid: $%d, by bidder %d\n", winning_bid, winning_bidder);

        // increase the current bid
        current_bid = winning_bid + 1;
        winning_bid = 0;
        winning_bidder = 0;
    }

    return 0;
}