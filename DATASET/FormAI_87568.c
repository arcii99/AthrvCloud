//FormAI DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of auctions and items per auction
#define MAX_AUCTIONS 10
#define MAX_ITEMS 5

// Define struct for item
typedef struct Item {
    char name[50]; // Name of item
    int starting_price; // Starting price of item
    int current_price; // Current bid price of item
    char highest_bidder[50]; // Name of highest bidder
} Item;

// Define struct for auction
typedef struct Auction {
    char name[50]; // Name of auction
    Item items[MAX_ITEMS]; // Array of items in auction
    int num_items; // Number of items in auction
} Auction;

// Define array of auctions
Auction auctions[MAX_AUCTIONS];

// Define functions for adding an item to an auction and making a bid on an item
void add_item(int auction_index, char* name, int starting_price);
void make_bid(int auction_index, int item_index, char* bidder_name, int bid_price);

int main() {
    // Initialize auctions
    for (int i = 0; i < MAX_AUCTIONS; i++) {
        strcpy(auctions[i].name, ""); // Blank name
        auctions[i].num_items = 0; // No items initially
    }

    int choice; // User's choice
    int auction_index, item_index; // Index of auction and item
    char name[50], bidder_name[50]; // Name of item and bidder
    int starting_price, bid_price; // Starting price and bid price

    while (1) {
        // Print menu and get user's choice
        printf("\nDigital Auction System\n");
        printf("1. Create new auction\n");
        printf("2. Add item to auction\n");
        printf("3. Make bid on item\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create new auction
                for (int i = 0; i < MAX_AUCTIONS; i++) {
                    if (strcmp(auctions[i].name, "") == 0) { // Find empty slot in array
                        printf("Enter name of auction: ");
                        scanf("%s", auctions[i].name);
                        auctions[i].num_items = 0; // No items initially
                        break;
                    }
                }
                break;
            case 2:
                // Add item to auction
                printf("Enter name of auction: ");
                scanf("%s", name);
                for (int i = 0; i < MAX_AUCTIONS; i++) {
                    if (strcmp(auctions[i].name, name) == 0) { // Find auction with given name
                        printf("Enter name of item: ");
                        scanf("%s", name);
                        printf("Enter starting price of item: ");
                        scanf("%d", &starting_price);
                        add_item(i, name, starting_price); // Add item to auction
                        break;
                    }
                }
                break;
            case 3:
                // Make bid on item
                printf("Enter name of auction: ");
                scanf("%s", name);
                for (int i = 0; i < MAX_AUCTIONS; i++) {
                    if (strcmp(auctions[i].name, name) == 0) { // Find auction with given name
                        printf("Enter index of item: ");
                        scanf("%d", &item_index);
                        printf("Enter name of bidder: ");
                        scanf("%s", bidder_name);
                        printf("Enter bid price: ");
                        scanf("%d", &bid_price);
                        make_bid(i, item_index, bidder_name, bid_price); // Make bid on item
                        break;
                    }
                }
                break;
            case 4:
                // Quit
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

// Function for adding an item to an auction
void add_item(int auction_index, char* name, int starting_price) {
    if (auctions[auction_index].num_items >= MAX_ITEMS) { // Check if auction is full
        printf("Auction is full.\n");
        return;
    }
    strcpy(auctions[auction_index].items[auctions[auction_index].num_items].name, name);
    auctions[auction_index].items[auctions[auction_index].num_items].starting_price = starting_price;
    auctions[auction_index].items[auctions[auction_index].num_items].current_price = starting_price;
    strcpy(auctions[auction_index].items[auctions[auction_index].num_items].highest_bidder, "");
    auctions[auction_index].num_items++;
    printf("Item added to auction.\n");
}

// Function for making a bid on an item
void make_bid(int auction_index, int item_index, char* bidder_name, int bid_price) {
    if (strcmp(auctions[auction_index].items[item_index].highest_bidder, bidder_name) == 0) { // Check if bidder has already made highest bid
        printf("%s has already made the highest bid on this item.\n", bidder_name);
        return;
    }
    if (bid_price <= auctions[auction_index].items[item_index].current_price) { // Check if bid price is greater than current price
        printf("Bid price must be greater than current price.\n");
        return;
    }
    strcpy(auctions[auction_index].items[item_index].highest_bidder, bidder_name);
    auctions[auction_index].items[item_index].current_price = bid_price;
    printf("Bid made on item.\n");
}