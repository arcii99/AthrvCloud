//FormAI DATASET v1.0 Category: Digital Auction System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define a struct for the auction item
struct AuctionItem {
    char name[50];
    int minimum_bid;
    int current_bid;
    char bidder[50];
};

// function to display the current bid and bidder information
void display_bid_info(struct AuctionItem item) {
    printf("Current Bid: %d\n", item.current_bid);
    if (item.current_bid == item.minimum_bid) {
        printf("Minimum Bid: %d\n", item.minimum_bid);
    } else {
        printf("Minimum Bid: %d (Current Bid + $1)\n", item.current_bid);
    }
    if (strlen(item.bidder) == 0) {
        printf("Highest Bidder: None\n");
    } else {
        printf("Highest Bidder: %s\n", item.bidder);
    }
    printf("\n");
}

int main() {

    // create an array of auction items
    int num_items = 3;
    struct AuctionItem auction_items[num_items];

    // initialize the auction_items
    strcpy(auction_items[0].name, "Signed basketball by LeBron James");
    auction_items[0].minimum_bid = 100;
    auction_items[0].current_bid = 0;
    strcpy(auction_items[0].bidder, "");

    strcpy(auction_items[1].name, "Game-worn jersey by Tom Brady");
    auction_items[1].minimum_bid = 500;
    auction_items[1].current_bid = 0;
    strcpy(auction_items[1].bidder, "");

    strcpy(auction_items[2].name, "Autographed guitar by Jimi Hendrix");
    auction_items[2].minimum_bid = 1000;
    auction_items[2].current_bid = 0;
    strcpy(auction_items[2].bidder, "");

    // display the auction items
    printf("Welcome to the Digital Auction System!\n\n");
    printf("Auction Items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s\n", i+1, auction_items[i].name);
    }

    // prompt the user to select an item to bid on
    int item_index;
    printf("\nEnter the number of the item you want to bid on: ");
    scanf("%d", &item_index);
    item_index--;

    // display the selected auction item
    printf("\n%s\n", auction_items[item_index].name);
    display_bid_info(auction_items[item_index]);

    // prompt the user to enter a bid
    int bid_amount;
    char bidder_name[50];
    printf("Enter your name: ");
    scanf("%s", bidder_name);
    printf("Enter your bid: $");
    scanf("%d", &bid_amount);

    // check if the bid meets the minimum bid
    if (bid_amount >= auction_items[item_index].minimum_bid) {
        // check if the bid is higher than the current bid
        if (bid_amount > auction_items[item_index].current_bid) {
            auction_items[item_index].current_bid = bid_amount;
            strcpy(auction_items[item_index].bidder, bidder_name);
            printf("\nCongratulations! You are currently the highest bidder.\n");
            display_bid_info(auction_items[item_index]);
        } else {
            printf("\nSorry, your bid must be higher than the current bid.\n");
            display_bid_info(auction_items[item_index]);
        }
    } else {
        printf("\nSorry, your bid must be at least the minimum bid.\n");
        display_bid_info(auction_items[item_index]);
    }

    return 0;
}