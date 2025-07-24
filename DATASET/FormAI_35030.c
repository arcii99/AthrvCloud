//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EXERCISES 5

typedef struct {
    int sets;
    int reps;
    int weight;
} Exercise;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Exercise exercises[MAX_EXERCISES];
    int exercisesCount;
} Workout;

Workout tracking[MAX_EXERCISES];
int trackingCount = 0;

void addWorkout(char *name, Exercise *exercises, int exercisesCount);
void printWorkout(Workout workout);
void printTracking();

int main() {
    Exercise exercises1[MAX_EXERCISES] = {
        {3, 10, 100},
        {3, 12, 80},
        {3, 8, 120},
        {3, 15, 50},
        {3, 20, 20}
    };
    
    addWorkout("Monday Workout", exercises1, MAX_EXERCISES);
    
    Exercise exercises2[MAX_EXERCISES] = {
        {3, 10, 120},
        {3, 12, 100},
        {3, 8, 140},
        {3, 15, 60},
        {3, 20, 30}
    };
    
    addWorkout("Wednesday Workout", exercises2, MAX_EXERCISES);
    
    printTracking();

    return 0;
}

void addWorkout(char *name, Exercise *exercises, int exercisesCount) {
    Workout workout;
    strncpy(workout.name, name, MAX_NAME_LENGTH);
    memcpy(workout.exercises, exercises, sizeof(Exercise) * exercisesCount);
    workout.exercisesCount = exercisesCount;
    
    tracking[trackingCount] = workout;
    trackingCount++;
}

void printWorkout(Workout workout) {
    printf("%s\n", workout.name);
    for(int i = 0; i < workout.exercisesCount; i++) {
        printf("Exercise %d: Sets %d, Reps %d, Weight %d lbs.\n", i + 1, workout.exercises[i].sets, workout.exercises[i].reps, workout.exercises[i].weight);
    }
}

void printTracking() {
    printf("**** WORKOUT TRACKING ****\n");
    for(int i = 0; i < trackingCount; i++) {
        printWorkout(tracking[i]);
    }
}