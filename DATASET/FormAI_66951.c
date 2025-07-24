//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_bags;
  int max_weight;
  int num_workers;

  printf("Please input the number of bags: ");
  scanf("%d", &num_bags);

  printf("Please input the maximum weight for bags: ");
  scanf("%d", &max_weight);

  printf("Please input the number of workers: ");
  scanf("%d", &num_workers);

  int *bag_weights = malloc(num_bags * sizeof(int));

  // Generate random weights for each bag
  for (int i = 0; i < num_bags; i++) {
    bag_weights[i] = rand() % (max_weight + 1);
  }

  printf("The bag weights are: \n");
  for (int i = 0; i < num_bags; i++) {
    printf("%d ", bag_weights[i]);
  }
  printf("\n");

  int total_weight = 0;

  // Calculate the total weight of all bags
  for (int i = 0; i < num_bags; i++) {
    total_weight += bag_weights[i];
  }

  printf("The total weight of all bags is %d \n", total_weight);

  // Calculate the average weight per worker
  float avg_weight = (float) total_weight / num_workers;

  printf("The average weight per worker is %.2f \n", avg_weight);

  free(bag_weights);

  return 0;
}