//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 50

enum ItemStatus {UNSOLD, SOLD};
struct Item {
  char name[MAX_NAME_LENGTH];
  double starting_price;
  double current_bid;
  enum ItemStatus status;
  int highest_bidder;
};

struct AuctionState {
  pthread_mutex_t lock;
  struct Item items[MAX_ITEMS];
  int num_items;
};

struct Bid {
  int bidder_id;
  int item_id;
  double bid_amount;
};

struct Bidder {
  pthread_t tid;
  int id;
  struct AuctionState *auction_state;
  double balance;
};

void *auctioneer_loop(void *arg);
void *bidder_loop(void *arg);
double get_rand(double lower, double upper);

int main() {
  // Initialize auction state
  struct AuctionState state = {
    .lock = PTHREAD_MUTEX_INITIALIZER,
    .num_items = 0
  };

  pthread_t auctioneer_tid;
  pthread_create(&auctioneer_tid, NULL, auctioneer_loop, &state);

  // Initialize bidders
  struct Bidder bidders[MAX_BIDDERS];
  int num_bidders = 0;

  struct Bidder bidder1 = {
    .id = num_bidders++,
    .auction_state = &state,
    .balance = get_rand(1000, 5000)
  };
  pthread_create(&bidder1.tid, NULL, bidder_loop, &bidder1);
  bidders[bidder1.id] = bidder1;

  struct Bidder bidder2 = {
    .id = num_bidders++,
    .auction_state = &state,
    .balance = get_rand(1000, 5000)
  };
  pthread_create(&bidder2.tid, NULL, bidder_loop, &bidder2);
  bidders[bidder2.id] = bidder2;

  // Wait for bidders and auctioneer to finish
  for (int i = 0; i < num_bidders; i++) {
    pthread_join(bidders[i].tid, NULL);
  }
  pthread_join(auctioneer_tid, NULL);

  return 0;
}

void *auctioneer_loop(void *arg) {
  struct AuctionState *state = arg;
  int num_items = 0;

  while (num_items < MAX_ITEMS) {
    // Sleep for some random time
    struct timespec sleep_time = {
      .tv_sec = 0,
      .tv_nsec = (long)(get_rand(1, 5) * 1000000000)
    };
    nanosleep(&sleep_time, NULL);

    // Generate new item to auction
    struct Item item = {
      .starting_price = get_rand(100, 1000),
      .status = UNSOLD,
      .highest_bidder = -1
    };
    snprintf(item.name, MAX_NAME_LENGTH, "Item %d", num_items);

    // Lock state and add item
    pthread_mutex_lock(&state->lock);
    if (state->num_items < MAX_ITEMS) {
      state->items[state->num_items++] = item;
      printf("Auctioneer: Created new item %s\n", item.name);
    } else {
      printf("Auctioneer: Cannot create new item, maximum reached\n");
    }
    pthread_mutex_unlock(&state->lock);

    num_items++;
  }

  return NULL;
}

void *bidder_loop(void *arg) {
  struct Bidder *bidder = arg;
  struct AuctionState *state = bidder->auction_state;

  while (1) {
    // Select item to bid on
    struct Item *item = NULL;
    int item_id = -1;
    pthread_mutex_lock(&state->lock);
    for (int i = 0; i < state->num_items; i++) {
      if (state->items[i].status == UNSOLD) {
        item = &state->items[i];
        item_id = i;
        break;
      }
    }
    pthread_mutex_unlock(&state->lock);

    if (item) {
      // Generate random bid amount
      double bid_amount = get_rand(item->current_bid + 10, bidder->balance);

      // Lock state and update item bid
      pthread_mutex_lock(&state->lock);
      if (bid_amount > item->current_bid) {
        item->current_bid = bid_amount;
        item->highest_bidder = bidder->id;
        printf("Bidder %d: Placed bid for %s, new highest bid is %.2f\n", bidder->id, item->name, item->current_bid);
      } else {
        printf("Bidder %d: Placed bid for %s, but not high enough\n", bidder->id, item->name);
      }
      pthread_mutex_unlock(&state->lock);

      // Update balance
      bidder->balance -= bid_amount;
    } else {
      // No items left to bid on, stop loop
      break;
    }
  }

  // Print final balance
  printf("Bidder %d: Final balance is %.2f\n", bidder->id, bidder->balance);

  return NULL;
}

double get_rand(double lower, double upper) {
  return (rand() / (double)RAND_MAX) * (upper - lower) + lower;
}