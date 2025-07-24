//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
  int value;
  int weight;
};

int compare_items(const void *a, const void *b) {
  const struct Item *x = (const struct Item *)a;
  const struct Item *y = (const struct Item *)b;
  double ratio_x = (double)x->value / x->weight;
  double ratio_y = (double)y->value / y->weight;
  return ratio_y - ratio_x;
}

double knapsack_greedy(struct Item *items, int n, int capacity) {
  qsort(items, n, sizeof(struct Item), compare_items);

  double total_value = 0.0;
  int i;
  for (i = 0; i < n && capacity > 0; ++i) {
    struct Item *curr_item = &items[i];
    if (capacity >= curr_item->weight) {
      total_value += curr_item->value;
      capacity -= curr_item->weight;
    } else {
      total_value += capacity * ((double)curr_item->value / curr_item->weight);
      break;
    }
  }

  return total_value;
}

int main() {
  struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
  int n = sizeof(items) / sizeof(struct Item);
  int capacity = 50;

  double max_value = knapsack_greedy(items, n, capacity);
  printf("The maximum value that can be obtained is: %g\n", max_value);

  return 0;
}