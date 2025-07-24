//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

struct product {
    char name[100];
    int quantity;
    float price;
};

struct warehouse {
    int id;
    struct product products[100];
};

int main() {
    int numProducts = 0;
    struct warehouse warehouse1;
    warehouse1.id = 1;

    // Adding products to the warehouse
    strcpy(warehouse1.products[numProducts].name, "Product 1");
    warehouse1.products[numProducts].quantity = 10;
    warehouse1.products[numProducts].price = 5.99;
    numProducts++;

    strcpy(warehouse1.products[numProducts].name, "Product 2");
    warehouse1.products[numProducts].quantity = 5;
    warehouse1.products[numProducts].price = 7.99;
    numProducts++;

    strcpy(warehouse1.products[numProducts].name, "Product 3");
    warehouse1.products[numProducts].quantity = 15;
    warehouse1.products[numProducts].price = 2.99;
    numProducts++;

    // Displaying the warehouse contents
    printf("Warehouse %d contains:\n", warehouse1.id);
    for(int i = 0; i < numProducts; i++) {
        printf("%s - Quantity: %d - Price: $%.2f\n", 
            warehouse1.products[i].name, 
            warehouse1.products[i].quantity, 
            warehouse1.products[i].price);
    }

    return 0;
}