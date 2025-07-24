//FormAI DATASET v1.0 Category: Digital Auction System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char item_name[50];
    int item_id;
    float starting_bid;
    int seller_id;
    int bidder_id;
    float current_bid;
} Item;

Item items[100];
int num_items = 0;

typedef struct {
    char username[20];
    int user_id;
    float balance;
} User;

User users[100];
int num_users = 0;

void add_user(char name[20], float balance) {
    User new_user;
    strcpy(new_user.username, name);
    new_user.user_id = num_users;
    new_user.balance = balance;
    users[num_users] = new_user;
    num_users++;
}

void add_item(char name[50], int seller_id, float starting_bid) {
    Item new_item;
    strcpy(new_item.item_name, name);
    new_item.item_id = num_items;
    new_item.seller_id = seller_id;
    new_item.bidder_id = -1;
    new_item.starting_bid = starting_bid;
    new_item.current_bid = starting_bid;
    items[num_items] = new_item;
    num_items++;
}

void bid(int user_id, int item_id, float new_bid) {
    Item item = items[item_id];
    if (item.bidder_id == -1) {
        item.bidder_id = user_id;
        item.current_bid = new_bid;
        printf("Item %d has been bid on by user %d for %.2f\n", item_id, user_id, new_bid);
    } else if (new_bid > item.current_bid) {
        User old_bidder = users[item.bidder_id];
        old_bidder.balance += item.current_bid;
        users[item.bidder_id] = old_bidder;
        item.bidder_id = user_id;
        item.current_bid = new_bid;
        printf("Item %d has been bid on by user %d for %.2f\n", item_id, user_id, new_bid);
    } else {
        printf("Bid must be higher than current bid of %.2f\n", item.current_bid);
    }
}

int main() {
    add_user("John", 100.00);
    add_user("Sarah", 200.00);
    add_user("Mike", 50.00);

    add_item("Baseball", 0, 5.00);
    add_item("Football", 1, 10.00);
    add_item("Basketball", 2, 7.50);

    bid(1, 0, 6.00);
    bid(2, 0, 7.00);
    bid(0, 0, 8.00);
    bid(2, 1, 11.00);

    return 0;
}