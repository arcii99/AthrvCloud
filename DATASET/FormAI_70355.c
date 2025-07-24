//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Constants for auction system
#define MAX_ITEMS 10
#define MAX_BIDS 5
#define MAX_NAME_LEN 20

// Structure for each auction item
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double min_price;
    double current_bid;
    int num_bids;
    char highest_bidder[MAX_NAME_LEN];
} AuctionItem;

// Array of Auction Items
AuctionItem items[MAX_ITEMS];

// Mutex locks for thread synchronization
pthread_mutex_t bid_locks[MAX_ITEMS];

// Function to initialize the auction items
void init_items() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].id = i + 1;
        sprintf(items[i].name, "Item %d", i + 1);
        items[i].min_price = (i + 1) * 10.0;
        items[i].current_bid = items[i].min_price;
        items[i].num_bids = 0;
        memset(items[i].highest_bidder, '\0', MAX_NAME_LEN);
        pthread_mutex_init(&bid_locks[i], NULL);
    }
}

// Function to handle bids for an item
void *handle_bids(void *arg) {
    int item_id = *((int *) arg) - 1;
    while (items[item_id].num_bids < MAX_BIDS) {
        char bidder_name[MAX_NAME_LEN];
        double bid_amount;
        printf("\nEnter your name: ");
        scanf("%s", bidder_name);
        printf("Enter your bid amount: ");
        scanf("%lf", &bid_amount);
        pthread_mutex_lock(&bid_locks[item_id]);
        if (bid_amount > items[item_id].current_bid) {
            items[item_id].current_bid = bid_amount;
            strcpy(items[item_id].highest_bidder, bidder_name);
            items[item_id].num_bids++;
            printf("\nBid accepted for item %d by %s for %.2f\n", item_id + 1, bidder_name, bid_amount);
        } else {
            printf("\nBid amount should be greater than %.2f\n", items[item_id].current_bid);
        }
        pthread_mutex_unlock(&bid_locks[item_id]);
    }
    return NULL;
}

// Function to display the final results of the auction
void display_results() {
    printf("Auction Results:\n\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Item %d: %s\n", items[i].id, items[i].name);
        printf("Minimum Price: %.2f\n", items[i].min_price);
        printf("Current Bid: %.2f by %s\n", items[i].current_bid, items[i].highest_bidder);
        printf("Number of Bids: %d\n\n", items[i].num_bids);
    }
}

// Main function to simulate the auction system
int main() {
    // Initialize the auction items
    init_items();
    // Array of threads for handling bids for each item
    pthread_t bid_threads[MAX_ITEMS];
    // Start a thread for each item to handle bids
    for (int i = 0; i < MAX_ITEMS; i++) {
        pthread_create(&bid_threads[i], NULL, handle_bids, (void *) &items[i].id);
    }
    // Wait for each thread to finish executing
    for (int i = 0; i < MAX_ITEMS; i++) {
        pthread_join(bid_threads[i], NULL);
    }
    // Display the final results of the auction
    display_results();
    // Destroy the mutex locks
    for (int i = 0; i < MAX_ITEMS; i++) {
        pthread_mutex_destroy(&bid_locks[i]);
    }
    return 0;
}