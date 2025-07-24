//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Exercise {
    char name[20];
    int duration_mins;
    int calories_burned;
} Exercise;

typedef struct Workout {
    Exercise exercises[10];
    int num_exercises;
    int total_duration;
    int total_calories_burned;
} Workout;

typedef struct Tracker {
    char name[20];
    int age;
    int height_inches;
    int weight_lbs;
    Workout workouts[100];
    int num_workouts;
} Tracker;

void add_new_workout(Tracker *tracker) {
    Workout workout;
    workout.num_exercises = 0;
    workout.total_duration = 0;
    workout.total_calories_burned = 0;

    printf("\nEnter workout details: \n");
    printf("\tName: ");
    scanf("%s", workout.exercises[workout.num_exercises].name);

    printf("\tDuration (mins): ");
    scanf("%d", &workout.exercises[workout.num_exercises].duration_mins);

    printf("\tCalories burned: ");
    scanf("%d", &workout.exercises[workout.num_exercises].calories_burned);

    workout.total_duration += workout.exercises[workout.num_exercises].duration_mins;
    workout.total_calories_burned += workout.exercises[workout.num_exercises].calories_burned;

    workout.num_exercises++;

    printf("\nWorkout added successfully!\n");

    tracker->workouts[tracker->num_workouts] = workout;
    tracker->num_workouts++;
}

void view_all_workouts(Tracker tracker) {
    printf("\nAll Workouts:\n");

    for (int i = 0; i < tracker.num_workouts; i++) {
        Workout workout = tracker.workouts[i];

        printf("\tWorkout %d:\n", i+1);

        for (int j = 0; j < workout.num_exercises; j++) {
            Exercise exercise = workout.exercises[j];

            printf("\t\tName: %s\n", exercise.name);
            printf("\t\tDuration (mins): %d\n", exercise.duration_mins);
            printf("\t\tCalories burned: %d\n", exercise.calories_burned);
        }

        printf("\t\tTotal Duration (mins): %d\n", workout.total_duration);
        printf("\t\tTotal Calories Burned: %d\n", workout.total_calories_burned);
    }
}

int main() {
    Tracker tracker;
    tracker.num_workouts = 0;

    printf("Welcome to the Fitness Tracker! Please enter your details: \n");
    printf("\tName: ");
    scanf("%s", tracker.name);

    printf("\tAge: ");
    scanf("%d", &tracker.age);

    printf("\tHeight (inches): ");
    scanf("%d", &tracker.height_inches);

    printf("\tWeight (lbs): ");
    scanf("%d", &tracker.weight_lbs);

    int option;

    do {
        printf("\nOptions:\n");
        printf("\t1. Add new workout\n");
        printf("\t2. View all workouts\n");
        printf("\t3. Exit\n");
        printf("\nPlease select an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_new_workout(&tracker);
                break;
            case 2:
                view_all_workouts(tracker);
                break;
            case 3:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option! Please select again.\n");
                break;
        }
    } while(option != 3);

    return 0;
}