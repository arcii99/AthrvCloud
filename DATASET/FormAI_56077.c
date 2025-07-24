//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 100 //number of points
#define INF 1e9 //infinity

typedef struct{
    double x,y;
} Point;

typedef struct{
    Point center;
    int size;
} Cluster;

Cluster clusters[N];
int num_clusters = 0;

Point points[N];
int num_points = 0;

double distance(Point a, Point b){ //calculating distance between two points
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void add_point(double x, double y){ //adding a point to the point list
    Point p = {x,y};
    points[num_points++] = p;
}

double calculate_variance(Cluster c){ //calculating variance of the given cluster
    double sum = 0;
    for(int i=0;i<c.size;i++){
        sum += distance(c.center, points[i])*distance(c.center, points[i]);
    }
    return sum/c.size;
}

void create_clusters(){ //creating initial clusters using k-means++
    int index = rand()%num_points;
    clusters[num_clusters].center = points[index];
    clusters[num_clusters].size = 0;
    num_clusters++;

    while(num_clusters < N){
        double max_var = -INF;
        Point next_center;
        for(int i=0;i<num_points;i++){
            double d = INF;
            for(int j=0;j<num_clusters;j++){
                double dist = distance(points[i],clusters[j].center);
                if(dist < d)
                    d = dist;
            }
            double var = (d*d)/(num_clusters+1);
            if(var > max_var){
                max_var = var;
                next_center = points[i];
            }
        }
        clusters[num_clusters].center = next_center;
        clusters[num_clusters].size = 0;
        num_clusters++;
    }
}

int main(){
    srand(0);

    //Adding random points from (-20, -20) to (20, 20)
    for(int i=0;i<N;i++){
        double x = ((double)rand()/RAND_MAX)*40 - 20;
        double y = ((double)rand()/RAND_MAX)*40 - 20;
        add_point(x,y);
    }

    //creating clusters using k-means++ algorithm
    create_clusters();

    //assigning points to nearest clusters
    for(int i=0;i<num_points;i++){
        int index = -1;
        double min_dist = INF;
        for(int j=0;j<num_clusters;j++){
            double dist = distance(points[i],clusters[j].center);
            if(dist < min_dist){
                min_dist = dist;
                index = j;
            }
        }
        clusters[index].size++;
    }

    //printing clusters and their variances
    for(int i=0;i<num_clusters;i++){
        printf("Cluster #%d (%d points): (%lf, %lf)  Variance: %lf\n",i+1,clusters[i].size,clusters[i].center.x,clusters[i].center.y,calculate_variance(clusters[i]));
    }

    return 0;
}