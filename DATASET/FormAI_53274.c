//FormAI DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

struct AuctionItem{
  int itemNumber;
  char itemName[20];
  float startingBid;
  float currentBid;
  char bidderName[20];
  int bidCount;
};

void displayItem(struct AuctionItem item){
  printf("Item Number: %d\nItem Name: %s\nStarting Bid: $%.2f\nCurrent Bid: $%.2f\nBidder Name: %s\nBid Count: %d\n", item.itemNumber, item.itemName, item.startingBid, item.currentBid, item.bidderName, item.bidCount);
}

int main(){
  struct AuctionItem items[3];
  items[0].itemNumber = 1;
  strcpy(items[0].itemName, "Antique Vase");
  items[0].startingBid = 100.00;
  items[0].currentBid = 100.00;
  strcpy(items[0].bidderName, "");
  items[0].bidCount = 0;
  
  items[1].itemNumber = 2;
  strcpy(items[1].itemName, "Signed Baseball");
  items[1].startingBid = 50.00;
  items[1].currentBid = 50.00;
  strcpy(items[1].bidderName, "");
  items[1].bidCount = 0;
  
  items[2].itemNumber = 3;
  strcpy(items[2].itemName, "Framed Art Print");
  items[2].startingBid = 75.00;
  items[2].currentBid = 75.00;
  strcpy(items[2].bidderName, "");
  items[2].bidCount = 0;

  int choice;
  float bidAmount;
  char name[20];
  printf("Welcome to the Digital Auction System!\n\n");
  while(1){
    printf("\n-------- MENU --------\n");
    printf("1. Display Items\n2. Place Bid\n3. Exit\n");
    printf("----------------------\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    if(choice == 1){
      printf("\n----- CURRENT AUCTION ITEMS -----\n");
      for(int i = 0; i < 3; i++){
        printf("Item %d\n", i+1);
        displayItem(items[i]);
        printf("\n");
      }
    }
    else if(choice == 2){
      int itemChoice;
      printf("\nEnter Item Number: ");
      scanf("%d", &itemChoice);

      if(itemChoice > 0 && itemChoice < 4){
        printf("Enter Your Name: ");
        scanf("%s", name);
        printf("Enter Bid Amount: ");
        scanf("%f", &bidAmount);
        if(bidAmount > items[itemChoice-1].currentBid){
          items[itemChoice-1].currentBid = bidAmount;
          strcpy(items[itemChoice-1].bidderName, name);
          items[itemChoice-1].bidCount++;
          printf("\nBid Placed Successfully!\n");
        }
        else{
          printf("\nYour Bid Amount Should be Greater Than Current Bid Amount!\n");
        }
      }
      else{
        printf("\nInvalid Item Number.\n");
      }
    }
    else if(choice == 3){
      printf("\nExiting the Digital Auction System...\n");
      exit(0);
    }
    else{
      printf("\nInvalid Choice. Please Try Again.\n");
    }
  }

  return 0;
}