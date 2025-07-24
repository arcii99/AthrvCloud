//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char bidder_name[50];
    int bid_amount;
} Bid;

typedef struct {
    char item_name[50];
    int current_bid;
    int num_bids;
    Bid* bids[10];
} Auction_Item;

void create_auction_item(Auction_Item* item, char* name, int starting_bid) {
    strcpy(item->item_name, name);
    item->current_bid = starting_bid;
    item->num_bids = 0;
}

void add_bid(Auction_Item* item, char* bidder_name, int bid_amount) {
    Bid* new_bid = (Bid*)malloc(sizeof(Bid));
    strcpy(new_bid->bidder_name, bidder_name);
    new_bid->bid_amount = bid_amount;
    item->current_bid = bid_amount;
    item->bids[item->num_bids] = new_bid;
    item->num_bids++;
}

void print_bids(Auction_Item* item) {
    printf("Current Bid: $%d\n", item->current_bid);
    printf("Bids:\n");
    for (int i = 0; i < item->num_bids; i++) {
        printf("%s: $%d\n", item->bids[i]->bidder_name, item->bids[i]->bid_amount);
    }
}

int main() {
    Auction_Item guitar;
    create_auction_item(&guitar, "Gibson Les Paul Standard", 1000);

    add_bid(&guitar, "John", 1100);
    add_bid(&guitar, "Paul", 1200);
    add_bid(&guitar, "George", 1300);
    add_bid(&guitar, "Ringo", 1400);

    print_bids(&guitar);

    return 0;
}