//FormAI DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[20];
    int current_bid;
    int highest_bid;
    char highest_bidder[20];
};

void print_product(struct product* p) {
    printf("Name: %s\nCurrent Bid: %d\nHighest Bid: %d\nHighest Bidder: %s\n\n", p->name, p->current_bid, p->highest_bid, p->highest_bidder);
}

int main() {
    int num_products;
    printf("Enter Number of Products: ");
    scanf("%d", &num_products);
    printf("\n");

    // Allocate memory for products
    struct product* products = malloc(num_products * sizeof(struct product));

    // Initialize products
    for (int i = 0; i < num_products; i++) {
        printf("Enter Product Name: ");
        scanf("%s", products[i].name);
        printf("Enter Starting Bid: ");
        scanf("%d", &(products[i].current_bid));
        products[i].highest_bid = products[i].current_bid;
        strcpy(products[i].highest_bidder, "None");
        printf("\n");
    }

    int auction_running = 1;
    while (auction_running) {
        int choice;
        printf("1. View Products\n2. Make Bid\n3. Quit Auction\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < num_products; i++) {
                    printf("Product %d:\n", i+1);
                    print_product(&products[i]);
                }
                break;
            case 2:
                int product_num, bid_amount;
                printf("Enter Product Number: ");
                scanf("%d", &product_num);
                printf("Enter Bid Amount: ");
                scanf("%d", &bid_amount);

                if (bid_amount > products[product_num-1].highest_bid) {
                    products[product_num-1].highest_bid = bid_amount;
                    printf("Bid accepted for %s at %d!\n", products[product_num-1].name, bid_amount);
                    printf("Enter Bidder Name: ");
                    scanf("%s", products[product_num-1].highest_bidder);
                    printf("\n");
                } else {
                    printf("Bid amount not high enough for %s!\n\n", products[product_num-1].name);
                }
                break;
            case 3:
                auction_running = 0;
                break;
            default:
                printf("Invalid Choice! Choose again.\n");
                break;
        }
    }

    // Free memory
    free(products);

    return 0;
}