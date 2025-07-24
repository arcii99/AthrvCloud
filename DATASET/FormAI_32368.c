//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x;
    double y;
    int cluster;
};

struct Cluster {
    double sum_x;
    double sum_y;
    double center_x;
    double center_y;
    int size;
};

double distance(struct Point A, struct Point B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

int assign_clusters(struct Point* points, int n, struct Cluster* clusters, int k) {
    int i, j, min_distance_index;
    double min_distance, d;
    int updated = 0;
    for(i = 0; i < n; i++) {
        min_distance_index = -1;
        min_distance = -1;
        for(j = 0; j < k; j++) {
            d = distance(points[i], (struct Point){clusters[j].center_x, clusters[j].center_y, 0});
            if(min_distance == -1 || d < min_distance) {
                min_distance = d;
                min_distance_index = j;
            }
        }
        if(points[i].cluster != min_distance_index) {
            clusters[points[i].cluster].size--;
            clusters[points[i].cluster].sum_x -= points[i].x;
            clusters[points[i].cluster].sum_y -= points[i].y;
            points[i].cluster = min_distance_index;
            clusters[points[i].cluster].size++;
            clusters[points[i].cluster].sum_x += points[i].x;
            clusters[points[i].cluster].sum_y += points[i].y;
            updated = 1;
        }
    }
    return updated;
}

void update_centers(struct Cluster* clusters, int k) {
    int i;
    for(i = 0; i < k; i++) {
        clusters[i].center_x = clusters[i].sum_x / clusters[i].size;
        clusters[i].center_y = clusters[i].sum_y / clusters[i].size;
    }
}

void print_clusters(struct Point* points, int n, int k) {
    int i, j;
    for(i = 0; i < k; i++) {
        printf("Cluster %d (center at %.2f, %.2f)\n", i, points[i].x, points[i].y);
        for(j = 0; j < n; j++) {
            if(points[j].cluster == i) {
                printf("\t(%f, %f)\n", points[j].x, points[j].y);
            }
        }
    }
}

int main(int argc, char** argv) {
    int n, k, i, updated;
    double x, y;
    
    if(argc != 3) {
        printf("Usage: %s <number of points> <number of clusters>\n", argv[0]);
        exit(1);
    }
    
    n = atoi(argv[1]);
    k = atoi(argv[2]);
    
    struct Point* points = malloc(sizeof(struct Point) * n);
    struct Cluster* clusters = malloc(sizeof(struct Cluster) * k);
    
    for(i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        points[i] = (struct Point){x, y, 0};
    }
    
    for(i = 0; i < k; i++) {
        clusters[i] = (struct Cluster){0, 0, points[i].x, points[i].y, 0};
        points[i].cluster = i;
        clusters[i].size++;
        clusters[i].sum_x += points[i].x;
        clusters[i].sum_y += points[i].y;
    }
    
    do {
        updated = assign_clusters(points, n, clusters, k);
        update_centers(clusters, k);
    } while(updated);
    
    print_clusters(points, n, k);
    
    free(points);
    free(clusters);
    
    return 0;
}