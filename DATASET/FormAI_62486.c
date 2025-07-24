//FormAI DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>

int main() {
  int stocks[5] = {100, 200, 350, 75, 500};
  int total = 0;
  
  printf("Welcome to the cheerful C Stock Market Tracker!\n");
  printf("***********************************************\n");
  
  for (int i = 0; i < 5; i++) {
    printf("Today's stock value for Company %d is $%d.\n", i+1, stocks[i]);
    total += stocks[i];
  }
  
  printf("The total value of all 5 companies is $%d.\n", total);
  
  if (total > 1000) {
    printf("Looks like the market is up today! Happy investing!\n");
  } else {
    printf("The market may be down today, but don't worry - there's always tomorrow!\n");
  }
  
  return 0;
}