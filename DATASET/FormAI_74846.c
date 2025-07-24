//FormAI DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MAX_ITEM_NAME 30
#define MAX_ITEM_DESC 100

struct Item {
    char name[MAX_ITEM_NAME];
    char description[MAX_ITEM_DESC];
    int highest_bid;
    char highest_bidder[20];
    int num_bidders;
    char bidder_names[MAX_BIDDERS][20];
    int bid_amounts[MAX_BIDDERS];
};

int main() {
    int num_items;
    printf("How many items are up for auction? ");
    scanf("%d", &num_items);
    printf("\n");

    struct Item items[num_items];
    for (int i = 0; i < num_items; ++i) {
        printf("Item %d:\n", i + 1);
        printf("What is the name of the item? ");
        scanf("%29s", items[i].name);
        printf("What is the item description? ");
        scanf(" %[^\n]s", items[i].description);
        printf("What is the starting bid? ");
        scanf("%d", &items[i].highest_bid);
        strcpy(items[i].highest_bidder, "");
        items[i].num_bidders = 0;
        printf("\n");
    }

    srand(time(NULL));
    int current_item = rand() % num_items;

    char choice;
    do {
        printf("Welcome to the auction for %s!\n", items[current_item].name);
        printf("%s\n", items[current_item].description);
        printf("The current highest bid is $%d held by %s.\n", items[current_item].highest_bid, items[current_item].highest_bidder);
        printf("Would you like to bid on this item (y/n)? ");
        scanf(" %c", &choice);

        if (choice == 'y') {
            if (items[current_item].num_bidders >= MAX_BIDDERS) {
                printf("Sorry, there are too many bidders for this item.\n");
                continue;
            }

            char name[20];
            printf("What is your name? ");
            scanf("%19s", name);

            int bid;
            printf("What is your bid? ");
            scanf("%d", &bid);

            // Update the highest bid and bidder
            if (bid > items[current_item].highest_bid) {
                items[current_item].highest_bid = bid;
                strcpy(items[current_item].highest_bidder, name);
            }

            // Add the new bidder to the list
            strcpy(items[current_item].bidder_names[items[current_item].num_bidders], name);
            items[current_item].bid_amounts[items[current_item].num_bidders] = bid;
            ++items[current_item].num_bidders;
        }

        // Move on to the next item in the list
        current_item = (current_item + 1) % num_items;
    } while (choice != 'n');

    return 0;
}