//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    double x, y;
};

double calculate_distance(struct point a, struct point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;
    double threshold;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    struct point* points = malloc(n * sizeof(struct point));
    for (int i = 0; i < n; i++) {
        printf("Enter the x and y coordinates of point %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    printf("Enter the clustering threshold: ");
    scanf("%lf", &threshold);
    int* clusters = malloc(n * sizeof(int));
    int num_clusters = 0;
    for (int i = 0; i < n; i++) {
        if (clusters[i] != 0) { continue; }
        num_clusters++;
        clusters[i] = num_clusters;
        for (int j = 0; j < n; j++) {
            if (i == j || clusters[j] != 0) { continue; }
            double distance = calculate_distance(points[i], points[j]);
            if (distance <= threshold) {
                clusters[j] = num_clusters;
            }
        }
    }
    printf("Number of clusters: %d\n", num_clusters);
    printf("Cluster assignments:\n");
    for (int i = 0; i < n; i++) {
        printf("(%0.1f, %0.1f) -> Cluster %d\n", points[i].x, points[i].y, clusters[i]);
    }
    free(points);
    free(clusters);
    return 0;
}