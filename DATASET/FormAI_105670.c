//FormAI DATASET v1.0 Category: Stock market tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if stock is crashing
int is_stock_crashing(float current_price, float prev_price) {
  float percent_drop = (prev_price - current_price) / prev_price * 100;
  if (percent_drop >= 10) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  float current_price = 100.00;
  float prev_price = 110.00;
  int crash_alert = 0;
  
  // Setting seed for random fluctuations in stock price
  srand(time(NULL));
  
  while(1) {
    // Random fluctuation in stock price up to +/- 5%
    float fluctuation = ((float)rand() / RAND_MAX) * 0.1 - 0.05;
    current_price += current_price * fluctuation;
    // Checking if stock is crashing
    if (is_stock_crashing(current_price, prev_price)) {
      crash_alert = 1;
    }
    // Printing current stock price and crash alert
    printf("Current stock price: $%.2f\n", current_price);
    if (crash_alert) {
      printf("ALERT: Stock is crashing!\n");
    }
    prev_price = current_price;
    // Delay for dramatic effect
    for (int i = 0; i < 100000000; i++) {}
  }
  
  return 0;
}