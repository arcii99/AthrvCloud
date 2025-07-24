//FormAI DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for digital auction system

typedef struct {
    char item_name[50];
    char item_description[1000];
    float starting_price;
    float current_price;
    char seller_name[50];
    char bidder_name[50];
} AuctionItem;

// Function to create new auction item

AuctionItem create_auction_item(char item_name[], char item_description[], float starting_price, char seller_name[]) {
    AuctionItem new_item;
    strcpy(new_item.item_name, item_name);
    strcpy(new_item.item_description, item_description);
    new_item.starting_price = starting_price;
    new_item.current_price = starting_price;
    strcpy(new_item.seller_name, seller_name);
    strcpy(new_item.bidder_name, "");
    return new_item;
}

// Function to bid on auction item

void place_bid(AuctionItem* item, float bid, char bidder_name[]) {
    if (bid <= item->current_price) {
        printf("Your bid must be higher than the current price of %.2f.\n", item->current_price);
    } else {
        item->current_price = bid;
        strcpy(item->bidder_name, bidder_name);
        printf("Bid of %.2f accepted from %s.\n", bid, bidder_name);
    }
}

// Function to display auction item information

void display_item(AuctionItem item) {
    printf("Item Name: %s\n", item.item_name);
    printf("Description: %s\n", item.item_description);
    printf("Starting Price: %.2f\n", item.starting_price);
    printf("Current Price: %.2f\n", item.current_price);
    printf("Seller: %s\n", item.seller_name);
    printf("Current highest bidder: %s\n", item.bidder_name);
}

int main() {
    // Sample usage of digital auction system
    printf("Welcome to the Digital Auction System!\n\n");

    // Create new auction item
    AuctionItem item = create_auction_item("Antique Watch", "A beautiful antique watch made in Switzerland.", 200.00, "John");

    // Display item information
    display_item(item);

    // Place bid
    place_bid(&item, 250.00, "Alice");

    // Display updated item information
    display_item(item);

    return 0;
}