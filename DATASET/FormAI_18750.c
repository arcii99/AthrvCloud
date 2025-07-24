//FormAI DATASET v1.0 Category: Product Inventory System ; Style: innovative
#include <stdio.h>
#include <string.h>

// Function to add product to inventory
void addProduct(char name[], int quantity, float price, char inventory[][20], int quantities[], float prices[]) {
    strcpy(inventory[0], name);
    quantities[0] = quantity;
    prices[0] = price;
    printf("\nProduct added successfully!\n");
}

// Function to remove product from inventory
void removeProduct(char name[], char inventory[][20], int quantities[], float prices[]) {
    int i, index = -1;
    for(i=0; i<10; i++) {
        if(!strcmp(inventory[i], name)) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nProduct not found in inventory!\n");
    } else {
        strcpy(inventory[index], "");
        quantities[index] = -1;
        prices[index] = -1.0;
        printf("\nProduct removed successfully!\n");
    }
}

// Function to update product in inventory
void updateProduct(char name[], int quantity, float price, char inventory[][20], int quantities[], float prices[]) {
    int i, index = -1;
    for(i=0; i<10; i++) {
        if(!strcmp(inventory[i], name)) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nProduct not found in inventory!\n");
    } else {
        quantities[index] = quantity;
        prices[index] = price;
        printf("\nProduct updated successfully!\n");
    }
}

// Function to display inventory
void displayInventory(char inventory[][20], int quantities[], float prices[]) {
    int i;
    printf("\n%-20s%-20s%s\n", "Name", "Quantity", "Price");
    for(i=0; i<10; i++) {
        if(strcmp(inventory[i], "")) {
            printf("%-20s%-20d$%.2f\n", inventory[i], quantities[i], prices[i]);
        }
    }
}

int main() {
    char inventory[10][20], name[20];
    int quantities[10], quantity, choice, i;
    float prices[10], price;
    for(i=0; i<10; i++) {
        strcpy(inventory[i], "");
        quantities[i] = -1;
        prices[i] = -1.0;
    }
    while(1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Update Product\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addProduct(name, quantity, price, inventory, quantities, prices);
                break;
            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                removeProduct(name, inventory, quantities, prices);
                break;
            case 3:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                updateProduct(name, quantity, price, inventory, quantities, prices);
                break;
            case 4:
                displayInventory(inventory, quantities, prices);
                break;
            case 5:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }
}