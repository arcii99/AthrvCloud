//FormAI DATASET v1.0 Category: Digital Auction System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants 
#define MAX_BIDS 100
#define MAX_NAME 50

// Define struct for a bid
typedef struct {
    char name[MAX_NAME];
    double amount;
} Bid;

// Define struct for auction
typedef struct {
    char item_name[MAX_NAME];
    double starting_price;
    Bid bids[MAX_BIDS];
    int num_bids;
} Auction;

// Define function to create an auction
Auction create_auction(char name[], double price) {
    Auction auction;
    strcpy(auction.item_name, name);
    auction.starting_price = price;
    auction.num_bids = 0;
    return auction;
}

// Define function to add a bid to an auction
void add_bid(Auction *auction, Bid bid) {
    if (auction->num_bids >= MAX_BIDS) {
        printf("Maximum number of bids reached\n");
        return;
    }
    if (bid.amount < auction->starting_price) {
        printf("Bid amount must be greater than or equal to starting price\n");
        return;
    }
    auction->bids[auction->num_bids] = bid;
    auction->num_bids++;
}

// Define function to print all bids for an auction
void print_bids(Auction auction) {
    printf("Bids for %s: \n", auction.item_name);
    for (int i = 0; i < auction.num_bids; i++) {
        printf("%s bid $%.2f\n", auction.bids[i].name, auction.bids[i].amount);
    }
}

int main() {
    Auction painting = create_auction("Famous Painting", 1000.00);
    Bid bidder1 = {"John", 1200.00};
    Bid bidder2 = {"Mary", 1100.00};
    add_bid(&painting, bidder1);
    add_bid(&painting, bidder2);
    print_bids(painting);
    return 0;
}