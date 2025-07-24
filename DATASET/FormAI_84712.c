//FormAI DATASET v1.0 Category: Digital Auction System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bid {
    char bidder[50];
    int amount;
};

int main() {
    int num_bids;
    printf("Welcome to the Digital Auction System!\n\n");
    printf("Enter the number of bids: ");
    scanf("%d", &num_bids);

    struct Bid bids[num_bids];

    for (int i = 0; i < num_bids; i++) {
        printf("\nBid #%d\n", i+1);
        printf("Enter bidder name: ");
        scanf("%s", bids[i].bidder);
        printf("Enter bid amount: ");
        scanf("%d", &bids[i].amount);
    }

    printf("\n\n********** WINNER **********\n");

    int max_bid = 0;
    char winner[50];

    for (int i = 0; i < num_bids; i++) {
        if (bids[i].amount > max_bid) {
            max_bid = bids[i].amount;
            strcpy(winner, bids[i].bidder);
        }
    }

    printf("The winner is %s with a bid of $%d!\n", winner, max_bid);

    return 0;
}