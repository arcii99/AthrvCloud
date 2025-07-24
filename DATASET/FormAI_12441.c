//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

// define struct for data points
typedef struct {
   double x;
   double y;
} point;

// function to calculate Euclidean distance
double distance(point p1, point p2) {
   double dx = p1.x - p2.x, dy = p1.y - p2.y;
   return sqrt(dx*dx + dy*dy);
}

// function to perform clustering
void cluster(point* data, int n, int k, point* centers) {
   int i, j, iter;

   // initialize centers at random data points
   for (i = 0; i < k; i++) {
      centers[i] = data[rand()%n];
   }

   // perform clustering iterations
   for (iter = 0; iter < 100; iter++) {

      // initialize cluster counts and sums
      int *counts = calloc(k, sizeof(int));
      point *sums = calloc(k, sizeof(point));
      
      // loop over data points and assign to nearest cluster
      for (i = 0; i < n; i++) {
         double minDist = 1e9;
         int minIndex = 0;
         for (j = 0; j < k; j++) {
            double dist = distance(data[i], centers[j]);
            if (dist < minDist) {
               minDist = dist;
               minIndex = j;
            }
         }
         counts[minIndex]++;
         sums[minIndex].x += data[i].x;
         sums[minIndex].y += data[i].y;
      }

      // update cluster centers
      for (i = 0; i < k; i++) {
         centers[i].x = sums[i].x / counts[i];
         centers[i].y = sums[i].y / counts[i];
      }

      // free memory
      free(counts);
      free(sums);
   }
}

int main() {

   // generate random data points
   point data[N];
   int i;
   for (i = 0; i < N; i++) {
      data[i].x = rand() / (double)RAND_MAX;
      data[i].y = rand() / (double)RAND_MAX;
   }

   // cluster data into 3 clusters
   point centers[3];
   cluster(data, N, 3, centers);

   // print out results
   printf("Cluster centers: (%lf, %lf), (%lf, %lf), (%lf, %lf)\n",
          centers[0].x, centers[0].y,
          centers[1].x, centers[1].y,
          centers[2].x, centers[2].y);

   return 0;
}