//FormAI DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char itemName[20];
    double currentBid;
    char bidderName[20];
} Item;

void printItem(Item item) {
    printf("Item: %s\n", item.itemName);
    printf("Current Bid: $%.2f\n", item.currentBid);
    if (strlen(item.bidderName) > 0) {
        printf("Bidder: %s\n", item.bidderName);
    } else {
        printf("No bids yet.\n");
    }
}

int main() {
    Item items[3]; // assume 3 items to auction
    
    // item 1
    strcpy(items[0].itemName, "Vintage guitar");
    items[0].currentBid = 0;
    strcpy(items[0].bidderName, "");
    
    // item 2
    strcpy(items[1].itemName, "Signed basketball");
    items[1].currentBid = 0;
    strcpy(items[1].bidderName, "");
    
    // item 3
    strcpy(items[2].itemName, "Antique watch");
    items[2].currentBid = 0;
    strcpy(items[2].bidderName, "");
    
    int choice;
    while (1) {
        printf("\nSelect an item to bid on:\n");
        for (int i=0; i<3; i++) {
            printf("%d. ", i+1);
            printItem(items[i]);
        }
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if (choice == 4) {
            break;
        }
        
        printf("\nEnter your name: ");
        char bidderName[20];
        scanf("%s", bidderName);
        
        Item* item = &items[choice-1];
        if (item->currentBid == 0) {
            printf("Starting bid is $5.00.\n");
            item->currentBid = 5.00;
            strcpy(item->bidderName, bidderName);
        } else {
            printf("Current bid is $%.2f.\n", item->currentBid);
            printf("Enter your bid: $");
            double bid;
            scanf("%lf", &bid);
            if (bid > item->currentBid) {
                item->currentBid = bid;
                strcpy(item->bidderName, bidderName);
                printf("Bidding successful!\n");
            } else {
                printf("Your bid must be higher than the current bid.\n");
            }
        }
    }
    
    printf("Auction ended. Here are the final bids:\n");
    for (int i=0; i<3; i++) {
        printf("%d. ", i+1);
        printItem(items[i]);
    }
    
    return 0;
}