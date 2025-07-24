//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_CLUSTERS 3
#define DIMENSIONS 2
#define NUM_PLAYERS 4
#define MIN_VALUE 0
#define MAX_VALUE 100

/* Functions Declarations */
void print_points(float points[NUM_PLAYERS][DIMENSIONS]);
int find_nearest_center(float points[DIMENSIONS], float centers[NUM_CLUSTERS][DIMENSIONS]);
void update_centers(float points[NUM_PLAYERS][DIMENSIONS], float centers[NUM_CLUSTERS][DIMENSIONS], int cluster_assignments[NUM_PLAYERS]);
void play_game(float points[NUM_PLAYERS][DIMENSIONS], float centers[NUM_CLUSTERS][DIMENSIONS], int cluster_assignments[NUM_PLAYERS]);

int main(void) {
    srand(time(NULL));

    float points[NUM_PLAYERS][DIMENSIONS] = {{0}};
    int cluster_assignments[NUM_PLAYERS] = {0};
    float centers[NUM_CLUSTERS][DIMENSIONS] = {{0}};
    
    // initialize the points with random values
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            points[i][j] = (float) rand() / RAND_MAX * (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
        }
    }

    // initialize the centers with random points from the dataset
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        int random_index = rand() % NUM_PLAYERS;
        for (int j = 0; j < DIMENSIONS; j++) {
            centers[i][j] = points[random_index][j];
        }
    }
    
    printf("Initial Points:\n");
    print_points(points);

    printf("\nInitial Centers:\n");
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Center %d: (%.2f, %.2f)\n", i, centers[i][0], centers[i][1]);
    }

    play_game(points, centers, cluster_assignments);
    
    return 0;
}

void print_points(float points[NUM_PLAYERS][DIMENSIONS]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i, points[i][0], points[i][1]);
    }
}

int find_nearest_center(float points[DIMENSIONS], float centers[NUM_CLUSTERS][DIMENSIONS]) {
    int nearest_center = 0;
    float min_distance = 1e9;
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        float distance = 0;
        for (int j = 0; j < DIMENSIONS; j++) {
            distance += (points[j] - centers[i][j]) * (points[j] - centers[i][j]);
        }
        if (distance < min_distance) {
            nearest_center = i;
            min_distance = distance;
        }
    }
    return nearest_center;
}

void update_centers(float points[NUM_PLAYERS][DIMENSIONS], float centers[NUM_CLUSTERS][DIMENSIONS], int cluster_assignments[NUM_PLAYERS]) {
    int cluster_counts[NUM_CLUSTERS] = {0};
    float new_centers[NUM_CLUSTERS][DIMENSIONS] = {{0}};
    for (int i = 0; i < NUM_PLAYERS; i++) {
        int cluster = cluster_assignments[i];
        for (int j = 0; j < DIMENSIONS; j++) {
            new_centers[cluster][j] += points[i][j];
        }
        cluster_counts[cluster]++;
    }
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        if (cluster_counts[i] > 0) {
            for (int j = 0; j < DIMENSIONS; j++) {
                centers[i][j] = new_centers[i][j] / cluster_counts[i];
            }
        }
    }
}

void play_game(float points[NUM_PLAYERS][DIMENSIONS], float centers[NUM_CLUSTERS][DIMENSIONS], int cluster_assignments[NUM_PLAYERS]) {
    for (int iteration = 0; iteration < 10; iteration++) {
        printf("\nIteration %d:\n", iteration + 1);

        // assign each point to the nearest center
        bool updated = false;
        for (int i = 0; i < NUM_PLAYERS; i++) {
            int nearest_center = find_nearest_center(points[i], centers);
            if (nearest_center != cluster_assignments[i]) {
                cluster_assignments[i] = nearest_center;
                updated = true;
            }
        }

        printf("Cluster Assignments:\n");
        for (int i = 0; i < NUM_PLAYERS; i++) {
            printf("Point %d: Cluster %d\n", i, cluster_assignments[i]);
        }

        // update the centers to the average location of the points in each cluster
        update_centers(points, centers, cluster_assignments);

        printf("\nUpdated Centers:\n");
        for (int i = 0; i < NUM_CLUSTERS; i++) {
            printf("Center %d: (%.2f, %.2f)\n", i, centers[i][0], centers[i][1]);
        }

        // if no point is reassigned to another cluster, the algorithm has converged
        if (!updated) {
            printf("\nConverged after %d iterations.\n", iteration + 1);
            break;
        }
    }
}