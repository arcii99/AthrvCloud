//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <string.h>

struct Product {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int option, i, j, index, reorder;
    float total;
    char search[50], confirm;
    struct Product inventory[100];
    
    //initialize inventory
    for (i = 0; i < 100; i++) {
        strcpy(inventory[i].name, "");
        inventory[i].quantity = 0;
        inventory[i].price = 0.0;
    }
    
    do {
        //display menu
        printf("\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Search Product\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            //add product
            case 1:
                for (i = 0; i < 100; i++) {
                    if (inventory[i].quantity == 0) {
                        printf("\nEnter Product Name: ");
                        scanf("%s", &inventory[i].name);
                        printf("Enter Quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        printf("Enter Price: ");
                        scanf("%f", &inventory[i].price);
                        
                        printf("\nProduct added successfully!\n");
                        break;
                    }
                }
                if (i == 100) {
                    printf("\nInventory full. Cannot add more products.\n");
                }
                break;
                
            //remove product
            case 2:
                printf("\nEnter Product Name: ");
                scanf("%s", &search);
                
                for (i = 0; i < 100; i++) {
                    if (strcmp(search, inventory[i].name) == 0) {
                        printf("\nProduct Found:\n");
                        printf("Name: %s\n", inventory[i].name);
                        printf("Quantity: %d\n", inventory[i].quantity);
                        printf("Price: $%.2f\n", inventory[i].price);
                        
                        printf("\nAre you sure you want to remove this product? (Y/N): ");
                        scanf(" %c", &confirm);
                        if (confirm == 'Y' || confirm == 'y') {
                            inventory[i].quantity = 0;
                            printf("\nProduct removed successfully!\n");
                        } else {
                            printf("\nRemoval of product cancelled.\n");
                        }
                        break;
                    }
                }
                if (i == 100) {
                    printf("\nProduct not found. Unable to remove.\n");
                }
                break;
                
            //search product
            case 3:
                printf("\nEnter Product Name: ");
                scanf("%s", &search);
                
                for (i = 0; i < 100; i++) {
                    if (strcmp(search, inventory[i].name) == 0) {
                        printf("\nProduct Found:\n");
                        printf("Name: %s\n", inventory[i].name);
                        printf("Quantity: %d\n", inventory[i].quantity);
                        printf("Price: $%.2f\n", inventory[i].price);
                        break;
                    }
                }
                if (i == 100) {
                    printf("\nProduct not found.\n");
                }
                break;
                
            //display inventory
            case 4:
                //initialize total and reorder flag
                total = 0.0;
                reorder = 0;
                
                printf("\nInventory:\n");
                printf("Product Name\t\tQuantity\tPrice\n");
                for (i = 0; i < 100; i++) {
                    if (inventory[i].quantity > 0) {
                        printf("%-20s\t\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                        total += (inventory[i].quantity * inventory[i].price);
                        if (inventory[i].quantity < 10) {
                            reorder = 1;
                        }
                    }
                }
                printf("\nTotal value of inventory: $%.2f\n", total);
                if (reorder) {
                    printf("\nSome products need to be reordered.\n");
                }
                break;
                
            //exit
            case 5:
                printf("\nExiting program...\n");
                break;
                
            //invalid option
            default:
                printf("\nInvalid option. Please try again.\n");
        }
        
    } while (option != 5);
    
    return 0;
}