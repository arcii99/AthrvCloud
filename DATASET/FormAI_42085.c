//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define NUM_BIDDERS 3

// Global variables
int highestBid = 0;
int currentBidder = -1;
pthread_mutex_t mutex;
pthread_cond_t cond[NUM_BIDDERS];

// Struct for bidder info
struct Bidder {
    int id;
    int budget;
    int bidAmount;
};

// Function for bidder to place a bid
void *placeBid(void *bidder) {
    struct Bidder *b = (struct Bidder *)bidder;
    pthread_mutex_lock(&mutex);
    while (currentBidder != b->id) {
        pthread_cond_wait(&cond[b->id], &mutex);
    }
    if (b->budget >= highestBid) {
        printf("Bidder %d places a bid of %d\n", b->id, b->bidAmount);
        highestBid = b->bidAmount;
        currentBidder = (currentBidder + 1) % NUM_BIDDERS;
        pthread_cond_broadcast(&cond[currentBidder]);
    } else {
        printf("Bidder %d has dropped out of the auction\n", b->id);
        currentBidder = (currentBidder + 1) % NUM_BIDDERS;
        pthread_cond_broadcast(&cond[currentBidder]);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

// Main function
int main() {
    // Initialize mutex and conditions
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_BIDDERS; i++) {
        pthread_cond_init(&cond[i], NULL);
    }
    
    // Create bidders and assign budgets and bid amounts
    struct Bidder bidders[NUM_BIDDERS];
    bidders[0].id = 0;
    bidders[0].budget = 1000;
    bidders[0].bidAmount = 300;
    bidders[1].id = 1;
    bidders[1].budget = 1500;
    bidders[1].bidAmount = 500;
    bidders[2].id = 2;
    bidders[2].budget = 2000;
    bidders[2].bidAmount = 750;
    
    // Create bidder threads
    pthread_t threads[NUM_BIDDERS];
    for (int i = 0; i < NUM_BIDDERS; i++) {
        pthread_create(&threads[i], NULL, placeBid, (void *)&bidders[i]);
    }
    
    // Join bidder threads
    for (int i = 0; i < NUM_BIDDERS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print final highest bid
    printf("Auction has ended. Highest bid is %d\n", highestBid);
    
    // Cleanup
    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < NUM_BIDDERS; i++) {
        pthread_cond_destroy(&cond[i]);
    }
    pthread_exit(NULL);
}