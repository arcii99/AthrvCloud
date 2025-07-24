//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize variables
  int stockPrice = 100;
  int change;
  int day = 1;
  char trend;

  // seed random number generator
  srand(time(NULL));

  // print header
  printf("%-5s %-10s %-10s %-10s\n", "DAY", "ACTION", "CHANGE", "PRICE");
  printf("%-5s %-10s %-10s %-10s\n", "---", "------", "------", "-----");

  // generate stock market movements for 30 days
  while (day <= 30) {
    change = rand() % 21 - 10;  // random change between -10 and 10

    if (change > 0)
      trend = '+';
    else if (change < 0)
      trend = '-';
    else
      trend = ' ';

    // update stock price with change
    stockPrice += change;

    // print daily movement
    printf("%-5d %-10c %-+9d %-10d\n", day, trend, abs(change), stockPrice);

    day++;
  }

  return 0;
}