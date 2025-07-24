//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Exercise {
    char name[20];
    int duration;
    float calories;
};

struct FitnessTracker {
    char username[20];
    int age;
    float weight;
    float height;
    struct Exercise exercises[10];
    int numExercises;
    float totalCaloriesBurned;
};

void addExercise(struct FitnessTracker* ft, char name[], int duration, float calories) {
    strcpy((*ft).exercises[(*ft).numExercises].name, name);
    (*ft).exercises[(*ft).numExercises].duration = duration;
    (*ft).exercises[(*ft).numExercises].calories = calories;
    (*ft).numExercises++;
    (*ft).totalCaloriesBurned += calories;
}

void printExercises(struct FitnessTracker ft) {
    printf("Exercises for %s:\n", ft.username);
    for (int i = 0; i < ft.numExercises; i++) {
        printf("%s, %d minutes, %.2f calories\n", ft.exercises[i].name, ft.exercises[i].duration, ft.exercises[i].calories);
    }
    printf("Total calories burned: %.2f\n", ft.totalCaloriesBurned);
}

int main() {
    struct FitnessTracker ft;
    strcpy(ft.username, "John");
    ft.age = 30;
    ft.weight = 75.4;
    ft.height = 1.8;
    ft.numExercises = 0;
    ft.totalCaloriesBurned = 0.0;

    addExercise(&ft, "Running", 30, 250.0);
    addExercise(&ft, "Weight lifting", 45, 150.0);
    addExercise(&ft, "Yoga", 60, 100.0);

    printExercises(ft);

    return 0;
}