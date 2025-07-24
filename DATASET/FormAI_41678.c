//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for coffee item
typedef struct {
    char item_name[20];
    int item_price;
} coffee_item;

int main() {
    // Initialize coffee menu with prices
    coffee_item menu[5];
    strcpy(menu[0].item_name, "Americano");
    menu[0].item_price = 2;
    strcpy(menu[1].item_name, "Latte");
    menu[1].item_price = 3;
    strcpy(menu[2].item_name, "Cappuccino");
    menu[2].item_price = 3;
    strcpy(menu[3].item_name, "Mocha");
    menu[3].item_price = 4;
    strcpy(menu[4].item_name, "Espresso");
    menu[4].item_price = 2;

    int order_total = 0;  // Initialize total cost of the order
    int order_number = 1;  // Initialize order number

    // Infinitely loop the program until user inputs 'exit'
    while (1) {
        printf("Enter item (or 'exit' to end order): ");
        char input[20];
        scanf("%s", input);

        // Check if user wants to exit program
        if (strcmp(input, "exit") == 0) {
            printf("---\nOrder %d total: $%d\n", order_number, order_total);
            printf("Thank you for your business!\n");
            break;
        }

        // Search through the menu array for the user's input
        int found = 0;
        for (int i = 0; i < 5; i++) {
            if (strcmp(menu[i].item_name, input) == 0) {
                printf("%s added to order. Cost: $%d\n", input, menu[i].item_price);
                order_total += menu[i].item_price;
                found = 1;
                break;
            }
        }

        // Print an error message if item is not found in the menu array
        if (!found) {
            printf("Error: '%s' is not on the menu.\n", input);
        }
    }

    return 0;
}