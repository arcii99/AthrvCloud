//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item {
    char itemName[100];
    float itemPrice;
    int itemQuantity;
};

int main()
{
    int numberOfItems, i;
    struct item items[100];

    printf("Enter the number of items in the warehouse: ");
    scanf("%d", &numberOfItems);

    for (i = 0; i < numberOfItems; ++i) {
        printf("\nEnter the name of the item #%d: ", i+1);
        scanf("%s", items[i].itemName);

        printf("Enter the price of the item #%d: ", i+1);
        scanf("%f", &items[i].itemPrice);

        printf("Enter the quantity of the item #%d: ", i+1);
        scanf("%d", &items[i].itemQuantity);
    }

    printf("\n\t\t\t\t\tWAREHOUSE INVENTORY");
    printf("\n-----------------------------------------------------------------------------------");
    printf("\n| Item Name\t| Price\t\t| Quantity\t| Value\t\t|");
    printf("\n-----------------------------------------------------------------------------------");

    float totalValue = 0;
    for (i = 0; i < numberOfItems; ++i) {
        float value = items[i].itemPrice * items[i].itemQuantity;
        printf("\n| %s\t| %0.2f\t| %d\t\t| %0.2f\t\t|", items[i].itemName, items[i].itemPrice, items[i].itemQuantity, value);
        totalValue += value;
    }

    printf("\n-----------------------------------------------------------------------------------");
    printf("\nTotal Warehouse Value:\t\t\t\t%0.2f\n", totalValue);

    return 0;
}