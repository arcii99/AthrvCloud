//FormAI DATASET v1.0 Category: Digital Auction System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct AuctionItem {
    char itemName[50];
    int itemId;
    int currentBid;
    int minimumBid;
    char highestBidder[50];
};

int main() {
    int numItems = 3;
    struct AuctionItem items[numItems];
    // Initialize auction items
    strcpy(items[0].itemName, "iPhone X");
    items[0].itemId = 1;
    items[0].currentBid = 500;
    items[0].minimumBid = 550;
    strcpy(items[0].highestBidder, "");

    strcpy(items[1].itemName, "Samsung Galaxy S9");
    items[1].itemId = 2;
    items[1].currentBid = 300;
    items[1].minimumBid = 320;
    strcpy(items[1].highestBidder, "");

    strcpy(items[2].itemName, "Sony Playstation 5");
    items[2].itemId = 3;
    items[2].currentBid = 200;
    items[2].minimumBid = 220;
    strcpy(items[2].highestBidder, "");

    // Main menu
    int choice;
    do {
        printf("\n\nDigital Auction System\n\n");
        printf("1. View all items\n");
        printf("2. Place bid on an item\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // View all items
                printf("\nAll Auction Items:\n");
                printf("%-20s%-10s%-10s%-20s\n", "Item Name", "Item ID", "Current Bid", "Highest Bidder");
                for (int i = 0; i < numItems; i++) {
                    printf("%-20s%-10d%-10d%-20s\n", items[i].itemName, items[i].itemId,
                           items[i].currentBid, items[i].highestBidder);
                }
                break;
            case 2: // Place a bid
                int itemId;
                printf("\nEnter the item ID to bid on: ");
                scanf("%d", &itemId);

                // Find the item
                int index = -1;
                for (int i = 0; i < numItems; i++) {
                    if (items[i].itemId == itemId) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    printf("\nItem not found.\n");
                } else {
                    printf("\nItem: %s, Minimum Bid: %d\n", items[index].itemName, items[index].minimumBid);
                    printf("Current bid: %d, Highest bidder: %s\n", items[index].currentBid, items[index].highestBidder);
                    int bidAmount;
                    printf("Enter your bid: ");
                    scanf("%d", &bidAmount);

                    // Validate bid amount
                    if (bidAmount < items[index].minimumBid) {
                        printf("Bid amount is less than minimum bid required.\n");
                    } else if (bidAmount <= items[index].currentBid) {
                        printf("Bid amount is not higher than current bid.\n");
                    } else {
                        items[index].currentBid = bidAmount;
                        char nameEntered[50];
                        printf("Enter your name: ");
                        scanf("%s", nameEntered);
                        strcpy(items[index].highestBidder, nameEntered);
                        printf("Bid successful!\n");
                    }
                }
                break;
            case 3: // Exit
                printf("\nThank you for using the Digital Auction System.\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}