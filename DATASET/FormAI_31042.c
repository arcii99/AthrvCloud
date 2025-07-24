//FormAI DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define USERNAME_LENGTH 20
#define ITEM_NAME_LENGTH 50
#define MAX_ITEMS 10
#define MIN_AUCTION_TIME 5

// Structures
typedef struct User {
    char username[USERNAME_LENGTH];
    float balance;
} User;

typedef struct Item {
    char name[ITEM_NAME_LENGTH];
    float price;
    time_t auctionEndTime;
    User* highestBidder; // NULL if no bids have been placed
} Item;

// Function prototypes
void createUser(User* user, char* username, float balance);
void createItem(Item* item, char* name, float price, int auctionDuration);
void displayItem(Item* item);
void auctionItem(Item* item, User* bidder, float bidAmount);
void processAuctions(Item items[], int numItems);
void printUsers(User users[], int numUsers);

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create some example users
    User alice, bob;
    createUser(&alice, "alice", 1000.0);
    createUser(&bob, "bob", 500.0);

    // Create some example items
    Item items[MAX_ITEMS];
    createItem(&items[0], "Antique Watch", 500.0, 15);
    createItem(&items[1], "Baseball Card Collection", 1000.0, 10);
    createItem(&items[2], "Signed Football", 750.0, 20);

    // Auction off the items
    processAuctions(items, 3);

    // Print out the final balances of the users
    printf("Final balances:\n");
    User users[] = {alice, bob};
    printUsers(users, 2);

    return 0;
}

void createUser(User* user, char* username, float balance) {
    strncpy(user->username, username, USERNAME_LENGTH);
    user->balance = balance;
}

void createItem(Item* item, char* name, float price, int auctionDuration) {
    strncpy(item->name, name, ITEM_NAME_LENGTH);
    item->price = price;
    item->auctionEndTime = time(NULL) + auctionDuration;
    item->highestBidder = NULL;
}

void displayItem(Item* item) {
    printf("%s\n", item->name);
    printf("Price: $%.2f\n", item->price);
    printf("Auction Ends: %s", ctime(&item->auctionEndTime));
    if (item->highestBidder != NULL) {
        printf("Highest Bid: $%.2f by %s\n", item->price, item->highestBidder->username);
    } else {
        printf("No bids yet.\n");
    }
}

void auctionItem(Item* item, User* bidder, float bidAmount) {
    if (bidAmount > item->price) {
        item->price = bidAmount;
        item->highestBidder = bidder;
        printf("%s is now the highest bidder with a bid of $%.2f\n", bidder->username, bidAmount);
    } else {
        printf("Bid must be higher than the current price of $%.2f\n", item->price);
    }
}

void processAuctions(Item items[], int numItems) {
    int numBids;
    float bidAmount;
    User* bidder;

    while (1) {
        // Display all the items and ask the user which one to bid on
        printf("Choose an item to bid on:\n");
        for (int i = 0; i < numItems; i++) {
            printf("%d. %s\n", i+1, items[i].name);
        }
        printf("%d. Quit\n", numItems+1);
        int choice;
        scanf("%d", &choice);

        if (choice == numItems+1) {
            break; // User chose to quit
        }

        Item* item = &items[choice-1];

        // Check if the auction for this item has ended
        if (time(NULL) >= item->auctionEndTime) {
            printf("Auction has ended for %s\n", item->name);
            continue;
        }

        // Check if the user has enough balance to bid on this item
        printf("Your Balance: $%.2f\n", bidder->balance);
        printf("Enter your bid: ");
        scanf("%f", &bidAmount);
        if (bidAmount > bidder->balance) {
            printf("You don't have enough balance\n");
            continue;
        }

        auctionItem(item, bidder, bidAmount);
    }
}

void printUsers(User users[], int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        printf("%s: $%.2f\n", users[i].username, users[i].balance);
    }
}