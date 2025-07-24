//FormAI DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the auction structure
typedef struct Auction {
    char itemName[50];
    char itemDescription[100];
    int startingBid;
    int currentBid;
    char bidderName[50];
    char bidderEmail[50];
    int bidderPhone;
    int numberOfBids;
} Auction;

// Define the main function
int main() {
    // Define the variables
    Auction myAuction;
    int choice;
    int biddingAmount;
    int highestBid;
    char bidderName[50], bidderEmail[50];
    int bidderPhone;
    char temp[50];

    // Set the initial values
    strcpy(myAuction.itemName, "Painting");
    strcpy(myAuction.itemDescription, "A beautiful painting by a local artist.");
    myAuction.startingBid = 100;
    myAuction.currentBid = myAuction.startingBid;
    strcpy(myAuction.bidderName, "");
    strcpy(myAuction.bidderEmail, "");
    myAuction.bidderPhone = 0;
    myAuction.numberOfBids = 0;

    // Print a welcome message
    printf("Welcome to the digital auction system!\n");
    printf("The item up for auction is a %s.\n\n", myAuction.itemName);

    // Loop until the user chooses to exit
    while(1) {
        // Print the menu and get the user's choice
        printf("What would you like to do?\n");
        printf("1. View item details\n");
        printf("2. Place a bid\n");
        printf("3. View current bid\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        // Handle the user's choice
        switch(choice) {
            case 1:
                // Print the item details
                printf("Item Name: %s\n", myAuction.itemName);
                printf("Item Description: %s\n", myAuction.itemDescription);
                printf("Starting Bid: $%d\n\n", myAuction.startingBid);
                break;

            case 2:
                // Get the bidding amount from the user
                printf("Enter your bidding amount: ");
                scanf("%d", &biddingAmount);
                printf("\n");

                // Check if the bidding amount is higher than the current bid
                if(biddingAmount > myAuction.currentBid) {
                    // Set the new current bid and update the bidder information
                    myAuction.currentBid = biddingAmount;
                    strcpy(myAuction.bidderName, bidderName);
                    strcpy(myAuction.bidderEmail, bidderEmail);
                    myAuction.bidderPhone = bidderPhone;
                    myAuction.numberOfBids++;

                    // Print a success message
                    printf("Congratulations, your bid of $%d is the current highest bid!\n\n", myAuction.currentBid);
                } else {
                    // Print an error message
                    printf("Sorry, your bid must be higher than the current bid of $%d.\n\n", myAuction.currentBid);
                }
                break;

            case 3:
                // Print the current highest bid
                printf("The current highest bid is $%d.\n\n", myAuction.currentBid);
                break;

            case 4:
                // Print a goodbye message and exit the program
                printf("Thank you for using the digital auction system. Goodbye!\n");
                exit(0);

            default:
                // Print an error message for invalid input
                printf("Invalid choice, please try again.\n\n");
                break;
        }
    }

    return 0;
}