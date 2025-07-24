//FormAI DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// struct for each item that will be auctioned
typedef struct Item {
    char name[MAX_NAME_LENGTH];
    float starting_bid;
    float current_bid;
    char current_bidder[MAX_NAME_LENGTH];
    int time_left;
    int is_active; // 1 if active, 0 if sold
} Item;

//struct to hold the auction house
typedef struct AuctionHouse {
    Item items[MAX_ITEMS];
    int num_items;
    char bidders[MAX_BIDDERS][MAX_NAME_LENGTH];
    int num_bidders;
    float commission_rate;
} AuctionHouse;

//function to add an item to the auction house
void add_item(AuctionHouse* ah, char* name, float starting_bid, int time_left) {
    if (ah->num_items == MAX_ITEMS) {
        printf("Auction house at capacity, cannot add item");
        return;
    }
    Item* new_item = &(ah->items[ah->num_items]);
    strncpy(new_item->name, name, MAX_NAME_LENGTH);
    new_item->starting_bid = starting_bid;
    new_item->current_bid = starting_bid;
    new_item->time_left = time_left;
    new_item->is_active = 1;
    ah->num_items++;
}

//function to register a bidder
void register_bidder(AuctionHouse* ah, char* name) {
    if (ah->num_bidders == MAX_BIDDERS) {
        printf("Auction house at capacity, cannot add bidder");
        return;
    }
    strncpy(ah->bidders[ah->num_bidders], name, MAX_NAME_LENGTH);
    ah->num_bidders++;
}

//function to place a bid on an item
void bid(AuctionHouse* ah, int item_index, char* bidder, float bid_amount) {
    Item* item = &(ah->items[item_index]);
    if (!item->is_active) {
        printf("Item is not active for bidding");
        return;
    }
    if (bid_amount <= item->current_bid) {
        printf("Bid amount should be higher than the current bid amount");
        return;
    }
    strncpy(item->current_bidder, bidder, MAX_NAME_LENGTH);
    item->current_bid = bid_amount;
}

//function to end the auction and sell items
void end_auction(AuctionHouse* ah) {
    for (int i = 0; i < ah->num_items; i++) {
        Item* item = &(ah->items[i]);
        if (item->is_active && item->time_left == 0) {
            item->is_active = 0;
            float commission = item->current_bid * ah->commission_rate;
            printf("Item %s sold to %s for %f (commission: %f)\n", 
                   item->name, item->current_bidder, item->current_bid, commission);
        }
    }
}

int main() {
    AuctionHouse ah;
    ah.num_items = 0;
    ah.num_bidders = 0;
    ah.commission_rate = 0.1; //10% commission
    
    //add items to the auction house
    add_item(&ah, "Painting", 100, 10);
    add_item(&ah, "Furniture", 500, 5);
    
    //register bidders
    register_bidder(&ah, "John");
    register_bidder(&ah, "Jane");
    
    //bidding phase
    bid(&ah, 0, "John", 150);
    bid(&ah, 0, "Jane", 200);
    
    //end of auction
    end_auction(&ah);
    
    return 0;
}