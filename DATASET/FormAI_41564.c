//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>

int main(void) {
  // Declare stock variables
  float apple_stock = 135.28;
  float tesla_stock = 678.90;
  float microsoft_stock = 244.87;

  // Set starting date
  int day = 1;
  int month = 1;
  int year = 2022;
  
  // Loop through 30 days
  for(int i=0; i<30; i++) {
    // Print date and stock prices
    printf("Date: %d/%d/%d\n", day, month, year);
    printf("Apple Stock: $%.2f\n", apple_stock);
    printf("Tesla Stock: $%.2f\n", tesla_stock);
    printf("Microsoft Stock: $%.2f\n\n", microsoft_stock);
    
    // Randomly pick a stock to increase or decrease by 1-5%
    int random = rand() % 3;
    float percentage = (float)(rand() % 5 + 1) / 100; // 1-5%
    switch(random) {
      case 0:
        apple_stock *= (1 + percentage);
        break;
      case 1:
        tesla_stock *= (1 - percentage);
        break;
      case 2:
        microsoft_stock *= (1 + percentage);
        break;
    }
    
    // Increase date by one day
    day++;
    if(day > 31) {
      day = 1;
      month++;
    }
    if(month > 12) {
      month = 1;
      year++;
    }
  }
  
  return 0;
}