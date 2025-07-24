//FormAI DATASET v1.0 Category: Digital Auction System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_BIDDERS 10
#define MAX_NAME_LENGTH 20

// Data Structures
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH+1];
    double current_bid;
    int bidder_id;
    int is_sold;
} Item;

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH+1];
    double money;
    int num_items_won;
    int item_ids_won[MAX_ITEMS];
} Bidder;

// Global Variables
Item items[MAX_ITEMS];
Bidder bidders[MAX_BIDDERS];
int num_items = 0;
int num_bidders = 0;
int current_bidder_id = -1;

// Helper Functions
void print_item(Item item) {
    printf("Item ID: %d\n", item.id);
    printf("Item Name: %s\n", item.name);
    printf("Current Bid: $%.2f\n", item.current_bid);
    printf("Bidder ID: %d\n", item.bidder_id);
}

void print_bidder(Bidder bidder) {
    printf("Bidder ID: %d\n", bidder.id);
    printf("Bidder Name: %s\n", bidder.name);
    printf("Balance: $%.2f\n", bidder.money);
    printf("Number of items won: %d\n", bidder.num_items_won);
}

void print_all_items() {
    printf("----- All Items -----\n");
    for(int i=0; i<num_items; i++) {
        printf("Item %d:\n", i+1);
        print_item(items[i]);
    }
}

void print_all_bidders() {
    printf("----- All Bidders -----\n");
    for(int i=0; i<num_bidders; i++) {
        printf("Bidder %d:\n", i+1);
        print_bidder(bidders[i]);
    }
}

void add_item(char* name, double starting_bid) {
    items[num_items].id = num_items+1;
    strcpy(items[num_items].name, name);
    items[num_items].current_bid = starting_bid;
    items[num_items].bidder_id = -1;
    items[num_items].is_sold = 0;
    num_items++;
}

void add_bidder(char* name, double starting_balance) {
    bidders[num_bidders].id = num_bidders+1;
    strcpy(bidders[num_bidders].name, name);
    bidders[num_bidders].money = starting_balance;
    bidders[num_bidders].num_items_won = 0;
    num_bidders++;
}

int find_item_by_id(int item_id) {
    for(int i=0; i<num_items; i++) {
        if(items[i].id == item_id) {
            return i;
        }
    }
    return -1;
}

int find_bidder_by_id(int bidder_id) {
    for(int i=0; i<num_bidders; i++) {
        if(bidders[i].id == bidder_id) {
            return i;
        }
    }
    return -1;
}

void place_bid(int item_id, double bid_amount, int bidder_id) {
    int item_index = find_item_by_id(item_id);
    if(item_index == -1) {
        printf("Error: Item not found with id %d\n", item_id);
        return;
    }

    int bidder_index = find_bidder_by_id(bidder_id);
    if(bidder_index == -1) {
        printf("Error: Bidder not found with id %d\n", bidder_id);
        return;
    }

    if(bidders[bidder_index].money < bid_amount) {
        printf("Error: Bidder does not have enough money to place bid.\n");
        return;
    }

    if(current_bidder_id == -1 || current_bidder_id == bidder_id) {
        items[item_index].current_bid = bid_amount;
        items[item_index].bidder_id = bidder_id;
        current_bidder_id = bidder_id;
        printf("Bid placed.\n");
    } else {
        printf("Error: Only the current highest bidder can increase their bid.\n");
    }
}

void end_auction(int item_id) {
    int item_index = find_item_by_id(item_id);
    if(item_index == -1) {
        printf("Error: Item not found with id %d\n", item_id);
        return;
    }

    if(items[item_index].is_sold) {
        printf("Error: Item has already been sold.\n");
        return;
    }

    int bidder_index = find_bidder_by_id(items[item_index].bidder_id);

    if(bidder_index == -1) {
        printf("Error: Bidder not found with id %d\n", items[item_index].bidder_id);
        return;
    } else {
        bidders[bidder_index].money -= items[item_index].current_bid;
        bidders[bidder_index].item_ids_won[bidders[bidder_index].num_items_won] = item_id;
        bidders[bidder_index].num_items_won++;
        printf("Item sold to %s for $%.2f\n", bidders[bidder_index].name, items[item_index].current_bid);
        items[item_index].is_sold = 1;
        current_bidder_id = -1;
    }
}

// Main Function
int main() {
    printf("Welcome to the Digital Auction System!\n");

    // Add Items
    add_item("Painting", 1000.0);
    add_item("Antique Vase", 500.0);
    add_item("Rare Book", 750.0);

    // Add Bidders
    add_bidder("John", 10000.0);
    add_bidder("Sarah", 5000.0);

    // Place Bids
    place_bid(1, 1100.0, 2);
    place_bid(1, 1150.0, 2);
    place_bid(1, 1200.0, 1);
    place_bid(1, 1300.0, 2);

    place_bid(2, 600.0, 1);
    place_bid(2, 700.0, 2);
    place_bid(2, 750.0, 1);
    end_auction(2);

    place_bid(3, 800.0, 1);
    place_bid(3, 900.0, 2);
    place_bid(3, 950.0, 1);
    end_auction(3);

    // Print Results
    print_all_items();
    print_all_bidders();

    return 0;
}