//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cafe_Order
{
    char item[20];
    float price;
    int quantity;
    float total;
};

int main()
{
    printf("Welcome to Cafe Billing System!\n");

    int n;
    printf("Enter the number of orders: ");
    scanf("%d", &n);

    struct Cafe_Order orders[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nOrder %d:\n", i + 1);
        printf("Enter item name: ");
        scanf("%s", &orders[i].item);
        printf("Enter item price: ");
        scanf("%f", &orders[i].price);
        printf("Enter item quantity: ");
        scanf("%d", &orders[i].quantity);
        orders[i].total = orders[i].price * orders[i].quantity;
    }

    printf("\n=====================================================\n");
    printf("\t\t\t\tCafe Bill\n");
    printf("=====================================================\n");
    printf("Item\t\tPrice\t\tQuantity\tTotal\n");
    printf("=====================================================\n");

    float total = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%.2f\t\t%d\t\t%.2f\n", orders[i].item, orders[i].price, orders[i].quantity, orders[i].total);
        total += orders[i].total;
    }

    printf("=====================================================\n");
    printf("\t\t\t\tTotal: %.2f\n", total);

    printf("\nThank you for choosing our cafe!\n");

    return 0;
}