//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

struct Menu {
    char name[20];
    float price;
};

int main() {
    struct Menu items[10];
    strcpy(items[0].name, "Coffee");
    items[0].price = 1.50;
    strcpy(items[1].name, "Tea");
    items[1].price = 1.20;
    strcpy(items[2].name, "Sandwich");
    items[2].price = 2.50;
    strcpy(items[3].name, "Burger");
    items[3].price = 3.00;
    strcpy(items[4].name, "French Fries");
    items[4].price = 1.80;
    
    char order[20];
    float bill = 0;
    printf("Welcome to C Cafe Billing System\n");
    printf("Menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }
    printf("Enter your order (Enter 'done' to exit):\n");
    do {
        scanf("%s", order);
        for (int i = 0; i < 5; i++) {
            if (strcmp(order, items[i].name) == 0) {
                bill += items[i].price;
                printf("%s is added to your order. Your bill is now $%.2f\n", order, bill);
                break;
            }
        }
    } while (strcmp(order, "done") != 0);
    printf("Thank you for your order. Your total bill is $%.2f.\n", bill);
    return 0;
}