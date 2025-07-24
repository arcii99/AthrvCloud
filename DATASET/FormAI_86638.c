//FormAI DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 10

struct Bid {
    int bidderId;
    double amount;
};

struct Item {
    char name[100];
    double startingPrice;
    double currentPrice;
    struct Bid highestBid;
};

struct Auction {
    struct Item items[MAX_ITEMS];
    int numItems;
    struct Bid currentBids[MAX_BIDDERS];
    int numBids;
};

void printMenu() {
    printf("*** Digital Auction System ***\n");
    printf("1. List available items\n");
    printf("2. View item details\n");
    printf("3. Place a bid\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void listItems(struct Auction auction) {
    printf("Available items:\n");
    for (int i = 0; i < auction.numItems; i++) {
        printf("%d. %s\n", i + 1, auction.items[i].name);
    }
}

void viewItemDetails(struct Auction auction, int itemId) {
    struct Item item = auction.items[itemId];
    printf("Item name: %s\n", item.name);
    printf("Starting price: $%.2f\n", item.startingPrice);
    printf("Current price: $%.2f\n", item.currentPrice);
    if (item.highestBid.bidderId != -1) {
        printf("Highest bidder: bidder%d\n", item.highestBid.bidderId);
        printf("Highest bid: $%.2f\n", item.highestBid.amount);
    } else {
        printf("No bids placed yet.\n");
    }
}

void placeBid(struct Auction *auction, int itemId, int bidderId, double amount) {
    struct Item *item = &(auction->items[itemId]);
    if (amount <= item->currentPrice) {
        printf("Bid rejected: amount must be higher than current price.\n");
        return;
    }
    if (auction->numBids >= MAX_BIDDERS) {
        printf("Bid rejected: maximum number of bidders reached.\n");
        return;
    }
    for (int i = 0; i < auction->numBids; i++) {
        if (auction->currentBids[i].bidderId == bidderId) {
            printf("Bid rejected: bidder has already placed a bid.\n");
            return;
        }
    }
    item->highestBid.bidderId = bidderId;
    item->highestBid.amount = amount;
    item->currentPrice = amount;
    auction->currentBids[auction->numBids].bidderId = bidderId;
    auction->currentBids[auction->numBids].amount = amount;
    auction->numBids++;
    printf("Bid placed successfully!\n");
}

int main() {
    struct Auction auction;
    auction.numItems = 3;
    auction.numBids = 0;

    strcpy(auction.items[0].name, "iPhone X");
    auction.items[0].startingPrice = 1000.0;
    auction.items[0].currentPrice = 1000.0;
    auction.items[0].highestBid.bidderId = -1;
    auction.items[0].highestBid.amount = 0.0;

    strcpy(auction.items[1].name, "Nintendo Switch");
    auction.items[1].startingPrice = 300.0;
    auction.items[1].currentPrice = 300.0;
    auction.items[1].highestBid.bidderId = -1;
    auction.items[1].highestBid.amount = 0.0;

    strcpy(auction.items[2].name, "Samsung 4K TV");
    auction.items[2].startingPrice = 1500.0;
    auction.items[2].currentPrice = 1500.0;
    auction.items[2].highestBid.bidderId = -1;
    auction.items[2].highestBid.amount = 0.0;

    bool running = true;
    while (running) {
        printMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                listItems(auction);
                break;
            case 2:
                printf("Enter item number: ");
                int itemId;
                scanf("%d", &itemId);
                itemId--; // Decrement to convert from 1-indexed to 0-indexed
                if (itemId >= 0 && itemId < auction.numItems) {
                    viewItemDetails(auction, itemId);
                } else {
                    printf("Invalid item number.\n");
                }
                break;
            case 3:
                printf("Enter item number: ");
                scanf("%d", &itemId);
                itemId--; // Decrement to convert from 1-indexed to 0-indexed
                printf("Enter bidder number: ");
                int bidderId;
                scanf("%d", &bidderId);
                bidderId--; // Decrement to convert from 1-indexed to 0-indexed
                if (itemId >= 0 && itemId < auction.numItems && bidderId >= 0 && bidderId < MAX_BIDDERS) {
                    printf("Enter bid amount: ");
                    double amount;
                    scanf("%lf", &amount);
                    placeBid(&auction, itemId, bidderId, amount);
                } else {
                    printf("Invalid item number or bidder number.\n");
                }
                break;
            case 4:
                running = false;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}