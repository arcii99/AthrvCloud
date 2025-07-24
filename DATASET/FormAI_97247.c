//FormAI DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include<stdio.h>

int main(){

  printf("Welcome to the Stock Market Tracker!\n\n");

  float stock1, stock2, stock3, stock4, stock5, sum;

  printf("Enter the stock price for Stock 1: ");
  scanf("%f", &stock1);

  printf("Enter the stock price for Stock 2: ");
  scanf("%f", &stock2);

  printf("Enter the stock price for Stock 3: ");
  scanf("%f", &stock3);

  printf("Enter the stock price for Stock 4: ");
  scanf("%f", &stock4);

  printf("Enter the stock price for Stock 5: ");
  scanf("%f", &stock5);

  sum = stock1 + stock2 + stock3 + stock4 + stock5;

  printf("\nCurrent Value of the Stock Portfolio: %f\n", sum);

  printf("\nThank you for using the Stock Market Tracker! Happy Investing!\n");

  return 0;

}