//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for auction item
typedef struct {
    char name[50];
    int startingPrice;
    int currentPrice;
    char highestBidder[50];
} AuctionItem;

// Define function to display auction items
void displayAuctionItems(int numItems, AuctionItem items[]) {
    printf("\n---Current Auction Items---\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s || Current Price: %d || Highest Bidder: %s\n", i+1, items[i].name, items[i].currentPrice, items[i].highestBidder);
    }
}

int main() {

    // Declare variables
    int numItems, selection, bidAmount;
    char bidderName[50];
    AuctionItem items[10];
    
    printf("Welcome to the Digital Auction System!\n");

    // Initialize auction items
    strcpy(items[0].name, "Antique Pocketwatch");
    items[0].startingPrice = 100;
    items[0].currentPrice = 100;
    strcpy(items[1].name, "Oil Painting of a Countryside");
    items[1].startingPrice = 200;
    items[1].currentPrice = 200;
    strcpy(items[2].name, "Rare Edition of Sherlock Holmes Books");
    items[2].startingPrice = 300;
    items[2].currentPrice = 300;
    numItems = 3;

    // Display initial items
    displayAuctionItems(numItems, items);

    // Enter main bidding loop
    while (1) {
        printf("\nEnter the number of the item you would like to bid on (0 to quit): ");
        scanf("%d", &selection);

        // Check for exit condition
        if (selection == 0) {
            printf("Thank you for using the Digital Auction System. Goodbye!\n");
            break;
        }

        // Check for invalid selection
        if (selection < 1 || selection > numItems) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        // Get bid amount and bidder name
        printf("Enter your bid amount: ");
        scanf("%d", &bidAmount);
        printf("Enter your name: ");
        scanf("%s", bidderName);

        // Check bid against current price
        if (bidAmount <= items[selection-1].currentPrice) {
            printf("Your bid is not higher than the current price. Please try again with a higher bid.\n");
            continue;
        }

        // Update current price and highest bidder
        items[selection-1].currentPrice = bidAmount;
        strcpy(items[selection-1].highestBidder, bidderName);

        // Display updated items
        printf("Congratulations, %s! You are now the highest bidder for %s with a bid of %d.\n", bidderName, items[selection-1].name, bidAmount);
        displayAuctionItems(numItems, items);
    }

    return 0;
}