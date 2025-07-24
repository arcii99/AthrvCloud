//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct AuctionItem {
  int item_id;
  char item_name[20];
  float min_bid;
  int bid_count;
  float current_bid;
};

int main() {
  int num_items, i, j, choice, item_choice, bid_choice;
  printf("Welcome to the Digital Auction System!\n\n");
  printf("Enter the number of items up for bidding: ");
  scanf("%d", &num_items);

  struct AuctionItem items[num_items];

  for(i=0; i<num_items; i++) {
    printf("\nEnter details for item %d: \n\n", i+1);
    printf("Item name: ");
    scanf("%s", items[i].item_name);
    printf("Minimum bid: ");
    scanf("%f", &items[i].min_bid);
    items[i].current_bid = items[i].min_bid - 1;
    items[i].bid_count = 0;
    items[i].item_id = i+1;
  }

  do {
    printf("\nChoose an option:\n\n");
    printf("1. View items\n");
    printf("2. Place a bid\n");
    printf("3. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: // View items
        printf("\nCurrent items for bidding:\n\n");
        for(i=0; i<num_items; i++) {
          printf("%d. %s (minimum bid: %.2f)\n", items[i].item_id, items[i].item_name, items[i].min_bid);
          printf("   Current bid: %.2f\n", items[i].current_bid);
          printf("   Number of bids: %d\n\n", items[i].bid_count);
        }
        break;

      case 2: // Place a bid
        printf("\nEnter the ID of the item you want to bid for: ");
        scanf("%d", &item_choice);
        for(i=0; i<num_items; i++) {
          if(items[i].item_id == item_choice) {
            printf("\nYou are bidding for: %s (minimum bid: %.2f)\n\n", items[i].item_name, items[i].min_bid);
            printf("Current highest bid: %.2f\n\n", items[i].current_bid);
            printf("Enter your bid (must be higher than current highest bid): ");
            scanf("%f", &items[i].current_bid);
            if(items[i].current_bid <= items[i].min_bid || items[i].current_bid <= items[i].current_bid) {
              printf("\nInvalid bid, must be higher than minimum bid and current highest bid.\n");
              items[i].current_bid = items[i].current_bid - 1;
            }
            else {
              items[i].bid_count++;
              printf("\nCongratulations, you are the current highest bidder for %s at %.2f!\n", items[i].item_name, items[i].current_bid);
            }
            break;
          }
        }
        if(i == num_items) {
          printf("\nInvalid item choice, please try again.\n");
        }
        break;

      case 3: // Exit
        printf("\nThank you for using the Digital Auction System!\n\n");
        break;

      default:
        printf("\nPlease choose a valid option.\n");
        break;
    }
  } while(choice != 3);

  return 0;
}