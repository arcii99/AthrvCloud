//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bidder {
  int id;
  char name[50];
  int bid_amount;
};

struct Auction {
  char item_name[50];
  int starting_bid;
  int highest_bid;
  struct Bidder highest_bidder;
};

int main() {
  struct Auction auction;
  strcpy(auction.item_name, "Antique Painting");
  auction.starting_bid = 100;
  auction.highest_bid = 0;
  
  struct Bidder bidders[3];
  strcpy(bidders[0].name, "Romeo");
  bidders[0].id = 1;
  bidders[0].bid_amount = 150;
  strcpy(bidders[1].name, "Juliet");
  bidders[1].id = 2;
  bidders[1].bid_amount = 200;
  strcpy(bidders[2].name, "Tybalt");
  bidders[2].id = 3;
  bidders[2].bid_amount = 120;
  
  printf("Welcome to the auction of %s\n", auction.item_name);
  printf("The starting bid is %d\n", auction.starting_bid);
  
  int i;
  for (i=0; i<3; i++) {
    if (bidders[i].bid_amount >= auction.starting_bid && bidders[i].bid_amount > auction.highest_bid) {
      auction.highest_bid = bidders[i].bid_amount;
      auction.highest_bidder = bidders[i];
    }
  }
  
  if (auction.highest_bid > 0) {
    printf("The highest bid is %d by %s\n", auction.highest_bid, auction.highest_bidder.name);
  } else {
    printf("No one has bid on the item yet.\n");
  }
  
  return 0;
}