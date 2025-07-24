//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for menu items
struct menu_item {
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct menu_item menu[5] = {
        {"Americano", 2.50, 0},
        {"Latte", 3.00, 0},
        {"Cappuccino", 3.50, 0},
        {"Croissant", 2.00, 0},
        {"Bagel", 1.50, 0}
    };

    float subtotal = 0.0;
    float tax_rate = 0.06;
    float tax;
    float total;
    char input[50];
    int choice;
    int quantity;

    // Print the menu
    printf("Welcome to C Cafe!\n");
    printf("===================\n\n");
    printf("Menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }

    // Take the user's order
    printf("\nEnter your order (e.g. '1 2 2 4'): ");
    fgets(input, 50, stdin);
    strtok(input, "\n");
    char* token = strtok(input, " ");
    while (token != NULL) {
        choice = atoi(token) - 1;
        if (choice >= 0 && choice < 5) {
            menu[choice].quantity++;
            subtotal += menu[choice].price;
        }
        token = strtok(NULL, " ");
    }

    // Print the order
    printf("\n\nYour order:\n");
    for (int i = 0; i < 5; i++) {
        if (menu[i].quantity > 0) {
            printf("%s x%d - $%.2f\n", menu[i].name, menu[i].quantity, menu[i].price * menu[i].quantity);
        }
    }

    // Calculate the total
    tax = subtotal * tax_rate;
    total = subtotal + tax;

    // Print the subtotal, tax and total
    printf("\nSubtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax);
    printf("Total: $%.2f\n", total);

    return 0;
}