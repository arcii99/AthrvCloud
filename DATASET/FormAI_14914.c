//FormAI DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
   char userName[30], itemName[50], c;
   int minBid, currentBid, newBid;
   printf("Hey there! Welcome to our Digital Auction System!\n");
   printf("Please enter your name: ");
   scanf("%s", userName);
   printf("\nThank you, %s! Let's get started.\n", userName);
   printf("What is the name of the item up for auction? ");
   scanf("%s", itemName);
   printf("\nGreat, the item up for bid is %s.\n", itemName);
   printf("What's the starting bid for %s? $", itemName);
   scanf("%d", &minBid);
   printf("\nGot it. The current bid for %s is $%d.\n", itemName, minBid);
   printf("\nLet's start the auction! Enter -1 if you want to quit the auction.\n");
   currentBid = minBid;
   do {
      printf("\n%s, enter your bid (current bid: $%d): $", userName, currentBid);
      scanf("%d", &newBid);
      if (newBid == -1) {
         printf("\nThank you for participating in the auction, %s!\n", userName);
         exit(0);
      }
      if (newBid <= currentBid) {
         printf("\nYour bid of $%d is too low. Please try again.\n", newBid);
      }
      else {
         currentBid = newBid;
         printf("\nCongratulations, %s! You are the new high bidder with a bid of $%d!\n", userName, currentBid);
      }
   } while (1);
   return 0;
}