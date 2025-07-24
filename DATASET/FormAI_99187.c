//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>

int main() {

    float current_price = 1729.43;
    float opening_price = 1700.60;
    char company_name[] = "XYZ Corp.";
    int shares_owned = 1000;
    float total_value = current_price * shares_owned;

    printf("************************************\n");
    printf("    %s STOCK MARKET TRACKER\n", company_name);
    printf("************************************\n");
    printf("\n");

    printf("Opening Price: $%.2f\n", opening_price);
    printf("Current Price: $%.2f\n", current_price);
    printf("Number of Shares Owned: %d\n", shares_owned);
    printf("Total Value: $%.2f\n", total_value);
    printf("\n");

    printf("********** PRICE MOVEMENT **********\n");
    printf("\n");

    // Simulate price fluctuations
    float price_movement[] = {0.75, -1.25, 1.50, -2.00, 1.25, 0.50, -0.25, 0.75, -1.00, 2.50};

    for (int i = 0; i < 10; i++) {
        current_price += price_movement[i];
        total_value = current_price * shares_owned;

        printf("Price Movement #%d: %.2f%%\n", i+1, price_movement[i]);
        printf("Current Price: $%.2f\n", current_price);
        printf("Total Value: $%.2f\n", total_value);

        if (current_price >= opening_price) {
            printf("Price Change: +%.2f%%\n", (current_price - opening_price) / opening_price * 100);
        } else {
            printf("Price Change: -%.2f%%\n", (opening_price - current_price) / opening_price * 100);
        }

        printf("\n");

        // Simulate delay (in milliseconds)
        for (int j = 0; j < 100000000; j++) {}
    }

    printf("************************************\n");
    printf("    END OF %s STOCK MARKET TRACKER\n", company_name);
    printf("************************************\n");

    return 0;
}