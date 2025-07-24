//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
/*
  Welcome to a mind-bending, unique example program showcasing Greedy Algorithms in C!
  This program solves the Knapsack Problem using the Greedy Strategy, but with a twist!
  Instead of just maximizing the value of items that fit in the knapsack, this program
  also considers the weight of the items and maximizes the value per unit of weight.
  To make things more interesting, we will only allow selecting fractions of items, not
  entire items.
  
  So buckle up and enjoy the ride!
*/

#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold item information
struct Item {
  int id;          // unique identifier for the item
  double value;    // value of the item
  double weight;   // weight of the item
  double ratio;    // value-to-weight ratio of the item (computed)
};

// Function to sort items based on their value-to-weight ratio
int compare_items(const void* a, const void* b) {
  const struct Item* item1 = (const struct Item*) a;
  const struct Item* item2 = (const struct Item*) b;
  
  if (item1->ratio < item2->ratio)
    return 1;
  else if (item1->ratio > item2->ratio)
    return -1;
  else
    return 0;
}

int main() {
  // Initialize values for the Knapsack Problem
  const int knapsack_capacity = 50;
  struct Item items[] = {
    {1, 60.0, 10.0, 0.0},
    {2, 100.0, 20.0, 0.0},
    {3, 120.0, 30.0, 0.0}
  };
  const int num_items = sizeof(items) / sizeof(items[0]);
  
  // Compute value-to-weight ratios for all items
  for (int i = 0; i < num_items; ++i) {
    items[i].ratio = items[i].value / items[i].weight;
  }
  
  // Sort items in decreasing order of value-to-weight ratio
  qsort(items, num_items, sizeof(struct Item), compare_items);
  
  // Pack items into the knapsack
  double knapsack_weight = 0.0;
  double knapsack_value = 0.0;
  
  for (int i = 0; i < num_items; ++i) {
    if (knapsack_weight + items[i].weight <= knapsack_capacity) {
      // The entire item fits into the knapsack
      knapsack_weight += items[i].weight;
      knapsack_value += items[i].value;
    }
    else {
      // Only part of the item fits into the knapsack
      double remaining_capacity = knapsack_capacity - knapsack_weight;
      knapsack_value += (remaining_capacity / items[i].weight) * items[i].value;
      break;
    }
  }
  
  // Print the final result
  printf("The maximum value that can be packed in the knapsack is %.2f\n", knapsack_value);
  
  return 0;
}