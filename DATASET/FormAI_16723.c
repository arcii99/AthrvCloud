//FormAI DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bid {
    char bidder_name[50];
    float bid_amount;
};

struct Auction_Item {
    char item_name[50];
    float base_price;
    struct Bid highest_bid;
};

int main() {
    int num_items;
    printf("Enter the number of items to be auctioned: ");
    scanf("%d", &num_items);

    struct Auction_Item items[num_items];

    for (int i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].item_name);
        printf("Enter the base price of item %d: ", i+1);
        scanf("%f", &items[i].base_price);
        strcpy(items[i].highest_bid.bidder_name, "None");
        items[i].highest_bid.bid_amount = items[i].base_price;
    }

    int current_item = 0;
    char input[10];
    while (1) {
        printf("Current item up for auction: %s\n", items[current_item].item_name);
        printf("Highest Bid: $%.2f by %s\n", items[current_item].highest_bid.bid_amount, items[current_item].highest_bid.bidder_name);
        printf("Type 'next' to move to next item or 'end' to end auction: ");
        scanf("%s", input);

        if (strcmp(input, "next") == 0) {
            current_item++;
            if (current_item == num_items) {
                printf("Auction ended.\n");
                break;
            }
        }
        else if (strcmp(input, "end") == 0) {
            printf("Auction ended.\n");
            break;
        }
        else {
            float bid_amount;
            char bidder_name[50];
            printf("Enter bidder name: ");
            scanf("%s", bidder_name);
            printf("Enter bid amount: ");
            scanf("%f", &bid_amount);
            if (bid_amount < items[current_item].highest_bid.bid_amount) {
                printf("Bid amount must be higher than current highest bid.\n");
            }
            else {
                items[current_item].highest_bid.bid_amount = bid_amount;
                strcpy(items[current_item].highest_bid.bidder_name, bidder_name);
                printf("Bid accepted.\n");
            }
        }
    }

    return 0;
}