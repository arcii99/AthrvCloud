//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    
    float stockPrice;
    float prevPrice;
    float priceChange;
    
    printf("Enter the current stock price: ");
    scanf("%f", &stockPrice);
    printf("Enter the previous stock price: ");
    scanf("%f", &prevPrice);
    
    priceChange = ((stockPrice - prevPrice)/prevPrice) * 100;
    
    if(priceChange > 0) {
        printf("The stock price has increased by %.2f%%\n", priceChange);
    }
    else if(priceChange == 0) {
        printf("The stock price has not changed.\n");
    }
    else {
        printf("The stock price has decreased by %.2f%%\n", priceChange);
    }
    
    return 0;
}