//FormAI DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for auction item
typedef struct AuctionItem {
    int id;             // Unique identifier for the item
    char name[50];      // Name of the item
    float current_price;// Current highest bid for the item
    float starting_price;// Starting price for the item
    char bidder_name[50];// Name of the current highest bidder
    int active;         // Flag indicating if the item is currently up for auction
} AuctionItem;

// Data structure for node in linked list of auction items
typedef struct AuctionListNode {
    AuctionItem *item;              // Pointer to auction item stored in this node
    struct AuctionListNode *next;   // Pointer to the next node in the list
} AuctionListNode;

// Data structure for auction system
typedef struct AuctionSystem {
    int current_item_id;            // Unique ID to assign to next auction item added
    AuctionListNode *items;         // Head of the linked list of auction items
} AuctionSystem;

// Function to create a new auction item with given parameters
AuctionItem *new_auction_item(char *name, float starting_price, int id) {
    AuctionItem *item = (AuctionItem*)malloc(sizeof(AuctionItem));
    item->id = id;
    strcpy(item->name, name);
    item->starting_price = starting_price;
    item->current_price = starting_price;
    strcpy(item->bidder_name, "");
    item->active = 1;
    return item;
}

// Function to add a new auction item to the system
void add_auction_item(AuctionSystem *system, char *name, float starting_price) {
    AuctionItem *item = new_auction_item(name, starting_price, system->current_item_id);
    system->current_item_id++;
    AuctionListNode *new_node = (AuctionListNode*)malloc(sizeof(AuctionListNode));
    new_node->item = item;
    new_node->next = system->items;
    system->items = new_node;
}

// Function to get the node in the linked list of auction items holding the auction item with the given ID
AuctionListNode *get_auction_item_node(AuctionListNode *current_node, int id) {
    if (current_node == NULL) {
        return NULL;
    }
    if (current_node->item->id == id) {
        return current_node;
    }
    return get_auction_item_node(current_node->next, id);
}

// Function to get the auction item with the given ID
AuctionItem *get_auction_item(AuctionSystem *system, int id) {
    AuctionListNode *node = get_auction_item_node(system->items, id);
    if (node != NULL) {
        return node->item;
    }
    return NULL;
}

// Function to place a bid on an auction item
void place_bid(AuctionSystem *system, int id, char *bidder_name, float bid_amount) {
    AuctionItem *item = get_auction_item(system, id);
    if (item != NULL && item->active && bid_amount > item->current_price) {
        strcpy(item->bidder_name, bidder_name);
        item->current_price = bid_amount;
    }
}

// Function to end the auction for a given auction item
void end_auction(AuctionSystem *system, int id) {
    AuctionItem *item = get_auction_item(system, id);
    if (item != NULL) {
        item->active = 0;
        printf("Auction for item %d (%s) has ended. Highest bidder: %s. Final price: $%.2f\n", item->id, item->name, item->bidder_name, item->current_price);
    }
}

int main() {
    AuctionSystem *system = (AuctionSystem*)malloc(sizeof(AuctionSystem));
    system->current_item_id = 1;
    system->items = NULL;

    add_auction_item(system, "Painting", 500.0);
    add_auction_item(system, "Sculpture", 750.0);
    add_auction_item(system, "Jewelry", 1000.0);

    place_bid(system, 2, "Alice", 800.0);
    place_bid(system, 1, "Bob", 600.0);
    place_bid(system, 3, "Charlie", 1500.0);

    end_auction(system, 1);
    end_auction(system, 2);
    end_auction(system, 3);

    // Free memory
    while (system->items != NULL) {
        AuctionListNode *node_to_remove = system->items;
        system->items = system->items->next;
        free(node_to_remove->item);
        free(node_to_remove);
    }
    free(system);

    return 0;
}