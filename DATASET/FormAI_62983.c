//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <string.h>

// Define a struct for each item
struct MenuItem {
    char name[30];
    float price;
};

// Define a struct for the order
struct Order {
    struct MenuItem item;
    int quantity;
};

// Declare global variables
struct MenuItem menu[5];
struct Order order[10];
int orderIndex = 0;

// Function to print the menu
void printMenu() {
    printf("\nMenu\n");
    printf("====================\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

// Function to validate user input
int validateInput(int input, int min, int max) {
    if (input >= min && input <= max) {
        return 1;
    }
    printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
    return 0;
}

// Function to add an item to the order
void addItem() {
    int itemNum, quantity;
    printf("Enter the item number: ");
    scanf("%d", &itemNum);
    if (!validateInput(itemNum, 1, 5)) {
        return;
    }
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    if (!validateInput(quantity, 1, 10)) {
        return;
    }
    order[orderIndex].item = menu[itemNum-1];
    order[orderIndex].quantity = quantity;
    orderIndex++;
    printf("%s x%d added to the order.\n", menu[itemNum-1].name, quantity);
}

// Function to print the order
void printOrder() {
    printf("\nOrder\n");
    printf("====================\n");
    float total = 0;
    for (int i = 0; i < orderIndex; i++) {
        printf("%d. %s x%d - $%.2f\n", i+1, order[i].item.name, order[i].quantity, order[i].item.price * order[i].quantity);
        total += order[i].item.price * order[i].quantity;
    }
    printf("--------------------\n");
    printf("Total: $%.2f\n", total);
}

int main() {
    // Populate the menu items
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 2.50;
    strcpy(menu[1].name, "Latte");
    menu[1].price = 3.50;
    strcpy(menu[2].name, "Cappuccino");
    menu[2].price = 3.00;
    strcpy(menu[3].name, "Muffin");
    menu[3].price = 1.50;
    strcpy(menu[4].name, "Croissant");
    menu[4].price = 2.00;
    
    // Welcome the user
    printf("Welcome to the cafe billing system!\n");
    int choice;
    do {
        // Print menu
        printMenu();
        // Ask user for their choice
        printf("Enter your choice (1-3 to add an item, 4 to view order, 5 to exit): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            case 2:
            case 3:
                addItem();
                break;
            case 4:
                printOrder();
                break;
            case 5:
                printf("Thank you for using the cafe billing system.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}