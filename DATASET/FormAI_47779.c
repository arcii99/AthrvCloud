//FormAI DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare constants for the maximum bidding value and number of bidders
#define MAX_BID_VALUE 10000
#define NUM_BIDDERS 5

// Declare an array to hold the bidders' names
char* bidder_names[NUM_BIDDERS] = {"Alice", "Bob", "Charlie", "Dave", "Eve"};

// Declare an array to hold the bids
int bids[NUM_BIDDERS];

// Function to generate random bids for the bidders
void generate_random_bids() {
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = 0; i < NUM_BIDDERS; i++) {
        bids[i] = rand() % MAX_BID_VALUE; // Generate a random bid between 0 and MAX_BID_VALUE
    }
}

// Function to find the highest bid among the bidders
int find_highest_bid() {
    int highest_bid = 0;
    for (int i = 0; i < NUM_BIDDERS; i++) {
        if (bids[i] > highest_bid) {
            highest_bid = bids[i];
        }
    }
    return highest_bid;
}

// Function to find the name of the bidder with the highest bid
char* find_highest_bidder() {
    int highest_bid = find_highest_bid();
    for (int i = 0; i < NUM_BIDDERS; i++) {
        if (bids[i] == highest_bid) {
            return bidder_names[i];
        }
    }
}

// Main function to run the auction
int main() {
    generate_random_bids(); // Generate random bids for the bidders
    
    // Print the bids of the bidders
    printf("Bids:\n");
    for (int i = 0; i < NUM_BIDDERS; i++) {
        printf("%s: %d\n", bidder_names[i], bids[i]);
    }
    
    // Find the highest bidder and print the result
    char* highest_bidder = find_highest_bidder();
    int highest_bid = find_highest_bid();
    printf("%s wins the auction with a bid of %d.\n", highest_bidder, highest_bid);
    
    return 0;
}