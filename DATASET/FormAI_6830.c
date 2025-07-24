//FormAI DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i, j, k, n;
  float stock[10000];
  float max_gain = 0, max_loss = 0, current_gain, current_loss;
  srand(time(0));
  
  printf("Enter the number of days to track: ");
  scanf("%d", &n);
  
  printf("\n");
  
  for(i=0; i<n; i++) {
    stock[i] = (rand() % 1000) / 100.0;
    printf("Day %d: $%.2f\n", i+1, stock[i]);
  }
  
  printf("\n");
  
  for(i=0; i<n; i++) {
    for(j=i+1; j<n; j++) {
      current_gain = stock[j] - stock[i];
      current_loss = stock[i] - stock[j];
      if(current_gain > max_gain)
        max_gain = current_gain;
      if(current_loss > max_loss)
        max_loss = current_loss;
    }
  }
  
  printf("Maximum gain possible: $%.2f\n", max_gain);
  printf("Maximum loss possible: $%.2f\n", max_loss);
  
  return 0;
}