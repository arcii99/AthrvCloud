//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define global constants for item prices
const float COFFEE_PRICE = 2.50;
const float TEA_PRICE = 2.00;
const float HOT_CHOCOLATE_PRICE = 3.00;
const float TOAST_PRICE = 2.00;
const float CROISSANT_PRICE = 1.50;

// Define function prototypes
void printMenu();
float calculateTotalBill(int coffee, int tea, int hotChocolate, int toast, int croissant);

int main() {
    int coffeeQuantity = 0;
    int teaQuantity = 0;
    int hotChocolateQuantity = 0;
    int toastQuantity = 0;
    int croissantQuantity = 0;

    char orderInput[256];

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please place your order by typing the item names and quantities separated by spaces. Type 'done' to finish your order and calculate the total bill.\n");

    printMenu();

    while (1) {
        printf("Order: ");

        if (fgets(orderInput, sizeof(orderInput), stdin) == NULL) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (strcmp(orderInput, "done\n") == 0) {
            break;
        }

        char *itemName = strtok(orderInput, " ");
        char *itemQuantity = strtok(NULL, " \n");

        if (itemName == NULL || itemQuantity == NULL) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (strcmp(itemName, "coffee") == 0) {
            int quantity = atoi(itemQuantity);
            coffeeQuantity += quantity;
        } else if (strcmp(itemName, "tea") == 0) {
            int quantity = atoi(itemQuantity);
            teaQuantity += quantity;
        } else if (strcmp(itemName, "hotchocolate") == 0) {
            int quantity = atoi(itemQuantity);
            hotChocolateQuantity += quantity;
        } else if (strcmp(itemName, "toast") == 0) {
            int quantity = atoi(itemQuantity);
            toastQuantity += quantity;
        } else if (strcmp(itemName, "croissant") == 0) {
            int quantity = atoi(itemQuantity);
            croissantQuantity += quantity;
        } else {
            printf("Invalid item name. Please try again.\n");
            continue;
        }
    }

    float totalBill = calculateTotalBill(coffeeQuantity, teaQuantity, hotChocolateQuantity, toastQuantity, croissantQuantity);
    printf("\nTotal Bill: $%.2f\n\n", totalBill);

    return EXIT_SUCCESS;
}

void printMenu() {
    printf("\nMenu:\n");
    printf(" - Coffee ($%.2f)\n", COFFEE_PRICE);
    printf(" - Tea ($%.2f)\n", TEA_PRICE);
    printf(" - Hot Chocolate ($%.2f)\n", HOT_CHOCOLATE_PRICE);
    printf(" - Toast ($%.2f)\n", TOAST_PRICE);
    printf(" - Croissant ($%.2f)\n\n", CROISSANT_PRICE);
}

float calculateTotalBill(int coffee, int tea, int hotChocolate, int toast, int croissant) {
    float totalBill = coffee * COFFEE_PRICE + tea * TEA_PRICE + hotChocolate * HOT_CHOCOLATE_PRICE + toast * TOAST_PRICE + croissant * CROISSANT_PRICE;
    return totalBill;
}