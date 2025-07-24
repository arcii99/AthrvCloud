//FormAI DATASET v1.0 Category: Digital Auction System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ITEMS 50
#define MAX_BIDS 50

struct Item {
  int id;
  char name[50];
  int current_bid;
  int highest_bidder_id;
};

struct Bid {
  int item_id;
  int bidder_id;
  int bid_amount;
};

struct Bidder {
  int id;
  char name[50];
  int gold_coins;
};

struct Item auction_items[MAX_ITEMS];
struct Bid auction_bids[MAX_BIDS];
struct Bidder auction_bidders[MAX_BIDS];

int init_auction() {
  int num_items = 5;
  int num_bidders = 3;

  // Items
  auction_items[0] = (struct Item) {1, "Sword of Destiny", 50, 2};
  auction_items[1] = (struct Item) {2, "Magic Potion", 20, 0};
  auction_items[2] = (struct Item) {3, "Golden Chalice", 100, 3};
  auction_items[3] = (struct Item) {4, "Enchanted Necklace", 75, 0};
  auction_items[4] = (struct Item) {5, "Dragon Egg", 200, 0};

  // Bidders
  auction_bidders[0] = (struct Bidder) {1, "Sir Lancelot", 300};
  auction_bidders[1] = (struct Bidder) {2, "Lady Guinevere", 500};
  auction_bidders[2] = (struct Bidder) {3, "Sir Galahad", 200};

  return num_items;
}

void display_items(int num_items) {
  printf("Auction Items:\n");
  printf("%-5s%-25s%-15s%-20s\n", "ID", "Name", "Current Bid", "Highest Bidder");
  for (int i = 0; i < num_items; i++) {
    struct Item item = auction_items[i];
    struct Bidder bidder;
    if (item.highest_bidder_id != 0) {
      bidder = auction_bidders[item.highest_bidder_id - 1];
    }
    printf("%-5d%-25s%d%-14s%-20s\n", item.id, item.name, item.current_bid, "gold", item.highest_bidder_id == 0 ? "No bids yet" : bidder.name);
  }
  printf("\n");
}

void display_bidders(int num_bidders) {
  printf("Auction Bidders:\n");
  printf("%-5s%-25s%-15s\n", "ID", "Name", "Gold Coins");
  for (int i = 0; i < num_bidders; i++) {
    struct Bidder bidder = auction_bidders[i];
    printf("%-5d%-25s%-15d\n", bidder.id, bidder.name, bidder.gold_coins);
  }
  printf("\n");
}

void print_welcome_message() {
  printf("Welcome to the Medieval Auction System!\n");
  printf("To bid on an item, enter the ID of the item and your bid amount.\n");
  printf("To exit, enter 0 for both the item ID and bid amount.\n");
  printf("\n");
}

bool bid_on_item(int bidder_id, int item_id, int bid_amount, int num_items) {
  struct Item * item = NULL;
  for (int i = 0; i < num_items; i++ ) {
    if (auction_items[i].id == item_id) {
      item = &auction_items[i];
      break;
    }
  }

  if (item == NULL || bid_amount <= item->current_bid) {
    return false;
  }

  struct Bidder * bidder = NULL;
  for (int i = 0; i < MAX_BIDS; i++ ) {
    if (auction_bidders[i].id == bidder_id) {
      bidder = &auction_bidders[i];
      break;
    }
  }

  if (bidder == NULL || bid_amount > bidder->gold_coins) {
    return false;
  }

  if (item->highest_bidder_id != 0) {
    struct Bidder * previous_bidder = &auction_bidders[item->highest_bidder_id - 1];
    previous_bidder->gold_coins += item->current_bid;
  }

  item->highest_bidder_id = bidder_id;
  item->current_bid = bid_amount;
  bidder->gold_coins -= bid_amount;

  auction_bids[item_id - 1] = (struct Bid) {item_id, bidder_id, bid_amount};

  return true;
}

void display_bids(int num_items) {
  printf("Auction Bids:\n");
  printf("%-5s%-25s%-15s%-20s\n", "ID", "Item", "Bidder", "Bid Amount");
  for (int i = 0; i < num_items; i++) {
    struct Bid bid = auction_bids[i];
    struct Item item = auction_items[bid.item_id - 1];
    struct Bidder bidder = auction_bidders[bid.bidder_id - 1];
    printf("%-5d%-25s%-15s%-20d\n", i+1, item.name, bidder.name, bid.bid_amount);
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  int num_items = init_auction();
  int num_bidders = 3;

  print_welcome_message();

  while (true) {
    display_items(num_items);
    display_bidders(num_bidders);
    display_bids(num_items);

    int item_id, bid_amount;
    printf("Enter the ID of the item you want to bid on: ");
    scanf("%d", &item_id);

    if (item_id == 0) {
      break;
    }

    printf("Enter your bid amount: ");
    scanf("%d", &bid_amount);

    if (bid_amount == 0) {
      break;
    }

    if (bid_on_item(1, item_id, bid_amount, num_items)) {
      printf("Bid successful!\n");
    } else {
      printf("Bid unsuccessful. Please try again.\n");
    }
  }

  printf("Auction Results:\n");
  display_items(num_items);
  display_bidders(num_bidders);
  display_bids(num_items);

  return 0;
}