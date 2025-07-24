//FormAI DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Item struct to hold information about each item being auctioned
typedef struct item {
    char name[50];
    char description[200];
    double min_bid;
    double current_bid;
    char highest_bidder[50];
    char seller[50];
    int id;
} Item;

// Bid struct to hold information about each bid made by a user
typedef struct bid {
    char bidder[50];
    double amount;
    int item_id;
} Bid;

// Array of items being auctioned
Item items[10];

// Array of bids made by users
Bid bids[100];
int num_bids = 0;

// Function to display the menu of options for the user
void display_menu() {
    printf("\n\nWelcome to the Digital Auction System!\n\n");
    printf("1. View all items being auctioned\n");
    printf("2. View details of a specific item\n");
    printf("3. Place a bid on an item\n");
    printf("4. View all bids made\n");
    printf("5. Exit\n");
}

// Function to add an item to the array of items being auctioned
void add_item(char name[], char description[], double min_bid, char seller[]) {
    Item item;
    strcpy(item.name, name);
    strcpy(item.description, description);
    item.min_bid = min_bid;
    item.current_bid = min_bid;
    strcpy(item.highest_bidder, "");
    strcpy(item.seller, seller);
    item.id = rand() % 1000;
    items[item.id] = item;
    printf("\nItem added successfully!\n");
}

// Function to display all the items being auctioned
void view_all_items() {
    printf("\n\nItems being auctioned:\n\n");
    for (int i = 0; i < 10; i++) {
        Item item = items[i];
        printf("%d. %s - Current Bid: $%.2f - Highest Bidder: %s\n", item.id, item.name, item.current_bid, item.highest_bidder);
    }
}

// Function to display the details of a specific item
void view_item_details(int item_id) {
    Item item = items[item_id];
    printf("\n\n%s - Current Bid: $%.2f - Highest Bidder: %s\n\n", item.name, item.current_bid, item.highest_bidder);
    printf("Description: %s\n", item.description);
    printf("Minimum Bid: $%.2f\n", item.min_bid);
}

// Function to place a bid on an item
void place_bid(int item_id, char bidder[], double amount) {
    Item item = items[item_id];
    if (amount <= item.current_bid) {
        printf("\nYour bid must be greater than the current bid of $%.2f\n", item.current_bid);
        return;
    }
    item.current_bid = amount;
    strcpy(item.highest_bidder, bidder);
    items[item_id] = item;
    Bid bid;
    strcpy(bid.bidder, bidder);
    bid.amount = amount;
    bid.item_id = item_id;
    bids[num_bids] = bid;
    num_bids++;
    printf("\nBid placed successfully!\n");
}

// Function to display all the bids made
void view_all_bids() {
    printf("\n\nAll bids made:\n\n");
    for (int i = 0; i < num_bids; i++) {
        Bid bid = bids[i];
        Item item = items[bid.item_id];
        printf("%s bid $%.2f on %s\n", bid.bidder, bid.amount, item.name);
    }
}

int main() {
    srand(time(NULL));
    
    // Add some items to the auction system
    add_item("Macbook Pro", "Brand new Macbook Pro, still in the box", 1000.00, "John");
    add_item("iPhone X", "Gently used iPhone X, in excellent condition", 500.00, "Jane");
    add_item("Nintendo Switch", "Barely used Nintendo Switch, comes with 2 games", 250.00, "Bob");
    
    int choice;
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                view_all_items();
                break;
            case 2:
                printf("\nEnter the id of the item you want to view: ");
                int item_id;
                scanf("%d", &item_id);
                view_item_details(item_id);
                break;
            case 3:
                printf("\nEnter the id of the item you want to bid on: ");
                int bid_id;
                scanf("%d", &bid_id);
                printf("Enter your name: ");
                char bidder[50];
                scanf("%s", bidder);
                printf("Enter your bid amount: ");
                double amount;
                scanf("%lf", &amount);
                place_bid(bid_id, bidder, amount);
                break;
            case 4:
                view_all_bids();
                break;
            case 5:
                printf("\nThank you for using the Digital Auction System!\n\n");
                break;
            default:
                printf("\nInvalid choice, please try again!\n");
        }
    } while (choice != 5);
    
    return 0;
}