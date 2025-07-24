//FormAI DATASET v1.0 Category: Digital Auction System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define AUCTION_DURATION 60 // 1 minute auction
#define MAX_BID_LENGTH 8
#define MAX_NAME_LENGTH 20
#define NUM_ITEMS 3

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int current_bid;
    char current_bidder[MAX_NAME_LENGTH];
    int time_left;
} auction_item;

auction_item auction_items[NUM_ITEMS]; // array to store all auction items

// function to randomly generate starting bids for items
int gen_starting_bid() {
    return (rand() % 50) + 50; // starting bid between $50 and $100
}

// function to print out all current auction items
void print_items() {
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("(%d) %s - Current Bid: $%d - Current Bidder: %s - Time Left: %d seconds\n", 
            auction_items[i].id, auction_items[i].name, auction_items[i].current_bid, 
            auction_items[i].current_bidder, auction_items[i].time_left);
    }
}

// function to handle bids, called asynchronously
void bid_handler(void *args) {
    char *input = (char *) args;
    int item_id, bid;
    sscanf(input, "%d %d", &item_id, &bid);
    auction_item *item = &auction_items[item_id-1]; // subtract 1 from item_id to match array index
    if (bid > item->current_bid) {
        item->current_bid = bid;
        strcpy(item->current_bidder, "Anonymous"); // bidder not authenticated
        printf("New bid of $%d received for %s!\n", bid, item->name);
    }
    else {
        printf("Bid of $%d for %s not accepted, current bid is $%d\n", bid, item->name, item->current_bid);
    }
}

int main() {
    srand(time(NULL)); // initialize random seed
    char input[MAX_BID_LENGTH];
    int seconds_passed = 0;

    // initialize auction items
    auction_items[0].id = 1;
    strcpy(auction_items[0].name, "Vintage Typewriter");
    auction_items[0].current_bid = gen_starting_bid();
    auction_items[0].time_left = AUCTION_DURATION;
    
    auction_items[1].id = 2;
    strcpy(auction_items[1].name, "Autographed Baseball");
    auction_items[1].current_bid = gen_starting_bid();
    auction_items[1].time_left = AUCTION_DURATION;
    
    auction_items[2].id = 3;
    strcpy(auction_items[2].name, "Handmade Quilt");
    auction_items[2].current_bid = gen_starting_bid();
    auction_items[2].time_left = AUCTION_DURATION;

    printf("Welcome to the Auction!\n");
    printf("These are the items up for bid:\n");
    print_items();
    printf("Enter your bids in the format \"{itm} {bid}\" (ex: \"1 75\")\n");

    while (1) { // loop until auction is over
        printf("\nTime left: %d seconds\n", AUCTION_DURATION - seconds_passed);
        fgets(input, MAX_BID_LENGTH, stdin); // get input from user
        bid_handler((void *) input); // call bid_handler asynchronously
        sleep(1); // sleep for 1 second to simulate asynchronous processing
        seconds_passed++; // increment time passed
        if (seconds_passed >= AUCTION_DURATION) {
            printf("\nThank you for participating in the auction!\n");
            printf("These are the final results:\n");
            print_items();
            break; // end auction
        }
    }
    return 0;
}