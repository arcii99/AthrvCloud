//FormAI DATASET v1.0 Category: Digital Auction System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char item_name[50];
    int bid_amount;
    char bidder_name[50];
} Item;

int main()
{
    int num_items;
    printf("Welcome to the Digital Auction System!\n");
    printf("How many items are up for auction today?\n");
    scanf("%d", &num_items);

    Item items[num_items];

    for (int i=0; i<num_items; i++) {
        printf("\nEnter the name of item %d:\n", i+1);
        scanf("%s", items[i].item_name);
        printf("Enter the starting bid amount for item %d:\n", i+1);
        scanf("%d", &items[i].bid_amount);
    }

    printf("\nLet the bidding begin!\n");

    for (int i=0; i<num_items; i++) {
        printf("\n%s\nStarting bid: $%d\n", items[i].item_name, items[i].bid_amount);
        printf("Enter your name to place a bid:\n");
        scanf("%s", items[i].bidder_name);

        int bid_amount;
        printf("Enter your bid amount:\n");
        scanf("%d", &bid_amount);

        if (bid_amount <= items[i].bid_amount) {
            printf("Sorry, your bid is not high enough.\n");
        } else {
            strcpy(items[i].bidder_name, items[i].bidder_name);
            items[i].bid_amount = bid_amount;
            printf("Congratulations, you are now the highest bidder for %s with a bid of $%d!\n", items[i].item_name, items[i].bid_amount);
        }
    }

    printf("\nAuction results:\n");
    for (int i=0; i<num_items; i++) {
        printf("\n%s:\n", items[i].item_name);
        printf("Highest bidder: %s\n", items[i].bidder_name);
        printf("Winning bid: $%d\n", items[i].bid_amount);
    }

    return 0;
}