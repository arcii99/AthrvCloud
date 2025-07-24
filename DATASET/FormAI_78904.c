//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include <stdio.h>

struct Item {
  int value;
  int weight;
};

float maxValue(struct Item items[], int n, int W) {
  float maxV = 0;
  float fWeight = (float)W;

  while (fWeight > 0) {
    int idx = -1;
    float max = 0;

    // Find item with the max value to weight ratio
    for (int i = 0; i < n; i++) {
      if (items[i].weight > 0 && ((float)items[i].value / items[i].weight) > max) {
        max = (float)items[i].value / items[i].weight;
        idx = i;
      }
    }

    // Add item to the knapsack
    if (idx != -1) {
      int add = fWeight < items[idx].weight ? fWeight : items[idx].weight;
      fWeight -= add;
      maxV += add * ((float)items[idx].value / items[idx].weight);
      items[idx].weight -= add;
    } else {
      // No items left to add
      break;
    }
  }

  return maxV;
}

int main() {
  struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(items) / sizeof(items[0]);
  int W = 50;

  float max = maxValue(items, n, W);

  printf("The maximum value for a knapsack of weight %d is: %.2f\n", W, max);
  return 0;
}