//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 20

/* Struct for auction item */
typedef struct {
    char name[50];
    double start_price;
    double current_price;
    char bidder[50];
    int num_bids;
    double bids[MAX_BIDS];
} AuctionItem;

/* Function to add a bid to auction item */
void add_bid(AuctionItem* item, double bid, char* bidder) {
    if (bid <= item->current_price) {
        printf("%s's bid of %.2f is too low.\n", bidder, bid);
        return;
    }
    if (item->num_bids >= MAX_BIDS) {
        printf("No more bids can be added for %s.\n", item->name);
        return;
    }
    item->current_price = bid;
    strcpy(item->bidder, bidder);
    item->bids[item->num_bids] = bid;
    item->num_bids++;
    printf("%s has the current highest bid of %.2f.\n", bidder, bid);
}

/* Function to print auction item details */
void print_auction_item(AuctionItem* item) {
    printf("Name: %s\n", item->name);
    printf("Starting price: %.2f\n", item->start_price);
    printf("Current highest bid: %.2f by %s\n", item->current_price, item->bidder);
    printf("Number of bids: %d\n", item->num_bids);
}

int main() {
    AuctionItem item = {"Painting", 100.0, 100.0, "", 0, {0}};
    
    print_auction_item(&item); // Print initial item details
    
    add_bid(&item, 150.0, "Alice"); // Alice bids 150
    print_auction_item(&item);
    
    add_bid(&item, 125.0, "Bob"); // Bob bids 125
    print_auction_item(&item);
    
    add_bid(&item, 200.0, "Charlie"); // Charlie bids 200
    print_auction_item(&item);
    
    return 0;
}