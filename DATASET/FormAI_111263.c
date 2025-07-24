//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//define struct for cluster data
struct cluster {
  float x; //x coordinate of cluster
  float y; //y coordinate of cluster
  int size; //number of data-points in cluster
  struct cluster* next; //pointer to next cluster
};

//function to calculate Euclidean distance
float euclideanDistance(float x1, float y1, float x2, float y2) {
  float distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
  return distance;
}

//function to merge clusters
struct cluster* mergeClusters(struct cluster* c1, struct cluster* c2) {
  struct cluster* newCluster = (struct cluster*) malloc(sizeof(struct cluster));
  newCluster->x = (c1->x*c1->size + c2->x*c2->size)/(c1->size + c2->size);
  newCluster->y = (c1->y*c1->size + c2->y*c2->size)/(c1->size + c2->size);
  newCluster->size = c1->size + c2->size;
  newCluster->next = NULL;
  return newCluster;
}

//function to add new cluster to list of clusters
void addCluster(struct cluster** clusterList, struct cluster* newCluster) {
  if (*clusterList == NULL) { //if list is empty, assign new cluster as head
    *clusterList = newCluster;
  } else { //else, add new cluster to end of list
    struct cluster* currCluster = *clusterList;
    while (currCluster->next != NULL) {
      currCluster = currCluster->next;
    }
    currCluster->next = newCluster;
  }
}

//recursive function to perform clustering
void performClustering(struct cluster** dataList, struct cluster** clusterList, int k) {
  if (k == 1) { //base case, only one cluster remaining
    *clusterList = *dataList;
  } else { //recursive case
    struct cluster* closestCluster1 = NULL;
    struct cluster* closestCluster2 = NULL;
    float minDistance = INFINITY; //initialize minimum distance to infinity
    struct cluster* currCluster1 = *dataList;
    while (currCluster1 != NULL) { //iterate over all clusters
      struct cluster* currCluster2 = currCluster1->next;
      while (currCluster2 != NULL) {
        float distance = euclideanDistance(currCluster1->x, currCluster1->y, currCluster2->x, currCluster2->y); //calculate distance between clusters
        if (distance < minDistance) { //update closest clusters and minimum distance if new minimum is found
          closestCluster1 = currCluster1;
          closestCluster2 = currCluster2;
          minDistance = distance;
        }
        currCluster2 = currCluster2->next;
      }
      currCluster1 = currCluster1->next;
    }
    //merge closest clusters and add new cluster to list of clusters
    struct cluster* newCluster = mergeClusters(closestCluster1, closestCluster2);
    addCluster(dataList, newCluster);
    //remove closest clusters from list of clusters
    if (closestCluster1 == *dataList) {
      *dataList = closestCluster1->next;
    } else {
      struct cluster* currCluster = *dataList;
      while (currCluster->next != closestCluster1) {
        currCluster = currCluster->next;
      }
      currCluster->next = closestCluster1->next;
    }
    if (closestCluster2 == *dataList) {
      *dataList = closestCluster2->next;
    } else {
      struct cluster* currCluster = *dataList;
      while (currCluster->next != closestCluster2) {
        currCluster = currCluster->next;
      }
      currCluster->next = closestCluster2->next;
    }
    //recursively call function with k-1 clusters
    performClustering(dataList, clusterList, k-1);
  }
}

//main function
int main() {
  //initialize data-points
  struct cluster* d1 = (struct cluster*) malloc(sizeof(struct cluster));
  d1->x = 2.0;
  d1->y = 14.0;
  d1->size = 1;
  d1->next = NULL;
  struct cluster* d2 = (struct cluster*) malloc(sizeof(struct cluster));
  d2->x = 23.0;
  d2->y = 5.0;
  d2->size = 1;
  d2->next = NULL;
  struct cluster* d3 = (struct cluster*) malloc(sizeof(struct cluster));
  d3->x = 8.0;
  d3->y = 18.0;
  d3->size = 1;
  d3->next = NULL;
  struct cluster* d4 = (struct cluster*) malloc(sizeof(struct cluster));
  d4->x = 6.0;
  d4->y = 6.0;
  d4->size = 1;
  d4->next = NULL;
  struct cluster* d5 = (struct cluster*) malloc(sizeof(struct cluster));
  d5->x = 18.0;
  d5->y = 8.0;
  d5->size = 1;
  d5->next = NULL;
  struct cluster* d6 = (struct cluster*) malloc(sizeof(struct cluster));
  d6->x = 12.0;
  d6->y = 10.0;
  d6->size = 1;
  d6->next = NULL;
  struct cluster* d7 = (struct cluster*) malloc(sizeof(struct cluster));
  d7->x = 17.0;
  d7->y = 15.0;
  d7->size = 1;
  d7->next = NULL;
  //initialize list of data-points
  struct cluster* dataList = NULL;
  addCluster(&dataList, d1);
  addCluster(&dataList, d2);
  addCluster(&dataList, d3);
  addCluster(&dataList, d4);
  addCluster(&dataList, d5);
  addCluster(&dataList, d6);
  addCluster(&dataList, d7);
  //perform clustering with k=3 clusters
  struct cluster* clusterList = NULL;
  performClustering(&dataList, &clusterList, 3);
  //print results
  int i = 1;
  printf("Cluster Results:\n");
  struct cluster* currCluster = clusterList;
  while (currCluster != NULL) {
    printf("Cluster %d:\n", i);
    printf("Center: (%f, %f)\n", currCluster->x, currCluster->y);
    printf("Size: %d\n", currCluster->size);
    currCluster = currCluster->next;
    i++;
  }
  //free memory allocated for lists
  while (dataList != NULL) {
    struct cluster* temp = dataList;
    dataList = dataList->next;
    free(temp);
  }
  while (clusterList != NULL) {
    struct cluster* temp = clusterList;
    clusterList = clusterList->next;
    free(temp);
  }
  return 0;
}