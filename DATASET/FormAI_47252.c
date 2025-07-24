//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_BIDDERS 5
#define NUM_ITEMS 3

struct item {
    char name[20];
    float starting_bid;
    float current_bid;
    int highest_bidder;
    sem_t *semaphore;
};

struct bidder {
    char name[20];
    float money;
    int item_choice;
};

struct item auction_items[NUM_ITEMS] = {
    {"Painting", 100.00, 100.00, -1, NULL},
    {"Jewelry", 200.00, 200.00, -1, NULL},
    {"Antique", 300.00, 300.00, -1, NULL}
};

struct bidder bidders[NUM_BIDDERS] = {
    {"Bidder1", 1000.00, -1},
    {"Bidder2", 1000.00, -1},
    {"Bidder3", 1000.00, -1},
    {"Bidder4", 1000.00, -1},
    {"Bidder5", 1000.00, -1}
};

void *auction(void *arg) {
    struct item *i = (struct item *)arg;
    int h_bidder = i->highest_bidder;
    sem_wait(i->semaphore);
    
    printf("Item: %s\n", i->name);
    printf("Starting Bid: $%.2f\n", i->starting_bid);
    printf("Current Bid: $%.2f\n", i->current_bid);
    printf("Highest Bidder: %s\n", h_bidder == -1 ? "None" : bidders[h_bidder].name);
    printf("\n");
    
    sem_post(i->semaphore);
    pthread_exit(NULL);
}

void *bid(void *arg) {
    struct bidder *b = (struct bidder *)arg;

    while (1) {
        int choice = rand() % NUM_ITEMS;
        if (choice == b->item_choice) {
            continue;
        }
        b->item_choice = choice;
    
        float bid_amount = (rand() % (int)b->money) + 1;
    
        sem_wait(auction_items[choice].semaphore);
        if (bid_amount <= auction_items[choice].current_bid) {
            sem_post(auction_items[choice].semaphore);
            continue;
        }

        printf("%s bids $%.2f on item %s\n", b->name, bid_amount, auction_items[choice].name);
        auction_items[choice].current_bid = bid_amount;
        auction_items[choice].highest_bidder = b - bidders;
        sem_post(auction_items[choice].semaphore);
        
        b->money -= bid_amount;
    }
}

int main() {
    pthread_t thread[NUM_BIDDERS + NUM_ITEMS];
    sem_t item_semaphores[NUM_ITEMS];
    
    for (int i = 0; i < NUM_ITEMS; i++) {
        auction_items[i].semaphore = &item_semaphores[i];
        sem_init(auction_items[i].semaphore, 0, 1);
        pthread_create(&thread[i], NULL, auction, &auction_items[i]);
    }

    for (int i = 0; i < NUM_BIDDERS; i++) {
        pthread_create(&thread[NUM_ITEMS + i], NULL, bid, &bidders[i]);
    }

    for (int i = 0; i < NUM_BIDDERS + NUM_ITEMS; i++) {
        pthread_join(thread[i], NULL);
    }

    return 0;
}