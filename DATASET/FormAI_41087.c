//FormAI DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct AuctionItem {
    int id;
    char name[20];
    float highest_bid;
    char highest_bidder[20];
};

struct AuctionItem auction_items[10]; //maximum 10 items for auction
int num_of_items = 0; //number of items for auction

void addAuctionItem(int id, char *name, float highest_bid, char *highest_bidder) {
    auction_items[num_of_items].id = id;
    strcpy(auction_items[num_of_items].name, name);
    auction_items[num_of_items].highest_bid = highest_bid;
    strcpy(auction_items[num_of_items].highest_bidder, highest_bidder);
    num_of_items++;
}

void checkAuctionItems() {
    printf("Current auction items:\n");
    for(int i=0; i<num_of_items; i++) {
        printf("%d - %s: %.2f (Highest bidder: %s)\n", auction_items[i].id, auction_items[i].name,
            auction_items[i].highest_bid, auction_items[i].highest_bidder);
    }
}

void bidOnAuctionItem(int item_id, float bid_amount, char *bidder_name) {
    for(int i=0; i<num_of_items; i++) {
        if(auction_items[i].id == item_id) {
            if(bid_amount > auction_items[i].highest_bid) {
                auction_items[i].highest_bid = bid_amount;
                strcpy(auction_items[i].highest_bidder, bidder_name);
                printf("Congratulations, %s! You are the highest bidder for %s with a bid of %.2f\n",
                    bidder_name, auction_items[i].name, bid_amount);
            } else {
                printf("Sorry, your bid of %.2f is not high enough for %s\n", bid_amount, auction_items[i].name);
            }
            return;
        }
    }
    printf("Invalid item id\n");
}

int main() {
    addAuctionItem(1, "Painting", 100.00, "No one");
    addAuctionItem(2, "Guitar", 50.00, "No one");
    checkAuctionItems();

    bidOnAuctionItem(1, 150.00, "John");
    bidOnAuctionItem(1, 120.00, "Jane");
    bidOnAuctionItem(2, 75.00, "Bob");
    checkAuctionItems();

    return 0;
}