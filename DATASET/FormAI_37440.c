//FormAI DATASET v1.0 Category: Digital Auction System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BIDDERS 10
#define MAX_PRODUCTS 5

typedef struct Product {
    int id;
    char name[50];
    double price;
    int bidders[MAX_BIDDERS];
    int num_bidders;
} Product;

typedef struct Bidder {
    int id;
    char name[50];
    double balance;
    int products[MAX_PRODUCTS];
    int num_products;
} Bidder;

// Initialize products with default values
void init_products(Product products[]) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        products[i].id = i + 1;
        sprintf(products[i].name, "Product %d", i + 1);
        products[i].price = (i + 1) * 10.0;
        products[i].num_bidders = 0;
    }
}

// Initialize bidders with default values
void init_bidders(Bidder bidders[]) {
    for (int i = 0; i < MAX_BIDDERS; i++) {
        bidders[i].id = i + 1;
        sprintf(bidders[i].name, "Bidder %d", i + 1);
        bidders[i].balance = 100.0;
        bidders[i].num_products = 0;
    }
}

// Print product information
void print_product(Product product) {
    printf("Product %d: %s\n", product.id, product.name);
    printf("Price: $%.2f\n", product.price);
    printf("Bidders:");
    for (int i = 0; i < product.num_bidders; i++) {
        printf(" %d", product.bidders[i]);
    }
    printf("\n");
}

// Print bidder information
void print_bidder(Bidder bidder) {
    printf("Bidder %d: %s\n", bidder.id, bidder.name);
    printf("Balance: $%.2f\n", bidder.balance);
    printf("Products:");
    for (int i = 0; i < bidder.num_products; i++) {
        printf(" %d", bidder.products[i]);
    }
    printf("\n");
}

// Check if bidder has already bid on the product
int has_bid_on_product(Bidder bidder, int product_id) {
    for (int i = 0; i < bidder.num_products; i++) {
        if (bidder.products[i] == product_id) {
            return 1;
        }
    }
    return 0;
}

// Get winning bidder for product
Bidder get_winning_bidder(Product product, Bidder bidders[]) {
    Bidder winning_bidder = bidders[product.bidders[0] - 1];
    for (int i = 1; i < product.num_bidders; i++) {
        Bidder bidder = bidders[product.bidders[i] - 1];
        if (bidder.balance > winning_bidder.balance) {
            winning_bidder = bidder;
        }
    }
    return winning_bidder;
}

int main() {
    srand(time(NULL));

    Product products[MAX_PRODUCTS];
    init_products(products);

    Bidder bidders[MAX_BIDDERS];
    init_bidders(bidders);

    // Randomly select a product to auction
    int product_id = rand() % MAX_PRODUCTS;
    Product product = products[product_id];

    printf("*** Welcome to the Digital Auction System! ***\n\n");
    printf("Today we are auctioning:\n\n");

    print_product(product);

    printf("The starting bid is $%.2f.\n\n", product.price);

    int finished = 0;
    while (!finished) {
        // Randomly select a bidder
        int bidder_id = rand() % MAX_BIDDERS;
        Bidder bidder = bidders[bidder_id];

        // Check if bidder has already bid on the product
        if (has_bid_on_product(bidder, product.id)) {
            continue;
        }

        double bid = ((double)rand() / (double)RAND_MAX) * bidder.balance;

        if (bid <= product.price) {
            continue;
        }

        product.price = bid;
        product.bidders[product.num_bidders] = bidder.id;
        product.num_bidders++;

        bidder.products[bidder.num_products] = product.id;
        bidder.num_products++;
        bidder.balance -= bid;

        printf("%s has bid $%.2f on %s!\n\n", bidder.name, bid, product.name);

        // Check if auction is finished
        if (product.num_bidders == MAX_BIDDERS || bidder.balance < product.price) {
            finished = 1;

            printf("Auction finished!\n\n");

            if (product.num_bidders == 0) {
                printf("No one bid on %s.\n\n", product.name);
            } else {
                Bidder winning_bidder = get_winning_bidder(product, bidders);

                printf("%s won the auction for %s with a bid of $%.2f!\n\n", winning_bidder.name, product.name, product.price);
            }

            printf("Final product details:\n\n");
            print_product(product);
            printf("Final bidder details:\n\n");
            for (int i = 0; i < MAX_BIDDERS; i++) {
                print_bidder(bidders[i]);
            }
        }
    }

    return 0;
}