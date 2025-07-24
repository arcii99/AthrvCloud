//FormAI DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 10

typedef struct Item {
    char name[50];
    float price;
    char bidder[50];
    int is_sold;
} Item;

typedef struct Auction {
    Item items[MAX_ITEMS];
    int num_items;
    char bidders[MAX_BIDDERS][50];
    int num_bidders;
} Auction;

void print_menu();
int get_menu_choice();
void add_item(Auction *auction);
void display_items(Auction *auction);
void add_bid(Auction *auction);
void display_bids(Auction *auction);

int main() {
    Auction auction = {0};
    int choice;

    do {
        print_menu();
        choice = get_menu_choice();

        switch (choice) {
            case 1:
                add_item(&auction);
                break;
            case 2:
                display_items(&auction);
                break;
            case 3:
                add_bid(&auction);
                break;
            case 4:
                display_bids(&auction);
                break;
            case 5:
                printf("Exiting auction system\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void print_menu() {
    printf("Digital Auction System Menu:\n");
    printf("1. Add item to auction\n");
    printf("2. Display items in auction\n");
    printf("3. Add bid for an item\n");
    printf("4. Display bids for an item\n");
    printf("5. Exit auction system\n");
}

int get_menu_choice() {
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void add_item(Auction *auction) {
    if (auction->num_items >= MAX_ITEMS) {
        printf("Auction is full. Cannot add more items.\n");
        return;
    }

    Item new_item;
    printf("Enter name of item: ");
    scanf("%s", new_item.name);
    printf("Enter starting price of item: ");
    scanf("%f", &new_item.price);

    new_item.is_sold = 0;

    auction->items[auction->num_items] = new_item;
    auction->num_items++;

    printf("Item added to auction successfully.\n");
}

void display_items(Auction *auction) {
    printf("Items in auction:\n");
    printf("------------------\n");

    for (int i = 0; i < auction->num_items; i++) {
        printf("%s (%.2f)\n", auction->items[i].name, auction->items[i].price);
    }
}

void add_bid(Auction *auction) {
    char item_name[50];
    int item_index = -1;

    printf("Enter name of item to bid on: ");
    scanf("%s", item_name);

    for (int i = 0; i < auction->num_items; i++) {
        if (strcmp(item_name, auction->items[i].name) == 0) {
            item_index = i;
            break;
        }
    }

    if (item_index == -1) {
        printf("Invalid item name. Please try again.\n");
        return;
    }

    if (auction->items[item_index].is_sold) {
        printf("Item has already been sold. Cannot bid on this item.\n");
        return;
    }

    char bidder_name[50];
    float bid_amount;

    printf("Enter your name: ");
    scanf("%s", bidder_name);

    int bidder_index = -1;
    for (int i = 0; i < auction->num_bidders; i++) {
        if (strcmp(bidder_name, auction->bidders[i]) == 0) {
            bidder_index = i;
            break;
        }
    }

    if (bidder_index == -1) {
        bidder_index = auction->num_bidders;
        strcpy(auction->bidders[bidder_index], bidder_name);
        auction->num_bidders++;
    }

    printf("Enter bid amount: ");
    scanf("%f", &bid_amount);

    if (bid_amount <= auction->items[item_index].price) {
        printf("Bid amount must be greater than current price.\n");
        return;
    }

    auction->items[item_index].price = bid_amount;
    strcpy(auction->items[item_index].bidder, bidder_name);

    printf("Bid added successfully.\n");
}

void display_bids(Auction *auction) {
    char item_name[50];
    int item_index = -1;

    printf("Enter name of item to display bids for: ");
    scanf("%s", item_name);

    for (int i = 0; i < auction->num_items; i++) {
        if (strcmp(item_name, auction->items[i].name) == 0) {
            item_index = i;
            break;
        }
    }

    if (item_index == -1) {
        printf("Invalid item name. Please try again.\n");
        return;
    }

    if (!auction->items[item_index].is_sold) {
        printf("Item has not been sold yet. No bids to display.\n");
        return;
    }

    printf("Bids for %s:\n", item_name);
    printf("--------------\n");

    for (int i = 0; i < auction->num_items; i++) {
        if (strcmp(item_name, auction->items[i].name) == 0) {
            printf("%s: %.2f\n", auction->items[i].bidder, auction->items[i].price);
        }
    }
}