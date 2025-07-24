//FormAI DATASET v1.0 Category: Digital Auction System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// define some constants
#define MAX_BIDS 10
#define MAX_NAME_LEN 20
#define MAX_ITEM_NAME_LEN 50

// define the Bid struct
typedef struct {
    char bidder_name[MAX_NAME_LEN];
    float bid_amount;
} Bid;

// define the Item struct
typedef struct {
    char item_name[MAX_ITEM_NAME_LEN];
    char description[100];
    float starting_price;
    Bid bids[MAX_BIDS];
    int num_bids;
} Item;

// function to print out the bids on an item
void print_bids(Item item) {
    printf("Bids on item: %s\n", item.item_name);
    for (int i = 0; i < item.num_bids; i++) {
        printf("%s bid $%.2f\n", item.bids[i].bidder_name, item.bids[i].bid_amount);
    }
}

int main() {
    Item item;
    item.starting_price = 10.0;
    item.num_bids = 0;

    // set the item name and description
    strcpy(item.item_name, "Rusty old toaster");
    strcpy(item.description, "This is a classic piece of kitchen equipment, perfect for making toast or just sitting on a shelf as a conversation starter.");

    // print out the item details
    printf("Item: %s\n", item.item_name);
    printf("Description: %s\n", item.description);
    printf("Starting price: $%.2f\n", item.starting_price);

    // ask for bids
    while (1) {
        float new_bid;
        char bidder_name[MAX_NAME_LEN];

        printf("Enter your name: ");
        fgets(bidder_name, MAX_NAME_LEN, stdin);

        printf("Enter your bid: $");
        scanf("%f", &new_bid);
        getchar(); // get rid of the extra newline character

        // check if the bid is higher than the previous ones
        if (new_bid <= item.starting_price) {
            printf("Sorry %s, your bid is too low. The current highest bid is $%.2f\n", bidder_name, item.starting_price);
        }
        else if (item.num_bids >= MAX_BIDS) {
            printf("Sorry %s, too many bids on this item already. Cannot accept any more.\n", bidder_name);
        }
        else {
            // add the bid to the bids array
            Bid new_bid_struct;
            strcpy(new_bid_struct.bidder_name, bidder_name);
            new_bid_struct.bid_amount = new_bid;

            item.bids[item.num_bids] = new_bid_struct;
            item.num_bids++;

            // update the current highest bid
            item.starting_price = new_bid;

            printf("Congratulations %s, your bid of $%.2f is currently the highest one!\n", bidder_name, new_bid);

            // option to exit bidding system
            char exit_choice;
            printf("Would you like to exit the bidding system? (y/n): ");
            scanf("%c", &exit_choice);

            if (exit_choice == 'y') {
                break;
            }
        }
    }

    // print out the bids again
    print_bids(item);

    printf("Thanks for bidding on our digital auction system!");
    return 0;
}