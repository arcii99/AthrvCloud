//FormAI DATASET v1.0 Category: Digital Auction System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define NUM_ITEMS 5 // number of items up for auction
#define MAX_BIDS 3 // maximum number of bids per item
#define MAX_BIDDERS 10 // maximum number of bidders per item
#define STARTING_PRICE 100 // starting price for each item

struct bid {
    int bidder_id;
    float bid_amount;
};

struct item {
    int item_id;
    char item_name[50];
    float current_price;
    struct bid bids[MAX_BIDS];
    int num_bids;
    int num_bidders;
};

struct auction {
    struct item items[NUM_ITEMS];
};

void initialize_auction(struct auction *auction);
void display_items(struct auction *auction);
void place_bid(struct auction *auction, int item_id, int bidder_id, float bid_amount);
void display_bids(struct item item);
void display_bid_history(struct auction auction);

int main() {
    struct auction auction;
    initialize_auction(&auction);
    int choice;
    do {
        printf("\n1. Display Items\n");
        printf("2. Place Bid\n");
        printf("3. Display Bid History\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_items(&auction);
                break;
            case 2:
                printf("\nEnter Item ID: ");
                int item_id;
                scanf("%d", &item_id);
                printf("Enter Bidder ID: ");
                int bidder_id;
                scanf("%d", &bidder_id);
                printf("Enter Bid Amount: ");
                float bid_amount;
                scanf("%f", &bid_amount);
                place_bid(&auction, item_id, bidder_id, bid_amount);
                break;
            case 3:
                display_bid_history(auction);
                break;
            case 4:
                printf("Exiting Auction System...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}

void initialize_auction(struct auction *auction) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        auction->items[i].item_id = i + 1;
        sprintf(auction->items[i].item_name, "Item %d", i + 1);
        auction->items[i].current_price = STARTING_PRICE;
        auction->items[i].num_bids = 0;
        auction->items[i].num_bidders = 0;
    }
}

void display_items(struct auction *auction) {
    printf("\nList of Items in Auction\n");
    printf("----------------------------\n");
    printf("Item ID\tItem Name\tCurrent Price\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%d\t%s\t%.2f\n", auction->items[i].item_id, auction->items[i].item_name, auction->items[i].current_price);
    }
}

void place_bid(struct auction *auction, int item_id, int bidder_id, float bid_amount) {
    if (item_id < 1 || item_id > NUM_ITEMS) {
        printf("Invalid Item ID!\n");
        return;
    }
    int item_index = item_id - 1;
    if (auction->items[item_index].num_bidders >= MAX_BIDDERS) {
        printf("Maximum number of bidders reached for this item!\n");
        return;
    }
    if (auction->items[item_index].num_bids >= MAX_BIDS) {
        printf("Maximum number of bids reached for this item!\n");
        return;
    }
    if (auction->items[item_index].bids[auction->items[item_index].num_bids].bidder_id == bidder_id) {
         printf("Bidder has already placed a bid for this item!\n");
         return;
    }
    if (bid_amount <= auction->items[item_index].current_price) {
        printf("Bid amount should be greater than current price of the item!\n");
        return;
    }
    auction->items[item_index].bids[auction->items[item_index].num_bids].bidder_id = bidder_id;
    auction->items[item_index].bids[auction->items[item_index].num_bids].bid_amount = bid_amount;
    auction->items[item_index].num_bids++;
    auction->items[item_index].num_bidders++;
    auction->items[item_index].current_price = bid_amount;
    printf("Bid placed successfully!\n");
}

void display_bids(struct item item) {
    printf("\nItem %d: %s\n", item.item_id, item.item_name);
    printf("-----------------------------------------------------\n");
    printf("Bidder ID\tBid Amount\n");
    for (int i = 0; i < item.num_bids; i++) {
        printf("%d\t\t%.2f\n", item.bids[i].bidder_id, item.bids[i].bid_amount);
    }
}

void display_bid_history(struct auction auction) {
    printf("\nBid History\n");
    printf("----------------------------\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        display_bids(auction.items[i]);
    }
}