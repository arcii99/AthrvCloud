//FormAI DATASET v1.0 Category: Digital Auction System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct auction_item {
    char name[50];
    char description[100];
    int min_bid;
    int curr_bid;
    char curr_bidder[50];
} item;

int main()
{
    item items[10]; // array of 10 auction items

    // Initialize the items with some default values
    strcpy(items[0].name, "Antique Vase");
    strcpy(items[0].description, "A beautiful porcelain vase");
    items[0].min_bid = 100;
    items[0].curr_bid = 0;
    strcpy(items[0].curr_bidder, "");

    strcpy(items[1].name, "Signed Baseball");
    strcpy(items[1].description, "A baseball signed by Babe Ruth");
    items[1].min_bid = 500;
    items[1].curr_bid = 0;
    strcpy(items[1].curr_bidder, "");

    // ... and so on for the other items

    int choice, bid;
    char name[50];
    char c;

    do {
        printf("\n\nAuction System Menu\n");
        printf("--------------------\n");
        printf("1. View current items\n");
        printf("2. Place bid\n");
        printf("3. Quit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nCurrent Items\n");
                printf("--------------\n");
                for (int i = 0; i < 10; i++) {
                    printf("%d. %s\n", i+1, items[i].name);
                }
                break;

            case 2:
                printf("\nEnter item number: ");
                int item_num;
                scanf("%d", &item_num);

                if (item_num < 1 || item_num > 10) {
                    printf("\nInvalid item number. Try again.\n");
                    break;
                }

                item selected_item = items[item_num-1];

                printf("\n%s\n", selected_item.name);
                printf("----------------\n");
                printf("Description: %s\n", selected_item.description);
                printf("Minimum bid: %d\n", selected_item.min_bid);
                printf("Current bid: %d\n", selected_item.curr_bid);

                if (selected_item.curr_bid == 0) {
                    printf("No bids yet.\n");
                } else {
                    printf("Current bidder: %s\n", selected_item.curr_bidder);
                }

                printf("\nEnter your name: ");
                scanf("%s", name);

                printf("Enter your bid: ");
                scanf("%d", &bid);

                if (bid <= selected_item.curr_bid) {
                    printf("\nYour bid must be higher than the current bid.\n");
                    break;
                }

                selected_item.curr_bid = bid;
                strcpy(selected_item.curr_bidder, name);
                items[item_num-1] = selected_item;

                printf("\nBid accepted! %s is now the highest bidder with a bid of %d.\n", name, bid);
                break;

            case 3:
                printf("\nQuitting program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }

        printf("\nPress enter to continue...");
        scanf("%c", &c);
    } while (choice != 3);

    return 0;
}