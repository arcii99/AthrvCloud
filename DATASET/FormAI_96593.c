//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  
  printf("Welcome to the C Clustering Algorithm Implementation program!\n");
  printf("You won't believe how we cluster the data here. It's like magic!\n");
  
  /* pretend this is some data we're clustering */
  int data[10] = {1, 2, 7, 8, 11, 13, 17, 19, 23, 29};
  
  /* pretend these are our initial cluster centers */
  int centers[3] = {2, 13, 23};
  
  /* pretend we have some fancy distance function */
  int distance(int x, int y) {
    return abs(x - y);
  }
  
  /* let's iterate 10 times, because why not? */
  for (int i = 0; i < 10; i++) {
    
    /* create some fake clusters */
    int cluster1[10] = {0}, cluster2[10] = {0}, cluster3[10] = {0};
    
    /* assign data points to nearest cluster center */
    for (int j = 0; j < 10; j++) {
      int dist1 = distance(data[j], centers[0]);
      int dist2 = distance(data[j], centers[1]);
      int dist3 = distance(data[j], centers[2]);
      
      if (dist1 < dist2 && dist1 < dist3) {
        cluster1[j] = data[j];
      } else if (dist2 < dist1 && dist2 < dist3) {
        cluster2[j] = data[j];
      } else {
        cluster3[j] = data[j];
      }
    }
    
    /* calculate new cluster center for each cluster */
    int sum1 = 0, sum2 = 0, sum3 = 0, count1 = 0, count2 = 0, count3 = 0;
    
    for (int j = 0; j < 10; j++) {
      if (cluster1[j] != 0) {
        sum1 += cluster1[j];
        count1++;
      }
      if (cluster2[j] != 0) {
        sum2 += cluster2[j];
        count2++;
      }
      if (cluster3[j] != 0) {
        sum3 += cluster3[j];
        count3++;
      }
    }
    
    centers[0] = sum1 / count1;
    centers[1] = sum2 / count2;
    centers[2] = sum3 / count3;

    printf("Iteration %d\n", i+1);
    printf("Cluster 1: ");
    for (int j = 0; j < 10; j++) {
      if (cluster1[j] != 0) {
        printf("%d ", cluster1[j]);
      }
    }
    printf("\n");
    
    printf("Cluster 2: ");
    for (int j = 0; j < 10; j++) {
      if (cluster2[j] != 0) {
        printf("%d ", cluster2[j]);
      }
    }
    printf("\n");
    
    printf("Cluster 3: ");
    for (int j = 0; j < 10; j++) {
      if (cluster3[j] != 0) {
        printf("%d ", cluster3[j]);
      }
    }
    printf("\n\n");
  }
  
  printf("Wow, can you believe we actually clustered that data? I'm impressed!\n");
  
  return 0;
}