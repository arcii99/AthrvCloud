//FormAI DATASET v1.0 Category: Stock market tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, l, m, n;
    double stock_prices[5][5] = {
        {29.3, 28.5, 29.6, 32.9, 33.8},
        {27.9, 29.4, 31.1, 30.7, 29.3},
        {26.8, 27.9, 27.2, 28.6, 27.8},
        {29.1, 28.8, 28.3, 29.4, 28.5},
        {27.3, 26.1, 27.1, 28.4, 29.3}
    };
    
    printf("\n\n **** Welcome to the Stock Market Tracker ****\n\n");
    
    //Generating random stock prices for the day
    
    srand(time(NULL));
    
    for(n = 0; n < 5; n++) {
        for(m = 0; m < 5; m++) {
            stock_prices[n][m] += (rand()%8 - 4) / 10.0;
        }
    }
    
    // Printing the stock prices for the day
    
    printf("\n\n ------------ Today's Stock Prices ------------\n\n");
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%.2lf ", stock_prices[i][j]);
        }
        printf("\n");
    }
    
    //Calculating the mean, median, and mode of the stock prices
    
    double sum, mean = 0.0, median, mode = 0.0;
    int count = 0, max_count = 0;
    
    for(k = 0; k < 5; k++) {
        for(l = 0; l < 5; l++) {
            sum += stock_prices[k][l];
            count++;
        }
    }
    
    mean = sum / count;
    
    double values[25];
    int index = 0;
    
    for(k = 0; k < 5; k++) {
        for(l = 0; l < 5; l++) {
            values[index] = stock_prices[k][l];
            index++;
        }
    }
    
    //Sorting the values array
    
    for(i = 0; i < 24; i++) {
        for(j = i+1; j < 25; j++) {
            if(values[j] < values[i]) {
                double temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    
    //Calculating the median
    
    median = (values[12] + values[13]) / 2;
    
    //Calculating the mode
    
    for(i = 0; i < 25; i++) {
        count = 0;
        for(j = 0; j < 25; j++) {
            if(values[i] == values[j]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            mode = values[i];
        }
    }
    
    //Printing the results
    
    printf("\n\n ------------ Analysis of Stock Prices ------------\n\n");
    printf("Mean: %.2lf\n", mean);
    printf("Median: %.2lf\n", median);
    printf("Mode: %.2lf (%d times)\n", mode, max_count);
    
    printf("\n\n **** Thank you for using the Stock Market Tracker! ****\n\n");
    
    return 0;
}