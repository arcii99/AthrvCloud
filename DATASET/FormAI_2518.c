//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int numItems;
    float totalCost = 0;

    printf("Welcome to Ken's Cafe Billing System.\n");
    printf("Please enter the number of items you have ordered: ");
    scanf("%d", &numItems);

    char items[numItems][50];
    float prices[numItems];

    for (int i=0; i<numItems; i++) {
        printf("Enter the name of the item: ");
        scanf("%s", items[i]);
        printf("Enter the price of the item: ");
        scanf("%f", &prices[i]);
        totalCost += prices[i];
    }

    printf("\nKen's Cafe Bill: \n\n");
    
    for (int i=0; i<numItems; i++) {
        printf("%s: $%.2f\n", items[i], prices[i]);
    }

    printf("\nTotal cost: $%.2f\n", totalCost);

    return 0;
}