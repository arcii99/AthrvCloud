//FormAI DATASET v1.0 Category: Digital Auction System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 100
#define MAX_ITEMS 100

struct Item {
  int id;
  char name[50];
  int current_bid;
  int bidder_id;
} items[MAX_ITEMS];

struct Bidder {
  int id;
  char name[50];
  int balance;
  int num_bids;
  int item_ids[MAX_ITEMS];
} bidders[MAX_BIDDERS];

int num_items = 0;
int num_bidders = 0;

void add_item(int id, char *name, int starting_bid) {
  items[num_items].id = id;
  strncpy(items[num_items].name, name, sizeof(items[num_items].name));
  items[num_items].current_bid = starting_bid;
  items[num_items].bidder_id = -1;
  num_items++;
}

void add_bidder(int id, char *name, int balance) {
  bidders[num_bidders].id = id;
  strncpy(bidders[num_bidders].name, name, sizeof(bidders[num_bidders].name));
  bidders[num_bidders].balance = balance;
  bidders[num_bidders].num_bids = 0;
  num_bidders++;
}

void bid(int bidder_id, int item_id, int amount) {
  if (item_id < 0 || item_id >= num_items) {
    printf("Invalid item ID\n");
    return;
  }
  if (bidder_id < 0 || bidder_id >= num_bidders) {
    printf("Invalid bidder ID\n");
    return;
  }
  struct Item *item = &items[item_id];
  struct Bidder *bidder = &bidders[bidder_id];
  if (item->current_bid >= amount) {
    printf("Bid amount must be higher than current bid\n");
    return;
  }
  if (bidder->balance < amount) {
    printf("Bidder does not have sufficient balance\n");
    return;
  }
  if (item->bidder_id == bidder_id) {
    printf("Bidder is already highest bidder for this item\n");
    return;
  }
  if (item->bidder_id != -1) {
    struct Bidder *prev_bidder = &bidders[item->bidder_id];
    prev_bidder->balance += item->current_bid;
    prev_bidder->num_bids--;
  }
  item->bidder_id = bidder_id;
  item->current_bid = amount;
  bidder->balance -= amount;
  bidder->num_bids++;
  bidder->item_ids[bidder->num_bids-1] = item_id;
  printf("%s is now the highest bidder for %s with a bid of %d\n", bidder->name, item->name, amount);
}

void display_items() {
  char header[100];
  sprintf(header, "|%5s | %-20s |%12s |%10s |%7s|", "ID", "Name", "Current Bid", "Bidder ID", "Status");
  printf("%s\n", header);
  printf("%s\n", "------------------------------------------------------------------");
  for (int i = 0; i < num_items; i++) {
    struct Item *item = &items[i];
    char status[10];
    if (item->bidder_id == -1) {
      snprintf(status, sizeof(status), "Open");
    } else {
      snprintf(status, sizeof(status), "Sold");
    }
    printf("|%5d | %-20s |%12d |%10d |%7s|\n", item->id, item->name, item->current_bid, item->bidder_id, status);
  }
}

void display_bidders() {
  char header[100];
  sprintf(header, "|%5s | %-20s |%12s |%10s |%20s |", "ID", "Name", "Balance", "Num Bids", "Items Bid On");
  printf("%s\n", header);
  printf("%s\n", "-------------------------------------------------------------------------------------");
  for (int i = 0; i < num_bidders; i++) {
    struct Bidder *bidder = &bidders[i];
    printf("|%5d | %-20s |%12d |%10d |", bidder->id, bidder->name, bidder->balance, bidder->num_bids);
    for (int j = 0; j < bidder->num_bids; j++) {
      printf("%d ", bidder->item_ids[j]);
    }
    printf("|\n");
  }
}

int main() {
  add_item(0, "Painting", 1000);
  add_item(1, "Statue", 500);
  add_item(2, "Vase", 750);
  add_bidder(0, "Alice", 2000);
  add_bidder(1, "Bob", 1500);
  add_bidder(2, "Charlie", 1000);
  bid(0, 0, 1200);
  bid(1, 0, 1300);
  bid(2, 0, 1400);
  bid(1, 1, 600);
  display_items();
  display_bidders();
  return 0;
}