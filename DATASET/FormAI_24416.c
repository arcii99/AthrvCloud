//FormAI DATASET v1.0 Category: Digital Auction System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BIDS 10 // Maximum number of bids
#define ITEM_PRICE 1000 // Starting price of the item
#define MIN_INCREMENT 50 // Minimum bid increment

void auction(int bid_counter, float highest_bid) {
    float new_bid;
    printf("Current highest bid: $%.2f\n", highest_bid);
    printf("Enter Your Bid (at least $%.2f): ", highest_bid + MIN_INCREMENT);
    scanf("%f", &new_bid);
    if (new_bid >= highest_bid + MIN_INCREMENT) {
        highest_bid = new_bid;
        printf("You are now the highest bidder with a bid of $%.2f\n", highest_bid);
    } else {
        printf("Sorry, you must bid at least $%.2f higher than the current bid of $%.2f\n", MIN_INCREMENT, highest_bid);
    }
    if (bid_counter < MAX_BIDS) {
        printf("Bids remaining: %d\n", MAX_BIDS - bid_counter);
        auction(bid_counter + 1, highest_bid);
    } else {
        printf("Auction Over!\n");
    }
}

int main() {
    printf("Starting Price of the item: $%d\n", ITEM_PRICE);
    printf("Welcome to the Digital Auction System\n");
    printf("************************************\n");
    printf("Instructions:\n");
    printf("1. The starting bid is set at $%d\n", ITEM_PRICE);
    printf("2. Each subsequent bid must be at least $%d higher than the previous bid.\n", MIN_INCREMENT);
    printf("3. The auction will end after %d bids have been placed.\n", MAX_BIDS);
    auction(1, ITEM_PRICE);
    return 0;
}