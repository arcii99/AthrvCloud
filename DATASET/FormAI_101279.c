//FormAI DATASET v1.0 Category: Digital Auction System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 20    // Maximum number of bids per item
#define MAX_ITEMS 5    // Maximum number of items in the auction

typedef struct {
    char name[50];     // Name of the item being auctioned
    int highest_bid;   // Highest bid so far
    char bidder[50];   // Name of the highest bidder
    int num_bids;      // Number of bids for this item
    int bids[MAX_BIDS]; // Array of bids
    char bidders[MAX_BIDS][50]; // Array of bidder names
} auction_item;

auction_item items[MAX_ITEMS]; // Array of auction items
int num_items = 0;             // Number of items currently in the auction

void add_item(char *name, int starting_bid) {
    auction_item item;
    strcpy(item.name, name);
    item.highest_bid = starting_bid;
    strcpy(item.bidder, "");
    item.num_bids = 0;
    num_items++;
    items[num_items - 1] = item;
}

void display_auction() {
    printf("Items currently being auctioned:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - Highest bid: $%d", i + 1, items[i].name, items[i].highest_bid);
        if (strcmp(items[i].bidder, "") != 0) {
            printf(" (Bid by %s)", items[i].bidder);
        }
        printf("\n");
    }
}

void place_bid(int item_num, char *bidder_name, int bid_amount) {
    if (item_num < 1 || item_num > num_items) {
        printf("Invalid item number.\n");
        return;
    }
    if (bid_amount <= items[item_num - 1].highest_bid) {
        printf("Bid amount must be higher than the current highest bid.\n");
        return;
    }
    if (items[item_num - 1].num_bids == MAX_BIDS) {
        printf("Maximum number of bids for this item has been reached.\n");
        return;
    }
    items[item_num - 1].highest_bid = bid_amount;
    strcpy(items[item_num - 1].bidder, bidder_name);
    items[item_num - 1].bids[items[item_num - 1].num_bids] = bid_amount;
    strcpy(items[item_num - 1].bidders[items[item_num - 1].num_bids], bidder_name);
    items[item_num - 1].num_bids++;
    printf("Bid placed successfully.\n");
}

void display_item_bids(int item_num) {
    if (item_num < 1 || item_num > num_items) {
        printf("Invalid item number.\n");
        return;
    }
    printf("Bids for item %d (%s):\n", item_num, items[item_num - 1].name);
    for (int i = 0; i < items[item_num - 1].num_bids; i++) {
        printf("%s - $%d\n", items[item_num - 1].bidders[i], items[item_num - 1].bids[i]);
    }
}

int main() {
    printf("Welcome to the Digital Auction System!\n");
    printf("-------------------------------------\n");
    printf("Select an option:\n");
    printf("1. Add auction item\n");
    printf("2. Display auction items\n");
    printf("3. Place bid on item\n");
    printf("4. Display bids for item\n");
    printf("5. Quit\n");
    int choice = 0;
    while (choice != 5) {
        printf("Enter choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name of item: ");
                char item_name[50];
                scanf("%s", item_name);
                printf("Enter starting bid: $");
                int starting_bid;
                scanf("%d", &starting_bid);
                add_item(item_name, starting_bid);
                printf("Item added successfully.\n");
                break;
            case 2:
                display_auction();
                break;
            case 3:
                printf("Enter item number: ");
                int item_num;
                scanf("%d", &item_num);
                printf("Enter bidder name: ");
                char bidder_name[50];
                scanf("%s", bidder_name);
                printf("Enter bid amount: $");
                int bid_amount;
                scanf("%d", &bid_amount);
                place_bid(item_num, bidder_name, bid_amount);
                break;
            case 4:
                printf("Enter item number: ");
                int item_num2;
                scanf("%d", &item_num2);
                display_item_bids(item_num2);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}