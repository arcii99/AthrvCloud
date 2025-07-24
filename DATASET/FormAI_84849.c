//FormAI DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ITEMS       100
#define MAX_BIDDERS     10
#define NAME_LEN        50

// Define structures
struct item {
    char name[NAME_LEN];
    double current_bid;
    char bidder[NAME_LEN];
    int num_bids;
};

struct bidder {
    char name[NAME_LEN];
    double funds;
    int num_items;
    int item_indices[MAX_ITEMS];
};

// Declare global variables
struct item items[MAX_ITEMS];
struct bidder bidders[MAX_BIDDERS];
int num_items = 0;
int num_bidders = 0;

// Function prototypes
void add_item(char* name, double starting_bid);
void add_bid(char* bidder_name, int item_index, double bid_amount);
void print_items();
void print_bidders();
void simulate_auction();

int main() {
    // Add some initial items to the auction
    add_item("Painting", 1000);
    add_item("Jewelry", 500);
    add_item("Antique vase", 750);

    // Add some initial bidders to the auction
    strcpy(bidders[0].name, "John Smith");
    bidders[0].funds = 5000;
    bidders[0].num_items = 0;

    strcpy(bidders[1].name, "Jane Doe");
    bidders[1].funds = 10000;
    bidders[1].num_items = 0;

    num_bidders = 2;

    // Simulate the auction
    simulate_auction();

    return 0;
}

void add_item(char* name, double starting_bid) {
    if (num_items < MAX_ITEMS) {
        strcpy(items[num_items].name, name);
        items[num_items].current_bid = starting_bid;
        items[num_items].num_bids = 0;
        num_items++;
    }
}

void add_bid(char* bidder_name, int item_index, double bid_amount) {
    // Find the bidder
    int bidder_index = -1;
    for (int i = 0; i < num_bidders; i++) {
        if (strcmp(bidders[i].name, bidder_name) == 0) {
            bidder_index = i;
            break;
        }
    }
    if (bidder_index == -1) {
        printf("Bidder not found!\n");
        return;
    }

    // Find the item
    if (item_index < 0 || item_index >= num_items) {
        printf("Item not found!\n");
        return;
    }

    // Check if bid is higher than current bid
    if (bid_amount <= items[item_index].current_bid) {
        printf("Bid must be higher than current bid!\n");
        return;
    }

    // Check if bidder has enough funds for the bid
    if (bid_amount > bidders[bidder_index].funds) {
        printf("Bidder does not have enough funds!\n");
        return;
    }

    // Update item information
    strcpy(items[item_index].bidder, bidder_name);
    items[item_index].current_bid = bid_amount;
    items[item_index].num_bids++;

    // Update bidder information
    bidders[bidder_index].funds -= bid_amount;
    bidders[bidder_index].num_items++;
    bidders[bidder_index].item_indices[bidders[bidder_index].num_items-1] = item_index;

    printf("Bid accepted!\n");
}

void print_items() {
    printf("Items for auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: %s\n", i+1, items[i].name);
        printf("Current bid: %.2f\n", items[i].current_bid);
        if (items[i].num_bids > 0) {
            printf("Bidder: %s\n", items[i].bidder);
        }
        printf("\n");
    }
}

void print_bidders() {
    printf("Bidders:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("Bidder %d: %s\n", i+1, bidders[i].name);
        printf("Funds: %.2f\n", bidders[i].funds);
        printf("Items won: %d\n", bidders[i].num_items);
        for (int j = 0; j < bidders[i].num_items; j++) {
            printf("%s\n", items[bidders[i].item_indices[j]].name);
        }
        printf("\n");
    }
}

void simulate_auction() {
    int input = 0;
    double bid_amount = 0;
    char bidder_name[NAME_LEN];

    do {
        print_items();

        // Prompt user to select an item to bid on
        printf("Enter item number to bid on (0 to quit): ");
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        input--;

        // Prompt user to enter their name and bid amount
        printf("Enter your name: ");
        scanf("%s", bidder_name);
        printf("Enter your bid amount: ");
        scanf("%lf", &bid_amount);

        // Add the bid
        add_bid(bidder_name, input, bid_amount);
    } while (input != -1);

    // Print final results
    printf("Auction has ended!\n");
    print_items();
    print_bidders();
}