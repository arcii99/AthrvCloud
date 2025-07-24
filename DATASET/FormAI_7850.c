//FormAI DATASET v1.0 Category: Digital Auction System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of items that can be auctioned
#define MAX_ITEMS 10

// Define maximum length of item description and bidder name
#define MAX_LENGTH 50

// Struct for auction item
struct AuctionItem {
    char description[MAX_LENGTH];
    double starting_bid;
    double current_bid;
    char current_bidder[MAX_LENGTH];
    int time_left;
};

// Function to initialize auction item with random values
void init_item(struct AuctionItem *item) {
    char descriptions[MAX_ITEMS][MAX_LENGTH] = {
        "Antique watch",
        "Signed basketball",
        "Painting by famous artist",
        "Rare book",
        "Vintage guitar",
        "Collection of coins",
        "Gold necklace",
        "Car",
        "Vacation package",
        "Concert tickets"
    };
    int desc_index = rand() % MAX_ITEMS;
    strcpy(item->description, descriptions[desc_index]);
    item->starting_bid = (double)(rand() % 5000 + 1000);
    item->current_bid = item->starting_bid;
    strcpy(item->current_bidder, "");
    item->time_left = rand() % 31 + 30;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize auction items
    struct AuctionItem items[MAX_ITEMS];
    for (int i = 0; i < MAX_ITEMS; i++) {
        init_item(&items[i]);
    }

    // Print auction items
    printf("Digital Auction System - Auction Items\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Item %d: %s\n", i+1, items[i].description);
        printf("Starting Bid: $%.2f\n", items[i].starting_bid);
        printf("Time Left: %d minutes\n", items[i].time_left);
        printf("\n");
    }

    // Start bidding
    printf("Auction has started! Enter 'q' at any time to quit.\n");
    char input[MAX_LENGTH];
    while (1) {
        printf("Enter the item number you'd like to bid on: ");
        fgets(input, MAX_LENGTH, stdin);
        if (input[0] == 'q') {
            break;
        }
        int item_num = atoi(input) - 1;
        if (item_num < 0 || item_num >= MAX_ITEMS) {
            printf("Invalid item number. Try again.\n");
            continue;
        }
        printf("Enter your name: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;
        printf("Enter your bid: ");
        fgets(input, MAX_LENGTH, stdin);
        double bid = atof(input);
        if (bid <= items[item_num].current_bid) {
            printf("Your bid must be higher than the current bid of $%.2f. Try again.\n", items[item_num].current_bid);
            continue;
        }
        printf("Congratulations, you are now the highest bidder with a bid of $%.2f!\n", bid);
        strcpy(items[item_num].current_bidder, input);
        items[item_num].current_bid = bid;
    }

    // Print final bid results
    printf("Digital Auction System - Final Bids\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Item %d: %s\n", i+1, items[i].description);
        printf("Starting Bid: $%.2f\n", items[i].starting_bid);
        if (strlen(items[i].current_bidder) == 0) {
            printf("No bids received.\n");
        } else {
            printf("Winning Bid: $%.2f by %s\n", items[i].current_bid, items[i].current_bidder);
        }
        printf("\n");
    }

    return 0;
}