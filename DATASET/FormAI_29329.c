//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_BIDDERS 5

// Define struct to represent an auction item
typedef struct {
    char item_name[50];
    int base_price;
    int highest_bid;
    char highest_bidder[20];
} AuctionItem;

// Define struct to represent a bidder
typedef struct {
    char name[20];
    int current_bid;
} Bidder;

// Function to display available auction items
void display_items(AuctionItem items[]) {
    printf("Available Auction Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s (Base Price: %d)\n", i+1, items[i].item_name, items[i].base_price);
    }
    printf("\n");
}

// Function to add and validate a bid
int add_bid(AuctionItem *item, Bidder *bidder) {
    int bid;
    printf("%s, enter your bid: ", bidder->name);
    scanf("%d", &bid);

    // Check if the bid is valid
    if (bid > item->highest_bid && bid > bidder->current_bid) {
        item->highest_bid = bid;
        strcpy(item->highest_bidder, bidder->name);
        bidder->current_bid = bid;
        printf("Bid accepted!\n");
        return 1;
    } else {
        printf("Bid rejected. Enter a higher bid.\n");
        return 0;
    }
}

int main() {
    // Initialize auction items
    AuctionItem items[MAX_ITEMS] = {
        {"Painting", 500, 0, ""},
        {"Jewelry", 1000, 0, ""},
        {"Antique vase", 800, 0, ""},
        {"Vintage watch", 400, 0, ""},
        {"Sports memorabilia", 200, 0, ""},
        {"Rare coins", 600, 0, ""},
        {"Musical instrument", 300, 0, ""},
        {"Collectible figurine", 150, 0, ""},
        {"Textbook", 50, 0, ""},
        {"Kitchen appliance", 100, 0, ""}
    };

    // Initialize bidders
    Bidder bidders[MAX_BIDDERS] = {
        {"John", 0},
        {"Mary", 0},
        {"Tim", 0},
        {"Dave", 0},
        {"Samantha", 0}
    };

    printf("Welcome to the Digital Auction System!\n\n");

    // Display available items
    display_items(items);

    // Start bidding
    int item_index, bid_count = 0;
    while (bid_count < MAX_ITEMS) {
        // Prompt user to choose an item to bid on
        printf("Choose an item to bid on (1-%d): ", MAX_ITEMS);
        scanf("%d", &item_index);
        while (item_index < 1 || item_index > MAX_ITEMS) {
            printf("Invalid item index. Choose an item to bid on (1-%d): ", MAX_ITEMS);
            scanf("%d", &item_index);
        }

        // Prompt user to enter a bid
        int bidder_index;
        display_items(&items[item_index-1]);
        printf("Enter your bidder number (1-%d): ", MAX_BIDDERS);
        scanf("%d", &bidder_index);
        while (bidder_index < 1 || bidder_index > MAX_BIDDERS) {
            printf("Invalid bidder number. Enter your bidder number (1-%d): ", MAX_BIDDERS);
            scanf("%d", &bidder_index);
        }

        // Add bid
        if (add_bid(&items[item_index-1], &bidders[bidder_index-1])) {
            bid_count++;
        }
    }

    // Display results
    printf("\nAuction Ended! Results:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%s sold to %s for %d\n", items[i].item_name, items[i].highest_bidder, items[i].highest_bid);
    }
    printf("\n");

    return 0;
}