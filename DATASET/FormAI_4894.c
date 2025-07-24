//FormAI DATASET v1.0 Category: Digital Auction System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 5

typedef struct Auction_Item {
    int item_id;
    char item_description[50];
    double starting_bid;
    double current_bid;
    int current_bidder_id;
    int bids_count;
} Auction_Item;

typedef struct Bidder {
    int bidder_id;
    char bidder_name[20];
    double balance;
    int items_owned[MAX_ITEMS];
    int items_owned_count;
} Bidder;

Bidder bidders[MAX_BIDDERS];
Auction_Item items[MAX_ITEMS];

void initialize() {
    int i;
    // Initialize Bidders
    for (i = 0; i < MAX_BIDDERS; i++) {
        bidders[i].bidder_id = i;
        sprintf(bidders[i].bidder_name, "Bidder %d", i+1);
        bidders[i].balance = 1000.0;
        bidders[i].items_owned_count = 0;
    }
    // Initialize items
    for (i = 0; i < MAX_ITEMS; i++) {
        items[i].item_id = i+1;
        sprintf(items[i].item_description, "Auction Item %d", i+1);
        items[i].starting_bid = (i+1)*10.0;
        items[i].current_bid = items[i].starting_bid;
        items[i].current_bidder_id = -1;
        items[i].bids_count = 0;
    }
}

void print_bidder_info(Bidder b) {
    printf("Bidder ID: %d, Name: %s, Balance: %g\n", b.bidder_id, b.bidder_name, b.balance);
}

void print_item_info(Auction_Item item) {
    printf("Item ID: %d, Description: %s, Starting Bid: %g, Current Bid: %g, Current Bidder ID: %d, Bids Count: %d\n", 
            item.item_id, item.item_description, item.starting_bid, item.current_bid, item.current_bidder_id, item.bids_count);
}

void show_bidders_items() {
    int i, j;
    printf("\nBidders and Their Items:\n");
    for (i = 0; i < MAX_BIDDERS; i++) {
        if (bidders[i].items_owned_count > 0) {
            print_bidder_info(bidders[i]);
            printf("Items Owned: ");
            for (j = 0; j < bidders[i].items_owned_count; j++) {
                printf("%d ", bidders[i].items_owned[j]);                
            }
            printf("\n");
        }
    }
}

void show_auction_items() {
    int i;
    printf("\nCurrent Auction Items:\n");
    for (i = 0; i < MAX_ITEMS; i++) {
        print_item_info(items[i]);
    }
}

void submit_bid(int bidder_id, int item_id, double bid_amount) {
    Bidder *bidder = &bidders[bidder_id];
    Auction_Item *item = &items[item_id];
    if (bid_amount > item->current_bid && bidder->balance >= bid_amount) {
        if (item->current_bidder_id != -1) {
            bidders[item->current_bidder_id].balance += item->current_bid; // refund the previous bidder
        }
        item->current_bid = bid_amount;
        item->current_bidder_id = bidder_id;
        bidder->balance -= bid_amount;
        item->bids_count++;
        bidder->items_owned[bidder->items_owned_count++] = item_id+1;
        printf("\n%s is the highest bidder for %s with bid of %g\n", bidder->bidder_name, item->item_description, item->current_bid);
    } else {
        printf("\nBid Rejected!\n");
    }
}

int main() {
    int bidder_id, item_id;
    double bid_amount;
    initialize();
    show_bidders_items();
    show_auction_items();
    // Simulate a bidding process
    submit_bid(2, 3, 55.0);
    submit_bid(4, 1, 30.0);
    submit_bid(8, 4, 42.0);
    submit_bid(1, 5, 75.0);
    printf("\nAuction Finished!\n");
    show_bidders_items();
    show_auction_items();
    return 0;
}