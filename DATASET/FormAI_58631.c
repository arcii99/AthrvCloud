//FormAI DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global constants for the maximum bids and the maximum length of the item description
#define MAX_BIDS 100
#define MAX_DESCRIPTION_LENGTH 50

// Struct definition for a bid
struct Bid {
    char bidderName[50];
    double amount;
};

// Struct definition for an auction item
struct Item {
    int id;
    char description[MAX_DESCRIPTION_LENGTH];
    double startingPrice;
    struct Bid bids[MAX_BIDS];
    int numBids;
};

// Function to print the details of an item
void printItemDetails(struct Item item) {
    printf("ITEM DETAILS\n");
    printf("ID: %d\n", item.id);
    printf("Description: %s\n", item.description);
    printf("Starting Price: $%.2f\n", item.startingPrice);
    printf("Number of Bids: %d\n\n", item.numBids);
}

// Function to add a bid for an item
void addBid(struct Item* item, char bidderName[50], double amount) {
    // Check if there is room for another bid
    if (item->numBids < MAX_BIDS) {
        // Create a new bid struct and add it to the item's bids array
        struct Bid newBid;
        strcpy(newBid.bidderName, bidderName);
        newBid.amount = amount;

        item->bids[item->numBids] = newBid;
        item->numBids++;

        printf("Bid of $%.2f added for item %d by %s\n\n", amount, item->id, bidderName);
    } else {
        printf("Error: maximum number of bids reached for item %d\n\n", item->id);
    }
}

// Function to get the highest bid for an item
double getHighestBid(struct Item item) {
    double highestBid = item.startingPrice;
    for (int i = 0; i < item.numBids; i++) {
        struct Bid currentBid = item.bids[i];
        if (currentBid.amount > highestBid) {
            highestBid = currentBid.amount;
        }
    }
    return highestBid;
}

int main() {
    // Create some sample items
    struct Item item1 = {1, "Antique Vase", 100.00, {}, 0};
    struct Item item2 = {2, "Signed Baseball", 50.00, {}, 0};
    struct Item item3 = {3, "Original Picasso Painting", 1000.00, {}, 0};

    // Print the details of the items
    printItemDetails(item1);
    printItemDetails(item2);
    printItemDetails(item3);

    // Add some bids for item 1
    addBid(&item1, "John", 125.00);
    addBid(&item1, "Mary", 150.00);

    // Print the updated details of item 1
    printItemDetails(item1);

    // Add some bids for item 2
    addBid(&item2, "Peter", 75.00);
    addBid(&item2, "David", 100.00);

    // Print the updated details of item 2
    printItemDetails(item2);

    // Add some bids for item 3
    addBid(&item3, "Sarah", 1250.00);
    addBid(&item3, "Mike", 1500.00);

    // Print the updated details of item 3
    printItemDetails(item3);

    // Get the highest bid for item 1 and print it out
    double highestBid1 = getHighestBid(item1);
    printf("Highest bid for item 1: $%.2f\n", highestBid1);

    // Get the highest bid for item 2 and print it out
    double highestBid2 = getHighestBid(item2);
    printf("Highest bid for item 2: $%.2f\n", highestBid2);

    // Get the highest bid for item 3 and print it out
    double highestBid3 = getHighestBid(item3);
    printf("Highest bid for item 3: $%.2f\n", highestBid3);

    return 0;
}