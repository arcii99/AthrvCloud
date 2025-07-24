//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#define MAX_STOCKS 10

int main() {
    char stock_names[MAX_STOCKS][10] = {"AAPL", "GOOGL", "MSFT", "TSLA", "AMZN", "FB", "NVDA", "PYPL", "ADBE", "NFLX"};
    float current_price[MAX_STOCKS] = {156.15, 1425.00, 187.71, 607.80, 2039.87, 176.56, 506.76, 103.34, 522.78, 516.05};
    float previous_close[MAX_STOCKS] = {157.92, 1439.22, 185.23, 613.00, 2040.99, 173.15, 504.58, 101.05, 519.23, 511.29};
    int num_stocks = 10;

    printf("Welcome to the Stock Market Tracker!\n\n");

    while (1) {
        printf("Please enter the stock you want to track (or Q to quit):\n");
        char input[10];
        scanf("%s", input);

        if (input[0] == 'Q' || input[0] == 'q') {
            printf("Thank you for using the Stock Market Tracker!\n");
            break;
        }

        int index = -1;
        for (int i = 0; i < num_stocks; i++) {
            if (stock_names[i][0] == input[0] && stock_names[i][1] == input[1] && stock_names[i][2] == input[2] && stock_names[i][3] == input[3]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Invalid stock symbol\n");
            continue;
        }

        printf("%.2f is the current price of %s\n", current_price[index], stock_names[index]);

        float change = current_price[index] - previous_close[index];
        if (change > 0) {
            printf("The price has increased by %.2f\n", change);
        } else if (change < 0) {
            printf("The price has decreased by %.2f\n", -change);
        } else {
            printf("The price has not changed since the previous close.\n");
        }
    }

    return 0;
}