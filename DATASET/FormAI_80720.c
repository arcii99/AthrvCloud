//FormAI DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MAX_BIDS 100 // maximum number of bids
#define MAX_LEN 50 // maximum length of bidder name
#define MAX_PRODUCTS 5 // maximum number of products
#define START_PRICE 100 // starting price of each product
#define INCREMENT 10 // minimum increment in bids

typedef struct Bid {
    int amount;
    char name[MAX_LEN];
} Bid;

typedef struct Product {
    int id;
    char name[MAX_LEN];
    int current_price;
    Bid bids[MAX_BIDS];
    int num_bids;
} Product;

Product products[MAX_PRODUCTS];
int num_products;

void initialize_products() {
    num_products = 0;

    Product p;

    // add products
    p.id = 1;
    strcpy(p.name, "iPhone X");
    p.current_price = START_PRICE;
    p.num_bids = 0;
    products[num_products++] = p;

    p.id = 2;
    strcpy(p.name, "Samsung Galaxy S9");
    p.current_price = START_PRICE;
    p.num_bids = 0;
    products[num_products++] = p;

    p.id = 3;
    strcpy(p.name, "Google Pixel 2");
    p.current_price = START_PRICE;
    p.num_bids = 0;
    products[num_products++] = p;

    p.id = 4;
    strcpy(p.name, "MacBook Pro");
    p.current_price = START_PRICE;
    p.num_bids = 0;
    products[num_products++] = p;

    p.id = 5;
    strcpy(p.name, "Dell XPS 13");
    p.current_price = START_PRICE;
    p.num_bids = 0;
    products[num_products++] = p;
}

void print_products() {
    printf("----- Products -----\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d - %s ($%d)\n", products[i].id, products[i].name, products[i].current_price);
    }
}

void place_bid(int product_id, int amount, char* name) {
    if (product_id < 1 || product_id > num_products) {
        printf("Invalid product id\n");
        return;
    }

    Product* p = &products[product_id - 1];

    if (amount < p->current_price + INCREMENT) {
        printf("Bid should be at least %d more than current price\n", INCREMENT);
        return;
    }

    if (p->num_bids >= MAX_BIDS) {
        printf("Maximum number of bids reached\n");
        return;
    }

    Bid b;
    b.amount = amount;
    strcpy(b.name, name);

    p->bids[p->num_bids++] = b;
    p->current_price = amount;
}

void print_bids(int product_id) {
    if (product_id < 1 || product_id > num_products) {
        printf("Invalid product id\n");
        return;
    }

    Product p = products[product_id - 1];

    printf("----- Bids for %s -----\n", p.name);

    for (int i = 0; i < p.num_bids; i++) {
        printf("%s - $%d\n", p.bids[i].name, p.bids[i].amount);
    }
}

int main() {
    initialize_products();

    int choice;
    int product_id;
    int bid_amount;
    char name[MAX_LEN];

    while (1) {
        printf("\n1. List products\n");
        printf("2. Place bid\n");
        printf("3. List bids for product\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: print_products(); break;
            case 2: {
                printf("Enter product id: ");
                scanf("%d", &product_id);
                printf("Enter bid amount: ");
                scanf("%d", &bid_amount);
                printf("Enter your name: ");
                scanf("%s", name);
                place_bid(product_id, bid_amount, name);
                break;
            }
            case 3: {
                printf("Enter product id: ");
                scanf("%d", &product_id);
                print_bids(product_id);
                break;
            }
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}