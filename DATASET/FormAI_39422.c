//FormAI DATASET v1.0 Category: Digital Auction System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_BIDDERS 10

int item_count = 0;

typedef struct {
    char title[50];
    char description[100];
    float starting_bid;
    int highest_bidder_id;
    float highest_bid;
} Item;

Item items[MAX_ITEMS];

typedef struct {
    char name[20];
    float balance;
    int item_bids[MAX_ITEMS];
    float item_bid_amounts[MAX_ITEMS];
} Bidder;

Bidder bidders[MAX_BIDDERS];
int bidder_count = 0;

void add_item(char *title, char *description, float starting_bid) {
    strcpy(items[item_count].title, title);
    strcpy(items[item_count].description, description);
    items[item_count].starting_bid = starting_bid;
    items[item_count].highest_bidder_id = -1;
    items[item_count].highest_bid = starting_bid;
    item_count++;
}

void add_bidder(char *name, float balance) {
    strcpy(bidders[bidder_count].name, name);
    bidders[bidder_count].balance = balance;
    memset(bidders[bidder_count].item_bids, -1, sizeof(bidders[bidder_count].item_bids));
    memset(bidders[bidder_count].item_bid_amounts, 0, sizeof(bidders[bidder_count].item_bid_amounts));
    bidder_count++;
}

void show_items() {
    printf("Items:\n");
    for (int i = 0; i < item_count; i++) {
        printf("%d. Title: %s\n", i+1, items[i].title);
        printf("   Description: %s\n", items[i].description);
        printf("   Starting Bid: $%.2f\n", items[i].starting_bid);
        if (items[i].highest_bidder_id != -1) {
            printf("   Highest Bidder: %s\n", bidders[items[i].highest_bidder_id].name);
            printf("   Highest Bid: $%.2f\n", items[i].highest_bid);
        } else {
            printf("   No bids yet\n");
        }
    }
}

void show_bidders() {
    printf("Bidders:\n");
    for (int i = 0; i < bidder_count; i++) {
        printf("%d. Name: %s\n", i+1, bidders[i].name);
        printf("   Balance: $%.2f\n", bidders[i].balance);
        printf("   Item Bids: ");
        for (int j = 0; j < item_count; j++) {
            if (bidders[i].item_bids[j] != -1) {
                printf("%d: $%.2f, ", j+1, bidders[i].item_bid_amounts[j]);
            }
        }
        printf("\n");
    }
}

void place_bid(int bidder_id, int item_id, float bid_amount) {
    Item *item = &items[item_id-1];
    Bidder *bidder = &bidders[bidder_id-1];
    if (bid_amount > item->highest_bid && bid_amount <= bidder->balance) {
        bidder->balance -= bid_amount;
        if (item->highest_bidder_id != -1) {
            bidders[item->highest_bidder_id].balance += item->highest_bid;
        }
        item->highest_bid = bid_amount;
        item->highest_bidder_id = bidder_id-1;
        bidder->item_bids[item_id-1] = item_id-1;
        bidder->item_bid_amounts[item_id-1] = bid_amount;
        printf("Bid accepted!\n");
    } else if (bid_amount <= item->highest_bid) {
        printf("Your bid must be higher than the current highest bid.\n");
    } else if (bid_amount > bidder->balance) {
        printf("You do not have enough money to place that bid.\n");
    }
}

int main() {
    add_item("Antique Chair", "A beautiful antique chair made in the late 1800s.", 1000);
    add_item("Signed Baseball", "A baseball signed by Babe Ruth.", 5000);
    add_item("Original Picasso Painting", "A rare original painting by Picasso.", 100000);
    add_bidder("John", 50000);
    add_bidder("Mary", 100000);
    while (1) {
        printf("Welcome to the Digital Auction System!\n");
        printf("1. View Items\n");
        printf("2. View Bidders\n");
        printf("3. Place Bid\n");
        printf("4. Quit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                show_items();
                break;
            case 2:
                show_bidders();
                break;
            case 3:
                printf("Enter your bidder ID (1 - %d): ", bidder_count);
                int bidder_id;
                scanf("%d", &bidder_id);
                printf("Enter the item ID you wish to bid on (1 - %d): ", item_count);
                int item_id;
                scanf("%d", &item_id);
                printf("Enter your bid amount: ");
                float bid_amount;
                scanf("%f", &bid_amount);
                place_bid(bidder_id, item_id, bid_amount);
                break;
            case 4:
                printf("Thank you for using the Digital Auction System!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}