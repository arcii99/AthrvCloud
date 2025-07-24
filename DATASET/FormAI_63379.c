//FormAI DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be auctioned on the platform
#define MAX_ITEMS 10

// Define the maximum length of item descriptions
#define MAX_DESC_LENGTH 100

// Define the maximum number of bids that can be made on an item
#define MAX_BIDS 100

// Define the struct for an item
typedef struct {
    int id; // Unique ID for the item
    char description[MAX_DESC_LENGTH]; // Description of the item
    float minimum_bid; // Minimum bid required for the item
    float current_bid; // Current highest bid for the item
    char current_bidder[50]; // Name of the current highest bidder for the item
    float bids[MAX_BIDS]; // Array to hold all the bids made for this item
    int num_bids; // Number of bids made for this item
} AuctionItem;

// Define the struct for the auction platform
typedef struct {
    int num_items; // Number of items currently up for auction
    AuctionItem items[MAX_ITEMS]; // Array to hold all the items up for auction
} AuctionPlatform;

// Function to add a new item to the platform
void add_item(AuctionPlatform *platform, char desc[], float min_bid) {
    // Check if the platform has reached the maximum number of items
    if (platform->num_items >= MAX_ITEMS) {
        printf("Sorry, the maximum number of items has been reached.\n");
        return;
    }
    
    // Create the new item
    AuctionItem item;
    item.id = platform->num_items + 1; // ID is the current number of items + 1
    strcpy(item.description, desc);
    item.minimum_bid = min_bid;
    item.current_bid = min_bid;
    strcpy(item.current_bidder, "None");
    item.num_bids = 0;
    
    // Add the item to the platform
    platform->items[platform->num_items] = item;
    platform->num_items++;
}

// Function to make a bid on an item
void make_bid(AuctionPlatform *platform, int item_id, char bidder[], float amount) {
    // Check if the item ID is valid
    if (item_id > platform->num_items || item_id <= 0) {
        printf("Invalid item ID.\n");
        return;
    }
    
    // Get the item with the specified ID
    AuctionItem *item = &platform->items[item_id - 1];
    
    // Check if the bid amount is greater than the current highest bid
    if (amount <= item->current_bid) {
        printf("Sorry, your bid must be higher than the current highest bid.\n");
        return;
    }
    
    // Add the bid to the item
    item->bids[item->num_bids] = amount;
    item->num_bids++;
    item->current_bid = amount;
    strcpy(item->current_bidder, bidder);
    
    printf("Bid successful! Current highest bidder for item #%d is %s with a bid of %.2f.\n",
            item->id, item->current_bidder, item->current_bid);
}

// Main function to run the program
int main() {
    // Create the auction platform
    AuctionPlatform platform;
    platform.num_items = 0;
    
    // Add some sample items to the platform
    add_item(&platform, "Antique vase", 50.00);
    add_item(&platform, "Signed football", 100.00);
    add_item(&platform, "Diamond necklace", 500.00);
    
    // Make some bids on the items
    make_bid(&platform, 2, "John", 150.00);
    make_bid(&platform, 1, "Mary", 75.00);
    make_bid(&platform, 2, "Emily", 200.00);
    make_bid(&platform, 3, "David", 700.00);
    
    return 0;
}