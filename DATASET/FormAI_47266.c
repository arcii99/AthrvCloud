//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_VALUE 1000
#define MAX_NUMBERS 20

// Define the structure for store points
struct Point {
    int x;
    int y;
};

// Function to calculate distance between two points
double distance(struct Point p1, struct Point p2) {
    int x = pow(p1.x - p2.x, 2);
    int y = pow(p1.y - p2.y, 2);
    return sqrt(x + y);
}

// Function to print the points
void printPoints(struct Point* points, int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", points[i].x, points[i].y);
    }
    printf("\n");
}

// Function for implementation of Greedy Algorithm
double greedyAlgorithm(struct Point* points, int size) {
    // Store array to check if a number is already used or not
    int usedNumbers[MAX_NUMBERS] = {0};
    // Pick the first point at random
    int currentIndex = rand() % size;
    usedNumbers[currentIndex] = 1;
    struct Point currentPoint = points[currentIndex];
    double totalDistance = 0;

    while (1) {
        double minDistance = MAX_VALUE;
        int nextIndex = -1;
        // Find the nearest point
        for (int i = 0; i < size; i++) {
            if (!usedNumbers[i]) {
                double d = distance(points[i], currentPoint);
                if (d < minDistance) {
                    minDistance = d;
                    nextIndex = i;
                }
            }
        }
        // If all points have been visited, stop searching
        if (nextIndex == -1) {
            break;
        }
        // Update the current point and add the distance to the total
        currentPoint = points[nextIndex];
        usedNumbers[nextIndex] = 1;
        totalDistance += minDistance;
    }
    // Add the final distance to complete the path
    totalDistance += distance(currentPoint, points[currentIndex]);
    return totalDistance;
}

int main() {
    srand(time(NULL));
    // Generate random points
    struct Point points[MAX_NUMBERS];
    int size = rand() % MAX_NUMBERS + 1;
    for (int i = 0; i < size; i++) {
        points[i].x = rand() % MAX_VALUE;
        points[i].y = rand() % MAX_VALUE;
    }
    printf("Randomly generated points: ");
    printPoints(points, size);
    // Calculate the shortest path using the Greedy Algorithm
    double shortestPath = greedyAlgorithm(points, size);
    printf("Shortest Path using Greedy Algorithm: %.2f\n", shortestPath);
    return 0;
}