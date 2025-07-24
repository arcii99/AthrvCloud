//FormAI DATASET v1.0 Category: Digital Auction System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10
#define MAX_NAME_LEN 20

struct bid {
    char name[MAX_NAME_LEN]; // bidder name
    int amount; // the bid amount
};

struct auction {
    char item[MAX_NAME_LEN]; // item name
    int max_bid; // the maximum bid of the auction
    struct bid bids[MAX_BIDS]; // array of bids
    int num_bids; // number of bids
};

void print_auction(struct auction *a) {
    printf("Item: %s\n", a->item);
    printf("Current maximum bid: $%d\n", a->max_bid);
    printf("Bids:\n");
    for (int i = 0; i < a->num_bids; i++) {
        printf("%d. %s: $%d\n", i+1, a->bids[i].name, a->bids[i].amount);
    }
}

void bid_on_auction(struct auction *a, char *name, int amount) {
    if (a->num_bids == MAX_BIDS) {
        printf("Sorry, no more bids can be accepted.\n");
        return;
    }
    if (amount <= a->max_bid) {
        printf("Sorry, your bid must be higher than the current highest bid of $%d.\n", a->max_bid);
        return;
    }
    struct bid new_bid = { .amount = amount };
    strncpy(new_bid.name, name, MAX_NAME_LEN-1);
    a->bids[a->num_bids] = new_bid;
    a->num_bids++;
    a->max_bid = amount;
    printf("Bid accepted!\n");
}

int main(void) {
    struct auction my_auction = { .item = "Ferrari F40", .max_bid = 1000000, .num_bids = 0 };
    print_auction(&my_auction);
    bid_on_auction(&my_auction, "John", 1200000);
    print_auction(&my_auction);
    bid_on_auction(&my_auction, "Sarah", 1100000);
    print_auction(&my_auction);
    bid_on_auction(&my_auction, "Bob", 950000);
    print_auction(&my_auction);
    bid_on_auction(&my_auction, "Mary", 1500000);
    print_auction(&my_auction);
    return 0;
}