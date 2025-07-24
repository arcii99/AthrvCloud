//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct billing {
    char name[50];
    int quantity;
    float price;
};

float total_bill(struct billing bills[], int num) {
    float total = 0.0;
    for (int i = 0; i < num; i++) {
        total += bills[i].price * bills[i].quantity;
    }
    return total;
}

int main() {
    struct billing bills[50];
    int num_items, i;

    printf("Welcome to Cafe XYZ!\n");
    printf("How many items would you like to order? ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter item name: ");
        scanf("%s", bills[i].name);
        printf("Enter item quantity: ");
        scanf("%d", &bills[i].quantity);
        printf("Enter item price: ");
        scanf("%f", &bills[i].price);
    }

    printf("\n-------------------------\n");
    printf("  Cafe XYZ BILLING SYSTEM\n");
    printf("-------------------------\n");
    printf("Item Name\tQuantity\tPrice\n");
    for (i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t\t%.2f\n", bills[i].name, bills[i].quantity, bills[i].price);
    }
    printf("\nTotal bill: %.2f\n", total_bill(bills, num_items));

    return 0;
}