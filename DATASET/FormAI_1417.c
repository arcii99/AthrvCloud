//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

struct point { // structure to represent point in 2D space
    double x;
    double y;
};

int cluster(struct point *points, int n, double threshold, int *labels) {
    int i, j, k, n_cluster = 0;
    double dist;
    // Array to store the visited status of the points
    int visited[n];

    for (i=0; i<n; i++) {
        labels[i] = -1; // initialize all labels as unassigned
        visited[i] = 0; // mark all points as unvisited
    }

    for (i=0; i<n; i++) {
        if (visited[i] == 1) // skip this point if already processed
            continue;

        labels[i] = n_cluster++; // create a new cluster with the current point

        for (j=i+1; j<n; j++) {
            dist = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
            if (dist < threshold) {
                if (visited[j] == 0) {
                    visited[j] = 1;
                    labels[j] = labels[i]; // assign the current point's label to this point
                } else {
                    if (labels[j] != labels[i]) { // merge two clusters if needed
                        for (k=0; k<n; k++) {
                            if (labels[k] == labels[j])
                                labels[k] = labels[i];
                        }
                    }
                }
            }
        }
    }

    return n_cluster; // return the total number of clusters found
}

int main() {
    int n = 10; // number of points
    double threshold = 1.0; // clustering threshold
    int labels[n];

    // generate random points between (0,0) and (10,10)
    struct point points[10] = {{0.8, 1.4}, {2.1, 2.7}, {1.9, 2.3}, {4.2, 5.9}, {9.3, 5.6},
                                {8.2, 6.1}, {7.6, 2.4}, {6.9, 3.3}, {0.9, 3.9}, {9.4, 4.8}};

    int n_cluster = cluster(points, n, threshold, labels);
    printf("%d clusters found:\n", n_cluster);

    for (int i=0; i<n_cluster; i++) {
        printf("cluster %d:\n", i);
        for (int j=0; j<n; j++) {
            if (labels[j] == i)
                printf("(%f, %f)\n", points[j].x, points[j].y);
        }
    }

    return 0;
}