//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include<stdio.h>
#include<stdlib.h>

/* Curious Clustering Algorithm */

int main() {
  printf("Hello! Welcome to Curious Clustering Algorithm!\n");
  printf("How many data points would you like to cluster?\n");

  int num_pts;
  scanf("%d", &num_pts);
  
  int* data_points = (int*)malloc(num_pts * sizeof(int));

  if (data_points == NULL) {
    printf("Oops! Memory allocation failed!\n");
    return 0;
  }

  printf("Great! Please enter your data points:\n");

  for (int i = 0; i < num_pts; i++) {
    scanf("%d", &data_points[i]);
  }

  printf("Thank you! Now, we will perform clustering based on the first digit of each data point.\n");

  int clusters[10][num_pts]; // Maximum 10 clusters
  int counts[10] = {0}; // Number of data points in each cluster

  for (int i = 0; i < num_pts; i++) {
    int first_digit = data_points[i] / 10;

    clusters[first_digit][counts[first_digit]] = data_points[i];

    counts[first_digit]++;
  }

  printf("Clustering completed!\n");

  printf("Here are the clusters:\n");

  for (int i = 0; i < 10; i++) {
    if (counts[i] > 0) {
      printf("Cluster %d: ", i);
      for (int j = 0; j < counts[i]; j++) {
        printf("%d ", clusters[i][j]);
      }
      printf("\n");
    }
  }

  free(data_points);

  return 0;
}