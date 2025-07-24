//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_COUNT 10
#define CLUSTER_COUNT 3
#define DIMENSION_COUNT 2
#define MAX_ITERATIONS 1000
#define THRESHOLD 0.001

struct sample {
    float x[DIMENSION_COUNT];
    int cluster;
};

struct cluster {
    float centroid[DIMENSION_COUNT];
    int sampleCount;
};

struct sample samples[SAMPLE_COUNT] = {
    {{5, 7}, -1}, {{2, 5}, -1}, {{3, 3}, -1},
    {{1, 6}, -1}, {{9, 8}, -1}, {{8, 7}, -1},
    {{5, 9}, -1}, {{2, 3}, -1}, {{6, 6}, -1},
    {{7, 9}, -1}
};

struct cluster clusters[CLUSTER_COUNT];

void initialize_clusters(void) {
    for (int i = 0; i < CLUSTER_COUNT; i++) {
        for (int j = 0; j < DIMENSION_COUNT; j++) {
            clusters[i].centroid[j] = (float) rand() / RAND_MAX;
        }
    }
}

float distance(struct sample s, struct cluster c) {
    float distance = 0;
    for (int i = 0; i < DIMENSION_COUNT; i++) {
        float delta = s.x[i] - c.centroid[i];
        distance += delta * delta;
    }
    return sqrtf(distance);
}

void assign_clusters(void) {
    for (int i = 0; i < SAMPLE_COUNT; i++) {
        float closest = INFINITY;
        for (int j = 0; j < CLUSTER_COUNT; j++) {
            float d = distance(samples[i], clusters[j]);
            if (d < closest) {
                closest = d;
                samples[i].cluster = j;
            }
        }
    }
}

void update_clusters(void) {
    for (int i = 0; i < CLUSTER_COUNT; i++) {
        for (int j = 0; j < DIMENSION_COUNT; j++) {
            float sum = 0;
            int count = 0;
            for (int k = 0; k < SAMPLE_COUNT; k++) {
                if (samples[k].cluster == i) {
                    sum += samples[k].x[j];
                    count++;
                }
            }
            clusters[i].centroid[j] = sum / count;
        }
    }
}

void print_clusters(void) {
    for (int i = 0; i < CLUSTER_COUNT; i++) {
        printf("Cluster %d: ", i);
        for (int j = 0; j < SAMPLE_COUNT; j++) {
            if (samples[j].cluster == i) {
                printf("(%f, %f) ", samples[j].x[0], samples[j].x[1]);
            }
        }
        printf("\nCentroid: (%f, %f)\n", clusters[i].centroid[0], clusters[i].centroid[1]);
    }
    printf("\n");
}

int converged(void) {
    for (int i = 0; i < CLUSTER_COUNT; i++) {
        for (int j = 0; j < DIMENSION_COUNT; j++) {
            if (fabsf(clusters[i].centroid[j] - clusters[i].centroid[j]) > THRESHOLD) {
                return 0;
            }
        }
    }
    return 1;
}

void k_means_clustering(void) {
    int iteration = 0;
    while (!converged() && iteration < MAX_ITERATIONS) {
        assign_clusters();
        update_clusters();
        print_clusters();
        iteration++;
    }
}

int main(void) {
    initialize_clusters();
    k_means_clustering();
    return 0;
}