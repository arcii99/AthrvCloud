//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
  char name[50];
  float startPrice;
  float currentPrice;
  char seller[30];
  char bidder[30];
} Item;

typedef struct AuctionList {
  Item items[20];
  int itemCount;
} AuctionList;

void addItem(AuctionList* list, char itemName[], float startPrice, char seller[]) {
  Item item;
  strcpy(item.name, itemName);
  item.startPrice = startPrice;
  item.currentPrice = startPrice;
  strcpy(item.seller, seller);
  strcpy(item.bidder, "");
  list->items[list->itemCount] = item;
  list->itemCount++;
}

void bidOnItem(AuctionList* list, char itemName[], float bidAmount, char bidder[]) {
  int i;
  for(i = 0; i < list->itemCount; i++) {
    if(strcmp(list->items[i].name, itemName) == 0) {
      if(list->items[i].currentPrice < bidAmount) {
        list->items[i].currentPrice = bidAmount;
        strcpy(list->items[i].bidder, bidder);
        printf("%s has bid %.2f on %s.\n", bidder, bidAmount, itemName);
        return;
      }
      else {
        printf("Bid amount must be higher than current price.\n");
        return;
      }
    }
  }
  printf("Item not found in auction list.\n");
}

void printItems(AuctionList* list) {
  int i;
  for(i = 0; i < list->itemCount; i++) {
    printf("%d. %s - £%.2f (current highest bid: £%.2f by %s)\n", i+1, list->items[i].name, list->items[i].startPrice, list->items[i].currentPrice, list->items[i].bidder);
  }
}

int main() {
  AuctionList list;
  list.itemCount = 0;

  addItem(&list, "Laptop", 200.00, "John");
  addItem(&list, "Phone", 100.00, "Sarah");
  addItem(&list, "TV", 400.00, "Mike");

  int choice = 0;
  char itemName[50];
  char bidderName[30];
  float bidAmount;

  printf("Welcome to the Digital Auction System!\n\n");

  while(choice != 3) {
    printf("\nPlease choose an option:\n");
    printf("1. View items\n");
    printf("2. Bid on item\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nCurrent items in auction:\n");
        printItems(&list);
        break;
      case 2:
        printf("\nPlease enter the name of the item you would like to bid on:\n");
        scanf("%s", itemName);

        printf("Please enter your name:\n");
        scanf("%s", bidderName);

        printf("Please enter your bid amount:\n");
        scanf("%f", &bidAmount);

        bidOnItem(&list, itemName, bidAmount, bidderName);
        break;
      case 3:
        printf("\nThank you for using the Digital Auction System!\n");
        break;
      default:
        printf("\nInvalid choice, please try again.\n");
        break;
    }
  }

  return 0;
}