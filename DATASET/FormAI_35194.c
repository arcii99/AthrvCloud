//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define a custom struct to represent each item
struct Item {
  int weight;
  int value;
};

// Calculate the total value of a list of items
int calculateValue(struct Item items[], int n, int selected[]) {
  int total = 0;
  for (int i=0; i<n; i++) {
    if (selected[i]) {
      total += items[i].value;
    }
  }
  return total;
}

// Calculate the total weight of a list of items
int calculateWeight(struct Item items[], int n, int selected[]) {
  int total = 0;
  for (int i=0; i<n; i++) {
    if (selected[i]) {
      total += items[i].weight;
    }
  }
  return total;
}

// Greedy algorithm function
void knapsack(struct Item items[], int n, int capacity) {
  
  // Create an array to keep track of which items are selected
  int selected[n];

  // Initialize all items to not be selected
  for (int i=0; i<n; i++) {
    selected[i] = 0;
  }
  
  // Keep selecting the item with the highest value to weight ratio until the knapsack is full
  while (calculateWeight(items, n, selected) < capacity) {
    int highestRatioIndex = -1;
    double highestRatio = -1;

    // Find the item with the highest value to weight ratio
    for (int i=0; i<n; i++) {
      if (!selected[i]) {
        double vwr = (double) items[i].value / (double) items[i].weight;
        if (vwr > highestRatio) {
          highestRatio = vwr;
          highestRatioIndex = i;
        }
      }
    }

    // Select the item and move to the next iteration
    selected[highestRatioIndex] = 1;
  }

  // Print out the selected items and their total value and weight
  printf("Selected Items: ");
  for (int i=0; i<n; i++) {
    if (selected[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  printf("Total Value: %d\n", calculateValue(items, n, selected));
  printf("Total Weight: %d\n", calculateWeight(items, n, selected));
}

int main() {
  
  // Define the items and the capacity of the knapsack
  struct Item items[] = {{20, 100}, {30, 120}, {10, 60}, {5, 30}, {40, 200}};
  int n = sizeof(items) / sizeof(items[0]);
  int capacity = 50;

  // Solve the knapsack problem and print the results
  knapsack(items, n, capacity);

  return 0;
}