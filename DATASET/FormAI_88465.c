//FormAI DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 5

typedef struct {
    char name[20];
    float bidAmount;
    int isActive;
} bidder;

typedef struct {
    char itemName[20];
    float basePrice;
    float highestBid;
    bidder highestBidder;
    int isActive;
} item;

bidder bidders[MAX_BIDDERS];
item items[MAX_ITEMS];

void initializeBidders() {
    for (int i = 0; i < MAX_BIDDERS; i++) {
        bidders[i].bidAmount = 0;
        bidders[i].isActive = 0;
    }

    strcpy(bidders[0].name, "John");
    strcpy(bidders[1].name, "Mary");
    strcpy(bidders[2].name, "Tom");
    strcpy(bidders[3].name, "Jane");

    // set first 4 bidders to active
    for (int i = 0; i < 4; i++) {
        bidders[i].isActive = 1;
    }
}

void initializeItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].basePrice = 0;
        items[i].highestBid = 0;
        items[i].isActive = 0;
    }

    strcpy(items[0].itemName, "Painting");
    items[0].basePrice = 100;
    items[0].isActive = 1;

    strcpy(items[1].itemName, "Watch");
    items[1].basePrice = 50;
    items[1].isActive = 1;

    strcpy(items[2].itemName, "Book");
    items[2].basePrice = 20;
    items[2].isActive = 1;
}

void displayItemMenu() {
    printf("=== ITEMS ===\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].isActive == 1) {
            printf("%d. %s - Base Price: $%.2f\n", i+1, items[i].itemName, items[i].basePrice);
        }
    }
    printf("0. Go Back\n");
}

void displayBidderMenu() {
    printf("=== BIDDERS ===\n");
    for (int i = 0; i < MAX_BIDDERS; i++) {
        if (bidders[i].isActive == 1) {
            printf("%d. %s - Bid Amount: $%.2f\n", i+1, bidders[i].name, bidders[i].bidAmount);
        }
    }
    printf("0. Go Back\n");
}

void displayItemDetails(int itemIndex) {
    item currentItem = items[itemIndex];
    printf("Item Name: %s\n", currentItem.itemName);
    printf("Base Price: $%.2f\n", currentItem.basePrice);
    if (currentItem.highestBid > 0) {
        printf("Highest Bidder: %s\n", currentItem.highestBidder.name);
        printf("Highest Bid: $%.2f\n", currentItem.highestBid);
    } else {
        printf("No Bids Yet.\n");
    }
}

int main() {
    initializeBidders();
    initializeItems();

    int choice;
    while(1) {
        printf("\n=== MAIN MENU ===\n");
        printf("1. View Items\n");
        printf("2. Bid on an Item\n");
        printf("3. View Bidders\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayItemMenu();
            printf("Enter Choice: ");
            scanf("%d", &choice);

            if (choice > 0 && choice <= MAX_ITEMS && items[choice-1].isActive == 1) {
                displayItemDetails(choice-1);
            }
        } else if (choice == 2) {
            displayItemMenu();
            printf("Enter Choice: ");
            scanf("%d", &choice);

            if (choice > 0 && choice <= MAX_ITEMS && items[choice-1].isActive == 1) {
                item currentItem = items[choice-1];

                printf("Enter Bid Amount: ");
                float bidAmount;
                scanf("%f", &bidAmount);

                if (bidAmount > currentItem.highestBid) {
                    int bidderChoice;
                    while(1) {
                        displayBidderMenu();
                        printf("Enter Choice: ");
                        scanf("%d", &bidderChoice);

                        if (bidderChoice == 0) {
                            break;
                        } else if (bidderChoice > 0 && bidderChoice <= MAX_BIDDERS && bidders[bidderChoice-1].isActive == 1) {
                            bidders[bidderChoice-1].bidAmount = bidAmount;
                            currentItem.highestBid = bidAmount;
                            currentItem.highestBidder = bidders[bidderChoice-1];
                            printf("Bid Successful!\n");
                            break;
                        } else {
                            printf("Invalid Choice. Try Again.\n");
                        }
                    }
                } else {
                    printf("Bid Too Low. Try Again.\n");
                }
            }
        } else if (choice == 3) {
            displayBidderMenu();
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid Choice. Try Again.\n");
        }
    }

    return 0;
}