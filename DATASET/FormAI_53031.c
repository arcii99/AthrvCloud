//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20

// Define struct for item information
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float current_bid;
    float minimum_bid;
    int bidder_id;
} Item;

// Define struct for bid information
typedef struct {
    int item_id;
    int bidder_id;
    float bid_amount;
} Bid;

// Define array of items
Item items[MAX_ITEMS];

// Define array of bids
Bid bids[MAX_ITEMS];

// Define function to add items to auction
void add_item(int id, char* name, float minimum_bid) {
    Item new_item;
    new_item.id = id;
    strcpy(new_item.name, name);
    new_item.current_bid = 0.0;
    new_item.minimum_bid = minimum_bid;
    new_item.bidder_id = -1; // no bidder yet
    items[id] = new_item;
}

// Define function to place a bid
void place_bid(int item_id, int bidder_id, float bid_amount) {
    Item item = items[item_id];
    if (item.bidder_id == -1 || bid_amount > item.current_bid) {
        // Update item information
        item.current_bid = bid_amount;
        item.bidder_id = bidder_id;
        items[item_id] = item;

        // Add bid to array
        Bid new_bid;
        new_bid.item_id = item_id;
        new_bid.bidder_id = bidder_id;
        new_bid.bid_amount = bid_amount;
        bids[item_id] = new_bid;

        printf("Bid placed successfully for item %d by bidder %d for $%.2f\n",
                item_id, bidder_id, bid_amount);
    } else {
        printf("Bid not placed - current bid for item %d is $%.2f\n",
                item_id, item.current_bid);
    }
}

int main() {
    // Add some items to the auction
    add_item(0, "Painting", 100.0);
    add_item(1, "Sculpture", 200.0);

    // Place some bids
    place_bid(0, 1, 125.0);
    place_bid(1, 2, 220.0);
    place_bid(0, 2, 150.0);

    return 0;
}