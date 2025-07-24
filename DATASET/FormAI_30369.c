//FormAI DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // Seeds the random number generator with the current system time
    
    float stock_price = 1000.00;
    float previous_price = stock_price;
    float range = 50.00; // Price range for each fluctuation
    float max_increase = 5.00; // Maximum percentage increase for each price movement
    float max_decrease = 3.00; // Maximum percentage decrease for each price movement
    int counter = 0;
    
    printf("Initial stock price: $%.2f\n", stock_price);
    
    while (counter < 10)
    {
        float rand_num = ((float)rand()/(float)(RAND_MAX)) * range; // Generates random number between 0 and range
        int sign = rand() % 2 == 0 ? 1 : -1; // Randomly determines whether the price should increase or decrease
        float percentage_change = ((float)rand()/(float)(RAND_MAX)) * sign * (sign > 0 ? max_increase : max_decrease); // Randomly generates percentage change
        float absolute_change = stock_price * percentage_change / 100; // Calculates absolute price change
        stock_price += absolute_change; // Modifies the stock price based on the percentage change
        
        printf("Stock price (after %dth movement): $%.2f (%c%.2f%%)\n", counter, stock_price, sign > 0 ? '+' : '-', percentage_change);
        
        if (stock_price < 0) // If the stock price goes negative, terminate the program
        {
            printf("Stock price has gone negative. Exiting program.\n");
            break;
        }
        
        if ((previous_price > stock_price && previous_price - stock_price > range) || (previous_price < stock_price && stock_price - previous_price > range)) // If the stock price moves by more than the range, reset the range
        {
            printf("Price movement has exceeded range. Resetting range and starting again.\n");
            range = 50.00;
            previous_price = stock_price;
            counter = 0;
        }
        else // Otherwise, increment the counter and reduce the range
        {
            counter++;
            range -= 5.00;
            previous_price = stock_price;
        }
    }
    
    printf("Final stock price: $%.2f\n", stock_price);
    
    return 0;
}