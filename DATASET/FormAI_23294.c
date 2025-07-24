//FormAI DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int current_price = 100;
    int previous_price = 90;
    int change = current_price - previous_price;

    printf("My dearest stock market tracker,\n");
    printf("I hope this letter finds you well and profitable.\n");

    printf("Today, the stock market has been quite adventurous.\n");
    printf("The current price of my favorite stock is $%d.\n", current_price);
    printf("This is a %d dollar change from the previous price of $%d.\n", change, previous_price);

    if (change > 0) {
        printf("Although my heart is heavy, I am thrilled to see that the stock has risen.\n");
        printf("I have high hopes for its continued success.\n");
    } else if (change < 0) {
        printf("My dear, my heart has been struck with sadness with this drop in the stock price.\n");
        printf("I feel as if all is lost, but I hope for a speedy recovery.\n");
    } else {
        printf("I am perplexed, as there has been no change in the stock price.\n");
        printf("I hope for some excitement in the market soon.\n");
    }

    printf("My love for stock market tracking grows stronger every day.\n");
    printf("Till we meet again, my dear tracker.\n");

    return 0;
}