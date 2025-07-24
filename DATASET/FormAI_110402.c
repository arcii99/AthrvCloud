//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_BIDS 20

struct bid {
    char bidder_name[100];
    float bid_amount;
};

struct auction_item {
    char item_name[100];
    char item_description[500];
    float minimum_bid;
    struct bid bids[MAX_BIDS];
    int num_bids;
};

struct auction {
    struct auction_item items[MAX_ITEMS];
    int num_items;
};

void print_bid(struct bid b) {
    printf("%s bid $%.2f\n", b.bidder_name, b.bid_amount);
}

void print_item(struct auction_item item) {
    printf("Item: %s\n", item.item_name);
    printf("Description: %s\n", item.item_description);
    printf("Minimum Bid: $%.2f\n", item.minimum_bid);
    printf("Bids:\n");
    for(int i = 0; i < item.num_bids; i++) {
        print_bid(item.bids[i]);
    }
}

void print_auction(struct auction a) {
    printf("Auction Items:\n");
    for(int i = 0; i < a.num_items; i++) {
        print_item(a.items[i]);
    }
}

void add_item(struct auction *a, char *name, char *description, float minimum_bid) {
    if(a->num_items >= MAX_ITEMS) {
        printf("Error: auction is full\n");
        return;
    }

    struct auction_item item;
    strcpy(item.item_name, name);
    strcpy(item.item_description, description);
    item.minimum_bid = minimum_bid;
    item.num_bids = 0;

    a->items[a->num_items] = item;
    a->num_items++;
}

void add_bid(struct auction *a, int item_index, char *bidder_name, float bid_amount) {
    if(item_index >= a->num_items) {
        printf("Error: invalid item index\n");
        return;
    }
    struct auction_item *item = &a->items[item_index];

    if(bid_amount < item->minimum_bid) {
        printf("Error: bid is lower than minimum bid\n");
        return;
    }

    if(item->num_bids >= MAX_BIDS) {
        printf("Error: item has reached maximum number of bids\n");
        return;
    }

    struct bid bid;
    strcpy(bid.bidder_name, bidder_name);
    bid.bid_amount = bid_amount;

    item->bids[item->num_bids] = bid;
    item->num_bids++;
}

int main() {
    struct auction auction;
    auction.num_items = 0;

    add_item(&auction, "Painting", "A beautiful painting by a local artist", 500.00);
    add_item(&auction, "Antique Vase", "A rare vase from the Ming Dynasty", 1000.00);
    add_item(&auction, "Vintage Watch", "A classic watch from the 1950s", 750.00);

    add_bid(&auction, 0, "Alice", 550.00);
    add_bid(&auction, 0, "Bob", 600.00);
    add_bid(&auction, 1, "Carol", 1200.00);
    add_bid(&auction, 2, "Dave", 800.00);
    add_bid(&auction, 2, "Eve", 1000.00);

    print_auction(auction);

    return 0;
}