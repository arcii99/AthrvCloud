//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char itemName[30];
    int itemQuantity;
    float itemPrice;
} Item;

Item menu[] = {{"Espresso", 10, 1.50}, {"Latte", 15, 2.50}, {"Cappuccino", 8, 2.00}, {"Mocha", 5, 2.75}, {"Americano", 12, 2.25}};
int menuSize = sizeof(menu) / sizeof(menu[0]);

float calculateTotal(Item purchased[], int size);
void printBill(Item purchased[], int size);

int main() {
    printf("\tWelcome to The Irregular Cafe!\n");
    printf("Here is our menu:\n");
    printf("\tItem Name\t\t| Quantity Available\t| Price\n");
    for (int i = 0; i < menuSize; i++) {
        printf("\t%-20s\t| %04d\t\t\t| $%.2f\n", menu[i].itemName, menu[i].itemQuantity, menu[i].itemPrice);
    }
    
    printf("\n");
    int orderSize;
    do {
        printf("How many items would you like to order? (Maximum 5): ");
        char input[2];
        fgets(input, sizeof(input), stdin);
        orderSize = atoi(input);
    } while (orderSize < 1 || orderSize > 5);

    Item order[orderSize];
    int orderIndex = 0;
    while (orderIndex < orderSize) {
        printf("Please enter the name of item %d: ", orderIndex+1);
        char input[30];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        int found = 0;
        for (int i = 0; i < menuSize; i++) {
            if (strcmp(input, menu[i].itemName) == 0) {
                found = 1;
                if (menu[i].itemQuantity < 1) {
                    printf("Sorry, we are currently out of stock of %s.\n", menu[i].itemName);
                    continue;
                }
                order[orderIndex] = menu[i];
                menu[i].itemQuantity--;
                break;
            }
        }

        if (!found) {
            printf("Sorry, %s is not on our menu.\n", input);
            continue;
        }

        orderIndex++;
    }

    printf("\n\nDING DING DING! Your order is complete. Here is your bill:\n");
    printBill(order, orderSize);

    float total = calculateTotal(order, orderSize);

    printf("\nYour total comes to: $%.2f. How will you be paying today?\n", total);

    printf("Thank you for visiting The Irregular Cafe! Please come again soon.\n");

    return 0;
}

float calculateTotal(Item purchased[], int size) {
    float total = 0.0;

    for (int i = 0; i < size; i++) {
        total += purchased[i].itemPrice;
    }

    return total;
}

void printBill(Item purchased[], int size) {
    printf("+=====%20s=======+==========+=======+\n", "Menu Item");
    printf("| %20s | %8s | %5s |\n", "", "Quantity", "Price");
    printf("+=====%20s=======+==========+=======+\n", "==================");
    for (int i = 0; i < size; i++) {
        printf("| %20s | %8d | $%4.2f |\n", purchased[i].itemName, purchased[i].itemQuantity, purchased[i].itemPrice);
    }
    printf("+=====%20s=======+==========+=======+\n", "==================");
}