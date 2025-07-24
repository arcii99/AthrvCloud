//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>

int main() {
  
  float stock_price; //variable to hold the stock price
  float previous_price; //variable to hold the previous stock price
  float change; //variable to hold the change in stock price
  float percent_change; //variable to hold the percentage change in stock price
  
  printf("Enter the current stock price: ");
  scanf("%f", &stock_price); //taking input for the current stock price
  
  printf("Enter the previous stock price: ");
  scanf("%f", &previous_price); //taking input for the previous stock price
  
  change = stock_price - previous_price; //calculate the change in stock price
  percent_change = (change / previous_price) * 100; //calculate the percentage change in stock price
  
  printf("\n\nThe current stock price is: %.2f", stock_price);
  printf("\nThe previous stock price was: %.2f", previous_price);
  printf("\nThe change in stock price is: %.2f", change);
  printf("\nThe percentage change in stock price is: %.2f%%", percent_change);
  
  //apply conditional logic to determine whether the stock is up or down
  if(change > 0){
      printf("\n\nThe stock is up today!");
  }
  else if(change < 0){
      printf("\n\nThe stock is down today!");
  }
  else{
      printf("\n\nThe stock price remains unchanged!");
  }

  return 0;
}