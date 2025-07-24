//FormAI DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 1000
#define MAX_BIDDERS 100

int current_item = 0;
int current_bidder = 0;

struct Item {
    char name[50];
    int highest_bid;
    char highest_bidder[50];
};

struct Bidder {
    char name[50];
    int balance;
};

struct Item items[MAX_ITEMS];
struct Bidder bidders[MAX_BIDDERS];

void add_item(char *name) {
    struct Item item;
    strcpy(item.name, name);
    item.highest_bid = 0;
    strcpy(item.highest_bidder, "-");
    items[current_item] = item;
    current_item++;
}

void add_bidder(char *name, int balance) {
    struct Bidder bidder;
    strcpy(bidder.name, name);
    bidder.balance = balance;
    bidders[current_bidder] = bidder;
    current_bidder++;
}

void print_items() {
    printf("Current Items for auction:\n");
    for(int i = 0; i < current_item; i++) {
        printf("Item %d: %s \t\t Highest Bid: %d \t\t Highest Bidder: %s\n", i+1, items[i].name, items[i].highest_bid, items[i].highest_bidder);
    }
}

void print_bidders() {
    printf("Current Bidders:\n");
    for(int i = 0; i < current_bidder; i++) {
        printf("%d. %s \t\t Balance: %d\n", i+1, bidders[i].name, bidders[i].balance);
    }
}

void make_bid(int item_index, int bidder_index, int amount) {
    if(amount <= bidders[bidder_index].balance) {
        if(amount > items[item_index].highest_bid) {
            items[item_index].highest_bid = amount;
            strcpy(items[item_index].highest_bidder, bidders[bidder_index].name);
            bidders[bidder_index].balance -= amount;
            printf("Bid successful! %s now has the highest bid for %s at %d.\n", bidders[bidder_index].name, items[item_index].name, amount);
        } else {
            printf("Your bid amount is not higher than the current highest bid for this item.\n");
        }
    } else {
        printf("Insufficient balance to make this bid.\n");
    }
}

int main(void) {
    printf("Welcome to the Digital Auction System!\n\n");

    add_item("Smart TV");
    add_item("Nike Shoes");
    add_item("Playstation 5");

    add_bidder("John Doe", 5000);
    add_bidder("Sarah Smith", 7000);
    add_bidder("Mark Johnson", 10000);
    
    int choice = 0;

    while(choice != 4) {
        printf("\nPlease choose an option: \n1. Display Items \n2. Display Bidders \n3. Make Bid \n4. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            print_items();
        } else if(choice == 2) {
            print_bidders();
        } else if(choice == 3) {
            printf("Enter the number of the item you want to bid on: ");
            int item_choice;
            scanf("%d", &item_choice);
            printf("Enter the number of the bidder: ");
            int bidder_choice;
            scanf("%d", &bidder_choice);
            printf("Enter the amount of your bid: ");
            int amount;
            scanf("%d", &amount);
            make_bid(item_choice-1, bidder_choice-1, amount);
        } else if(choice == 4) {
            printf("Thank you for using the Digital Auction System!\n");
        } else {
            printf("Invalid input, please try again.\n");
        }
    }

    return 0;
}