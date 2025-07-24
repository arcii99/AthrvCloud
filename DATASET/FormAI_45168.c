//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Global variables
int inventory[100];   // An array to store inventory items
int quantity[100];    // An array to store quantity of each inventory item
char items[100][50];  // A 2D array to store the name of each inventory item

// Function to add an item to the inventory
void add_item(int item_number, char* item_name, int item_quantity) {
    inventory[item_number-1] = item_number;
    quantity[item_number-1] = item_quantity;
    strcpy(items[item_number-1], item_name);
}

// Function to remove an item from the inventory
void remove_item(int item_number) {
    inventory[item_number-1] = 0;
    quantity[item_number-1] = 0;
    strcpy(items[item_number-1], "");
}

// Function to display the inventory
void display_inventory() {
    printf("Inventory:\n");
    printf("Item Number\tItem Name\tQuantity\n");
    for(int i=0; i<100; i++) {
        if(inventory[i] != 0) {
            printf("%d\t\t%s\t\t%d\n", inventory[i], items[i], quantity[i]);
        }
    }
}

int main() {
    // Set initial values for inventory
    memset(inventory, 0, 100);
    memset(quantity, 0, 100);
    memset(items, 0, 5000);
    
    // Welcome message
    printf("Welcome to the Medical Store Management System!\n");
    
    // Add some initial items to the inventory
    add_item(1, "Bandages", 50);
    add_item(2, "Antibiotics", 20);
    add_item(3, "Painkillers", 30);
    
    // Display current inventory
    display_inventory();
    
    // Allow user to add and remove items from the inventory
    int choice, item_number, item_quantity;
    char item_name[50];
    while(1) {
        printf("Enter 1 to add item, 2 to remove item, 3 to display inventory, or 4 to exit: ");
        scanf("%d", &choice);
        
        if(choice == 1) {
            printf("Enter item number: ");
            scanf("%d", &item_number);
            printf("Enter item name: ");
            scanf("%s", item_name);
            printf("Enter item quantity: ");
            scanf("%d", &item_quantity);
            add_item(item_number, item_name, item_quantity);
        }
        else if(choice == 2) {
            printf("Enter item number: ");
            scanf("%d", &item_number);
            remove_item(item_number);
        }
        else if(choice == 3) {
            display_inventory();
        }
        else if(choice == 4) {
            return 0;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    
    return 0;
}