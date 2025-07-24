//FormAI DATASET v1.0 Category: Digital Auction System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 10

struct AuctionItem {
    char name[20];
    int starting_bid;
    int current_bid;
};

struct Bid {
    char bidder_name[20];
    int amount;
};

struct Auction {
    struct AuctionItem items[MAX_ITEMS];
    int num_items;
    struct Bid current_bid;
    struct Bid previous_bid;
    struct Bid highest_bid;
    struct Bid bidder_list[MAX_BIDDERS];
    int num_bidders;
} auction;

void initialize_auction() {
    auction.num_items = 0;
    auction.num_bidders = 0;
    auction.current_bid.amount = 0;
    auction.previous_bid.amount = 0;
    auction.highest_bid.amount = 0;
}

void add_item(char *name, int starting_bid) {
    if (auction.num_items >= MAX_ITEMS) {
        printf("Maximum number of items reached!\n");
        return;
    }
    struct AuctionItem item;
    strcpy(item.name, name);
    item.starting_bid = starting_bid;
    item.current_bid = starting_bid;
    auction.items[auction.num_items++] = item;    
}

void display_item_list() {
    printf("*************************\n");
    printf("      ITEM LIST          \n");
    printf("*************************\n");
    for (int i = 0; i < auction.num_items; i++) {
        printf("%d. %s\n", i+1, auction.items[i].name);
    }
    printf("*************************\n\n");
}

void add_bid(char *bidder_name, int amount) {
    if (auction.num_bidders >= MAX_BIDDERS) {
        printf("Maximum number of bidders reached!\n");
        return;
    }
    if (amount <= auction.current_bid.amount) {
        printf("Bid amount must be higher than the current bid!\n");
        return;
    }
    struct Bid bid;
    strcpy(bid.bidder_name, bidder_name);
    bid.amount = amount;
    auction.previous_bid = auction.current_bid;
    auction.current_bid = bid;
    if (bid.amount > auction.highest_bid.amount) {
        auction.highest_bid = bid;
    }
    auction.bidder_list[auction.num_bidders++] = bid;
}

void display_bidder_list() {
    printf("*************************\n");
    printf("     BIDDER LIST         \n");
    printf("*************************\n");
    for (int i = 0; i < auction.num_bidders; i++) {
        printf("%d. %s: %d\n", i+1, auction.bidder_list[i].bidder_name, auction.bidder_list[i].amount);
    }
    printf("*************************\n\n");
}

int main() {
    initialize_auction();
    add_item("Antique Watch", 200);
    add_item("Oil Painting", 500);
    add_item("Vintage Camera", 250);
    display_item_list();
    add_bid("John", 300);
    add_bid("Jane", 400);
    add_bid("Mike", 350);
    display_bidder_list();
    return 0;
}