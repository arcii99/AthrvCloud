//FormAI DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>

int main() {
    float stock_price, total_value;
    int num_shares;

    printf("Enter the current stock price: ");
    scanf("%f", &stock_price);

    printf("Enter the number of shares owned: ");
    scanf("%d", &num_shares);

    total_value = stock_price * num_shares;

    printf("The total value of your investments in this stock is $%.2f\n", total_value);

    return 0;
}