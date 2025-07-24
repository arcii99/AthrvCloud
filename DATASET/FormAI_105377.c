//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float current_price = 0.0;
    float percent_change = 0.0;

    printf("Enter the current price of the stock: ");
    scanf("%f", &current_price);

    printf("Enter the percentage change in the stock: ");
    scanf("%f", &percent_change);

    float new_price = current_price * (1 + percent_change / 100);

    printf("The new price of the stock is: %.2f\n", new_price);

    if (percent_change >= 0)
    {
        printf("The stock is up by %.2f%%\n", percent_change);
    }
    else
    {
        printf("The stock is down by %.2f%%\n", percent_change);
    }

    return 0;
}