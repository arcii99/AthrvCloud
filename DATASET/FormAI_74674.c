//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include<stdio.h>
#include<string.h>

//function to calculate the average of the array elements
float average(float arr[], int size){
    float sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    return sum/size;
}

//function to calculate the variance of the array elements
float variance(float arr[], int size, float avg){
    float var = 0;
    for(int i=0; i<size; i++){
        var += (arr[i]-avg)*(arr[i]-avg);
    }
    return var/size;
}

//function to calculate the standard deviation of the array elements
float stdev(float var){
    return sqrt(var);
}

//main function
int main(){
    //declare an array to hold the stock prices
    float stock_prices[5];
    //ask the user to input the stock prices
    printf("Enter the stock prices for the week:\n");
    for(int i=0; i<5; i++){
        scanf("%f", &stock_prices[i]);
    }
    //calculate the average of the stock prices
    float avg = average(stock_prices, 5);
    //calculate the variance of the stock prices
    float var = variance(stock_prices, 5, avg);
    //calculate the standard deviation of the stock prices
    float st_dev = stdev(var);
    //print the result
    printf("Average price: $%.2f\n", avg);
    printf("Variance: %.2f\n", var);
    printf("Standard deviation: %.2f\n", st_dev);
    return 0;
}