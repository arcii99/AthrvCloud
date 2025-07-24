//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define the macros
#define MAX_NAME_LEN 20
#define MAX_WORKOUTS 10
#define MAX_EXERCISES 5

//Define the structs
struct exercise {
    char name[MAX_NAME_LEN+1];
    int sets;
    int reps;
    int weight;
};

struct workout {
    char name[MAX_NAME_LEN+1];
    struct exercise exercises[MAX_EXERCISES];
    int num_exercises;
};

struct fitness_tracker {
    char name[MAX_NAME_LEN+1];
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts;
};

//Function prototypes
void add_workout(struct fitness_tracker *tracker);
void add_exercise(struct workout *workout);
void display_workouts(struct fitness_tracker tracker);

int main() {
    struct fitness_tracker tracker;
    strcpy(tracker.name, "John");
    tracker.num_workouts = 0;
    int choice = 0;
    while(choice != 3) {
        printf("Welcome to the Fitness Tracker\n");
        printf("1. Add Workout\n");
        printf("2. Display Workouts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_workout(&tracker);
                break;
            case 2:
                display_workouts(tracker);
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

void add_workout(struct fitness_tracker *tracker) {
    if(tracker->num_workouts == MAX_WORKOUTS) {
        printf("Maximum number of workouts reached\n");
        return;
    }
    struct workout new_workout;
    printf("Enter workout name: ");
    scanf("%s", new_workout.name);
    new_workout.num_exercises = 0;
    int choice = 0;
    while(choice != 2 && new_workout.num_exercises < MAX_EXERCISES) {
        printf("Adding exercise %d to %s workout\n", new_workout.num_exercises+1, new_workout.name);
        printf("Enter exercise name: ");
        scanf("%s", new_workout.exercises[new_workout.num_exercises].name);
        printf("Enter number of sets: ");
        scanf("%d", &new_workout.exercises[new_workout.num_exercises].sets);
        printf("Enter number of reps: ");
        scanf("%d", &new_workout.exercises[new_workout.num_exercises].reps);
        printf("Enter weight (in lbs): ");
        scanf("%d", &new_workout.exercises[new_workout.num_exercises].weight);
        new_workout.num_exercises++;
        printf("1. Add another exercise\n");
        printf("2. Finish workout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    tracker->workouts[tracker->num_workouts++] = new_workout;
    printf("Workout added successfully\n");
}

void display_workouts(struct fitness_tracker tracker) {
    if(tracker.num_workouts == 0) {
        printf("No workouts added yet\n");
        return;
    }
    printf("Workouts for %s:\n", tracker.name);
    for(int i = 0; i < tracker.num_workouts; i++) {
        printf("Workout %d: %s\n", i+1, tracker.workouts[i].name);
        for(int j = 0; j < tracker.workouts[i].num_exercises; j++) {
            printf("\t%s:\n", tracker.workouts[i].exercises[j].name);
            printf("\t\tSets: %d\n", tracker.workouts[i].exercises[j].sets);
            printf("\t\tReps: %d\n", tracker.workouts[i].exercises[j].reps);
            printf("\t\tWeight: %d lbs\n", tracker.workouts[i].exercises[j].weight);
        }
    }
}

void add_exercise(struct workout *workout) {
    if(workout->num_exercises == MAX_EXERCISES) {
        printf("Maximum number of exercises reached\n");
        return;
    }
    printf("Enter exercise name: ");
    scanf("%s", workout->exercises[workout->num_exercises].name);
    printf("Enter number of sets: ");
    scanf("%d", &workout->exercises[workout->num_exercises].sets);
    printf("Enter number of reps: ");
    scanf("%d", &workout->exercises[workout->num_exercises].reps);
    printf("Enter weight (in lbs): ");
    scanf("%d", &workout->exercises[workout->num_exercises].weight);
    workout->num_exercises++;
}