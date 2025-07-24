//FormAI DATASET v1.0 Category: Digital Auction System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 5

struct bidder {
    char name[30];
    int bid_amount;
};

struct item {
    char name[30];
    int current_bid;
    struct bidder highest_bidder;
};

int main() {
    struct item items[MAX_ITEMS];
    struct bidder bidders[MAX_BIDDERS];

    char input[30];
    int input_number, item_counter = 0, bidder_counter = 0;

    // Welcome message and menu
    printf("Welcome to Digital Auction System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add item for auction\n");
        printf("2. Add bidder\n");
        printf("3. Show items for auction\n");
        printf("4. Start auction\n");
        printf("5. Exit\n\n");
        printf("Please select an option (1-5): ");

        fgets(input, sizeof(input), stdin);
        input_number = atoi(input);

        switch (input_number) {
            case 1:
                // Adding an item
                printf("\nAdding item #%d\n", item_counter+1);
                printf("Item name: ");
                fgets(items[item_counter].name, sizeof(items[item_counter].name), stdin);
                items[item_counter].current_bid = 0;
                item_counter++;
                break;

            case 2:
                // Adding a bidder
                printf("\nAdding bidder #%d\n", bidder_counter+1);
                printf("Bidder name: ");
                fgets(bidders[bidder_counter].name, sizeof(bidders[bidder_counter].name), stdin);
                bidders[bidder_counter].bid_amount = 0;
                bidder_counter++;
                break;

            case 3:
                // Showing items for auction
                printf("\nItems for auction:\n");
                for (int i = 0; i < item_counter; i++) {
                    printf("%d. %s (highest bid: %d by %s)\n", i+1, items[i].name, items[i].current_bid, items[i].highest_bidder.name);
                }
                break;

            case 4:
                // Starting the auction
                printf("\nStarting auction...\n");
                for (int i = 0; i < item_counter; i++) {
                    printf("%d. %s\n", i+1, items[i].name);
                    printf("Enter bid amount: ");
                    fgets(input, sizeof(input), stdin);
                    int bid_amount = atoi(input);

                    // Updating the highest bidder and bid amount for the item
                    for (int j = 0; j < bidder_counter; j++) {
                        if (bidders[j].bid_amount >= bid_amount && bidders[j].bid_amount > items[i].current_bid) {
                            items[i].highest_bidder = bidders[j];
                            items[i].current_bid = bidders[j].bid_amount;
                        }
                    }
                }

                // Showing the winners of each item
                printf("\nAuction is over!\nWinners:\n");
                for (int i = 0; i < item_counter; i++) {
                    printf("%s won %s for %d\n", items[i].highest_bidder.name, items[i].name, items[i].current_bid);
                }
                break;

            case 5:
                // Exiting the program
                printf("\nThank you for using the Digital Auction System!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid option! Please select an option (1-5).\n");
                break;
        }
    }

    return 0;
}