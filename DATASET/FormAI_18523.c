//FormAI DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BID 1000

struct item {
    char name[50];
    char description[100];
    int starting_bid;
    int current_bid;
    char bidder_name[50];
};

struct auction {
    char name[50];
    int num_items;
    struct item items[MAX_BID];
};

void display_items(struct auction *auction) {
    printf("Items in auction: %s\n", auction->name);
    for (int i = 0; i < auction->num_items; i++) {
        printf("%d. %s - %s - Starting bid: $%d - Current bid: $%d - Bidder: %s\n", 
            i+1, auction->items[i].name, auction->items[i].description, 
            auction->items[i].starting_bid, auction->items[i].current_bid, auction->items[i].bidder_name);
    }
}

int main() {
    struct auction my_auction;
    strcpy(my_auction.name, "Online Auction");

    int num_items;
    printf("Enter number of items in auction: ");
    scanf("%d", &num_items);
    my_auction.num_items = num_items;

    for (int i = 0; i < num_items; i++) {
        printf("Enter item %d name: ", i+1);
        scanf("%s", my_auction.items[i].name);

        printf("Enter item %d description: ", i+1);
        scanf("%s", my_auction.items[i].description);

        printf("Enter item %d starting bid: ", i+1);
        scanf("%d", &my_auction.items[i].starting_bid);

        my_auction.items[i].current_bid = my_auction.items[i].starting_bid;
        printf("Item %d starting bid set to: $%d\n", i+1, my_auction.items[i].starting_bid);
    }

    display_items(&my_auction);

    int choice = 0;
    while (choice != -1) {
        printf("Enter item number to bid on (-1 to quit): ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= num_items) {
            int bid_amount;
            printf("Enter your bid for item %d: ", choice);
            scanf("%d", &bid_amount);

            if (bid_amount > my_auction.items[choice-1].current_bid) {
                my_auction.items[choice-1].current_bid = bid_amount;
                printf("Bid accepted for $%d on item %d.\n", bid_amount, choice);
                printf("Bidder name: ");
                scanf("%s", my_auction.items[choice-1].bidder_name);

                display_items(&my_auction);
            } else {
                printf("Bid rejected. Your bid must be higher than the current bid of $%d.\n", my_auction.items[choice-1].current_bid);
            }
        }
    }

    return 0;
}