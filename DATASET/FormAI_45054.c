//FormAI DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    float price;
    int bidder_id;
    float highest_bid;
};

struct User {
    int id;
    char name[50];
    float balance;
};

int item_count = 0;
struct Item items[50]; // maximum of 50 items in the auction
int user_count = 0;
struct User users[50]; // maximum of 50 users

// Function to print the list of available items in the auction
void print_items() {
    printf("Available items:\n");
    for (int i = 0; i < item_count; i++) {
        printf("%d. %s - $%.2f\n", items[i].id, items[i].name, items[i].price);
    }
    printf("\n");
}

// Function to add an item to the auction
void add_item(char name[50], float price) {
    struct Item item = {
        .id = item_count + 1,
        .price = price,
        .bidder_id = -1,
        .highest_bid = price,
    };
    strcpy(item.name, name);
    items[item_count] = item;
    item_count++;
}

// Function to add a user to the auction
void add_user(char name[50], float balance) {
    struct User user = {
        .id = user_count + 1,
        .balance = balance,
    };
    strcpy(user.name, name);
    users[user_count] = user;
    user_count++;
}

// Function to bid on an item
void bid_item(int item_id, int user_id, float amount) {
    // check if item exists
    if (item_id <= 0 || item_id > item_count) {
        printf("Invalid item id.\n");
        return;
    }
    struct Item item = items[item_id - 1];
    // check if user exists
    if (user_id <= 0 || user_id > user_count) {
        printf("Invalid user id.\n");
        return;
    }
    struct User user = users[user_id - 1];
    // check if user has enough balance
    if (amount > user.balance) {
        printf("Insufficient balance.\n");
        return;
    }
    // check if bid is higher than current highest bid
    if (amount <= item.highest_bid) {
        printf("Bid must be higher than current highest bid.\n");
        return;
    }
    // update highest bid
    item.highest_bid = amount;
    item.bidder_id = user_id;
    printf("Bid successful.\n");
    // update user balance
    user.balance -= amount;
    // update item price
    item.price = amount;
    // update arrays
    items[item_id - 1] = item;
    users[user_id - 1] = user;
}

int main() {
    // Add some items to the auction
    add_item("iPhone", 1000);
    add_item("Macbook", 2000);
    add_item("AirPods", 200);
    // Add some users to the auction
    add_user("John", 5000);
    add_user("Mary", 10000);
    add_user("Bob", 2000);
    // Print the list of available items
    print_items();
    // John bids $1200 on the MacBook
    bid_item(2, 1, 1200);
    // Bob bids $250 on the AirPods (should fail because it's not higher than the current highest bid of $200)
    bid_item(3, 3, 250);
    // Mary bids $2500 on the MacBook
    bid_item(2, 2, 2500);
    // Print the list of available items (should show updated highest bids and prices)
    print_items();
    // Print the list of users (should show updated balances)
    printf("Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("%d. %s - $%.2f\n", users[i].id, users[i].name, users[i].balance);
    }
    return 0;
}