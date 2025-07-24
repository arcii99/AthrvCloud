//FormAI DATASET v1.0 Category: Digital Auction System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing bidding information
struct bid {
    char name[50];
    int amount;
};

// Function to find the highest bidder
int find_highest_bidder(struct bid bids[], int num_bids) {
    int max_bid = 0;
    int max_bid_index = 0;
    for(int i = 0; i < num_bids; i++) {
        if(bids[i].amount > max_bid) {
            max_bid = bids[i].amount;
            max_bid_index = i;
        }
    }
    return max_bid_index;
}

// Main function
int main() {
    int num_bids;
    printf("Enter the number of bids: ");
    scanf("%d", &num_bids);

    struct bid* bids = malloc(num_bids * sizeof(struct bid));

    // Inputting the bids
    for(int i = 0; i < num_bids; i++) {
        printf("Enter the name of bidder %d: ", i+1);
        scanf("%s", bids[i].name);
        printf("Enter the bid amount: ");
        scanf("%d", &bids[i].amount);
    }

    // Finding the highest bidder
    int max_bidder_index = find_highest_bidder(bids, num_bids);

    // Printing the results
    printf("\nThe highest bidder is %s with a bid of %d\n", bids[max_bidder_index].name, bids[max_bidder_index].amount);

    free(bids); // Freeing the memory

    return 0;
}