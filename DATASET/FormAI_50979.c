//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_BID_VALUE 1000
#define AUCTION_TIME 60 // Auction time in seconds
#define MAX_BIDDERS 50
#define MAX_NAME_LENGTH 20

// Global variables
char highestBidder[MAX_NAME_LENGTH];
int highestBid = 0;
int totalBids = 0;

// Function prototypes
void handleBid(char *bidderName, int bidValue);
void printBidStats();

int main() {
    printf("Welcome to Digital Auction System\n");
    printf("Auction time: %d seconds\n", AUCTION_TIME);
    printf("Maximum bid value: $%d\n", MAX_BID_VALUE);
    printf("Maximum number of bidders: %d\n", MAX_BIDDERS);
    printf("Please enter your name to start bidding: ");
    
    char bidderName[MAX_NAME_LENGTH];
    fgets(bidderName, MAX_NAME_LENGTH, stdin);
    strtok(bidderName, "\n"); // remove newline character

    printf("Hello %s!\n", bidderName);
    printf("The current highest bid is $%d by %s\n", highestBid, highestBidder);
    printf("Please enter your bid. Type 'quit' to exit.\n");

    // Start bidding loop
    int bidValue = 0;
    char input[MAX_NAME_LENGTH];
    int timeLeft = AUCTION_TIME;
    while (timeLeft > 0) {
        printf("Time left: %d seconds\n", timeLeft);

        // Get user input
        fgets(input, MAX_NAME_LENGTH, stdin);
        strtok(input, "\n"); // remove newline character

        if (strcmp(input, "quit") == 0) {
            break; // exit loop
        }

        // Convert input to integer
        bidValue = atoi(input);

        if (bidValue <= 0 || bidValue > MAX_BID_VALUE) {
            printf("Invalid bid value. Please try again.\n");
            continue;
        }

        handleBid(bidderName, bidValue);
        printBidStats();

        // Wait 1 second
        sleep(1);
        timeLeft--;
    }

    printf("Auction ended! Thank you for your bids.\n");
    return 0;
}

void handleBid(char *bidderName, int bidValue) {
    if (bidValue > highestBid) {
        strcpy(highestBidder, bidderName);
        highestBid = bidValue;
        totalBids++;
        printf("Congratulations! Your bid of $%d is the new highest bid.\n", bidValue);
    } else {
        printf("Sorry, your bid of $%d is not high enough.\n", bidValue);
    }
}

void printBidStats() {
    printf("---------------------------\n");
    printf("Current highest bid: $%d by %s\n", highestBid, highestBidder);
    printf("Total number of bids: %d\n", totalBids);
    printf("---------------------------\n");
}