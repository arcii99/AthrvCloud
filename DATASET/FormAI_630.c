//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// define maximum allowable length of strings
#define MAX_LENGTH 100

// define struct for bids
typedef struct {
    char name[MAX_LENGTH];
    int amount;
} Bid;

int main() {
    // initialize variables, including two bids for Romeo and Juliet
    int num_bids = 2;
    Bid romeo_bid, juliet_bid;
    // set default values for the bids
    strcpy(romeo_bid.name, "Romeo");
    romeo_bid.amount = 0;
    strcpy(juliet_bid.name, "Juliet");
    juliet_bid.amount = 0;

    // set up random seed for generating bids
    srand(time(NULL));

    // generate bids for Romeo and Juliet
    romeo_bid.amount = rand() % 5000 + 1;
    juliet_bid.amount = rand() % 5000 + 1;

    // compare bids to determine winner
    if (romeo_bid.amount > juliet_bid.amount) {
        printf("Romeo wins with a bid of %d!\n", romeo_bid.amount);
    } else if (juliet_bid.amount > romeo_bid.amount) {
        printf("Juliet wins with a bid of %d!\n", juliet_bid.amount);
    } else {
        printf("The bidding war ended in a tie!\n");
    }

    return 0;
}