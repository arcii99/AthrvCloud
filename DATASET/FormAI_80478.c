//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 100

typedef struct {
    char name[50];
    float duration;
    float calories_burned;
} Exercise;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    Date date;
    Exercise exercises[MAX_EXERCISES];
    int num_exercises;
    float total_calories;
} Workout;

typedef struct {
    Workout workouts[MAX_EXERCISES];
    int num_workouts;
} FitnessTracker;

void addExercise(Workout *workout) {
    Exercise exercise;
    printf("Enter name of exercise: ");
    scanf("%s", exercise.name);
    printf("Enter duration of exercise (in minutes): ");
    scanf("%f", &exercise.duration);
    printf("Enter calories burned during exercise: ");
    scanf("%f", &exercise.calories_burned);
    workout->exercises[workout->num_exercises++] = exercise;
    workout->total_calories += exercise.calories_burned;
}

void addWorkout(FitnessTracker *tracker) {
    Workout workout;
    printf("Enter date of workout (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &workout.date.day, &workout.date.month, &workout.date.year);
    char addAnother;
    do {
        addExercise(&workout);
        printf("Do you want to add another exercise? (Y/N) ");
        scanf(" %c", &addAnother);
    } while (addAnother == 'Y' || addAnother == 'y');
    tracker->workouts[tracker->num_workouts++] = workout;
}

void displayWorkouts(FitnessTracker tracker) {
    printf("\nWorkouts:\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < tracker.num_workouts; i++) {
        Workout workout = tracker.workouts[i];
        printf("Date: %02d/%02d/%d\n", workout.date.day, workout.date.month, workout.date.year);
        for (int j = 0; j < workout.num_exercises; j++) {
            Exercise exercise = workout.exercises[j];
            printf("%s - %.2f minutes - %.0f calories\n", exercise.name, exercise.duration, exercise.calories_burned);
        }
        printf("Total calories burned: %.0f\n", workout.total_calories);
        printf("---------------------------------------------------\n");
    }
}

int main() {
    FitnessTracker tracker = {0};
    char choice;
    do {
        printf("\n1. Add workout\n");
        printf("2. Display all workouts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                addWorkout(&tracker);
                break;
            case '2':
                displayWorkouts(tracker);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != '3');
    return 0;
}