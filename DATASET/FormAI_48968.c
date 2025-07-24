//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure definition to hold inventory data
typedef struct {
    char name[20];
    int quantity;
    float price;
} Inventory;

int main() {
    int numItems, i;
    
    // get the number of items in the inventory
    printf("Enter the number of items in the inventory: ");
    scanf("%d", &numItems);
    getchar();  // consume newline
    
    // allocate memory for the inventory
    Inventory *inventory = (Inventory*) malloc(numItems * sizeof(Inventory));
    
    // get inventory data from user
    for (i = 0; i < numItems; i++) {
        printf("\nEnter details for item %d: \n", i+1);
        printf("Name: ");
        fgets(inventory[i].name, 20, stdin);
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
        getchar();  // consume newline
        printf("Price: ");
        scanf("%f", &inventory[i].price);
        getchar();  // consume newline
    }
    
    // print inventory data
    printf("\nInventory:\n");
    for (i = 0; i < numItems; i++) {
        printf("%d. %s - %d pcs - $%.2f each\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    
    // free the allocated memory
    free(inventory);
    
    return 0;
}