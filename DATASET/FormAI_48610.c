//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct menu {
    char item[25];
    int price;
};

int main() {
    int i, j, ch, total = 0, quantity;
    printf("Welcome to C Cafe!\n");
    printf("Today's Menu\n");
    struct menu m[5] = {
        {"Coffee", 50},
        {"Tea", 30},
        {"Sandwich", 80},
        {"Burger", 100},
        {"Cake", 60}
    };
    printf("------------------------\n");
    printf("Item\t\tPrice\n");
    printf("------------------------\n");
    for (i = 0; i < 5; i++) {
        printf("%s\t\t%d\n", m[i].item, m[i].price);
    }
    printf("------------------------\n");
    do {
        printf("\nEnter the item number you want to order: ");
        scanf("%d", &ch);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        total += (m[ch-1].price * quantity);
        printf("\n%s (Quantity: %d) added to the cart\n", m[ch-1].item, quantity);
        printf("Do you want to order anything else? (Yes->1, No->0): ");
        scanf("%d", &j);
    } while (j);
    printf("Total bill amount = %d\n", total);
    printf("Thank you for visiting C Cafe!\n");
    return 0;
}