//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
  int id;
  char bidder[20];
  int bid_amount;
  int seconds_left;
} Bid;

void generate_random_bids(Bid *bids, int num_bids, int max_amount) {
  srand(time(0));

  for (int i = 0; i < num_bids; i++) {
    int id = rand() % 1000;
    int amount = rand() % max_amount;
    int seconds = rand() % 60;
    sprintf(bids[i].bidder, "Bidder%d", i+1);
    bids[i].id = id;
    bids[i].bid_amount = amount;
    bids[i].seconds_left = seconds;
  }
}

void print_bidder_info(Bid bidder) {
  printf("Bidder: %s, ID: %d, Bid Amount: $%d, Time Left: %d seconds\n", 
         bidder.bidder, bidder.id, bidder.bid_amount, bidder.seconds_left);
}

void display_bids(Bid *bids, int num_bids) {
  printf("\nBids:\n");
  for (int i = 0; i < num_bids; i++) {
    print_bidder_info(bids[i]);
  }
}

void sort_bids(Bid *bids, int num_bids) {
  for (int i = 0; i < num_bids - 1; i++) {
    for (int j = 0; j < num_bids - i - 1; j++) {
      if (bids[j].bid_amount < bids[j+1].bid_amount) {
        Bid temp = bids[j];
        bids[j] = bids[j+1];
        bids[j+1] = temp;
      }
    }
  }
}

int main() {
  int num_bids = 5;
  int max_amount = 1000;
  Bid bids[num_bids];

  generate_random_bids(bids, num_bids, max_amount);
  display_bids(bids, num_bids);
  sort_bids(bids, num_bids);
  printf("\nBids sorted in descending order by amount:\n");
  display_bids(bids, num_bids);
  printf("\nWinning bid: ");
  print_bidder_info(bids[0]);

  return 0;
}