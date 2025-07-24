//FormAI DATASET v1.0 Category: Digital Auction System ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold information for each bid
typedef struct {
    char bidder_name[50];
    int bid_amount;
} Bid;

// Define a function to find the highest bid
Bid get_highest_bid(Bid *bids, int num_bids) {
    Bid highest_bid = {"", 0};
    for (int i = 0; i < num_bids; i++) {
        if (bids[i].bid_amount > highest_bid.bid_amount) {
            highest_bid = bids[i];
        }
    }
    return highest_bid;
}

int main() {
    int num_bidders, starting_bid, current_bid = 0, round_num = 1;
    printf("Welcome to the Digital Auction System!\n");
    printf("How many bidders are participating in this auction? ");
    scanf("%d", &num_bidders);
    printf("What is the starting bid for this auction? $");
    scanf("%d", &starting_bid);
    Bid *bids = malloc(num_bidders * sizeof(Bid));
    while (current_bid < starting_bid) {
        printf("\n\n--- Round %d ---\n", round_num);
        for (int i = 0; i < num_bidders; i++) {
            printf("Bidder %d, what is your name? ", i + 1);
            scanf("%s", bids[i].bidder_name);
            printf("What is your bid, %s? $", bids[i].bidder_name);
            scanf("%d", &bids[i].bid_amount);
        }
        Bid highest_bid = get_highest_bid(bids, num_bidders);
        printf("\nThe highest bid is $%d by %s!\n", highest_bid.bid_amount, highest_bid.bidder_name);
        if (highest_bid.bid_amount < starting_bid) {
            printf("Sorry, the bid is not high enough. Please try again in the next round.\n");
            round_num++;
        } else {
            printf("Congratulations, %s! You won the auction with a bid of $%d.\n", highest_bid.bidder_name, highest_bid.bid_amount);
            break;
        }
    }
    free(bids);
    return 0;
}