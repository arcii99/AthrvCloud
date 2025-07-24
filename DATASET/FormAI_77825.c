//FormAI DATASET v1.0 Category: Digital Auction System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MAX_ITEM_NAME_LENGTH 20

// Struct for auctions
typedef struct Auction {
    char item_name[MAX_ITEM_NAME_LENGTH];
    int highest_bid;
    char highest_bidder[MAX_ITEM_NAME_LENGTH];
    int num_bidders;
    char bidders[MAX_BIDDERS][MAX_ITEM_NAME_LENGTH];
} Auction;

// Helper function to generate a random number between min and max
int random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max + 1 - min)) + min;
}

// Helper function to print out all bidders in an auction
void print_bidders(Auction *auction) {
    printf("Bidders:\n");
    for (int i = 0; i < auction->num_bidders; i++) {
        printf("%s\n", auction->bidders[i]);
    }
    printf("\n");
}

int main() {
    Auction auction;

    strcpy(auction.item_name, "Rare Baseball Card");
    auction.highest_bid = 0;
    strcpy(auction.highest_bidder, "");
    auction.num_bidders = 0;

    printf("Item for Auction: %s\n\n", auction.item_name);

    // Add bidders
    strcpy(auction.bidders[0], "John");
    auction.num_bidders++;
    printf("New Bidder: %s\n", auction.bidders[0]);
    strcpy(auction.bidders[1], "Mary");
    auction.num_bidders++;
    printf("New Bidder: %s\n", auction.bidders[1]);
    strcpy(auction.bidders[2], "Peter");
    auction.num_bidders++;
    printf("New Bidder: %s\n", auction.bidders[2]);

    printf("\n");
    print_bidders(&auction);

    // Auction begins
    printf("Auction begins...\n");

    for (int i = 0; i < 5; i++) {
        printf("\nRound %d\n", i+1);
        for (int j = 0; j < auction.num_bidders; j++) {
            int bid = random_number(auction.highest_bid+1, auction.highest_bid+10);
            printf("%s bids %d\n", auction.bidders[j], bid);

            if (bid > auction.highest_bid) {
                auction.highest_bid = bid;
                strcpy(auction.highest_bidder, auction.bidders[j]);
            }
        }

        printf("\n");
        printf("Current Highest Bid: %d\n", auction.highest_bid);
        printf("Current Highest Bidder: %s\n", auction.highest_bidder);
        printf("\n");
    }

    printf("\nAuction ends!\n");
    printf("Highest Bid: %d\n", auction.highest_bid);
    printf("Highest Bidder: %s\n", auction.highest_bidder);

    return 0;
}