//FormAI DATASET v1.0 Category: Stock market tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize variables for stock prices
  float stockA = 10.0;
  float stockB = 15.0;
  float stockC = 20.0;
  
  // initialize variables for day count and current time
  int days = 0;
  time_t currentTime;
  
  // generate random seed based on current time
  srand((unsigned) time(&currentTime));
  
  // print initial stock prices
  printf("Day %d - Stock A: %.2f, Stock B: %.2f, Stock C: %.2f\n", days, stockA, stockB, stockC);
  
  // initialize variable for disaster probability
  int disasterProbability = 0;
  
  while (days < 365) { // simulate 1 year of trading
    
    // randomly generate disaster probability
    disasterProbability = rand() % 100 + 1;
    
    // simulate stock fluctuations
    stockA += ((float) rand() / RAND_MAX - 0.5) * 3;
    if (stockA < 0) stockA = 0;
    stockB += ((float) rand() / RAND_MAX - 0.5) * 4;
    if (stockB < 0) stockB = 0;
    stockC += ((float) rand() / RAND_MAX - 0.5) * 5;
    if (stockC < 0) stockC = 0;
    
    // check for disaster
    if (disasterProbability > 90) { // 10% chance of disaster
      printf("Day %d - DISASTER STRIKES!\n", days);
      stockA *= 0.5;
      if (stockA < 0) stockA = 0;
      stockB *= 0.5;
      if (stockB < 0) stockB = 0;
      stockC *= 0.5;
      if (stockC < 0) stockC = 0;
    }
    
    // print current stock prices
    printf("Day %d - Stock A: %.2f, Stock B: %.2f, Stock C: %.2f\n", days, stockA, stockB, stockC);
    
    // increment day count
    days++;
  }
  
  // print final stock prices
  printf("1 Year Later - Stock A: %.2f, Stock B: %.2f, Stock C: %.2f\n", stockA, stockB, stockC);
  
  return 0;
}