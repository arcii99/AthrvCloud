//FormAI DATASET v1.0 Category: Digital Auction System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 50
#define MAX_NAME_LENGTH 20

struct Bid {
    char name[MAX_NAME_LENGTH];
    int amount;
};

struct Auction {
    int currentBid;
    struct Bid bids[MAX_BIDS];
    int numBids;
};

void placeBid(struct Auction *auction, char *name, int amount) {
    if (amount > auction->currentBid) {
        struct Bid newBid = { .amount = amount };
        strncpy(newBid.name, name, MAX_NAME_LENGTH - 1);
        auction->bids[auction->numBids++] = newBid;
        auction->currentBid = amount;
        printf("%s placed a bid for $%d\n", name, amount);
    } else {
        printf("Bid of $%d is too low\n", amount);
    }
}

void printBids(struct Auction *auction) {
    printf("Bids:\n");
    for (int i = 0; i < auction->numBids; i++) {
        struct Bid bid = auction->bids[i];
        printf("%s: $%d\n", bid.name, bid.amount);
    }
}

int main() {
    srand(time(NULL));
    struct Auction auction = { .currentBid = 0, .numBids = 0 };

    printf("Welcome to the digital auction!\n");
    printf("Current item: Antique vase\n");

    while (1) {
        printf("Current bid: $%d\n", auction.currentBid);

        // simulate a new bid
        if (rand() % 2 == 0) {
            char *names[] = { "Alice", "Bob", "Charlie", "Dave", "Emily" };
            int numNames = sizeof(names) / sizeof(names[0]);
            char *name = names[rand() % numNames];
            int amount = auction.currentBid + (rand() % 100);
            printf("%s placed a bid for $%d\n", name, amount);
            placeBid(&auction, name, amount);
            printBids(&auction);
        }

        // check if auction is over
        if (rand() % 10 == 0 && auction.numBids > 0) {
            struct Bid winner = auction.bids[rand() % auction.numBids];
            printf("Auction over! %s won with a bid of $%d\n", winner.name, winner.amount);
            break;
        }

        // wait
        int seconds = 1 + rand() % 4;
        printf("Pausing for %d seconds...\n", seconds);
        sleep(seconds);
    }

    return 0;
}