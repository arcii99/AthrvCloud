//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
 
  int arr[n];
  printf("Enter the elements: ");
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  int budget;
  printf("Enter the budget: ");
  scanf("%d", &budget);

  int max_profit = 0;
  for(int i=0; i<n-1 && budget>0; i++) {
    int item_profit = arr[i+1] - arr[i];
    if(item_profit > 0) {
      int quantity = budget / arr[i];
      max_profit += item_profit * quantity;
      budget -= arr[i] * quantity;
    }
  }

  printf("Maximum profit: %d", max_profit);
  return 0;
}