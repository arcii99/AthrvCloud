//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <string.h>

struct FitnessTracker {
    char user[20];
    float weight;
    float height;
    int age;
    int steps;
    int calories;
};

void initializeFitnessTracker(struct FitnessTracker *tracker, char *user, float weight, float height, int age) {
    strcpy(tracker->user, user);
    tracker->weight = weight;
    tracker->height = height;
    tracker->age = age;
    tracker->steps = 0;
    tracker->calories = 0;
}

void recordSteps(struct FitnessTracker *tracker, int steps) {
    tracker->steps += steps;
}

void calculateCalories(struct FitnessTracker *tracker) {
    float BMR;
    if (strcmp(tracker->user, "Male") == 0) {
        BMR = 88.362 + (13.397 * tracker->weight) + (4.799 * tracker->height) - (5.677 * tracker->age);
    } 
    else {
        BMR = 447.593 + (9.247 * tracker->weight) + (3.098 * tracker->height) - (4.330 * tracker->age);
    }
    tracker->calories = (int) (BMR * 1.375);
}

void displayFitnessTracker(struct FitnessTracker *tracker) {
    printf("\nUser: %s\n", tracker->user);
    printf("Weight: %.2f\n", tracker->weight);
    printf("Height: %.2f\n", tracker->height);
    printf("Age: %d\n", tracker->age);
    printf("Steps: %d\n", tracker->steps);
    printf("Calories Burned: %d\n", tracker->calories);
}

int main() {
   struct FitnessTracker tracker;
   initializeFitnessTracker(&tracker, "Male", 70.5, 180.2, 25);
   recordSteps(&tracker, 1500);
   calculateCalories(&tracker);
   displayFitnessTracker(&tracker);
   return 0;
}