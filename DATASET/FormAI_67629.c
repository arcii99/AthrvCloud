//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_POINTS 100000

typedef struct{
    double x;
    double y;
} Point;


int assign_clusters(Point points[], Point centroid1, Point centroid2, int cluster[]) {
    int i, count1 = 0, count2 = 0, min;
    double d1, d2;

    for(i=0;i<MAX_POINTS;i++) {
        d1 = sqrt(pow(points[i].x - centroid1.x, 2) + pow(points[i].y - centroid1.y, 2));
        d2 = sqrt(pow(points[i].x - centroid2.x, 2) + pow(points[i].y - centroid2.y, 2));
        
        if(d1<d2) {
            cluster[i] = 1;
            count1++;
        }
        else {
            cluster[i] = 2;
            count2++;
        }
    }

    if(count1<count2) return 1;
    else return 2;
}


void find_new_centroid(Point points[], Point *centroid, int cluster[]) {
    int i, count = 0;
    double sum_x = 0, sum_y = 0;

    for(i=0;i<MAX_POINTS;i++) {
        if(cluster[i] == 1) {
            sum_x += points[i].x;
            sum_y += points[i].y;
            count++;
        }
    }

    centroid->x = sum_x/count;
    centroid->y = sum_y/count;
}


void clustering_kmeans(Point points[], int k, Point centroids[]) {
    int i, cluster[MAX_POINTS], iter = 0;

    for(i=0;i<MAX_POINTS;i++) {
        cluster[i] = 0;
    }

    int centroid_index = rand()%k;
    centroids[0] = points[centroid_index];

    for(i=1;i<k;i++) {
        int max_index = 0, j;
        double max_distance = 0;
        for(j=0;j<MAX_POINTS;j++) {
            double min_distance = 1000000000;
            if(cluster[j] != 0) continue;
            int l;
            for(l=0;l<i;l++) {
                double distance = sqrt(pow(points[j].x - centroids[l].x, 2) + pow(points[j].y - centroids[l].y, 2));
                if(distance<min_distance) min_distance = distance;
            }
            if(min_distance>max_distance) {
                max_distance = min_distance;
                max_index = j;
            }
        }
        centroids[i] = points[max_index];
    }

    int flag = assign_clusters(points, centroids[0], centroids[1], cluster), iter_max = 10;

    while(iter<iter_max) {
        Point new_centroid1, new_centroid2;
        find_new_centroid(points, &new_centroid1, cluster);
        centroids[0] = new_centroid1;
        find_new_centroid(points, &new_centroid2, cluster);
        centroids[1] = new_centroid2;
        
        int new_flag = assign_clusters(points, centroids[0], centroids[1], cluster);

        if(flag == new_flag) iter++;
        else {
            flag = new_flag;
            iter = 0;
        }
    }
}


int main() {
    Point points[MAX_POINTS];
    int i;
    for(i=0;i<MAX_POINTS;i++) {
        points[i].x = rand()%100;
        points[i].y = rand()%100;
    }

    Point centroids[2];
    clustering_kmeans(points, 2, centroids);

    printf("The centroids are: (%lf, %lf) and (%lf, %lf)", centroids[0].x, centroids[0].y, centroids[1].x, centroids[1].y);
    return 0;
}