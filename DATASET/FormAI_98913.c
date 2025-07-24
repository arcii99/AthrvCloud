//FormAI DATASET v1.0 Category: Digital Auction System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char itemName[50];
    char itemDesc[100];
    int basePrice;
    int currentBid;
    char highestBidder[50];
} Item;

void printItemDetails(Item item);
void placeBid(Item *item, int bidAmount);
void openAuction(Item *item);

int main() {
    Item auctionItem;
    strcpy(auctionItem.itemName, "Antique Vase");
    strcpy(auctionItem.itemDesc, "A beautiful porcelain vase with intricate design.");
    auctionItem.basePrice = 100;
    auctionItem.currentBid = auctionItem.basePrice;
    strcpy(auctionItem.highestBidder, "");

    openAuction(&auctionItem);

    return 0;
}

void printItemDetails(Item item) {
    printf("--- ITEM DETAILS ---\n");
    printf("Name: %s\n", item.itemName);
    printf("Description: %s\n", item.itemDesc);
    printf("Base Price: %d\n", item.basePrice);
    printf("Current Bid: %d\n", item.currentBid);
    printf("Highest Bidder: %s\n", item.highestBidder);
}

void placeBid(Item *item, int bidAmount) {
    if (bidAmount <= item->currentBid) {
        printf("Sorry, your bid must be higher than the current highest bid.\n");
        return;
    }

    printf("Congratulations, you are now the highest bidder with a bid of %d!\n", bidAmount);
    item->currentBid = bidAmount;
}

void openAuction(Item *item) {
    char input[10];
    int bid;

    printf("Welcome to the auction for %s.\n", item->itemName);
    printItemDetails(*item);

    while (strcmp(input, "exit") != 0) {
        printf("Place your bid (or type 'exit' to end the auction): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            printf("Auction ended. Thank you for your participation!\n");
            break;
        }

        bid = atoi(input);
        placeBid(item, bid);
    }
}