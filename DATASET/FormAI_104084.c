//FormAI DATASET v1.0 Category: Digital Auction System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct auction_item {
    char name[50];
    double starting_price;
    double highest_bid;
    char highest_bidder[50];
} AuctionItem;

int main() {
    int num_items;
    printf("Enter the number of items to auction: ");
    scanf("%d", &num_items);

    AuctionItem *items = (AuctionItem*) malloc(num_items * sizeof(AuctionItem));

    // populate items array
    for (int i = 0; i < num_items; i++) {
        char name[50];
        double starting_price;
        printf("Enter name for item %d: ", i+1);
        scanf("%s", &name);
        printf("Enter starting price for %s: ", name);
        scanf("%lf", &starting_price);

        items[i].starting_price = starting_price;
        items[i].highest_bid = starting_price;
        strcpy(items[i].name, name);
    }

    int current_item = -1; // item not selected yet
    char option = ' ';
    while (option != 'q') {
        printf("\nAuction Menu:\n");
        printf("s - select an item\n");
        printf("b - place bid on selected item\n");
        printf("q - quit program\n");
        printf("Choice: ");
        scanf("%s", &option);

        switch (option) {
            case 's':
                int item_choice;
                printf("\nSelect item:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%d. %s - %.2f\n", i+1, items[i].name, items[i].highest_bid);
                }
                printf("Choice: ");
                scanf("%d", &item_choice);

                if (item_choice < 1 || item_choice > num_items) {
                    printf("\nError: invalid choice\n");
                } else {
                    current_item = item_choice - 1;
                    printf("\nSelected %s\n", items[current_item].name);
                }
                break;
            case 'b':
                if (current_item == -1) {
                    printf("\nError: no item selected\n");
                } else {
                    double bid;
                    printf("\nEnter bid for %s: ", items[current_item].name);
                    scanf("%lf", &bid);
                    if (bid < items[current_item].highest_bid) {
                        printf("\nError: bid must be higher than current highest bid of %.2f\n", items[current_item].highest_bid);
                    } else {
                        items[current_item].highest_bid = bid;
                        printf("\n%s new highest bidder with a bid of %.2f\n", items[current_item].name, bid);
                    }
                }
                break;
            case 'q':
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nError: invalid option\n");
        }
    }

    free(items);

    return 0;
}