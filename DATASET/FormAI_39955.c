//FormAI DATASET v1.0 Category: Stock market tracker ; Style: optimized
#include<stdio.h>

int main()
{
    float stocks[5] = {10.5, 30.2, 25.8, 40.2, 15.9}; // Initializing stock prices
    float sum = 0, avg, max = stocks[0], min = stocks[0]; // Initializing variables with default values

    // Loop to calculate sum, max and min
    for(int i=0; i<5; i++)
    {
        sum += stocks[i]; // calculating sum
        if(stocks[i]>max)
            max = stocks[i]; // finding max value
        if(stocks[i]<min)
            min = stocks[i]; // finding min value
    }

    avg = sum/5; // calculating average

    // Displaying the calculated values
    printf("The sum of stock prices is: %.2f\n", sum);
    printf("The average stock price is: %.2f\n", avg);
    printf("The maximum stock price is: %.2f\n", max);
    printf("The minimum stock price is: %.2f\n", min);

    return 0;
}