//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct Item {
  int value;
  int weight;
};

int compare(const void *a, const void *b) {
  double v1 = (*(struct Item *)b).value / (double)(*(struct Item *)b).weight;
  double v2 = (*(struct Item *)a).value / (double)(*(struct Item *)a).weight;
  return v1 - v2;
}

double fractionalKnapsack(struct Item arr[], int n, int W) {
  qsort(arr, n, sizeof(struct Item), compare);
  int currW = 0;
  double finalValue = 0.0;
  for (int i = 0; i < n; i++) {
    if (currW + arr[i].weight <= W) {
      currW += arr[i].weight;
      finalValue += arr[i].value;
    } else {
      int remaining = W - currW;
      finalValue += arr[i].value * ((double)remaining / arr[i].weight);
      break;
    }
  }
  return finalValue;
}

int main() {
  int W = 50;
  struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(arr) / sizeof(arr[0]);
  double max = fractionalKnapsack(arr, n, W);
  printf("Maximum value in Knapsack = %lf", max);
  return 0;
}