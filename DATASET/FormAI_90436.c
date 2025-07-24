//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_ITEMS 100
#define MAX_ITEM_NAME 50
#define MAX_DESCRIPTION 100
#define MAX_BIDS 50

// Structs
typedef struct user {
    char username[MAX_ITEM_NAME];
    float balance;
} User;

typedef struct bid {
    char username[MAX_ITEM_NAME];
    float amount;
} Bid;

typedef struct auction_item {
    char name[MAX_ITEM_NAME];
    char description[MAX_DESCRIPTION];
    float start_price;
    float current_price;
    User seller;
    Bid bids[MAX_BIDS];
    int num_bids;
    int auction_ended;
} AuctionItem;

// Function Prototypes
void print_auction_item(AuctionItem item);
void print_bid(Bid bid);
void bid_on_item(AuctionItem *item, User *user, float amount);
void end_auction(AuctionItem *item);

// Global Variables 
User users[MAX_USERS];
AuctionItem items[MAX_ITEMS];
int num_users = 0;
int num_items = 0;

// Main Function
int main() {
    // Create Users
    User user1 = {"Sarah", 500};
    User user2 = {"John", 1000};
    users[0] = user1;
    users[1] = user2;
    num_users = 2;

    // Create Auction Item
    AuctionItem item1 = {"Computer", "MacBook Pro, 16GB RAM, 1TB Storage", 1000, 1000, user1, {}, 0, 0};
    items[0] = item1;
    num_items = 1;

    // Print Auction Details
    print_auction_item(item1);

    // User 2 bids on item 1
    bid_on_item(&item1, &user2, 1200);

    // Print updated auction details
    print_auction_item(item1);

    // End Auction
    end_auction(&item1);

    return 0;
}

// Function Definitions
void print_auction_item(AuctionItem item) {
    printf("Item: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Start Price: $%.2f\n", item.start_price);
    printf("Current Price: $%.2f\n", item.current_price);
    printf("Seller: %s\n", item.seller.username);
    printf("Bids:\n");
    for(int i = 0; i < item.num_bids; i++) {
        print_bid(item.bids[i]);
    }
    printf("\n");
}

void print_bid(Bid bid) {
    printf("%s bid $%.2f\n", bid.username, bid.amount);
}

void bid_on_item(AuctionItem *item, User *user, float amount) {
    if(amount > item->current_price && user->balance >= amount) {
        Bid new_bid = {*user->username, amount};
        item->bids[item->num_bids] = new_bid;
        item->num_bids++;
        item->current_price = amount;
    } else {
        printf("Invalid bid amount or balance too low\n");
    }
}

void end_auction(AuctionItem *item) {
    if(item->num_bids > 0) {
        printf("Auction Winner: %s\n", item->bids[item->num_bids - 1].username);
        item->seller.balance += item->current_price;
        User *buyer = NULL;
        for(int i = 0; i < num_users; i++) {
            if(strcmp(item->bids[item->num_bids - 1].username, users[i].username) == 0) {
                buyer = &users[i];
            }
        }
        buyer->balance -= item->current_price;
    }
    item->auction_ended = 1;
}