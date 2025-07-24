//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Structs */
typedef struct Bid {
    int bidder_id;
    int amount;
} Bid;

typedef struct Auction {
    int id;
    char name[100];
    char description[200];
    int starting_bid;
    Bid *highest_bid;
    int num_bids;
    int num_bidders;
    int *bidders;
} Auction;

/* Functions */
void create_auction(Auction *auction, int id, char *name, char *description, int starting_bid) {
    auction->id = id;
    strcpy(auction->name, name);
    strcpy(auction->description, description);
    auction->starting_bid = starting_bid;
    auction->highest_bid = NULL;
    auction->num_bids = 0;
    auction->num_bidders = 0;
    auction->bidders = NULL;
}

void add_bid(Auction *auction, int bidder_id, int amount) {
    if (amount <= auction->starting_bid) {
        printf("Bid must be higher than the starting bid.\n");
        return;
    }
    if (auction->highest_bid != NULL && amount <= auction->highest_bid->amount) {
        printf("Bid must be higher than the current highest bid.\n");
        return;
    }
    Bid *new_bid = malloc(sizeof(Bid));
    new_bid->bidder_id = bidder_id;
    new_bid->amount = amount;
    if (auction->highest_bid != NULL) {
        free(auction->highest_bid);
    }
    auction->highest_bid = new_bid;
    auction->num_bids++;
    if (auction->num_bidders == 0) {
        auction->bidders = malloc(sizeof(int));
        auction->bidders[0] = bidder_id;
        auction->num_bidders++;
        return;
    }
    bool bidder_already_in_auction = false;
    for (int i = 0; i < auction->num_bidders; i++) {
        if (auction->bidders[i] == bidder_id) {
            bidder_already_in_auction = true;
            break;
        }
    }
    if (!bidder_already_in_auction) {
        auction->bidders = realloc(auction->bidders, (auction->num_bidders + 1) * sizeof(int));
        auction->bidders[auction->num_bidders] = bidder_id;
        auction->num_bidders++;
    }
}

int main() {
    Auction auction;
    create_auction(&auction, 1, "Test auction", "A test auction for the digital auction system", 10);
    add_bid(&auction, 1, 15);
    add_bid(&auction, 2, 20);
    add_bid(&auction, 3, 25);
    printf("Highest bid: %d by bidder %d\n", auction.highest_bid->amount, auction.highest_bid->bidder_id);
    printf("Number of bids: %d\n", auction.num_bids);
    printf("Number of bidders: %d\n", auction.num_bidders);
    printf("Bidders:");
    for (int i = 0; i < auction.num_bidders; i++) {
        printf(" %d", auction.bidders[i]);
    }
    printf("\n");
    return 0;
}