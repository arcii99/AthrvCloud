//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  return (a > b) ? a : b;
}

int recursiveFunction(int currentBag, int currCapacity, int bagSizes[], int n) {
  if (currCapacity == 0)
    return 1;
  if (currCapacity < 0 || currentBag >= n)
    return 0;
  int include = recursiveFunction(currentBag + 1, currCapacity - bagSizes[currentBag], bagSizes, n);
  int exclude = recursiveFunction(currentBag + 1, currCapacity, bagSizes, n);
  return max(include, exclude);
}

int main() {
  int n, capacity;
  printf("Enter the number of bags: ");
  scanf("%d", &n);
  int bagSizes[n];
  printf("Enter the size of each bag:\n");
  for (int i = 0; i < n; i++)
    scanf("%d", &bagSizes[i]);
  printf("Enter the capacity of the airplane: ");
  scanf("%d", &capacity);
  int result = recursiveFunction(0, capacity, bagSizes, n);
  if (result)
    printf("All bags can be accommodated in the airplane\n");
  else
    printf("Some bags cannot be put into the airplane due to lack of space\n");
  return 0;
}