//FormAI DATASET v1.0 Category: Digital Auction System ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bidder {
    char name[100];
    int bidderID;
    float bidAmount;
};

struct item {
    char itemName[100];
    float startingBid;
    float highestBid;
    int timeRemaining;
    struct bidder highestBidder;
};

void createItem(struct item *newItem, char *itemName, float startingBid) {
    strcpy(newItem->itemName, itemName);
    newItem->startingBid = startingBid;
    newItem->highestBid = startingBid;
    newItem->timeRemaining = 60; // seconds
}

void registerBidder(struct bidder *newBidder, char *name, int bidderID) {
    strcpy(newBidder->name, name);
    newBidder->bidderID = bidderID;
    newBidder->bidAmount = 0.0;
}

void bidOnItem(struct item *itemPtr, struct bidder *bidderPtr, float bidAmount) {
    if (bidAmount > itemPtr->highestBid) {
        itemPtr->highestBid = bidAmount;
        itemPtr->timeRemaining = 60;
        itemPtr->highestBidder = *bidderPtr;
        bidderPtr->bidAmount = bidAmount;
        printf("%s is now the highest bidder with a bid of %.2f\n", bidderPtr->name, bidAmount);
    } else {
        printf("Sorry, your bid of %.2f is not high enough.\n", bidAmount);
    }
}

void printItemDetails(struct item item) {
    printf("Item Name: %s\n", item.itemName);
    printf("Starting Bid: %.2f\n", item.startingBid);
    printf("Highest Bid: %.2f\n", item.highestBid);
    printf("Time Remaining: %d seconds\n", item.timeRemaining);
    printf("High Bidder: %s (Bidder ID: %d)\n", item.highestBidder.name, item.highestBidder.bidderID);
}

int main() {
    struct item myItem;
    createItem(&myItem, "Laptop", 500.0);

    struct bidder bidder1;
    registerBidder(&bidder1, "John", 1);

    struct bidder bidder2;
    registerBidder(&bidder2, "Amy", 2);

    bidOnItem(&myItem, &bidder1, 550.0);
    bidOnItem(&myItem, &bidder2, 600.0);

    printItemDetails(myItem);

    return 0;
}