//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>

struct item {
   int value;
   int weight;
};

void knapsack(int capacity, struct item items[], int num_items) {
   // Sort items in decreasing order by value/weight ratio
   for (int i = 0; i < num_items; i++) {
      for (int j = i + 1; j < num_items; j++) {
         if ((float)items[j].value / items[j].weight > (float)items[i].value / items[i].weight) {
            struct item temp = items[i];
            items[i] = items[j];
            items[j] = temp;
         }
      }
   }

   // Greedily fill knapsack
   int weight = 0;
   float value = 0;
   for (int i = 0; i < num_items; i++) {
      if (weight + items[i].weight <= capacity) {
         weight += items[i].weight;
         value += items[i].value;
      }
      else {
         value += ((float)capacity - weight) / items[i].weight * items[i].value;
         weight = capacity;
         break;
      }
   }

   printf("Maximum value: %.2f\n", value);
}

int main() {
   // Example problem
   struct item items[] = {
      {60, 10},
      {100, 20},
      {120, 30}
   };
   int capacity = 50;
   int num_items = 3;
   
   knapsack(capacity, items, num_items);

   return 0;
}