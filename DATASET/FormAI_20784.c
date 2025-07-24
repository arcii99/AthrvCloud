//FormAI DATASET v1.0 Category: Digital Auction System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 1000  // maximum number of auction items
#define MAX_NAME_LEN 50  // maximum length of item name

// define the structure of an auction item
typedef struct {
    int id;  // unique identifier of the item
    char name[MAX_NAME_LEN];  // name of the item
    float starting_price;  // starting price of the item
    float current_price;  // current highest bid for the item
    int bidder_id;  // ID of the current highest bidder, or -1 if there is none
} AuctionItem;

// global variables
AuctionItem items[MAX_ITEMS];  // array of all available auction items
int num_items = 0;  // number of current auction items
int current_bidder_id = 0;  // ID of the current highest bidder

// function to add a new item to the auction
void add_item(char name[], float starting_price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: maximum number of items reached.\n");
        return;
    }

    AuctionItem new_item;
    new_item.id = num_items;
    strcpy(new_item.name, name);
    new_item.starting_price = starting_price;
    new_item.current_price = starting_price;
    new_item.bidder_id = -1;

    items[num_items] = new_item;
    num_items++;

    printf("Item '%s' added to the auction for $%.2f.\n", name, starting_price);
}

// function to display all current auction items and their details
void display_items() {
    printf("Current auction items:\n");

    for (int i = 0; i < num_items; i++) {
        AuctionItem item = items[i];
        printf("%d. '%s' (starting at $%.2f, current bid: $%.2f)\n", item.id, item.name, item.starting_price, item.current_price);
    }
}

// function to submit a bid for an auction item
void submit_bid(int item_id, float bid_amount, int bidder_id) {
    if (item_id < 0 || item_id >= num_items) {
        printf("Error: invalid item ID.\n");
        return;
    }

    AuctionItem item = items[item_id];

    if (bid_amount <= item.current_price) {
        printf("Error: your bid of $%.2f is not higher than the current bid of $%.2f.\n", bid_amount, item.current_price);
        return;
    }

    items[item_id].current_price = bid_amount;
    items[item_id].bidder_id = bidder_id;
    current_bidder_id = bidder_id;

    printf("You are now the highest bidder for item '%s' at $%.2f.\n", item.name, bid_amount);
}

int main() {
    // seed the random number generator with current time
    srand(time(0));

    // add some sample items to the auction
    add_item("Guitar", 100.0);
    add_item("Painting", 500.0);
    add_item("Laptop", 800.0);

    // display the items to the user
    display_items();

    // simulate bidding for the items by generating random bids from multiple bidders
    int num_bidders = 3;  // number of bidders to simulate

    for (int i = 0; i < num_items; i++) {
        AuctionItem item = items[i];
        printf("Bidding for item %d ('%s') has started.\n", item.id, item.name);

        for (int j = 0; j < num_bidders; j++) {
            float bid_amount = item.current_price + rand() % 100;
            int bidder_id = rand() % 1000;

            submit_bid(item.id, bid_amount, bidder_id);
        }

        printf("Bidding for item %d ('%s') has ended.\n", item.id, item.name);
        printf("Current highest bidder is %d.\n", current_bidder_id);
    }

    return 0;
}