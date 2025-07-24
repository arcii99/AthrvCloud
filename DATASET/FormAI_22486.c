//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_CUSTOMERS 6
#define NUM_OF_ATTRIBUTES 4
#define NUM_OF_CLUSTERS 2
#define MAX_ITERATIONS 10

typedef struct {
    double attributes[NUM_OF_ATTRIBUTES];
    int cluster;
} Customer;

typedef struct {
    double centroid[NUM_OF_ATTRIBUTES];
    int count;
} Cluster;

void assignRandomClusters(Customer customers[], Cluster clusters[]) {
    int i;
    for (i = 0; i < NUM_OF_CUSTOMERS; i++) {
        int clusterIndex = rand() % NUM_OF_CLUSTERS;
        customers[i].cluster = clusterIndex;
        clusters[clusterIndex].count++;
        for (int j = 0; j < NUM_OF_ATTRIBUTES; j++) {
            clusters[clusterIndex].centroid[j] += customers[i].attributes[j];
        }
    }
}

void calculateCentroids(Customer customers[], Cluster clusters[]) {
    for (int i = 0; i < NUM_OF_CLUSTERS; i++) {
        if (clusters[i].count == 0) {
            continue; // avoid division by zero
        }
        for (int j = 0; j < NUM_OF_ATTRIBUTES; j++) {
            clusters[i].centroid[j] /= clusters[i].count;
        }
    }
}

int assignCustomersToClusters(Customer customers[], Cluster clusters[]) {
    int numOfMovedCustomers = 0;
    for (int i = 0; i < NUM_OF_CUSTOMERS; i++) {
        double minDistance = -1;
        int minDistanceClusterIndex = -1;
        for (int j = 0; j < NUM_OF_CLUSTERS; j++) {
            double distance = 0;
            for (int k = 0; k < NUM_OF_ATTRIBUTES; k++) {
                double diff = customers[i].attributes[k] - clusters[j].centroid[k];
                distance += (diff * diff);
            }
            if (distance < minDistance || minDistance < 0) {
                minDistance = distance;
                minDistanceClusterIndex = j;
            }
        }
        if (customers[i].cluster != minDistanceClusterIndex) {
            numOfMovedCustomers++;
            int oldClusterIndex = customers[i].cluster;
            customers[i].cluster = minDistanceClusterIndex;
            clusters[oldClusterIndex].count--;
            clusters[minDistanceClusterIndex].count++;
            for (int j = 0; j < NUM_OF_ATTRIBUTES; j++) {
                clusters[oldClusterIndex].centroid[j] -= customers[i].attributes[j];
                clusters[minDistanceClusterIndex].centroid[j] += customers[i].attributes[j];
            }
        }
    }
    return numOfMovedCustomers;
}

void printClusters(Customer customers[], Cluster clusters[]) {
    for (int i = 0; i < NUM_OF_CLUSTERS; i++) {
        printf("Cluster %d (centroid: ", i);
        for (int j = 0; j < NUM_OF_ATTRIBUTES; j++) {
            printf("%.2f ", clusters[i].centroid[j]);
        }
        printf(")\n");
        for (int j = 0; j < NUM_OF_CUSTOMERS; j++) {
            if (customers[j].cluster == i) {
                printf("[%d] (", j);
                for (int k = 0; k < NUM_OF_ATTRIBUTES; k++) {
                    printf("%.2f ", customers[j].attributes[k]);
                }
                printf(")\n");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(0); // set random seed to be deterministic
    Customer customers[NUM_OF_CUSTOMERS] = {
        {{1, 1, 1, 1}, 0},
        {{2, 2, 2, 2}, 0},
        {{1, 2, 3, 4}, 0},
        {{5, 6, 7, 8}, 0},
        {{6, 5, 4, 3}, 0},
        {{8, 8, 8, 8}, 0}
    };
    Cluster clusters[NUM_OF_CLUSTERS] = {
        {{0, 0, 0, 0}, 0},
        {{0, 0, 0, 0}, 0}
    };
    assignRandomClusters(customers, clusters);
    printf("Initial clusters:\n");
    printClusters(customers, clusters);
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        calculateCentroids(customers, clusters);
        int numOfMovedCustomers = assignCustomersToClusters(customers, clusters);
        printf("Iteration %d:\n", i + 1);
        printf("Number of moved customers: %d\n", numOfMovedCustomers);
        printClusters(customers, clusters);
        if (numOfMovedCustomers == 0) {
            // convergence reached
            break;
        }
    }
    return 0;
}