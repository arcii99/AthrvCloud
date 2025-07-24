//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

/* Structure for an Auction Item */
struct auction_item {
    int id;
    char name[50];
    int starting_bid;
    int current_bid;
    char highest_bidder[50];
};

/* Function to Initialize Auction Items */
void initialize_items(struct auction_item items[], int num_items) {
    int i;
    for(i=0; i<num_items; i++) {
        items[i].id = i+1;
        sprintf(items[i].name, "Item %d", i+1);
        items[i].starting_bid = rand() % 100 + 1; /* Random starting bid between 1 and 100 */
        items[i].current_bid = items[i].starting_bid;
        sprintf(items[i].highest_bidder, "None");
    }
}

/* Function to Display Auction Items */
void display_items(struct auction_item items[], int num_items) {
    int i;
    printf("\nAuction Items:\n");
    printf("ID\tName\tStarting Bid\tCurrent Bid\tHighest Bidder\n");
    for(i=0; i<num_items; i++) {
        printf("%d\t%s\t\t$%d\t\t$%d\t\t%s\n", items[i].id, items[i].name, items[i].starting_bid, items[i].current_bid, items[i].highest_bidder);
    }
    printf("\n");
}

/* Function to Place Bid */
void place_bid(struct auction_item items[], int item_id, char bidder_name[50], int bid_amount) {
    if(bid_amount > items[item_id-1].current_bid) {
        items[item_id-1].current_bid = bid_amount;
        sprintf(items[item_id-1].highest_bidder, bidder_name);
        printf("%s has placed a bid of $%d on %s.\n", bidder_name, bid_amount, items[item_id-1].name);
    }
    else {
        printf("Bid amount is not greater than current bid for %s.\n", items[item_id-1].name);
    }
}

/* Main Function */
int main() {
    int num_items = 5;
    struct auction_item items[num_items];
    initialize_items(items, num_items);
    display_items(items, num_items);
    place_bid(items, 1, "John", 50);
    place_bid(items, 2, "Sarah", 75);
    place_bid(items, 3, "Mike", 100);
    place_bid(items, 1, "Bob", 75);
    place_bid(items, 4, "Karen", 50);
    place_bid(items, 5, "Mark", 150);
    display_items(items, num_items);
    return 0;
}