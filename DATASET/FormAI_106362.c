//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct item_s {
    char name[32];
    int starting_price;
    int reserve_price;
    int current_bid;
} item_t;

void bid(item_t *item, int amount) {
    if (amount > item->current_bid) {
        printf("New bid of %d for item %s\n", amount, item->name);
        item->current_bid = amount;
    } else {
        printf("Sorry, your bid of %d is too low for item %s\n", amount, item->name);
    }
}

void auction(item_t *item) {
    printf("Auctioning item %s starting at %d\n", item->name, item->starting_price);

    srand(time(NULL));
    int bidder = rand() % 10 + 1;
    int bid_amount = item->starting_price;

    while (bid_amount < item->reserve_price) {
        printf("Bidder %d bids %d for item %s\n", bidder, bid_amount, item->name);
        bid(item, bid_amount);

        bidder = rand() % 10 + 1;
        bid_amount = item->current_bid + rand() % 10 + 1;
    }

    printf("Item %s sold for %d\n", item->name, item->current_bid);
}

int main(void) {
    item_t item1 = {"Antique vase", 100, 200, 0};
    item_t item2 = {"Modern art", 50, 100, 0};

    auction(&item1);
    auction(&item2);

    return 0;
}