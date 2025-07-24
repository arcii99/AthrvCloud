//FormAI DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining the maximum size of the product inventory
#define MAX 1000

//Structure of each product in the inventory
typedef struct {
    char name[50];
    char category[30];
    float price;
    int quantity;
} Product;

//Global variable for the product inventory
Product inventory[MAX];

//Function to add products to the inventory
void addProduct() {
    char tempName[50], tempCategory[30];
    float tempPrice;
    int tempQuantity, i;

    //Checking if the inventory is full
    for (i = 0; i < MAX; i++) {
        if (strcmp(inventory[i].name, "") == 0) { //If there is an empty slot
            break;
        }
    }

    if (i == MAX) { //Inventory is full
        printf("The inventory is full! Cannot add more products.\n");
        return;
    }

    //Getting details of the new product
    printf("Enter Product Name: ");
    fgets(tempName, 50, stdin);
    tempName[strlen(tempName) - 1] = '\0'; //Removing the trailing newline character

    printf("Enter Product Category: ");
    fgets(tempCategory, 30, stdin);
    tempCategory[strlen(tempCategory) - 1] = '\0'; //Removing the trailing newline character

    printf("Enter Product Price: ");
    scanf("%f", &tempPrice);

    printf("Enter Product Quantity: ");
    scanf("%d", &tempQuantity);

    //Adding the product to the inventory
    strcpy(inventory[i].name, tempName);
    strcpy(inventory[i].category, tempCategory);
    inventory[i].price = tempPrice;
    inventory[i].quantity = tempQuantity;

    printf("Product added successfully!\n");
}

//Function to search for a product in the inventory
void searchProduct() {
    char searchTerm[50];
    int i, found = 0;

    //Getting the search term from the user
    printf("Enter Product Name to search: ");
    fgets(searchTerm, 50, stdin);
    searchTerm[strlen(searchTerm) - 1] = '\0'; //Removing the trailing newline character

    //Searching for the product
    for (i = 0; i < MAX; i++) {
        if (strcmp(inventory[i].name, searchTerm) == 0) { //If product name matches the search term
            printf("Product details:\n");
            printf("Name: %s\nCategory: %s\nPrice: %.2f\nQuantity: %d\n", inventory[i].name, inventory[i].category, inventory[i].price, inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (found == 0) { //Product not found
        printf("Product not found in inventory.\n");
    }
}

//Function to display all products in the inventory
void displayAll() {
    int i, count = 0;

    printf("\nProduct Inventory:\n");

    for (i = 0; i < MAX; i++) {
        if (strcmp(inventory[i].name, "") != 0) { //If slot is not empty
            printf("%d. Name: %s | Category: %s | Price: %.2f | Quantity: %d\n", count + 1, inventory[i].name, inventory[i].category, inventory[i].price, inventory[i].quantity);
            count++;
        }
    }

    if (count == 0) { //No products in the inventory
        printf("No products in the inventory yet!\n");
    }
}

//Function to update the quantity of a product
void updateQuantity() {
    char searchTerm[50];
    int i, found = 0, quantityUpdate;

    //Getting the search term from the user
    printf("Enter Product Name to update quantity: ");
    fgets(searchTerm, 50, stdin);
    searchTerm[strlen(searchTerm) - 1] = '\0'; //Removing the trailing newline character

    //Searching for the product
    for (i = 0; i < MAX; i++) {
        if (strcmp(inventory[i].name, searchTerm) == 0) { //If product name matches the search term
            printf("Enter updated quantity: ");
            scanf("%d", &quantityUpdate);

            inventory[i].quantity = quantityUpdate;

            printf("Quantity updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) { //Product not found
        printf("Product not found in inventory.\n");
    }
}

int main() {
    int choice;

    //Initializing the product inventory
    for (int i = 0; i < MAX; i++) {
        strcpy(inventory[i].name, "");
        strcpy(inventory[i].category, "");
        inventory[i].price = 0;
        inventory[i].quantity = 0;
    }

    printf("\t*+ Welcome to the Happy Product Inventory System! +*\n\n");

    do {
        printf("What would you like to do?\n");
        printf("1. Add a product to the inventory\n");
        printf("2. Search for a product\n");
        printf("3. Display all products\n");
        printf("4. Update quantity of a product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        getchar(); //Removing the '\n' character from the input buffer

        switch (choice) {
            case 1: addProduct(); break;
            case 2: searchProduct(); break;
            case 3: displayAll(); break;
            case 4: updateQuantity(); break;
            case 5: printf("\n*+ Thanks for using the Happy Product Inventory System! +*\n"); break;
            default: printf("\nInvalid choice. Please select again.\n");
        }
    } while(choice != 5);

    return 0;
}