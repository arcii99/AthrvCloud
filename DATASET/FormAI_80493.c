//FormAI DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>

int main() {
  float stockPriceC = 50.99;
  float stockPriceG = 80.45;
  float stockPriceA = 125.67;
  float stockPriceD = 20.98;
  
  printf("Stock Market Tracker: \n\n");
  
  while(1) {
    char input;
    
    printf("Enter a company symbol (C, G, A, or D) to get the stock price: ");
    scanf(" %c", &input);
    
    switch(input) {
      case 'C':
        printf("Stock Price for Company C: $%.2f\n\n", stockPriceC);
        break;
      case 'G':
        printf("Stock Price for Company G: $%.2f\n\n", stockPriceG);
        break;
      case 'A':
        printf("Stock Price for Company A: $%.2f\n\n", stockPriceA);
        break;
      case 'D':
        printf("Stock Price for Company D: $%.2f\n\n", stockPriceD);
        break;
      default:
        printf("Invalid symbol entered. Please enter either C, G, A, or D.\n\n");
        continue;
    }
    
    printf("Press enter to get updated stock prices.\n");
    getchar();
  }
  
  return 0;
}