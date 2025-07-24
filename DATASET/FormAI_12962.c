//FormAI DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the structure for products
typedef struct {
    int product_id;
    char product_name[50];
    int quantity;
    float price;
} product;

// function prototypes
void add_product(product *inventory, int *num_products);
void remove_product(product *inventory, int *num_products);
void display_inventory(product *inventory, int num_products);

int main() {
    int num_products = 0; // keeps track of number of products in inventory
    product *inventory = NULL; // pointer to dynamically allocated array of products
    
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                remove_product(inventory, &num_products);
                break;
            case 3:
                display_inventory(inventory, num_products);
                break;
            case 4:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice! Please enter again.\n");
                break;
        }
    } while(choice != 4);
    
    // free memory used for inventory
    free(inventory);
    inventory = NULL;
    
    return 0;
}

void add_product(product *inventory, int *num_products) {
    // dynamically reallocate memory for inventory
    inventory = (product*) realloc(inventory, (*num_products + 1) * sizeof(product));
    
    // ask user for product details
    printf("\nEnter details of product %d\n", *num_products + 1);
    printf("Product ID: ");
    scanf("%d", &inventory[*num_products].product_id);
    printf("Product name: ");
    scanf("%s", inventory[*num_products].product_name);
    printf("Quantity: ");
    scanf("%d", &inventory[*num_products].quantity);
    printf("Price: ");
    scanf("%f", &inventory[*num_products].price);
    
    // increment num_products
    *num_products += 1;
    
    printf("Product added successfully!\n");
}

void remove_product(product *inventory, int *num_products) {
    int prod_id, i, j;
    printf("\nEnter ID of product to remove: ");
    scanf("%d", &prod_id);
    
    // search for product by prod_id
    for(i = 0; i < *num_products; i++) {
        if(inventory[i].product_id == prod_id) {
            // move all products after the removed product up by one position
            for(j = i+1; j < *num_products; j++) {
                inventory[j-1] = inventory[j];
            }
            // dynamically reallocate memory for inventory
            inventory = (product*) realloc(inventory, (*num_products - 1) * sizeof(product));
            // decrement num_products
            *num_products -= 1;
            printf("Product removed successfully!\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void display_inventory(product *inventory, int num_products) {
    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    int i;
    for(i = 0; i < num_products; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", inventory[i].product_id, inventory[i].product_name,
        inventory[i].quantity, inventory[i].price);
    }
}