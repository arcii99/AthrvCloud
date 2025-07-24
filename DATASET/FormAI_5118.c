//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold data for each item in the warehouse
typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

// Define a function to print each item's data
void print_item(Item i) {
    printf("%s:\n", i.name);
    printf(" - Quantity: %d\n", i.quantity);
    printf(" - Price: $%.2f\n", i.price);
}

int main(void) {

    // Define an array to hold all of the items in the warehouse
    Item items[100];

    // Add some sample data to the items array
    strcpy(items[0].name, "Widget");
    items[0].quantity = 10;
    items[0].price = 5.99;
    strcpy(items[1].name, "Thingamajig");
    items[1].quantity = 5;
    items[1].price = 10.99;
    strcpy(items[2].name, "Doodad");
    items[2].quantity = 3;
    items[2].price = 2.99;

    // Define some variables to hold user input
    char action[10]; // add, remove, or view
    char name[50]; // name of item to add or remove
    int quantity; // quantity of item to add or remove

    // Define a loop to prompt the user for input and act on that input
    while (1) {

        // Prompt the user for an action
        printf("Enter an action (add, remove, view): ");
        scanf("%s", action);

        // Perform the appropriate action based on user input
        if (strcmp(action, "add") == 0) {
            // Prompt the user for the name of the item to add
            printf("Enter the name of the item to add: ");
            scanf("%s", name);

            // Check if the item is already in the warehouse
            int found = 0;
            int i;
            for (i = 0; i < 100; i++) {
                if (strcmp(items[i].name, name) == 0) {
                    found = 1;
                    break;
                }
            }

            // If the item is already in the warehouse, prompt the user for the quantity to add
            if (found) {
                printf("Item already exists in warehouse. Enter quantity to add: ");
                scanf("%d", &quantity);
                items[i].quantity += quantity;
            }
            // If the item is not already in the warehouse, prompt the user for all of the item's data and add it to the array
            else {
                printf("Enter quantity and price of item to add: ");
                scanf("%d %f", &quantity, &items[3].price);
                strcpy(items[3].name, name);
                items[3].quantity = quantity;
            }
        }
        else if (strcmp(action, "remove") == 0) {
            // Prompt the user for the name of the item to remove
            printf("Enter the name of the item to remove: ");
            scanf("%s", name);

            // Check if the item is in the warehouse
            int found = 0;
            int i;
            for (i = 0; i < 100; i++) {
                if (strcmp(items[i].name, name) == 0) {
                    found = 1;
                    break;
                }
            }

            // If the item is in the warehouse, prompt the user for the quantity to remove
            if (found) {
                printf("Enter quantity to remove: ");
                scanf("%d", &quantity);
                items[i].quantity -= quantity;
            }
            // If the item is not in the warehouse, print an error message
            else {
                printf("Item not found in warehouse.\n");
            }
        }
        else if (strcmp(action, "view") == 0) {
            // Print out the data for each item in the warehouse
            int i;
            for (i = 0; i < 100; i++) {
                if (strlen(items[i].name) == 0) break;
                print_item(items[i]);
            }
        }
        else {
            // If the user enters an invalid action, print an error message
            printf("Invalid action.\n");
        }

    }

    return 0;
}