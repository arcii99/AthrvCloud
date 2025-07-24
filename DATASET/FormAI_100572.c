//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 5
#define MIN_BID_AMOUNT 100

struct Bid {
  int amount;
  int bidder_id;
};

struct Item {
  int item_id;
  int current_bid;
  struct Bid bids[MAX_BIDDERS];
  int num_bids;
};

struct Auction {
  struct Item items[MAX_ITEMS];
  int num_items;
};

int generate_random_bid() {
  return (rand() % 1000) + MIN_BID_AMOUNT;
}

void print_item(struct Item item) {
  printf("Item %d\n", item.item_id);
  printf("------------\n");
  printf("Current Bid: %d\n", item.current_bid);
  printf("Bids:\n");

  for (int i = 0; i < item.num_bids; i++) {
    printf("Bid %d: $%d (Bidder ID: %d)\n", i+1, item.bids[i].amount, item.bids[i].bidder_id);
  }
}

int main() {
  srand(time(0));

  struct Auction auction = {
    .num_items = MAX_ITEMS,
    .items = {
      {
        .item_id = 1,
        .current_bid = MIN_BID_AMOUNT,
        .bids = {},
        .num_bids = 0
      },
      {
        .item_id = 2,
        .current_bid = MIN_BID_AMOUNT,
        .bids = {},
        .num_bids = 0
      },
      {
        .item_id = 3,
        .current_bid = MIN_BID_AMOUNT,
        .bids = {},
        .num_bids = 0
      },
      {
        .item_id = 4,
        .current_bid = MIN_BID_AMOUNT,
        .bids = {},
        .num_bids = 0
      },
      {
        .item_id = 5,
        .current_bid = MIN_BID_AMOUNT,
        .bids = {},
        .num_bids = 0
      },
    }
  };

  int num_bidders = MAX_BIDDERS;
  int bidder_id = 1;

  for (int i = 0; i < auction.num_items; i++) {
    printf("*************************************************\n");
    printf("Item %d up for auction!\n", auction.items[i].item_id);
    printf("Current Bid: $%d\n", auction.items[i].current_bid);
    printf("\n");

    for (int j = 0; j < num_bidders; j++) {
      int bid_amount = generate_random_bid();
      struct Bid bid = {
        .amount = bid_amount,
        .bidder_id = bidder_id
      };

      printf("Bidder %d places a bid of $%d on Item %d\n", bid.bidder_id, bid.amount, auction.items[i].item_id);
      bidder_id++;

      if (bid.amount > auction.items[i].current_bid) {
        auction.items[i].bids[0] = bid;
        auction.items[i].current_bid = bid.amount;
        auction.items[i].num_bids = 1;

        printf("Current highest bid: $%d\n", auction.items[i].current_bid);
      } else if (bid.amount == auction.items[i].current_bid) {
        auction.items[i].bids[auction.items[i].num_bids] = bid;
        auction.items[i].num_bids++;

        printf("Bid tied with current highest bid!\n");
        printf("Current highest bid: $%d\n", auction.items[i].current_bid);
      } else {
        printf("Bid not high enough!\n");
        printf("Current highest bid: $%d\n", auction.items[i].current_bid);
      }

      printf("\n");
    }

    print_item(auction.items[i]);

    printf("*************************************************\n\n");
  }

  return 0;
}