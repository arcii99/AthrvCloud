//FormAI DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char itemName[20];
  int itemId;
  float basePrice;
  float highestBid;
  char highestBidder[20];
} Item;

int main(){
  int i, j, choice, numItems, itemChoice, bidChoice;
  float bidAmt;
  char name[20];
  printf("Welcome to the Digital Auction System\nEnter the number of items up for auction: ");
  scanf("%d", &numItems);
  Item items[numItems];
  for(i=0; i<numItems; i++){
    printf("\nEnter details for item no. %d\n", i+1);
    printf("Enter item name: ");
    scanf("%s", &items[i].itemName);
    printf("Enter item ID: ");
    scanf("%d", &items[i].itemId);
    printf("Enter base price: ");
    scanf("%f", &items[i].basePrice);
    items[i].highestBid = items[i].basePrice;
    strcpy(items[i].highestBidder, "None");
  }
  while(1){
    printf("\nChoose an action:\n");
    printf("1. List all items\n2. Place a bid\n3. Exit\n");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("\nItem ID\tItem Name\tBase Price\tHighest Bid\tHighest Bidder\n");
        for(i=0; i<numItems; i++){
          printf("%d\t%s\t%.2f\t", items[i].itemId, items[i].itemName, items[i].basePrice);
          if(items[i].highestBid == items[i].basePrice){
            printf("--\t--\n");
          }
          else{
            printf("%.2f\t%s\n", items[i].highestBid, items[i].highestBidder);
          }
        }
        break;
      case 2:
        printf("\nEnter your name: ");
        scanf("%s", &name);
        printf("Enter the ID of the item you want to bid on: ");
        scanf("%d", &itemChoice);
        for(i=0; i<numItems; i++){
          if(items[i].itemId == itemChoice){
            printf("Enter your bid amount: ");
            scanf("%f", &bidAmt);
            if(bidAmt > items[i].highestBid){
              items[i].highestBid = bidAmt;
              strcpy(items[i].highestBidder, name);
              printf("Bid successful!\n");
            }
            else{
              printf("Your bid is not higher than the current highest bid.\n");
            }
            break;
          }
        }
        break;
      case 3:
        printf("\nExiting program. Thank you for using the Digital Auction System!\n");
        exit(0);
      default:
        printf("\nInvalid choice. Try again.\n");
    }
  }
  return 0;
}