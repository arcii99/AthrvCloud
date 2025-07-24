//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_EXERCISE_LENGTH 20

typedef struct {
    char name[MAX_EXERCISE_LENGTH];
    int calories;
    int duration;
} Exercise;

typedef struct {
    Exercise exercises[MAX_WORKOUTS];
    int num_workouts;
    int calories_burned;
    int total_duration;
} WorkoutTracker;

// function that generates a random exercise
Exercise generate_random_exercise() {
    Exercise exercise;
    int num_calories = rand() % 200 + 100;
    int duration = rand() % 60 + 30;
    char* exercise_names[] = {"Push Ups", "Squats", "Lunges", "Plank", "Crunches"};
    int num_names = sizeof(exercise_names) / sizeof(exercise_names[0]);
    int index = rand() % num_names;
    snprintf(exercise.name, MAX_EXERCISE_LENGTH, "%s", exercise_names[index]);
    exercise.calories = num_calories;
    exercise.duration = duration;
    return exercise;
}

// function that adds an exercise to the workout tracker
void add_exercise(WorkoutTracker* tracker, Exercise exercise) {
    tracker->exercises[tracker->num_workouts] = exercise;
    tracker->num_workouts++;
    tracker->calories_burned += exercise.calories;
    tracker->total_duration += exercise.duration;
}

// function that prints out the current workout tracker stats
void print_workout_tracker(WorkoutTracker tracker) {
    printf("Total Workouts: %d\n", tracker.num_workouts);
    printf("Total Calories Burned: %d\n", tracker.calories_burned);
    printf("Total Workout Duration: %d minutes\n", tracker.total_duration);
    printf("Exercise Breakdown: \n");
    for(int i = 0; i < tracker.num_workouts; i++) {
        printf("%s - %d calories, %d minutes\n", tracker.exercises[i].name, 
               tracker.exercises[i].calories, tracker.exercises[i].duration);
    }
}

// main function that adds some random exercises to the tracker and prints out the stats
int main() {
    srand(time(NULL));
    WorkoutTracker tracker;
    tracker.num_workouts = 0;
    tracker.calories_burned = 0;
    tracker.total_duration = 0;
    for(int i = 0; i < 5; i++) {
        Exercise exercise = generate_random_exercise();
        add_exercise(&tracker, exercise);
    }
    print_workout_tracker(tracker);
    return 0;
}