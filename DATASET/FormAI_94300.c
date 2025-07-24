//FormAI DATASET v1.0 Category: Digital Auction System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item { 
    char itemName[50];
    float itemCost;
};

int main() {
    int numItems;
    printf("How many items are you auctioning off? ");
    scanf("%d", &numItems);

    struct Item items[numItems];

    for(int i=0; i<numItems; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].itemName);
        printf("Enter the cost of item %d: ", i+1);
        scanf("%f", &items[i].itemCost);
    }

    int highestBidIndex = 0;
    float highestBid = 0.0;

    for(int i=0; i<numItems; i++) {
        printf("Item %d: %s (Current Highest Bid: $%.2f)\n", i+1, items[i].itemName, items[i].itemCost);
        float maxBid;
        printf("Enter your bid for this item: ");
        scanf("%f", &maxBid);
        if(maxBid > highestBid) {
            highestBid = maxBid;
            highestBidIndex = i;
        }
    }

    printf("\n\n");
    printf("Congratulations! You win the auction for %s with a bid of $%.2f!\n", items[highestBidIndex].itemName, highestBid);

    return 0;
}