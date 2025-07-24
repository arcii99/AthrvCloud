//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition for item to be auctioned
struct Item {
    char name[50];
    char description[200];
    int id;
    float price;
    int seller_id;
    int bidder_id;
};

// Structure definition for bidder
struct Bidder {
    char name[50];
    int id;
    float balance;
};

// Structure definition for auction
struct Auction {
    struct Item product;
    struct Bidder highest_bidder;
    float highest_bid;
    int status; // 0 - auction not started, 1 - accepting bids, 2 - closed
};

// Function prototype for displaying auction details
void display_auction(struct Auction auction) {
    printf("\n\nItem Details:");
    printf("\nName: %s", auction.product.name);
    printf("\nDescription: %s", auction.product.description);
    printf("\nID: %d", auction.product.id);
    printf("\nSeller ID: %d", auction.product.seller_id);

    printf("\n\nAuction Details:");
    printf("\nStatus: %d", auction.status);
    printf("\nHighest Bidder: %s", auction.highest_bidder.name);
    printf("\nHighest Bid: %.2f", auction.highest_bid);
}

int main() {
    struct Auction auction;

    // Initializing item details
    strcpy(auction.product.name, "Fender Guitar");
    strcpy(auction.product.description, "A classic electric guitar.");
    auction.product.id = 101;
    auction.product.price = 500.0;
    auction.product.seller_id = 201;

    // Initializing auction details
    auction.status = 0;
    auction.highest_bid = 0;

    // Initializing bidder details
    struct Bidder bidders[3];
    strcpy(bidders[0].name, "John");
    bidders[0].id = 301;
    bidders[0].balance = 1000.0;
    strcpy(bidders[1].name, "Mary");
    bidders[1].id = 302;
    bidders[1].balance = 1500.0;
    strcpy(bidders[2].name, "Bob");
    bidders[2].id = 303;
    bidders[2].balance = 2000.0;

    // Starting auction
    auction.status = 1;

    while (auction.status == 1) {
        display_auction(auction);

        // Accepting bids from bidders
        for (int i = 0; i < 3; i++) {
            printf("\n%s, enter your bid: ", bidders[i].name);
            float bid;
            scanf("%f", &bid);

            if (bid > bidders[i].balance) {
                printf("You don't have enough balance to make this bid.");
                continue;
            }

            if (bid > auction.highest_bid) {
                auction.highest_bid = bid;
                auction.highest_bidder = bidders[i];
                printf("\nNew highest bid is %.2f by %s", bid, bidders[i].name);
            } else {
                printf("\nYour bid is not high enough.");
            }
        }

        // Closing auction
        printf("\nDo you want to close the auction? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y') {
            auction.status = 2;

            // Deducting highest bid from bidder's balance
            for (int i = 0; i < 3; i++) {
                if (bidders[i].id == auction.highest_bidder.id) {
                    bidders[i].balance -= auction.highest_bid;
                }
            }
        }
    }

    // Auction closed
    display_auction(auction);

    printf("\n\nBidders Information:");
    for (int i = 0; i < 3; i++) {
        printf("\nName: %s, ID: %d, Balance: %.2f\n", bidders[i].name, bidders[i].id, bidders[i].balance);
    }

    return 0;
}