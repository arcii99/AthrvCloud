//FormAI DATASET v1.0 Category: Stock market tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// define maximum price change
#define MAX_PRICE_CHANGE 0.05

// function to randomly generate price change
float genPriceChange()
{
    return (float)rand()/(float)(RAND_MAX) * MAX_PRICE_CHANGE;
}

// function to simulate stock price change
void simulateStock(char* stock_name, float* price, bool* market_closed)
{
    // loop until market is closed
    while(!(*market_closed))
    {
        // randomly generate price change
        float price_change = genPriceChange();
        
        // randomly choose direction of price change
        bool price_direction = rand()%2;
        
        // update price based on direction and change amount
        if(price_direction == 0)
        {
            (*price) -= price_change;
        }
        else
        {
            (*price) += price_change;
        }
        
        // print out updated stock price
        printf("%s: $%.2f\n", stock_name, *price);
        
        // wait 1 second before next update
        sleep(1);
    }
    
    // market is closed, print message
    printf("Market closed for %s\n", stock_name);
}

int main()
{
    // initialize random seed
    srand(time(NULL));
    
    // initialize stock prices
    float goog_price = 1000.00;
    float aapl_price = 150.00;
    
    // initialize market status
    bool market_closed = false;
    
    // create two threads to simulate each stock
    #pragma omp parallel num_threads(2)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                simulateStock("GOOG", &goog_price, &market_closed);
            }
            #pragma omp section
            {
                simulateStock("AAPL", &aapl_price, &market_closed);
            }
        }
    }
    
    // print final stock prices
    printf("Final Stock Prices:\n");
    printf("GOOG: $%.2f\n", goog_price);
    printf("AAPL: $%.2f\n", aapl_price);
    
    return 0;
}