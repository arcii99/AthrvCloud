//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_WORKOUTS 100

struct workout {
    char name[MAX_NAME_LENGTH];
    int calories;
    float distance;
    float duration;
};

struct fitness_tracker {
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts;
    int total_calories_burned;
    float total_distance_covered;
    float total_duration;
};

void add_workout(struct fitness_tracker* tracker, char* name, int calories, float distance, float duration) {
    if (tracker->num_workouts == MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached\n");
        return;
    }

    struct workout new_workout;

    if (strlen(name) >= MAX_NAME_LENGTH) {
        printf("Error: Name is too long\n");
        return;
    }

    strcpy(new_workout.name, name);
    new_workout.calories = calories;
    new_workout.distance = distance;
    new_workout.duration = duration;

    tracker->workouts[tracker->num_workouts] = new_workout;
    tracker->num_workouts++;
    tracker->total_calories_burned += calories;
    tracker->total_distance_covered += distance;
    tracker->total_duration += duration;

    printf("New workout added: Name=%s, Calories=%d, Distance=%.2f km, Duration=%.2f minutes\n", name, calories, distance, duration);
}

void print_workouts(struct fitness_tracker* tracker) {
    printf("List of workouts:\n");

    for (int i = 0; i < tracker->num_workouts; i++) {
        printf("%d. Name=%s, Calories=%d, Distance=%.2f km, Duration=%.2f minutes\n", i+1, tracker->workouts[i].name, tracker->workouts[i].calories, tracker->workouts[i].distance, tracker->workouts[i].duration);
    }

    printf("Total calories burned: %d\n", tracker->total_calories_burned);
    printf("Total distance covered: %.2f km\n", tracker->total_distance_covered);
    printf("Total duration: %.2f minutes\n", tracker->total_duration);
}

int main() {
    struct fitness_tracker tracker;
    tracker.num_workouts = 0;
    tracker.total_calories_burned = 0;
    tracker.total_distance_covered = 0;
    tracker.total_duration = 0;

    add_workout(&tracker, "Running", 400, 5.0, 30.0);
    add_workout(&tracker, "Cycling", 300, 10.0, 45.0);
    add_workout(&tracker, "Swimming", 500, 2.0, 40.0);

    print_workouts(&tracker);

    return 0;
}