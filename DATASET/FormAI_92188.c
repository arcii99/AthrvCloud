//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold auction information
typedef struct {
    char item_name[50];
    char highest_bidder[50];
    int starting_price;
    int current_bid;
} Auction;

// Array to hold all the auctions
Auction auctions[10];

// Function to add a new auction to the array
void add_auction(int idx) {
    // Prompt user for auction information
    printf("Enter item name for auction #%d: ", idx+1);
    fgets(auctions[idx].item_name, 50, stdin);
    // Remove newline character from input
    auctions[idx].item_name[strcspn(auctions[idx].item_name, "\n")] = 0;
    printf("Enter starting price for auction #%d: ", idx+1);
    scanf("%d", &auctions[idx].starting_price);
    getchar(); // Remove newline character from input
    // Initialize other fields to empty or zero
    strcpy(auctions[idx].highest_bidder, "");
    auctions[idx].current_bid = 0;
    printf("Auction #%d added successfully.\n", idx+1);
}

// Function to display all the auctions in the array
void display_auctions() {
    printf("---- Current Auctions ----\n");
    for (int i = 0; i < 10; i++) {
        if (strlen(auctions[i].item_name) > 0) {
            printf("Auction #%d\n", i+1);
            printf("Item Name: %s\n", auctions[i].item_name);
            printf("Starting Price: %d\n", auctions[i].starting_price);
            printf("Current Bid: %d\n", auctions[i].current_bid);
            printf("Highest Bidder: %s\n\n", auctions[i].highest_bidder);
        }
    }
}

// Function to place a bid on an auction
void place_bid(int idx, int bid_amount, char *bidder_name) {
    // Check if bid amount is greater than current bid and starting price
    if (bid_amount > auctions[idx].current_bid && bid_amount > auctions[idx].starting_price) {
        auctions[idx].current_bid = bid_amount;
        strcpy(auctions[idx].highest_bidder, bidder_name);
        printf("Bid placed successfully.\n");
    }
    else {
        printf("Sorry, your bid amount is less than the current bid or starting price.\n");
    }
}

int main() {
    // Initialize all auctions to empty
    for (int i = 0; i < 10; i++) {
        strcpy(auctions[i].item_name, "");
    }

    int choice, auction_idx, bid_amount;
    char bidder_name[50];

    while(1) {
        // Display menu options
        printf("\n---- Digital Auction System ----\n");
        printf("1. Add new auction\n");
        printf("2. Display all auctions\n");
        printf("3. Place bid on auction\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Remove newline character from input

        switch(choice) {
            case 1:
                // Find an empty slot in the array to add the new auction
                for (int i = 0; i < 10; i++) {
                    if (strlen(auctions[i].item_name) == 0) {
                        add_auction(i);
                        break;
                    }
                    // Display error message if array is full
                    if (i == 9) {
                        printf("Sorry, maximum number of auctions reached.\n");
                    }
                }
                break;

            case 2:
                display_auctions();
                break;

            case 3:
                // Prompt user for auction index, bidder name, and bid amount
                printf("Enter auction index to place bid: ");
                scanf("%d", &auction_idx);
                getchar(); // Remove newline character from input
                printf("Enter bidder name: ");
                fgets(bidder_name, 50, stdin);
                bidder_name[strcspn(bidder_name, "\n")] = 0;
                printf("Enter bid amount: ");
                scanf("%d", &bid_amount);
                place_bid(auction_idx-1, bid_amount, bidder_name);
                break;

            case 4:
                // Exit program
                printf("Thank you for using the Digital Auction System. Goodbye!\n");
                exit(0);
                break;

            // Display error message if user enters an invalid choice
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}