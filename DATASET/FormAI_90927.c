//FormAI DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int id;
    int price;
    int quantity;
};

int count = 0;

void add_product(struct product p[], char n[], int i, int pri, int q) {
    strcpy(p[count].name, n);
    p[count].id = i;
    p[count].price = pri;
    p[count].quantity = q;
    count++;
}

void search_product_by_id(struct product p[], int i) {
    int found = 0;
    for (int j = 0; j < count; j++) {
        if (p[j].id == i) {
            printf("Product Name: %s\n", p[j].name);
            printf("Price: %d\n", p[j].price);
            printf("Quantity: %d\n", p[j].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found!\n");
    }
}

void show_all_products(struct product p[]) {
    printf("ID\tNAME\t\tPRICE\tQUANTITY\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t%d\n", p[i].id, p[i].name, p[i].price, p[i].quantity);
    }
}

int main() {
    struct product products[100];

    add_product(products, "Apple", 1001, 50, 100);
    add_product(products, "Banana", 1002, 20, 200);
    add_product(products, "Orange", 1003, 30, 150);
    
    printf("Product Inventory System\n");
    printf("========================\n");
    
    int choice;
    while (1) {
        printf("\n1. Add Product\n");
        printf("2. Search Product by ID\n");
        printf("3. Show All Products\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            char n[50];
            int i, pri, q;
            printf("\nEnter product name: ");
            scanf("%s", n);
            printf("Enter product id: ");
            scanf("%d", &i);
            printf("Enter product price: ");
            scanf("%d", &pri);
            printf("Enter product quantity: ");
            scanf("%d", &q);
            add_product(products, n, i, pri, q);
            printf("\nProduct added to inventory!\n");
        }
        else if (choice == 2) {
            int i;
            printf("\nEnter product id: ");
            scanf("%d", &i);
            search_product_by_id(products, i);
        }
        else if (choice == 3) {
            show_all_products(products);
        }
        else if (choice == 4) {
            exit(0);
        }
        else {
            printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}