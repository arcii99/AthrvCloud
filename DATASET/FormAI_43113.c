//FormAI DATASET v1.0 Category: Digital Auction System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold bidder information
struct bidder {
    char name[20];
    int bid;
};

// Global variables
struct bidder bidders[5];    // Array to hold bidder information
int num_bidders;             // Number of bidders
int current_bid = 0;         // Current highest bid
int current_bidder = -1;     // Index of current highest bidder in bidders array

// Function to initialize bidder array with empty names and bids
void initialize_bidders() {
    for (int i = 0; i < 5; i++) {
        strcpy(bidders[i].name, "");
        bidders[i].bid = 0;
    }
}

// Function to add a new bidder
void add_bidder(char *name) {
    if (num_bidders < 5) {
        strcpy(bidders[num_bidders].name, name);
        num_bidders++;
    }
    else {
        printf("Sorry, maximum number of bidders reached.\n");
    }
}

// Function to get a random number in a given range
int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate bidding 
void simulate_bidding() {
    // Define bidding parameters
    int num_rounds = 5;
    int min_bid = 100;
    int max_bid = 1000;
    int max_increase = 200;

    printf("--- Starting auction ---\n");

    // Loop through rounds
    for (int round = 1; round <= num_rounds; round++) {
        printf("Round %d\n", round);

        // Loop through bidders
        for (int i = 0; i < num_bidders; i++) {
            // Generate random bid
            int bid = get_random(min_bid, max_bid);
            printf("%s bids %d\n", bidders[i].name, bid);

            // Check if bid is higher than current bid and within allowable increase
            if (bid > current_bid && bid <= current_bid + max_increase) {
                current_bid = bid;
                current_bidder = i;
                printf("%s is the current highest bidder with a bid of %d!\n", bidders[current_bidder].name, current_bid);
            }
        }
    }

    printf("--- Auction ends ---\n");
    printf("%s wins the auction with a bid of %d!\n", bidders[current_bidder].name, current_bid);
}

int main() {
    srand(time(NULL));     // Seed random number generator

    initialize_bidders();

    add_bidder("Alice");
    add_bidder("Bob");
    add_bidder("Charlie");
    add_bidder("Dave");
    add_bidder("Eve");

    simulate_bidding();

    return 0;
}