//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int num_points;
    Point *points;
    Point centroid;
} Cluster;

void update_centroid(Cluster *cluster) {
    double sum_x = 0, sum_y = 0;
    int i;

    for (i = 0; i < cluster->num_points; i++) {
        sum_x += cluster->points[i].x;
        sum_y += cluster->points[i].y;
    }

    cluster->centroid.x = sum_x / cluster->num_points;
    cluster->centroid.y = sum_y / cluster->num_points;
}

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int num_clusters, num_points, i, j, k, l, iterations = 0;
    double threshold;
    Cluster *clusters, *new_clusters;
    Point *points;

    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);

    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    printf("Enter the threshold: ");
    scanf("%lf", &threshold);

    clusters = (Cluster *) malloc(num_clusters * sizeof(Cluster));
    new_clusters = (Cluster *) malloc(num_clusters * sizeof(Cluster));
    points = (Point *) malloc(num_points * sizeof(Point));

    for (i = 0; i < num_points; i++) {
        printf("Enter x and y for point %d: ", i + 1);
        scanf("%lf%lf", &points[i].x, &points[i].y);
    }

    for (i = 0; i < num_clusters; i++) {
        clusters[i].num_points = 1;
        clusters[i].points = (Point *) malloc(sizeof(Point));
        clusters[i].points[0] = points[i];
        clusters[i].centroid = points[i];
    }

    while (iterations < MAX_ITERATIONS) {
        for (i = 0; i < num_clusters; i++) {
            new_clusters[i].num_points = 0;
            new_clusters[i].points = (Point *) malloc(0);
            new_clusters[i].centroid = clusters[i].centroid;
        }

        for (i = 0; i < num_points; i++) {
            int nearest_cluster = 0;
            double min_distance = distance(points[i], clusters[0].centroid);

            for (j = 1; j < num_clusters; j++) {
                double d = distance(points[i], clusters[j].centroid);

                if (d < min_distance) {
                    nearest_cluster = j;
                    min_distance = d;
                }
            }

            int np = new_clusters[nearest_cluster].num_points;
            new_clusters[nearest_cluster].points = (Point *) realloc(new_clusters[nearest_cluster].points, (np + 1) * sizeof(Point));
            new_clusters[nearest_cluster].points[np] = points[i];
            new_clusters[nearest_cluster].num_points++;
        }

        for (i = 0; i < num_clusters; i++) {
            if (new_clusters[i].num_points == 0) {
                printf("Cluster %d is empty.\n", i + 1);
                new_clusters[i].centroid = clusters[i].centroid;
                continue;
            }

            update_centroid(&new_clusters[i]);

            double d = distance(new_clusters[i].centroid, clusters[i].centroid);

            if (d < threshold) {
                printf("No significant change in cluster %d at iteration %d.\n", i + 1, iterations + 1);
                continue;
            }

            clusters[i] = new_clusters[i];
            printf("Cluster %d updated at iteration %d.\n", i + 1, iterations + 1);
        }

        iterations++;

        int convergence = 1;

        for (i = 0; i < num_clusters; i++) {
            for (j = 0; j < clusters[i].num_points; j++) {
                int found = 0;

                for (k = 0; k < new_clusters[i].num_points; k++) {
                    if (clusters[i].points[j].x == new_clusters[i].points[k].x && clusters[i].points[j].y == new_clusters[i].points[k].y) {
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    convergence = 0;
                    break;
                }
            }

            if (!convergence) {
                break;
            }
        }

        if (convergence) {
            printf("Converged after %d iterations.\n", iterations);
            break;
        }
    }

    if (iterations >= MAX_ITERATIONS) {
        printf("Did not converge after %d iterations.\n", MAX_ITERATIONS);
    }

    for (i = 0; i < num_clusters; i++) {
        printf("Cluster %d with centroid (%lf, %lf): ", i + 1, clusters[i].centroid.x, clusters[i].centroid.y);

        for (j = 0; j < clusters[i].num_points; j++) {
            printf("(%lf, %lf) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }

        printf("\n");
    }

    for (i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
        free(new_clusters[i].points);
    }

    free(clusters);
    free(new_clusters);
    free(points);

    return 0;
}