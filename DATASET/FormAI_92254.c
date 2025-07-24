//FormAI DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bidder {
    char name[50];
    int bid_amount;
};

struct Auction {
    char item_name[50];
    struct Bidder* highest_bidder;
    int highest_bid;
};

int main() {
    struct Auction auction;
    strcpy(auction.item_name, "Antique painting");
    auction.highest_bidder = NULL;
    auction.highest_bid = 0;
    struct Bidder bidders[3];

    // Initialize bidder names
    strcpy(bidders[0].name, "John");
    strcpy(bidders[1].name, "Alice");
    strcpy(bidders[2].name, "Bob");

    // Start bidding process
    printf("Welcome to the digital auction system for %s!\n", auction.item_name);
    for (int i = 0; i < 3; i++) {
        printf("%s, please enter your bid: $", bidders[i].name);
        scanf("%d", &bidders[i].bid_amount);

        // Check if bid is higher than current highest bid
        if (bidders[i].bid_amount > auction.highest_bid) {
            auction.highest_bidder = &bidders[i];
            auction.highest_bid = bidders[i].bid_amount;
            printf("Congratulations, %s, you have the highest bid at $%d!\n", bidders[i].name, bidders[i].bid_amount);
        }
        else {
            printf("Sorry, %s, your bid of $%d was not high enough. The current highest bid is $%d.\n", bidders[i].name, bidders[i].bid_amount, auction.highest_bid);
        }
    }

    // Display winning bidder
    printf("\nThe auction for %s is now closed. The winner is %s with a bid of $%d!\n", auction.item_name, auction.highest_bidder->name, auction.highest_bid);

    return 0;
}