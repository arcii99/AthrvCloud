//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Get data points from user
  int numPoints;
  printf("Enter the number of data points: ");
  scanf("%d", &numPoints);
  double data[numPoints][2];
  for(int i=0; i<numPoints; i++) {
    printf("Enter data point #%d (x y): ", i+1);
    scanf("%lf %lf", &data[i][0], &data[i][1]);
  }

  // Set initial values for cluster centers
  double center1[] = {data[0][0], data[0][1]};
  double center2[] = {data[1][0], data[1][1]};

  // Loop until cluster centers converge
  while(1) {
    // Assign points to clusters based on distance to centers
    int cluster1Count = 0, cluster2Count = 0;
    double cluster1SumX = 0, cluster1SumY = 0;
    double cluster2SumX = 0, cluster2SumY = 0;
    for(int i=0; i<numPoints; i++) {
      double distance1 = sqrt(pow(data[i][0]-center1[0],2)+pow(data[i][1]-center1[1],2));
      double distance2 = sqrt(pow(data[i][0]-center2[0],2)+pow(data[i][1]-center2[1],2));
      if(distance1 < distance2) {
        cluster1Count++;
        cluster1SumX += data[i][0];
        cluster1SumY += data[i][1];
      } else {
        cluster2Count++;
        cluster2SumX += data[i][0];
        cluster2SumY += data[i][1];
      }
    }

    // Update cluster centers
    double newCenter1[] = {cluster1SumX/cluster1Count, cluster1SumY/cluster1Count};
    double newCenter2[] = {cluster2SumX/cluster2Count, cluster2SumY/cluster2Count};

    // Check if cluster centers converged
    if(newCenter1[0] == center1[0] && newCenter1[1] == center1[1] && newCenter2[0] == center2[0] && newCenter2[1] == center2[1]) {
      break;
    }

    // Update cluster centers and repeat
    center1[0] = newCenter1[0];
    center1[1] = newCenter1[1];
    center2[0] = newCenter2[0];
    center2[1] = newCenter2[1];
  }

  // Print final clusters
  printf("\nCluster 1: ");
  for(int i=0; i<numPoints; i++) {
    double distance1 = sqrt(pow(data[i][0]-center1[0],2)+pow(data[i][1]-center1[1],2));
    double distance2 = sqrt(pow(data[i][0]-center2[0],2)+pow(data[i][1]-center2[1],2));
    if(distance1 < distance2) printf("(%g,%g) ", data[i][0], data[i][1]);
  }
  printf("\nCluster 2: ");
  for(int i=0; i<numPoints; i++) {
    double distance1 = sqrt(pow(data[i][0]-center1[0],2)+pow(data[i][1]-center1[1],2));
    double distance2 = sqrt(pow(data[i][0]-center2[0],2)+pow(data[i][1]-center2[1],2));
    if(distance1 >= distance2) printf("(%g,%g) ", data[i][0], data[i][1]);
  }

  return 0;
}