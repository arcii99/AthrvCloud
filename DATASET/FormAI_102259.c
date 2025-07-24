//FormAI DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID 1000000
#define MAX_NAME 50

typedef struct AuctionItem {
    char itemName[MAX_NAME];
    int currentBid;
    char highestBidder[MAX_NAME];
} AuctionItem;

void displayAuctionItem(AuctionItem item) {
    printf("Item Name: %s\n", item.itemName);
    printf("Current Bid: $%d\n", item.currentBid);
    if (strcmp(item.highestBidder, "") != 0) {
        printf("Highest Bidder: %s\n", item.highestBidder);
    }
}

int main() {
    srand(time(NULL));
    int numItems, numBids, maxBidsPerItem;
    printf("Enter the number of auction items: ");
    scanf("%d", &numItems);
    printf("Enter the number of bids per item: ");
    scanf("%d", &numBids);
    printf("Enter the maximum bids per item: ");
    scanf("%d", &maxBidsPerItem);
    AuctionItem items[numItems];
    for (int i = 0; i < numItems; i++) {
        printf("\nNEW ITEM\n");
        printf("Enter the name of item #%d: ", i+1);
        scanf("%s", items[i].itemName);
        items[i].currentBid = rand() % MAX_BID;
        items[i].highestBidder[0] = '\0';
        displayAuctionItem(items[i]);
        for (int j = 0; j < numBids; j++) {
            printf("\nNEW BID\n");
            int bidAmount = rand() % (MAX_BID - items[i].currentBid) + items[i].currentBid;
            char bidder[MAX_NAME];
            printf("Enter the name of bidder #%d: ", j+1);
            scanf("%s", bidder);
            if (strcmp(bidder, items[i].highestBidder) == 0) {
                printf("%s is already the highest bidder.\n", bidder);
                j--;
            } else if (bidAmount > MAX_BID) {
                printf("The bid amount exceeds the maximum bid of $%d.\n", MAX_BID);
                j--;
            } else if (bidAmount <= items[i].currentBid) {
                printf("The bid amount is lower than the current bid of $%d.\n", items[i].currentBid);
                j--;
            } else {
                items[i].currentBid = bidAmount;
                strcpy(items[i].highestBidder, bidder);
                displayAuctionItem(items[i]);
                if (j >= maxBidsPerItem) {
                    printf("Maximum number of bids reached for item #%d.\n", i+1);
                    break;
                }
            }
        }
    }
    printf("\nAUCTION ENDED\n");
    for (int i = 0; i < numItems; i++) {
        printf("\nFINAL ITEM\n");
        displayAuctionItem(items[i]);
    }
    return 0;
}