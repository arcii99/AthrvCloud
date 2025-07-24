//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>

int main() {
  printf("Welcome to the Curious Clustering Algorithm!\n");

  // Generate random data points
  int data_points[10][2] = {
    {1, 3},
    {2, 5},
    {4, 7},
    {9, 8},
    {10, 11},
    {12, 13},
    {14, 16},
    {17, 18},
    {19, 20},
    {21, 23}
  };

  printf("Data points:\n");
  for (int i = 0; i < 10; i++) {
    printf("(%d, %d)\n", data_points[i][0], data_points[i][1]);
  }

  // Initialize clusters
  int cluster_1[10][2] = {data_points[0]};
  int cluster_2[10][2] = {data_points[1]};
  int cluster_3[10][2] = {data_points[2]};
  int cluster_4[10][2] = {data_points[3]};
  int cluster_5[10][2] = {data_points[4]};
  int cluster_6[10][2] = {data_points[5]};
  int cluster_7[10][2] = {data_points[6]};
  int cluster_8[10][2] = {data_points[7]};
  int cluster_9[10][2] = {data_points[8]};
  int cluster_10[10][2] = {data_points[9]};
  
  // Start clustering algorithm
  for (int i = 0; i < 10; i++) {
    // Calculate distance between data point and each cluster
    int dist_1 = abs(data_points[i][0] - cluster_1[0][0]) + abs(data_points[i][1] - cluster_1[0][1]);
    int dist_2 = abs(data_points[i][0] - cluster_2[0][0]) + abs(data_points[i][1] - cluster_2[0][1]);
    int dist_3 = abs(data_points[i][0] - cluster_3[0][0]) + abs(data_points[i][1] - cluster_3[0][1]);
    int dist_4 = abs(data_points[i][0] - cluster_4[0][0]) + abs(data_points[i][1] - cluster_4[0][1]);
    int dist_5 = abs(data_points[i][0] - cluster_5[0][0]) + abs(data_points[i][1] - cluster_5[0][1]);
    int dist_6 = abs(data_points[i][0] - cluster_6[0][0]) + abs(data_points[i][1] - cluster_6[0][1]);
    int dist_7 = abs(data_points[i][0] - cluster_7[0][0]) + abs(data_points[i][1] - cluster_7[0][1]);
    int dist_8 = abs(data_points[i][0] - cluster_8[0][0]) + abs(data_points[i][1] - cluster_8[0][1]);
    int dist_9 = abs(data_points[i][0] - cluster_9[0][0]) + abs(data_points[i][1] - cluster_9[0][1]);
    int dist_10 = abs(data_points[i][0] - cluster_10[0][0]) + abs(data_points[i][1] - cluster_10[0][1]);

    // Select closest cluster
    int min_dist = dist_1;
    int min_index = 1;
    if (dist_2 < min_dist) {
      min_dist = dist_2;
      min_index = 2;
    }
    if (dist_3 < min_dist) {
      min_dist = dist_3;
      min_index = 3;
    }
    if (dist_4 < min_dist) {
      min_dist = dist_4;
      min_index = 4;
    }
    if (dist_5 < min_dist) {
      min_dist = dist_5;
      min_index = 5;
    }
    if (dist_6 < min_dist) {
      min_dist = dist_6;
      min_index = 6;
    }
    if (dist_7 < min_dist) {
      min_dist = dist_7;
      min_index = 7;
    }
    if (dist_8 < min_dist) {
      min_dist = dist_8;
      min_index = 8;
    }
    if (dist_9 < min_dist) {
      min_dist = dist_9;
      min_index = 9;
    }
    if (dist_10 < min_dist) {
      min_dist = dist_10;
      min_index = 10;
    }

    // Add data point to nearest cluster
    switch (min_index) {
      case 1:
        cluster_1[i][0] = data_points[i][0];
        cluster_1[i][1] = data_points[i][1];
        break;
      case 2:
        cluster_2[i][0] = data_points[i][0];
        cluster_2[i][1] = data_points[i][1];
        break;
      case 3:
        cluster_3[i][0] = data_points[i][0];
        cluster_3[i][1] = data_points[i][1];
        break;
      case 4:
        cluster_4[i][0] = data_points[i][0];
        cluster_4[i][1] = data_points[i][1];
        break;
      case 5:
        cluster_5[i][0] = data_points[i][0];
        cluster_5[i][1] = data_points[i][1];
        break;
      case 6:
        cluster_6[i][0] = data_points[i][0];
        cluster_6[i][1] = data_points[i][1];
        break;
      case 7:
        cluster_7[i][0] = data_points[i][0];
        cluster_7[i][1] = data_points[i][1];
        break;
      case 8:
        cluster_8[i][0] = data_points[i][0];
        cluster_8[i][1] = data_points[i][1];
        break;
      case 9:
        cluster_9[i][0] = data_points[i][0];
        cluster_9[i][1] = data_points[i][1];
        break;
      case 10:
        cluster_10[i][0] = data_points[i][0];
        cluster_10[i][1] = data_points[i][1];
        break;
    }
  }

  printf("Curious Clusters (sorted by index):\n");
  for (int i = 0; i < 10; i++) {
    printf("\nCluster %d:\n", i+1);
    switch (i+1) {
      case 1:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_1[j][0], cluster_1[j][1]);
        }
        break;
      case 2:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_2[j][0], cluster_2[j][1]);
        }
        break;
      case 3:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_3[j][0], cluster_3[j][1]);
        }
        break;
      case 4:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_4[j][0], cluster_4[j][1]);
        }
        break;
      case 5:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_5[j][0], cluster_5[j][1]);
        }
        break;
      case 6:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_6[j][0], cluster_6[j][1]);
        }
        break;
      case 7:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_7[j][0], cluster_7[j][1]);
        }
        break;
      case 8:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_8[j][0], cluster_8[j][1]);
        }
        break;
      case 9:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_9[j][0], cluster_9[j][1]);
        }
        break;
      case 10:
        for (int j = 0; j < 10; j++) {
          printf("(%d, %d)\n", cluster_10[j][0], cluster_10[j][1]);
        }
        break;
    }
  }

  return 0;
}