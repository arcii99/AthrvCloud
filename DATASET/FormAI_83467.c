//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>

int main() {
  int array[] = {3, 4, 2, 1, 5};
  int n = sizeof(array) / sizeof(array[0]);
  int k = 3;
  int clusters[k][n], means[k], temp_mean[k];
  int i, j, l, min_distance, dist, index;

  // initialize means randomly
  for (i = 0; i < k; i++) {
    means[i] = array[i];
  }

  // loop until convergence
  do {
    // initialize clusters
    for (i = 0; i < k; i++) {
      l = 0;
      for (j = 0; j < n; j++) {
        if (array[j] == means[i]) {
          clusters[i][l++] = array[j];
        }
      }
    }

    // recalculate means
    for (i = 0; i < k; i++) {
      temp_mean[i] = means[i];
      if (clusters[i][0] != 0) {
        int sum = 0;
        for (j = 0; j < sizeof(clusters[i]) / sizeof(clusters[i][0]); j++) {
          if (clusters[i][j] == 0) {
            break;
          }
          sum += clusters[i][j];
        }
        means[i] = sum / j;
      }
    }

    // check for convergence
    min_distance = 100000;
    for (i = 0; i < k; i++) {
      dist = 0;
      for (j = 0; j < n; j++) {
        if (array[j] != 0) {
          int diff = array[j] - means[i];
          dist += diff * diff;
        }
      }
      if (dist < min_distance) {
        min_distance = dist;
        index = i;
      }
    }
  } while (means[index] != temp_mean[index]);

  // print results
  printf("Cluster 1: ");
  for (i = 0; i < sizeof(clusters[0]) / sizeof(clusters[0][0]); i++) {
    if (clusters[0][i] == 0) {
      break;
    }
    printf("%d ", clusters[0][i]);
  }
  printf("\n");
  printf("Cluster 2: ");
  for (i = 0; i < sizeof(clusters[1]) / sizeof(clusters[1][0]); i++) {
    if (clusters[1][i] == 0) {
      break;
    }
    printf("%d ", clusters[1][i]);
  }
  printf("\n");
  printf("Cluster 3: ");
  for (i = 0; i < sizeof(clusters[2]) / sizeof(clusters[2][0]); i++) {
    if (clusters[2][i] == 0) {
      break;
    }
    printf("%d ", clusters[2][i]);
  }
  printf("\n");
  return 0;
}