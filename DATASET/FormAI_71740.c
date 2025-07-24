//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char menu[50][50] = {"Cappuccino", "Espresso", "Latte", "Mocha", "Americano", "Macchiato", "Tea", "Hot Chocolate", "Smoothie", "Juice"};
    int price[50] = {150, 100, 130, 170, 120, 140, 80, 100, 180, 70};
    int quantity[50];
    int total = 0, choice, qty, i;

    printf("\t\tWelcome to Linux Cafe\n\n");

    printf("Menu:\n");
    for (i = 0; i < 10; i++) {
        printf("%d. %-15s Rs.%d\n", i + 1, menu[i], price[i]);
    }

    while (1) {
        printf("\nEnter your choice (Press 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("\n\nYour total bill is: Rs. %d\n", total);
            printf("Thank you for visiting Linux Cafe!\n\n");
            break;
        }

        if (choice < 0 || choice > 10) {
            printf("Invalid Choice!\n\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &qty);

        total += (qty * price[choice - 1]);
        quantity[choice - 1] += qty;
    }

    return 0;
}