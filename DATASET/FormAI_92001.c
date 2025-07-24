//FormAI DATASET v1.0 Category: Digital Auction System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_BIDS 100       // Max number of bids allowed
#define MAX_NAME_LEN 50    // Max length of bidder name

// Structs
typedef struct bid {
  char name[MAX_NAME_LEN + 1];
  float amount;
} Bid;

typedef struct auction {
  char item_name[MAX_NAME_LEN + 1];
  Bid bids[MAX_BIDS];
  int num_bids;
  float highest_bid;
} Auction;

// Globals
Auction current_auction;

// Functions
void init_auction(char* item_name);
void add_bid(char* name, float amount);
void print_bids();

int main() {
  char item_name[MAX_NAME_LEN + 1];
  printf("Enter auction item name: ");
  fgets(item_name, MAX_NAME_LEN, stdin);

  // Remove newline character from input
  item_name[strcspn(item_name, "\n")] = '\0';

  init_auction(item_name);

  // Begin accepting bids
  char bid_name[MAX_NAME_LEN + 1];
  float bid_amount;
  printf("\nWelcome to the auction for %s!\n", current_auction.item_name);
  while (1) {
    printf("\nEnter your name (or exit to end bidding): ");
    fgets(bid_name, MAX_NAME_LEN, stdin);
    
    // Remove newline character from input
    bid_name[strcspn(bid_name, "\n")] = '\0';

    if (strcmp(bid_name, "exit") == 0) {
      break;
    }

    printf("Enter your bid amount: ");
    scanf("%f", &bid_amount);
    getchar();    // Clear input buffer

    add_bid(bid_name, bid_amount);
  }
  print_bids();  // Print out all bids
  return 0;
}

void init_auction(char* item_name) {
  // Initialize auction struct
  current_auction.num_bids = 0;
  current_auction.highest_bid = 0;
  strncpy(current_auction.item_name, item_name, MAX_NAME_LEN);
}

void add_bid(char* name, float amount) {
  if (current_auction.num_bids == MAX_BIDS) {
    printf("Maximum number of bids reached. Bid not accepted.\n");
    return;
  }
  if (amount <= current_auction.highest_bid) {
    printf("Bid not accepted. Please enter a higher amount.\n");
    return;
  }

  Bid new_bid;
  strncpy(new_bid.name, name, MAX_NAME_LEN);
  new_bid.amount = amount;

  current_auction.bids[current_auction.num_bids] = new_bid;
  current_auction.num_bids++;

  printf("Bid accepted.\n");
  current_auction.highest_bid = amount;
}

void print_bids() {
  printf("\n=====================\n");
  printf("Bids for %s\n", current_auction.item_name);
  printf("=====================\n");

  for (int i = 0; i < current_auction.num_bids; i++) {
    printf("%s: $%.2f\n", current_auction.bids[i].name, 
                          current_auction.bids[i].amount);
  }

  printf("=====================\n");
  printf("Highest bid: $%.2f\n", current_auction.highest_bid);
}