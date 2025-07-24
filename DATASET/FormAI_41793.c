//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for maximum menu items
#define MAX_MENU_ITEMS 20

// Define a struct to represent a menu item
struct MenuItem {
    char name[30];
    double price;
    int quantity;
};

// Define a struct to represent a table
struct Table {
    int number;
    double subtotal;
    double tax;
    double total;
    struct MenuItem items[MAX_MENU_ITEMS];
    int numItems;
};

// Function to calculate the subtotal for a table
double calculateTableSubtotal(struct Table table) {
    double subtotal = 0.0;
    for (int i = 0; i < table.numItems; i++) {
        subtotal += (table.items[i].price * table.items[i].quantity);
    }
    return subtotal;
}

// Function to calculate tax for a table
double calculateTableTax(struct Table table, double taxRate) {
    return table.subtotal * (taxRate / 100.0);
}

// Function to calculate the total cost of a table (including tax)
double calculateTableTotal(struct Table table, double taxRate) {
    double subtotal = calculateTableSubtotal(table);
    table.subtotal = subtotal;
    double tax = calculateTableTax(table, taxRate);
    table.tax = tax;
    double total = subtotal + tax;
    table.total = total;
    return total;
}

// Function to print the receipt for a table
void printTableReceipt(struct Table table, double taxRate) {
    printf("Table %d\n", table.number);
    printf("------------------\n");
    printf("- Menu Items: \n");
    for (int i = 0; i < table.numItems; i++) {
        printf("  - %s x %d - $%.2lf\n", table.items[i].name, table.items[i].quantity, table.items[i].price);
    }
    double subtotal = calculateTableSubtotal(table);
    table.subtotal = subtotal;
    printf("- Subtotal: $%.2lf\n", table.subtotal);
    double tax = calculateTableTax(table, taxRate);
    table.tax = tax;
    printf("- Tax (%.1lf%%): $%.2lf\n", taxRate, table.tax);
    double total = calculateTableTotal(table, taxRate);
    table.total = total;
    printf("- Total: $%.2lf\n", total);
    printf("------------------\n");
}

int main() {
    // Initialize tables with an empty menu
    struct Table tables[10];
    for (int i = 0; i < 10; i++) {
        tables[i].number = i + 1;
        tables[i].subtotal = 0.0;
        tables[i].tax = 0.0;
        tables[i].total = 0.0;
        tables[i].numItems = 0;
    }
    
    // Define the menu with prices for each item
    struct MenuItem menu[MAX_MENU_ITEMS];
    menu[0] = (struct MenuItem) { "Coffee", 1.50 };
    menu[1] = (struct MenuItem) { "Bagel", 2.00 };
    menu[2] = (struct MenuItem) { "Muffin", 2.50 };
    menu[3] = (struct MenuItem) { "Croissant", 2.50 };
    menu[4] = (struct MenuItem) { "Fruit Cup", 3.00 };
    menu[5] = (struct MenuItem) { "Yogurt Parfait", 3.50 };
    menu[6] = (struct MenuItem) { "Egg Sandwich", 4.00 };
    menu[7] = (struct MenuItem) { "Ham and Cheese Sandwich", 4.50 };
    menu[8] = (struct MenuItem) { "Turkey and Cheese Sandwich", 4.50 };
    menu[9] = (struct MenuItem) { "Bagel with Cream Cheese", 3.00 };
    
    // Define the tax rate
    double taxRate = 8.75;
    
    // Start the user interface loop
    while (1) {
        int choice = 0;
        
        // Print the main menu
        printf("\nWelcome to the Cafe Billing System!\n");
        printf("1. New table order\n");
        printf("2. Print receipt for table\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        // Handle the user's choice
        if (choice == 1) {
            int tableNum = 0;
            struct Table *table;
            
            // Get the table number from the user
            printf("\nEnter table number (1-10): ");
            scanf("%d", &tableNum);
            if (tableNum < 1 || tableNum > 10) {
                printf("\nInvalid table number!\n");
                continue;
            }
            
            // Get the table struct for the chosen table number
            table = &tables[tableNum-1];
            
            // Get the menu item to add to the table
            int itemIndex = 0;
            printf("\nMenu Items:\n");
            for (int i = 0; i < MAX_MENU_ITEMS; i++) {
                if (strlen(menu[i].name) == 0) {
                    continue;
                }
                printf("%d. %s - $%.2lf\n", i+1, menu[i].name, menu[i].price);
            }
            printf("\nEnter menu item: ");
            scanf("%d", &itemIndex);
            if (itemIndex < 1 || itemIndex > MAX_MENU_ITEMS) {
                printf("\nInvalid menu item!\n");
                continue;
            }
            
            // Get the quantity of the menu item to add to the table
            int quantity = 0;
            printf("\nEnter quantity: ");
            scanf("%d", &quantity);
            if (quantity < 1) {
                printf("\nInvalid quantity!\n");
                continue;
            }
            
            // Add the menu item to the table
            table->items[table->numItems] = menu[itemIndex - 1];
            table->items[table->numItems].quantity = quantity;
            table->numItems++;
            
            // Confirm the added item
            printf("\nAdded %s x %d to table %d\n", table->items[table->numItems-1].name, table->items[table->numItems-1].quantity, table->number);
        } else if (choice == 2) {
            int tableNum = 0;
            
            // Get the table number from the user
            printf("\nEnter table number (1-10): ");
            scanf("%d", &tableNum);
            if (tableNum < 1 || tableNum > 10) {
                printf("\nInvalid table number!\n");
                continue;
            }
            
            // Print the receipt for the table
            printTableReceipt(tables[tableNum-1], taxRate);
        } else if (choice == 3) {
            // Exit the program
            printf("\nExiting Cafe Billing System...\n");
            break;
        } else {
            // Invalid choice
            printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}