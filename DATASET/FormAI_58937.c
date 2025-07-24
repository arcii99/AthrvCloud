//FormAI DATASET v1.0 Category: Digital Auction System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BIDS 10    // maximum number of bids allowed
#define AUCTION_ITEM "Smartwatch"   // name of the auction item

struct Bid {
    char name[50];
    double amount;
};

struct Auction {
    char item[50];
    struct Bid bids[MAX_BIDS];
    int num_bids;
};

void init_auction(struct Auction *auction) {
    strcpy(auction->item, AUCTION_ITEM);
    auction->num_bids = 0;
}

void add_bid(struct Auction *auction, char *name, double amount) {
    if (auction->num_bids < MAX_BIDS) {
        struct Bid new_bid = { .amount = amount };
        strcpy(new_bid.name, name);
        auction->bids[auction->num_bids] = new_bid;
        auction->num_bids++;
        printf("%s has placed a bid for $%.2f\n", name, amount);
    } else {
        printf("Sorry, the maximum number of bids has been reached.\n");
    }
}

void display_bids(struct Auction *auction) {
    printf("\nCurrent Bids for %s:\n", auction->item);
    for (int i = 0; i < auction->num_bids; i++) {
        printf("%s: $%.2f\n", auction->bids[i].name, auction->bids[i].amount);
    }
}

int main() {
    struct Auction auction;
    init_auction(&auction);
    int option;

    do {
        printf("\nWelcome to the Simple Digital Auction System!\n");
        printf("Select an option:\n");
        printf("1. Place a bid\n");
        printf("2. Display current bids\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter your name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter bid amount: $");
                double amount;
                scanf("%lf", &amount);
                add_bid(&auction, name, amount);
                break;
            case 2:
                display_bids(&auction);
                break;
            case 3:
                printf("Thanks for using Simple Digital Auction System!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);

    return 0;
}