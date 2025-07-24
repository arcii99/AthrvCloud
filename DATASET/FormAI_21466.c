//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to hold menu items
typedef struct MenuItem
{
    char name[100];
    float price;
    int quantity;
} MenuItem;

// Helper function to print menu
void printMenu(MenuItem* menuItems, int numItems)
{
    printf("------------------------------\n");
    printf("|%-30s|%-10s|\n", "Item Name", "Price");
    printf("------------------------------\n");

    for(int i = 0; i < numItems; i++)
    {
        printf("|%-30s| $%-9.2f|\n", menuItems[i].name, menuItems[i].price);
    }

    printf("------------------------------\n");
}

// Helper function to calculate total cost of order
float calculateTotal(MenuItem* orderItems, int numItems)
{
    float total = 0;

    for(int i = 0; i < numItems; i++)
    {
        total += orderItems[i].price * orderItems[i].quantity;
    }

    return total;
}

int main()
{
    // Initialize menu
    MenuItem menu[MAX_ITEMS];
    int numMenuItems = 0;

    // Add some items to the menu
    strcpy(menu[numMenuItems].name, "Coffee");
    menu[numMenuItems].price = 2.00;
    numMenuItems++;

    strcpy(menu[numMenuItems].name, "Tea");
    menu[numMenuItems].price = 1.50;
    numMenuItems++;

    strcpy(menu[numMenuItems].name, "Bagel");
    menu[numMenuItems].price = 3.00;
    numMenuItems++;

    // Print menu
    printMenu(menu, numMenuItems);

    // Take order
    MenuItem order[MAX_ITEMS];
    int numOrderItems = 0;
    char input[100];

    while(1)
    {
        printf("Enter item name (or 'done' to finish order): ");
        scanf("%s", input);

        // Check if user is done with order
        if(strcmp(input, "done") == 0)
        {
            break;
        }

        // Search for item in menu
        int foundItem = 0;
        for(int i = 0; i < numMenuItems; i++)
        {
            if(strcmp(input, menu[i].name) == 0)
            {
                // Item found, add to order
                foundItem = 1;
                strcpy(order[numOrderItems].name, menu[i].name);
                order[numOrderItems].price = menu[i].price;

                printf("Enter quantity: ");
                scanf("%d", &order[numOrderItems].quantity);

                numOrderItems++;
                break;
            }
        }

        if(!foundItem)
        {
            printf("Item not found.\n");
        }
    }

    // Calculate total cost
    float totalCost = calculateTotal(order, numOrderItems);

    // Print order summary
    printf("\nOrder summary:\n");
    printf("------------------------------\n");
    printf("|%-30s|%-10s|%-10s|\n", "Item Name", "Price", "Quantity");
    printf("------------------------------\n");

    for(int i = 0; i < numOrderItems; i++)
    {
        printf("|%-30s| $%-9.2f|%-10d|\n", order[i].name, order[i].price, order[i].quantity);
    }

    printf("------------------------------\n");
    printf("|%-41s $%-9.2f|\n", "Total Cost:", totalCost);
    printf("------------------------------\n");

    return 0;
}