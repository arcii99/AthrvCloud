//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char name[50];
    char description[100];
    float startingBid;
    float currentBid;
    char bidderName[50];
    int bidderID;
} Item;

int main() {
    int numItems = 3; // the number of items being auctioned
    Item items[numItems]; // an array to hold the items

    // initialize the items
    strcpy(items[0].name, "Antique Vase");
    strcpy(items[0].description, "A beautiful vase from the 18th century");
    items[0].startingBid = 500.0;
    items[0].currentBid = items[0].startingBid;
    strcpy(items[1].name, "Signed Guitar");
    strcpy(items[1].description, "A guitar signed by legendary musician Jimi Hendrix");
    items[1].startingBid = 1000.0;
    items[1].currentBid = items[1].startingBid;
    strcpy(items[2].name, "Rare Stamp");
    strcpy(items[2].description, "A rare stamp from the 1800s");
    items[2].startingBid = 200.0;
    items[2].currentBid = items[2].startingBid;

    int bidNum = 1; // a counter for the number of bids
    int bidderNum = 1; // a counter for the number of bidders

    printf("Welcome to the digital auction system!\n\n");

    while (1) { // loop forever until the user chooses to exit
        printf("Choose an item to bid on (1-3, or enter anything else to exit):\n");
        int itemNum;
        if (!scanf("%d", &itemNum)) break; // if input is not a valid integer, exit the program
        if (itemNum < 1 || itemNum > numItems) break; // if input is outside the range of valid item numbers, exit the program

        Item *item = &items[itemNum-1]; // get a pointer to the selected item

        printf("Item: %s\nDescription: %s\nStarting bid: %.2f\nCurrent bid: %.2f\n\n", item->name, item->description, item->startingBid, item->currentBid);

        printf("Enter your bid amount (0 to cancel):\n");
        float bidAmount;
        if (!scanf("%f", &bidAmount)) break; // if input is not a valid float, exit the program
        if (bidAmount <= item->currentBid) {
            printf("Bid amount must be higher than the current bid of %.2f\n\n", item->currentBid);
            continue; // go back to the beginning of the loop to prompt the user again
        }

        item->currentBid = bidAmount;

        printf("Enter your name:\n");
        char bidderName[50];
        scanf("%s", bidderName);

        int bidderID = bidderNum++; // assign a unique ID to the bidder

        strcpy(item->bidderName, bidderName);
        item->bidderID = bidderID;

        printf("Bid %d: %.2f by %s (ID %d)\n\n", bidNum++, item->currentBid, item->bidderName, item->bidderID);
    }

    printf("Thank you for using the digital auction system!\n");

    return 0;
}