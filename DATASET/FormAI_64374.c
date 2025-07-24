//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the struct for tracking fitness stats
typedef struct FitnessTracker {
    int steps;
    float distance;
    float calories;
    bool isTracking;
} FitnessTracker;

// Function to start the fitness tracker
void startTracker(FitnessTracker *tracker) {
    tracker->isTracking = true;
    printf("Fitness tracker started!\n");
}

// Function to stop the fitness tracker
void stopTracker(FitnessTracker *tracker) {
    tracker->isTracking = false;
    printf("Fitness tracker stopped!\n");
}

// Function to update the step count
void updateSteps(FitnessTracker *tracker, int numSteps) {
    if (tracker->isTracking) {
        tracker->steps += numSteps;
        printf("Step count updated to %d\n", tracker->steps);
    } else {
        printf("Tracker not running!\n");
    }
}

// Function to update the distance
void updateDistance(FitnessTracker *tracker, float distance) {
    if (tracker->isTracking) {
        tracker->distance += distance;
        printf("Distance updated to %.2f km\n", tracker->distance);
    } else {
        printf("Tracker not running!\n");
    }
}

// Function to update the calories burned
void updateCalories(FitnessTracker *tracker, float calories) {
    if (tracker->isTracking) {
        tracker->calories += calories;
        printf("Calories burned updated to %.2f cal\n", tracker->calories);
    } else {
        printf("Tracker not running!\n");
    }
}

int main() {
    FitnessTracker myTracker = {0, 0.0, 0.0, false};
    startTracker(&myTracker);

    updateSteps(&myTracker, 1000);
    updateDistance(&myTracker, 0.5);
    updateCalories(&myTracker, 50.0);

    updateSteps(&myTracker, 2000);
    updateDistance(&myTracker, 1.0);
    updateCalories(&myTracker, 100.0);

    stopTracker(&myTracker);

    return 0;
}