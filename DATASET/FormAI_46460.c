//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E 0.0001

struct Point {
    double x, y;
};

struct Cluster {
    struct Point P;
    int num_points;
    double diameter;
};

double dist(struct Point A, struct Point B) {
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

void init_clusters(struct Cluster * C, int k, struct Point * P, int n) {
    int i;
    for (i = 0; i < k; i++) {
        C[i].P = P[i];
        C[i].num_points = 1;
        C[i].diameter = 0;
    }
    for (; i < n; i++) {
        int j = rand() % k;
        double d = dist(P[i], C[j].P);
        if (d > C[j].diameter)
            C[j].diameter = d;
        C[j].num_points++;
    }
}

void update_clusters(struct Point * P, int n, struct Cluster * C, int k) {
    int i, j;
    for (i = 0; i < k; i++) {
        double x_sum = 0, y_sum = 0;
        int num_points = 0;
        double max_diameter = 0;

        for (j = 0; j < n; j++) {
            if (dist(P[j], C[i].P) <= C[i].diameter) {
                x_sum += P[j].x;
                y_sum += P[j].y;
                num_points++;
                double d = dist(P[j], C[i].P);
                if (d > max_diameter)
                    max_diameter = d;
            }
        }

        if (num_points > 0) {
            C[i].P.x = x_sum / num_points;
            C[i].P.y = y_sum / num_points;
            C[i].num_points = num_points;
            C[i].diameter = max_diameter;
        }
    }
}

void print_clusters(struct Cluster * C, int k) {
    int i;
    for (i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("  Center: (%lf, %lf)\n", C[i].P.x, C[i].P.y);
        printf("  Diameter: %lf\n", C[i].diameter);
        printf("  Number of Points: %d\n", C[i].num_points);
    }
    printf("\n");
}

int main() {
    struct Point P[] = {{1, 1}, {3, 1}, {8, 1}, {12, 1}, {2, 2}, {10, 2}, {6, 3}, {4, 4}, {2, 6}, {4, 6}};
    int n = sizeof(P) / sizeof(P[0]);
    int k = 3;
    struct Cluster C[k];

    init_clusters(C, k, P, n);

    while (1) {
        struct Cluster old_C[k];
        int i;
        for (i = 0; i < k; i++) {
            old_C[i] = C[i];
        }

        update_clusters(P, n, C, k);

        int clusters_changed = 0;
        for (i = 0; i < k; i++) {
            if (dist(C[i].P, old_C[i].P) > E || fabs(C[i].diameter - old_C[i].diameter) > E) {
                clusters_changed = 1;
                break;
            }
        }
        if (!clusters_changed)
            break;
    }

    print_clusters(C, k);

    return 0;
}