//FormAI DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>

struct item {
    char name[50];
    char description[255];
    float price;
};

struct bid {
    char buyer_name[50];
    float bid_amount;
};

int main() {
    struct item auction_item;
    struct bid highest_bid = { "None", 0.0 };

    // Input the item details
    printf("Enter the name of the item: ");
    scanf("%s", auction_item.name);

    printf("Enter the description of the item: ");
    scanf("%s", auction_item.description);

    printf("Enter the starting price of the item: ");
    scanf("%f", &auction_item.price);

    // Bid process
    while (1) {
        struct bid new_bid;
        printf("Enter your name: ");
        scanf("%s", new_bid.buyer_name);

        printf("Enter your bid amount: ");
        scanf("%f", &new_bid.bid_amount);

        if (new_bid.bid_amount <= highest_bid.bid_amount) {
            printf("Your bid must be higher than the current highest bid of %.2f\n", highest_bid.bid_amount);
        } else {
            highest_bid = new_bid;
            printf("Your bid of %.2f is now the highest bid!\n", new_bid.bid_amount);
        }
    }
    return 0;
}