//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for the item being auctioned
struct Item {
    char name[50];
    int current_bid;
    int bid_count;
    char highest_bidder[50];
};

//Function to update the current bid of the item
void update_bid(struct Item *item, int bid, char bidder[]) {
    if (bid > item->current_bid) {
        item->current_bid = bid;
        strcpy(item->highest_bidder, bidder);
        item->bid_count++;
        printf("Bid successfully placed by %s for %d\n", bidder, bid);
    } else {
        printf("Bid should be higher than current bid of %d\n", item->current_bid);
    }
}

int main() {
    //Array of items being auctioned
    struct Item items[5];

    //Initializing each item with a name and initial bid of $10
    strcpy(items[0].name, "Painting");
    items[0].current_bid = 10;
    items[0].bid_count = 0;

    strcpy(items[1].name, "Antique vase");
    items[1].current_bid = 10;
    items[1].bid_count = 0;

    strcpy(items[2].name, "Gold watch");
    items[2].current_bid = 10;
    items[2].bid_count = 0;

    strcpy(items[3].name, "Signed baseball");
    items[3].current_bid = 10;
    items[3].bid_count = 0;

    strcpy(items[4].name, "Rare stamp collection");
    items[4].current_bid = 10;
    items[4].bid_count = 0;

    //Displaying the items being auctioned
    printf("Items being auctioned:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - Current bid: $%d\n", i+1, items[i].name, items[i].current_bid);
    }

    //Starting the auction
    int item_choice, bid;
    char bidder[50];

    while (1) {
        //Asking for item choice and bid amount
        printf("Enter item number to bid on (0 to exit): ");
        scanf("%d", &item_choice);

        if (item_choice == 0) {
            break;
        }

        printf("Enter bid amount: $");
        scanf("%d", &bid);

        printf("Enter bidder name: ");
        scanf("%s", bidder);

        //Making sure the item being bid on exists
        if (item_choice < 1 || item_choice > 5) {
            printf("Invalid item number\n");
            continue;
        }

        //Updating the bid for the selected item
        update_bid(&items[item_choice-1], bid, bidder);
    }

    //Displaying the results of the auction
    printf("Results of auction:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - Highest bid: $%d (by %s), number of bids: %d\n", items[i].name, items[i].current_bid, items[i].highest_bidder, items[i].bid_count);
    }

    return 0;
}