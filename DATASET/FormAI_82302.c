//FormAI DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDS 10
#define MAX_ITEMS 5

typedef struct {
   int id;
   char name[20];
   int price;
   int status;
} Item;

typedef struct {
   int id;
   char name[20];
   int bid;
} Bid;

int main() {
   srand(time(NULL));

   Item items[MAX_ITEMS] = {
      {1, "Item A", 100, 0},
      {2, "Item B", 200, 0},
      {3, "Item C", 300, 0},
      {4, "Item D", 400, 0},
      {5, "Item E", 500, 0}
   };

   Bid bids[MAX_BIDS];
   int num_bids = 0;

   printf("Welcome to the Digital Auction System!\n");

   // Main loop
   while (1) {
      // Display items
      printf("\nItems:\n");
      for (int i = 0; i < MAX_ITEMS; i++) {
         Item item = items[i];
         printf("%d. %s - $%d - ", item.id, item.name, item.price);
         if (item.status == 1) {
            printf("SOLD\n");
         } else {
            printf("AVAILABLE\n");
         }
      }

      // Display bids
      printf("\nBids:\n");
      for (int i = 0; i < MAX_BIDS; i++) {
         Bid bid = bids[i];
         if (bid.bid > 0) {
            printf("%d. %s - $%d\n", bid.id, bid.name, bid.bid);
         }
      }

      // Get user input
      int action;
      printf("\nWhat would you like to do?\n");
      printf("1. Bid on an item\n");
      printf("2. Quit\n");
      scanf("%d", &action);

      if (action == 1) {
         // Get item id
         int item_id;
         printf("Enter the item id you would like to bid on: ");
         scanf("%d", &item_id);

         // Check if item exists and is available
         Item item;
         int item_found = 0;
         for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i].id == item_id) {
               item = items[i];
               item_found = 1;
               break;
            }
         }
         if (!item_found || item.status == 1) {
            printf("Invalid item id or item not available.\n");
            continue;
         }

         // Get bid amount
         int bid_amount;
         printf("Enter your bid amount: ");
         scanf("%d", &bid_amount);

         // Check if bid is higher than current price
         if (bid_amount <= item.price) {
            printf("Your bid must be higher than the current price.\n");
            continue;
         }

         // Add bid to list
         Bid bid = {num_bids + 1, "User", bid_amount};
         bids[num_bids] = bid;
         num_bids++;

         // Update item price
         items[item_id - 1].price = bid_amount;

         printf("Bid placed successfully!\n");
      } else if (action == 2) {
         printf("Thanks for using the Digital Auction System!\n");
         break;
      } else {
         printf("Invalid option selected.\n");
      }
   }

   return 0;
}