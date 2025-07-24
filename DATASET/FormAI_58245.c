//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 20
#define MAX_ITEM_NAME 20

// Structure for an item
typedef struct {
    char name[MAX_ITEM_NAME];
    int quantity;
    double price;
} Item;

// Structure for a bill
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
    double total;
} Bill;

// Function to add an item to a bill
void add_item(Bill *bill, char *name, int quantity, double price) {
    // Check if the item already exists in the bill
    for (int i = 0; i < bill->num_items; i++) {
        if (strcmp(bill->items[i].name, name) == 0) {
            // Update the quantity and total price of the existing item
            bill->items[i].quantity += quantity;
            bill->total += quantity * price;
            return;
        }
    }
    
    // Add the new item to the bill
    strcpy(bill->items[bill->num_items].name, name);
    bill->items[bill->num_items].quantity = quantity;
    bill->items[bill->num_items].price = price;
    bill->total += quantity * price;
    bill->num_items++;
}

// Function to print a bill
void print_bill(Bill *bill) {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < bill->num_items; i++) {
        printf("%s\t\t%d\t\t%.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price);
    }
    printf("Total: $%.2f\n", bill->total);
}

// Main function
int main() {
    // Create a new bill
    Bill bill = { .num_items = 0, .total = 0 };
    
    // Add some items to the bill
    add_item(&bill, "Coffee", 1, 2.50);
    add_item(&bill, "Tea", 2, 1.75);
    add_item(&bill, "Croissant", 1, 3.00);
    
    // Print the bill
    print_bill(&bill);
    
    return 0;
}