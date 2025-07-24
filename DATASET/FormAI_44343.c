//FormAI DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct auction_item {
    char name[50];
    char description[200];
    int current_bid;
    int minimum_bid;
    char seller[50];
    char highest_bidder[50];
    int number_of_bids;
};

void add_item(struct auction_item* items, int* num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*num_items].name);

    printf("Enter a brief description of the item: ");
    scanf("%s", items[*num_items].description);

    printf("Enter the minimum bid amount: ");
    scanf("%d", &items[*num_items].minimum_bid);

    printf("Enter the seller's name: ");
    scanf("%s", items[*num_items].seller);

    items[*num_items].current_bid = 0;
    strcpy(items[*num_items].highest_bidder, "");
    items[*num_items].number_of_bids = 0;

    printf("\nItem added successfully!\n");
    (*num_items)++;
}

void display_items(struct auction_item* items, int num_items) {
    printf("Current Items up for bid:\n");

    for (int i = 0; i < num_items; i++) {
        printf("\nItem %d\n", i+1);
        printf("Name: %s\n", items[i].name);
        printf("Description: %s\n", items[i].description);
        printf("Minimum bid: %d\n", items[i].minimum_bid);
        if (items[i].current_bid > 0) {
            printf("Current bid: %d (by %s)\n", items[i].current_bid, items[i].highest_bidder);
        }
        printf("Seller: %s\n", items[i].seller);
    }
}

void place_bid(struct auction_item* items, int num_items) {
    int choice;
    int item_choice;

    printf("Which item do you want to bid on?");
    scanf("%d", &item_choice);
    item_choice--;

    printf("Enter your bid amount: $");
    scanf("%d", &choice);

    if (choice <= items[item_choice].current_bid) {
        printf("Sorry, your bid is too low.\n");
    } else if (choice < items[item_choice].minimum_bid) {
        printf("Sorry, your bid does not meet the minimum bid amount.\n");
    } else {
        items[item_choice].current_bid = choice;
        strcpy(items[item_choice].highest_bidder, "You");
        items[item_choice].number_of_bids++;
        printf("Your bid was successfully placed!\n");
    }
}

void show_help() {
    printf("\n====================================\n");
    printf("Welcome to the Digital Auction System\n");
    printf("====================================\n");
    printf("\nHere are the available commands:\n");
    printf("1. View current items up for bid\n");
    printf("2. Add an item to the auction\n");
    printf("3. Place a bid\n");
    printf("4. Help (displays this menu)\n");
    printf("5. Exit\n");
};

int main() {
    int choice;
    int num_items = 0;
    struct auction_item items[100];

    show_help();

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_items(items, num_items);
                break;
            case 2:
                add_item(items, &num_items);
                break;
            case 3:
                place_bid(items, num_items);
                break;
            case 4:
                show_help();
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
}