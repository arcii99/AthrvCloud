//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50 // Max items in the cafe menu
#define MAX_ORDERS 100 // Max orders per day

// Structure to represent item in the menu
struct MenuItem {
    char name[30];
    double price;
};

// Structure to represent an order
struct Order {
    int id;
    char item[30];
    double price;
};

// Function to print the menu
void printMenu(struct MenuItem menu[], int itemCount) {
    printf("Menu:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s ($%.2f)\n", i + 1, menu[i].name, menu[i].price);
    }
    printf("\n");
}

int main() {

    struct MenuItem menu[MAX_ITEMS]; // Cafe menu
    struct Order orders[MAX_ORDERS]; // Ordered items

    int itemCount = 0; // Number of items in the menu
    int orderCount = 0; // Number of orders placed today

    // Adding items to the menu
    strcpy(menu[itemCount].name, "Cappuccino");
    menu[itemCount].price = 3.99;
    itemCount++;

    strcpy(menu[itemCount].name, "Latte");
    menu[itemCount].price = 4.99;
    itemCount++;

    strcpy(menu[itemCount].name, "Espresso");
    menu[itemCount].price = 2.99;
    itemCount++;

    printMenu(menu, itemCount);

    // Taking orders
    char choice[30];

    do {
        // Displaying the menu and taking orders until user types "done"
        printf("Enter a menu item or type \"done\" to finish ordering: ");
        fgets(choice, 30, stdin);

        if (strcmp(choice, "done\n") != 0) {
            // Find the selected item in the menu and add it to orders array
            int itemIndex = -1;
            for (int i = 0; i < itemCount; i++) {
                // Compare the entered string to name of menu items
                if (strcmp(choice, menu[i].name) == 0) {
                    itemIndex = i;
                    break;
                }
            }

            if (itemIndex != -1) {
                // Add the selected item to the order and increment number of orders
                strcpy(orders[orderCount].item, menu[itemIndex].name);
                orders[orderCount].price = menu[itemIndex].price;
                orders[orderCount].id = orderCount + 1;
                orderCount++;
            }
            else {
                printf("Invalid choice. Please try again.\n");
            }
        }
    } while (strcmp(choice, "done\n") != 0);

    // Printing the bill
    double total = 0;
    printf("\n\n\n");
    printf("************************************\n");
    printf("Your Order:\n");
    printf("************************************\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%d. %s \t $%.2f\n", orders[i].id, orders[i].item, orders[i].price);
        total += orders[i].price;
    }
    printf("************************************\n");
    printf("Total: \t\t $%.2f\n", total);
    printf("************************************\n");

    return 0;
}