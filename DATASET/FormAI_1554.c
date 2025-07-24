//FormAI DATASET v1.0 Category: Digital Auction System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  char name[100];
  int startingBid;
  int currentBid;
  char highestBidder[100];
};

int main() {
  int numItems;
  printf("Enter the number of items for auction: ");
  scanf("%d", &numItems);

  struct Item items[numItems];

  for(int i = 0; i < numItems; i++) {
    printf("Enter the name of item %d: ", i+1);
    scanf("%s", items[i].name);

    printf("Enter the starting bid for item %d: ", i+1);
    scanf("%d", &items[i].startingBid);

    items[i].currentBid = items[i].startingBid;
    strcpy(items[i].highestBidder, "None");
  }

  printf("\n===== AUCTION BEGINS =====\n");

  int itemNum;
  char bidderName[100];
  int bidAmount;

  while(1) {
    printf("\nCurrent items for auction:\n");
    for(int i = 0; i < numItems; i++) {
      printf("%d. %s - Current bid: %d - Highest bidder: %s\n", i+1, items[i].name, items[i].currentBid, items[i].highestBidder);
    }

    printf("\nEnter the number of the item you wish to bid on (0 to exit): ");
    scanf("%d", &itemNum);

    if(itemNum == 0) {
      break;
    } else if(itemNum < 0 || itemNum > numItems) {
      printf("Invalid choice.\n");
      continue;
    }

    printf("Enter your name: ");
    scanf("%s", bidderName);

    printf("Enter your bid amount: ");
    scanf("%d", &bidAmount);

    if(bidAmount <= items[itemNum-1].currentBid) {
      printf("Bid amount is too low.\n");
    } else {
      items[itemNum-1].currentBid = bidAmount;
      strcpy(items[itemNum-1].highestBidder, bidderName);
      printf("Bid accepted.\n");
    }
  }

  printf("===== AUCTION ENDS =====\n");

  for(int i = 0; i < numItems; i++) {
    printf("%s - Highest bidder: %s - Sold for: %d\n", items[i].name, items[i].highestBidder, items[i].currentBid);
  }

  return 0;
}