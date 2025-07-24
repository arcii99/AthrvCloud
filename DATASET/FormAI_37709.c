//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int bids[10];
  int maxBidIndex = 0;
  int maxBid = 0;
  for(int i = 0; i < 10; i++) {
     bids[i] = rand() % 1000 + 1;
     printf("Bidder %d: $%d\n", i+1, bids[i]);
  }
  for(int i = 0; i < 10; i++) {
      if(bids[i] > maxBid) {
         maxBid = bids[i];
         maxBidIndex = i;
      }
  }
  printf("The highest bid is $%d from bidder %d\n", maxBid, maxBidIndex+1);
  return 0; 
}