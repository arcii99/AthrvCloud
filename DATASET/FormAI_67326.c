//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BIDDERS 10
#define MIN_VALUE 50
#define MAX_VALUE 500

int main() {
   srand(time(NULL));
   int winning_bid = 0;
   int winning_bidder = -1;
   int bidders[NUM_BIDDERS];
   int i;
   
   // fill bidders array with random bid values
   for (i = 0; i < NUM_BIDDERS; i++) {
      bidders[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
   }
   
   // display the bidders and their bids
   printf("Digital Auction System - Bidders and their Bids:\n");
   for (i = 0; i < NUM_BIDDERS; i++) {
      printf("Bidder %d: $%d\n", i+1, bidders[i]);
   }
   printf("\n");
   
   // determine the highest bidder and winning bid
   for (i = 0; i < NUM_BIDDERS; i++) {
      if (bidders[i] > winning_bid) {
         winning_bid = bidders[i];
         winning_bidder = i;
      }
   }
   
   // display the winning bid and bidder
   printf("The winning bid is $%d from Bidder %d!\n", winning_bid, winning_bidder+1);
   
   return 0;
}