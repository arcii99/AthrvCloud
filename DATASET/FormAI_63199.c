//FormAI DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_BIDDERS 20

typedef struct {
    char name[50];
    int current_bid;
    int time_left;
} Product;

typedef struct {
    char name[50];
    int bid_amount;
    int active_product;
} Bidder;

int main() {
    Product products[MAX_PRODUCTS];
    Bidder bidders[MAX_BIDDERS];
    int num_products = 0, num_bidders = 0, current_time = 0;

    // Add products
    strcpy(products[num_products].name, "iPhone X");
    products[num_products].current_bid = 0;
    products[num_products].time_left = 60;
    num_products++;

    strcpy(products[num_products].name, "Samsung Galaxy S9");
    products[num_products].current_bid = 0;
    products[num_products].time_left = 45;
    num_products++;

    // Add bidders
    strcpy(bidders[num_bidders].name, "John Smith");
    bidders[num_bidders].bid_amount = 0;
    bidders[num_bidders].active_product = -1;
    num_bidders++;

    strcpy(bidders[num_bidders].name, "Jane Doe");
    bidders[num_bidders].bid_amount = 0;
    bidders[num_bidders].active_product = -1;
    num_bidders++;

    // Auction loop
    while (1) {
        printf("Current time: %d\n", current_time);

        // Check if all products have been sold
        int all_products_sold = 1;
        for (int i = 0; i < num_products; i++) {
            if (products[i].time_left > 0) {
                all_products_sold = 0;
                break;
            }
        }
        if (all_products_sold) {
            printf("All products have been sold!\n");
            break;
        }

        // Print products and their info
        printf("Products available:\n");
        for (int i = 0; i < num_products; i++) {
            if (products[i].time_left > 0) {
                printf("%d. %s - Current bid: %d - Time left: %d seconds\n", i+1, products[i].name, products[i].current_bid, products[i].time_left);
            }
        }

        // Print bidders and their info
        printf("Bidders:\n");
        for (int i = 0; i < num_bidders; i++) {
            printf("%d. %s - Bid amount: %d - Active product: %d\n", i+1, bidders[i].name, bidders[i].bid_amount, bidders[i].active_product+1);
        }

        // Let bidders place bids
        for (int i = 0; i < num_bidders; i++) {
            printf("%s, enter your bid for a product (-1 to skip): ", bidders[i].name);
            int bid;
            scanf("%d", &bid);

            if (bid == -1) {
                continue;
            }

            printf("Which product do you want to bid on (-1 to skip)? ");
            int product;
            scanf("%d", &product);

            if (product == -1) {
                continue;
            }

            if (bid <= bidders[i].bid_amount || bid <= products[product-1].current_bid || products[product-1].time_left <= 0) {
                printf("Invalid bid!\n");
                continue;
            }

            // Update product and bidder info
            products[product-1].current_bid = bid;
            bidders[i].bid_amount = bid;
            bidders[i].active_product = product-1;
        }

        // Decrease time left for all products
        for (int i = 0; i < num_products; i++) {
            if (products[i].time_left > 0) {
                products[i].time_left--;
            }
        }

        current_time++;
    }

    return 0;
}