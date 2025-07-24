//FormAI DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

// Struct to hold auction data
struct auction_item {
    int item_id;
    char item_name[50];
    float highest_bid;
    bool is_active;
};

// Function to create a new auction item
struct auction_item create_auction_item(int item_id, char item_name[], float starting_bid) {
    struct auction_item item;
    item.item_id = item_id;
    strcpy(item.item_name, item_name);
    item.highest_bid = starting_bid;
    item.is_active = true;
    return item;
}

// Function to display all active auction items
void display_auction_items(struct auction_item inventory[], int num_items) {
    printf("Active Auction Items:\n");
    for(int i=0; i<num_items; i++) {
        if(inventory[i].is_active) {
            printf("Item ID: %d, Item Name: %s, Current Highest Bid: $%.2f\n", inventory[i].item_id, inventory[i].item_name, inventory[i].highest_bid);
        }
    }
}

// Function to place a bid on an auction item
void place_bid(struct auction_item * item, float new_bid) {
    if(item->is_active && new_bid > item->highest_bid) {
        item->highest_bid = new_bid;
        printf("New highest bid on %s: $%.2f\n", item->item_name, item->highest_bid);
    }
}

int main() {
    // Create initial auction inventory
    struct auction_item inventory[5];
    inventory[0] = create_auction_item(1001, "Vintage Record Player", 50.00);
    inventory[1] = create_auction_item(1002, "Signed Baseball", 75.00);
    inventory[2] = create_auction_item(1003, "Antique Book Collection", 150.00);
    inventory[3] = create_auction_item(1004, "Original Painting", 200.00);
    inventory[4] = create_auction_item(1005, "Rare Movie Memorabilia", 100.00);

    // Display available auction items
    display_auction_items(inventory, 5);

    // Simulate bidding process
    place_bid(&inventory[0], 75.00);
    place_bid(&inventory[0], 100.00);
    place_bid(&inventory[1], 100.00);
    place_bid(&inventory[1], 200.00);
    place_bid(&inventory[1], 150.00);

    // Display final auction results
    display_auction_items(inventory, 5);

    return 0;
}