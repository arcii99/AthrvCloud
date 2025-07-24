//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIDS 5
#define MAX_NAME_LENGTH 20

typedef struct {
    int bid_id;
    char bidder_name[MAX_NAME_LENGTH];
    int bid_amount;
} Bid;

typedef struct {
    int auction_id;
    char item_name[MAX_NAME_LENGTH];
    int current_bid;
    Bid bids[MAX_BIDS];
    int num_bids;
    bool open;
} Auction;

Auction create_auction(int auction_id, char *item_name) {
    Auction a;
    a.auction_id = auction_id;
    strcpy(a.item_name, item_name);
    a.current_bid = 0;
    a.num_bids = 0;
    a.open = true;
    return a;
}

void print_bid(Bid b) {
    printf("Bid ID: %d, Bidder Name: %s, Bid Amount: $%d\n", b.bid_id, b.bidder_name, b.bid_amount);
}

void print_auction_details(Auction a) {
    printf("Auction ID: %d, Item Name: %s, Current Bid: $%d, Number of Bids: %d, Open: %d\n", a.auction_id, a.item_name, a.current_bid, a.num_bids, a.open);
    printf("Bids:\n");
    for (int i = 0; i < a.num_bids; i++) {
        print_bid(a.bids[i]);
    }
}

void make_bid(Auction *a, char *bidder_name, int bid_amount) {
    if (bid_amount > a->current_bid && a->open) {
        Bid b;
        b.bid_id = a->num_bids + 1;
        strcpy(b.bidder_name, bidder_name);
        b.bid_amount = bid_amount;
        a->bids[a->num_bids] = b;
        a->num_bids += 1;
        a->current_bid = bid_amount;
        printf("Bid accepted!\n");
    } else {
        printf("Bid rejected.\n");
    }
}

int main() {
    Auction a = create_auction(1, "Antique Lamp");
    print_auction_details(a);

    make_bid(&a, "John", 50);
    make_bid(&a, "Sarah", 75);
    make_bid(&a, "Mark", 100);
    make_bid(&a, "Emily", 125);
    make_bid(&a, "David", 150);

    print_auction_details(a);
}