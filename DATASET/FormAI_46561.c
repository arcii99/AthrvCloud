//FormAI DATASET v1.0 Category: Data mining ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order {
    int customerId;
    char itemName[20];
    float price;
};

int main() {
    struct Order orders[5];
    float totalSales = 0;
    int itemCount = 0;
    for (int i = 0; i < 5; i++) {
        printf("Enter customer ID: ");
        scanf("%d", &orders[i].customerId);
        printf("Enter item name: ");
        scanf("%s", orders[i].itemName);
        printf("Enter price in dollars: ");
        scanf("%f", &orders[i].price);
        totalSales += orders[i].price;
        itemCount++;
    }
    printf("\nTotal sales: $%.2f\n", totalSales);

    // Find the item that sold the most
    char maxItem[20] = "";
    float maxItemSales = 0;
    for (int i = 0; i < 5; i++) {
        float itemSales = 0;
        for (int j = 0; j < 5; j++) {
            if (strcmp(orders[j].itemName, orders[i].itemName) == 0) {
                itemSales += orders[j].price;
            }
        }
        if (itemSales > maxItemSales) {
            maxItemSales = itemSales;
            strcpy(maxItem, orders[i].itemName);
        }
    }
    printf("Most popular item: %s ($%.2f sold)\n", maxItem, maxItemSales);

    // Find the average order value
    float avgOrderValue = totalSales / itemCount;
    printf("Average order value: $%.2f\n", avgOrderValue);

    return 0;
}