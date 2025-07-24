//FormAI DATASET v1.0 Category: Digital Auction System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold auction item
typedef struct {
    char name[50];
    char description[250];
    float startPrice;
    float currentBid;
    char bidder[50];
} AuctionItem;

// Function to display auction item details
void displayItem(AuctionItem item) {
    printf("------------------------\n");
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Start price: $%.2f\n", item.startPrice);
    printf("Current bid: $%.2f\n", item.currentBid);
    printf("Bidder: %s\n", item.bidder);
    printf("------------------------\n");
}

// Function to place a bid on an auction item
void placeBid(AuctionItem *item, char *bidder, float bidAmount) {
    if (bidAmount > item->currentBid) {
        item->currentBid = bidAmount;
        strcpy(item->bidder, bidder);
        printf("Bid placed successfully!\n");
    } else {
        printf("Your bid must be higher than the current bid!\n");
    }
}

int main() {
    // Create an array of auction items
    AuctionItem items[3];

    // Initialize the auction items
    strcpy(items[0].name, "Vintage Clock");
    strcpy(items[0].description, "Antique clock made in the early 1900s");
    items[0].startPrice = 100.00;
    items[0].currentBid = 0.00;
    strcpy(items[0].bidder, "");

    strcpy(items[1].name, "Signed Baseball");
    strcpy(items[1].description, "Official baseball signed by Babe Ruth");
    items[1].startPrice = 500.00;
    items[1].currentBid = 0.00;
    strcpy(items[1].bidder, "");

    strcpy(items[2].name, "Oil Painting");
    strcpy(items[2].description, "Beautiful landscape painted by a local artist");
    items[2].startPrice = 250.00;
    items[2].currentBid = 0.00;
    strcpy(items[2].bidder, "");

    // Display the available auction items
    printf("Welcome to the Digital Auction System!\n\n");
    printf("We have the following items available for auction:\n");
    for (int i = 0; i < 3; i++) {
        displayItem(items[i]);
    }

    // Take user input to place bids
    char bidder[50];
    float bidAmount;
    int itemNum;
    while (1) {
        printf("Enter the item number you want to bid on (1-3): ");
        scanf("%d", &itemNum);
        if (itemNum < 1 || itemNum > 3) {
            printf("Invalid item number. Please try again.\n");
            continue;
        }
        printf("Enter your name: ");
        scanf("%s", bidder);
        printf("Enter your bid amount: $");
        scanf("%f", &bidAmount);
        placeBid(&items[itemNum-1], bidder, bidAmount);
        printf("\n");
    }

    return 0;
}