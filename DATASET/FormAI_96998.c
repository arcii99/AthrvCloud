//FormAI DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    int id;
    char name[30];
    int price;
} Item;

Item items[MAX_ITEMS];
int total_items = 0;

// Function to add item to auction system
void add_item(int id, char name[], int price) {
    if (total_items >= MAX_ITEMS) {
        printf("Error: Auction system is full. No more items can be added.\n");
        return;
    }

    items[total_items].id = id;
    strcpy(items[total_items].name, name);
    items[total_items].price = price;
    total_items++;

    printf("Item %d with name \"%s\" added to auction system with starting price of $%d.\n", id, name, price);
}

// Function to display all items in the auction system
void display_items() {
    if (total_items == 0) {
        printf("No items found in auction system. Please add items.\n");
        return;
    }

    printf("All items in auction system:\n");
    for (int i = 0; i < total_items; i++) {
        printf("Item %d: %s ($%d)\n", items[i].id, items[i].name, items[i].price);
    }
}

// Function to bid on an item
void place_bid(int item_id, int bid_amount) {
    for (int i = 0; i < total_items; i++) {
        if (items[i].id == item_id) {
            if (bid_amount <= items[i].price) {
                printf("Error: Bid amount should be greater than current price of $%d.\n", items[i].price);
                return;
            }

            items[i].price = bid_amount;
            printf("Congratulations! You are now the highest bidder for \"%s\" with a bid of $%d.\n", items[i].name, bid_amount);
            return;
        }
    }

    printf("Error: Item with id %d not found in the auction system.\n", item_id);
}

int main() {
    // Add initial items to auction system
    add_item(1, "Washing machine", 100);
    add_item(2, "Smartphone", 200);
    add_item(3, "Television", 300);

    // Display all items in auction system
    display_items();

    // Place a bid on an item
    place_bid(2, 250);

    // Display all items in auction system after bid
    display_items();

    return 0;
}