//FormAI DATASET v1.0 Category: Digital Auction System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// struct to hold information about an auction item
typedef struct {
    char name[50];
    double current_bid;
    char current_bidder[50];
    int auction_duration;  // in minutes
    time_t starting_time;
} AuctionItem;

// function to display the details of an AuctionItem
void display_item_details(AuctionItem item) {
    printf("Name: %s\n", item.name);
    printf("Starting bid: $%.2f\n", item.current_bid);
    printf("Current bidder: %s\n", item.current_bidder);
    printf("Auction duration: %d minutes\n", item.auction_duration);
}

// function to bid on an item
void place_bid(AuctionItem *item, double bid_amount, char bidder_name[50]) {
    if (bid_amount <= item->current_bid) {
        printf("Bid must be higher than current bid of $%.2f\n", item->current_bid);
    } else {
        // update the current_bid and current_bidder fields of the item
        item->current_bid = bid_amount;
        strcpy(item->current_bidder, bidder_name);
        printf("%s is now the highest bidder with a bid of $%.2f\n", bidder_name, bid_amount);
    }
}

int main() {
    // create an AuctionItem object for a watch
    AuctionItem watch = {"Luxury Watch", 100.00, "No current bidder", 5, time(NULL)};
    display_item_details(watch);
    
    // simulate the passage of time
    printf("\nSimulating auction...\n");
    int seconds_passed = 0;
    while (seconds_passed < watch.auction_duration * 60) {
        // generate a random bid every 10 seconds
        if (seconds_passed % 10 == 0) {
            double bid_amount = (double) rand() / (double) RAND_MAX * 100.00 + watch.current_bid;
            char bidder_name[50];
            sprintf(bidder_name, "Bidder %d", rand() % 10);
            place_bid(&watch, bid_amount, bidder_name);
        }
        seconds_passed += 1;
    }
    
    // display the details of the final bid
    printf("\nAuction over!\n");
    display_item_details(watch);
    
    return 0;
}