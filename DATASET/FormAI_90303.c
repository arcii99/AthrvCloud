//FormAI DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct to represent customer data
typedef struct {
    char name[50];
    int age;
    double income;
    char occupation[50];
} Customer;

int main() {
    int numCustomers = 5;
    Customer customers[numCustomers];

    // read in customer data from file
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("customer_data.csv", "r");
    int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        char *token;
        int count = 0;
        token = strtok(line, ",");
        while (token != NULL) {
            switch (count) {
                case 0:
                    strcpy(customers[i].name, token);
                    break;
                case 1:
                    customers[i].age = atoi(token);
                    break;
                case 2:
                    customers[i].income = atof(token);
                    break;
                case 3:
                    strcpy(customers[i].occupation, token);
                    break;
            }
            count++;
            token = strtok(NULL, ",");
        }
        i++;
    }
    fclose(fp);

    // perform clustering on customer data based on income and age
    int numClusters = 3;
    double clusterCenters[numClusters][2];
    int clusterSizes[numClusters];
    for (int i = 0; i < numClusters; i++) {
        // randomly initialize cluster centers
        clusterCenters[i][0] = rand() % 100;
        clusterCenters[i][1] = rand() % 100;
        clusterSizes[i] = 0;
    }
    for (int i = 0; i < numCustomers; i++) {
        // determine nearest cluster
        int nearestCluster = 0;
        double minDistance = 10000000;
        for (int j = 0; j < numClusters; j++) {
            double distance = sqrt(pow((customers[i].income - clusterCenters[j][0]), 2) + pow((customers[i].age - clusterCenters[j][1]), 2));
            if (distance < minDistance) {
                minDistance = distance;
                nearestCluster = j;
            }
        }
        // update cluster center and size
        clusterCenters[nearestCluster][0] = (clusterCenters[nearestCluster][0] * clusterSizes[nearestCluster] + customers[i].income) / (clusterSizes[nearestCluster] + 1);
        clusterCenters[nearestCluster][1] = (clusterCenters[nearestCluster][1] * clusterSizes[nearestCluster] + customers[i].age) / (clusterSizes[nearestCluster] + 1);
        clusterSizes[nearestCluster]++;
    }

    // print out clustering results
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Center: (%.2f, %.2f)\n", clusterCenters[i][0], clusterCenters[i][1]);
        printf("Size: %d\n", clusterSizes[i]);
        printf("Customers:\n");
        for (int j = 0; j < numCustomers; j++) {
            int nearestCluster = 0;
            double minDistance = 10000000;
            for (int k = 0; k < numClusters; k++) {
                double distance = sqrt(pow((customers[j].income - clusterCenters[k][0]), 2) + pow((customers[j].age - clusterCenters[k][1]), 2));
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestCluster = k;
                }
            }
            if (nearestCluster == i) {
                printf("\t%s\n", customers[j].name);
            }
        }
    }

    return 0;
}