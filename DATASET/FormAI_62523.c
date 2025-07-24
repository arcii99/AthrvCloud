//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_POINTS 10000
#define MAX_CLUSTERS 1000

typedef struct point{   
    int index;  
    double x,y; 
    int cluster; 
}Point;

typedef struct cluster{
    int num_points; 
    Point points[MAX_POINTS]; 
    Point centroid; 
}Cluster;

Cluster clusters[MAX_CLUSTERS];
int n_clusters = 0;
int n_features = 2;
int n_points = 0;
double threshold;

double distance(Point p1, Point p2){
    double dist = pow(p1.x - p2.x, 2);
    dist += pow(p1.y - p2.y, 2);
    return sqrt(dist);
}

void initialize_clusters(){
   int i;
   for(i=0;i<n_clusters;i++){
      clusters[i].num_points=0;
   }
}

void calculate_centroids(){
   int i,j,k;
   double x=0,y=0;
   for(k=0;k<n_clusters;k++){
      for(i=0;i<clusters[k].num_points;i++){
         x+= clusters[k].points[i].x;
         y+= clusters[k].points[i].y;
      }
      clusters[k].centroid.x= x/clusters[k].num_points;
      clusters[k].centroid.y= y/clusters[k].num_points;
   }
}

void assign_clusters(Point p){
   int i,k;
   double min_distance,d;
   min_distance=1000000.00;
   for(k=0;k<n_clusters;k++){
      d=distance(p, clusters[k].centroid);
      if(d<min_distance){
         min_distance=d;  
         p.cluster=k;
      }
   }
   clusters[p.cluster].points[ clusters[p.cluster].num_points++]= p;
}

void print_clusters(){
   int i,j;
   printf("\nClusters formed are:\n");
   for(i=0;i<n_clusters;i++){
      printf("\nCluster %d\n",i+1);
      printf("\nPoints belonging to cluster %d:\n",i+1);
      for(j=0;j<clusters[i].num_points;j++){
         printf("(%lf,%lf) ", clusters[i].points[j].x, clusters[i].points[j].y);
      }
      printf("\nCentroid of Cluster %d: (%lf,%lf)",i+1,clusters[i].centroid.x, clusters[i].centroid.y);
   } 
}

int main(){
   int i, j,k;
   Point points[MAX_POINTS];
   double x,y;
   printf("Enter the threshold: ");
   scanf("%lf", &threshold);
   printf("Enter the number of clusters: ");
   scanf("%d",&n_clusters);
   printf("Enter the number of points: ");
   scanf("%d", &n_points);
   printf("Enter the points:\n");
   for(i=0;i<n_points;i++){
      scanf("%lf %lf",&x,&y);
      points[i].x=x;
      points[i].y=y;
      points[i].cluster=-1;
      points[i].index=i;
   }
   
   for(i=0;i<n_clusters;i++){
      clusters[i].centroid.x=points[i].x;
      clusters[i].centroid.y=points[i].y;
   }
   
   while(1){
      initialize_clusters();
      for(i=0;i<n_points;i++){
         assign_clusters(points[i]);
      }
      calculate_centroids();
      int convergence = 1;
      for(i=0;i<n_clusters;i++){
         double d = distance(clusters[i].centroid, points[0]);
         for(j=1;j<n_points;j++){
            double cd = distance(clusters[i].centroid, points[j]);
            if(cd<d)d = cd;
         }
         if(threshold<d)convergence=0;
      }
      if(convergence)break;      
   }
   print_clusters();
   return 0;
}