//FormAI DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Item {
    char name[50];
    char description[100];
    double starting_price;
    double current_bid;
    char current_bidder[50];
};

void print_item(struct Item i);
bool validate_bid(struct Item i, double bid);
void make_bid(struct Item *i, char bidder[50], double bid);

int main() {
    struct Item item;
    strcpy(item.name, "Vintage Rolex watch");
    strcpy(item.description, "This is a rare, vintage Rolex watch made in the 1960s.");
    item.starting_price = 10000.0;
    item.current_bid = 10000.0;
    strcpy(item.current_bidder, "");
    
    printf("Welcome to the digital auction system for %s\n\n", item.name);
    printf("Item description: %s\n", item.description);
    printf("Starting price: %.2f\n\n", item.starting_price);
    
    while (true) {
        printf("Current bid: %.2f\n", item.current_bid);
        if (strcmp(item.current_bidder, "") == 0) {
            printf("No one has bid on this item yet.\n");
        } else {
            printf("Current highest bidder: %s\n", item.current_bidder);
        }
        printf("Enter your name: ");
        char name[50];
        scanf("%s", name);
        printf("Enter your bid: ");
        double bid;
        scanf("%lf", &bid);
        if (validate_bid(item, bid)) {
            printf("Your bid of %.2f has been accepted.\n", bid);
            make_bid(&item, name, bid);
        } else {
            printf("Sorry, your bid of %.2f was not accepted.\n", bid);
        }
        printf("\n");
    }
    
    return 0;
}

void print_item(struct Item i) {
    printf("Name: %s\n", i.name);
    printf("Description: %s\n", i.description);
    printf("Starting price: %.2f\n", i.starting_price);
    printf("Current bid: %.2f\n", i.current_bid);
    printf("Current bidder: %s\n", i.current_bidder);
}

bool validate_bid(struct Item i, double bid) {
    if (bid > i.current_bid) {
        return true;
    } else {
        return false;
    }
}

void make_bid(struct Item *i, char bidder[50], double bid) {
    i->current_bid = bid;
    strcpy(i->current_bidder, bidder);
}