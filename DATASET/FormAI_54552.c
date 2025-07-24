//FormAI DATASET v1.0 Category: Digital Auction System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define MIN_PRICE 100

struct Auction {
    char item[50];
    int current_price;
    char bidder_names[MAX_BIDS][50];
    char winner[50];
    int num_bids;
};

void display_auction(struct Auction auction) {
    printf("Current auction: %s\n", auction.item);
    printf("Current price: %d\n", auction.current_price);
    printf("Number of bids: %d\n", auction.num_bids);
    printf("Bids:\n");
    for(int i=0; i<auction.num_bids; i++) {
        printf("  %s\n", auction.bidder_names[i]);
    }
    printf("Winner: %s\n", auction.winner);
}

void place_bid(struct Auction *auction, char bidder_name[50], int amount) {
    if(amount > auction->current_price && amount >= MIN_PRICE) {
        auction->current_price = amount;
        strcpy(auction->winner, bidder_name);
    }
    strcpy(auction->bidder_names[auction->num_bids], bidder_name);
    auction->num_bids++;
}

int main() {
    struct Auction latest_auction = {"Gaming Laptop", 800, {{"Alice"}, {"Bob"}}, "Alice", 2};
    display_auction(latest_auction);
    place_bid(&latest_auction, "Charlie", 1000);
    display_auction(latest_auction);
    place_bid(&latest_auction, "Dave", 1200);
    display_auction(latest_auction);
    place_bid(&latest_auction, "Eve", 500);
    display_auction(latest_auction);
    place_bid(&latest_auction, "Faye", 900);
    display_auction(latest_auction);
    return 0;
}