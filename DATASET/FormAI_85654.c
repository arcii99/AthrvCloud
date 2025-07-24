//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

#define N 10    // Number of points
#define K 3     // Number of clusters

typedef struct Point {
    float x,y;
} Point;

float distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    Point points[N] = {{1,2}, {2,3}, {1,3}, {5,6}, {4,5}, {7,8}, {9,9}, {8,9}, {7,7}, {6,5}};
    Point centroids[K] = {{1,2}, {5,6}, {8,9}};
    int cluster[N];
    float d, min;
    int i,j,k;

    for(i=0; i<N; i++) {
        min = INFINITY;
        for(j=0; j<K; j++) {
            d = distance(points[i], centroids[j]);
            if(d < min) {
                min = d;
                cluster[i] = j;
            }
        }
    }

    for(k=0; k<K; k++) {
        printf("Cluster %d:\n", k);
        for(i=0; i<N; i++) {
            if(cluster[i] == k) {
                printf("(%f,%f)\n", points[i].x, points[i].y);
            }
        }
    }

    return 0;
}