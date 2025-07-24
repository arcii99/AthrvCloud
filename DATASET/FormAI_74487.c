//FormAI DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[20];
    int quantity;
    float price;
};

int main() {
    struct product inventory[10];
    int choice, index, quantity;
    float price;
    char name[20];
    
    // Initialize the inventory with some products
    strcpy(inventory[0].name, "Canned Food");
    inventory[0].quantity = 25;
    inventory[0].price = 15.0;
    
    strcpy(inventory[1].name, "Water bottle");
    inventory[1].quantity = 10;
    inventory[1].price = 5.0;
    
    strcpy(inventory[2].name, "Knife");
    inventory[2].quantity = 5;
    inventory[2].price = 25.0;
    
    strcpy(inventory[3].name, "Flashlight");
    inventory[3].quantity = 7;
    inventory[3].price = 10.0;
    
    do {
        printf("\n\nPRODUCT INVENTORY SYSTEM\n");
        printf("1. Add Product\n2. Remove Product\n3. Update Product\n4. Display Inventory\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Add Product
                printf("\nEnter Product Name: ");
                scanf("%s", name);
                printf("Enter Price: ");
                scanf("%f", &price);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                
                // Find the first empty slot in inventory
                for(index = 0; index < 10; index++) {
                    if(inventory[index].quantity == 0) {
                        break;
                    }
                }
                
                if(index == 10) {
                    printf("\nInventory is Full!\n");
                } else {
                    // Add the product to inventory
                    strcpy(inventory[index].name, name);
                    inventory[index].price = price;
                    inventory[index].quantity = quantity;
                    
                    printf("\nProduct Added Successfully!\n");
                }
                
                break;
            
            case 2:
                // Remove Product
                printf("\nEnter the Product Name to Remove: ");
                scanf("%s", name);
                
                // Find the product in inventory
                for(index = 0; index < 10; index++) {
                    if(strcmp(inventory[index].name, name) == 0) {
                        break;
                    }
                }
                
                if(index == 10) {
                    printf("\nProduct not Found!\n");
                } else {
                    // Remove the product from inventory
                    strcpy(inventory[index].name, "");
                    inventory[index].price = 0;
                    inventory[index].quantity = 0;
                    
                    printf("\nProduct Removed Successfully!\n");
                }
                
                break;
            
            case 3:
                // Update Product
                printf("\nEnter Product Name to Update: ");
                scanf("%s", name);
                
                // Find the product in inventory
                for(index = 0; index < 10; index++) {
                    if(strcmp(inventory[index].name, name) == 0) {
                        break;
                    }
                }
                
                if(index == 10) {
                    printf("\nProduct not Found!\n");
                } else {
                    // Update the product in inventory
                    printf("Enter New Price: ");
                    scanf("%f", &price);
                    printf("Enter New Quantity: ");
                    scanf("%d", &quantity);
                    
                    inventory[index].price = price;
                    inventory[index].quantity = quantity;
                    
                    printf("\nProduct Updated Successfully!\n");
                }
                
                break;
            
            case 4:
                // Display Inventory
                printf("\nProduct Inventory:\n");
                printf("%-20s %-10s %-10s\n", "Product Name", "Price", "Quantity");
                
                for(index = 0; index < 10; index++) {
                    if(inventory[index].quantity > 0) {
                        printf("%-20s $%-9.2f %-10d\n", inventory[index].name, inventory[index].price, inventory[index].quantity);
                    }
                }
                
                break;
            
            case 5:
                // Exit
                printf("\nExiting Product Inventory System...\n");
                exit(0);
                break;
            
            default:
                printf("\nInvalid Choice! Try Again.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}