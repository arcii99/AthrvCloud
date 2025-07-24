//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 20
#define MAX_Y 20
#define MAX_CLUSTERS 5
#define MAX_ITERATIONS 100

int map[MAX_X][MAX_Y];
int clusters[MAX_CLUSTERS][2];

void initializeMap() {
    srand(time(NULL));
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++) {
            map[i][j] = rand() % MAX_CLUSTERS;
        }
    }
}

void initializeClusters() {
    srand(time(NULL));
    for(int i = 0; i < MAX_CLUSTERS; i++) {
        clusters[i][0] = rand() % MAX_X;
        clusters[i][1] = rand() % MAX_Y;
    }
}

void printMap() {
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void printClusters() {
    for(int i = 0; i < MAX_CLUSTERS; i++) {
        printf("(%d,%d) ", clusters[i][0], clusters[i][1]);
    }
    printf("\n");
}

void assignPointsToClusters() {
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++) {
            int closestCluster = 0;
            int shortestDistance = MAX_X * MAX_Y;
            for(int c = 0; c < MAX_CLUSTERS; c++) {
                int distance = abs(i - clusters[c][0]) + abs(j - clusters[c][1]);
                if(distance < shortestDistance) {
                    shortestDistance = distance;
                    closestCluster = c;
                }
            }
            map[i][j] = closestCluster;
        }
    }
}

void updateClusters() {
    for(int c = 0; c < MAX_CLUSTERS; c++) {
        int sumX = 0, sumY = 0, count = 0;
        for(int i = 0; i < MAX_X; i++) {
            for(int j = 0; j < MAX_Y; j++) {
                if(map[i][j] == c) {
                    sumX += i;
                    sumY += j;
                    count++;
                }
            }
        }
        if(count > 0) {
            clusters[c][0] = sumX / count;
            clusters[c][1] = sumY / count;
        }
    }
}

int main() {
    initializeMap();
    initializeClusters();
    printf("Initial Map:\n");
    printMap();
    printf("\nInitial Clusters:\n");
    printClusters();
    for(int i = 0; i < MAX_ITERATIONS; i++) {
        assignPointsToClusters();
        updateClusters();
    }
    printf("\nFinal Map:\n");
    printMap();
    printf("\nFinal Clusters:\n");
    printClusters();
    return 0;
}