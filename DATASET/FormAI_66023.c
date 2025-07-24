//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include<stdio.h>
#include<string.h>

struct Product {
    // Product details
    int id;
    char name[20];
    int quantity;
    float price;
};

// Function to display product details
void displayProduct(struct Product product)
{
    printf("ID: %d\n", product.id);
    printf("Name: %s\n", product.name);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: %.2f\n\n", product.price);
}

int main()
{
    // Array to store products
    struct Product products[3];

    // Product 1
    products[0].id = 1;
    strcpy(products[0].name, "Romeo's Perfume");
    products[0].quantity = 10;
    products[0].price = 199.99;

    // Product 2
    products[1].id = 2;
    strcpy(products[1].name, "Juliet's Scarf");
    products[1].quantity = 5;
    products[1].price = 99.99;

    // Product 3
    products[2].id = 3;
    strcpy(products[2].name, "Romeo's Hat");
    products[2].quantity = 15;
    products[2].price = 149.99;

    // Display all products
    printf("Inventory:\n\n");

    for(int i=0; i<3; i++) {
        displayProduct(products[i]);
    }

    return 0;
}