//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare global variables
#define MAX_CLUSTERS 5
#define MAX_VILLAGES 100
#define DIMENSION 2
#define MIN_DISTANCE 5
#define MAX_DISTANCE 50

int num_clusters;
int num_villages;
int clusters[MAX_CLUSTERS][DIMENSION];
int villages[MAX_VILLAGES][DIMENSION];

// Function to randomly generate coordinates within the range
int generate_coordinate(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to initialize the clusters and villages with random coordinates
void initialize() {
    srand(time(NULL));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i][0] = generate_coordinate(0, 100);
        clusters[i][1] = generate_coordinate(0, 100);
    }
    for (int i = 0; i < num_villages; i++) {
        villages[i][0] = generate_coordinate(0, 100);
        villages[i][1] = generate_coordinate(0, 100);
    }
}

// Function to calculate distance between two points
float calculate_distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Function to calculate the closest cluster for each village
void assign_clusters() {
    float min_distance, distance;
    int closest_cluster;
    for (int i = 0; i < num_villages; i++) {
        min_distance = MAX_DISTANCE;
        closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            distance = calculate_distance(villages[i][0], villages[i][1], clusters[j][0], clusters[j][1]);
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        printf("Village %d assigned to Cluster %d\n", i+1, closest_cluster+1);
    }
}

// Function to re-calculate the coordinates of the clusters
void update_clusters() {
    int x_avg, y_avg, num_assigned, sum_x, sum_y;
    for (int i = 0; i < num_clusters; i++) {
        num_assigned = 0;
        sum_x = sum_y = 0;
        for (int j = 0; j < num_villages; j++) {
            if (villages[j][2] == i) {
                num_assigned++;
                sum_x += villages[j][0];
                sum_y += villages[j][1];
            }
        }
        if (num_assigned > 0) {
            x_avg = sum_x / num_assigned;
            y_avg = sum_y / num_assigned;
            clusters[i][0] = x_avg;
            clusters[i][1] = y_avg;
        }
    }
}

// Function to check if the clusters have stabilized
int are_cluster_stable() {
    float distance;
    for (int i = 0; i < num_clusters; i++) {
        distance = calculate_distance(clusters[i][0], clusters[i][1], clusters[i][2], clusters[i][3]);
        if (distance > MIN_DISTANCE) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Get inputs from the user
    printf("Enter number of Clusters (max 5): ");
    scanf("%d", &num_clusters);
    printf("Enter number of Villages (max 100): ");
    scanf("%d", &num_villages);

    // Check if inputs are valid
    if (num_clusters > MAX_CLUSTERS || num_villages > MAX_VILLAGES || num_clusters <= 0 || num_villages <= 0) {
        printf("Invalid Input!\n");
        return 0;
    }

    // Initialize the clusters and villages
    initialize();

    // Run the clustering algorithm until the clusters have stabilized
    int num_iterations = 0, max_iterations = 50;
    while (!are_cluster_stable()) {
        assign_clusters();
        update_clusters();
        num_iterations++;
        if (num_iterations > max_iterations) {
            printf("Maximum iterations reached!\n");
            break;
        }
    }

    // Print the final clusters
    printf("Final Clusters: \n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: (%d, %d)\n", i+1, clusters[i][0], clusters[i][1]);
    }

    return 0;
}