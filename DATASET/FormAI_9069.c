//FormAI DATASET v1.0 Category: Digital Auction System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BIDDERS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int bid;
} Bidder;

typedef struct {
    Bidder bidder[MAX_BIDDERS];
    int num_bidders;
    int starting_price;
    int current_price;
    int sold_price;
    char sold_to[MAX_NAME_LENGTH];
} Auction;

void init_auction(Auction *auction, int starting_price) {
    auction->num_bidders = 0;
    auction->starting_price = starting_price;
    auction->current_price = starting_price;
    auction->sold_price = 0;
    strcpy(auction->sold_to, "");
}

void add_bidder(Auction *auction, char *name, int bid) {
    if (auction->num_bidders < MAX_BIDDERS) {
        Bidder new_bidder = { .bid = bid };
        strncpy(new_bidder.name, name, MAX_NAME_LENGTH);
        auction->bidder[auction->num_bidders] = new_bidder;
        auction->num_bidders++;
        if (bid > auction->current_price) {
            auction->current_price = bid;
        }
    }
}

void sell_item(Auction *auction) {
    if (auction->num_bidders > 0) {
        Bidder winner = auction->bidder[0];
        for (int i = 1; i < auction->num_bidders; i++) {
            if (auction->bidder[i].bid > winner.bid) {
                winner = auction->bidder[i];
            }
        }
        auction->sold_price = winner.bid;
        strcpy(auction->sold_to, winner.name);
    }
}

void print_auction(Auction *auction) {
    printf("Starting price: $%d\n", auction->starting_price);
    printf("Current price: $%d\n", auction->current_price);
    printf("Sold price: $%d to %s\n", auction->sold_price, auction->sold_to);
    printf("Bidders:\n");
    for (int i = 0; i < auction->num_bidders; i++) {
        printf("- %s bid $%d\n", auction->bidder[i].name, auction->bidder[i].bid);
    }
}

int main() {
    Auction auction;
    init_auction(&auction, 100);
    add_bidder(&auction, "Alice", 120);
    add_bidder(&auction, "Bob", 110);
    add_bidder(&auction, "Charlie", 130);
    sell_item(&auction);
    print_auction(&auction);
    return 0;
}