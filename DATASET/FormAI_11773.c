//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100 // Maximum number of products that can be stored

struct product {
    int id; // Unique ID of the product
    char name[50]; // Name of the product
    int quantity; // Quantity available in the store
    float price; // Price of the product per unit
};

struct product products[MAX_PRODUCTS]; // Array to store all the products

int num_products; // Total number of products in the store

// Function to add a new product to the store
void add_product() {
    struct product new_product;
    
    printf("Enter the ID of the product: ");
    scanf("%d", &new_product.id);
    
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == new_product.id) {
            printf("Error: Product with ID %d already exists!\n", new_product.id);
            return;
        }
    }
    
    printf("Enter the name of the product: ");
    scanf("%s", new_product.name);
    
    printf("Enter the quantity of the product: ");
    scanf("%d", &new_product.quantity);
    
    printf("Enter the price of the product: ");
    scanf("%f", &new_product.price);
    
    products[num_products] = new_product;
    num_products++;
    
    printf("Product added successfully!\n");
}

// Function to search for a product by ID
int search_by_id(int id) {
    for (int i = 0; i < num_products; i++) {
        if (products[i].id == id) {
            return i;
        }
    }
    
    return -1;
}

// Function to update the quantity of a product
void update_quantity(int id, int quantity) {
    int index = search_by_id(id);
    
    if (index == -1) {
        printf("Error: Product with ID %d not found!\n", id);
        return;
    }
    
    products[index].quantity += quantity;
    
    printf("Quantity updated successfully!\n");
}

// Function to display all the products in the store
void display_products() {
    printf("ID\tName\t\tQuantity\tPrice\n");
    
    for (int i = 0; i < num_products; i++) {
        printf("%d\t%s\t\t%d\t\t$%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    num_products = 0; // Initialize number of products to 0
    
    int choice;
    
    do {
        printf("\n");
        printf("1. Add a new product\n");
        printf("2. Update the quantity of a product\n");
        printf("3. Display all products\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                int id, quantity;
                printf("Enter the ID of the product: ");
                scanf("%d", &id);
                printf("Enter the quantity to be added/subtracted: ");
                scanf("%d", &quantity);
                update_quantity(id, quantity);
                break;
            case 3:
                display_products();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}