//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fitnessTracker {
    char name[20];
    int age;
    float height;
    float weight;
    int steps;
    int caloriesBurned;
};

void displayTracker(struct fitnessTracker trk) {
    printf("\nName: %s\n", trk.name);
    printf("Age: %d\n", trk.age);
    printf("Height: %.2f m\n", trk.height);
    printf("Weight: %.2f kg\n", trk.weight);
    printf("Steps: %d\n", trk.steps);
    printf("Calories Burned: %d\n", trk.caloriesBurned);
}

void updateWeight(struct fitnessTracker *trk, float newWeight) {
    trk->weight = newWeight;
}

void updateSteps(struct fitnessTracker *trk, int newSteps) {
    trk->steps += newSteps;
    trk->caloriesBurned += newSteps * 0.05;
}

int main() {
    struct fitnessTracker trk1;
    strcpy(trk1.name, "John Doe");
    trk1.age = 35;
    trk1.height = 1.75;
    trk1.weight = 75.0;
    trk1.steps = 2356;
    trk1.caloriesBurned = trk1.steps * 0.05;
    displayTracker(trk1);

    printf("\nUpdating weight to 70.5 kg\n");
    updateWeight(&trk1, 70.5);
    displayTracker(trk1);

    printf("\nAdding 500 steps\n");
    updateSteps(&trk1, 500);
    displayTracker(trk1);

    return 0;
}