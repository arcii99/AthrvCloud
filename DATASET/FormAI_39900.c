//FormAI DATASET v1.0 Category: Digital Auction System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define NUM_ITEMS 5
#define MAX_AUCTION_TIME 30 // in seconds
#define MAX_BID 100
#define NUM_BUYERS 3

typedef struct {
    int id;
    char name[50];
    int current_bid;
    int bid_winner;
    int seller_id;
} item;

typedef struct {
    int id;
    int current_bid;
    int item_id;
} bid;

item items[NUM_ITEMS];
bid current_bids[NUM_ITEMS];
int num_bids;

pthread_mutex_t mutex_current_bids = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_num_bids = PTHREAD_MUTEX_INITIALIZER;

void randomize_items() {
    srand(time(NULL));
    for(int i = 0; i < NUM_ITEMS; i++) {
        items[i].id = i + 1;
        sprintf(items[i].name, "Item %d", i + 1);
        items[i].current_bid = 0;
        items[i].bid_winner = 0;
        items[i].seller_id = (rand() % NUM_BUYERS) + 1; // assign random seller
    }
}

void print_item(item item) {
    printf("Item %d: %s. Current bid: $%d. ", item.id, item.name, item.current_bid);
    if(item.bid_winner) {
        printf("Bid winner: Buyer %d.\n", item.bid_winner);
    } else {
        printf("No bid winner yet.\n");
    }
}

void print_items() {
    for(int i = 0; i < NUM_ITEMS; i++) {
        print_item(items[i]);
    }
}

void print_bid(bid bid) {
    printf("Bid: $%d for Item %d. Bidder: Buyer %d\n", bid.current_bid, bid.item_id, bid.id);
}

void add_bid(int id, int current_bid, int item_id) {
    pthread_mutex_lock(&mutex_current_bids);
    current_bids[num_bids].id = id;
    current_bids[num_bids].current_bid = current_bid;
    current_bids[num_bids].item_id = item_id;
    num_bids++;
    pthread_mutex_unlock(&mutex_current_bids);
}

void update_item_bid(int item_id, int current_bid, int bidder_id) {
    pthread_mutex_lock(&mutex_current_bids);
    for(int i = 0; i < NUM_ITEMS; i++) {
        if(items[i].id == item_id) {
            if(current_bid > items[i].current_bid) {
                items[i].current_bid = current_bid;
                items[i].bid_winner = bidder_id;
            }
            break;
        }
    }
    pthread_mutex_unlock(&mutex_current_bids);
}

void *buyer(void *id_ptr) {
    int id = *(int *)id_ptr;
    printf("Buyer %d has joined the auction.\n", id);

    while(1) {
        int time_to_bid = (rand() % MAX_AUCTION_TIME) + 1;
        printf("Buyer %d is waiting for %d seconds to bid.\n", id, time_to_bid);
        sleep(time_to_bid);

        int item_to_bid = rand() % NUM_ITEMS;
        int bid_amount = (rand() % MAX_BID) + 1;

        pthread_mutex_lock(&mutex_num_bids);
        int bid_id = num_bids;
        num_bids++;
        pthread_mutex_unlock(&mutex_num_bids);

        printf("Buyer %d is placing a bid of $%d on Item %d.\n", id, bid_amount, item_to_bid + 1);
        add_bid(id, bid_amount, item_to_bid + 1);
        update_item_bid(item_to_bid + 1, bid_amount, id);

        printf("Buyer %d's bid has been recorded.\n", id);
    }
    pthread_exit(NULL);
}

int main() {
    randomize_items();
    print_items();

    int buyer_ids[NUM_BUYERS];
    pthread_t threads[NUM_BUYERS];

    for(int i = 0; i < NUM_BUYERS; i++) {
        buyer_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, &buyer, (void *)&buyer_ids[i]);
    }

    for(int i = 0; i < NUM_BUYERS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}