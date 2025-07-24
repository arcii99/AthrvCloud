//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int numProducts;
    printf("Enter the number of products: ");
    scanf("%d", &numProducts);
    
    struct product warehouse[numProducts];
    
    for(int i = 0; i < numProducts; i++) {
        printf("\nEnter product name: ");
        scanf("%s", warehouse[i].name);
        printf("\nEnter product quantity: ");
        scanf("%d", &warehouse[i].quantity);
        printf("\nEnter product price: ");
        scanf("%f", &warehouse[i].price);
    }
    
    // Display product details
    printf("\nProduct details:\n");
    for(int i = 0; i < numProducts; i++) {
        printf("\nProduct %d\n", i+1);
        printf("Product name: %s\n", warehouse[i].name);
        printf("Product quantity: %d\n", warehouse[i].quantity);
        printf("Product price: %.2f\n", warehouse[i].price);
    }
    
    // Find most expensive product
    float maxPrice = 0;
    int maxIndex = 0;
    for(int i = 0; i < numProducts; i++) {
        if(warehouse[i].price > maxPrice) {
            maxPrice = warehouse[i].price;
            maxIndex = i;
        }
    }
    
    printf("\nThe most expensive product is \"%s\" with a price of %.2f\n", warehouse[maxIndex].name, maxPrice);
    
    return 0;
}