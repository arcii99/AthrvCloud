//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDS 5

typedef struct {
    char name[50];
    int bid;
} Bidder;

int main() {
    Bidder bidders[MAX_BIDS];
    int num_bidders = 0, current_bid = 0, winner_index = 0;
    char user_input[50];

    printf("Welcome to the Digital Auction System!\n");
    printf("Please enter the number of bidders (maximum %d): ", MAX_BIDS);
    fgets(user_input, sizeof(user_input), stdin);
    num_bidders = atoi(user_input);

    if (num_bidders < 2 || num_bidders > MAX_BIDS) {
        printf("Invalid number of bidders.\n");
        return 1;
    }

    for (int i = 0; i < num_bidders; i++) {
        printf("Enter bidder %d's name: ", i+1);
        fgets(bidders[i].name, sizeof(bidders[i].name), stdin);
        strtok(bidders[i].name, "\n"); // remove newline character
        printf("Enter bidder %d's starting bid (must be at least 1): ", i+1);
        fgets(user_input, sizeof(user_input), stdin);
        bidders[i].bid = atoi(user_input);

        if (bidders[i].bid < 1) {
            printf("Invalid bid.\n");
            return 1;
        }
    }

    srand(time(NULL)); // seed random number generator
    printf("Let the auction begin!\n");

    while (1) {
        printf("Current bid: %d\n", current_bid);
        printf("Enter your bid, or type 'quit' to end the auction: ");
        fgets(user_input, sizeof(user_input), stdin);

        if (strcmp(user_input, "quit\n") == 0) {
            printf("The auction has ended.\n");
            break;
        }

        int new_bid = atoi(user_input);

        if (new_bid <= current_bid) {
            printf("Invalid bid.\n");
            continue;
        }

        int bidder_index = rand() % num_bidders;
        bidders[bidder_index].bid = new_bid;
        current_bid = new_bid;
    }

    for (int i = 0; i < num_bidders; i++) {
        if (bidders[i].bid > bidders[winner_index].bid) {
            winner_index = i;
        }
    }

    printf("The winner is %s with a bid of %d!\n", bidders[winner_index].name, bidders[winner_index].bid);

    return 0;
}