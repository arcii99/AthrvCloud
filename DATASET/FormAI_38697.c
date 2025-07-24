//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: authentic
#include <stdio.h>
#include <string.h>

struct FitnessTracker {
    char name[50];
    int steps;
    float distance;
    int calories;
};

void displayStats(struct FitnessTracker ft) {
    printf("\n%s's Stats:\n", ft.name);
    printf("Steps: %d\n", ft.steps);
    printf("Distance: %.2f miles\n", ft.distance);
    printf("Calories Burned: %d\n", ft.calories);
}

void updateSteps(struct FitnessTracker *ft, int newSteps) {
    ft->steps += newSteps;
    ft->distance = ft->steps * 0.0005; // Assuming 1 step = 0.0005 miles
    ft->calories = ft->steps * 0.05; // Assuming 1 step = 0.05 calories burned
}

int main() {
    struct FitnessTracker user;
    strcpy(user.name, "John");

    user.steps = 7423; // initial steps
    user.distance = user.steps * 0.0005; // initial distance
    user.calories = user.steps * 0.05; // initial calories burned

    displayStats(user); // display initial stats

    // simulate user walking for 500 steps
    int walkSteps = 500;
    updateSteps(&user, walkSteps);

    displayStats(user); // display updated stats

    // simulate user taking the stairs for 100 steps (burns more calories)
    int stairSteps = 100;
    updateSteps(&user, stairSteps);
    updateSteps(&user, stairSteps);
    updateSteps(&user, stairSteps);

    displayStats(user); // display updated stats

    return 0;
}