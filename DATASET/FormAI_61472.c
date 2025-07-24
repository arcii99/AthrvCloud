//FormAI DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define MAX_NAME_LEN 20

struct Bidder {
    char name[MAX_NAME_LEN];
    int bid;
};

struct Auction {
    char item_name[MAX_NAME_LEN];
    struct Bidder bidders[MAX_BIDS];
    int num_bidders;
};

void add_bid(struct Auction *auction, char *name, int bid) {
    if (auction->num_bidders == MAX_BIDS) {
        printf("Error: maximum number of bidders reached\n");
        return;
    }

    strcpy(auction->bidders[auction->num_bidders].name, name);
    auction->bidders[auction->num_bidders].bid = bid;
    auction->num_bidders++;

    printf("Bid added for %s: $%d\n", name, bid);
}

void print_winner(struct Auction auction) {
    if (auction.num_bidders == 0) {
        printf("No bids have been placed.\n");
        return;
    }

    int max_bid = auction.bidders[0].bid;
    char *winner_name = auction.bidders[0].name;

    for (int i = 1; i < auction.num_bidders; i++) {
        if (auction.bidders[i].bid > max_bid) {
            max_bid = auction.bidders[i].bid;
            winner_name = auction.bidders[i].name;
        }
    }
    
    printf("The winner of the %s auction is %s with a bid of $%d.\n", 
           auction.item_name, winner_name, max_bid);
}

int main() {
    struct Auction auction;
    strcpy(auction.item_name, "painting");
    auction.num_bidders = 0;

    add_bid(&auction, "Alice", 1000);
    add_bid(&auction, "Bob", 1500);
    add_bid(&auction, "Charlie", 2000);

    print_winner(auction);

    return 0;
}