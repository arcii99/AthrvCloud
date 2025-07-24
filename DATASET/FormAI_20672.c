//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_PRODUCTS 20
#define PRODUCT_NAME_SIZE 50
#define MAX_QUANTITY 100

struct Product {
    char name[PRODUCT_NAME_SIZE];
    float price;
    int quantity;
};

void printMenu();
int addProduct(struct Product*, int);
void removeProduct(struct Product*, int);
void printInventory(struct Product*, int);

int main() {
    struct Product inventory[MAX_PRODUCTS];
    int inventorySize = 0;
    char choice;

    /* Sample products added for ease of testing */
    strcpy(inventory[inventorySize].name, "Paracetamol Tablets");
    inventory[inventorySize].price = 1.50;
    inventory[inventorySize].quantity = 20;
    inventorySize++;
    strcpy(inventory[inventorySize].name, "Aspirin Tablets");
    inventory[inventorySize].price = 2.00;
    inventory[inventorySize].quantity = 15;
    inventorySize++;
    strcpy(inventory[inventorySize].name, "Betadine Solution");
    inventory[inventorySize].price = 3.50;
    inventory[inventorySize].quantity = 10;
    inventorySize++;

    do {
        printMenu();
        scanf(" %c", &choice);

        switch(choice) {
            case 'A':
            case 'a': inventorySize = addProduct(inventory, inventorySize);
                      break;

            case 'R':
            case 'r': removeProduct(inventory, inventorySize);
                      inventorySize--;
                      break;

            case 'P':
            case 'p': printInventory(inventory, inventorySize);
                      break;

            case 'Q':
            case 'q': printf("\nThank you for using the program. Goodbye!\n");
                      break;

            default: printf("\nInvalid command. Please try again.\n");
        }

    } while(choice!='Q' && choice!='q');

    return 0;
}

/* Function to display the menu to the user */
void printMenu() {
    printf("\n\n");
    printf("Please choose one of the following options:\n");
    printf("-------------------------------------------\n");
    printf("A: Add a new product to the inventory\n");
    printf("R: Remove a product from the inventory\n");
    printf("P: Print the current inventory\n");
    printf("Q: Quit the program\n");
    printf("-------------------------------------------\n");
    printf("\nEnter your choice: ");
}

/* Function to add a new product to the inventory */
int addProduct(struct Product* inventory, int inventorySize) {
    char name[PRODUCT_NAME_SIZE];
    float price;
    int quantity;
    printf("\n\n***ADD PRODUCT***\n");
    printf("Enter the name of the product: ");
    fflush(stdin);
    fgets(name, PRODUCT_NAME_SIZE, stdin);
    printf("Enter the price of the product: ");
    scanf("%f", &price);
    printf("Enter the quantity of the product: ");
    scanf("%d", &quantity);
    if(inventorySize < MAX_PRODUCTS) {
        strcpy(inventory[inventorySize].name, name);
        inventory[inventorySize].price = price;
        inventory[inventorySize].quantity = quantity;
        printf("\nProduct added successfully.\n");
        return inventorySize + 1;
    } else {
        printf("\nInventory is full. Unable to add new product.\n");
        return inventorySize;
    }
}

/* Function to remove a product from the inventory */
void removeProduct(struct Product* inventory, int inventorySize) {
    char name[PRODUCT_NAME_SIZE];
    int i, index = -1;
    printf("\n\n***REMOVE PRODUCT***\n");
    printf("Enter the name of the product: ");
    fflush(stdin);
    fgets(name, PRODUCT_NAME_SIZE, stdin);
    for(i=0;i<inventorySize;i++) {
        if(strcmp(inventory[i].name, name)==0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("\nProduct not found in inventory.\n");
    } else {
        for(i=index;i<inventorySize-1;i++) {
            strcpy(inventory[i].name, inventory[i+1].name);
            inventory[i].price = inventory[i+1].price;
            inventory[i].quantity = inventory[i+1].quantity;
        }
        printf("\nProduct removed from inventory.\n");
    }
}

/* Function to print the current inventory */
void printInventory(struct Product* inventory, int inventorySize) {
    int i;
    if(inventorySize == 0) {
        printf("\nInventory is Empty!\n");
    } else {
        printf("\n\n***INVENTORY***\n");
        printf("Product Name\tPrice\tQuantity\n");
        printf("--------------------------------------------------\n");
        for(i=0;i<inventorySize;i++) {
            printf("%s\t$%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
        }
        printf("--------------------------------------------------\n");
    }
}