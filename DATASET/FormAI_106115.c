//FormAI DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initialize random number generator with current time
  double stockPrice = 100.00; //initialize stock price variable to $100.00
  
  for (int i = 0; i < 50; i++) { //simulate 50 days of trading
    double change = (double)rand() / (double)RAND_MAX; //generate a random number between 0 and 1
    if (change < 0.5) { //if the number is less than 0.5, subtract from the stock price
      stockPrice -= change * 10.00; //subtract a random amount between 0 and $10.00
    } else { //if the number is greater than or equal to 0.5, add to the stock price
      stockPrice += change * 10.00; //add a random amount between 0 and $10.00
    }
    
    printf("Day %d: $%.2lf\n", i+1, stockPrice); //print the current day and stock price
  }
  
  return 0; //exit the program
}