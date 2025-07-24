//FormAI DATASET v1.0 Category: Digital Auction System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10 // Maximum number of bids allowed for each item
#define MAX_ITEMS 5 // Maximum number of items in the auction

// Struct to hold details about an Item being auctioned
struct Item {
    char name[50];
    int current_bid;
    char highest_bidder[50];
    int bid_count;
};

// Struct to hold details about the auction
struct Auction {
    struct Item items[MAX_ITEMS];
    int item_count;
    int current_item_index;
};

// Function to add a new item to the auction
void add_item(struct Auction *auction, char *name, int starting_bid) {
    if (auction->item_count >= MAX_ITEMS) {
        printf("Error: Auction already has maximum allowed items.\n");
        return;
    }
    struct Item item;
    strcpy(item.name, name);
    item.current_bid = starting_bid;
    strcpy(item.highest_bidder, "None");
    item.bid_count = 0;
    auction->items[auction->item_count] = item;
    auction->item_count++;
}

// Function to start a new auction
void start_auction(struct Auction *auction) {
    auction->current_item_index = 0;
}

// Function to get the current item being auctioned
struct Item get_current_item(struct Auction *auction) {
    return auction->items[auction->current_item_index];
}

// Function to place a bid on the current item
void place_bid(struct Auction *auction, char *bidder_name, int bid_amount) {
    struct Item *item = &auction->items[auction->current_item_index];
    if (bid_amount <= item->current_bid) {
        printf("Error: Bid amount is not higher than current bid.\n");
        return;
    }
    if (item->bid_count >= MAX_BIDS) {
        printf("Error: Maximum number of bids reached for this item.\n");
        return;
    }
    item->current_bid = bid_amount;
    strcpy(item->highest_bidder, bidder_name);
    item->bid_count++;
}

// Function to end the current item's auction and move to the next item (if there is one)
void end_item_auction(struct Auction *auction) {
    auction->current_item_index++;
    if (auction->current_item_index >= auction->item_count) {
        printf("Auction is over! Thank you for participating!\n");
        exit(0);
    }
}

int main() {
    struct Auction auction;
    auction.item_count = 0;
    add_item(&auction, "Painting", 100);
    add_item(&auction, "Antique vase", 50);
    start_auction(&auction);
    struct Item item = get_current_item(&auction);
    printf("Current item: %s (starting bid: %d)\n", item.name, item.current_bid);
    while (1) {
        char bidder_name[50];
        int bid_amount;
        printf("Enter bidder name (or 'quit' to end auction): ");
        scanf("%s", bidder_name);
        if (strcmp(bidder_name, "quit") == 0) {
            end_item_auction(&auction);
            item = get_current_item(&auction);
            printf("Current item: %s (starting bid: %d)\n", item.name, item.current_bid);
            continue;
        }
        printf("Enter bid amount: ");
        scanf("%d", &bid_amount);
        place_bid(&auction, bidder_name, bid_amount);
    }
    return 0;
}