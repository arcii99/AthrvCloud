//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 50
#define MAX_ITEM_NAME 50
#define MAX_BIDDER_NAME 50

typedef struct {
    char name[MAX_ITEM_NAME];
    float highest_bid;
    char highest_bidder[MAX_BIDDER_NAME];
    char status[10];
} AuctionItem;

typedef struct {
    char name[MAX_BIDDER_NAME];
    float bid_amount;
} Bid;

int current_item = 0;
int current_bid = 0;
AuctionItem items[MAX_BIDS];
Bid bids[MAX_BIDS][MAX_BIDS];

void add_item(char *name) {
    AuctionItem item;
    strcpy(item.name, name);
    item.highest_bid = 0;
    strcpy(item.highest_bidder, "");
    strcpy(item.status, "open");
    items[current_item++] = item;
}

void make_bid(char *bidder, float bid, int item_idx) {
    if (item_idx >= current_item || strcmp(items[item_idx].status, "closed") == 0) {
        printf("Invalid item index or item is closed\n");
        return;
    }

    if (bid <= items[item_idx].highest_bid) {
        printf("Bid amount must be higher than the current highest bid\n");
        return;
    }

    Bid new_bid;
    strcpy(new_bid.name, bidder);
    new_bid.bid_amount = bid;
    bids[item_idx][current_bid++] = new_bid;

    items[item_idx].highest_bid = bid;
    strcpy(items[item_idx].highest_bidder, bidder);
    printf("Bid of %.2f made by %s for item %s\n", bid, bidder, items[item_idx].name);
}

void print_items() {
    for (int i = 0; i < current_item; i++) {
        printf("%d. %s - Current highest bid: %.2f by %s - Status: %s\n", i+1, items[i].name, items[i].highest_bid, items[i].highest_bidder, items[i].status);
    }
}

void close_auction() {
    for (int i = 0; i < current_item; i++) {
        if (strcmp(items[i].status, "open") == 0) {
            printf("Auction for item %s closed.\n", items[i].name);
            strcpy(items[i].status, "closed");
        }
    }
}

int main() {
    printf("Welcome to the Digital Auction System\n");

    add_item("Painting");
    add_item("Antique Clock");

    print_items();

    make_bid("John", 150.0, 0);
    make_bid("Mary", 175.0, 0);
    make_bid("Peter", 300.0, 0);
    make_bid("Tim", 250.0, 0);
    make_bid("Samantha", 450.0, 0);

    make_bid("David", 100.0, 1);
    make_bid("Sarah", 200.0, 1);
    make_bid("Josh", 150.0, 1);
    make_bid("Victoria", 250.0, 1);
    make_bid("Mark", 350.0, 1);

    printf("\nCurrent bids:\n");
    for (int i = 0; i < current_item; i++) {
        for (int j = 0; j < MAX_BIDS; j++) {
            if (bids[i][j].bid_amount > 0) {
                printf("%s bid $%.2f for %s\n", bids[i][j].name, bids[i][j].bid_amount, items[i].name);
            }
        }
    }

    close_auction();
    print_items();

    return 0;
}